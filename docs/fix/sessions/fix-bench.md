# Session notes: fix/bench

Branch `fix/bench`, from `origin/fix/core` (e5babf6).

## Done
* `benchmarks/fix/`: standalone CMake project (not built by default), `gen_corpus.py`
  (deterministic 10k-message FIX 4.4 corpus, seed 20261105), `data/corpus.fix`, `fix_bench.cpp`,
  `run.sh`, `README.md` with machine info and the results table.
* Message structs: NewOrderSingle (D), ExecutionReport (8), MarketDataIncrementalRefresh (X,
  group 268).
* Libraries: glaze-fix, hffix (FetchContent, pinned 797ce7d) and QuickFIX C++ (FetchContent,
  pinned 386ce46, opt-in `-DFIX_BENCH_QUICKFIX=ON`, builds in ~1 min on 4 vCPU). Read, read
  with/without checksum, write.
* Correctness: glaze write reproduces corpus bytes 0/10000 mismatches; hffix decode agrees with
  glaze on sampled fields 0/10000 mismatches.

## Not done / left
* QuickFIX write orders fields by tag, so it is not byte-identical to the corpus (expected,
  reported as 10000/10000 mismatches by the check). Could pass a message order to match.
* Per-message (rather than per-100-message batch) latency distribution.
* `std::string_view` variants of the structs for zero-copy read comparison.
* Profiling glaze-fix read/write: on this VM it is ~3x slower than hffix on read and ~4x on write; faster than QuickFIX on both.
* The bench is not built with the glaze test flags (`-fno-exceptions -fno-rtti -Werror`); hffix
  uses exceptions in places.
