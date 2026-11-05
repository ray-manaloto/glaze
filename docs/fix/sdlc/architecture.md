# glaze-fix: target architecture

This document describes where the FIX tag=value codec in `include/glaze/fix/` is going. It is
grounded in the code as it stands today; each section names the functions that exist now and the
shape they take in the target design. Nothing here changes the public contract: `glz::read<fix_opts>`
and `glz::write<fix_opts>` over structs mapped with `glz::meta`/`glz::object`, errors returned as
`glz::error_ctx`, no exceptions, no RTTI.

## 1. Where the code is now

| Layer | File | Entry points today |
|---|---|---|
| scanning | `scan.hpp` | `detail::next_field`, `field_cursor`, `for_each_field`, `parse_fields`, `checksum`, `validate`, `frame` |
| typed values | `types.hpp` | `utc_timestamp`, `decimal`, `parse_utc_timestamp`, `append_utc_timestamp`, `parse_decimal`, `append_decimal` |
| options | `opts.hpp` | `glz::FIX`, `fix_opts : opts`, `fix::pipe_opts` |
| codec | `codec.hpp` | `detail::tags<T>`, `detail::member_index<T>`, `detail::decode_scalar`, `detail::field_stream`, `detail::decode_struct`, `detail::decode_group`, `detail::put_tag`, `detail::encode_scalar`, `detail::encode_checked`, `detail::encode_field`, `detail::encode_struct`, `from<FIX, T>`, `to<FIX, T>`, `parse<FIX>`, `serialize<FIX>` |

Observations that drive the target design:

* `from<FIX, T>::op` walks the input twice when tag 8 is first: once in `fix::validate` (which
  itself calls `next_field` over every field and then `checksum` over the body), and once more in
  `decode_struct` through `field_stream`. A third short walk (`field_cursor hc`) re-reads 8/9/35 to
  compare MsgType.
* `detail::next_field` uses `std::string_view::find` twice per field ('=' then SOH) and parses the
  tag with `parse_uint` on a sub-view. Each field costs several branches that depend on data.
* `detail::member_index<T>` is a linear scan over `tags<T>`, evaluated at run time per field, and
  the member dispatch in `decode_struct` is a `for_each<reflect<T>::size>` that visits every member
  until `I == m`.
* `to<FIX, T>::op` builds `body` into a temporary `std::string`, then a second `std::string msg`,
  then copies into the caller's buffer. `put_tag` runs `std::to_chars` on the tag for every field of
  every message, although the tag is a compile-time constant (`tags<T>[I]`).
* `encode_checked` scans the just-written value for the delimiter with `find`. `fix::checksum`
  runs a second time over the whole message after it is assembled.

## 2. Target design overview

```
bytes ──► framer (frame) ──► scanner (next_field / field_cursor)
                                 │  (tag, value view, running checksum, body offset)
                                 ▼
                          envelope check (fold of validate into the scanner pass)
                                 │
                                 ▼
                 tag table lookup (compile-time sorted array / perfect hash from glz::meta)
                                 │
                                 ▼
                    member decode (decode_scalar / decode_group) into T

T ──► encode_struct (precomputed "tag=" prefixes, direct writes into caller buffer)
      └─► BodyLength and CheckSum back-patched after the body is written
```

The constraints are the usual glaze ones: options come from `fix_opts`, behaviour is chosen with
`if constexpr` on `Opts`, the per-type work is driven by `glz::reflect<T>`, every failure sets
`ctx.error` / `ctx.custom_error_message` and returns, and the public surface stays
`from<FIX, T>` / `to<FIX, T>`.

## 3. Reading

### 3.1 Zero-copy fields

`field` already holds `std::string_view value`, and `decode_scalar` assigns it straight into
`std::string_view` members. This stays the default: a struct of `string_view` members decodes
with no allocation. `std::string` members copy on assignment, `std::optional<...>` members use
`emplace`, and `std::vector<Group>` is the only container the reader sizes (`vec.resize(count)` in
`decode_group`). The target keeps those semantics and adds one rule for the reader: no code path
may create a `std::string` from the input. Error messages stay `string_view` literals, as they are
now in `ctx.custom_error_message`.

### 3.2 Compile-time tag tables

`detail::tags<T>` is already a `constexpr std::array<uint32_t, N>` derived from
`reflect<T>::keys` via `tag_at<T>`. `member_index<T>(tag)` scans it linearly at run time. Target:

