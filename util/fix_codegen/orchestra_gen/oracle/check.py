"""Independent check of orchestra_gen output against the Orchestra XML.

It shares no code or model with the generator: it reads the XML with the Python standard library,
derives each message's expected fields from the spec rules, and compares them with what the
*compiled* generated header contains (printed by dump.cpp through reflection).

Checked per part (message, header, trailer, every group entry it reaches):
  * the tag list in wire order, with required/optional and group flags
  * each member's C++ type family (L2-L5) and the optional wrapper (L4)
  * each group's entry, recursively
  * int enum widths against the field's legal range, including unionDataType Reserved<N>Plus

  python3 -I check.py ORCHESTRA.xml DUMP.txt [MsgType ...]
Exit status 1 if any check fails.
"""
import re
import sys
import xml.etree.ElementTree as ET

xml_path, dump_path, *wanted = sys.argv[1:]


def local(tag):
    return tag.rsplit('}', 1)[-1]


root = ET.parse(xml_path).getroot()
by_kind = {}
for el in root.iter():
    by_kind.setdefault(local(el.tag), []).append(el)
fields = {int(f.get('id')): f for f in by_kind['field']}
components = {int(c.get('id')): c for c in by_kind['component']}
groups = {int(g.get('id')): g for g in by_kind['group']}
codesets = {c.get('name'): c for c in by_kind['codeSet']}
datatypes = {d.get('name'): d for d in by_kind['datatype']}
messages = {m.get('msgType'): m for m in by_kind['message']}
ENVELOPE = {8, 9, 35, 10}


def base_type(t):
    seen = 0
    while t in datatypes and datatypes[t].get('baseType') and seen < 16:
        if t in ('int', 'float', 'char', 'String', 'Boolean', 'UTCTimestamp', 'SeqNum', 'Length', 'NumInGroup', 'TagNum'):
            break
        t = datatypes[t].get('baseType')
        seen += 1
    return t


def refs_of(el):
    for c in el:
        n = local(c.tag)
        if n in ('fieldRef', 'componentRef', 'groupRef'):
            yield n, int(c.get('id')), c.get('presence', 'optional')


class Part:
    def __init__(self, name):
        self.name, self.fields, self.repeats = name, [], []  # fields: (tag, required, group_id or None)


def flatten(el, part, required_ctx, skip_session, seen):
    for kind, rid, pres in refs_of(el):
        if pres in ('forbidden', 'ignored'):
            continue
        req = required_ctx and pres == 'required'
        if kind == 'componentRef':
            c = components[rid]
            if skip_session and c.get('name') in ('StandardHeader', 'StandardTrailer'):
                continue
            flatten(c, part, req, False, seen)
        elif kind == 'groupRef':
            g = groups[rid]
            nig = next(x for x in g if local(x.tag) == 'numInGroup')
            tag = int(nig.get('id'))
            if tag in seen:
                part.repeats.append(tag)
                continue
            seen.add(tag)
            part.fields.append((tag, req, rid))
        else:
            if rid in ENVELOPE:
                continue
            if rid in seen:
                part.repeats.append(rid)
                continue
            seen.add(rid)
            part.fields.append((rid, req, None))


def expected_part(el, name, kind):
    p = Part(name)
    if kind == 'message':
        flatten(next(x for x in el if local(x.tag) == 'structure'), p, True, True, set())
    elif kind == 'session':
        flatten(el, p, True, False, set())
    else:  # group entry: first field is the delimiter, always present
        flatten(el, p, True, False, set())
        if p.fields and p.fields[0][2] is None:
            p.fields[0] = (p.fields[0][0], True, None)
    return p


