#!/usr/bin/env python3
# Regenerates data/SOURCES.md from the .fixv files.
# Usage: python3 -I tests/fix_vectors_test/tools/gen_sources.py tests/fix_vectors_test/data
import sys, os, glob
d = sys.argv[1]
meta = {
 'simplefix.fixv': ('da4089/simplefix', 'https://github.com/da4089/simplefix', 'MIT', 'licenses/simplefix-LICENSE'),
 'crocofix.fixv': ('GaryHughes/crocofix', 'https://github.com/GaryHughes/crocofix', 'MIT', 'licenses/crocofix-LICENSE.txt'),
 'philadelphia.fixv': ('paritytrading/philadelphia', 'https://github.com/paritytrading/philadelphia', 'Apache-2.0 (no NOTICE file upstream)', 'licenses/philadelphia-LICENSE.txt'),
 'artio.fixv': ('real-logic/artio', 'https://github.com/real-logic/artio', 'Apache-2.0 (no NOTICE file upstream)', 'licenses/artio-LICENSE'),
 'fefix.fixv': ('ferrumfix/ferrumfix', 'https://github.com/ferrumfix/ferrumfix', 'MIT OR Apache-2.0 (used under Apache-2.0)', 'licenses/fefix-LICENSE.txt'),
 'spec.fixv': ('written afresh', 'FIX 4.4 Vol. 2 / FIX Session Layer', 'part of this repository (MIT)', '-'),
 'fefix_crate.fixv': ('fefix crate (crates.io)', 'https://crates.io/crates/fefix', 'MIT OR Apache-2.0 (used under Apache-2.0)', 'licenses/fefix-LICENSE.txt'),
}
out = ["# Sources of the FIX test vectors", "",
 "Generated from the `.fixv` files (`id`, `source`, `note` keys). Each vector's `source` key names the",
 "upstream repository, file and test it was ported from; `spec` means written afresh from the FIX",
 "specification. Values were copied as test data only (message strings and expected outcomes); no",
 "upstream code is included. See `docs/fix/references.md` for the survey and `FORMAT.md` for the format.", "",
 "| file | upstream | licence | licence file | vectors |", "|---|---|---|---|---|"]
blocks = {}
for f in sorted(glob.glob(os.path.join(d, '*.fixv'))):
    name = os.path.basename(f); cur = {}; vs = []
    for line in open(f, encoding='utf-8').read().split('\n') + ['']:
        if not line.strip():
            if cur: vs.append(cur); cur = {}
            continue
        if line.startswith('#'): continue
        k, _, v = line.partition(' = '); cur[k] = v
    blocks[name] = vs
    m = meta.get(name) or meta.get(name.split('_')[0] + '.fixv', ('?', '?', '?', '?'))
    out.append(f"| `{name}` | [{m[0]}]({m[1]}) | {m[2]} | `{m[3]}` | {len(vs)} |" if m[1].startswith('http') else f"| `{name}` | {m[0]} ({m[1]}) | {m[2]} | {m[3]} | {len(vs)} |")
for name, vs in blocks.items():
    out += ["", f"## {name}", "", "| id | kind | expect | source | what it checks |", "|---|---|---|---|---|"]
    for v in vs:
        exp = v.get('expect', v.get('frame_len', v.get('value', '')))
        if 'frame_len' in v: exp = 'len ' + v['frame_len']
        if 'pending' in v: exp += ' (pending)'
        esc = lambda s: s.replace('|', '\\|')
        out.append(f"| `{v.get('id')}` | {v.get('kind')} | {exp} | `{esc(v.get('source',''))}` | {esc(v.get('note',''))} |")
open(os.path.join(d, 'SOURCES.md'), 'w').write('\n'.join(out) + '\n')