* `detail::sorted_tags<T>`: a `constexpr` array of `(tag, member index)` pairs sorted by tag,
  built once from `tags<T>`. Lookup is a branchless lower-bound (or an unrolled compare chain for
  small `N`, which is the common case for a FIX struct).
* `detail::tag_hash<T>`: for structs above a size threshold, a minimal perfect hash chosen at
  compile time over `tags<T>` (the same search-for-a-seed approach glaze uses for string keys in
  `glz::hash` helpers), giving a single multiply-shift-index and one compare. Which of the two is
  instantiated is a compile-time choice on `N`; both expose the same `member_index<T>(tag)` signature,
  so `decode_struct` is unchanged by the choice.
* Both tables also carry the member kind (scalar / optional / group / raw-data) as a small enum,
  so `decode_struct` can `switch` on the kind before entering the `for_each` member visit rather
  than discovering it inside the visit.

`is_raw_length_of_mapped<T>` and `is_session_envelope_tag` become lookups in the same table
(a bit in the entry) instead of a nested `raw_data_tag_for` switch plus a second `member_index`.

### 3.3 Member dispatch

`decode_struct` finds the member with `for_each<reflect<T>::size>` and an `if (int(I) != m) return;`
guard. The target replaces this with a jump table: a `constexpr std::array<void(*)(T&, field_stream&, context&), N>`
built from `reflect<T>::values`, indexed by the member index the tag table returns. That keeps
one indirect call per field and no per-member test. `decode_group` is one such entry; it continues
to require `in.cur.tag == tags<G>[0]` (the delimiter tag) for each entry.

### 3.4 Branch-light scanning

`detail::next_field` is the inner loop and remains the single place that knows the wire syntax.
Target shape:

* Tag parsing reads digits directly from `msg[pos]` while accumulating, stopping at `'='`,
  instead of `find('=')` followed by `parse_uint` on a sub-view. Tags are at most 9 digits, so the
  loop bound is small and fixed.
* Delimiter search uses an 8-byte SWAR step: load eight bytes, compute the has-zero-byte mask for
  `x ^ broadcast(soh)`, and advance by whole words until a match. The tail (fewer than eight bytes
  left) falls back to byte compares. The SOH byte comes from `Opts.soh`, so the broadcast constant is
  a compile-time value when the scanner is instantiated through `from<FIX, T>`; the `field_cursor`
  constructor that takes `soh` at run time keeps working and simply broadcasts at run time.
* An optional SIMD path (SSE2 / NEON, selected the same way other glaze hot loops do it) does the
  same compare on 16 bytes. It is an implementation detail behind the same `next_field` signature
  and is off when the target does not provide the intrinsics.
* Raw-data handling (`scan_state`, `raw_data_tag_for`) is unchanged in behaviour: when the previous
  field was a standard length tag, the next field is read by byte count, not by delimiter.

`field_cursor::next`, `for_each_field`, `parse_fields`, `validate` and `frame` all sit on top of
`next_field`, so they inherit the faster scan without API changes.

### 3.5 Single-pass checksum and body length

