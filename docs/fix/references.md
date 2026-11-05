# Reference FIX tag=value parsers

This page lists open-source FIX tag=value parsers whose test suites were read for branch
`fix/tests-more-parsers`. For each one it gives the licence, a short inventory of the tests, and what
was ported into `tests/fix_vectors_test/data/`. A vector was copied only when the licence plainly
allows it; the licence text sits beside the data in `tests/fix_vectors_test/data/licenses/`.
Where a licence is copyleft or carries extra conditions, nothing was copied, and the behaviour its
tests cover is instead written afresh from the FIX specification in `data/spec.fixv`.
`data/SOURCES.md` lists every vector with its origin.

All projects were read at the default-branch HEAD on 2026-11-05 (shallow clones, not committed).

## simplefix (Python), da4089/simplefix — MIT

The suite is unittest in `test/`, about 133 test methods. `test_message.py` (about 101 tests) covers
the `FixMessage` encoder: tag=value string input, raw versus full encoding, BodyLength and CheckSum
calculation, required 8 and 35 on encode, header-field order, repeated fields, value conversions
(large integers, enums) and much UTC and timezone timestamp formatting. `test_parser.py` (30 tests)
covers `FixParser`: whole and fragmented buffers, partial-buffer handling, empty values, non-numeric
tags, junk before BeginString, large integer values, raw data fields (95/96, including SOH inside data
and data split across packets), `=` inside values, alternative stop tags and stop bytes, and CME
secdef records without a BeginString. The parser does not check 9 and 10 on input, and several sample
messages carry wrong 9 and 10 values by accident.
**Ported:** 31 vectors in `simplefix.fixv` (15 parse, 5 validate, 8 frame, 3 checksum). Where a
sample's 9 or 10 was accidentally wrong, the validate and frame vectors use corrected values and say
so in `note`. Raw-data tests (SOH inside a value) and option-dependent tests (stop bytes, empty-value
switch) were skipped; the file header lists them. simplefix skips junk before `8=`; glaze's `frame()` reports `frame_error`
instead, so `simplefix.leading_junk_pairs` and `simplefix.junk_pairs_only` expect that.

## crocofix (C++), GaryHughes/crocofix — MIT

The core tests are Catch2 in `libcrocofix_tests/`, about 58 top-level tests. Only
`message_tests.cpp` (one `TEST_CASE` "Message" with 20 `SECTION`s) exercises the wire format:
decoding whole and split messages, invalid tags, RawData(89) with SOH inside, encode round trips with
optional BodyLength and CheckSum, and CheckSum formatting. Decode uses tag 10 only to find the end of
a message and does not check its value. `order_tests.cpp` and `order_book_tests.cpp` use about 40
literal FIX.4.4 and FIXT.1.1 order-flow messages (35=D/F/G/8/9). `session_tests.cpp` (35 fixture
tests) covers logon, heartbeats, sequence numbers, resend and rejects for bad CheckSum, BodyLength and
BeginString, but builds its messages at run time, so there are no fixed bytes to copy.
**Ported:** 32 vectors in `crocofix.fixv` (6 parse, 21 validate, 4 frame, 1 checksum). The order-flow
messages are good real-world validate vectors with correct 9 and 10. Two upstream messages kept a
stale `10=021` after an edit to 35; they are kept as `expect = error` and the note says why. One
source literal mixes `|` with an escaped SOH; both are treated as the separator.

## Philadelphia (Java), paritytrading/philadelphia — Apache-2.0

The core tests in `libraries/core/src/test/java/com/paritytrading/philadelphia/` are small and precise.
`FIXMessageParserTest` is the best framing source: it cuts the buffer at every point in the header
and trailer, and covers a garbled BeginString or BodyLength, a bad CheckSum with checking on and off,
and minimal FIX.4.2 and FIXT.1.1 messages. `FIXInitiatorTest` asserts the exact bytes of about 20
session messages (Logon, Logout, Heartbeat, TestRequest, ResendRequest, Reject, SequenceReset), all
with correct BodyLength and CheckSum. `FIXMessageTest` covers body-only formatting and parsing plus
capacity limits. `FIXValueTest`, `FIXIntDecoderTest` and `FIXTimestampTest` decode single values.
There is no NOTICE file upstream.
**Ported:** 30 vectors in `philadelphia.fixv`: the parser's minimal messages (validate, frame,
checksum), a garbled CheckSum, ten partial-buffer frame cases, garbled BeginString and BodyLength
frame cases, and nine exact session messages from `FIXInitiatorTest` as validate vectors. Value
decoder tests were not ported (they are below the tag=value layer).
**Second pass:** 23 more in `philadelphia_more.fixv`: the remaining exact wire messages from
`FIXInitiatorTest` (session Rejects for missing BeginSeqNo/EndSeqNo/NewSeqNo and BeginSeqNo too high,
SequenceReset-GapFill replies, Logouts, a ResendRequest, Heartbeats, a Heartbeat+TestRequest
two-message frame), the bare bodies the tests send, and an unterminated last field from
`receiveTooLongMessage`. The clone has no `FIXAcceptorTest`.

## Artio (Java), real-logic/artio — Apache-2.0

