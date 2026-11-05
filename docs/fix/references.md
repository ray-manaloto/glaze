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
switch) were skipped; the file header lists them. `simplefix.leading_junk_pairs` is `pending` on
API question Q1 (`docs/fix/api-questions.md`).

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

<!-- PHILADELPHIA_ARTIO_FEFIX -->

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
**Ported:** nothing copied. The structural cases these suites cover (bad CheckSum, BodyLength too long
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
