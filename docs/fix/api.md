# FIX tag=value API (contract)

Branch `fix/core` owns this file. Other FIX branches code against it. Changes to the contract are
recorded in the changelog at the bottom.

```cpp
#include "glaze/fix/fix.hpp"   // umbrella header (also "glaze/fix.hpp")
```

## Format id and options

```cpp
namespace glz {
  inline constexpr uint32_t FIX = 65536 + 9;   // custom format id (>= 65536, glaze #1619)

  struct fix_opts : opts {
    uint32_t format = FIX;
    char soh = '\x01';                  // field delimiter; tests may use '|'
    bool validate_checksum = true;      // tag 10
    bool validate_body_length = true;   // tag 9
    bool error_on_unknown_tags = false; // extension: top-level unknown tags are skipped unless true
    bool validate_msg_type = true;      // extension: on read, 35 must equal meta<T>::fix_msg_type
  };
}
```

`fix_opts` is an aggregate whose first base is `glz::opts`, so positional initialisation is
`glz::fix_opts{{}, glz::FIX, '|'}`. `glz::fix::pipe_opts` is a ready-made `fix_opts` with `soh = '|'` (GCC warns on `fix_opts{.soh = '|'}` under `-Wextra` because the base cannot be designated).

## Scanner (`glaze/fix/scan.hpp`)

```cpp
namespace glz::fix {
  struct field { uint32_t tag; std::string_view value; };       // value is a view into the input

  glz::expected<std::vector<field>, glz::error_ctx>
    parse_fields(std::string_view msg, char soh = '\x01');

  constexpr uint8_t checksum(std::string_view bytes_before_tag10);  // sum of bytes mod 256

  constexpr glz::error_ctx validate(std::string_view msg, char soh = '\x01',
                                    bool check_body_length = true,   // extension (defaulted)
                                    bool check_checksum = true);     // extension (defaulted)

  inline constexpr size_t frame_error = SIZE_MAX;                  // extension
  constexpr size_t frame(std::string_view stream, char soh = '\x01');
}
```

* `parse_fields`: every field must be `tag=value<soh>`, including the last. Tags are 1..999999999
  decimal; values must be non-empty and may contain `=`.
* **Raw-data fields** (v2): when a standard length field (95 RawDataLength, 90, 93, 212, 348, 350,
  352, 354, 356, 358, 360, 362, 364, 445, 618, 621) is directly followed by its data field (96, 91,
  89, 213, 349, ...), the data value is taken by byte count and may contain SOH, `=` or NUL. The
  byte after it must be the delimiter (else `syntax_error`), and a count past the end gives
  `unexpected_end`. A length field that is not a number is a `syntax_error`. A length field not
  followed by its data field is an ordinary field. `parse_fields`, `validate`, `field_cursor`,
  `for_each_field` and `glz::read` all follow this rule. Custom length/data pairs are not supported.
* `validate`: 8 first, 9 second, 35 third, 10 last; tag 9 equals the number of bytes from after
  the SOH ending field 9 to just before `10=`; tag 10 is exactly three digits and equals
  `checksum` of every byte before `10=`.
* `frame`: returns the length of the first complete message at the front of `stream`, `0` if more
  bytes are needed, or `frame_error` if the front cannot start a FIX message (so a reader never
  waits forever on garbage). Framing trusts tag 9 only; run `validate` on the framed bytes.

### Raw-data tag table and zero-allocation scanning (v2, additions)

```cpp
namespace glz::fix {
  constexpr uint32_t raw_data_tag_for(uint32_t length_tag);   // 95 -> 96, else 0
  constexpr uint32_t raw_length_tag_for(uint32_t data_tag);   // 96 -> 95, else 0

  class field_cursor {                       // no allocation; usable in constant expressions
   public:
    constexpr explicit field_cursor(std::string_view msg, char soh = '\x01');
    constexpr bool next(field& f);           // false at end or on a malformed field
    constexpr glz::error_ctx error() const;  // none, or the error; count = offset of the bad field
    constexpr size_t position() const;       // offset of the next field
    constexpr bool done() const;
  };
  // fn(const field&) -> void, or bool where false stops early. Returns the scanner's error.
  template <class Fn> constexpr glz::error_ctx for_each_field(std::string_view msg, char soh, Fn&& fn);
}
```

