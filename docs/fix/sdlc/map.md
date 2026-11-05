# Architecture map: glaze and the FIX tag=value codec

This document is an orientation map for anyone working on the FIX format in this
fork. It describes how glaze is put together, where the FIX code plugs in, and how
the design compares with a few other FIX and parsing libraries. File paths are
relative to the repository root.

## 1. Glaze in one paragraph

Glaze is a header-only C++ library that serializes and deserializes C++ objects to
and from several text and binary formats. Every format shares the same front door
(`glz::read<Opts>(value, buffer)` / `glz::write<Opts>(value, buffer)`), the same
options object (`glz::opts`), the same reflection layer (`glz::meta<T>` or pure
compile-time reflection of aggregates), and the same error/context types. A format
is just an integer id plus a family of template specializations. FIX is one more
such format.

## 2. Core: options and format ids

- `include/glaze/forward.hpp` declares the format ids (`BEVE = 1`, `JSON = 10`,
  `NDJSON = 100`, `TOML = 400`, `CSV = 10000`, ...) and forward-declares the
  dispatch templates: `to<Format, T>`, `from<Format, T>`, `to_partial`,
  `skip_value<Format>`, and the per-format entry points `parse<Format>` /
  `serialize<Format>`.
- `include/glaze/core/opts.hpp` defines `struct opts` (line 74), the compile-time
  option bundle passed as a non-type template parameter. Its `format` member is
  what selects a codec. Options are read with `check_*` helpers so a derived
  options struct may add members that the base does not know about. This is the
  mechanism that lets a format bring its own knobs without touching core.
- `include/glaze/core/context.hpp` holds `glz::context` (the per-call error
  state), and `include/glaze/core/error_category.hpp` the `error_code` enum used by
  every format.

## 3. Core: the read/write pipeline

The pipeline is deliberately thin:

1. `glz::read<Opts>(value, buffer)` in `include/glaze/core/read.hpp` normalises
   the buffer into an iterator pair, sets up a `context`, and calls
   `parse<Opts.format>::template op<Opts>(value, ctx, it, end)` (around line 200;
   a streaming variant appears near line 314).
2. `parse<Format>` is specialised per format (`include/glaze/json/read.hpp:45`
   is `parse<JSON>`, `include/glaze/beve/read.hpp:32` is `parse<BEVE>`). Its job
   is to forward to `from<Format, std::remove_cvref_t<T>>::op<Opts>(...)`, which is
   where the type-specific logic lives.
3. `glz::write<Opts>` in `include/glaze/core/write.hpp` is the mirror image: it
   calls `to<Opts.format, T>::template op<Opts>(value, ctx, buffer, ix)` (lines 29
   and 135) where `ix` is a write index into a growable buffer.
4. `include/glaze/core/to.hpp` holds the format-agnostic `to` specialisations
   (`hidden`, `skip`, filesystem paths). `include/glaze/core/custom.hpp` provides
   the generic `from<Format, T>` / `to<Format, T>` for `glz::custom` wrappers, so a
   user-supplied read/write lambda works in any format.
5. `include/glaze/core/wrappers.hpp`, `write_wrappers.hpp` and `wrapper_traits.hpp`
   implement option-carrying wrappers (quoted numbers, raw strings, etc.), again
   format-agnostic where possible.

The consequence for a new format: you write `from<MYFMT, T>` and `to<MYFMT, T>`
partial specialisations constrained by concepts (`glaze_object_t`, `num_t`,
`str_t`, and so on from `include/glaze/core/common.hpp`), plus a `parse<MYFMT>` /
`serialize<MYFMT>` pair if you want the generic entry points to dispatch to you.
Nothing in `core/` needs to change.

## 4. Core: reflection and metadata

- `include/glaze/core/meta.hpp` defines `glz::meta<T>` and the `glz::object(...)`
  builder that pairs key strings with member pointers.
- `include/glaze/core/reflect.hpp` builds `reflect<T>` from either a `meta`
  specialisation or from pure reflection. It exposes `reflect<T>::size`,
  `reflect<T>::keys` and member accessors that formats iterate with
  `for_each<N>` from `include/glaze/util/for_each.hpp`.
- `include/glaze/reflection/to_tuple.hpp` converts an aggregate to a tuple of
  references by counting constructible members. `include/glaze/reflection/get_name.hpp`
  derives member names from mangled function names (with a P2996 path for compilers
  that have it). `include/glaze/reflection/requires_key.hpp` handles the
  "required key" option.
