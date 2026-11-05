# FIX data dictionary

The FIX data dictionary layer gives glaze a C++ type for every FIX message, repeating group,
component and code set of a FIX version, plus a `glz::meta` mapping members to FIX tag numbers.
The FIX tag=value codec reads and writes these types (see the API contract in `docs/fix/api.md`).

| Version  | Header                               | Namespace          | Source file (FIX Trading Community)   |
|----------|--------------------------------------|--------------------|---------------------------------------|
| FIX 4.2  | `include/glaze/fix/dict/fix42.hpp`   | `glz::fix::fix42`  | `OrchestraFIX42.xml` (FIX.4.2_EP311)  |
| FIX 4.4  | `include/glaze/fix/dict/fix44.hpp`   | `glz::fix::fix44`  | `OrchestraFIX44.xml` (FIX.4.4_EP311)  |
| FIXT 1.1 session | `include/glaze/fix/dict/fixt11.hpp` | `glz::fix::fixt11` | `FIXTSession.xml` (FIXT, as of FIX.5.0SP2_EP247) |
| FIX 5.0 SP2 | generated on demand (~5.6 MB), not committed | `glz::fix::fix50sp2` | `FixRepositoryUnifiedEP247.xml` (FIX.5.0SP2_EP247, Repository 2010 Unified format) |
| FIX Latest (5.0 SP2 + later extension packs) | generated on demand (~6 MB), not committed | `glz::fix::fixlatest` | `OrchestraFIXLatest.xml` |

## Licence of the source data

The FIX 4.2, 4.4 and Latest data comes from <https://github.com/FIXTradingCommunity/orchestrations>,
directory `FIX Standard/`. That repository's README and `LICENSE` say:

> © Copyright 2017-2026 FIX Protocol Limited.
> Licensed under the Apache License, Version 2.0.

The FIX 5.0 SP2 data is `repository-util/src/test/resources/FixRepositoryUnifiedEP247.xml` in
<https://github.com/FIXTradingCommunity/fix-orchestra>, whose `LICENSE` is also Apache-2.0 (the
same text, byte for byte, as orchestrations'). The schema for that format is in
<https://github.com/FIXTradingCommunity/fix-repository> (Apache-2.0, © 2015 FIX Protocol Limited).

Each XML file's metadata also carries `dcterms:rights` "Copyright (c) FIX Protocol Ltd. All
Rights Reserved." Under the repository's Apache-2.0 grant, the derived headers can be
redistributed with a copy of the licence and the attribution kept. Therefore:

* each generated header names its source file, version and copyright holder in its preamble;
* `include/glaze/fix/dict/LICENSE-FIX-ORCHESTRA` is a verbatim copy of the orchestrations
  repository's Apache-2.0 `LICENSE`;
* the generated headers hold only names, tag numbers, enum values and structure. The
  descriptive documentation text from the XML is not copied.

The generator itself (`util/fix_codegen/fix_codegen.py`) is original code under glaze's MIT licence.
No XML file is committed. Fetch it to regenerate.

## Regenerating

```sh
git clone --depth 1 https://github.com/FIXTradingCommunity/orchestrations /tmp/refs/orchestrations
S="/tmp/refs/orchestrations/FIX Standard"
python3 util/fix_codegen/fix_codegen.py --xml "$S/OrchestraFIX44.xml" --namespace fix44 \
    --out include/glaze/fix/dict/fix44.hpp
python3 util/fix_codegen/fix_codegen.py --xml "$S/OrchestraFIX42.xml" --namespace fix42 \
    --out include/glaze/fix/dict/fix42.hpp
python3 util/fix_codegen/fix_codegen.py --xml "$S/FIXTSession.xml" --namespace fixt11 \
    --out include/glaze/fix/dict/fixt11.hpp
python3 util/fix_codegen/fix_codegen.py --xml "$S/OrchestraFIXLatest.xml" --namespace fixlatest \
    --out include/glaze/fix/dict/fixlatest.hpp   # ~6 MB, not committed

git clone --depth 1 https://github.com/FIXTradingCommunity/fix-orchestra /tmp/refs/fix-orchestra
python3 util/fix_codegen/fix_codegen.py \
    --xml /tmp/refs/fix-orchestra/repository-util/src/test/resources/FixRepositoryUnifiedEP247.xml \
    --namespace fix50sp2 --out include/glaze/fix/dict/fix50sp2.hpp   # ~5.6 MB, not committed
```