# ---- what the compiled header contains ----------------------------------------------------------
got, cur = {}, None
for line in open(dump_path):
    w = line.rstrip('\n').split(' ', 4)
    if w[0] == 'PART':
        cur = {'name': w[1], 'msg_type': w[2], 'fields': [], 'types': {}, 'groups': {}}
        got[w[1]] = cur
    elif w[0] == 'F':
        cur['fields'].append((int(w[1]), w[2] == '1', w[3] == '1', w[4]))
    elif w[0] == 'T':
        cur['types'][w[1]] = line.rstrip('\n').split(' ', 2)[2]
    elif w[0] == 'G':
        m = re.search(r'aka ([\w:]+)', line)
        cur['groups'][w[1]] = m.group(1) if m else w[2]
enum_size = {}
for line in open(dump_path):
    if line.startswith('ENUM '):
        _, n, sz = line.split()
        enum_size[n] = int(sz)
# every int enum in the generated enums header (the dump's ENUM lines are the compiler's view of a few)
SIZES = {'std::uint8_t': 1, 'std::int8_t': 1, 'std::uint16_t': 2, 'std::int16_t': 2, 'std::uint32_t': 4, 'std::int32_t': 4}
enums_hpp = re.sub(r'dump[^/]*\.txt$', 'enums.hpp', dump_path)
try:
    for m in re.finditer(r'enum class (\w+) : ([\w:]+)', open(enums_hpp).read()):
        if m.group(2) in SIZES:
            enum_size.setdefault(m.group(1), SIZES[m.group(2)])
except FileNotFoundError:
    pass

failures, checks = [], 0


def fail(msg):
    failures.append(msg)


def expected_type(tag, required):
    """L2-L5 type family from the spec, written independently of the generator."""
    f = fields[tag]
    t = f.get('type')
    if t in codesets:
        cs = codesets[t]
        ct = cs.get('type')
        if base_type(ct) in ('char', 'int') or ct in ('char', 'int'):
            fam = 'enum:' + t.removesuffix('CodeSet')
        else:
            t = ct
            fam = None
        if fam:
            return fam if required else 'opt(' + fam + ')'
    b = base_type(t)
    if t == 'SeqNum': fam = 'u64'
    elif t == 'Length': fam = 'u32'
    elif t in ('NumInGroup', 'TagNum'): fam = 'u16'
    elif t == 'DayOfMonth': fam = 'u8'
    elif b == 'int': fam = 'i64'
    elif b == 'float': fam = 'decimal'
    elif t == 'Boolean' or b == 'Boolean': return 'bool:1' if required else 'opt(yes_no)'
    elif b == 'char': fam = 'char'
    elif t in ('UTCTimestamp', 'TZTimestamp'): fam = 'timestamp'
    else: fam = 'string_view'
    return fam if required else 'opt(' + fam + ')'


def family_of(cpp):
    """Map the compiler's spelling of a member type to the same family names."""
    bit = cpp.endswith(' :bit')
    cpp = cpp.removesuffix(' :bit')
    opt = cpp.startswith('stdx::v1::optional<')
    inner = cpp
    if opt:
        inner = cpp[len('stdx::v1::optional<'):].split(', stdx::v1::tombstone_value')[0].rstrip('> ').strip()
    table = [('time_point', 'timestamp'), ('decimal64_t', 'decimal'), ('yes_no', 'yes_no'),
             ('basic_string_view', 'string_view'), ('long long unsigned int', 'u64'), ('long unsigned int', 'u64'),
             ('short unsigned int', 'u16'), ('unsigned int', 'u32'), ('unsigned char', 'u8'),
             ('long long int', 'i64'), ('long int', 'i64')]
    fam = None
    if inner == 'char':
        fam = 'char'
    elif inner == 'bool':
        fam = 'bool'
    else:
        for k, v in table:
            if k in inner:
                fam = v
                break
    if fam is None and inner.startswith('fix44::'):
        fam = 'enum:' + inner.split('::')[-1]
    if bit:
        fam += ':1'
    return 'opt(' + str(fam) + ')' if opt else str(fam)


