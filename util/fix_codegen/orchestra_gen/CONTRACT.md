# Codec contract for orchestra_gen output (draft, v1)

What a codec may rely on in a generated `<ns>.hpp`. Anything not listed here is not part of the contract.

## Per version (namespace scope)

| Name | Type | Meaning |
|---|---|---|
| `dictionary_version` | `std::string_view` | Orchestra repository name, e.g. `FIX.4.4` |
| `begin_string` | `std::string_view` | tag 8 on the wire: the version for FIX 4.x, `FIXT.1.1` for FIX 5.0 and later |
| `appl_ver_id` | `std::string_view` | tag 1128, only when the version has a known code (FIX 5.0, SP1, SP2) |
| `length_data_pairs` | `std::array<std::array<uint16_t, 2>, N>` | every (Length tag, data tag) pair from `lengthId`: the data field's bytes may contain SOH and are framed by the length |
| `tag::<FixName>` | `inline constexpr std::uint16_t` | every field's tag, by its Orchestra name |

## Per part (group entry, `StandardHeader<U>`, `StandardTrailer<U>`, each message `<Name><U>`)

- An aggregate. Members are in layout order (alignment 8, 4, 2, 1, then bit-fields). The codec must not
  depend on member order; it uses `fix_fields` / `fix_visit`.
- `static constexpr std::array<glz::fix3::field_info, N> fix_fields`, in **dictionary (wire) order**:

  | Field | Meaning |
  |---|---|
  | `tag` | FIX tag; for a group, its NumInGroup tag |
  | `member` | index of the member in declaration order (what reflection and `fix_visit` see) |
  | `name`, `fix_name` | C++ member name; Orchestra name (`ClOrdID`, `Parties`) |
  | `required` | `presence="required"` and every enclosing component ref required; a group entry's first field is always required (it delimits entries) |
  | `group` | the member is `std::span<const Entry>` |
  | `length_tag` | data field: the tag of its Length field, else 0 |
  | `max_entries` | group: `implMaxOccurs`, 0 = unbounded |
  | `deprecated` | the field carries `deprecated` |
  | `open_enum` | an int enum whose field allows values beyond its codes (`unionDataType` Reserved<N>Plus): accept any value in range, not only the named ones |

- `fix_visit(f)`: calls `f(const field_info&, member)` for every `fix_fields` entry, in the same order,
  on any compiler, with no reflection. A bit-field member (a required Boolean) is passed as
  `glz::fix3::bit_ref{get, set}` because it has no address. The unknown-tag member is not visited.
- Messages only: `static constexpr std::string_view fix_msg_type` (tag 35).
- `unknown` member (templated parts): `glz::fix3::unknown_t<U>` = `std::span<const field>` for
  `keep_unknown`, `std::uint16_t` for `count_unknown`. Group entries have no unknown member yet.
- `static_assert`s on `sizeof` and `alignof` for each policy are emitted after each part.

## Member types

| FIX | C++ (required) | optional (L4: "absent" is an unused value) |
|---|---|---|
| SeqNum / Length / NumInGroup, TagNum / DayOfMonth / other int | `uint64_t` / `uint32_t` / `uint16_t` / `uint8_t` / `int64_t` | `glz::fix3::opt_int<I>` (absent = `max()`) |
| float family (Price, Qty, Amt, ...) | `boost::decimal::decimal64_t` | `stdx::optional<...>` (absent = +infinity) |
| UTCTimestamp, TZTimestamp | `glz::fix3::timestamp` (ns) | absent = `timestamp::min()` |
| char codeSet | `enum class X : char` (value = wire char) | absent = `'\0'` |
| int codeSet | smallest integer enum holding every legal value; 32-bit if `open_enum` | absent = `max()` |
| Boolean | `bool : 1` (bit-field) | `glz::fix3::yes_no` (absent = `'\0'`) |
| char | `char` | absent = `'\0'` |
| everything else (String, data, dates, String codeSets, MultipleValueString, ...) | `std::string_view` | absent = empty view (FIX forbids empty values) |

## Not in the contract yet

Per-field timestamp write precision (L3); unknown tags inside group entries; enum name tables; the `#embed`
module path (its structs match the headers' layout only: no static members, no annotations on clang-p2996).
