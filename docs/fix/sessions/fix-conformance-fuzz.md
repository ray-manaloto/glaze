# Session notes: fix/conformance-fuzz

## Done

- `include/glaze/fix/fix.hpp`: a **local stub** of the shared FIX API contract, written before
  `fix/core` had a header. It provides `parse_fields`, `checksum`, `validate`, `frame`, and a flat
  struct mapping through `glz::from<FIX, T>` / `glz::to<FIX, T>` (strings, integers, floating
  point, char, bool as Y/N; Length-prefixed data fields in the scanner). No repeating groups.
- `tests/fix_property_test/` (registered in `tests/CMakeLists.txt`): property tests P1-P3 and
  conformance tests R1-R25. All 34 tests pass with GCC 13, `-fno-exceptions -fno-rtti -Werror`.
- `fuzzing/fix_parse_fields.cpp`, `fix_validate.cpp`, `fix_frame.cpp`, `fix_read.cpp`, added to
  `fuzzing/CMakeLists.txt`. Seed corpus in `fuzzing/corpus/fix/`; crash inputs in
  `fuzzing/regressions/fix_read/`.
- `docs/fix/conformance.md`: the checklist, one test per rule.

## Fuzzing results (60-second bursts, clang 19, libFuzzer + ASan + UBSan)

- `fix_frame`, `fix_parse_fields`, `fix_validate`: no crashes.
- `fix_read`: two round-trip bugs in the stub, both fixed, each with a regression input and a unit test:
  1. `large_double_write_overflow`: a 301-digit price was read, but the writer's 64-byte buffer was
     too small for fixed notation, so the write failed. The buffer is now 512 bytes.
  2. `char_nul_write_refused`: `54=\0` was read, but the writer refused a NUL char. FIX char allows
     any byte but the delimiter, so the writer now accepts it.
  Both apply to any implementation of the contract, so `fix/core` should pass these inputs too.

## Not done

- Merging `fix/core`: it appeared during this session; the stub has not been replaced yet. Next
  step: `git fetch origin fix/core && git merge origin/fix/core`, delete the stub in favour of
  core's header, and rerun the tests. Expect to adapt error codes (the stub uses `syntax_error`,
  `invalid_header`, `invalid_length`, `invalid_body`, `unexpected_end`, `parse_number_failure`,
  `unknown_key`) to whatever `docs/fix/api.md` on `fix/core` specifies.
- Built through CMake: the container had CMake 3.28 and glaze needs 3.31, so targets were compiled
  directly with g++ / clang++-19 using the same flags. Check `cmake --build build --target
  fix_property_test fuzz_fix_read ...` locally.
- Repeating groups and the other items listed under "Not yet covered" in `docs/fix/conformance.md`.
- clang 18 cannot compile glaze here (an existing consteval issue in `get_name.hpp`); use clang 19+.

## Provenance of tests

No tests were ported from other projects. Reference repositories were not fetched; every test
vector was written from scratch from the FIX 4.4 and FIX 5.0 SP2 / FIXT.1.1 specifications.

## Reproduce

    g++ -std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror -Iinclude -Itests \
        tests/fix_property_test/fix_property_test.cpp -o fpt && ./fpt
    clang++-19 -std=c++23 -O1 -g -fsanitize=fuzzer,address,undefined -Iinclude fuzzing/fix_read.cpp -o fz_read
    ./fz_read -max_total_time=60 -max_len=512 fuzzing/corpus/fix
