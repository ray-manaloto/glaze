# Session notes: fix/conformance-fuzz

## Done

- `fix/core` is merged (07:20 UTC). The local stub this branch began with is gone; tests and fuzzers
  now run against core's `include/glaze/fix/*.hpp`. The stub is in this branch's history (commit
  `cbaccd2f`) if its Length-prefixed data handling (95/96 etc.) is wanted for core.
- `tests/fix_property_test/` (registered in `tests/CMakeLists.txt`): property tests P1-P3 and
  conformance tests R1-R25. All 34 tests pass with GCC 13, `-fno-exceptions -fno-rtti -Werror`.
- `fuzzing/fix_parse_fields.cpp`, `fix_validate.cpp`, `fix_frame.cpp`, `fix_read.cpp`, added to
  `fuzzing/CMakeLists.txt`. Seed corpus in `fuzzing/corpus/fix/`; crash inputs in
  `fuzzing/regressions/fix_read/`.
- `docs/fix/conformance.md`: the checklist, one test per rule.

## Fuzzing results (60-second bursts, clang 19, libFuzzer + ASan + UBSan)

- `fix_frame`, `fix_parse_fields`, `fix_validate`: no crashes.
- After merging `fix/core`: `fix_frame`, `fix_parse_fields`, `fix_read` clean for 45 s each;
  `fix_validate` found gap 2 below.
- Before the merge, against the stub, `fix_read` found two round-trip bugs in the stub, both fixed, each with a regression input and a unit test:
  1. `large_double_write_overflow`: a 301-digit price was read, but the writer's 64-byte buffer was
     too small for fixed notation, so the write failed. The buffer is now 512 bytes.
  2. `char_nul_write_refused`: `54=\0` was read, but the writer refused a NUL char. FIX char allows
     any byte but the delimiter, so the writer now accepts it.
  Both apply to any implementation of the contract, so `fix/core` should pass these inputs too.

## Known gaps in fix/core (found by these tests and fuzzers)

The tests that check these run only with `-DGLZ_FIX_KNOWN_GAPS=1`; the default build passes.

1. **Corrupted BeginString skips all checks.** If byte 0 (`8`) is changed, `glz::read` treats the
   input as a body fragment and runs no BodyLength or CheckSum check, so a corrupted message reads
   successfully. Found by property P2. Suggest: only read a fragment when an option asks for it.
2. **Leading zeros in tags are accepted** (`058=x`). Worse, `validate` accepts `010=219` as the
   CheckSum while `frame` does not, so they disagree about where a message ends. Found by the
   `fix_validate` fuzzer; input in `fuzzing/regressions/fix_validate/leading_zero_checksum_tag`.
3. **Length-prefixed data fields** (95/96 RawData, 354/355, 93/89 ...) are not supported, as core's
   api.md says. Rule R14.
4. **Header tags may repeat in the body** (`35`, `9`, `8` after the header pass `validate`). R15.
5. **A repeated body tag overwrites** instead of failing. R16. (Core documents this choice; the
   FIX spec says a tag appears at most once outside a repeating group.)
6. **Exponent notation is read** for floats (`44=1e5`). FIX float has no exponent. R19.
7. **Floats are written in shortest form**, which can use an exponent (`1e+20`). R19.

## Not done

- Fixing the known gaps below in `fix/core` (that branch owns the code). When one is fixed, remove
  its `if constexpr (known_gaps)` guard in the test.
- Repeating groups and the other items listed under "Not yet covered" in `docs/fix/conformance.md`.
- clang 18 cannot compile glaze here (an existing consteval issue in `get_name.hpp`); use clang 19+.

## Provenance of tests

No tests were ported from other projects. Reference repositories were not fetched; every test
vector was written from scratch from the FIX 4.4 and FIX 5.0 SP2 / FIXT.1.1 specifications.

## Reproduce through CMake (verified 07:33 UTC with CMake 4.4 from `pip install cmake`)

    cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++
    cmake --build build --target fix_property_test fix_test
    ctest --test-dir build -R fix_ --output-on-failure        # 2/2 pass

    # clang 19 (apt install clang-19 libclang-rt-19-dev). Module scanning is off because the
    # container has no clang-scan-deps-19; that flag is not needed where it is installed.
    cmake -B build-fuzz -G Ninja -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=Off \
          -DCMAKE_CXX_COMPILER=clang++-19 -DCMAKE_CXX_SCAN_FOR_MODULES=OFF
    cmake --build build-fuzz --target fuzz_fix_frame fuzz_fix_parse_fields fuzz_fix_read fuzz_fix_validate
    build-fuzz/fuzzing/fuzz_fix_read -max_total_time=600 fuzzing/corpus/fix

## Reproduce without CMake

    g++ -std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror -Iinclude -Itests \
        tests/fix_property_test/fix_property_test.cpp -o fpt && ./fpt
    clang++-19 -std=c++23 -O1 -g -fsanitize=fuzzer,address,undefined -Iinclude fuzzing/fix_read.cpp -o fz_read
    ./fz_read -max_total_time=60 -max_len=512 fuzzing/corpus/fix
