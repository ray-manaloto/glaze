# FIX tag=value in glaze: design notes

## What FIX tag=value is

A FIX message is a flat sequence of `tag=value<SOH>` fields, where the tag is a decimal integer,
the value is ASCII text, and SOH is byte 0x01. Three fields frame every message:
`8=BeginString`, then `9=BodyLength` (bytes from after 9's SOH to before `10=`), then `35=MsgType`,
and the message ends with `10=CheckSum` (three digits, the sum of every preceding byte mod 256).
Structure beyond that is implicit. A repeating group is a count field (`NoXXX`, e.g. 453
NoPartyIDs) followed by that many entries, and each entry starts with a fixed delimiter tag
(448 PartyID). Nothing marks where a group ends: it ends at the first tag that does not belong
to it. So you can only parse groups if you know the message's data dictionary, and in glaze the
`glz::meta` mapping is that dictionary.

## Why it differs from BEVE

| | FIX tag=value | BEVE |
|---|---|---|
| encoding | text, every value is ASCII digits/characters | typed binary (little-endian numbers, typed arrays) |
| delimiting | SOH after every field; no lengths except tag 9 | length/size prefixes and type tags in headers |
| keys | integer tags, written as decimal text | strings (or integer keys for maps) |
| self-describing | no; types come from the dictionary | yes; a reader can skip any value without a schema |
| nesting | none on the wire; groups are inferred from tag membership | explicit objects and arrays |
| integrity | BodyLength + mod-256 checksum in-band | none in-band |
| numbers | decimal text, so prices are exact decimals as written | IEEE binary floats or integers |

So the two codecs share almost nothing at the byte level. BEVE's reader is driven by the bytes,
since the type tag says what comes next. The FIX reader has to be driven by the schema, because
the tag only means something through the mapping. That is why the FIX reader works in two passes. It
first splits the message into `(tag, view)` fields and checks the envelope, then walks the
fields against the compile-time tag table of the target struct. A group entry hands control back
to its parent when it meets a tag it does not own.

## What glaze's design gives FIX

* **Custom format ids.** `glz::FIX = 65536 + 9` plugs into `glz::read<Opts>` / `glz::write<Opts>`
  through `parse<FIX>` / `serialize<FIX>` and `from<FIX, T>` / `to<FIX, T>` specialisations, the
  same mechanism BEVE, TOML and EETF use. Existing glaze entry points, `error_ctx`, buffer
  handling and `format_error` work unchanged.
* **Options as a struct type.** `fix_opts : opts` adds the delimiter and the validation switches
  as compile-time options, so `soh = '|'` for tests and `validate_checksum = false` for replay
  cost nothing at run time when they are off.
* **`glz::meta` as the data dictionary.** `glz::object("11", &T::cl_ord_id, ...)` already maps
  string keys to members. FIX reads those keys as tag numbers at compile time (`tags<T>`), so
  any mistake in a key is a compile error, and the struct's member types give each field's FIX type.
  Repeating groups fall out of `std::vector<Group>` members, and nesting is just recursion.
* **Views.** `std::string_view` members read as views into the input, so a read-only decode of
  an execution report need not allocate for its string fields.
* **No exceptions, no RTTI.** Like the rest of glaze, errors travel in the context and come back
  as `error_ctx`, so the code builds with `-fno-exceptions -fno-rtti`.

## How SBE relates

Simple Binary Encoding (SBE) is FIX Trading Community's binary encoding of the same FIX
application messages. It is a third point on the spectrum. Like BEVE it is binary, but unlike
BEVE it is not self-describing. An XML schema fixes each message's layout: a fixed-size root
block at known offsets, then repeating groups (with a block-length/count header), then
variable-length data. It is schema-driven like FIX tag=value, with offsets taking the place of
tags.

In glaze terms, an SBE codec would reuse the same `glz::meta` mapping idea, with extra
per-field metadata (offset, primitive type, null value) in place of tag numbers. It would plug in
the same way, as another custom format id with its own `from`/`to`. The tag numbers declared for
FIX tag=value are the FIX field ids that SBE schemas also carry, so the same struct could, in
principle, carry both mappings. That is future work; nothing SBE-specific is implemented here.

## Current limits

* Raw-data fields use a fixed table of the standard length/data pairs; custom pairs are not
  configurable.
* UTCTimestamp and an exact decimal are typed. UTCDateOnly, UTCTimeOnly, LocalMktDate and
  MonthYear are still text.
* Header and trailer fields other than 8/9/35/10 (49, 56, 34, 52, ...) are mapped as ordinary
  members; there is no separate standard-header struct.
* A message is held whole in memory; `frame` finds message boundaries in a stream but the codec
  does not read incrementally.
* `parse_fields` allocates a `std::vector<field>`. `field_cursor` / `for_each_field` (used by
  the reader) do not.