The input format is detected from the root element: `fixr:repository` (Orchestra) or
`fixRepository` (Repository 2010 Edition, Unified). In the 2010 format, enums are inline in
`<field>`, and each becomes a code set named after its field. A `BlockRepeating` component becomes
a group named after the component. An inline `<repeatingGroup>` becomes a group named after its
NumInGroup field, without the `No` prefix.

The generator uses the Python 3 standard library only (`xml.etree.ElementTree`, `argparse`, `re`).

## What gets generated

```cpp
namespace glz::fix::fix44 {
  inline constexpr std::string_view begin_string = "FIX.4.4";
  namespace tag { inline constexpr uint32_t ClOrdID = 11; /* every field */ }

  enum class Side : char { Buy = '1', Sell = '2', /* ... */ };          // char code sets
  enum class PartyRole : int32_t { ExecutingFirm = 1, /* ... */ };      // int code sets
  enum class ResetSeqNumFlag : uint16_t { Yes = 0, No = 1 };            // other code sets: ordinal (reference only)

  struct PartiesGrp {                                                    // repeating group
    std::optional<std::string> party_id{};
    std::optional<PartyIDSource> party_id_source{};
    std::optional<PartyRole> party_role{};
    std::vector<PtysSubGrp> no_party_sub_ids{};                          // nested group
    bool operator==(const PartiesGrp&) const = default;
  };
  struct Instrument { /* component, flattened */ };
  struct NewOrderSingle {                                                // message
    std::string cl_ord_id{};                                             // required -> plain
    std::vector<PartiesGrp> no_party_ids{};                              // group keyed by 453
    std::optional<std::string> symbol{};                                 // optional -> std::optional
    Side side{};
    /* ... */
  };
}
template <> struct glz::meta<glz::fix::fix44::Side> {
  using enum glz::fix::fix44::Side;
  static constexpr auto value = glz::enumerate(Buy, Sell, /* ... */);    // names: JSON etc. work
  static constexpr std::array<std::string_view, N> fix_values{"1", "2", /* ... */}; // wire values
};
template <> struct glz::meta<glz::fix::fix44::NewOrderSingle> {
  using T = glz::fix::fix44::NewOrderSingle;
  static constexpr std::string_view fix_msg_type = "D";
  static constexpr std::string_view fix_begin_string = "FIX.4.4";
  static constexpr auto value = glz::object("11", &T::cl_ord_id, "453", &T::no_party_ids, /* ... */);
};
```

### Mapping rules

* **Fields.** Orchestra type to C++ type: `int`, `Length`, `SeqNum`, `TagNum`, `DayOfMonth` → `int64_t`;
  `float`, `Price`, `Qty`, `Amt`, `Percentage`, `PriceOffset` → `double`; `char` → `char`;
  `Boolean` → `bool` (Y/N); a char or int code set → its `enum class`; a Boolean code set →
  `bool`; a String code set or a `MultipleValueString` / `MultipleCharValue` /
  `MultipleStringValue` code set → `std::string` (multi-value is space-separated on the wire);
  everything else (String, dates, times, Currency, data, ...) → `std::string`.
* **Presence.** `presence="required"` members are plain values. All others are `std::optional`.
  A field inside a component is required only if both the field and the reference to its
  component are required.
* **Member names.** snake_case of the FIX name (`ClOrdID` → `cl_ord_id`, `NoPartyIDs` →
  `no_party_ids`). C++ keywords get a trailing `_`.
* **Enums.** One `enum class` per code set that a field uses. The `CodeSet` suffix is dropped.
  The underlying type is `char` (single-char values), `int32_t` (integer values) or `uint16_t`
  (ordinal, for String/Boolean code sets). `fix_values[i]` is the wire string of the i-th
  enumerator in `glz::enumerate` order. `fix/core` writes an enum as its underlying value, so
  only char and int enums are used as members. Ordinal enums are emitted for reference (names,
  wire values) but the member stays `bool` / `std::string`.
* **Components** are flattened into the struct that uses them, because tag=value has no component
  boundary on the wire. If a tag is reached twice through different components, the first wins.
  Every component is also emitted as a standalone struct, including `StandardHeader` and
  `StandardTrailer`.
