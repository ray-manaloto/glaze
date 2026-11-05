# glaze-fix test suite (`tests/fix_suite/`)

One CMake directory, one executable per source group (`fix_suite_*`, ctest label `fix_suite`).
Built with GCC 13, `-std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror`, against
`fix/core`. Run: `ctest -L fix_suite`.

| executable | directory | origin | tests | status |
|---|---|---|---|---|
| fix_suite_quickfix_imported | quickfix/imported | branch fix/tests-quickfix (QuickFIX C++, QuickFIX/J, QuickFIX/n) | 163 | pass |
| fix_suite_quickfix_new | quickfix/new | QuickFIX C++ @386ce46e (FieldConvertors, Message, Parser test cases) | 22 | pass |
| fix_suite_hffix_imported | hffix/imported | branch fix/tests-hffix-fixpp (hffix) | 44 | pass |
| fix_suite_hffix_new | hffix/new | hffix @797ce7db | 19 | pass |
| fix_suite_fixpp_imported | fixpp/imported | branch fix/tests-hffix-fixpp (fixpp) | 47 | pass |
| fix_suite_more_parsers | more_parsers | quickfixgo, artio, ferrumfix, simplefix, philadelphia | 22 | pass |
| fix_suite_vectors | vectors | branch fix/tests-more-parsers: data-driven `.fixv` vectors (artio, crocofix, fefix, philadelphia, simplefix, spec) | 373 | pass |
| fix_suite_spec | spec | written from the FIX spec rules (no third-party text) | 25 | pass |
| fix_suite_property | property | branch fix/conformance-fuzz (glaze-original property tests) | 35 | pass |
| **total** | | | **750** | **0 failing** |

Each directory has a `SOURCES.md` (upstream repo, commit, file per test) and the upstream licence file.
Behaviour that legitimately differs from the upstream library is kept as a `SKIP:` comment with the reason.

## Coverage matrix (approximate test counts; a test can count in several columns)

| source | framing | BodyLength | CheckSum | types | groups | nested | raw data | session | malformed | round-trip |
|---|---|---|---|---|---|---|---|---|---|---|
| QuickFIX C++ | 5+4 | 4+3 | 8+3 | 22+6 | 14+2 | 1+1 | 0+1 | 13+5 | 13+8 | 15+5 |
| QuickFIX/J | 4 | 2 | 1 | 1 | 6 | 2 | 1 | 2 | 5 | 2 |
| QuickFIX/n | 2 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 4 | 2 |
| hffix | 6+3 | 2+2 | 6+2 | 6+5 | 0+3 | 0 | 2 | 4+3 | 7+3 | 7+2 |
| fixpp | 3 | 1 | 1 | 6 | 17 | 3 | 0 | 3 | 10 | 6 |
| fix8 | – | – | – | – | – | – | – | – | – | – |
| quickfixgo | 2 | 1 | 1 | 1 | 1 | 0 | 0 | 2 | 2 | 1 |
| ferrumfix/fefix | 17+1 | 15 | 8+1 | 45+3 | 8 | 0 | 0 | 7 | 23+1 | 0+1 |
| simplefix | 9 | 10 | 3+1 | 15 | 1 | 0 | 11 | 5 | 10 | 0 |
| philadelphia | 17 | 6 | 2 | 32+1 | 0 | 0 | 0 | 48 | 20 | 1 |
| artio | 9+2 | 19+1 | 8+1 | 26+2 | 11+1 | 4 | 0+1 | 18+1 | 22+2 | 0+1 |
| crocofix | 6 | 9 | 2 | 30 | 0 | 0 | 6 | 4 | 2 | 0 |
| FIX spec | 35+3 | 24+3 | 6+3 | 16+5 | 16+2 | 5+1 | 1+2 | 11+8 | 36+6 | 0+3 |
| property/fuzz | 5 | 3 | 5 | 7 | 1 | 0 | 2 | 1 | 11 | 5 |

`a+b`: `a` = imported from the fix/tests-* branches, `b` = added in this suite. Counts from the
imported branches were classified by test name and vector kind; counts for new files by the feature list
each port reported. Treat them as approximate.

## Known gaps / not included
- **fix8**: LGPL-3.0, no separately licensed test data. Not ported.
- **QuickFIX/J, QuickFIX/n**: only what fix/tests-quickfix already had; no new ports this round.
- **quickfixgo**: three tests need byte-exact SOH vectors copied from the Go source (marked SKIP).
- **fix/dictionary** tests are not included: that branch is not based on the current fix/core and needs the generated dictionary headers.
- `.fixv` vectors cover no round-trip; nested groups and raw data are still thin for most libraries.
- Open question: in more_parsers, three artio checks (typed `glz::read` with a wrong BodyLength,
  CheckSum or MsgType) returned success while the matching `validate()` calls fail. Marked SKIP; needs a look.
