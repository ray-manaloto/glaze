# glaze-fix benchmark

Read/write benchmark for glaze's FIX tag=value format (`include/glaze/fix/`) against
[hffix](https://github.com/jamesdbrock/hffix) (header-only, BSD-2-Clause), fetched by CMake
FetchContent at pinned commit `797ce7db0bd1c240acee88fad297b69bec428778`, and optionally
[QuickFIX C++](https://github.com/quickfix/quickfix) (QuickFIX Software License) at pinned commit
`386ce46e917ae494ab6e90b1be90fd421cdbe3f9` (`-DFIX_BENCH_QUICKFIX=ON`, on by default in `run.sh`;
`QUICKFIX=OFF benchmarks/fix/run.sh` skips it). Neither library is vendored; both are downloaded
at configure time.

This is a standalone CMake project; it is not part of the default glaze build.

```sh
benchmarks/fix/run.sh            # generate corpus, configure, build, print machine + results
```

## Corpus

`gen_corpus.py` writes `data/corpus.fix`: 10,000 synthetic FIX 4.4 messages from a fixed seed
(`20261105`), rotating NewOrderSingle (35=D), ExecutionReport (35=8) and
MarketDataIncrementalRefresh (35=X, 1–8 entries in the NoMDEntries 268 group). BodyLength (9) and
CheckSum (10) are computed by the generator; the benchmark re-validates every message with
`glz::fix::validate` on load. All values are random; no real-world messages were used.
SHA-256 of the committed corpus: `760ff6c04b5975455abd1f08ff6f78d2e3b55278de7b942e9ef1e927a5b783b5`.

## Method

* Compiled with plain `-O3 -DNDEBUG` (no `-march=native`), C++23.
* Each benchmark: 3 warm-up passes over the corpus, then 30 timed passes. Every pass is cut into
  batches of 100 consecutive messages; each batch is timed with `steady_clock` and gives one
  ns/message sample. The table shows the median and p99 of those samples and overall messages/s.
  (Per-batch rather than per-message timing keeps clock overhead out of the numbers; p99 is
  therefore a p99 of 100-message averages, not of single messages.)
* Message type is determined once while loading, outside timing, and used to dispatch for both
  libraries.
* **read** decodes into the same C++ structs (owned `std::string` fields, `double` prices) for
  both libraries. glaze-fix uses `glz::read<glz::fix_opts{}>`, which checks header order,
  BodyLength and CheckSum and MsgType. hffix uses `message_reader` + a field switch; its
  `is_valid()` checks framing but does not compute the checksum, so a row with an explicit
  checksum check is included, along with a glaze row with `validate_checksum = false`.
* **write** serialises the pre-decoded structs into a reused buffer (`std::string` for glaze,
  a 4 KiB char array for hffix). glaze writes doubles with shortest round-trip `to_chars`; the
  hffix code writes prices with `push_back_decimal` (mantissa × 10^-2), so its output is not
  byte-identical, but carries the same fields.
* QuickFIX: read is `Message::setString(s, validate=true, &FIX44 DataDictionary)` (which checks
  BodyLength and CheckSum and parses the 268 group through the dictionary) followed by
  `getField`/`getGroup` into the same structs; input is held as `std::string` since that is what
  the API takes. Write builds a fresh `FIX::Message` with `setField`/`addGroup` and calls
  `toString`. QuickFIX orders body fields by tag number, so its output is not byte-identical to
  the corpus (the printed mismatch count reflects that), but carries the same fields.
* Correctness checks printed before the table: glaze's write of each decoded message reproduces
  the corpus bytes exactly, and hffix's decode agrees with glaze's on sampled fields.

## Results

**Ran on a shared 4-vCPU cloud VM; numbers are only indicative and vary from run to run.**
Output of `run.sh`:

```
## Machine
CPU(s):                                  4
Model name:                              Intel(R) Xeon(R) Processor @ 2.80GHz
Thread(s) per core:                      1
Core(s) per socket:                      4
Socket(s):                               1
L1d cache:                               128 KiB (4 instances)
L2 cache:                                4 MiB (4 instances)
L3 cache:                                33 MiB (1 instance)
compiler: c++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0

## Results
corpus: /home/user/glaze/benchmarks/fix/data/corpus.fix
messages: 10000, bytes: 2252403 (avg 225.2 bytes/msg)

glaze write == corpus bytes: 0/10000 mismatches
hffix decode == glaze decode: 0/10000 mismatches

quickfix decode == glaze decode: 0/10000 mismatches
quickfix write == corpus bytes: 10000/10000 mismatches

| benchmark | median ns/msg | p99 ns/msg | msgs/s |
|---|---:|---:|---:|
| glaze-fix read | 1404.6 | 3345.8 | 609273 |
| hffix read | 383.6 | 1167.8 | 2424635 |
| glaze-fix read (no 10= check) | 1272.9 | 3315.3 | 732449 |
| hffix read + 10= check | 403.5 | 1281.4 | 2209235 |
| glaze-fix write | 925.4 | 1464.2 | 1027205 |
| hffix write | 255.1 | 608.7 | 3713412 |
| quickfix read | 2464.8 | 6019.9 | 367733 |
| quickfix write | 2794.5 | 4208.4 | 347530 |
```

On this run glaze-fix is several times slower than hffix for both read and write, and faster
than QuickFIX for both. The glaze-fix codec has not been optimised yet; this benchmark exists to
measure that work.