* **Repeating groups** become `std::vector<XxxGrp>` keyed by the NumInGroup tag. The group's
  first member is its delimiter field. The codec writes the count and then each instance's fields
  in declaration order. On read, an instance ends at the first tag that the group does not own,
  or at a tag that repeats.
* **Messages.** The StandardHeader fields other than 8, 9 and 35 are flattened into every
  message, ahead of the body fields, in the dictionary's header order: SenderCompID(49),
  TargetCompID(56), MsgSeqNum(34), SendingTime(52), PossDupFlag(43), OrigSendingTime(122) and the
  rest, and ApplVerID(1128) for FIX 5.x. They read and write like any other member, and the
  required ones (49, 56, 34, 52) are plain members. The codec fills 8, 9, 35 and 10. The
  StandardTrailer (93/89 signature) is left out. `--no-header` turns the flattening off.
* **Session layer.** Logon, Heartbeat, TestRequest, ResendRequest, Reject, SequenceReset and
  Logout come from the same Orchestra files (`OrchestraFIX42.xml`, `OrchestraFIX44.xml`, which
  include the Session category), so they are ordinary generated messages. Boolean code sets such
  as GapFillFlag(123), ResetSeqNumFlag(141) and PossDupFlag(43) are `bool`.
* **FIX 5.x / FIXT.1.1.** For a dictionary whose version is FIX.5.x or FIX.Latest, the generator
  sets `fix_begin_string = "FIXT.1.1"` (tag 8 on the wire). The namespace gets
  `begin_string = "FIXT.1.1"`, `dictionary_version = "FIX.5.0SP2"` and `appl_ver_id = "9"`, and
  message metas get `fix_appl_ver_id = "9"` (from the ApplVerID code set: 7 = 5.0, 8 = 5.0 SP1,
  9 = 5.0 SP2). FIX.Latest has no fixed ApplVerID, so none is emitted for it. The ApplVerID(1128)
  member is `std::optional<std::string>`. The application sets it (e.g. to
  `std::string(fix50sp2::appl_ver_id)`) or leaves it absent when the session's
  DefaultApplVerID applies.
* **Name clashes** between structs and enums are resolved by appending `2`, `3`, ....

## Relation to the `fix/core` contract

* `glz::meta<Msg>::fix_begin_string` is accepted in `docs/fix/api.md` (v1).
* Group handling matches: the vector key is the NumInGroup tag, and the first group member is
  the delimiter.
* Proposed, not in the contract: `glz::meta<Enum>::fix_values`, which lets the codec reject a
  value outside its code set on read and write. It would also let String code sets be enums.
* Needed from `fix/core` for FIXT (not changed here):
  1. On read, compare tag 8 with `meta<T>::fix_begin_string` (opt-in, like `validate_msg_type`).
     Today any BeginString is accepted.
  2. On write, emit `1128=<meta<T>::fix_appl_ver_id>` after 35 when the message has no
     ApplVerID member set. Today the application must set the member, or the field is absent.
  3. A per-call or per-session BeginString override, for counterparties that send FIX 5.0 SP2
     application messages with a FIX 4.x-style 8.
* Reported to `fix/core`: doubles are written with shortest `std::to_chars`, which gives an
  exponent for values like 1000000 (`1e+06`). FIX float fields have no exponent, so
  `std::chars_format::fixed` is needed. The byte-exact test here avoids such values for now.

## Limitations

* The 5.0 SP2 file holds the application layer only. FIXT.1.1 session messages (Logon with
  DefaultApplVerID(1137), Heartbeat, ...) are in `fixt11.hpp`, generated from `FIXTSession.xml`.
  A FIXT session uses `fixt11` for session messages and `fix50sp2` for application messages.
* The 2010 Unified file is EP247, so it lacks extension packs after EP247.
* Enum values are not checked against their code set (the codec reads and writes the
  underlying value). A required enum left default-constructed is written as a NUL byte.
* `data` fields (with their `Length` field, e.g. RawData 96) are plain strings. A value holding
  SOH needs length-aware scanning in the codec.
* Orchestra scenarios other than `base` are skipped.
* User-defined fields: add them to the struct and meta by hand, or generate from a custom
  Orchestra file. The generator accepts any Orchestra repository file.
