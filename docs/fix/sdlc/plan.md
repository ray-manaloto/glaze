# glaze-fix: phased plan

Companion to `architecture.md`. Each phase lists the code changes, the tests to add to
`tests/fix_test/fix_test.cpp` (glaze `ut` suites, pipe-delimited messages built with the existing
`frame_msg`-style helper, SOH vectors where the delimiter matters), and the exit criteria. Phases are
ordered so that each one leaves the tree building and all previous tests green. No phase changes a
public signature listed in architecture.md section 7.

## Phase 0: baseline and safety net

Goal: pin current behaviour before touching the hot paths.

Changes
* Add a `fix_golden` suite with a fixed set of complete messages (NewOrderSingle, ExecutionReport,
  Heartbeat with `FIX.4.2`, a News message with raw data 95/96, a message with nested groups
  555/539/448) and their expected decoded structs and re-encoded bytes.
* Add round-trip assertions: `write` then `read` yields an equal struct; `read` then `write` of a
  canonical message yields identical bytes.
* Add an error-position table: for each malformed input, the expected `error_ctx::ec` and `count`.
* Add a `-fno-exceptions -fno-rtti` configuration to `tests/fix_test/CMakeLists.txt` so the
  no-exceptions constraint is checked, not assumed.

Tests
* `golden_decode`, `golden_encode`, `golden_roundtrip`.
* `error_positions` covering: missing trailing SOH, empty tag, non-digit tag, empty value, missing
  `=`, 8 not first, 9 not second, 35 not third, 10 not last, BodyLength mismatch, CheckSum mismatch,
  group count larger than entries, unknown tag with `error_on_unknown_tags = true`.
* `no_exceptions_build` (compile-only target).

Exit criteria
* All existing tests and the new suites pass on GCC, Clang and MSVC in CI.
* Every error path in `scan.hpp` and `codec.hpp` is hit by at least one test (checked by reading
  the coverage report once; no coverage gate is added).

## Phase 1: compile-time tag tables and member dispatch

Goal: replace the linear `member_index<T>` and the `for_each` member search in `decode_struct`.

Changes
* Add `detail::sorted_tags<T>` (sorted `(tag, index, kind)` entries) and `detail::tag_hash<T>`
  (perfect hash for larger `N`), both exposing `member_index<T>(uint32_t)`.
* Add `detail::member_kind` enum and fill it from the member type (`scalar`, `optional`, `group`,
  `raw_data`, `raw_length_of_mapped`).
* Add `detail::decode_table<Opts, T>`: an array of decode function pointers indexed by member index.
* Rewrite `decode_struct` to: look up the entry, switch on kind, call through the table.
* `static_assert` that `tags<T>` has no duplicate tags and that a group's first member tag is not
  also a tag of the enclosing struct (the current code silently relies on this).

Tests
* `tag_table_sorted`: `constexpr` check that `sorted_tags<T>` is sorted and complete for each test struct.
* `tag_table_lookup`: every mapped tag resolves to its index; unmapped neighbours (tag ± 1) resolve to -1.
* `tag_table_large`: a struct with 40+ members exercises the perfect-hash path; same assertions.
* `duplicate_tag_rejected`: a compile-fail test (CMake `try_compile`) for a duplicate key.
* `group_delimiter_dispatch`: groups still start at the delimiter tag and end at the first foreign tag,
  including nested groups and two consecutive groups.

Exit criteria
* Phase 0 suites pass unchanged.
* `decode_struct` contains no `for_each` over members on the per-field path.
* The compile-fail test fails to compile for the intended reason (checked by matching the diagnostic text).

## Phase 2: scanner and single-pass validation

Goal: branch-light `next_field` and an accumulating cursor that removes the separate `validate` walk
from `from<FIX, T>::op`.

Changes
* Rewrite tag parsing in `next_field` as a bounded digit loop.
* Add an 8-byte SWAR delimiter search; keep byte-wise fallback for the tail.
* Add `sum_` and `body_start_` to `field_cursor`; `next_field` accumulates the byte sum of each field.
* Add an envelope state machine to `from<FIX, T>::op` that enforces 8/9/35 ordering, MsgType, 10 last,
  BodyLength and CheckSum from the cursor's accumulators. Remove the second `field_cursor hc` walk.
* Reimplement `validate` on the accumulating cursor so the standalone function and the reader share code.
* Keep `scan_state` raw-data handling; add the running sum for raw-data bytes as well.

Tests
* `scan_swar_boundaries`: fields whose SOH falls at every offset 0..15 from an 8-byte boundary;
  messages shorter than 8 bytes; a value that is exactly 8 and exactly 16 bytes.
* `scan_delimiter_in_tag`: `"a|b=c|"` style corruption still rejected.
* `scan_rawdata_sum`: raw data containing SOH and bytes 0x80..0xFF; checksum agrees with `checksum()`.
* `single_pass_envelope`: for each Phase 0 error case, `from<FIX, T>` reports the same `ec` and `count`
  as before. Add cases where validation options are off (`validate_checksum = false`,
  `validate_body_length = false`, `validate_msg_type = false`) and the message is otherwise malformed.
