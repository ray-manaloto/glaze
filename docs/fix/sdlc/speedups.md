# glaze-fix: Speed-up Options

This document catalogues techniques that can make a header-only C++ FIX
tag=value parser/serializer faster, grouped by technique, operating system,
CPU family, compiler and library. For each option it states the expected
benefit in qualitative terms, the main risks, and how to verify that the
change actually helped. It deliberately contains no numeric performance
claims: every workload, message mix and machine is different, so each item
must be measured on the target hardware before it is adopted.

General rules that apply to every item below:

- Measure first. Profile a representative message set (`perf record`,
  `perf stat`, Instruments on macOS, or a microbenchmark harness such as
  Google Benchmark or nanobench) and identify where time actually goes
  before changing anything.
- Keep a correctness oracle. Every optimisation must be checked against the
  scalar reference path with the full conformance suite and a fuzzer
  (libFuzzer or AFL++) before and after.
- Change one variable at a time and keep the benchmark pinned (same core,
  same frequency governor, same input) so that differences are attributable.
- Prefer options that keep the library header-only and dependency-free; put
  heavier dependencies (allocators, SIMD libraries) behind opt-in macros.

---

## 1. Delimiter scanning (SOH `\x01` and `=`)

The inner loop of a tag=value parser is finding the next `=` and the next
SOH. This is byte scanning, which is where data-parallel techniques pay off
most.

### 1.1 SWAR (SIMD within a register)

Load 8 bytes into a `uint64_t`, XOR with a broadcast of the delimiter and use
the classic "has zero byte" bit trick to find the first match, then
`countr_zero` to get the offset. Works on every 64-bit target with no
intrinsics.

- Benefit: fewer branches and loads per byte than a `for` loop; fully
  portable; no ISA dispatch needed. Good for short fields (FIX fields are
  mostly short) where a 16- or 32-byte vector load is partly wasted.
- Risk: unaligned loads near the end of the buffer must be guarded (either
  pad the input or fall back to byte-at-a-time for the tail); the bit trick
  must be applied carefully so that it reports the *first* match, not just
  *some* match; endianness affects which end `countr_zero` refers to.
- Verify: unit tests with delimiters at every offset 0..15 of a word
  boundary; fuzz against the scalar loop; compare `perf stat` instructions
  and branch-misses per message.

### 1.2 SSE2 (x86-64 baseline)

`_mm_loadu_si128`, two `_mm_cmpeq_epi8` compares (one for SOH, one for `=`),
`_mm_movemask_epi8`, then `countr_zero` on the combined mask. SSE2 is part of
the x86-64 baseline so this needs no runtime dispatch.

- Benefit: 16 bytes per iteration; can locate `=` and SOH in one pass and
  record both positions; always available on x86-64.
- Risk: reading past the end of the buffer (needs a tail path or guaranteed
  slack); over-reading a `std::string_view` is undefined behaviour even when
  the page is mapped, so provide a safe tail.
- Verify: ASan/UBSan builds, tests on buffers that end exactly at a 16-byte
  boundary, Valgrind for over-reads.

### 1.3 AVX2

Same as SSE2 with 32-byte lanes (`_mm256_*`). Requires `-mavx2` or
`__attribute__((target("avx2")))` plus runtime dispatch via CPUID.

- Benefit: halves iterations for long messages or long values (e.g. raw
  data fields, repeating groups). For very short fields the gain over SSE2
  is small because the mask processing dominates.
- Risk: runtime dispatch adds a function pointer or branch; mixing AVX and
  legacy SSE code without `vzeroupper` causes transition penalties (the
  compiler handles this when the whole TU is compiled with `-mavx2`, but not
  always across inline boundaries); some older server parts downclock under
  heavy 256-bit use.
- Verify: build a dispatch test that forces each path; run on a machine
  without AVX2 (or with `-mno-avx2`) to confirm fallback works.

### 1.4 AVX-512