Today `from<FIX, T>::op` calls `fix::validate` (a full walk plus a `checksum` pass) and then
decodes in a second walk. Target: `field_cursor` carries two accumulators, `sum_` (bytes consumed
so far, mod 256) and the byte offset where the body started (after 9's SOH). `next_field` adds the
bytes of each field to `sum_` as it passes them, so by the time the cursor reaches tag 10 the
checksum of everything before `"10="` is already known. `BodyLength` is then
`position_of_tag10 - body_start`, which the cursor also knows. The envelope rules that `validate`
enforces today (8 first, 9 second, 35 third, 10 last and final, three-digit checksum) move into a
small state machine inside `from<FIX, T>::op` that runs as the cursor advances, with the same
`error_code` and `custom_error_message` values. `validate` remains as a public function for callers
who only want to check a message, implemented over the same accumulating cursor.

The MsgType compare (`Opts.validate_msg_type` against `meta<T>::fix_msg_type`) happens when the
third field is seen, removing the separate `field_cursor hc` walk.

Positions reported in `error_ctx::count` keep their meaning: the byte offset of the offending field.

### 3.6 Options

`fix_opts` keeps `soh`, `validate_checksum`, `validate_body_length`, `error_on_unknown_tags` and
`validate_msg_type`. Turning a validation off removes the final compare, not the accumulation, so the
scanner has one shape regardless of options. A future `fix_opts` field may select the SIMD path
explicitly for testing; it is not part of the public contract.

## 4. Writing

### 4.1 Precomputed "tag=" prefixes

`encode_field<Opts, Tag, V>` already has the tag as a template parameter but still calls `put_tag`,
which runs `std::to_chars` at run time. Target: `detail::tag_prefix<Tag>` is a `constexpr`
`std::array<char, K>` holding `"Tag="` (and, for raw-data fields, the matching length-tag prefix as
well), built once per tag at compile time. `encode_field` copies the prefix with a fixed-size
`memcpy`. The count tag of a group and the `"35="` prefix in `to<FIX, T>::op` use the same helper.

### 4.2 Direct writes and back-patching

`to<FIX, T>::op` currently assembles `body` and `msg` as `std::string`s and then `memcpy`s into
`b`. Target: write directly into the caller's buffer `b` at `ix`, using `ensure_space` before each
field as other glaze writers do (`glz::write` for JSON reserves and then dumps). The order of work:

1. Write `"8=" + begin_string_of<T>() + soh`.
2. Write `"9="`, then reserve a fixed number of digit slots for BodyLength (the maximum FIX
   BodyLength the writer supports, e.g. seven digits), then the SOH. Remember the slot offset.
3. Write `"35=" + fix_msg_type + soh` and the body through `encode_struct`, accumulating the
   checksum as bytes are emitted (see 4.3).
4. Compute BodyLength from the current `ix` and the body start, format it into the reserved slot.
   If leading slots are unused, the writer either left-pads with zeros (FIX permits leading zeros
   in BodyLength in practice but not all counterparties accept them) or, by default, shifts the
   body left over the unused slots with a single `memmove` so the output is canonical.
5. Finish the checksum over the bytes actually present (including any shifted prefix), write
   `"10=" ddd soh`.

The default is the canonical form with no leading zeros; a `fix_opts` flag can select the
zero-padded form, which avoids the `memmove`.

### 4.3 Single-pass checksum on write

`fix::checksum(msg)` currently runs over the completed message. Target: `encode_scalar` and
`encode_field` write through a small `sink` object that wraps `b`/`ix` and adds each emitted byte to a
running sum. `tag_prefix<Tag>` also carries its own precomputed byte sum, so prefix bytes cost one
addition rather than one per byte. After BodyLength is patched, only its digits (and any shifted
region, when shifting is used) need to be added to the sum.

### 4.4 Delimiter check

`encode_checked` scans the written value with `find(Opts.soh)`. The target keeps the check (a value
containing the delimiter would corrupt the message) but performs it inside the same byte loop that
accumulates the checksum for string values; for numeric, bool, char, `utc_timestamp` and `decimal`
values the check is unnecessary by construction and is skipped at compile time by type. Raw-data
fields (`raw_length_tag_for(Tag) != 0`) are exempt as they are today.

## 5. Typed values

`types.hpp` stays as the home of `utc_timestamp` and `decimal`. `append_decimal` currently builds a
temporary `std::string digits`; the target formats into a fixed `char[32]` and emits once.
`parse_decimal` and `parse_utc_timestamp` already operate on views with no allocation.
Additional typed values (UTCDateOnly, UTCTimeOnly, LocalMktDate, MonthYear) follow the same
pair-of-functions pattern and plug into `decode_scalar` / `encode_scalar` with one `if constexpr`
branch each.

## 6. Error handling

All failures continue to flow through `ctx.error` and `ctx.custom_error_message` and surface as
`glz::error_ctx` from `glz::read` / `glz::write`. The reader reports `count` as the byte offset of
the field at fault (`field_cursor::position()` semantics are preserved by the accumulating cursor).
The writer reports `dump_int_error` for a `to_chars` failure and `syntax_error` for a delimiter in a
value, as now. No new error codes are introduced; new messages use the existing `"fix: ..."` prefix.

## 7. Compatibility and layering

* Public: `glz::FIX`, `glz::fix_opts`, `glz::fix::pipe_opts`, `glz::fix::field`,
  `glz::fix::field_cursor`, `glz::fix::for_each_field`, `glz::fix::parse_fields`,
  `glz::fix::checksum`, `glz::fix::validate`, `glz::fix::frame`, `glz::fix::utc_timestamp`,
  `glz::fix::decimal`, and the `from`/`to` specialisations. These keep their signatures.
* Internal: everything under `glz::fix::detail` may change. The tag tables, jump tables, SWAR
  scanner, write sink and prefix tables all live there.
* Dependencies stay within what `codec.hpp` includes today: `glaze/core/{common,opts,read,write,reflect,buffer_traits}.hpp`
  and `glaze/util/for_each.hpp`. Nothing in `include/glaze/fix/` pulls in the JSON headers.
