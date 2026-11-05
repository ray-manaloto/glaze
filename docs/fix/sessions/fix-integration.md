# fix/integration — session notes

## What was done

1. Created `fix/integration` from `origin/fix/core`.
2. Merged with real `--no-ff` merges, in order: `fix/dictionary`, `fix/tests-quickfix`,
   `fix/tests-hffix-fixpp`, `fix/tests-more-parsers`, `fix/conformance-fuzz`.
   Every branch had already merged `fix/core` and adapted its tests to the core API, so the only
   conflicts were `add_subdirectory(...)` lines in `tests/CMakeLists.txt`; all were kept.
3. At about 07:33 UTC the branches had moved on again (core: raw-data fields, typed `utc_timestamp`,
   fixed-point decimal; quickfix/hffix: more cases; more-parsers/conformance-fuzz: tools and docs).
   Merged those too, in the same order with `fix/core` first. No conflicts.
   A third round at about 07:36 UTC (core: `field_cursor`/`for_each_field`; dictionary: FIXT.1.1 and
   flattened StandardHeader; more quickfix, hffix/fixpp, vectors and fuzz updates) conflicted only in
   `tests/fix_test/fix_test.cpp`, where `fix/core` had fixed the same `raw_data_roundtrip` literal bug
   (below) its own way; `fix/core`'s version was taken. A fourth round at about 07:38 UTC (dictionary,
   quickfix, hffix/fixpp, more-parsers) merged without conflicts.
4. Configured once per compiler (Ninja, Debug, `-Dglaze_DEVELOPER_MODE=ON`) and built only the
   seven FIX test targets. GCC builds with `-fno-exceptions -fno-rtti -Werror -std=gnu++23`.

## Fixes made on this branch

- **Missing fixpp data file.** `tests/fix_fixpp_test/data/fix42.log` was not committed, because the
  root `.gitignore` has `*.log`, so `fix42_log` failed (3 asserts). Added the file from
  Abc-Arbitrage/fixpp `tests/data/fix42.log` (MIT; `LICENSE-fixpp` is already beside the test) and a
  `!tests/fix_fixpp_test/data/*.log` exception to `.gitignore`. `fix/tests-hffix-fixpp` later
  committed the same file; the merge resolved cleanly.
- **Clang: `fix_dictionary_test` bracket depth.** `fix44::NewOrderSingle` has 156 fields, so its
  `glz::meta` tuple has 312 elements. Clang's default `-fbracket-depth=256` rejects the fold in
  `filter_indices_expand` (`include/glaze/core/reflect.hpp`). Added `-fbracket-depth=1024` for Clang
  to that test's CMakeLists only. Anyone using `glaze/fix/dict/fix44.hpp` with Clang needs the same
  flag. This is a test-build setting, not an API change.
- **Bug in a `fix/core` test (not in the library).** `raw_data_roundtrip` in
  `tests/fix_test/fix_test.cpp` built `std::string("bin\x01ary|with=delims\0end", 26)`. `\x01a`
  parses as one hex escape (0x1a), so the literal holds 23 bytes and the constructor read 3 bytes
  past it. ASan reported a global-buffer-overflow under Clang; GCC (no sanitizer in this config)
  passed by reading whatever bytes came next. Split the literal (`"bin\x01" "ary|..."`), used the
  real length 23, and changed the expected `95=26` to `95=23`. No change to `fix/core`'s public API.

## Clang 18 (image default): not fixed, cause found

Clang 18.1.3 with the image's libstdc++ 13 fails in `include/glaze/util/expected.hpp`:
`no template named 'expected' in namespace 'std'`. The cause: libstdc++ 13's `<expected>` only
defines `std::expected` when `__cpp_concepts >= 202002L`, and Clang 18 sets `__cpp_concepts` to
`201907L` (Clang 19 sets 202002L). Clang 18 also fails in glaze core code that has nothing to do with
FIX (`reflection/get_name.hpp:268` "cannot take address of consteval function",
`util/for_each.hpp:323` unknown attribute `assume` under `-Werror`). Upstream glaze supports Clang 19+
(README), so this is a toolchain limitation, not a small correct fix; nothing was changed for it.
No libc++ is installed, so `-stdlib=libc++` was not an option.

Workaround used: `apt-get install clang-19` (19.1.1 from Ubuntu noble), configured with
`-DCMAKE_CXX_COMPILER=clang++-19 -DCMAKE_CXX_SCAN_FOR_MODULES=OFF` (there is no
`clang-scan-deps-19`, so CMake's module scanning fails without that option). The Clang build uses
the test project's `-fno-exceptions -fno-rtti -Werror` and ASan/UBSan.

## Results (state at 07:39 UTC, after five merge rounds)

`ctest -R '^fix_'`: GCC 7/7 pass, Clang 19 7/7 pass.

Counts come from the `ut` summaries; a binary with two translation units prints one summary per TU,
and these numbers are the sums. "Skipped" counts the `SKIP` lines the tests print for documented
gaps (not run, not counted in "run").

| Test target          | GCC 13.3 run | pass | fail | skipped | Clang 19.1 run | pass | fail | skipped |
|----------------------|-------------:|-----:|-----:|--------:|---------------:|-----:|-----:|--------:|
| fix_test             | 32 | 32 | 0 | 0 | 32 | 32 | 0 | 0 |
| fix_dictionary_test  | 24 | 24 | 0 | 0 | 24 | 24 | 0 | 0 |
| fix_hffix_test       | 50 | 50 | 0 | 5 | 50 | 50 | 0 | 5 |
| fix_fixpp_test       | 51 | 51 | 0 | 6 | 51 | 51 | 0 | 6 |
| fix_quickfix_test    | 163 | 163 | 0 | 20 | 163 | 163 | 0 | 20 |
| fix_vectors_test     | 373 | 373 | 0 | 0 | 373 | 373 | 0 | 0 |
| fix_property_test    | 35 | 35 | 0 | 0 | 35 | 35 | 0 | 0 |
| Clang 18.1.3         | —   | —   | — | —  | does not compile (see above) | | | |

## What is left

- The skipped cases are the known `fix/core` gaps that the test branches recorded (for example
  floats written with an exponent, an unknown tag inside a group ending the group, BeginString
  checks). Build with `-DGLZ_FIX_KNOWN_FAILURES` to run the guarded ones.
- The fuzz targets in `fuzzing/fix_*.cpp` were merged but not built or run here.
- Clang 18 support would need either libc++ or a fallback `expected` in glaze, plus fixes to core
  glaze code; out of scope for this branch.