64-byte lanes with mask registers (`_mm512_cmpeq_epi8_mask`) and the
`VBMI`/`VBMI2` subsets for compress/expand if you also want to strip or
insert delimiters in one go.

- Benefit: fewest iterations per message; mask registers avoid the
  movemask step; compress-store instructions help serialisation.
- Risk: not available on many client CPUs or on ARM; licence-based frequency
  reduction on some Intel generations; code size; more dispatch variants to
  test; the cloud VM may hide the feature even when the host has it.
- Verify: only enable behind an explicit opt-in; benchmark against AVX2 on
  the same box with the same pinned core; check `perf stat` for frequency.

### 1.5 NEON (ARM64: Apple M-series, Graviton, Ampere)

`vld1q_u8`, `vceqq_u8`, then build a bitmask. NEON has no `movemask`; the
common idiom is `vshrn_n_u16` to narrow the compare result to a 64-bit
value where each nibble represents one byte, then `rbit`/`clz` to find the
first match.

- Benefit: 16 bytes per iteration on every ARM64 core; NEON is baseline so
  no dispatch is needed; Apple cores have wide issue so the extra mask
  shuffles are cheap.
- Risk: the movemask emulation is a known pitfall; a naive version with
  `vaddvq` or table lookups is slower than the narrowing shift idiom. SVE/SVE2
  (Graviton 3+) offer predicated loads that remove the tail problem but
  require separate code paths.
- Verify: test on at least one Apple Silicon machine and one Graviton
  instance; compare against SWAR, which is often competitive on ARM for
  short fields.

### 1.6 Portable wrappers

`std::experimental::simd` (GCC libstdc++), Google Highway, or xsimd give a
single source for the above.

- Benefit: one implementation, many ISAs; Highway in particular handles
  dispatch and tails.
- Risk: adds a dependency to a header-only library; abstraction may prevent
  the exact instruction sequence you want (e.g. the NEON narrowing trick).
- Verify: inspect generated assembly (Compiler Explorer, `objdump -d`) to
  confirm the wrapper emits what you expect.

---

## 2. Tag lookup

After splitting a field, the integer tag is mapped to a member of the user's
struct.

### 2.1 Switch on integer tag

Convert the tag digits to an integer, then `switch`. Compilers turn dense
cases into jump tables and sparse cases into binary search.

- Benefit: no hashing, no string compare; the compiler already does the hard
  work; perfect for reflected structs where the tag set is known at compile
  time.
- Risk: very sparse tag sets become a binary search with mispredicted
  branches; large switches can bloat code when generated per message type.
- Verify: look at the generated code; measure branch-misses on a realistic
  message mix (tags usually arrive in a predictable order, so a
  branch-predictor-friendly sequential check may beat the switch).

### 2.2 Perfect hash on tag number

Generate at compile time (constexpr) a minimal perfect hash from the set of
known tags to a dense index, then index an array of handlers.

- Benefit: constant time, no branches on the tag value, compact table;
  friendlier to the branch predictor than a long switch when tags are
  sparse.
- Risk: constexpr generation cost on large structs; a hash collision check is
  still needed for unknown tags; the extra indirection costs an
  unpredictable indirect branch if the handler is called through a function
  pointer rather than inlined.
- Verify: compile-time budget (`-ftime-trace` with Clang); compare against
  the switch on the same struct; fuzz with unknown and out-of-range tags.

### 2.3 Order-aware fast path

FIX fields in a given message type arrive in a mostly fixed order. Keep a
"next expected member" cursor and check it before falling back to the
general lookup.

- Benefit: the common case becomes a single predictable compare.
- Risk: pathological inputs (randomly ordered tags) must not be slower than
  the plain lookup by more than one compare; the logic must not change
  semantics for repeating groups.
- Verify: benchmark on both in-order and shuffled inputs.

---

## 3. Integer and decimal parsing

