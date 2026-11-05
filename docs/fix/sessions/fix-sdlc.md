# Session: fix/sdlc

Branch `fix/sdlc`, based on `origin/fix/core` (5d289570). Session window 07:37–07:57 UTC, 2026-11-05.

## How it was run

One orchestrator, with role subagents launched in parallel (Map, Architect+Plan, Metrics, Reflection,
Speed-ups, Implement), then a Review subagent run on the implementation diff. The orchestrator merged and
verified all output.

## Done

- `docs/fix/sdlc/map.md`: glaze core (opts, read/write dispatch, reflection, SWAR utilities) and the fix/core
  layer, file by file; short comparisons with hffix, QuickFIX, fix8 and simdjson's two-stage scanning.
- `docs/fix/sdlc/architecture.md`: target read/write architecture (zero-copy, compile-time tag tables,
  SWAR/SIMD scanning, single-pass checksum/body-length, writer with constexpr `tag=` prefixes and back-patching).
- `docs/fix/sdlc/plan.md`: phases 0–5, each with its tests and exit criteria.
- `docs/fix/sdlc/metrics.md`: measurement and profiling commands (perf, PMU/topdown, c2c, valgrind, uftrace,
  VTune/uProf, llvm-mca, rdtsc methodology, Google Benchmark/nanobench, page faults, huge pages, noise control).
- `docs/fix/sdlc/reflection.md`: C++26 reflection (P2996, P3394, P1306, define_aggregate), compiler status,
  how glaze reflects today, and an annotation-driven design with a C++23 `glz::meta` fallback.
- `docs/fix/sdlc/speedups.md`: catalogue of techniques by CPU/OS/compiler/library, with public sources.
- Implementation (plan phase 2, first step) in `include/glaze/fix/scan.hpp`:
  - `detail::find_byte`: 8-byte SWAR byte search (memcpy load, haszero, `countr_zero`). Scalar fallback when
    constant-evaluated and on big-endian targets. Used by `next_field` (both `=` and SOH) and by `frame`.
  - `detail::byte_sum`: 8-byte SWAR byte sum in 16-bit lanes, blocked so lanes cannot overflow; used by `checksum`.
- Tests in `tests/fix_test/fix_test.cpp`: delimiter at every offset 0..17, no match, buffers of 1..7 bytes,
  high-bit bytes, constexpr `static_assert`s, byte-sum lengths 0..39, and a 3077-byte run of 0xFF.
  Result with GCC 13.3, `-std=c++23 -O2 -fno-exceptions -fno-rtti -Werror -Wall -Wextra -pedantic`:
  34 tests, 669 asserts, all passed (base fix/core: 32 tests, 515 asserts).
- Micro-benchmark `tests/fix_test/fix_scan_bench.cpp`: runs `field_cursor` plus `checksum` over a 192-byte
  NewOrderSingle. Numbers below are as printed by that program on a **shared cloud VM**, built with GCC 13.3
  `-O2`. Run-to-run noise on this VM is about 10–15%.
  - before: 434.7, 385.5, 367.2 ns/message
  - after: 234.2, 227.0, 260.3 ns/message
  - The `sink` value is identical before and after, so the same fields and checksum are produced.

## Review

The Review subagent found no correctness problems. It checked haszero false positives (only the lowest set bit is used), bounds, lane overflow, the constexpr path and big-endian. Style nit applied: dropped the redundant `inline` on the two constexpr helpers. Not applied: reusing `glz::has_zero`/`glz::countr_zero` from `util/bit.hpp` and adding `GLZ_ALWAYS_INLINE`.

## Failed / not done

- The micro-benchmark is not wired into CMake; it is built by hand (see the file header / command below).
- The tests were built directly with g++, not through the repo's CMake (system CMake is 3.28).
- No PGO/LTO/BOLT or SIMD (SSE2/AVX2/NEON) paths yet. No perf counter runs were captured.

## Left (see plan.md)

- Phase 1: compile-time tag tables (sorted / perfect-hash) with jump-table member dispatch.
- Phase 2: merge validation into the scanning walk (single pass for checksum and body length); SWAR integer parsing.
- Phase 3: writer with constexpr `tag=` prefixes and back-patched 9/10.
- Phase 4: SIMD scanning behind a feature check; fuzzing.
- Reflection-based (P2996) tag tables once a compiler is available in CI.

## Reproduce

```
g++ -std=c++23 -O2 -fno-exceptions -fno-rtti -Werror -Wall -Wextra -pedantic -Iinclude -Itests \
    tests/fix_test/fix_test.cpp -o fix_test && ./fix_test
g++ -std=c++23 -O2 -Iinclude tests/fix_test/fix_scan_bench.cpp -o fix_scan_bench && ./fix_scan_bench
```
