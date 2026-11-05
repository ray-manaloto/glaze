# Session notes: `fix/tests-hffix-fixpp`

## Done

- `tests/fix_hffix_test/` and `tests/fix_fixpp_test/` are ut test targets, registered in
  `tests/CMakeLists.txt`. They cover:
  - checksums
  - BodyLength and field-order checks
  - empty values and data fields
  - multi-message iteration
  - streaming and incomplete buffers (`frame`)
  - custom separators
  - repeating groups, including nested and empty groups and unknown tags, at the scanner level
  - field wire forms
  - all copied sample files
- Results with the local stub, built with g++ 13 using `-std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror`:
  - hffix: 21 tests and 144 asserts pass.
  - fixpp: 18 tests and 70 asserts pass.
  - Both targets are also clean under `-fsanitize=address,undefined`.
- `include/glaze/fix/fix.hpp` is a **local stub** of the contract. It implements only
  `parse_fields`, `checksum`, `validate` and `frame`, plus `glz::FIX` and `glz::fix_opts`.
  **Replace it with `fix/core`'s header** when that branch lands. `fix/core` was not on the remote
  during this session.
- Design note: `docs/fix/ported-tests-hffix-fixpp.md`. It describes how the cases map to the
  contract and lists the open questions for core.

## Not done / skipped (printed as `SKIP name: reason` when the tests run)

- Struct-mapping tests are written but built only with `-DGLZ_FIX_HAS_STRUCT_MAPPING`. Core should
  define this macro, or the test CMake should add it, once `glz::read` and `glz::write<fix_opts>`
  exist. They have not been compiled yet, so expect small fixes.
- hffix `msg_type_string`: glaze has no FIX dictionary.
- hffix `message_writer_bounds`: needs fixed-size buffer writes.
- hffix and fixpp typed chrono, date and time tests: the contract has no time types. The test
  vectors are recorded in the skip messages.
- Raw data containing SOH (95/96).
- Reader rejection of BeginString `FIX.5.1`.
- hffix `test/data/fix.5.0.set.1` (2 MB) was not copied.
- Not ported:
  - fixpp `bench_test`, `*_bench` (benchmarks)
  - fixpp `message_test` getters and setters, which are fixpp API specific (group creation is
    covered by the struct tests)
  - fixpp `xml/` (code generator)
  - hffix `util/fixprint`
  - hffix `fixspec/` (FIX specification archives)
- clang 18 with libstdc++ 13 rejects glaze's own `glaze/util/expected.hpp` in this container
  (no `std::expected`). This is an environment problem, not a problem in these tests; only GCC was verified.
- The configure step needs CMake 3.31 or newer. The container has 3.28, so a pip-installed CMake 4.4
  was used: `cmake --preset gcc-debug`, then `cmake --build build/debug-gcc --target fix_hffix_test fix_fixpp_test`,
  then `ctest -R fix_`. Both targets pass.
- Pushing was blocked at first: the git proxy returned 403 until `ray-manaloto/glaze` was added to
  the session's sources. After that the branch was pushed.

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

The reference repositories were cloned with `git clone --depth 1` into `/tmp/refs/`. They are not committed.

## Next steps

1. Merge `fix/core`, delete the stub `include/glaze/fix/fix.hpp` in favour of core's header, and
   rebuild both targets. Then define `GLZ_FIX_HAS_STRUCT_MAPPING` and fix the struct tests to
   match core's real API: how `fix_opts` is constructed, whether header tags 49/56/34/52 need
   members, and how optional group fields work.
2. Get core's answers to the open questions in `docs/fix/ported-tests-hffix-fixpp.md` and turn
   the matching SKIPs into tests.
3. Optionally add `fix.5.0.set.1` (2 MB) through a fetch step instead of committing it.