* `validate_matches_reader`: for a corpus of valid and invalid messages, `validate()` and
  `read<fix_opts>` agree on success and on `ec`.
* `body_fragment_read`: a message that starts at 35 (no 8/9) still decodes, as today.

Exit criteria
* `from<FIX, T>::op` walks the input once.
* All Phase 0 error positions are unchanged.
* SWAR path and byte-wise path produce identical `field` sequences on the whole golden corpus
  (test runs both by forcing the fallback through an internal switch).

## Phase 3: writer with precomputed prefixes and back-patching

Goal: write straight into the caller's buffer, no temporary `std::string`s, checksum accumulated
while writing.

Changes
* Add `detail::tag_prefix<Tag>` (bytes and byte-sum) and use it in `encode_field`, group count
  fields and the `"35="` header. Remove `put_tag`'s run-time `to_chars` from the per-field path.
* Add `detail::write_sink` over `b`/`ix` that calls `ensure_space`, copies, and accumulates the sum.
* Rewrite `to<FIX, T>::op` to write header, reserved BodyLength slot, body, then patch BodyLength and
  append CheckSum. Default output is canonical (no leading zeros); add `fix_opts::pad_body_length`
  for the zero-padded variant.
* Fold the delimiter check into the string-copy loop of the sink; skip it by type for numeric and
  typed values.
* Replace the temporary `std::string digits` in `append_decimal` with a stack buffer.

Tests
* `write_bytes_identical`: for every golden message, the new writer produces the same bytes as the
  Phase 0 recorded output.
* `write_bodylength_widths`: bodies of 9, 99, 999, 9999 and 99999 bytes produce correct 9 and 10 values,
  in both canonical and padded modes.
* `write_into_small_buffer`: writing into a `std::string` that starts empty, and into one with prior
  content, grows correctly and leaves prior content intact.
* `write_delimiter_in_value`: a string containing `soh` fails with `syntax_error`; raw data containing
  `soh` succeeds.
* `write_empty_fields_skipped`: empty `std::string`, disengaged `std::optional` and empty group are omitted.
* `write_checksum_vs_scan`: the written checksum equals `checksum()` over the written bytes.

Exit criteria
* `to<FIX, T>::op` performs no heap allocation for a struct whose string members are already sized
  (verified with a counting allocator test on the output buffer type).
* Golden encode bytes unchanged.
* Round-trip suite from Phase 0 passes.

## Phase 4: optional SIMD scan and hardening

Goal: a 16-byte compare path where available, and robustness against hostile input.

Changes
* Add SSE2 and NEON variants of the delimiter search behind the existing `next_field` signature,
  selected by the same predefined-macro checks glaze uses elsewhere; keep SWAR as the portable path.
* Add an internal, test-only switch to force each implementation.
* Add a fuzz harness (`tests/fix_test/fix_fuzz.cpp`, libFuzzer when available, otherwise a seeded
  random driver run from `ut`) that feeds bytes to `frame`, `validate`, `read` and `write`→`read`.
* Bounds review of `frame` for truncated inputs at every prefix length of a valid message.

Tests
* `scan_impl_agreement`: SWAR, SIMD and byte-wise paths yield identical fields and errors on the golden
  corpus and on 10k generated messages.
* `frame_every_prefix`: for each valid golden message, every prefix returns 0 (need more) or the full
  length, never `frame_error`; corrupted prefixes return `frame_error` at the right point.
* `fuzz_smoke`: a bounded run of the random driver completes with no sanitizer findings.
* `group_count_bounds`: counts larger than the remaining bytes, zero counts, and counts with leading
  `+` or `-` are rejected.

Exit criteria
* ASan/UBSan CI job over the fix tests is green.
* The fuzz smoke test runs in CI under a time budget.
* Every scan implementation passes the agreement test.

## Phase 5: typed values, documentation and API freeze

Goal: finish the typed value set, align docs with the code, and declare the public surface stable.

Changes
* Add `utc_date_only`, `utc_time_only`, `local_mkt_date` and `month_year` to `types.hpp` with
  parse/append pairs, wired into `decode_scalar` / `encode_scalar`.
* Allow custom raw-data length/data pairs through `glz::meta<T>::fix_raw_data_pairs` (a `constexpr`
  array of `(length_tag, data_tag)`), merged with the standard table at compile time.
* Update `docs/fix/design.md` "Current limits" and `docs/fix/api.md` to the delivered behaviour.
* Mark `glz::fix::detail` as internal in the docs; list the public names from architecture.md section 7.

Tests
* `typed_values_roundtrip`: each new type parses and prints its documented formats, including
  fractional-second precision handling and invalid dates.
* `custom_raw_data_pair`: a struct declaring a custom pair reads and writes a data field containing SOH.
* `api_surface`: a compile-only test that uses every public name with the documented signature.
* `docs_examples_compile`: the snippets in `docs/fix/api.md` are extracted into a test target and built.

Exit criteria
* All suites green across the CI matrix, including the no-exceptions and sanitizer jobs.
* `design.md` and `api.md` contain no statement contradicted by a test.
* No open TODOs in `include/glaze/fix/`.
