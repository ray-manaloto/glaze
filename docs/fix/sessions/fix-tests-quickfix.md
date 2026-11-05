# Session notes: `fix/tests-quickfix`

Goal: port QuickFIX's C++ unit tests for parsing, serialisation, field conversion, checksum,
BodyLength, header/trailer order, repeating groups and malformed messages. The ported tests target
the shared glaze FIX API contract, so they form a suite the FIX core must pass in full.

## State at the end of the session

* `fix/core` was merged at `e5babf6e`, and again at `5d289570` (v2: raw-data fields, `utc_timestamp`, `decimal`).
  Its `include/glaze/fix/fix.hpp` replaced my local stub.
* `tests/fix_quickfix_test/` is registered in `tests/CMakeLists.txt`. Against `fix/core`, built with GCC 13
  under the `gcc-debug` preset (`-fno-exceptions -fno-rtti -Werror`), it gives **174 tests and 729 asserts,
  all passing, with 15 groups skipped** (final run, 07:40 UTC, against fix/core `5d289570`). Build and run it with
  `cmake --build build/debug-gcc --target fix_quickfix_test && build/debug-gcc/tests/fix_quickfix_test/fix_quickfix_test`.
  * `fix_quickfix_test.cpp` covers `validate`, `checksum`, `frame` and `parse_fields`, plus the
    QuickFIX/J and QuickFIX/n vectors.
  * `fix_quickfix_more_tests.inl` (added in the second half of the session) has typed QuickFIX/J and
    QuickFIX/n cases (nested and header groups, wrong group counts, delimiter-first rule, `=` inside values,
    empty values, missing 35, ISO-8859-1 bytes, the `validate_checksum=false` read, decoder framing of
    garbage and bad lengths). It also has more QuickFIX C++ `*GetString`/`*SetString` pairs
    (ExecutionReport, DontKnowTrade, OrderCancelReplaceRequest, OrderCancelRequest, NewOrderList,
    NewOrderCross, AllocationInstruction). Writes are compared **byte for byte** with QuickFIX's
    expected strings, using `meta<T>::fix_begin_string`.
  * `fix_quickfix_v2_tests.inl` holds cases that use fix/core v2. Raw data: QuickFIX `massQuoteSetString`
    and `massQuoteParseGetString` (365 holds SOH; the write is exact and 364 is filled in
    automatically), QuickFIX/J `testMessageBytesField` with SOH and `=` inside 96, QuickFIX/n
    `ReadXmlDataTest` (213 holds a whole FIX message), and `setStringWithDataFieldAndGarbageAsDataLength`.
    UTCTimestamp: `utcTimeStampConvertFrom*` and `utcTimeStampConvertTo*`, plus bad dates and times
    taken from `utcDateConvertFrom`. Decimal: the `doubleConvertFrom`/`doubleConvertTo` vectors run
    through `glz::fix::decimal`, which rejects exponents and keeps the scale. That gives the QuickFIX
    behaviour on a type the core does support; divergence 2 remains for `double`.
  * `fix_quickfix_struct_tests.inl` covers field conversion, typed messages, repeating groups and the
    `fix_opts` switches. The test file now defines `GLZ_FIX_STRUCT_MAPPING` itself, because the core
    always provides struct mapping. The time-type tests are still behind `GLZ_FIX_TIME_TYPES`; the core
    keeps timestamps as text.
