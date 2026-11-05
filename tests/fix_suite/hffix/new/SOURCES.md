# Sources for fix_suite_hffix_fix8.cpp

All tests in this file are new relative to `origin/fix/tests-hffix-fixpp`
(`tests/fix_hffix_test/fix_hffix_test.cpp`, `fix_hffix_more.cpp`); duplicates were skipped.

## hffix
- Repo: https://github.com/jamesdbrock/hffix
- Commit: 797ce7db0bd1c240acee88fad297b69bec428778
- Licence: BSD-2-Clause (copy: `LICENSE` beside this file)

| Test | Source file / case |
|---|---|
| set1_market_data_validate | test/data/fix.5.0.set.1 (first `35=X`, first `35=0`) |
| set1_heartbeat_struct_roundtrip | test/data/fix.5.0.set.1 (first heartbeat) |
| set1_market_data_group_read | test/data/fix.5.0.set.1 (first `35=X`, NoMDEntries 268 / delimiter 279) |
| set1_market_data_exact_rewrite | test/data/fix.5.0.set.1 |
| set1_stream_framing | test/data/fix.5.0.set.1 (stream shape: hb, hb, X) |
| set1_wrong_msg_type_rejected | test/data/fix.5.0.set.1 |
| msg_type_two_chars | test/src/unit_tests.cpp `msg_type_string` |
| writer_bounds_header_trailer | test/src/unit_tests.cpp `message_writer_bounds` |
| writer_bounds_string_char_int | test/src/unit_tests.cpp `message_writer_bounds` |
| writer_bounds_decimal | test/src/unit_tests.cpp `message_writer_bounds` |
| writer_bounds_timestamp | test/src/unit_tests.cpp `message_writer_bounds` |
| chrono_nano_roundtrip | test/src/unit_tests.cpp `chrono_nano` |
| chrono_nano_parse | test/src/unit_tests.cpp `chrono_nano` |
| checksum_zero_padded_three_digits | test/src/unit_tests.cpp `message_writer_bounds` / `checksum` (adapted) |
| missing_trailer_rejected | test/src/unit_tests.cpp `basic` / `null_field_value` (adapted) |
| body_length_beyond_end_is_incomplete | test/src/unit_tests.cpp `data_length` (adapted) |
| unknown_fixt_tags_skipped_or_rejected | test/src/unit_tests.cpp `iterating` + set.1 tags 1180/1181 (adapted) |
| group_entry_must_start_with_delimiter | shape derived from test/data/fix.5.0.set.1 |
| group_count_vs_entries | shape derived from test/data/fix.5.0.set.1 |

Adapted = hffix exercises its own writer/reader API (buffer bounds, iterators); the glaze test
checks the equivalent observable contract (byte sizes, BodyLength/CheckSum, framing, errors).

## fix8 — skipped
- Repo: https://github.com/fix8/fix8, LGPL-3.0. Not cloned: its test data (`test/*.xml`, unit test
  sources) carries the LGPL header without a separate permissive grant, so redistributing it in a
  MIT-licensed test file was not clearly permitted; omitted.

## fixpp — skipped
- No canonical repository could be identified and cloned within the time budget; omitted.
