"""Write a copy of OrchestraFIX44.xml with a synthetic extension pack, for the lock test (run.sh lock).

  synthetic_ep.py SRC DST          Side gets a new code Z, OrdType code 1 is renamed Market -> MarketOrder, and
                                   PartyRole gets code 256, one past what its uint8_t enum can hold next to the
                                   max() "absent" value. Expected: 3 refused changes, 1 kept name.
  synthetic_ep.py SRC DST renames  renames only: the OrdType code as above, the Side codeSet (enum) and the
                                   ClOrdID field (member). Expected: all names kept, no change refused.
  synthetic_ep.py SRC DST layout   in NewOrderSingle (message 14) only: the Parties group (453) becomes required
                                   and fields 526 and 583 swap places. Expected: 1 type change, 1 reordered part.
"""
import sys

src, dst = sys.argv[1], sys.argv[2]
renames = len(sys.argv) > 3 and sys.argv[3] == 'renames'
s = open(src, encoding='utf-8').read()

if len(sys.argv) > 3 and sys.argv[3] == 'layout':
    start = s.index('<fixr:message id="14" name="NewOrderSingle"')
    end = s.index('</fixr:message>', start)
    m = s[start:end]
    a, b = '<fixr:fieldRef id="526" added="FIX.4.3" />', '<fixr:fieldRef id="583" added="FIX.4.3" />'
    g = '<fixr:groupRef id="1012" added="FIX.4.3">'
    assert m.count(a) == 1 and m.count(b) == 1 and m.count(g) == 1
    m = m.replace(a, '@A@').replace(b, a).replace('@A@', b)
    m = m.replace(g, '<fixr:groupRef id="1012" presence="required" added="FIX.4.3">')
    open(dst, 'w', encoding='utf-8').write(s[:start] + m + s[end:])
    sys.exit(0)


def once(old, new):
    global s
    assert s.count(old) == 1, old
    s = s.replace(old, new)


once('<fixr:code id="40001" name="Market" value="1"', '<fixr:code id="40001" name="MarketOrder" value="1"')
if renames:
    once('<fixr:codeSet id="54" name="SideCodeSet" ', '<fixr:codeSet id="54" name="TradeSideCodeSet" ')
    s = s.replace('type="SideCodeSet"', 'type="TradeSideCodeSet"')
    once('<fixr:field id="11" name="ClOrdID" ', '<fixr:field id="11" name="ClientOrderID" ')
    open(dst, 'w', encoding='utf-8').write(s)
    sys.exit(0)
once('<fixr:codeSet id="54" name="SideCodeSet" type="char" added="FIX.2.7">',
     '<fixr:codeSet id="54" name="SideCodeSet" type="char" added="FIX.2.7">\n'
     '      <fixr:code id="54999" name="Synthetic" value="Z"/>')
once('<fixr:codeSet id="452" name="PartyRoleCodeSet" type="int" added="FIX.4.3">',
     '<fixr:codeSet id="452" name="PartyRoleCodeSet" type="int" added="FIX.4.3">\n'
     '      <fixr:code id="452999" name="SyntheticRole" value="256"/>')
open(dst, 'w', encoding='utf-8').write(s)