* **Where the core differs from QuickFIX.** These are left in as `SKIPPED` with a reason, so the core
  can decide whether to change:
  1. `frame()` needs a 3-digit CheckSum. QuickFIX's Parser vectors use `10=31`, so the framing tests run
     on the vectors widened to `10=031`.
  2. Doubles: the core reads `1e5` and writes `1e-05` / `1e+14`. FIX Float forbids exponents, and
     QuickFIX rejects them on read and never writes them.
  3. A repeating-group entry must begin with the group's first member. QuickFIX's
     `setStringWithGroupWithoutDelimiter` leaves out 11. The test checks that the strict mapping
     rejects it, and that a mapping with 67 first reads it.
  4. An empty input is an error in `parse_fields` (`no_read_input`). My stub had allowed it.

  These are recorded too, but are not counted among the four:
  * Data fields used to be skipped. fix/core v2 supports them, and those tests now pass (see above).
  * Observation, not a skip: `glz::fix::decimal::to_double()` of `0.00340244000` (340244000e-11) is
    not equal to the literal `0.00340244`, because the conversion is not correctly rounded. The test
    checks the exact mantissa and exponent instead.
  * Skipped because fix/core lets a repeated top-level tag overwrite instead of reporting it
    (QuickFIX/n `RepeatedTagDetection`).
  * Skipped because a data dictionary is needed: rejecting header tags that come after the body
    (QuickFIX/J `testValidateFieldsOutOfOrderFIXT11`, unorderedData).
  * Not a divergence: fix/core frames `8=!@#$%8=FIX.4.2...` as one message, because a value may
    contain `=`. The test only requires that the framed bytes fail `validate()`. Resyncing on garbage
    is the caller's job, as it is in QuickFIX/J's decoder.
* Toolchain: the image's CMake is 3.28 but glaze needs 3.31 or later, so I used
  `pip install --user cmake` and put `~/.local/bin` on `PATH`. Clang 18 with libstdc++ 13 lacks
  `std::expected` here, so only GCC was used.
* Pushing failed until the repo was added to the session's sources around 07:12 UTC. Everything is now pushed.

## Provenance

