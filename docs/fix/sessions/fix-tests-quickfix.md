# Session notes: `fix/tests-quickfix`

Goal: port QuickFIX's C++ unit tests for parsing, serialisation, field conversion, checksum,
BodyLength, header/trailer order, repeating groups and malformed messages. The ported tests target
the shared glaze FIX API contract, so they form a suite the FIX core must pass in full.

## State at the end of the session

* `include/glaze/fix/fix.hpp` is a **local stub** of the contract. It implements only
  `parse_fields`, `checksum`, `validate` and `frame`, and is enough to run the low-level tests.
  `fix/core` had not pushed a header during this session. **When merging `fix/core`, take its
  `fix.hpp` and drop this stub.**
* `tests/fix_quickfix_test/` is registered in `tests/CMakeLists.txt`.
  * `fix_quickfix_test.cpp` runs the low-level tests. Built with GCC 13 under the `gcc-debug`
    preset (`-fno-exceptions -fno-rtti -Werror`): **77 tests, 275 asserts, all passing** against
    the stub.
  * `fix_quickfix_struct_tests.inl` holds the struct-mapping tests: field conversion, typed messages,
    groups, and the `fix_opts` switches. They are compiled only when the core defines
    `GLZ_FIX_STRUCT_MAPPING`. Time-type tests also need `GLZ_FIX_TIME_TYPES`. **Neither macro is in
    the contract yet. They are proposals for `fix/core` to accept or replace.** These tests have
    passed a GCC syntax check but have never been compiled against a real core. Expect some
    mechanical fixes, for example in how `glz::write` picks BeginString (the tests sidestep this by
    comparing only the bytes from `35=` to `10=` and requiring that `validate` passes).
  * Tests that can't run print `SKIPPED: <source> -- <reason>` (20 groups when neither macro is set).
* Toolchain notes: the CMake in the image is 3.28, but glaze needs 3.31 or later, so I used
  `pip install --user cmake` and put `~/.local/bin` on `PATH`. Clang 18 with libstdc++ 13 lacks
  `std::expected` here, so only GCC was used.
* **Pushing failed for the whole session.** The git proxy answered 403: "ray-manaloto/glaze is not in
  this session's authorized repository set". Fetching worked; pushing did not. All work is in local
  commits on `fix/tests-quickfix`.

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
* `UtcTimeStampTestCase.cpp` / `UtcTimeOnlyTestCase.cpp` (comparison and arithmetic) depend on the
  time type that is chosen, so they were not ported.
* `DoubleConvertor` precision/padding variants such as `convert(1.5, 3) == "1.500"` were not ported,
  because the contract has no precision option.
* QuickFIX's `spec/FIX*.xml` dictionaries were not used. No dictionary-driven code exists yet.

## Next steps

1. Merge `fix/core`, delete the local stub, and rebuild `fix_quickfix_test`.
2. Agree in `docs/fix/api.md` on a macro or other gate for struct mapping and time types (or drop
   the gate once the core always provides them). Then build the `.inl` tests and fix any mismatches.
3. Settle the assumptions listed in `docs/fix/quickfix-tests.md` (for example, `frame` returns 0 for
   a malformed length, and integer reads reject a leading `+`).
4. Add the dictionary-dependent tests once the contract has a dictionary or header/trailer tag sets.