`glz::read<fix_opts>` now walks the message with `field_cursor` (one-field lookahead), and
allocates only for members that themselves allocate. A repeating group count larger than the
remaining bytes / 4 is rejected before the vector is sized.

## Typed values (v2, additions; `glaze/fix/types.hpp`)

```cpp
namespace glz::fix {
  struct utc_timestamp {                 // "YYYYMMDD-HH:MM:SS[.f{1,9}]"
    std::chrono::sys_time<std::chrono::nanoseconds> time{};
    uint8_t precision = 3;               // fractional digits written; a read sets it to the digits seen
  };
  struct decimal {                       // value = mantissa * 10^exponent, scale kept as written
    int64_t mantissa{}; int32_t exponent{};
    constexpr double to_double() const;
  };                                     // operator== compares representation: 1.5 != 1.50
  bool parse_utc_timestamp(std::string_view, utc_timestamp&);
  void append_utc_timestamp(std::string&, const utc_timestamp&);   // truncates to precision
  bool parse_decimal(std::string_view, decimal&);   // [-]digits[.digits], at most 18 digits, no '+', no exponent
  void append_decimal(std::string&, const decimal&);
}
```

Both work as struct members, including inside `std::optional`. A bad timestamp gives
`syntax_error` ("fix: invalid UTCTimestamp"). A bad decimal gives `parse_number_failure`
("fix: invalid decimal"). Timestamps check calendar validity (leap years), hours 0..23, minutes and
seconds 0..59. A leap second (60) is rejected.

## Struct mapping (`glaze/fix/codec.hpp`)

```cpp
struct NewOrderSingle { std::string cl_ord_id; std::string symbol; char side; double qty;
                        std::optional<double> price; std::vector<Party> parties; };
template <> struct glz::meta<NewOrderSingle> {
  using T = NewOrderSingle;
  static constexpr auto fix_msg_type = "D";                 // required for write, checked on read
  static constexpr auto fix_begin_string = "FIX.4.4";       // optional, default "FIX.4.4"
  static constexpr auto value = glz::object("11", &T::cl_ord_id, "55", &T::symbol, "54", &T::side,
                                            "38", &T::qty, "44", &T::price, "453", &T::parties);
};
glz::error_ctx ec = glz::read<glz::fix_opts{}>(obj, msg);
glz::error_ctx ec = glz::write<glz::fix_opts{}>(obj, buffer);   // buffer: std::string etc.
```

Only types mapped with `glz::meta` + `glz::object` whose keys are decimal tag numbers are
supported (pure reflection would give member names, not tags). Member types:

| C++ type | FIX type | write | read |
|---|---|---|---|
| signed/unsigned integers | int, SeqNum, Length, NumInGroup | decimal | `std::from_chars`, whole value; `-` rejected for unsigned |
| `float`, `double` | Qty, Price, Amt (decimal) | shortest round-trip `std::to_chars` | `std::from_chars`; `+` rejected |
| `char` | char | 1 byte | exactly 1 byte |
| `bool` | Boolean | `Y` / `N` | `Y` / `N` only |
| `std::string` | String, UTCTimestamp, etc. as text | verbatim, empty = not written | copied |
| `std::string_view` | as above | verbatim | **view into the input buffer** |
| enums | per underlying type (`char` enum = 1-char code, integer enum = number) | underlying value | underlying value |
| `std::optional<X>` | optional field | absent if `nullopt` | emplaced when present |
| `std::vector<G>` with `G` FIX-mapped | repeating group | key = NoXXX count; entries follow | see below |
| `glz::fix::utc_timestamp` | UTCTimestamp | `YYYYMMDD-HH:MM:SS.sss` (per precision) | parsed, precision recorded |
| `glz::fix::decimal` | Price, Qty, Amt (exact) | as written (scale kept) | exact |
| `std::string` mapped to a raw-data tag (96, 213, ...) | data | length field written first, automatically; may hold SOH | length field consumed |

