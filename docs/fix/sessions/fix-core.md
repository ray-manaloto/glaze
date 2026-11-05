# Session notes: `fix/core`

## Status

### Push blocked
`git push -u origin fix/core` failed during this session with HTTP 403 from the session's git
proxy: *"ray-manaloto/glaze is not in this session's authorized repository set"*. The clone also
had no `origin` remote (one was added pointing at `https://github.com/ray-manaloto/glaze.git`).
All work below is committed **locally** on `fix/core`, and a patch series and a git bundle were
saved to the session scratchpad. To publish it, add the repository to the session's sources and
run `git push -u origin fix/core`, or apply the patches/bundle locally. Until that happens the
other five sessions keep their local stubs of `include/glaze/fix/fix.hpp`. The real header matches
the contract signatures, so the stubs should be drop-in replaceable.

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

### Not done / known gaps
* Clang 18 could not be checked. With libstdc++ 13, glaze's own `glaze/util/expected.hpp` fails on
  `std::expected` (this happens before any FIX code), and libc++ is not installed in this image.
* Raw-data (length-prefixed) fields, a fixed-point decimal type, chrono UTCTimestamp
  conversion, a standard header/trailer struct, and session-level semantics (sequence numbers,
  resend) are not implemented.
* Reading has no streaming or incremental mode. `parse_fields` allocates one vector per message.
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
1. Push `fix/core` once the repository is authorised for the session, so other branches can merge it.
2. Add raw-data field support (length tag declares the next field's byte count, which may hold SOH).
3. Add an optional typed UTCTimestamp (chrono) and a fixed-point decimal member type.
4. Offer a no-allocation field iterator (`for_each_field`) and use it in the reader.
5. Check with Clang + libc++ and MSVC.