### 3.1 SWAR 8-digit integer parse

Load 8 ASCII digits into a `uint64_t`, subtract `'0'` from each byte, then
combine pairs of digits with three multiply-and-shift steps. Handles the
common case of tags and small integers without a loop.

- Benefit: branch-free conversion of up to 8 digits; validation (all bytes
  are digits) can be done with one mask test.
- Risk: requires at least 8 readable bytes (needs padding or a length
  check); must handle signs and lengths that are not a multiple of 8;
  overflow checks still required for 64-bit targets.
- Verify: exhaustive tests for lengths 1..20, boundary values, leading
  zeros, sign handling; fuzz against `std::from_chars`.

### 3.2 `std::from_chars`

The standard, locale-independent, non-allocating conversion for integers and
floating point.

- Benefit: correct rounding guaranteed; zero dependencies; integer overloads
  are fast in all mainstream standard libraries.
- Risk: floating-point `from_chars` is still missing or slow in some
  libc++ versions; behaviour differs slightly across standard libraries for
  edge cases (e.g. leading `+`); FIX decimals often need exact decimal
  semantics rather than binary floating point anyway.
- Verify: feature-test macro `__cpp_lib_to_chars`; compare results bit for
  bit against a reference implementation.

### 3.3 fast_float

Header-only library implementing the Eisel-Lemire algorithm for
`float`/`double` parsing with a correct fallback.

- Benefit: fast and correctly rounded; available where libc++ lacks
  floating-point `from_chars`; supports `std::string_view`-style input.
- Risk: adds a dependency; binary floating point may not be what a FIX price
  field should become (consider a fixed-point decimal type instead).
- Verify: the library ships its own test suite; run it under the project's
  compiler flags; check that the fallback path is exercised by at least one
  test input.

### 3.4 Fixed-point decimal

Parse price and quantity fields to an integer mantissa plus exponent instead
of `double`.

- Benefit: avoids floating-point rounding entirely and is usually cheaper
  than a correctly rounded `double` parse; serialisation becomes integer
  formatting.
- Risk: user-visible API change; scale handling and overflow must be
  specified.
- Verify: round-trip tests for every scale; property-based tests comparing
  with arbitrary-precision arithmetic.

### 3.5 Integer and decimal serialisation

Use digit-pair lookup tables (two digits per step), `std::to_chars`, or
Ryu/Dragonbox for shortest round-trip floating point output.

- Benefit: fewer divisions; branch-free length calculation with
  `countl_zero`-based digit counting.
- Risk: table adds a small amount of data to every translation unit of a
  header-only library (use `inline constexpr`).
- Verify: round-trip every value class; compare against `snprintf` output
  in tests.

---

## 4. Checksum (tag 10) vectorisation

The FIX checksum is the sum of all bytes modulo 256.

### 4.1 x86: `psadbw`

`_mm_sad_epu8` / `_mm256_sad_epu8` against a zero vector sums 8 bytes into
a 16-bit lane with no overflow. Accumulate the lanes and reduce at the end.

- Benefit: sums 16 or 32 bytes per instruction with no risk of 8-bit
  overflow; trivially combined with the delimiter scan loop so the message
  is only read once.
- Risk: the tail still needs a scalar path; combining checksum with parsing
  complicates error handling when a message is rejected early.
- Verify: compare with a scalar sum on random buffers of every length
  0..1024; confirm the compiler did not already auto-vectorise the scalar
  loop (check assembly: GCC and Clang often do this at `-O3`).

### 4.2 ARM: `vaddv` / widening adds

Use `vpadalq_u8`/`vpaddlq_u8` to widen into 16-bit accumulators, then
`vaddvq_u16` or `vaddlvq_u8` to reduce.

- Benefit: same single-pass benefit as x86; NEON horizontal adds are cheap.
- Risk: 16-bit accumulators must be flushed before they can overflow
  (every 255 iterations for `u16`); off-by-one in that flush is a classic
  bug.