Source: QuickFIX, <https://github.com/quickfix/quickfix>, commit
`386ce46e917ae494ab6e90b1be90fd421cdbe3f9`, directory `src/C++/test/`. Licence: The QuickFIX
Software License 1.0 (BSD-style with an acknowledgement clause). It is copied verbatim to
`tests/fix_quickfix_test/QUICKFIX_LICENSE`. The acknowledgement ("This product includes software
developed by quickfixengine.org (http://www.quickfixengine.org/).") appears in the test source
header and in `docs/fix/quickfix-tests.md`. Clauses 4 and 5 mean that nothing here may use the
"QuickFIX" name to endorse the work or to name a product. The name is used only to state where tests
came from.

The tests do not copy QuickFIX's code. They reuse its message vectors and the intent of its cases.

| Ported test (ut name prefix) | QuickFIX file / TEST_CASE / SECTION |
|---|---|
| `setString / strGood, strNull, strTrailingCharacter, strNoChk, strBadChk, strBad, strBadHeaderOrder, strNoLengthAndChk, strBadLength, strBadChecksum, strJunk, strEmpty, strBodyFields` | `MessagesTestCase.cpp / MessageTests / setString` |
| `noEndingDelim` | `MessagesTestCase.cpp / MessageTests / noEndingDelim` |
| `setStringWithGroup`, `...WithoutDelimiter`, `...WithHeaderGroup`, `...HeaderGroupDefinedInComponent` (wire and typed) | same names in `MessagesTestCase.cpp / MessageTests` |
| `outOfOrder` (expected output only) | `MessagesTestCase.cpp / MessageTests / outOfOrder` |
| `logon/testRequest/resendRequest/reject/sequenceReset/logout/newOrderSingle Get/SetString` | same names in `MessagesTestCase.cpp / MessageTests` |
| `setString_TrailerStructureInvalid` | `MessagesTestCase.cpp / MessageTests / setString_TrailerStructureInvalid_MessageStructureInvalid` |
| `setStringAndValidate_IncorrectBodyLength` | `MessagesTestCase.cpp / MessageTests / setStringAndValidate_IncorrectBodyLength_InvalidException` |
| `executionReport/dontKnowTrade/orderCancelReplace/orderCancelRequest/newOrderList/newOrderCross Get/SetString`, `allocationInstructionParseGetString`, `allocationInstructionString` | same names in `MessagesTestCase.cpp / MessageTests` (in `fix_quickfix_more_tests.inl`) |
| `massQuoteParseGetString`, `massQuoteSetString` (skipped: data fields) | `MessagesTestCase.cpp / MessageTests` |
| `checkSum`, `checkSum of ported vectors` | `MessagesTestCase.cpp / MessageTests / checkSum` (+ declared 10= of the vectors above) |
| `high-bit bytes` | `MessagesTestCase.cpp / MessageTests / setStringWithHighBit` (byte value -92) |
| `extractLength`, `readFixMessage`, `readPartialFixMessage`, `readMessagesByteByByte`, `readMessageWithBadLength` | `ParserTestCase.cpp / ParserTests / <same>` |
| `int8/int16/uint32/integer/uint64 ConvertFrom/To`, `doubleConvertFrom/To`, `charConvertFrom/To`, `booleanConvertFrom/To`, `emptyConvert` | `FieldConvertorsTestCase.cpp / FieldConvertorTests / <same>` |
| `checkSumConvertTo` | `FieldConvertorsTestCase.cpp / FieldConvertorTests / checkSumConvertTo` |
| `utcTimeStampConvertFrom*/To*`, `utcDateConvertFrom/To`, `utcTimeOnlyConvertFromMicro/To*` | `FieldConvertorsTestCase.cpp / FieldConvertorTests / <same>` |

Tests marked `glaze-original` or `derived` were written for this suite. They are not from QuickFIX.

### QuickFIX/J and QuickFIX/n vectors

`tests/fix_quickfix_test/qfj_qfn_vectors.inl` holds 43 raw message vectors: 14 are valid on the
wire and 29 are not. A script extracted them from the test sources, with Java and C# escapes
decoded and `|`-joined messages converted to SOH. Each one records its source in `source`, given as
`<repo>/<path> / <class> / <test method>`. BodyLength and CheckSum were recomputed for every
vector, and the `note` field says which one is wrong. The suite `quickfixj_quickfixn_vectors`
requires `validate()` to agree with `wire_valid`, and requires every wire-valid vector to `frame`
to its full length. All of them pass against the stub except `ReadXmlDataTest`, which is skipped:
its 213 value contains SOH, and the contract has no length-prefixed data fields yet.

* QuickFIX/J: <https://github.com/quickfix-j/quickfixj>, commit `9ac173b2a69ef2305258330d88685eccad80512d`,
  `quickfixj-core/src/test/java/quickfix/{MessageTest,RepeatingGroupTest,MessageUtilsTest}.java`
  and `.../mina/message/FIXMessageDecoderTest.java`. Licence: QuickFIX Software License 1.0, kept as
  `QUICKFIXJ_LICENSE`.
* QuickFIX/n: <https://github.com/connamara/quickfixn>, commit `df6e1000feb7683123f71a87ce11f465970117d7`,
  `UnitTests/ParserTest.cs` and `UnitTests/MessageTests.cs`. Licence: QuickFIX Software License 1.0,
  kept as `QUICKFIXN_LICENSE`.


Typed QuickFIX/J and QuickFIX/n cases in `fix_quickfix_more_tests.inl`. Each ut name starts with the
repo and file, then the test method:

* QuickFIX/J `quickfixj-core/src/test/java/quickfix/MessageTest.java`: `testParsing`, `testHeaderGroupParsing`,
  `testParsing2`, `testNestedRepeatingGroup`, `testFieldWithEqualsCharacter`, `testFirstFieldInGroupIsDelimiter`,
  `testMessageBytesField`, `testValidation`, `testCalculateStringWithNestedGroups`,
  `testValidateFieldsOutOfOrderFIXT11`. The last three are read verbatim, and only a subset of their
  fields is mapped. The unordered variant is skipped, because a dictionary is needed to reject header
  fields that come after the body.
* QuickFIX/J `.../RepeatingGroupTest.java`: `testWrongGroupCount`. `.../MessageUtilsTest.java`: `testParse`,
  `testParseMessageWithoutChecksumValidation`.
* QuickFIX/J `.../mina/message/FIXMessageDecoderTest.java`: `testSimpleMessage`, `testGarbageAtStart`,
  `testLengthFormatError`, `testLengthFormatError2`, `testBadLengthTooLong`, `testBadLengthTooShort`,
  `testBogusMessageLength`, `testFailedPatternMatchAtEndOfBuffer`, `testWesternEuropeanDecoding`.
* QuickFIX/n `UnitTests/MessageTests.cs`: `ConstructStringTest`, `TripleNestedGroups_Issue95`,
  `FromStringTestWithNoDataDictionary`, `RepeatedTagDetection`, `GetInvalidMsgTypeTest`, `IdentifyTypeTest`.
  `UnitTests/ParserTest.cs`: `ReadFixMessageWithMissingValues`, `ReadFixMessageWithNonAscii`.

Many of those originals carry a wrong 9 or 10. Where that happens the test keeps the body,
recomputes 9 and 10 with `make_msg()`, and says so in a comment. Some bodies were cut down to the
fields under test (`testNestedRepeatingGroup`, `testFieldWithEqualsCharacter`, `testWrongGroupCount`), and
`TripleNestedGroups_Issue95` gained an 887 level so that it really nests three deep. Each is marked
in the test.

Points to note from these vectors: many of their "good" messages have the wrong checksum (the
decoders frame only), and two use correct checksums written with only 1 or 2 digits. These are
marked invalid here because FIX requires exactly 3 digits. Also, in `RepeatedTagDetection`,
validation up to the *first* `10=` gives a correct 9 and 10, so a parser that stops at the first
`10=` would accept it.

## What is not done

* Tests that need a data dictionary are skipped with a reason: `headerFieldsFirst`, the
  DataDictionary part of `setString`, `outOfOrder` re-sorting, the raw-data length checks
  (`setStringWithDataFieldWithoutDataLength`, `...GarbageAsDataLength`) and the Signature trailer
  check.
* `GroupTestCase.cpp` and `FieldMapTestCase.cpp` test QuickFIX's container API, not the wire format,
  so they were not ported.
* `UtcTimeStampTestCase.cpp` / `UtcTimeOnlyTestCase.cpp` (comparison and arithmetic on QuickFIX's own time
  objects) and UTCTimeOnly/UTCDateOnly conversion: the contract has no types for these, so they stay skipped.
* Not ported from `MessagesTestCase.cpp`: `XMLNonFIXSetString`, `getXML`, `reverseRoute`, `addRemoveGroup`, `replaceGroup`,
  `copy`, `identifyType`, `isAdmin`/`isApp`. They test QuickFIX's API rather than the wire format.
* `DoubleConvertor` precision/padding variants such as `convert(1.5, 3) == "1.500"` were not ported,
  because the contract has no precision option.
* QuickFIX's `spec/FIX*.xml` dictionaries were not used. No dictionary-driven code exists yet.

## Next steps

1. Have `fix/core` decide on the four differences listed above. Either fix the core, for example by
   writing doubles in fixed notation, or record the behaviour in `docs/fix/api.md` and delete the
   matching skips.
2. If the contract gains UTCTimeOnly and UTCDateOnly types, port the remaining conversion vectors. The old
   `GLZ_FIX_TIME_TYPES` block in `fix_quickfix_struct_tests.inl` (a raw `std::chrono` mapping) can then
   be deleted, since `utc_timestamp` covers timestamps.
3. Check the assumptions listed in `docs/fix/quickfix-tests.md` against `docs/fix/api.md` whenever the core changes.
4. Add the dictionary-dependent tests once the contract has a dictionary or header/trailer tag sets.
5. Still to port: the remaining `FIXMessageDecoderTest` stream cases (resync after garbage, which is the
   caller's job here), QuickFIX/n `MessageTests.cs` cases that need a dictionary, and the FIX44/FIX50 spec
   XML from QuickFIX (no dictionary support yet).
