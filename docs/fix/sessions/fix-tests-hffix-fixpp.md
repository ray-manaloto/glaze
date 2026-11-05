# Session notes: `fix/tests-hffix-fixpp`

## Done

- `tests/fix_hffix_test/` and `tests/fix_fixpp_test/` are ut test targets, registered in
  `tests/CMakeLists.txt`. They cover:
  - checksums
  - BodyLength and field-order checks
  - empty values (rejected by the contract) and data fields
  - multi-message iteration
  - streaming and incomplete buffers (`frame`, including `frame_error`)
  - custom separators
  - repeating groups, including nested and empty groups and unknown tags
  - field wire forms
  - struct mapping through `glz::read` and `glz::write<fix_opts>`, including write-then-read round trips
  - more message types: Logon, Heartbeat (FIX.4.2 and FIX.4.4), NewOrderSingle, ExecutionReport,
    MarketDataSnapshot and IncrementalRefresh, Quote, ResendRequest, and the two-character type `BF`
  - nested groups (NoUnderlyings > NoUnderlyingSecurityAltID) read and written
  - malformed input: every single-byte change and every truncation of a valid message, header and
    trailer errors, group count too small or too large, a group entry without its delimiter, bad
    number, Boolean and char values, MsgType mismatch, strict vs default unknown tags
  - all copied sample files, read into structs: fix.4.1.set.1 (ExecutionReports), fix.5.0.set.2
    (FIXT.1.1 orders, logons, ResendRequest), fix42.log (330 Quotes)
- Each target has two sources: `fix_<lib>_test.cpp` (the first port) and `fix_<lib>_more.cpp`
  (the cases added later in the session).
- `tests/fix_fixpp_test/data/fix42.log` is force-added, because the repository's `.gitignore` excludes `*.log`.
- `fix/core` v2 was merged at about 07:37 UTC. It adds raw-data fields and typed `utc_timestamp`
  and `decimal`. The raw-data (95/96 with SOH) and UTCTimestamp skips became real tests, and the
  decimal type is shown writing `1000000` without an exponent.
- `fix/core` v1 was merged at 07:15 UTC, and the local stub header was replaced with core's header.
  Struct-mapping tests are on by default: the test CMake defines `GLZ_FIX_HAS_STRUCT_MAPPING`.
- Results against fix/core, built with g++ 13 using `-std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror`:
  - hffix: 50 tests pass (24 + 26).
  - fixpp: 51 tests pass (24 + 27).
  - Both targets are also clean under `-fsanitize=address,undefined`.
- Design note: `docs/fix/ported-tests-hffix-fixpp.md`.

## Known core gaps found by these tests (skipped unless built with `-DGLZ_FIX_KNOWN_FAILURES`)

- fixpp `should_visit_snapshot_frame_struct`: an unknown tag (9063) inside a group entry ends the
  group, although core skips unknown tags at the top level by default. The read then fails with "repeating group count
  does not match its entries". fixpp's non-strict mode accepts it. A variant with the custom tags
  removed passes.
- fixpp `should_write_float_field`: `1000000.0` is written as `1e+06`, but the FIX float type has
  no exponent. fixpp expects `1000000`.

## Core behaviour the tests pin down (not bugs, but worth knowing)

- Strict mode is `fix_opts::error_on_unknown_tags = true`, a core extension. glaze's own
  `error_on_unknown_keys` has no effect on FIX reads. The first port's strict-mode test passed only
  because of a MsgType mismatch. It now uses `35=A` and expects `unknown_key`.
- With default options, a group whose count is too small (268=1 followed by two entries) is
  accepted: the extra entry's tags are skipped as unknown top-level tags. Only strict mode rejects it.
- A repeated tag inside a group entry that is not the delimiter overwrites the earlier value. It
  does not start a new entry.

## Not done / skipped (printed as `SKIP name: reason` when the tests run)

- hffix `msg_type_string`: glaze has no FIX dictionary.
- hffix `message_writer_bounds`: needs fixed-size buffer writes.
- hffix UTCTimeOnly and fixpp UTCDateOnly/UTCTimeOnly: core v2 types only UTCTimestamp. The test
  vectors are recorded in the skip messages.