- Verify: tests with buffers longer than the flush interval.

### 4.3 Let the compiler do it

A plain `for` loop accumulating into a `uint32_t` is often auto-vectorised
at `-O2`/`-O3`.

- Benefit: no intrinsics to maintain.
- Risk: fragile; a small refactor or a change in the surrounding loop can
  silence the vectoriser.
- Verify: `-Rpass=loop-vectorize` (Clang) or `-fopt-info-vec` (GCC) in the
  build to assert the loop was vectorised.

---

## 5. Compiler and build options

### 5.1 Optimisation level and architecture

- `-O2` vs `-O3`: `-O3` enables more aggressive vectorisation and unrolling;
  may help scan loops, may bloat code and hurt instruction cache.
- `-march=x86-64-v2` (SSE4.2, POPCNT), `-march=x86-64-v3` (AVX2, BMI2, FMA),
  `-march=x86-64-v4` (AVX-512): the micro-architecture levels defined in the
  x86-64 psABI let a distributed binary assume a feature set without naming
  a specific CPU. BMI2 (`pdep`/`pext`, `tzcnt`) and `lzcnt` in v3 make the
  mask-processing steps of SIMD scanning cheaper.
- `-march=native`: best for a binary that runs only where it was built.
- ARM: `-mcpu=native`, `-mcpu=neoverse-v1`/`neoverse-v2` (Graviton 3/4),
  `-mcpu=apple-m1` and later on Apple Clang.

- Benefit: unlocks `tzcnt`, `popcnt`, BMI2 and wider vectors without
  intrinsics; lets the compiler pick better instruction sequences for the
  scalar code too.
- Risk: a binary built for v3 or v4 crashes with SIGILL on older hardware;
  `-march=native` is non-reproducible across a build farm.
- Verify: test on the lowest target machine; add a startup CPUID check that
  fails with a clear message; keep a baseline build in CI.

### 5.2 Clang vs GCC

Both are strong; they differ in which loops they vectorise, how they
inline, and in diagnostics.

- Clang: `-Rpass`/`-Rpass-missed` remarks, `-ftime-trace`, better
  `__builtin_expect` propagation in some cases, ThinLTO.
- GCC: `-fopt-info`, often more aggressive unrolling, `-fipa-pta`.
- Useful flags on both: `-fno-plt`, `-fno-semantic-interposition` (GCC;
  makes inline functions in shared objects actually inline),
  `-fno-exceptions` only if the library never throws, `-fomit-frame-pointer`
  (default at `-O2`), `-fno-math-errno`.

- Benefit: trying both compilers is cheap and sometimes shows a large
  difference on one hot loop, which usually indicates a code pattern that
  can be rewritten to be fast on both.
- Risk: per-compiler flags fragment the build; `-ffast-math` must be avoided
  for a parser that needs exact rounding.
- Verify: CI matrix with both compilers; benchmark artefacts stored per
  compiler.

### 5.3 Link-time optimisation (LTO)

`-flto` (GCC, full LTO) or `-flto=thin` (Clang ThinLTO).

- Benefit: cross-TU inlining and dead-code elimination; for a header-only
  library the win is mostly in the *user's* binary (e.g. inlining the
  message dispatch into the network loop).
- Risk: longer link times; debugging harder; some toolchain combinations
  (mismatched `ar`/`ranlib` plugins) silently drop LTO.
- Verify: confirm with `nm`/`objdump` that the hot functions were inlined;
  compare binary size and benchmark.

### 5.4 Profile-guided optimisation (PGO)

GCC: `-fprofile-generate`, run the workload, `-fprofile-use
-fprofile-correction`. Clang: `-fprofile-instr-generate`, run, merge with
`llvm-profdata merge`, then `-fprofile-instr-use=`. Clang also supports
sampling-based profiles via `-fprofile-sample-use` with `perf` data converted
by `llvm-profgen` or `create_llvm_prof`.