- Key lookup for JSON-style objects is built from these names at compile time
  (hash maps in `include/glaze/core/common.hpp` and `include/glaze/util/murmur.hpp`).

Because keys are compile-time strings, a format is free to interpret them however
it likes. FIX uses this freedom: the "key" of each member is a tag number spelled
as a string.

## 5. Core: utility layer

- `include/glaze/util/parse.hpp` contains the byte-level scanning helpers used by
  the JSON reader. The important idea is SWAR (SIMD within a register): a 64-bit
  word is loaded, a constant such as `repeat_byte8(c)` broadcasts a byte, and
  `has_zero` / `has_char` style bit tricks detect whether any lane matched, with
  `countr_zero(test) >> 3` locating the first match (see around lines 597-635 and
  920-930). The same approach is used for ASCII fast paths and whitespace skipping.
- `include/glaze/util/atoi.hpp`, `itoa.hpp`, `glaze_fast_float.hpp`, `zmij.hpp`
  and `write_chars.hpp` are the number conversions shared by all formats.
- `include/glaze/util/expected.hpp` provides `glz::expected`, used for
  error-returning APIs; `include/glaze/util/string_literal.hpp` and
  `type_traits.hpp` support the compile-time machinery.

## 6. FIX in this fork

The format lives under `include/glaze/fix/` and is documented in
`docs/fix/design.md` and `docs/fix/api.md`.

### 6.1 `include/glaze/fix/opts.hpp`

Declares `glz::FIX = 65536 + 9` (custom ids are `>= 65536`) and
`struct fix_opts : opts` with `format = FIX`. Extra members are the delimiter
(`soh`, defaulting to `'\x01'`), `validate_checksum`, `validate_body_length`,
`error_on_unknown_tags` and `validate_msg_type`. `glz::fix::pipe_opts` is a
ready-made option set that uses `'|'` for readable tests. This is the derived-opts
pattern from section 2 in action.

### 6.2 `include/glaze/fix/scan.hpp`

The allocation-free scanning layer. It knows nothing about user types:

- `field { uint32_t tag; std::string_view value; }` is a zero-copy view of one
  tag=value pair.
- `detail::next_field` advances through the buffer one field at a time. It
  carries a small `scan_state` so that a length field (tag 95 `RawDataLength`,
  tag 354 `EncodedTextLen`, ...) makes the following data field be read by byte
  count, because data fields may legitimately contain the delimiter. The pairing
  table is `raw_data_tag_for` / `raw_length_tag_for`.
- `parse_fields` returns a `glz::expected<std::vector<field>, error_ctx>`; it is
  the only function here that allocates.
- `checksum` computes the mod-256 byte sum used by tag 10, and `validate` checks
  the structural envelope (BeginString first, BodyLength, trailing CheckSum).
- `frame` finds the end of the first complete message in a stream using
  BodyLength only, returning `frame_error` when the prefix cannot be a message.
  This is the hook for a session layer that accumulates bytes from a socket.

### 6.3 `include/glaze/fix/types.hpp`

Two value types that FIX needs and C++ lacks: `utc_timestamp`, a
`sys_time<nanoseconds>` plus the fractional precision that was read, so a
round-trip preserves the original digit count; and `decimal`, an exact
`mantissa * 10^exponent` for Price/Qty/Amt fields. Both come with parse/append
functions and keep representation equality (`1.5 != 1.50`), which matches how FIX
counterparties compare text.

### 6.4 `include/glaze/fix/codec.hpp`

The glue to glaze's pipeline. `from<FIX, T>` (line 446) and `to<FIX, T>` (line
499) are specialised for `glaze_object_t` types. At compile time
`detail::tags<T>` converts each reflected key string into a `uint32_t` tag
(`tag_at` aborts in a constant expression on a non-numeric key, turning a bad
mapping into a compile error), and `member_index` maps a tag back to a member
position. Reading runs `fix::validate` when the options ask for it, then walks
fields with `next_field` and dispatches on `member_index`. Repeating groups are
`std::vector<Group>` members keyed by the `NoXXX` count tag; the group's first
member is treated as its delimiter, and groups nest. `std::optional` means
"absent is fine", `std::string_view` members alias the input buffer, and
session-envelope tags (8, 9, 35, 10) are handled by the codec rather than by the
user struct. Writing emits the envelope, the body, then computes the checksum
with `fix::checksum`.

