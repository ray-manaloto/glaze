// Message vectors extracted (by script, then hand-checked) from the unit tests of
// quickfixj (https://github.com/quickfix-j/quickfixj) and
// quickfixn (https://github.com/connamara/quickfixn).
// Both are distributed under The QuickFIX Software License, Version 1.0
// (BSD-style, with acknowledgement clause; see each repo's LICENSE).
// SOH is always byte 0x01, emitted as the octal escape \001 (3 digits, so it
// can never absorb a following digit). Vectors whose source used '|' or a
// runtime join are normalised to 0x01 and say so in `note`.
// wire_valid == true iff: tags 8, 9, 35 are the first three fields, 10 is the
// last field (exactly one 8 and one 10), declared 9 == byte count after the
// SOH ending 9 through the SOH before "10=", and declared 10 is the 3-digit
// sum of all bytes before "10=" mod 256. Exception: when a 212/213 XmlData
// field is present its value is treated as opaque (length-prefixed), so an
// embedded 8=/10= inside it does not count (see ReadXmlDataTest).
// Requires <string_view>.
// This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/).
// Licences: QUICKFIXJ_LICENSE and QUICKFIXN_LICENSE in this directory.
namespace qfjn_vectors {
struct vec { const char* source; std::string_view msg; bool wire_valid; const char* note; };
inline const vec all[] = {
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testSimpleMessage",
    std::string_view{"8=FIX.4.2\001"
      "9=12\001"
      "35=X\001"
      "108=30\001"
      "10=049\001", 34},
    true,
    "minimal 35=X message (only 108 in body); the decoder frames by 9 and does not validate 10; 9 ok (12); 10 ok (049)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testGarbageAtStart",
    std::string_view{"8=FIX.4.2\001"
      "9=12\001"
      "35=X\001"
      "108=30\001"
      "10=036\001", 34},
    false,
    "the good message found after '8=!@#$%' garbage prefix; 9 ok (12); 10 declared 036 actual 049" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testBadLengthTooLong",
    std::string_view{"8=FIX.4.2\001"
      "9=25\001"
      "35=X\001"
      "108=30\001"
      "10=036\001", 34},
    false,
    "9=25 overstates body; decoder must resync to following good msg; 9 declared 25 actual 12; 10 declared 036 actual 053" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testBadLengthTooShort",
    std::string_view{"8=FIX.4.2\001"
      "9=10\001"
      "35=X\001"
      "108=30\001"
      "10=036\001", 34},
    false,
    "9=10 understates body; decoder must resync; 9 declared 10 actual 12; 10 declared 036 actual 047" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testBogusMessageLength",
    std::string_view{"8=FIX.4.2\001"
      "9=10xyz\001"
      "35=X\001"
      "108=30\001"
      "10=036\001", 37},
    false,
    "non-numeric BodyLength '10xyz'; 9 declared 10xyz actual 12; 10 declared 036 actual 154" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testMessageWithoutChecksum",
    std::string_view{"8=FIX.4.4\001"
      "9=275\001"
      "35=D\001"
      "34=3\001"
      "49=441000-XXXXX-X-XXXX-001\001"
      "52=20131113-10:22:31.567\001"
      "56=XXXXX\001"
      "1=A1\001"
      "11=9fef3663330e209e1bce\001"
      "18=H\001"
      "22=4\001"
      "38=200\001"
      "40=M\001"
      "48=XX0005519XXXX\001"
      "54=1\001"
      "55=[N/A]\001"
      "58=MassTest\001"
      "59=0\001"
      "60=20131113-10:22:31.567\001"
      "100=XXXX\001"
      "526=9fef3663330e209e1bce\001"
      "25029=12345\001"
      "453=1\001"
      "448=XXXXXXXX030\001"
      "447=D\001"
      "452=3610=016\001", 298},
    false,
    "QFJ-760: SOH missing before 10= ('452=3610=016'), so no CheckSum field; decoder returns NEED_DATA; no 10 field; 9=275 but no 10= trailer to measure against" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testBadBodyLength",
    std::string_view{"8=FIX.4.4\001"
      "9=A\001"
      "35=D\001"
      "49=ST\001"
      "56=TS\001"
      "34=3\001"
      "52=20160830-14:21:45.472\001"
      "11=Order32\001"
      "1=Template1\001"
      "21=1\001"
      "55=VOD.L\001"
      "48=VOD.L\001"
      "22=5\001"
      "167=CS\001"
      "207=LSE\001"
      "54=1\001"
      "60=20160830-14:21:45.472\001"
      "38=100\001"
      "40=2\001"
      "44=95\001"
      "15=GBp\001"
      "59=0\001"
      "58=Staging\001"
      "10=206\001", 205},
    false,
    "QFJ-903: BodyLength 'A' (non-numeric); test sends this twice then a good msg; 9 declared A actual 184; 10 declared 206 actual 158" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testLengthFormatError",
    std::string_view{"8=FIX.4.4\001"
      "9=058=\001"
      "8=FIX.4.4\001"
      "9=058=\001"
      "8=FIX.4.4\001"
      "9=058=\001"
      "8=FIX.4.4\001"
      "9=058=\001", 68},
    false,
    "issue #432: stream of four junk fragments '8=FIX.4.4|9=058=|' with no 35/10; must not loop forever; header order is 8/9/8 not 8/9/35; no 10 field; tag 8 x4, tag 10 x0 (repeated/embedded/concatenated); 9=058= but no 10= trailer to measure against" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testLengthFormatError2",
    std::string_view{"8=FIX.4.2\001"
      "9=128=FIX.4.2\001"
      "9=8=FIX.4.2\001"
      "9=128=FIX.4.2\001"
      "9=8=FIX.4.2\001"
      "9=12\001"
      "35=X\001"
      "108=30\001"
      "10=049\001", 86},
    false,
    "issue #432: interleaved truncated headers '9=128=FIX...' followed by one complete msg; decoder must find the final msg; header order is 8/9/9 not 8/9/35; 9 declared 128=FIX.4.2 actual 55; 10 declared 049 actual 075" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / testFailedPatternMatchAtEndOfBuffer",
    std::string_view{"8=FIX.4.2\001"
      "9=12\001"
      "35=X\001"
      "108=30\001"
      "1wmyadz", 34},
    false,
    "truncated trailer '1wmyadz' instead of 10=; decoder returns NEED_DATA; does not end with SOH (truncated); no 10 field; 9=12 but no 10= trailer to measure against" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/mina/message/FIXMessageDecoderTest.java / FIXMessageDecoderTest / doWesternEuropeanDecodingTest (testWesternEuropeanDecoding)",
    std::string_view{"8=FIX.4.4\001"
      "9=18\001"
      "35=B\001"
      "148=\344bcf\366d\347\351\001"
      "10=253\001", 40},
    true,
    "ISO-8859-1 high bytes in 148=Headline (8 bytes, one per char); reconstructed from literal + headline variable; 9 ok (18); 10 ok (253)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testHeaderGroupParsing",
    std::string_view{"8=FIX.4.2\001"
      "9=40\001"
      "35=A\001"
      "627=2\001"
      "628=FOO\001"
      "628=BAR\001"
      "98=0\001"
      "384=2\001"
      "372=D\001"
      "385=R\001"
      "372=8\001"
      "385=S\001"
      "10=228\001", 84},
    false,
    "627 NoHops repeating group in the header, then 384 NoMsgTypes group in the body; 9 declared 40 actual 62; 10 ok (228)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testParsing",
    std::string_view{"8=FIX.4.2\001"
      "9=40\001"
      "35=A\001"
      "98=0\001"
      "384=2\001"
      "372=D\001"
      "385=R\001"
      "372=8\001"
      "385=S\001"
      "10=96\001", 61},
    false,
    "Logon with 384 NoMsgTypes group; checksum written as 2 digits '96'; 9 ok (40); 10 declared 96 actual 096 (value matches but not 3 digits)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testParsing2",
    std::string_view{"8=FIX.4.2\001"
      "9=76\001"
      "35=6\001"
      "23=IDENTIFIER\001"
      "28=N\001"
      "55=MSFT\001"
      "54=1\001"
      "711=2\001"
      "311=DELL\001"
      "318=USD\001"
      "311=IBM\001"
      "318=CAD\001"
      "10=037\001", 98},
    true,
    "IOI (35=6) with 711 NoUnderlyings group; comment says checksum not verified [assembled from successive '+=' statements]; 9 ok (76); 10 ok (037)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testValidation",
    std::string_view{"8=FIX.4.4\001"
      "9=309\001"
      "35=8\001"
      "49=ASX\001"
      "56=CL1_FIX44\001"
      "34=4\001"
      "52=20060324-01:05:58\001"
      "17=X-B-WOW-1494E9A0:58BD3F9D-1109\001"
      "150=D\001"
      "39=0\001"
      "11=184271\001"
      "38=200\001"
      "198=1494E9A0:58BD3F9D\001"
      "526=4324\001"
      "37=B-WOW-1494E9A0:58BD3F9D\001"
      "55=WOW\001"
      "54=1\001"
      "151=200\001"
      "14=0\001"
      "40=2\001"
      "44=15\001"
      "59=1\001"
      "6=0\001"
      "453=3\001"
      "448=AAA35791\001"
      "447=D\001"
      "452=3\001"
      "448=8\001"
      "447=D\001"
      "452=4\001"
      "448=FIX11\001"
      "447=D\001"
      "452=36\001"
      "60=20060320-03:34:29\001"
      "10=169\001", 332},
    true,
    "ExecutionReport with 453 NoPartyIDs=3 group; validated against FIX44 dictionary; 9 ok (309); 10 ok (169)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testAppMessageValidation",
    std::string_view{"8=FIXT.1.1\001"
      "9=234\001"
      "35=W\001"
      "34=2\001"
      "49=ABFX\001"
      "52=20080722-16:37:11.234\001"
      "56=X2RV1\001"
      "55=EUR/USD\001"
      "262=CAP0000011\001"
      "268=2\001"
      "269=0\001"
      "270=1.57844\001"
      "15=EUR\001"
      "271=500000\001"
      "272=20080724\001"
      "269=1\001"
      "270=1.57869\001"
      "15=EUR\001"
      "271=500000\001"
      "272=20080724\001"
      "10=097\001", 206},
    false,
    "FIXT.1.1 MarketDataSnapshot (35=W) with 268 NoMDEntries group; 9 declared 234 actual 182; 10 ok (097)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testCalculateStringWithNestedGroups",
    std::string_view{"8=FIX.4.4\001"
      "9=247\001"
      "35=s\001"
      "34=5\001"
      "49=sender\001"
      "52=20060319-09:08:20.881\001"
      "56=target\001"
      "22=8\001"
      "40=2\001"
      "44=9\001"
      "48=ABC\001"
      "55=ABC\001"
      "60=20060319-09:08:19\001"
      "548=184214\001"
      "549=2\001"
      "550=0\001"
      "552=2\001"
      "54=1\001"
      "453=2\001"
      "448=8\001"
      "447=D\001"
      "452=4\001"
      "448=AAA35777\001"
      "447=D\001"
      "452=3\001"
      "38=9\001"
      "54=2\001"
      "453=2\001"
      "448=8\001"
      "447=D\001"
      "452=4\001"
      "448=aaa\001"
      "447=D\001"
      "452=3\001"
      "38=9\001"
      "10=056\001", 270},
    true,
    "expected toString() output with nested repeating groups (generated by QFJ, so expected well-formed); 9 ok (247); 10 ok (056)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testMessageBytesField",
    std::string_view{"8=FIX.4.4\001"
      "9=21\001"
      "35=A\001"
      "95=7\001"
      "96=rawdata\001"
      "10=086\001", 43},
    true,
    "Logon with RawDataLength(95)/RawData(96) data field; 9 ok (21); 10 ok (086)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testFieldWithEqualsCharacter",
    std::string_view{"8=FIXT.1.1\001"
      "9=369\001"
      "35=W\001"
      "49=I\001"
      "56=F\001"
      "34=4\001"
      "52=20111021-15:09:16.535\001"
      "262=1319209757316210\001"
      "21=2\001"
      "55=EUR/USD\001"
      "461=RCSXX=0\001"
      "268=8\001"
      "269=0\001"
      "270=1.38898\001"
      "271=2000000\001"
      "269=0\001"
      "270=1.38897\001"
      "271=8000000\001"
      "269=0\001"
      "270=1.38854\001"
      "271=2000000\001"
      "269=1\001"
      "270=1.38855\001"
      "271=6000000\001"
      "269=1\001"
      "270=1.38856\001"
      "271=7000000\001"
      "269=1\001"
      "270=1.38857\001"
      "271=3000000\001"
      "269=1\001"
      "270=1.38858\001"
      "271=9000000\001"
      "269=1\001"
      "270=1.38859\001"
      "271=100000000\001"
      "10=51\001", 365},
    false,
    "field values containing '=' must not split the field; 9 declared 369 actual 342; 10 declared 51 actual 008" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testNestedRepeatingGroup",
    std::string_view{"8=FIX.4.4\001"
      "9=265\001"
      "35=D\001"
      "34=62\001"
      "49=sender\001"
      "52=20160803-12:55:42.094\001"
      "56=target\001"
      "11=16H03A0000021\001"
      "15=CHF\001"
      "22=4\001"
      "38=13\001"
      "40=2\001"
      "44=132\001"
      "48=CH000000000\001"
      "54=1\001"
      "55=[N/A]\001"
      "59=0\001"
      "60=20160803-12:55:41.866\001"
      "207=XXXX\001"
      "423=2\001"
      "526=foo\001"
      "528=P\001"
      "453=1\001"
      "448=test\001"
      "447=D\001"
      "452=7\001"
      "20000=0\001"
      "802=1\001"
      "523=test\001"
      "803=25\001"
      "22000=foobar\001"
      "10=244\001", 284},
    false,
    "NewOrderSingle with 453 Parties group nested 802 PartySubIDs and an undefined tag 20000 inside the group [source uses '|' replaced by SOH at runtime via replaceAll; normalised to \\x01]; 9 declared 265 actual 261; 10 ok (244)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testValidateFieldsOutOfOrderFIXT11",
    std::string_view{"8=FIXT.1.1\001"
      "9=561\001"
      "35=AE\001"
      "34=545\001"
      "49=SENDER\001"
      "52=20220210-02:44:00.820\001"
      "56=TARGET\001"
      "115=ON_BHEHALF\001"
      "1128=9\001"
      "627=2\001"
      "628=HOPID1\001"
      "629=20220414-15:22:54\001"
      "628=HOPID2\001"
      "629=20220414-15:22:54\001"
      "15=AUD\001"
      "22=4\001"
      "31=27\001"
      "32=5000.000000000000\001"
      "48=AU000000ANZ3\001"
      "55=ANZ\001"
      "60=20220210-02:43:27.796\001"
      "64=20220214\001"
      "75=20220210\001"
      "106=4075\001"
      "167=CS\001"
      "381=135000\001"
      "461=Exxxxx\001"
      "487=0\001"
      "762=1\001"
      "880=7533509260093686098:0#NORMAL#1644451200000000000\001"
      "1003=1120000338\001"
      "1015=0\001"
      "1301=XASX\001"
      "552=2\001"
      "54=1\001"
      "453=1\001"
      "448=338-3\001"
      "447=D\001"
      "452=1\001"
      "1=1040445\001"
      "576=1\001"
      "577=0\001"
      "11=7533509260093758035\001"
      "54=2\001"
      "453=1\001"
      "448=338-3\001"
      "447=D\001"
      "452=1\001"
      "1=1040445\001"
      "576=1\001"
      "577=0\001"
      "11=7533509260093757876\001"
      "10=129\001", 585},
    true,
    "orderedData: TradeCaptureReport (35=AE) with nested groups, fields in dictionary order; 9 ok (561); 10 ok (129)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testValidateFieldsOutOfOrderFIXT11",
    std::string_view{"8=FIXT.1.1\001"
      "9=561\001"
      "35=AE\001"
      "15=AUD\001"
      "22=4\001"
      "31=27\001"
      "32=5000.000000000000\001"
      "48=AU000000ANZ3\001"
      "55=ANZ\001"
      "60=20220210-02:43:27.796\001"
      "64=20220214\001"
      "75=20220210\001"
      "106=4075\001"
      "167=CS\001"
      "381=135000\001"
      "461=Exxxxx\001"
      "487=0\001"
      "762=1\001"
      "880=7533509260093686098:0#NORMAL#1644451200000000000\001"
      "1003=1120000338\001"
      "1015=0\001"
      "1301=XASX\001"
      "552=2\001"
      "54=1\001"
      "453=1\001"
      "448=338-3\001"
      "447=D\001"
      "452=1\001"
      "1=1040445\001"
      "576=1\001"
      "577=0\001"
      "11=7533509260093758035\001"
      "54=2\001"
      "453=1\001"
      "448=338-3\001"
      "447=D\001"
      "452=1\001"
      "1=1040445\001"
      "576=1\001"
      "577=0\001"
      "11=7533509260093757876\001"
      "627=2\001"
      "628=HOPID1\001"
      "629=20220414-15:22:54\001"
      "628=HOPID2\001"
      "629=20220414-15:22:54\001"
      "34=545\001"
      "49=SENDER\001"
      "52=20220210-02:44:00.820\001"
      "56=TARGET\001"
      "115=ON_BHEHALF\001"
      "1128=9\001"
      "10=129\001", 585},
    true,
    "first unorderedData: header fields 34/49/52/56/115/1128 and 627 header group placed after body fields; framing (8/9/35, 9, 10) still correct; 9 ok (561); 10 ok (129)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageTest.java / MessageTest / testFirstFieldInGroupIsDelimiter",
    std::string_view{"8=FIX.4.4\001"
      "9=688\001"
      "35=AB\001"
      "49=AAA\001"
      "56=BBB\001"
      "34=21133\001"
      "50=ABCABC\001"
      "52=20230905-13:24:37.022\001"
      "55=AAPL\001"
      "1=ACC1\001"
      "11=123456abcedf\001"
      "21=1\001"
      "38=5\001"
      "54=1\001"
      "40=2\001"
      "44=-0.8\001"
      "59=0\001"
      "60=20230905-13:24:36.984\001"
      "100=ALGO\001"
      "167=MLEG\001"
      "555=3\001"
      "602=111\001"
      "600=AAA\001"
      "602=222\001"
      "654=231\001"
      "600=BBB\001"
      "602=333\001"
      "654=332\001"
      "600=CCC\001"
      "58=TEXT\001"
      "10=168\001", 272},
    false,
    "555 NoLegs group whose instances start with 602 instead of the delimiter 600 (FirstFieldInGroupIsDelimiter setting); 9 declared 688 actual 249; 10 ok (168)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/RepeatingGroupTest.java / RepeatingGroupTest / testWrongGroupCount",
    std::string_view{"8=FIX.4.4\001"
      "9=0\001"
      "35=i\001"
      "34=2\001"
      "49=TW\001"
      "52=20080203-00:29:51.453\001"
      "56=ISLD\001"
      "117=ID\001"
      "296=1\001"
      "302=X\001"
      "304=5\001"
      "295=50\001"
      "299=QID\001"
      "10=085\001", 110},
    false,
    "9=0 placeholder; nested 295 NoQuoteEntries=50 but only one instance (INCORRECT_NUMINGROUP_COUNT); 9 declared 0 actual 89; 10 ok (085)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/RepeatingGroupTest.java / RepeatingGroupTest / testSettingGettingGroupWithStandardFieldsInHeader",
    std::string_view{"8=FIX.4.4\001"
      "9=87\001"
      "35=0\001"
      "34=2\001"
      "52=20080203-00:29:51.453\001"
      "56=ISLD\001"
      "49=TW\001"
      "627=2\001"
      "628=_TED02A\001"
      "629=20090717-13:25:31.896\001"
      "628=_GWSURV\001"
      "629=20090717-13:25:31.928\001"
      "10=012\001", 153},
    false,
    "627 NoHops header group placed after 49 in header, validated as OK; 9 declared 87 actual 131; 10 declared 012 actual 222" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageUtilsTest.java / MessageUtilsTest / testParse",
    std::string_view{"8=FIX.4.0\001"
      "9=56\001"
      "35=A\001"
      "34=1\001"
      "49=TW\001"
      "52=20060118-16:34:19\001"
      "56=ISLD\001"
      "98=0\001"
      "108=2\001"
      "10=223\001", 78},
    true,
    "FIX.4.0 Logon parsed via MessageSessionUtils.parse; 9 ok (56); 10 ok (223)" },
  { "quickfixj/quickfixj-core/src/test/java/quickfix/MessageUtilsTest.java / MessageUtilsTest / testParseMessageWithoutChecksumValidation",
    std::string_view{"8=FIX.4.0\001"
      "9=56\001"
      "35=A\001"
      "34=1\001"
      "49=TW\001"
      "52=20060118-16:34:19\001"
      "56=ISLD\001"
      "98=0\001"
      "108=2\001"
      "10=283\001", 78},
    false,
    "QFJ-973: same Logon with checksum 283 (> 255, impossible) parsed with validateChecksum=false; 9 ok (56); 10 declared 283 actual 223" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / NormalLength (const used by ExtractLength, ReadFixMessageWithBadLength)",
    std::string_view{"8=FIX.4.2\001"
      "9=12\001"
      "35=A\001"
      " 108=30\001"
      "10=31\001", 34},
    false,
    "note leading space in ' 108=30' and 2-digit '10=31'; 9 declared 12 actual 13; 10 declared 31 actual 058" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / ExtractLength",
    std::string_view{"8=FIX.4.2\001"
      "9=-1\001"
      "35=A\001"
      "108=30\001"
      "10=31\001", 33},
    false,
    "negativeLength: BodyLength '-1'; 9 declared -1 actual 12; 10 declared 31 actual 021" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / ReadCompleteFixMessages",
    std::string_view{"8=FIX.4.2\001"
      "9=19\001"
      "35=A\001"
      "108=30\001"
      "9710=8\001"
      "10=31\001", 40},
    false,
    "fixMsg3: contains a body tag 9710 that starts with '9' and '10' digits (tests tag-prefix confusion); 9 ok (19); 10 declared 31 actual 104" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / ReadFixMessageWithBadLength",
    std::string_view{"8=TEST\001"
      "9=TEST\001"
      "35=TEST\001"
      "49=SS1\001"
      "56=RORE\001"
      "34=3\001"
      "52=20050222-16:45:53\001"
      "10=TEST\001", 71},
    false,
    "8=TEST / 9=TEST / 35=TEST / 10=TEST garbage message; parser throws then recovers; 9 declared TEST actual 49; 10 declared TEST actual 153" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / ReadFixMessageWithNonAscii",
    std::string_view{"8=FIX.4.4\001"
      "9=19\001"
      "35=B\001"
      "148=Ol\351!\001"
      "33=0\001"
      "10=0\001", 39},
    false,
    "fixMsg2: 'é' must count as one byte (ISO-8859-1) in BodyLength; checksum is a dummy '0' [built at runtime via string.Join(SOH, ...) + SOH; reconstructed]; 9 ok (19); 10 declared 0 actual 094" },
  { "quickfixn/UnitTests/ParserTest.cs / ParserTest / ReadFixMessageWithMissingValues",
    std::string_view{"8=FIX.4.4\001"
      "9=15\001"
      "35=B\001"
      "148=\001"
      "33=0\001"
      "10=0\001", 35},
    false,
    "issue #282: empty field value '148=' [built at runtime via string.Join(SOH, ...) + SOH; reconstructed]; 9 ok (15); 10 declared 0 actual 149" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / IdentifyTypeTest",
    std::string_view{"8=FIX4.2\001"
      "9=12\001"
      "\001"
      "35=B\001"
      "10=031\001", 27},
    false,
    "msg3: missing '.' in BeginString and empty field '||' before 35 [source uses '|' replaced by SOH at runtime; normalised to \\x01]; header order is 8/9/ not 8/9/35; 9 declared 12 actual 6; 10 declared 031 actual 180" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / FromStringTestWithNoDataDictionary",
    std::string_view{"8=FIX.4.2\001"
      "9=55\001"
      "35=0\001"
      "34=3\001"
      "49=TW\001"
      "52=20000426-12:05:06\001"
      "56=ISLD\001"
      "1=acct123\001"
      "10=123\001", 77},
    true,
    "Heartbeat with account 1=acct123; checksum happens to be correct (123) [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 ok (55); 10 ok (123)" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / ConstructStringFieldOrder",
    std::string_view{"8=FIX.4.2\001"
      "9=31\001"
      "35=A\001"
      "34=42\001"
      "49=SENDER\001"
      "56=TARGET\001"
      "10=200\001", 53},
    true,
    "expected ConstructString() output (header ordering 8/9/35 then 34/49/56) [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 ok (31); 10 ok (200)" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / RepeatedTagDetection",
    std::string_view{"8=FIX.4.2\001"
      "9=72\001"
      "35=0\001"
      "34=3\001"
      "49=TW\001"
      "49=BOGUS\001"
      "52=20000426-12:05:06\001"
      "56=ISLD\001"
      "1=acct123\001"
      "1=bogus\001"
      "10=052\001"
      "10=000\001", 101},
    false,
    "duplicate 49 in header, duplicate 1 in body and duplicate 10 in trailer (10=052 then 10=000); measured to the FIRST 10= both 9=72 and 10=052 are correct, so a parser that stops at the first 10= accepts it and then sees a stray trailing 10=000 [source uses '|' replaced by SOH at runtime; normalised to \\x01]; tag 8 x1, tag 10 x2 (repeated/embedded/concatenated); 9 declared 72 actual 79; 10 declared 000 actual 106" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / RepeatingGroupParseGroupTest",
    std::string_view{"8=FIX.4.4\001"
      "9=309\001"
      "35=8\001"
      "49=ASX\001"
      "56=CL1_FIX44\001"
      "34=4\001"
      "52=20060324-01:05:58\001"
      "17=X-B-WOW-1494E9A0:58BD3F9D-1109\001"
      "150=D\001"
      "39=0\001"
      "11=184271\001"
      "38=200\001"
      "198=1494E9A0:58BD3F9D\001"
      "526=4324\001"
      "37=B-WOW-1494E9A0:58BD3F9D\001"
      "55=WOW\001"
      "54=1\001"
      "151=200\001"
      "14=0\001"
      "40=2\001"
      "44=15\001"
      "59=1\001"
      "6=0\001"
      "453=3\001"
      "448=AAA35791\001"
      "447=D\001"
      "452=3\001"
      "802=1\001"
      "523=OHAI123\001"
      "448=8\001"
      "447=D\001"
      "452=4\001"
      "448=FIX11\001"
      "447=D\001"
      "452=36\001"
      "60=20060320-03:34:29\001"
      "10=169\001", 350},
    false,
    "ExecutionReport with NoPartyIDs group [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 declared 309 actual 327; 10 declared 169 actual 065" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / ReadXmlDataTest",
    std::string_view{"8=FIX.4.2\001"
      "9=495\001"
      "35=n\001"
      "34=31420\001"
      "369=1003\001"
      "52=20200701-20:34:33.978\001"
      "49=CME\001"
      "50=84\001"
      "56=DUMMY11\001"
      "57=SID1\001"
      "143=US,IL\001"
      "212=392\001"
      "213=<RTRF>8=FIX.4.2\001"
      "9=356\001"
      "35=8\001"
      "34=36027\001"
      "369=18623\001"
      "52=20200701-20:34:33.977\001"
      "49=CME\001"
      "50=84\001"
      "56=M2L000N\001"
      "57=DUMMY\001"
      "143=US,IL\001"
      "1=00331\001"
      "6=0\001"
      "11=ACP1593635673935\001"
      "14=0\001"
      "17=84618:1342652\001"
      "20=0\001"
      "37=84778833500\001"
      "38=10\001"
      "39=0\001"
      "40=2\001"
      "41=0\001"
      "44=139.203125\001"
      "48=204527\001"
      "54=1\001"
      "55=ZN\001"
      "59=0\001"
      "60=20200701-20:34:33.976\001"
      "107=ZNH1\001"
      "150=0\001"
      "151=10\001"
      "167=FUT\001"
      "432=20200701\001"
      "1028=Y\001"
      "1031=Y\001"
      "5979=1593635673976364291\001"
      "9717=ACP1593635673935\001"
      "10=124\001"
      "</RTRF>\001"
      "10=028\001", 518},
    true,
    "XmlData 213 (length 212=392) whose value embeds a complete FIX message with its own SOHs, 9= and 10=; correct only if the 212 length prefix is honoured [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 ok (495); 10 ok (028); 212=392 lands on SOH; with 213 treated as opaque data the framing is valid; naive SOH split sees a second 10= inside 213" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / GetInvalidMsgTypeTest",
    std::string_view{"8=FIX.4.4\001"
      "9=68\001"
      "34=3\001"
      "49=sender\001"
      "52=20110909-09:09:09.999\001"
      "56=target\001"
      "55=sym\001"
      "268=0\001"
      "10=9\001", 83},
    false,
    "missing 35 entirely (9 followed by 34) [source uses '|' replaced by SOH at runtime; normalised to \\x01]; header order is 8/9/34 not 8/9/35; 9 declared 68 actual 63; 10 declared 9 actual 057" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / IsAdmin_IsApp",
    std::string_view{"8=FIX4.2\001"
      "9=5\001"
      "35=B\001"
      "10=133\001", 25},
    true,
    "newsStr: BeginString 'FIX4.2' without dot (framing otherwise correct; BeginString value not checked by wire_valid) [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 ok (5); 10 ok (133)" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / TripleNestedGroups_Issue95",
    std::string_view{"8=FIX.4.4\001"
      "9=999\001"
      "35=R\001"
      "34=6\001"
      "49=sendercompid\001"
      "52=20130225-10:44:59.149\001"
      "56=targetcompid\001"
      "131=quotereqid\001"
      "146=1\001"
      "55=ABC\001"
      "65=CD\001"
      "48=securityid\001"
      "22=1\001"
      "711=1\001"
      "311=underlyingsymbol\001"
      "312=WI\001"
      "309=underlyingsecurityid\001"
      "305=1\001"
      "10=999\001", 208},
    false,
    "triple-nested repeating groups (QuoteRequest) with placeholder 9=999 [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 declared 999 actual 185; 10 declared 999 actual 079" },
  { "quickfixn/UnitTests/MessageTests.cs / MessageTests / ConstructStringTest",
    std::string_view{"8=FIX.4.4\001"
      "9=43\001"
      "35=B\001"
      "148=myHeadline\001"
      "33=2\001"
      "58=line1\001"
      "58=line2\001"
      "10=161\001", 65},
    true,
    "expected ConstructString() of News with 33 LinesOfText group [source uses '|' replaced by SOH at runtime; normalised to \\x01]; 9 ok (43); 10 ok (161)" }
};
} // namespace qfjn_vectors