- Benefit: better block layout, inlining decisions and branch hints for the
  actual message mix; particularly effective on the tag dispatch code and
  error-handling paths, which PGO moves out of line.
- Risk: the training set must match production or PGO can make the real
  workload slower; profiles go stale as code changes (Clang warns on
  mismatch); instrumented builds are slow, so training must be scripted.
- Verify: keep the training input in the repository; CI step that rebuilds
  with the profile and fails if the benchmark regresses against the
  non-PGO build.

### 5.5 BOLT (post-link binary optimisation)

LLVM BOLT re-orders functions and basic blocks in an already linked binary
using `perf` samples (with LBR where available). Typical flow:
`perf record -e cycles:u -j any,u`, `perf2bolt`, `llvm-bolt
-reorder-blocks=ext-tsp -reorder-functions=hfsort -split-functions
-split-all-cold -icf=1 -use-gnu-stack`.

- Benefit: reduces instruction-cache and iTLB misses; stacks with PGO and
  LTO because it works on the final layout; no source changes.
- Risk: Linux-only in practice (ELF, `perf`); needs `-Wl,--emit-relocs`;
  requires LBR-capable hardware for best results (Intel has it; AMD Zen 3+
  has BRS/LBR; many VMs do not expose it); yet another artefact in the
  pipeline.
- Verify: `perf stat -e L1-icache-load-misses,iTLB-load-misses` before and
  after; benchmark on the pinned core.

### 5.6 Code layout hints without PGO

`[[likely]]`/`[[unlikely]]`, `__builtin_expect`, `[[gnu::cold]]` on error
paths, `[[gnu::hot]]`/`[[gnu::flatten]]` on the parse entry point,
`-falign-functions=64`.

- Benefit: cheap approximation of PGO for a header-only library whose users
  may not run PGO themselves.
- Risk: hints that are wrong hurt; `flatten` can explode code size.
- Verify: check with `perf annotate` that the hot path is contiguous.

---

## 6. Memory allocation

A parser into user structs should ideally allocate nothing. Where strings or
vectors are unavoidable:

### 6.1 Arena / `std::pmr`

Parse into a `std::pmr::monotonic_buffer_resource` that is reset per message
or per batch; use `std::pmr::string` and `std::pmr::vector` for repeating
groups.

- Benefit: allocation becomes a pointer bump; freeing is a reset; memory
  stays hot in cache; no dependency.
- Risk: `pmr` types are not drop-in for `std::string`; lifetime bugs when a
  parsed object outlives its arena; `polymorphic_allocator` adds a virtual
  call per allocation (cheap but not free).
- Verify: count allocations with a counting resource in tests; assert zero
  heap allocations on the hot path.

### 6.2 `std::string_view` / zero-copy

Return views into the input buffer instead of owning strings.

- Benefit: the largest possible allocation saving; no copying of field
  bodies.
- Risk: the user must keep the buffer alive; data fields that need
  unescaping cannot be views.
- Verify: lifetime tests under ASan.

### 6.3 mimalloc / jemalloc / tcmalloc

Replace the global allocator (`LD_PRELOAD`, link-time override, or
`mi_malloc` API).

- Benefit: faster small-object allocation and better multi-thread scaling
  than some default allocators; mimalloc is header-light and easy to link;
  jemalloc exposes detailed statistics.
- Risk: process-wide change the library author does not control; different
  fragmentation behaviour; macOS system allocator replacement is less
  straightforward than on Linux.
- Verify: benchmark the full application, not just the parser; compare RSS
  over time.

### 6.4 Small-buffer / inline storage

Use `std::string` SSO consciously (keep common fields under the SSO
threshold of the target standard library), or fixed-capacity strings for
known-short fields (currency, side, symbol).

- Benefit: no heap traffic for most FIX fields.
- Risk: SSO size differs between libstdc++, libc++ and MSVC.
- Verify: static_assert or runtime check on `std::string{}.capacity()`.

