# Measuring glaze-fix: a C++/Linux performance-metrics cookbook

This page collects every practical way we know to measure a header-only FIX
tag=value parser/serializer on Linux. Each tool section ends with
copy-pasteable commands. Assume a benchmark binary built like this:

```sh
cmake -S . -B build-bench -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_FLAGS="-O3 -march=native -fno-omit-frame-pointer -g" \
  -Dglaze_BUILD_FIX_BENCH=ON
cmake --build build-bench --target fix_bench
BENCH=./build-bench/fix_bench
```

`-fno-omit-frame-pointer -g` costs almost nothing at `-O3` and makes every
tool below produce readable stacks. Keep a separate build without it for
final numbers if you want to be strict.

---

## 1. Hardware counters with `perf stat`

Install: `sudo apt install linux-tools-common linux-tools-$(uname -r)`.
Allow unprivileged access (or use `sudo`):

```sh
sudo sysctl -w kernel.perf_event_paranoid=1
sudo sysctl -w kernel.kptr_restrict=0
```

Basic counters, repeated 10 times with mean +/- stddev:

```sh
perf stat -r 10 \
  -e cycles,instructions,branches,branch-misses,\
L1-dcache-loads,L1-dcache-load-misses,LLC-loads,LLC-load-misses,\
dTLB-load-misses,page-faults,context-switches,cpu-migrations \
  $BENCH --benchmark_filter=parse_execution_report
```

Interpretation cheat-sheet:

| Counter                         | Healthy for a tag=value scanner            |
|---------------------------------|--------------------------------------------|
| instructions / cycles (IPC)     | 2.5+ on modern x86; <1.5 means stalls      |
| branch-misses / branches        | <1 % ; a tag switch that mispredicts hurts |
| L1-dcache-load-misses / loads   | <2 % ; messages are small, should fit L1   |
| dTLB-load-misses                | ~0 ; otherwise see huge pages (section 12) |

Raw PMU events when a symbolic name is missing. Look up the encoding for
your microarchitecture (`perf list --details`, or the vendor event tables):

```sh
# Intel: cpu/event=0xXX,umask=0xYY/ ; AMD: cpu/event=0xXXX,umask=0xYY/
perf stat -e cpu/event=0xc5,umask=0x00,name=br_misp_retired/ \
          -e cpu/event=0xd1,umask=0x01,name=mem_load_retired_l1_hit/ \
          $BENCH

# Named events from the vendor JSON shipped with perf:
perf stat -e BR_MISP_RETIRED.ALL_BRANCHES,MEM_LOAD_RETIRED.L1_MISS $BENCH
```

Top-down microarchitecture analysis (Intel; AMD has a similar `-M` set on
Zen 4+):

```sh
perf stat -M TopdownL1 $BENCH             # frontend/backend/bad-spec/retiring %
perf stat -M TopdownL2 $BENCH             # one level deeper
perf stat --topdown $BENCH                # newer perf, Ice Lake+ fixed slots
```

Per-thread and interval output for long runs:

```sh
perf stat -I 1000 --per-thread -e cycles,instructions -p $(pgrep fix_bench)
```

Only count user space (drop kernel noise): append `:u`, e.g. `cycles:u`.

---

## 2. Sampling profiles with `perf record` / `report` / `annotate`

```sh
# Frame-pointer call graphs (needs -fno-omit-frame-pointer in *all* code)
perf record -F 4999 -g -o perf.fp.data $BENCH --benchmark_min_time=2s

# DWARF unwinding: works without frame pointers, bigger data files
perf record -F 2999 --call-graph dwarf,16384 -o perf.dwarf.data $BENCH

# LBR-based (Intel, very low overhead, limited depth)
perf record --call-graph lbr -o perf.lbr.data $BENCH
```

Reading the results:

```sh
perf report -i perf.dwarf.data --no-children --sort=dso,sym --stdio | head -60
perf report -i perf.dwarf.data --children -g caller --percent-limit 1
perf report -i perf.dwarf.data --sort=sym,srcline       # line-level attribution
perf annotate -i perf.dwarf.data --stdio -s 'glz::fix::parse<...>' | less
perf annotate -i perf.dwarf.data --stdio --percent-type local-period -l
```

Sample on a specific event instead of cycles (where do the misses happen?):

```sh
perf record -e branch-misses:pp -g $BENCH
perf record -e L1-dcache-load-misses:pp -g $BENCH
perf record -e mem_load_retired.l3_miss:pp -c 1000 --data $BENCH   # with data addresses
```