- Reader rejection of BeginString `FIX.5.1`.
- hffix `test/data/fix.5.0.set.1` (2 MB) was not copied.
- Not ported:
  - fixpp `bench_test`, `*_bench` (benchmarks)
  - fixpp `message_test` type-list and getter/setter internals. The behaviour-level cases are
    ported as struct tests, and the rest print SKIP.
  - fixpp `xml/` (code generator)
  - hffix `util/fixprint`
  - hffix `fixspec/` (FIX specification archives)
- hffix `null_field_value` was changed. hffix iterates over `37=`, but the contract rejects empty
  values, so the test now expects a `syntax_error`.
- clang 18 with libstdc++ 13 rejects glaze's own `glaze/util/expected.hpp` in this container
  (no `std::expected`), so only GCC was verified.
- The configure step needs CMake 3.31 or newer. The container has 3.28, so a pip-installed CMake 4.4
  was used: `cmake --preset gcc-debug`, then `cmake --build build/debug-gcc --target fix_hffix_test fix_fixpp_test`,
  then `ctest -R fix_`.
- Pushing was blocked at first: the git proxy returned 403 until `ray-manaloto/glaze` was added to
  the session's sources.

## Provenance of every ported test

| Glaze test | Source repo | File | Original test | Licence |
|---|---|---|---|---|
| checksum_empty, checksum, checksum_negative, checksum_calc | jamesdbrock/hffix | test/src/unit_tests.cpp | same names | BSD-style (LICENSE-hffix) |
| basic, basic_preconditions | jamesdbrock/hffix | test/src/unit_tests.cpp | basic | BSD-style |
| null_field_value, data_length, iterating, header, read_string, msg_type_string (skip) | jamesdbrock/hffix | test/src/unit_tests.cpp | same names | BSD-style |
| chrono_text, chrono_typed (skip) | jamesdbrock/hffix | test/src/unit_tests.cpp | chrono, chrono_nano | BSD-style |
| message_writer_bounds (skip), field_encodings (struct) | jamesdbrock/hffix | test/src/unit_tests.cpp | message_writer_bounds | BSD-style |
| reader01_writer01_fix, reader01_struct, writer01_roundtrip, streaming_chunks | jamesdbrock/hffix | test/src/reader01.cpp, test/src/writer01.cpp, test/expected/writer01.fix, reader01.txt | examples | BSD-style |
| data_fix_4_1_set_1, data_fix_5_0_set_2 | jamesdbrock/hffix | test/data/* | sample data | BSD-style |
| checksum_mismatch_rejected, body_length_mismatch_rejected, zero_padded_body_length_accepted, incomplete_prefixes, custom_separator | written for this port, from FIX spec rules | - | - | glaze MIT |
| should_visit_* (logon, repeating group, custom message, incremental refresh, snapshot, nested groups, empty group, unknown tags, multiple chars message type, tag), should_skip_unknown_tags, should_stop_when_encountering_invalid_fix_version, should_stop_in_strict_mode_... (struct) | Abc-Arbitrage/fixpp | tests/visitor_test.cc | same names | MIT (LICENSE-fixpp) |
| should_parse_utc_date/time/timestamp (skip) | Abc-Arbitrage/fixpp | tests/visitor_test.cc | same names | MIT |
| should_compute_proper_length_and_checksum, field_wire_forms, should_write_repeating_groups (struct), should_write_float_field (struct) | Abc-Arbitrage/fixpp | tests/writer_test.cc | same / should_write_{bool,char,float,utc_timestamp,int}_field | MIT |
| fix42_log, fix42_log_streaming | Abc-Arbitrage/fixpp | tests/data/fix42.log (used by bench_test.cc) | sample data | MIT |
| missing_final_separator_is_incomplete, malformed_fields_rejected, group_count_mismatch_rejected | written for this port | - | - | glaze MIT |
| fix_hffix_more.cpp: fix_4_1_set_1_message_types, fix_4_1_execution_reports, msg_type_mismatch, fix_5_0_set_2_*, fixt_orders_read_and_roundtrip, fixt_logons, fixt_resend_request | jamesdbrock/hffix | test/data/fix.4.1.set.1, test/data/fix.5.0.set.2 | sample data | BSD-style |
| fix_hffix_more.cpp: writer01_*_roundtrip, writer01_fix_reads_into_struct, stream_of_written_messages, market_order_without_price | jamesdbrock/hffix | test/src/writer01.cpp, test/expected/writer01.fix | example | BSD-style |
| fix_hffix_more.cpp: single_byte_corruption_detected, every_truncation_detected, header_errors, frame_garbage, bad_number_in_struct, write_rejects_delimiter_in_value, value_may_contain_equals | written for this port (hffix reader is_complete / is_valid semantics) | - | - | glaze MIT |
| fix_fixpp_more.cpp: nested_groups_struct, nested_groups_roundtrip, incremental_refresh_*, logon_struct, multi_char_msg_type | Abc-Arbitrage/fixpp | tests/visitor_test.cc, tests/writer_test.cc | should_visit_nested_repeating_groups, should_write_nested_repeating_groups, should_visit_incremental_refresh_frame, should_visit_logon_frame, should_visit_message_with_multiple_chars_message_type | MIT |
| fix_fixpp_more.cpp: heartbeat_42_and_44 | Abc-Arbitrage/fixpp | tests/writer_test.cc | should_write_heartbeat_message_42 / _44 | MIT |
| fix_fixpp_more.cpp: should_optionally_get, should_overwrite_tags_in_message, should_visit_custom_message_struct, read_into_filled_struct | Abc-Arbitrage/fixpp | tests/message_test.cc, tests/visitor_test.cc | should_optionally_get, should_overwrite_tags_in_message, should_extend_message_properly, should_visit_custom_message | MIT |
| fix_fixpp_more.cpp: SKIP lines for should_throw_when_missing_fields_in_repeating_group, should_throw_when_getting_not_present_tag (core has no required fields), should_bring_correct_version_with_message_type, should_compare_version, should_set_tag_if_defined (compile-time fixpp API) | Abc-Arbitrage/fixpp | tests/message_test.cc | same names | MIT |
| fix_hffix_more.cpp: data_with_embedded_soh, raw_data_roundtrip, raw_data_length_past_end, chrono_timestamp, chrono_nano_timestamp, chrono_bad_timestamp | jamesdbrock/hffix | test/src/unit_tests.cpp | data_length, chrono, chrono_nano | BSD-style |
| fix_fixpp_more.cpp: should_parse_utc_timestamp, should_write_utc_timestamp_field, should_write_decimal_field, decimal_keeps_scale | Abc-Arbitrage/fixpp | tests/visitor_test.cc, tests/writer_test.cc | should_parse_utc_timestamp(_with_milli/microseconds), should_write_utc_timestamp_field*, should_write_float_field | MIT |
| fix_fixpp_more.cpp: fix42_log_quotes | Abc-Arbitrage/fixpp | tests/data/fix42.log | sample data | MIT |
| fix_fixpp_more.cpp: group_count_*, group_entry_without_delimiter, bad_boolean, bad_char_length, msg_type_mismatch, unknown_tag_strict_vs_lenient, repeated_tag_overwrites, fields_in_any_order, empty_group_omitted_on_write | written for this port (fixpp strict/non-strict visitor semantics) | - | - | glaze MIT |

The reference repositories were cloned with `git clone --depth 1` into `/tmp/refs/`. They are not committed.

## Next steps

1. Merge newer `fix/core` commits, rebuild, and try `-DGLZ_FIX_KNOWN_FAILURES`. Remove each guard
   once core fixes the gap: unknown tags inside groups, and float output without exponents.
2. Get core's answers to the remaining open questions in `docs/fix/ported-tests-hffix-fixpp.md`
   (BeginString check, UTCTimeOnly and UTCDateOnly types) and turn the matching SKIPs into tests.
3. Optionally add `fix.5.0.set.1` (2 MB) through a fetch step instead of committing it.
4. Ask core whether a too-small group count should be an error with default options. The tests
   currently pin the lenient behaviour (`group_count_too_small`).
