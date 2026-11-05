# Session: fix/test-suite

Goal: one organised glaze-fix test suite drawing on the open-source FIX libraries.

What was done (2026-11-05, timeboxed to 07:57 UTC):
- Branch `fix/test-suite` from `origin/fix/core`. Added `tests/fix_suite/` (glob-driven CMake: every
  `**/fix_suite_*.cpp` is one ctest; `*.part.cpp` in the same directory are linked in).
- Imported, unchanged apart from file names, from fix/tests-more-parsers (vectors), fix/tests-quickfix,
  fix/tests-hffix-fixpp (hffix, fixpp) and fix/conformance-fuzz (property). All of them compile against the current fix/core.
- Parallel role subagents produced new ports: QuickFIX C++ (22), hffix (19), quickfixgo/artio/fefix/
  simplefix/philadelphia (22), FIX spec rules (25), plus a coverage gap inventory.
- Fixed `-Wmissing-field-initializers` (designated `fix_opts` initialisers) in two new files so the suite builds with `-Werror`.
- Result: 9 executables, 750 tests, all pass with GCC 13, `-fno-exceptions -fno-rtti -Werror`, CMake 4.x from pip.

Not done / follow-ups: see "Known gaps" in docs/fix/test-suite.md (fix8 licence, QFJ/QFN new ports,
quickfixgo byte-exact vectors, fix/dictionary tests, artio typed-read mismatch question).
The source branches are still being worked on, so re-import from them when they settle.
