# QuickFIX-derived tests for the FIX format

`tests/fix_quickfix_test/` holds unit tests ported from QuickFIX's C++ test suite
(<https://github.com/quickfix/quickfix>, `src/C++/test/`). `qfj_qfn_vectors.inl` adds 43 message vectors from the
QuickFIX/J and QuickFIX/n test suites (licences `QUICKFIXJ_LICENSE`, `QUICKFIXN_LICENSE`). These are tests of the glaze FIX API contract (`glaze/fix/fix.hpp`).
Each test is meant to pass once the FIX core is finished.

This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/).
QuickFIX's licence is kept beside the tests as `tests/fix_quickfix_test/QUICKFIX_LICENSE`.

## Layout

| File | What it covers | Needs |
|---|---|---|
| `fix_quickfix_test.cpp` | `validate`, `checksum`, `frame`, `parse_fields` over the QuickFIX message vectors | low-level contract only |
| `qfj_qfn_vectors.inl` | 43 raw QuickFIX/J and QuickFIX/n vectors with recomputed `wire_valid` | low-level |
| `fix_quickfix_more_tests.inl` | typed QuickFIX/J and QuickFIX/n cases, more QuickFIX C++ GetString/SetString (exact writes), nested and header groups | struct mapping |
| `fix_quickfix_v2_tests.inl` | raw-data fields, `utc_timestamp`, `decimal` | fix/core v2 |
| `fix_quickfix_struct_tests.inl` | field conversion (int8/16/32/64, uint32/64, double, char, bool, string), typed admin and app messages, repeating groups, `fix_opts` switches | `glz::read/write<fix_opts{}>` |

The struct tests are on by default, because `fix/core` provides `glz::read/write<fix_opts>`. The
time-type tests are compiled only with `GLZ_FIX_TIME_TYPES`, a proposed `std::chrono` mapping. Tests the
core does not pass print `SKIPPED: <source> -- <reason>` so the gaps stay visible. Those cover date/time
types, dictionary-dependent checks and the differences from QuickFIX listed in
`docs/fix/sessions/fix-tests-quickfix.md`.

## Semantics the tests assume

These assumptions come from the contract plus QuickFIX's behaviour. `fix/core` should confirm or
change them in `docs/fix/api.md`:

* `validate` rejects: an empty message, junk, a trailing byte after the last SOH, a missing final SOH,
  a non-numeric or wrong 9, a missing, non-numeric or wrong 10, 8/9/35 not in positions 1/2/3, and a
  10 that is not last.
* A field value may hold any byte except SOH, including NUL and bytes with the high bit set. The
  checksum adds bytes as unsigned values.
* `frame` uses BodyLength, so a SOH inside a value does not end a message early. It returns 0 when
  the stream is incomplete, and returns 0 or `frame_error` when the length is malformed (`9=A`, `9=-1`,
  `9=200A`). QuickFIX throws in the malformed case.
* `parse_fields` rejects a tag that is empty, non-numeric or signed, and also rejects a missing `=`,
  a missing final SOH and empty input.
* Integer conversion rejects a leading `+`, decimals, an empty value and values out of range for the
  member type. Float conversion rejects `.` and a second decimal point. Rejecting exponent notation
  is skipped for now, because fix/core accepts it.
  Bool is `Y`/`N` only. A char field holds exactly one byte.
* QuickFIX's own `Parser` vectors carry wrong `10=` values (its Parser only frames). They are used
  only for framing tests.