---

## 7. Operating system and hardware

### 7.1 Huge pages

Transparent huge pages (`madvise(MADV_HUGEPAGE)` or
`/sys/kernel/mm/transparent_hugepage/enabled`) for large message buffers
and arenas; `-Wl,-zcommon-page-size=2097152 -Wl,-zmax-page-size=2097152`
plus `hugetlbfs` or `libhugetlbfs` for the code segment.

- Benefit: fewer dTLB/iTLB misses when the working set is large (ring
  buffers, many sessions).
- Risk: a small parser working set gains little; THP can introduce latency
  spikes from compaction (`defrag` setting); macOS has no user-controllable
  huge page policy comparable to Linux; Apple Silicon already uses 16 KiB
  pages.
- Verify: `perf stat -e dTLB-load-misses,iTLB-load-misses`;
  `/proc/<pid>/smaps` `AnonHugePages`.

### 7.2 CPU pinning and isolation

`taskset`/`sched_setaffinity`, `isolcpus`/`nohz_full`/`rcu_nocbs` kernel
parameters, disabling SMT siblings for the hot core, `cpupower frequency-set
-g performance`.

- Benefit: removes migration, keeps L1/L2 warm, and (most importantly for
  this document) makes benchmarks repeatable.
- Risk: operational, not a library change; misconfigured isolation starves
  the kernel; macOS offers only QoS classes and thread affinity *hints*
  (`thread_policy_set` with `THREAD_AFFINITY_POLICY`), not hard pinning.
- Verify: `perf stat` run-to-run variance should fall; check
  `/proc/interrupts` for IRQs landing on the isolated core.

### 7.3 Linux vs macOS

- Linux: `perf`, BOLT, `isolcpus`, huge pages, `io_uring` for the network
  side, `LD_PRELOAD` allocators all available. Prefer it for benchmarking
  and production.
- macOS: Instruments (Time Profiler, Counters), `xctrace`; no BOLT; no hard
  pinning; Apple Clang lags upstream in some features (`std::from_chars`
  for floating point arrived late in libc++); `-march` is replaced by
  `-mcpu` on arm64; universal binaries complicate ISA dispatch.

- Benefit of acknowledging the split: avoids shipping Linux-only tuning that
  does nothing on developer laptops and vice versa.
- Verify: CI on both; benchmark numbers tagged with OS and CPU.

### 7.4 x86 vs ARM

- x86 (Intel/AMD): wide SIMD (AVX2 everywhere server-side, AVX-512 on many
  server parts and Zen 4+), `psadbw`, BMI2, LBR for BOLT; strong
  out-of-order execution hides branchy scalar code.
- Apple M-series: very wide decode and large reorder window, so scalar and
  SWAR code performs well; NEON only (no SVE); 16 KiB pages; high
  single-core throughput makes it a good development benchmark machine but
  not representative of server deployment.
- AWS Graviton (Neoverse N1/V1/V2): NEON on all, SVE on Graviton 3+;
  per-core performance lower than top x86 parts but cost-effective; memory
  tagging and pointer authentication available for hardening.

- Benefit: dispatching the scan loop per ISA (SSE2/AVX2/NEON) with a SWAR
  fallback covers all of the above with three code paths.
- Risk: code that is tuned only on an Apple laptop may regress on Graviton
  (smaller caches, narrower cores) and on x86 (different SIMD idioms).
- Verify: benchmark matrix covering at least one of each; track per-ISA
  numbers separately.

---

## 8. Suggested order of work

1. Establish the benchmark harness, pinned core, and conformance/fuzz
   suite.
2. Zero-copy views and zero-allocation hot path (section 6) — usually the
   largest and safest win.
3. SWAR delimiter scan and SWAR integer parse (sections 1.1, 3.1) —
   portable, no dispatch.
