# Session notes: fix/conformance-fuzz

Final state pushed 2026-11-05 ~07:50 UTC. `fix/core` merged at `e5babf6e` (unchanged since 07:20).

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

## Fuzzing results (clang 19, libFuzzer + ASan + UBSan)

Long run, 07:32-07:42 UTC, against `fix/core` at `e5babf6e`: all four fuzzers in parallel,
`-fork=1 -ignore_crashes=1 -max_total_time=600 -max_len=1024`.

| Target | Time | Execs (approx.) | Crashes | Notes |
|---|---|---|---|---|
| `fix_read` | 600 s | 50 M | 0 | cov 657 |
| `fix_frame` | 600 s | | 0 | cov 111 |
| `fix_parse_fields` | 600 s | | 0 | cov 59 |
| `fix_validate` | 90 s + 480 s | | 8 + 4 | all gap 2; the second run had the `010=` filter, the 4 it found are `08=`/`09=` |

Second run, 07:44-07:49 UTC, `-fork=2` each, both gap filters in `fix_validate`:
`fix_validate` about 71 M runs, cov 143, 0 crashes; `fix_read` about 12 M runs, cov 939, 0 crashes.
So apart from gap 2, no new bug turned up.

The minimised corpora (`-merge=1`) are committed in `fuzzing/corpus/<target>/`; the hand-written
seeds stay in `fuzzing/corpus/fix/`. No ASan or UBSan report came up in any target: every crash
was an invariant `abort()` in the harness.

Earlier 60-second bursts:

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

The tests that check these run only with `-DGLZ_FIX_KNOWN_GAPS=1`; the default build passes
(36/36). With the flag, 9 tests fail (P2, R11 x2, R14 x2, R15, R16, R19 x2), one for each gap below,
which is the expected result until core fixes them.

1. **Corrupted BeginString skips all checks.** If byte 0 (`8`) is changed, `glz::read` treats the
   input as a body fragment and runs no BodyLength or CheckSum check, so a corrupted message reads
   successfully. Found by property P2. Suggest: only read a fragment when an option asks for it.
2. **Leading zeros in tags are accepted** (`058=x`). Worse, `validate` accepts `010=219` as the
   CheckSum, `08=` as BeginString and `09=` as BodyLength, while `frame` does not, so the two
   disagree about whether and where a message is. Found by the `fix_validate` fuzzer; inputs in
   `fuzzing/regressions/fix_validate/` (`leading_zero_checksum_tag`, `leading_zero_beginstring_tag`,
   `leading_zero_bodylength_tag`). Suggest: reject a tag that starts with `0` in the scanner.
   `fuzzing/fix_validate.cpp` skips this gap unless built with `-DGLZ_FIX_KNOWN_GAPS=1`, so that
   fuzzing can go on finding other bugs; remove that filter once core is fixed.
3. **Length-prefixed data fields** (95/96 RawData, 354/355, 93/89 ...) are not supported, as core's
   api.md says. Rule R14.
4. **Header tags may repeat in the body** (`35`, `9`, `8` after the header pass `validate`). R15.
5. **A repeated body tag overwrites** instead of failing. R16. (Core documents this choice; the
   FIX spec says a tag appears at most once outside a repeating group.)
6. **Exponent notation is read** for floats (`44=1e5`). FIX float has no exponent. R19.
7. **Floats are written in shortest form**, which can use an exponent (`1e+20`). R19.

## Not done

- Longer fuzzing (hours), and a fuzzer for repeating groups, which `fuzzing/fix_read.cpp`
  does not map yet.
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