Timestamps can be text (`std::string`) or typed (`glz::fix::utc_timestamp`).

For raw data, map only the data tag (e.g. `"96", &T::raw`). The writer emits the length field from
`raw.size()` in front of it, and skips any member mapped to that length tag. The reader consumes
the length field, even with `error_on_unknown_tags` and inside groups.

**Write** emits `8=<begin>`, `9=<len>`, `35=<fix_msg_type>`, then members in declaration order,
then `10=<ddd>`. A group with no entries is omitted entirely.

**Read** of a message whose first field is 8 runs `validate` (with the opts) and checks 35
against `fix_msg_type`. Input whose first field is not 8 is read as a body fragment without
envelope checks. Tags 8, 9, 35 and 10 are never mapped to members. Fields can appear in any order
at the top level; a repeated tag overwrites.

**Repeating groups**: the count tag (key of the vector member) is followed by exactly `count`
entries. Each entry must begin with the group's first member tag (the delimiter). An entry ends
at the next delimiter or at the first tag not in the group's mapping, which returns control to
the enclosing struct, so groups nest to any depth and fields after a group go to the parent.

## Error codes

FIX reuses `glz::error_code`; `custom_error_message` (string literal, starts with `fix:`) names
the exact problem.

| Condition | `error_code` | message |
|---|---|---|
| malformed field (no `=`, bad tag, empty value) | `syntax_error` | `fix: malformed field` |
| value to write contains the delimiter | `syntax_error` | `fix: value contains the field delimiter` |
| last field has no delimiter | `unexpected_end` (scanner) / `syntax_error` (validate) | `fix: malformed field` |
| empty input | `no_read_input` | `fix: empty message` |
| 8/9/35 not first/second/third, 9 not a number | `invalid_header` | names the tag |
| 35 differs from `fix_msg_type` | `invalid_header` | `fix: MsgType (35) does not match the target type` |
| 10 missing, not last, not 3 digits | `invalid_body` | names the problem |
| body length wrong | `invalid_body` | `fix: BodyLength (9) mismatch` |
| checksum wrong | `invalid_body` | `fix: CheckSum (10) mismatch` |
| unknown tag with `error_on_unknown_tags` | `unknown_key` | `fix: unknown tag` |
| bad number | `parse_number_failure` | `fix: invalid number` |
| bad Boolean | `expected_true_or_false` | `fix: Boolean must be Y or N` |
| char not 1 byte | `syntax_error` | |
| group count / delimiter mismatch | `syntax_error` | `fix: repeating group count ...` |
| raw-data length disagrees with data | `syntax_error` (`unexpected_end` if past the end) | `fix: malformed field` |
| bad UTCTimestamp | `syntax_error` | `fix: invalid UTCTimestamp` |
| bad decimal | `parse_number_failure` | `fix: invalid decimal` |

## Changelog

* v2 (additions only, no existing signature changed): raw-data fields in every scanner path and
  the codec, `raw_data_tag_for`, `raw_length_tag_for`, `field_cursor`, `for_each_field`,
  `utc_timestamp`, `decimal` and their parse/append functions. Behaviour change: a standard length
  field followed by its data field now reads the data by byte count, where before it would have
  split at an embedded SOH.

* v1 (initial): contract as given, plus the extensions marked above: `glz::fix::pipe_opts`, `error_on_unknown_tags`,
  `validate_msg_type`, `frame_error`, the two defaulted flags on `validate`, `meta<T>::fix_begin_string`.
