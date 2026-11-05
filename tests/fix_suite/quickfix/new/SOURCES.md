# Sources for fix_suite_quickfix.cpp

| Repository | Commit (`git rev-parse HEAD`, shallow clone) | Licence |
|---|---|---|
| https://github.com/quickfix/quickfix | 386ce46e917ae494ab6e90b1be90fd421cdbe3f9 | QuickFIX licence (BSD-style) — copied to `LICENSE.quickfix` |

QuickFIX/J and QuickFIX/n were not cloned in this pass (time budget); every test below comes from
the QuickFIX C++ repository under `src/C++/test/`.

| Test in fix_suite_quickfix.cpp | Source file (QuickFIX C++) | Source test |
|---|---|---|
| integerConvertFrom | src/C++/test/FieldConvertorsTestCase.cpp | integerConvertFrom |
| integerConvertFrom (unsigned) | src/C++/test/FieldConvertorsTestCase.cpp | integerConvertFrom |
| doubleConvertFrom | src/C++/test/FieldConvertorsTestCase.cpp | doubleConvertFrom |
| doubleConvertTo | src/C++/test/FieldConvertorsTestCase.cpp | doubleConvertTo |
| doubleConvertToWithPadding (decimal keeps scale) | src/C++/test/FieldConvertorsTestCase.cpp | doubleConvertToWithPadding |
| charConvertFrom | src/C++/test/FieldConvertorsTestCase.cpp | charConvertFrom |
| charConvertTo | src/C++/test/FieldConvertorsTestCase.cpp | charConvertTo |
| boolConvertFrom | src/C++/test/FieldConvertorsTestCase.cpp | boolConvertFrom |
| boolConvertTo | src/C++/test/FieldConvertorsTestCase.cpp | boolConvertTo |
| utcTimeStampConvertFrom | src/C++/test/FieldConvertorsTestCase.cpp | utcTimeStampConvertFrom |
| utcTimeStampConvertTo | src/C++/test/FieldConvertorsTestCase.cpp | utcTimeStampConvertTo |
| heartbeatGetString round-trip | src/C++/test/MessagesTestCase.cpp | heartbeatGetString / isAdmin |
| fixMsg1 Logon typed read | src/C++/test/ParserTestCase.cpp | readFixMessage (fixMsg1) |
| msgType mismatch on typed read | src/C++/test/MessagesTestCase.cpp | setString (MsgType checks) |
| fixMsg3 unknown tag tolerated / rejected by option | src/C++/test/ParserTestCase.cpp | readFixMessage (fixMsg3) |
| readMessageWithBadLength (9=200A) | src/C++/test/ParserTestCase.cpp | readMessageWithBadLength |
| extractLength (negative, incomplete) | src/C++/test/ParserTestCase.cpp | extractLength |
| readFixMessage (three messages framed in sequence) | src/C++/test/ParserTestCase.cpp | readFixMessage |
| setStringWithGroup nested groups typed round-trip | src/C++/test/MessagesTestCase.cpp | setStringWithGroup |
| group count mismatch is rejected | src/C++/test/GroupTestCase.cpp | (group semantics) |
| raw data with embedded SOH round-trip | src/C++/test/MessagesTestCase.cpp | setString strNull / raw data handling |
| 9=TEST 10=TEST rejected | src/C++/test/DataDictionaryTestCase.cpp | (TEST envelope vector) |

Notes: QuickFIX's ParserTestCase vectors use 2-digit checksums (`10=31`); glaze requires three
digits, so those bodies are re-framed wire-valid by the `wire()` helper. Two `extractLength`
sub-cases are recorded as `SKIP:` comments inside the file.