4. Order-aware tag fast path, then switch/perfect hash (section 2).
5. SSE2/NEON scan with checksum fused in (sections 1.2, 1.5, 4).
6. AVX2 behind dispatch (section 1.3).
7. Build-level: `-march` levels, LTO, PGO, then BOLT (section 5).
8. Only then consider AVX-512, allocator replacement and huge pages.

---

## Sources

- simdjson: Parsing Gigabytes of JSON per Second — https://arxiv.org/abs/1902.08318
- simdjson repository — https://github.com/simdjson/simdjson
- fast_float repository — https://github.com/fastfloat/fast_float
- Number Parsing at a Gigabyte per Second (Eisel-Lemire) — https://arxiv.org/abs/2101.11408
- Daniel Lemire's blog — https://lemire.me/blog/
- Lemire: "Quickly parsing eight digits" — https://lemire.me/blog/2018/10/03/quickly-parsing-eight-digits/
- Bit Twiddling Hacks (has-zero-byte SWAR trick) — https://graphics.stanford.edu/~seander/bithacks.html
- Intel Intrinsics Guide — https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
- Arm NEON Intrinsics Reference — https://developer.arm.com/architectures/instruction-sets/intrinsics/
- Arm: "Porting SSE movemask to NEON" (community article) — https://community.arm.com/arm-community-blogs/b/infrastructure-solutions-blog/posts/porting-x86-vector-bitmask-optimizations-to-arm-neon
- Google Highway (portable SIMD) — https://github.com/google/highway
- xsimd — https://github.com/xtensor-stack/xsimd
- x86-64 psABI micro-architecture levels — https://gitlab.com/x86-psABIs/x86-64-ABI
- GCC x86 options (`-march` levels) — https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html
- GCC optimisation options (PGO, LTO flags) — https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
- GCC instrumentation options (`-fprofile-generate`/`-fprofile-use`) — https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
- Clang User's Manual: Profile Guided Optimization — https://clang.llvm.org/docs/UsersManual.html#profile-guided-optimization
- Clang: ThinLTO — https://clang.llvm.org/docs/ThinLTO.html
- llvm-profdata — https://llvm.org/docs/CommandGuide/llvm-profdata.html
- LLVM BOLT — https://github.com/llvm/llvm-project/tree/main/bolt
- BOLT: A Practical Binary Optimizer for Data Centers and Beyond — https://arxiv.org/abs/1807.06735
- Linux `perf` wiki — https://perf.wiki.kernel.org/
- Linux Transparent Hugepage documentation — https://www.kernel.org/doc/html/latest/admin-guide/mm/transhuge.html
- Linux CPU isolation (`isolcpus`, kernel parameters) — https://www.kernel.org/doc/html/latest/admin-guide/kernel-parameters.html
- mimalloc — https://github.com/microsoft/mimalloc
- jemalloc — https://github.com/jemalloc/jemalloc
- `std::pmr` memory resources (cppreference) — https://en.cppreference.com/w/cpp/memory/memory_resource
- `std::from_chars` (cppreference) — https://en.cppreference.com/w/cpp/utility/from_chars
- `std::to_chars` (cppreference) — https://en.cppreference.com/w/cpp/utility/to_chars
- Dragonbox (shortest float formatting) — https://github.com/jk-jeon/dragonbox
- Ryu — https://github.com/ulfjack/ryu
- Google Benchmark — https://github.com/google/benchmark
- nanobench — https://github.com/martinus/nanobench
- Agner Fog's optimisation manuals — https://www.agner.org/optimize/
- uops.info instruction tables — https://uops.info/
- Apple Silicon CPU Optimization Guide — https://developer.apple.com/documentation/apple-silicon/cpu-optimization-guide
- AWS Graviton Technical Guide — https://github.com/aws/aws-graviton-getting-started
- FIX Protocol tag=value encoding specification — https://www.fixtrading.org/standards/tagvalue/