`include/glaze/fix/fix.hpp` is the umbrella include.

### 6.5 Layering summary

```
glz::read<fix_opts{}> / glz::write<fix_opts{}>      core/read.hpp, core/write.hpp
        |
from<FIX,T> / to<FIX,T>                             fix/codec.hpp
        |                 \
fix::next_field, validate, frame                     fix/scan.hpp
fix::decimal, fix::utc_timestamp                     fix/types.hpp
        |
reflect<T>, for_each, context, expected              core/reflect.hpp, util/*
```

## 7. How other libraries approach the same problem

The notes below are general background, written from memory of each project's
public documentation and source, and are intended only to position the design
choices made here.

### 7.1 hffix

hffix is a header-only C++ library. Its central abstraction is a forward
iterator over the fields of a message held in a caller-owned buffer: the
iterator yields tag and value as views without copying or allocating, and the
message is parsed lazily as the caller advances. Writing is symmetric: a writer
appends fields into a buffer the caller provides and fixes up BodyLength and
CheckSum at the end. Field semantics are left to the application; hffix ships tag
name tables for convenience but does not enforce a dictionary. The scanning layer
in `include/glaze/fix/scan.hpp` is the closest analogue: `field` is a view, and
`next_field` is effectively the iterator step. Where this fork differs is the
layer above, which binds fields to typed struct members through glaze reflection
instead of leaving the application to switch on tag numbers.

### 7.2 QuickFIX

QuickFIX is a full engine: session management, sequence numbers, resend logic,
persistence, and message classes generated from an XML data dictionary. Its
`Message` type stores fields in ordered associative containers (a `std::map`
keyed by tag per header/body/trailer section), so field access is by tag at run
time and every field value is held as a string. The data dictionary drives
validation (required fields, allowed values, group layouts) at run time. The
design trades per-message allocation and lookup cost for generality and dynamic
reconfiguration. This fork intentionally does not try to be an engine; it provides
only the codec, and resolves the "dictionary" at compile time from the user's
struct, which is why unknown-tag handling and message-type checks are options
rather than schema lookups.

### 7.3 fix8

fix8 also starts from an XML dictionary but moves the work to build time: a
generator emits C++ classes for each message and field, with typed accessors and
static tables describing group structure. Field storage is in the generated
classes rather than a generic map, and the session layer is separate from the
message layer. Conceptually this is the same "schema known before the program
runs" position as this fork, but achieved by code generation rather than by
template reflection; the trade-off is an extra build step and generated sources
versus longer compile times and C++20/23 requirements.

### 7.4 simdjson's two-stage scanning

simdjson separates structural discovery from value parsing. Stage 1 sweeps the
whole input with SIMD, classifying bytes (quotes, backslashes, braces, commas,
whitespace) and producing a compact index of structural character positions.
Stage 2 then walks that index to build or lazily expose the document, parsing
numbers and strings only where needed. The appeal is that stage 1 is branch-light
and cache-friendly, and stage 2 can be an on-demand iterator.

FIX's structure is simpler than JSON's (no nesting syntax, no string escaping;
only the raw-data length fields break the "split on delimiter" rule), so the
analogue of stage 1 is finding `=` and SOH positions. glaze's SWAR helpers in
`include/glaze/util/parse.hpp` (`repeat_byte8`, `has_zero`, `countr_zero`-based
locate) are the natural building blocks if `next_field` is ever rewritten to scan
a word at a time; the raw-data pairing in `scan_state` would remain a sequential
fix-up over the structural positions, exactly as simdjson's stage 2 corrects for
quoted regions.

## 8. Where to look when changing things

| Task                                   | Files                                                     |
|----------------------------------------|-----------------------------------------------------------|
| Add a FIX option                       | `include/glaze/fix/opts.hpp`, read in `fix/codec.hpp`     |
| Change field splitting or framing      | `include/glaze/fix/scan.hpp`                              |
| Add a typed FIX value                  | `include/glaze/fix/types.hpp`, `decode_scalar` in codec   |
| Support a new member type              | `from<FIX,T>` / `to<FIX,T>` in `include/glaze/fix/codec.hpp` |
| Understand how `glz::read` reaches FIX | `include/glaze/core/read.hpp`, `include/glaze/forward.hpp` |
| Understand reflected keys              | `include/glaze/core/reflect.hpp`, `include/glaze/reflection/` |
| Design rationale and known limits      | `docs/fix/design.md`, `docs/fix/api.md`                    |
