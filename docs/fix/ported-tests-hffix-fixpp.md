# Ported tests: hffix and fixpp

Two test targets check the FIX tag=value format against cases taken from two existing open-source
FIX libraries. The cases are rewritten for the shared contract in `include/glaze/fix/fix.hpp`
(see `docs/fix/api.md` on the `fix/core` branch).

| Target | Source | Licence (kept beside the tests) |
|---|---|---|
| `tests/fix_hffix_test` | [jamesdbrock/hffix](https://github.com/jamesdbrock/hffix) `test/src/unit_tests.cpp`, `test/src/reader01.cpp`, `test/src/writer01.cpp`, `test/expected/writer01.fix`, `test/data/fix.4.1.set.1`, `test/data/fix.5.0.set.2` | `LICENSE-hffix` (BSD-style, Copyright 2011 T3 IP, LLC) |
| `tests/fix_fixpp_test` | [Abc-Arbitrage/fixpp](https://github.com/Abc-Arbitrage/fixpp) `tests/visitor_test.cc`, `tests/writer_test.cc`, `tests/message_test.cc`, `tests/data/fix42.log` | `LICENSE-fixpp` (MIT, Copyright (c) 2016 ABC arbitrage) |

## How the cases map to the contract

- **hffix `message_writer` / `message_reader`.** A small `make_msg()` helper builds complete
  messages and fills in 9 and 10. The reader-side checks become `parse_fields`, `validate` and `frame`.
- **fixpp visitor frames.** These are kept byte for byte with `|` as the separator. Many of them
  carry placeholder BodyLength and CheckSum values, such as `9=84`, `9=0000` and `10=213`. Some
  also have no separator after `10=NNN`, so the tests append a `|`. A `repair()` helper rebuilds
  9 and 10 for any test that needs a valid message.
- **Checksum vectors.** hffix's hand-computed checksums are used unchanged: 182, 254, and 230 for
  the `\x80` byte. They show that the sum treats every byte as unsigned.
- **Streaming.** `frame()` is fed the sample files in chunks of 1, 7, 13, 64 and 4096 bytes. It
  must split them into the same messages as a single pass does. Every proper prefix of a message
  must return 0.
- **Sample files:**
  - `fix.4.1.set.1` has 16 FIX.4.1 messages and a trailing newline.
  - `fix.5.0.set.2` has 65 FIXT.1.1 messages.
  - `writer01.fix` has 2 FIX.4.2 messages.
  - `fix42.log` has 330 lines of FIX.4.2. Its 9 and 10 values do not match the content, so it is
    split on newlines and checked after `repair()`.
- **Struct mapping.** These tests use `glz::read` and `glz::write` with `glz::fix_opts` and cover
  groups, nested groups, optional group fields, strict unknown tags (`error_on_unknown_tags`) and
  float output. They also round-trip every sample message type through write then read. The test
  CMake defines `GLZ_FIX_HAS_STRUCT_MAPPING` now that fix/core provides the codec.
- **Malformed input.** Every single-byte change and every truncation of a valid message must be
  rejected. The group tests cover bad counts, entries without their delimiter, and bad number,
  Boolean and char values.

## Open questions for `fix/core`

1. Length-prefixed data fields containing SOH: supported since core v2 and tested (`data_with_embedded_soh`, `raw_data_roundtrip`).
2. Should `parse_fields` and `validate` accept a final `10=NNN` with no SOH after it? The tests
   assume they should not: the message counts as incomplete.
3. Empty values (`37=`): settled by core. They are rejected with `syntax_error`, and the test now
   expects that.
4. Does `glz::read` check BeginString (8)? fixpp rejects `FIX.5.1`.
5. Typed times: core v2 has `utc_timestamp` (tested). UTCDateOnly and UTCTimeOnly are still text (skipped).

## Known core gaps (guarded by `GLZ_FIX_KNOWN_FAILURES`)

- An unknown tag inside a group entry ends the group, although unknown top-level tags are skipped
  by default (fixpp snapshot frame, tag 9063).
- Floats are written with an exponent (`1e+06`). The FIX float type has no exponent.