Flame graphs:

```sh
git clone https://github.com/brendangregg/FlameGraph /opt/FlameGraph
perf script -i perf.dwarf.data | /opt/FlameGraph/stackcollapse-perf.pl \
  | /opt/FlameGraph/flamegraph.pl > fix.svg
```

---

## 3. False sharing and cache-line contention: `perf c2c`

Relevant once the parser is driven from multiple threads (per-thread arenas,
sequence-number counters, shared dictionaries).

```sh
perf c2c record -g -o c2c.data $BENCH --threads=8
perf c2c report -i c2c.data --stdio -NN -c pid,iaddr | less
# Look at "Shared Data Cache Line Table": HITM counts, then the per-line
# offsets to see which fields collide inside one 64-byte line.
```

Fix candidates: `alignas(std::hardware_destructive_interference_size)` on
hot per-thread state; never put a write counter next to read-only config.

---

## 4. Instruction-level simulation: Valgrind callgrind / cachegrind

Deterministic, slow (30-100x), but reproducible on noisy machines such as
shared cloud VMs. Numbers are *simulated* instruction and cache counts, not
wall time.

```sh
valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes \
  --callgrind-out-file=callgrind.out $BENCH --benchmark_min_time=0.05s
callgrind_annotate --auto=yes --inclusive=yes callgrind.out | head -80
kcachegrind callgrind.out        # GUI: call graph + annotated source/asm

# Only measure between client-request markers (see include/valgrind/callgrind.h):
#   CALLGRIND_START_INSTRUMENTATION; ... CALLGRIND_STOP_INSTRUMENTATION;
valgrind --tool=callgrind --instr-atstart=no $BENCH
```

Cache simulation:

```sh
valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes \
  --cachegrind-out-file=cachegrind.out $BENCH
cg_annotate --auto=yes cachegrind.out | less
# Compare two runs:
cg_diff cachegrind.out.before cachegrind.out.after | cg_annotate -
```

Callgrind's `Ir` (instructions retired) per message is a good regression
metric in CI because it does not drift with CPU frequency.

---

## 5. Function-level tracing: `uftrace`

Compile the benchmark with `-pg` (or `-finstrument-functions`) so entry/exit
of every non-inlined function is recorded with timestamps:

```sh
cmake -S . -B build-uftrace -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_CXX_FLAGS="-pg -fno-omit-frame-pointer"
cmake --build build-uftrace --target fix_bench
uftrace record -d uftrace.data ./build-uftrace/fix_bench --benchmark_min_time=0.1s
uftrace report -d uftrace.data --sort=total | head
uftrace graph  -d uftrace.data 'glz::fix::parse'
uftrace replay -d uftrace.data -t 5us            # only calls longer than 5 us
uftrace tui    -d uftrace.data
```

Header-only code inlines aggressively, so uftrace is most useful with
`-O1`-style builds to understand call structure, not to time the hot loop.

---

## 6. Vendor profilers

### Intel VTune (CLI: `vtune`)

```sh
source /opt/intel/oneapi/vtune/latest/env/vars.sh
vtune -collect hotspots -knob sampling-mode=hw -r vt_hot -- $BENCH
vtune -collect uarch-exploration -r vt_uarch -- $BENCH   # full top-down tree
vtune -collect memory-access -knob analyze-mem-objects=true -r vt_mem -- $BENCH
vtune -report hotspots -r vt_hot -format=csv -csv-delimiter=comma > hot.csv
vtune -report summary  -r vt_uarch
```

### AMD uProf (CLI: `AMDuProfCLI`)

```sh
AMDuProfCLI collect --config tbp     -o up_tbp   $BENCH   # time-based sampling
AMDuProfCLI collect --config assess  -o up_ass   $BENCH   # IPC, branch, cache
AMDuProfCLI collect --config ibs     -o up_ibs   $BENCH   # instruction-based sampling
AMDuProfCLI report  -i up_ass/*/ --detail --src --asm
```

Both produce per-instruction attribution that is more precise than
`perf annotate` on their own hardware.

---

## 7. Static throughput analysis of the hot loop: `llvm-mca`

Extract the assembly of the loop you care about:

