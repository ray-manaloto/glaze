# Session notes: `fix/core`

## Status

### Push history
The first pushes failed with HTTP 403 because `ray-manaloto/glaze` was not attached to the
session. The clone also had no `origin` remote, so one was added. After the repository was
attached (07:11 UTC), `fix/core` was pushed with all commits.

### Done
* `include/glaze/fix/opts.hpp`: `glz::FIX`, `glz::fix_opts` (contract members plus
  `error_on_unknown_tags`, `validate_msg_type`), `glz::fix::pipe_opts`.
* `include/glaze/fix/scan.hpp`: `field`, `parse_fields`, `checksum` (constexpr), `validate`
  (constexpr, optional switches for 9/10 value checks), `frame` (+ `frame_error`).
* `include/glaze/fix/codec.hpp`: `parse<FIX>`/`serialize<FIX>` dispatch and
  `from<FIX,T>`/`to<FIX,T>` for `glz::meta`/`glz::object` structs with tag-number keys. Covers
  integers, floating point as decimal text, char, bool Y/N, std::string, std::string_view
  (zero-copy), enums, std::optional, timestamps as text, unknown tags (skip, or error with
  `error_on_unknown_tags`), repeating groups as `std::vector<Group>`, nested to any depth.
  Write fills 8 (from `meta<T>::fix_begin_string`, default FIX.4.4), 9, 35 and 10, and rejects
  values that contain the delimiter.
* `include/glaze/fix/fix.hpp` umbrella and `include/glaze/fix.hpp`.
* `tests/fix_test/` (registered in `tests/CMakeLists.txt`): 23 ut tests, 432 asserts. They pass with
  GCC 13.3 Debug (`-fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror`) through CMake, and
  also under `-fsanitize=address,undefined`.
* `docs/fix/api.md` (the contract, error-code table, changelog) and `docs/fix/design.md`
  (FIX vs BEVE, what glaze gives FIX, SBE).

### Done in the second pass (07:30 to 07:57 UTC, additions only)
* **Raw-data fields** (`scan.hpp`, `codec.hpp`): a standard length field (95, 90, 93, 212, 348..364,
  445, 618, 621) directly followed by its data field is read by byte count, so the data may hold SOH.
  This applies in `parse_fields`, `validate`, the new cursor and `glz::read`. Writing a
  `std::string` mapped to a data tag emits its length field automatically, and reading consumes it
  (also in strict mode and inside groups). New: `raw_data_tag_for`, `raw_length_tag_for`.
* **Typed values** (`types.hpp`, new): `glz::fix::utc_timestamp` (sys_time in nanoseconds plus
  precision 0..9) and `glz::fix::decimal` (exact int64 mantissa and base-10 exponent, scale kept as
  written), with `parse_*` / `append_*` functions. Both work as members and inside `std::optional`.
* **No-allocation iterator** (`scan.hpp`): `glz::fix::field_cursor` (constexpr, tested in a
  `static_assert`) and `glz::fix::for_each_field`. The `glz::read` path now uses the cursor
  through a one-field lookahead (`detail::field_stream`) instead of `parse_fields`, so
  reading allocates nothing beyond the members' own storage. A group count above remaining bytes / 4
  is rejected before the vector is sized.
* Tests: 32 tests and 515 asserts, passing under GCC 13 Debug `-Werror` and ASan/UBSan. New ones are
  `raw_data_scanner`, `raw_data_validate_and_frame`, `raw_data_roundtrip`, `utc_timestamp`,
  `decimal`, `typed_values_roundtrip`, `field_cursor`, `for_each_field` and
  `huge_group_count_rejected`.
* No existing public signature was changed or removed. The one behaviour change is the raw-data
  rule above; it is recorded in the `docs/fix/api.md` changelog as v2.

### Not done / known gaps
* Clang 18 could not be checked (now owned by `fix/integration`). With libstdc++ 13, glaze's own `glaze/util/expected.hpp` fails on
  `std::expected` (this happens before any FIX code), and libc++ is not installed in this image.
* Custom (non-standard) raw-data length/data pairs, UTCDateOnly/UTCTimeOnly/LocalMktDate types,
  a standard header/trailer struct, and session-level semantics (sequence numbers, resend) are not
  implemented.
* Reading has no streaming or incremental mode. `validate` and the decode each scan the message
  once, so a full message is scanned twice.
* `decimal` arithmetic is not provided (only parse, format, `to_double` and representation equality).
* `validate` is not exposed as `glz::read` option beyond the two existing flags. The
  `validate_msg_type` read check only applies when the input starts with tag 8.
* No performance work was done.

## Provenance of tests
No tests were ported. Every test in `tests/fix_test/fix_test.cpp` was written in this session
from the FIX tag=value rules (field syntax, BodyLength, CheckSum = byte sum mod 256, repeating
group delimiter rules). The fixed checksum vectors (`8=FIX.4.2|9=5|35=0|` → 018, and the SOH
variant → 161) were computed independently with Python and are explained in the test comments.
No reference repositories were fetched.

## Build
```
pip install cmake            # the image's cmake 3.28 is older than glaze's required 3.31
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++
cmake --build build --target fix_test && ./build/tests/fix_test/fix_test
```

## Next steps
1. Fold envelope validation into the decode pass, so a message is scanned once.
2. Let users register custom raw-data length/data pairs (for example through `glz::meta`).
3. Add UTCDateOnly / UTCTimeOnly / LocalMktDate types and decimal comparison by value.
4. Clang + libc++ and MSVC checks are owned by the `fix/integration` session.