Artio keeps shared FIX messages in `artio-codecs/src/test/java/uk/co/real_logic/artio/util/TestMessages.java`.
`otf/OtfParserTest.java` checks tag scanning, field offsets, checksum errors, parse errors and
repeating groups; `artio-core/.../engine/framer/ReceiverEndPointTest.java` covers framing (complete,
split and back-to-back messages, too-short BodyLength, bad checksum, out-of-order header fields,
oversized messages). `SessionParserTest`, `CommonDecoderImplTest` and `AsciiBufferTest` test
CompIDs, decimals and integers. There is no NOTICE file upstream.
**Ported:** 23 vectors in `artio.fixv`: valid NewOrderSingle and Logon, five framing cases (one, two,
incomplete, complete-plus-partial), invalid checksum, too-short BodyLength, header out of order, an
empty-field parse error, repeating-group messages (parse and checksum only, since their upstream
BodyLength values are not correct and Artio's parser does not check them) and a message whose correct
CheckSum is `000`.
**Second pass:** 25 more in `artio_more.fixv`, from `BusinessRejectRefIdExtractorTest`,
`PossDupFinderTest`, `PasswordCleanerTest`, `FixMessagePredicateTest`, `SessionParserTest` and three
more `ReceiverEndPointTest` framing cases (Logon followed by an order, a split prefix, a missing final
SOH). Many of these fixtures carry wrong 9 or 10 values because the code under test never checks
them; they are ported as `validate` errors and each note gives the stated and actual values.

## ferrumfix / fefix (Rust), ferrumfix/ferrumfix — MIT OR Apache-2.0

The shallow clone at HEAD is a snapshot ("Initial public release snapshot") without the `crates/`
directory, so the tagvalue decoder unit tests (checksum, body length, streaming) were not available.
What it has: a regression test `tests/test_regression_tainted_decoder_fix44` (two ERISX messages
decoded with checksum checking off), `#[test] fn run()` wrappers around the examples (single decode,
streaming decode, a custom Coinbase dictionary) and `tests/codegen_fix44` (field metadata only). The
licence is declared in `Cargo.toml`; there is no licence or NOTICE file in the snapshot, so the
vectors are used under the Apache-2.0 option and its text is kept beside them.
**Ported:** 15 vectors in `fefix.fixv`. Several example messages carry a CheckSum that is wrong when
`|` is read as SOH; they are kept as parse-ok and validate-error vectors, with a note. A full history
of the repository (with `crates/`) would likely give more vectors.

## QuickFIX (C++), quickfix/quickfix; QuickFIX/J (Java), quickfix-j/quickfixj; QuickFIX/Go, quickfixgo/quickfix — QuickFIX Software License 1.0

All three use the QuickFIX Software License 1.0, a BSD-style licence with an end-user acknowledgment
clause and naming restrictions. It is permissive, but the extra conditions make it less clear-cut than
MIT or Apache-2.0, so nothing was copied. QuickFIX C++ has CppUnit-style suites in `src/C++/test/`
(`ParserTestCase.cpp`, `MessagesTestCase.cpp`, `FieldMapTestCase.cpp`, `GroupTestCase.cpp`, data
dictionary tests) and a large acceptance suite of 471 `.def` scripts under `test/definitions/`
(per FIX version: garbled messages, wrong BodyLength or BeginString, fields out of order, repeated
tags, repeating-group count mismatches, sequence-number handling). QuickFIX/Go has 33 `*_test.go`
files in the repo root (`parser_test.go` with 9 tests, `message_test.go` with 25, `validation_test.go`,
`repeating_group_test.go`) and its own copy of the acceptance suite (505 `.def` files). QuickFIX/J has
135 Java test files, including `MessageTest` and `MessageUtilsTest` in `quickfixj-base` and
`quickfixj-core`.
**Ported:** nothing copied. A second pass (`spec_more.fixv`, 78 vectors) took only the *categories*
of their parser, message, validation and repeating-group tests and fix8's message tests, and wrote
new messages for them: checksum high/low/out of range/non-digit/wrong width, BodyLength zero,
negative, huge, signed or padded, missing or doubled SOH, `=` at the start of a field, repeated 9,
empty 35, FIXT.1.1 messages, groups (flat, zero count, nested, followed by more fields) and frames
cut at every header boundary or with garbage between messages. The structural cases these suites cover (bad CheckSum, BodyLength too long
or too short, non-numeric BodyLength, 8/9/35 out of order, field after 10, missing 10, unterminated
fields, bad tags) are written afresh from the FIX specification in `spec.fixv`. The acceptance `.def`
categories are a good checklist for a later session-level test suite.

## fix8 (C++), fix8/fix8 — LGPL-3.0

`utests/` holds Google Test suites: `message_test.cpp` (47 tests, encode and decode of generated
FIX.4.4 messages), `session_test.cpp`, `filePersister_test.cpp` and `fileLogger_test.cpp`; `test/`
holds the `hftest` harness and sample configurations.
**Ported:** nothing. LGPL-3.0 data is not copied into this MIT project. The cases are covered by
`spec.fixv`.

## Not reached

NexusFix was listed as a candidate but no public repository was located in the time available.
Further candidates for a later session: OnixS samples (commercial, not usable), `fix-simulator`
style test corpora, and the FIX Trading Community's own FIX Orchestra examples (check their licence
first).