```sh
# 1. Emit asm for the TU holding the benchmark (or a tiny TU that
#    instantiates just the parser with the hot message type).
clang++ -O3 -march=native -std=c++23 -S -o fix_hot.s \
  -fno-asynchronous-unwind-tables -masm=intel \
  -I include bench/fix_hot_tu.cpp

# 2. Find the function and its loop labels.
c++filt < fix_hot.s | grep -n 'glz::fix::parse' | head
#    Copy the loop body (from .LBB*_N: to the backward jump) into hot_loop.s
#    and wrap it in markers:
#      # LLVM-MCA-BEGIN parse_loop
#      ...
#      # LLVM-MCA-END

# 3. Analyse.
llvm-mca -mcpu=native -iterations=200 -timeline -bottleneck-analysis \
  -resource-pressure hot_loop.s | less
llvm-mca -mcpu=znver4 hot_loop.s     # model a different target
```

Alternative: put `__asm__ volatile("# LLVM-MCA-BEGIN tag_scan");` and the
matching END in the source around the loop, compile with `-S`, and feed the
whole file to `llvm-mca`; it only analyses the marked region. Also handy:
`objdump -d --no-show-raw-insn -M intel -C build-bench/fix_bench | less` to
confirm what actually got inlined.

Read: "Block RThroughput" is the cycles-per-iteration lower bound; the
bottleneck report tells you whether it is the dispatch width, a port, or a
dependency chain (common with running checksum accumulation).

---

## 8. Cycle-accurate timing with `rdtsc` / `rdtscp`

Use this only for micro-measurements where Google Benchmark's overhead
(~20-30 ns per iteration boundary) is comparable to the thing measured, such
as a single-field parse.

Prerequisites, check once per machine:

```sh
grep -o -m1 'constant_tsc\|nonstop_tsc\|rdtscp\|tsc_reliable' /proc/cpuinfo | sort -u
dmesg | grep -i tsc          # "tsc: Refined TSC clocksource calibration: 2995.200 MHz"
cat /sys/devices/system/clocksource/clocksource0/current_clocksource   # expect tsc
```

Calibrate TSC ticks per nanosecond rather than trusting the nominal
frequency:

```cpp
#include <x86intrin.h>
#include <chrono>
#include <cstdint>

inline uint64_t tsc_begin() {
   _mm_lfence();                       // drain earlier instructions
   uint64_t t = __rdtsc();
   _mm_lfence();                       // keep later loads behind the read
   return t;
}
inline uint64_t tsc_end() {
   unsigned aux;
   uint64_t t = __rdtscp(&aux);        // waits for prior instructions to retire
   _mm_lfence();                       // and nothing after it moves up
   return t;
}
inline double tsc_ghz() {
   using clk = std::chrono::steady_clock;
   auto t0 = clk::now(); auto c0 = __rdtsc();
   while (clk::now() - t0 < std::chrono::milliseconds(200)) {}
   auto t1 = clk::now(); auto c1 = __rdtsc();
   return double(c1 - c0) / std::chrono::duration<double, std::nano>(t1 - t0).count();
}
```

Methodology:

1. Warm the instruction and data caches with a few hundred untimed iterations.
2. Time a batch (e.g. 1000 parses) and divide, then take the *minimum* or a
   low percentile over many batches; the min is the least-disturbed estimate
   of the code's own cost, percentiles describe what callers will see.
3. Subtract the empty-loop cost measured the same way.
4. Report both ticks and ns (ticks / tsc_ghz()).
5. Never compare TSC values read on different cores unless the kernel reports
   `constant_tsc` and `nonstop_tsc`; use `rdtscp`'s `aux` (core id) to detect
   migration and discard that sample.

Pin and quiet the machine (root required for most of these):

```sh
# Boot-time: reserve cores 2-3 for measurement.
#   GRUB_CMDLINE_LINUX="isolcpus=2,3 nohz_full=2,3 rcu_nocbs=2,3"
cat /sys/devices/system/cpu/isolated

sudo cpupower frequency-set -g performance
echo 1 | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo        # Intel
echo 0 | sudo tee /sys/devices/system/cpu/cpufreq/boost                # AMD/acpi
echo 0 | sudo tee /sys/devices/system/cpu/cpu3/online                  # park the SMT sibling of cpu2 (check topology first)
cat /sys/devices/system/cpu/cpu2/topology/thread_siblings_list

taskset -c 2 chrt -f 50 $BENCH             # pin + SCHED_FIFO
```

On a shared cloud VM you usually cannot do any of this; say so in the report
(section 14) and lean on `-r N` repetitions, minimums, and instruction
counts instead of wall time.

---

## 9. Google Benchmark

```sh
cmake -S . -B build-bench -DCMAKE_BUILD_TYPE=Release -Dglaze_BUILD_FIX_BENCH=ON \
  -DBENCHMARK_ENABLE_LTO=ON
```

