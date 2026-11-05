# QuickFIX-derived tests for the FIX format

`tests/fix_quickfix_test/` holds unit tests ported from QuickFIX's C++ test suite
(<https://github.com/quickfix/quickfix>, `src/C++/test/`). QuickFIX/J and QuickFIX/n vectors may be
added to the same directory later. These are tests of the glaze FIX API contract (`glaze/fix/fix.hpp`).
Each test is meant to pass once the FIX core is finished.

This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/).
QuickFIX's licence is kept beside the tests as `tests/fix_quickfix_test/QUICKFIX_LICENSE`.

## Layout

| File | What it covers | Needs |
|---|---|---|
| `fix_quickfix_test.cpp` | `validate`, `checksum`, `frame`, `parse_fields` over the QuickFIX message vectors | low-level contract only |
| `fix_quickfix_struct_tests.inl` | field conversion (int8/16/32/64, uint32/64, double, char, bool, string), typed admin and app messages, repeating groups, `fix_opts` switches | `glz::read/write<fix_opts{}>` |

The struct tests are compiled only when the core defines `GLZ_FIX_STRUCT_MAPPING`. This
macro is **proposed** for the contract; `fix/core` has not adopted it yet. Without the macro they
print `SKIPPED: <source> -- <reason>` and do not fail. Tests outside the contract are also
printed as `SKIPPED` with a reason: date/time types, and checks that need a data dictionary.
That way the gaps stay visible.

## Semantics the tests assume

These assumptions come from the contract plus QuickFIX's behaviour. `fix/core` should confirm or
change them in `docs/fix/api.md`:

* `validate` rejects: an empty message, junk, a trailing byte after the last SOH, a missing final SOH,
  a non-numeric or wrong 9, a missing, non-numeric or wrong 10, 8/9/35 not in positions 1/2/3, and a
  10 that is not last.
* A field value may hold any byte except SOH, including NUL and bytes with the high bit set. The
  checksum adds bytes as unsigned values.
* `frame` uses BodyLength, so a SOH inside a value does not end a message early. It returns 0 when
  the stream is incomplete *or* the length is malformed (`9=A`, `9=-1`, `9=200A`). QuickFIX throws in
  the malformed case; here the caller is expected to `validate`.
* `parse_fields` rejects a tag that is empty, non-numeric, signed or has a leading zero, and also
  rejects a missing `=` or a missing final SOH.
* Integer conversion rejects a leading `+`, decimals, an empty value and values out of range for the
  member type. Float conversion rejects exponent notation, `.` and a second decimal point.
  Bool is `Y`/`N` only. A char field holds exactly one byte.
* QuickFIX's own `Parser` vectors carry wrong `10=` values (its Parser only frames). They are used
  only for framing tests.