def compare(exp, got_name, path):
    global checks
    g = got.get(got_name)
    if g is None:
        fail(f'{path}: struct {got_name} not in the generated header')
        return
    want = [(t, r, gid is not None) for t, r, gid in exp.fields]
    have = [(t, r, grp) for t, r, grp, _ in g['fields']]
    checks += 1
    if want != have:
        ws, hs = {x[0]: x for x in want}, {x[0]: x for x in have}
        for t in ws.keys() - hs.keys(): fail(f'{path}: tag {t} ({fields[t].get("name")}) missing')
        for t in hs.keys() - ws.keys(): fail(f'{path}: tag {t} extra')
        for t in ws.keys() & hs.keys():
            if ws[t] != hs[t]: fail(f'{path}: tag {t} ({fields[t].get("name")}) expected required={ws[t][1]} group={ws[t][2]}, got required={hs[t][1]} group={hs[t][2]}')
        if ws.keys() == hs.keys() and all(ws[t] == hs[t] for t in ws):
            fail(f'{path}: same tags, different wire order')
    for (tag, req, gid), (_, _, _, member) in zip(exp.fields, g['fields']):
        if gid is not None:
            entry = g['groups'].get(member)
            if entry is None:
                fail(f'{path}.{member}: group member is not a span of entries')
                continue
            ge = expected_part(groups[gid], groups[gid].get('name'), 'entry')
            compare(ge, entry, f'{path}.{member}')
            continue
        checks += 1
        want_t, have_t = expected_type(tag, req), family_of(g['types'].get(member, '?'))
        if want_t != have_t:
            fail(f'{path}.{member} (tag {tag}): expected {want_t}, got {have_t}  [{g["types"].get(member)}]')


targets = wanted or ['A', '0', 'D', '8', 'F', 'G', 'W']
hdr = next(c for c in components.values() if c.get('name') == 'StandardHeader')
trl = next(c for c in components.values() if c.get('name') == 'StandardTrailer')
h = expected_part(hdr, 'StandardHeader', 'session'); h.fields = [f for f in h.fields if f[0] not in ENVELOPE]
t = expected_part(trl, 'StandardTrailer', 'session'); t.fields = [f for f in t.fields if f[0] not in ENVELOPE]
compare(h, 'fix44::StandardHeader<glz::fix3::count_unknown>', 'StandardHeader')
compare(t, 'fix44::StandardTrailer<glz::fix3::count_unknown>', 'StandardTrailer')
summary = []
for mt in targets:
    m = messages[mt]
    e = expected_part(m, m.get('name'), 'message')
    before = len(failures)
    compare(e, f'fix44::{m.get("name")}<glz::fix3::count_unknown>', f'{m.get("name")}({mt})')
    nf = sum(1 for x in e.fields if x[2] is None)
    summary.append(f'  {m.get("name")} ({mt}): {len(e.fields)} top-level tags ({nf} fields, {len(e.fields)-nf} groups), '
                   f'{len(failures)-before} failures' + (f'; repeated tags in the dictionary, kept first: {sorted(set(e.repeats))}' if e.repeats else ''))

# ---- enum widths: the legal range, including unionDataType Reserved<N>Plus -----------------------
width_fail = []
for f in fields.values():
    cs = codesets.get(f.get('type'))
    if cs is None or cs.get('type') != 'int':
        continue
    codes = [int(c.get('value')) for c in cs if local(c.tag) == 'code']
    hi = max(codes) if codes else 0
    u = f.get('unionDataType') or ''
    m = re.match(r'Reserved(\d+)Plus', u)
    legal_hi = max(hi, 2**31 - 1) if m else hi  # Reserved<N>Plus: any value from N up is legal
    need = 1 if legal_hi < 255 else 2 if legal_hi < 65535 else 4
    name = cs.get('name').removesuffix('CodeSet')
    if name in enum_size:
        checks += 1
        if enum_size[name] < need:
            width_fail.append(f'{name} (field {f.get("name")} {f.get("id")}, {u or "no union"}): {enum_size[name]} byte(s), legal values need {need}')
failures += sorted(set(width_fail))

print(f'oracle: {checks} checks, {len(failures)} failures')
print('\n'.join(summary))
for x in failures:
    print('FAIL', x)
sys.exit(1 if failures else 0)