Skeleton for a parse benchmark:

```cpp
#include <benchmark/benchmark.h>

static void BM_parse_new_order_single(benchmark::State& state) {
   const std::string msg = sample_new_order_single();   // tag=value SOH string
   new_order_single out{};
   for (auto _ : state) {
      benchmark::DoNotOptimize(msg.data());             // input must look live
      auto ec = glz::fix::read(out, msg);
      benchmark::DoNotOptimize(ec);
      benchmark::DoNotOptimize(out);                    // result must look used
      benchmark::ClobberMemory();                       // writes may not be elided
   }
   state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(msg.size()));
   state.SetItemsProcessed(state.iterations());
   state.counters["ns/msg"] = benchmark::Counter(
      1.0, benchmark::Counter::kIsIterationInvariantRate | benchmark::Counter::kInvert);
}
BENCHMARK(BM_parse_new_order_single)
   ->Unit(benchmark::kNanosecond)
   ->MinWarmUpTime(0.5)
   ->Repetitions(20)
   ->ReportAggregatesOnly(true)
   ->ComputeStatistics("p50", [](const std::vector<double>& v) {
      auto s = v; std::nth_element(s.begin(), s.begin() + s.size()/2, s.end());
      return s[s.size()/2]; })
   ->ComputeStatistics("min", [](const std::vector<double>& v) {
      return *std::min_element(v.begin(), v.end()); });
BENCHMARK_MAIN();
```

Notes:

* `DoNotOptimize(x)` forces `x` to exist in a register or memory; it does not
  prevent the compiler hoisting *computation* that only depends on constants.
  Feed the input through `DoNotOptimize` or load it from a volatile index.
* `ClobberMemory()` is a compiler barrier for all memory, use it after the
  serializer writes into a buffer the loop never reads.
* Prefer `--benchmark_repetitions=N --benchmark_report_aggregates_only=true`
  on the command line over hard-coding, and always look at `median` and `cv`
  (coefficient of variation): cv above ~3 % means the run is not usable.

Running and comparing:

```sh
$BENCH --benchmark_filter='parse|write' --benchmark_min_time=1s \
       --benchmark_repetitions=20 --benchmark_report_aggregates_only=true \
       --benchmark_out=run_a.json --benchmark_out_format=json
# after a change:
$BENCH ... --benchmark_out=run_b.json
python3 -I third_party/benchmark/tools/compare.py benchmarks run_a.json run_b.json
# compare.py prints a U-test p-value per benchmark; treat p > 0.05 as "no change".
$BENCH --benchmark_perf_counters=CYCLES,INSTRUCTIONS,BRANCH-MISSES   # if built with libpfm
```

---

## 10. nanobench

Single header, good for quick in-tree experiments and for its built-in
`perf_event` counters:

```cpp
#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>

int main() {
   const std::string msg = sample_new_order_single();
   new_order_single out{};
   ankerl::nanobench::Bench b;
   b.title("fix parse").unit("msg").batch(1)
    .warmup(1000).minEpochIterations(20000).epochs(31)
    .performanceCounters(true)       // cycles, instr, branches, misses via perf_event
    .relative(true);
   b.run("read new_order_single", [&] {
      auto ec = glz::fix::read(out, msg);
      ankerl::nanobench::doNotOptimizeAway(ec);
      ankerl::nanobench::doNotOptimizeAway(out);
   });
   std::ofstream json("nanobench.json");
   b.render(ankerl::nanobench::templates::json(), json);
}
```

The output includes `err%` (median absolute percent error across epochs) and
`ins/op`, `cyc/op`, `IPC`, `bra/op`, `miss%`; nanobench prints `:wavy:`
when a result is too noisy to trust, treat that as a failed run.

---

## 11. Page faults, RSS and allocations

```sh
perf stat -e page-faults,minor-faults,major-faults $BENCH
/usr/bin/time -v $BENCH 2>&1 | grep -E 'Maximum resident|page faults|Elapsed|context'
perf trace -F all --no-syscalls $BENCH              # per-fault addresses
perf record -e page-faults -g $BENCH && perf report --stdio | head -40

# Heap: a parser that allocates per message is a bug. Prove it:
valgrind --tool=massif --pages-as-heap=no $BENCH --benchmark_min_time=0.05s && ms_print massif.out.*
heaptrack $BENCH && heaptrack_print heaptrack.fix_bench.*.zst | head -40
LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libjemalloc.so MALLOC_CONF=stats_print:true $BENCH 2>&1 | grep -E 'allocated|nmalloc'
strace -f -c -e trace=mmap,munmap,brk,madvise $BENCH    # syscall counts
```

Zero `minor-faults` after warm-up and zero `brk/mmap` during the timed
region are the targets.

---

## 12. Huge pages

Only matters for large message buffers or dictionaries (dTLB misses in
section 1); a single FIX message fits in a few 4 KiB pages.

```sh
cat /sys/kernel/mm/transparent_hugepage/enabled      # [always] madvise never
grep -E 'AnonHugePages|HugePages_' /proc/meminfo
```

THP via `madvise` (works unprivileged when the setting is `always` or
`madvise`):

```cpp
#include <sys/mman.h>
void* buf = std::aligned_alloc(2u << 20, size_rounded_to_2MiB);
madvise(buf, size_rounded_to_2MiB, MADV_HUGEPAGE);
```

Explicit hugetlbfs (reserved pages, never split, needs root once):

```sh
echo 64 | sudo tee /proc/sys/vm/nr_hugepages
sudo mkdir -p /mnt/huge && sudo mount -t hugetlbfs none /mnt/huge
# then mmap(..., MAP_HUGETLB | MAP_ANONYMOUS, ...) or a file under /mnt/huge
perf stat -e dTLB-load-misses,dTLB-loads $BENCH     # before/after
```

Verify at runtime: `grep -B1 'AnonHugePages: *[1-9]' /proc/$(pgrep fix_bench)/smaps`.

---

## 13. Noise control checklist

Do before every measurement that will be written down:

```sh
# Identify the box
lscpu | grep -E 'Model name|Thread|Core|Socket|NUMA|L1d|L2|L3'
cat /proc/sys/kernel/perf_event_paranoid
uptime                                   # load average should be ~0 beyond your run
cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor | sort | uniq -c
cat /proc/sys/kernel/randomize_va_space  # 2 = ASLR on; layout noise between runs
```

Measures, from cheapest to most intrusive:

1. Close everything else; on a VM, accept that neighbours exist and repeat
   the whole experiment at a different time of day.
2. Pin with `taskset -c N`; keep I/O (log writing) off the pinned core.
3. Governor `performance`, turbo off, SMT sibling idle or offline.
4. `isolcpus` + `nohz_full` for the measurement cores (section 8).
5. Disable ASLR for layout-sensitive microbenchmarks:
   `setarch $(uname -m) -R $BENCH`, and record that you did.
6. Randomise or fix link order deliberately; a 1-3 % swing from code
   alignment alone is normal. `-falign-functions=64` reduces it.
7. Use the same input corpus file (checked in, hashed) for every run:
   `sha256sum bench/data/*.fix`.
8. Interleave A/B runs (A B A B ...) instead of all-A then all-B so slow
   drifts (thermal, neighbour load) hit both sides equally.
9. Prefer counts that do not depend on frequency (instructions, callgrind
   `Ir`) as the CI gate; use wall time for human reports.

---

## 14. How we report numbers

* We publish only numbers printed by our own benchmark binaries or by the
  tools above run on our own code, with the exact command used. No figures
  copied from other projects' pages, and no comparisons against software we
  did not run ourselves under the same conditions.
* Every number carries a label with at least:
  machine class (e.g. `shared cloud VM, 4 vCPU, unknown host load`,
  or `dedicated workstation, Ryzen 9 7950X, SMT off, governor performance`),
  compiler and version (`clang 19.1.0`, `gcc 14.2`), flags
  (`-O3 -march=native`), libc/allocator if non-default, and the commit hash.
* State the statistic: `median of 20 repetitions, cv 1.2 %`, or
  `min over 31 epochs`. A bare "X ns" is not acceptable.
* Noisy results (cv > 3 %, nanobench `:wavy:`, load average > 1 during the
  run) are reported as noisy or not reported.
* Microarchitectural claims ("branch-miss bound") must point to the counter
  output that supports them, not to intuition.
* Keep the raw JSON/CSV from the run next to the write-up so anyone can
  regenerate the table.

Template:

```
glaze-fix read new_order_single (142 bytes): 118 ns/msg, 1.20 GB/s
  statistic: median of 20 reps, cv 0.9 %
  machine:   shared cloud VM, 2 vCPU (Intel Xeon, family 6 model 143), THP=madvise
  compiler:  clang 19.1.0, -O3 -march=native -std=c++23, libstdc++ 14, glibc malloc
  commit:    <sha>   command: fix_bench --benchmark_filter=read_nos --benchmark_repetitions=20
```
