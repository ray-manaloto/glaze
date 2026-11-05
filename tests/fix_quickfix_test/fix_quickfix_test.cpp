// Glaze Library
// For the license information refer to glaze.hpp
//
// Tests ported from QuickFIX (https://github.com/quickfix/quickfix, src/C++/test/, commit
// 386ce46e917ae494ab6e90b1be90fd421cdbe3f9). The message vectors and test intent come from
// QuickFIX; the test code is rewritten against the glaze FIX API contract.
//
// This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/).
// See QUICKFIX_LICENSE in this directory.
//
// Every test names its source as  "<QuickFIX file> / <TEST_CASE> / <SECTION>".
//
// Struct-mapping tests (field conversion, read/write of typed messages, repeating groups) are
// compiled only when the FIX core defines GLZ_FIX_STRUCT_MAPPING. Without it they are reported
// as SKIPPED with a reason, so the suite still builds against the low-level contract alone.

#include <cstdio>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;
using namespace std::string_view_literals;

namespace
{
   int skipped_count = 0;

   void skip(const char* name, const char* reason)
   {
      ++skipped_count;
      std::printf("SKIPPED: %s -- %s\n", name, reason);
   }

   // Build a complete message from "8=...|35=...|body" style input: replaces '|' with SOH and
   // fills in a correct 9 and 10. `begin` is the BeginString value, `rest` starts at tag 35.
   std::string make_msg(std::string_view begin, std::string_view rest)
   {
      std::string body{rest};
      for (auto& c : body) {
         if (c == '|') c = '\x01';
      }
      std::string out = "8=";
      out += begin;
      out += '\x01';
      out += "9=";
      out += std::to_string(body.size());
      out += '\x01';
      out += body;
      const auto cs = glz::fix::checksum(out);
      char buf[8];
      std::snprintf(buf, sizeof(buf), "%03u", unsigned(cs));
      out += "10=";
      out += buf;
      out += '\x01';
      return out;
   }

   bool is_valid(std::string_view msg) { return !glz::fix::validate(msg); }
}

// ---------------------------------------------------------------------------------------------
// MessagesTestCase.cpp / MessageTests / setString  (and checkSum, noEndingDelim, ...)
// ---------------------------------------------------------------------------------------------

namespace qf_vectors
{
   // MessagesTestCase.cpp / MessageTests / setString
   constexpr std::string_view strGood = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                        "52=20000426-12:05:06\00156=ISLD\00110=218\001";
   // 68 bytes, contains an embedded NUL inside the value of 56.
   constexpr std::string_view strNull{"8=FIX.4.2\0019=46\00135=0\00134=3\00149=TW\001"
                                      "52=20000426-12:05:06\00156=ISLD\000\00110=219\001",
                                      68};
   constexpr std::string_view strTrailingCharacter = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                                     "52=20000426-12:05:06\00156=ISLD\00110=218\001 ";
   constexpr std::string_view strNoChk = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                         "52=20000426-12:05:06\00156=ISLD\001";
   constexpr std::string_view strBadChk = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                          "52=20000426-12:05:06\00156=ISLD\00110=000\001";
   constexpr std::string_view strBad = "8=FIX.4.2\0019=45\00135=0\00134=3\001"
                                       "49garbled=TW\00152=20000426-12:05:06\00156=ISLD\00110=000\001";
   constexpr std::string_view strBadHeaderOrder = "8=FIX.4.2\00135=0\0019=45\00134=3\00149=TW\001"
                                                  "52=20000426-12:05:06\00156=ISLD\00110=218\001";
   constexpr std::string_view strBodyFields = "8=FIX.4.2\0019=60\00135=D\00111=ORDERID\00121=3\00140=2\001"
                                              "54=1\00155=MSFT\00160=19000101-00:00:00\00110=226\001";
   constexpr std::string_view strNoLengthAndChk = "8=FIX.4.2\00135=0\00134=3\00149=TW\001"
                                                  "52=20000426-12:05:06\00156=ISLD\001";
   constexpr std::string_view strBadLength = "8=FIX.4.2\0019=AB\00135=0\00134=3\00149=TW\001"
                                             "52=20000426-12:05:06\00156=ISLD\00110=218\001";
   constexpr std::string_view strBadChecksum = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                               "52=20000426-12:05:06\00156=ISLD\00110=ABC\001";
   constexpr std::string_view strJunk = "paste your FIX message here, then hit ENTER";
   constexpr std::string_view strEmpty = "";

   // MessagesTestCase.cpp / MessageTests / noEndingDelim
   constexpr std::string_view noEndingDelim = "8=FIX.4.2\0019=45\00135=0\00134=3\00149=TW\001"
                                              "52=20000426-12:05:06\00156=ISLD\00110=218";

   // MessagesTestCase.cpp / MessageTests / setStringWithGroup (FIX 4.3 List, 73=NoOrders)
   constexpr std::string_view withGroup =
      "8=FIX.4.3\0019=199\00135=E\00134=126\00149=BUYSIDE\00150=00303\00152"
      "=20040916-16:19:18.328\00156=SELLSIDE\00166=1095350459\00168=2\00173=2\00111"
      "=1095350459\00167=1\0011=00303\00155=fred\00154=1\00140=1\00159=3\00111=1095"
      "350460\00167=2\0011=00303\00155=fred\00154=1\00140=1\00159=3\001394=3\00110="
      "138\001";
   // MessagesTestCase.cpp / MessageTests / setStringWithGroupWithoutDelimiter
   constexpr std::string_view withGroupNoDelim =
      "8=FIX.4.3\0019=171\00135=E\00134=126\00149=BUYSIDE\00150=00303\00152"
      "=20040916-16:19:18.328\00156=SELLSIDE\00166=1095350459\00168=2\00173=2\001"
      "67=1\0011=00303\00155=fred\00154=1\00140=1\00159=3\001"
      "67=2\0011=00303\00155=fred\00154=1\00140=1\00159=3\001394=3\00110="
      "054\001";
   // MessagesTestCase.cpp / MessageTests / setStringWithHeaderGroup (627=NoHops)
   constexpr std::string_view withHeaderGroup43 = "8=FIX.4.3\0019=152\00135=A\00134=125\00149=BUYSIDE\001"
                                                  "52=20040916-16:19:18.328\00156=SELLSIDE\001"
                                                  "627=2\001628=HOP1\001629=20040916-16:19:18.328\001630=ID1\001"
                                                  "628=HOP2\001629=20040916-16:19:18.328\001630=ID2\001"
                                                  "10=079\001";
   // MessagesTestCase.cpp / MessageTests / setStringWithHeaderGroupDefinedInComponent
   constexpr std::string_view withHeaderGroup44 = "8=FIX.4.4\0019=152\00135=A\00134=125\00149=BUYSIDE\001"
                                                  "52=20040916-16:19:18.328\00156=SELLSIDE\001"
                                                  "627=2\001628=HOP1\001629=20040916-16:19:18.328\001630=ID1\001"
                                                  "628=HOP2\001629=20040916-16:19:18.328\001630=ID2\001"
                                                  "10=080\001";

   // MessagesTestCase.cpp / MessageTests / outOfOrder (expected output)
   constexpr std::string_view outOfOrderExpected =
      "8=FIX.4.2\0019=171\00135=8\00134=2\00149=MEK\00156=KEM\0011=acct1\001"
      "6=109.03125\00111=ID1\00114=3000\00115=USD\00117=2\00120=0\00122=1\001"
      "31=109.03125\00137=1\00138=3000\00139=2\00148=123ABC789\001"
      "54=1\00155=ABCD\00160=00000000-00:00:00\001150=2\001151=0\00110=225\001";

   // MessagesTestCase.cpp / MessageTests / <type>GetString / <type>SetString (FIX 4.2)
   constexpr std::string_view logon = "8=FIX.4.2\0019=12\00135=A\001108=30\00110=026\001";
   constexpr std::string_view testRequest = "8=FIX.4.2\0019=12\00135=1\001112=23\00110=007\001";
   constexpr std::string_view resendRequest = "8=FIX.4.2\0019=16\00135=2\0017=1\00116=233\00110=184\001";
   constexpr std::string_view reject = "8=FIX.4.2\0019=36\00135=3\00145=73\001"
                                       "58=This Message SUCKS!!!\00110=029\001";
   constexpr std::string_view sequenceReset = "8=FIX.4.2\0019=17\00135=4\00136=88\001123=Y\00110=028\001";
   constexpr std::string_view logout = "8=FIX.4.2\0019=18\00135=5\00158=See Ya...\00110=006\001";
   constexpr std::string_view newOrderSingleGet = "8=FIX.4.2\0019=60\00135=D\00111=ORDERID\00121=3\00140=2\001"
                                                  "54=1\00155=MSFT\00160=19000101-00:00:00\00110=226\001";
   constexpr std::string_view newOrderSingleSet = "8=FIX.4.2\0019=48\00135=D\00111=ORDERID\00121=3\00140=2\001"
                                                  "54=1\00155=MSFT\00160=TODAY\00110=028\001";

   // ParserTestCase.cpp / ParserTests / readFixMessage. NOTE: the 10= values in these
   // vectors are NOT correct checksums (QuickFIX's Parser only frames). Used for framing only.
   constexpr std::string_view parserMsg1 = "8=FIX.4.2\0019=12\00135=A\001108=30\00110=31\001";
   constexpr std::string_view parserMsg2 = "8=FIX.4.2\0019=17\00135=4\00136=88\001123=Y\00110=34\001";
   constexpr std::string_view parserMsg3 = "8=FIX.4.2\0019=19\00135=A\001108=30\0019710=8\00110=31\001";
   constexpr std::string_view parserBadLength = "8=FIX.4.2\0019=200A\00135=A\001108=30\00110=31\001";
   // ParserTestCase.cpp / ParserTests / readMessagesByteByByte (value of 365 contains SOH bytes)
   constexpr std::string_view parserByteMsg1 = "8=FIX.4.2\0019=54\00135=i\001117=1\001296=1\001302=A\001"
                                               "311=DELL\001364=10\001365=DELL\001COMP\001\00110=152\001";
   // ParserTestCase.cpp / ParserTests / readMessageWithBadLength
   constexpr std::string_view parserTestBadLength =
      "8=TEST\0019=TEST\00135=TEST\00149=SS1\00156=RORE\00134=3\00152=20050222-16:45:53\00110=TEST\001";
}

using namespace qf_vectors;

suite quickfix_validate = [] {
   "MessagesTestCase.cpp / MessageTests / setString / strGood"_test = [] { expect(is_valid(strGood)); };

   "MessagesTestCase.cpp / MessageTests / setString / strNull (embedded NUL in a value)"_test = [] {
      expect(strNull.size() == 68u);
      expect(is_valid(strNull));
   };

   "MessagesTestCase.cpp / MessageTests / setString / strTrailingCharacter"_test = [] {
      expect(not is_valid(strTrailingCharacter));
   };
   "MessagesTestCase.cpp / MessageTests / setString / strNoChk"_test = [] { expect(not is_valid(strNoChk)); };
   "MessagesTestCase.cpp / MessageTests / setString / strBadChk"_test = [] { expect(not is_valid(strBadChk)); };
   "MessagesTestCase.cpp / MessageTests / setString / strBad (garbled tag)"_test = [] {
      expect(not is_valid(strBad));
      expect(not glz::fix::parse_fields(strBad).has_value());
   };
   "MessagesTestCase.cpp / MessageTests / setString / strBadHeaderOrder"_test = [] {
      expect(not is_valid(strBadHeaderOrder));
   };
   "MessagesTestCase.cpp / MessageTests / setString / strNoLengthAndChk"_test = [] {
      expect(not is_valid(strNoLengthAndChk));
   };
   "MessagesTestCase.cpp / MessageTests / setString / strBadLength"_test = [] { expect(not is_valid(strBadLength)); };
   "MessagesTestCase.cpp / MessageTests / setString / strBadChecksum (non-numeric)"_test = [] {
      expect(not is_valid(strBadChecksum));
   };
   "MessagesTestCase.cpp / MessageTests / setString / strJunk"_test = [] { expect(not is_valid(strJunk)); };
   "MessagesTestCase.cpp / MessageTests / setString / strEmpty"_test = [] { expect(not is_valid(strEmpty)); };
   "MessagesTestCase.cpp / MessageTests / setString / strBodyFields"_test = [] { expect(is_valid(strBodyFields)); };

   "MessagesTestCase.cpp / MessageTests / noEndingDelim"_test = [] {
      expect(not is_valid(noEndingDelim));
      expect(not glz::fix::parse_fields(noEndingDelim).has_value());
   };

   "MessagesTestCase.cpp / MessageTests / setStringWithGroup (wire-valid)"_test = [] {
      expect(is_valid(withGroup));
      expect(is_valid(withGroupNoDelim));
      expect(is_valid(withHeaderGroup43));
      expect(is_valid(withHeaderGroup44));
   };

   "MessagesTestCase.cpp / MessageTests / outOfOrder (expected output is wire-valid)"_test = [] {
      expect(is_valid(outOfOrderExpected));
   };

   "MessagesTestCase.cpp / MessageTests / <admin and app message>GetString vectors are wire-valid"_test = [] {
      for (auto m : {logon, testRequest, resendRequest, reject, sequenceReset, logout, newOrderSingleGet,
                     newOrderSingleSet}) {
         expect(is_valid(m));
      }
   };

   // MessagesTestCase.cpp / MessageTests / setString_TrailerStructureInvalid_MessageStructureInvalid
   "MessagesTestCase.cpp / MessageTests / setString_TrailerStructureInvalid (10 inside body)"_test = [] {
      const std::string raw = "8=FIX.4.2\0019=200\00135=A\00149=SENDER\00156=TARGET\00134=1\00198=0\001"
                              "10=200\001108=30\00110=200\001";
      expect(not is_valid(raw));
      // Same shape with correct 9 and 10 for the outer message: still rejected because a
      // CheckSum appears before the end.
      const auto fixed = make_msg("FIX.4.2", "35=A|49=SENDER|56=TARGET|34=1|98=0|10=200|108=30|");
      expect(not is_valid(fixed));
   };

   // MessagesTestCase.cpp / MessageTests / setStringAndValidate_IncorrectBodyLength_InvalidException
   "MessagesTestCase.cpp / MessageTests / setStringAndValidate_IncorrectBodyLength"_test = [] {
      const std::string raw = "8=FIX.4.2\0019=2000\00135=A\00149=SENDER\00156=TARGET\00134=1\00198=0\001"
                              "108=30\00110=200\001";
      expect(not is_valid(raw));
   };

   // Derived from setString / strBadHeaderOrder: each of 8, 9, 35 must be in position.
   "MessagesTestCase.cpp / MessageTests / setString / header order permutations"_test = [] {
      const auto good = make_msg("FIX.4.2", "35=0|34=3|49=TW|");
      expect(is_valid(good));
      // 35 before 9 (strBadHeaderOrder)
      expect(not is_valid("8=FIX.4.2\00135=0\0019=11\00134=3\00149=TW\00110=000\001"));
      // 9 first
      expect(not is_valid("9=11\0018=FIX.4.2\00135=0\00134=3\00149=TW\00110=000\001"));
      // 35 not third
      const auto late35 = make_msg("FIX.4.2", "34=3|35=0|49=TW|");
      expect(not is_valid(late35));
   };
};

// ---------------------------------------------------------------------------------------------
// MessagesTestCase.cpp / MessageTests / checkSum
// ---------------------------------------------------------------------------------------------

suite quickfix_checksum = [] {
   "MessagesTestCase.cpp / MessageTests / checkSum"_test = [] {
      const std::string_view str1 = "8=FIX.4.2\0019=46\00135=0\00134=3\00149=TW\001"
                                    "52=20000426-12:05:06\00156=ISLD\001";
      int sum = 0;
      for (char c : str1) sum += static_cast<unsigned char>(c);
      expect(glz::fix::checksum(str1) == uint8_t(sum % 256));
   };

   // Declared 10= values of every QuickFIX vector that carries a correct checksum.
   "MessagesTestCase.cpp / MessageTests / checkSum of ported vectors"_test = [] {
      auto check = [](std::string_view m, unsigned expected_cs) {
         const auto t = m.rfind("10=");
         expect(t != std::string_view::npos);
         expect(glz::fix::checksum(m.substr(0, t)) == expected_cs) << m;
      };
      check(strGood, 218);
      check(strNull, 219);
      check(strBodyFields, 226);
      check(withGroup, 138);
      check(withGroupNoDelim, 54);
      check(withHeaderGroup43, 79);
      check(withHeaderGroup44, 80);
      check(logon, 26);
      check(testRequest, 7);
      check(resendRequest, 184);
      check(reject, 29);
      check(sequenceReset, 28);
      check(logout, 6);
      check(newOrderSingleSet, 28);
      check(outOfOrderExpected, 225);
      check(parserByteMsg1, 152);
   };

   "checksum: high-bit bytes are summed as unsigned (MessagesTestCase.cpp / setStringWithHighBit)"_test = [] {
      // QuickFIX fills RawData with char(-92) == 0xA4.
      const std::string s(3, char(-92));
      expect(glz::fix::checksum(s) == uint8_t((3 * 0xA4) % 256));
      expect(glz::fix::checksum("") == 0);
   };
};

// ---------------------------------------------------------------------------------------------
// ParserTestCase.cpp / ParserTests  -> glz::fix::frame
// ---------------------------------------------------------------------------------------------

suite quickfix_parser = [] {
   "ParserTestCase.cpp / ParserTests / extractLength"_test = [] {
      // normalLength frames; badLength / negativeLength / incomplete do not.
      expect(glz::fix::frame("8=FIX.4.2\0019=12\00135=A\001108=30\00110=31\001") == 33u);
      expect(glz::fix::frame("8=FIX.4.2\0019=A\00135=A\001108=30\00110=31\001") == 0u);
      expect(glz::fix::frame("8=FIX.4.2\0019=-1\00135=A\001108=30\00110=31\001") == 0u);
      expect(glz::fix::frame("8=FIX.4.2") == 0u);
      expect(glz::fix::frame("8=FIX.4.2\0019=12") == 0u);
      expect(glz::fix::frame("") == 0u);
   };

   "ParserTestCase.cpp / ParserTests / readFixMessage"_test = [] {
      std::string stream;
      stream += parserMsg1;
      stream += parserMsg2;
      stream += parserMsg3;
      stream += parserBadLength;
      std::string_view s = stream;

      auto n = glz::fix::frame(s);
      expect(s.substr(0, n) == parserMsg1);
      s.remove_prefix(n);
      n = glz::fix::frame(s);
      expect(s.substr(0, n) == parserMsg2);
      s.remove_prefix(n);
      n = glz::fix::frame(s);
      expect(s.substr(0, n) == parserMsg3);
      s.remove_prefix(n);
      // QuickFIX throws MessageParseError here; the contract returns 0 (no complete message),
      // and validate() must reject it.
      expect(glz::fix::frame(s) == 0u);
      expect(not is_valid(s));
   };

   "ParserTestCase.cpp / ParserTests / readPartialFixMessage"_test = [] {
      constexpr std::string_view part1 = "8=FIX.4.2\0019=17\00135=4\00136=";
      constexpr std::string_view part2 = "88\001123=Y\00110=34\001";
      expect(glz::fix::frame(part1) == 0u);
      std::string whole{part1};
      whole += part2;
      expect(glz::fix::frame(whole) == whole.size());
   };

   "ParserTestCase.cpp / ParserTests / readMessagesByteByByte"_test = [] {
      std::string stream;
      stream += parserByteMsg1;
      stream += parserMsg2;
      stream += parserMsg3;
      // Feeding one byte at a time: no frame until the first message is complete.
      for (size_t i = 0; i < parserByteMsg1.size(); ++i) {
         expect(glz::fix::frame(std::string_view{stream}.substr(0, i)) == 0u);
      }
      // Framing must use BodyLength, not stop at the SOH bytes inside the value of 365.
      expect(glz::fix::frame(stream) == parserByteMsg1.size());
      expect(glz::fix::frame(parserByteMsg1) == parserByteMsg1.size());
   };

   "ParserTestCase.cpp / ParserTests / readMessageWithBadLength"_test = [] {
      expect(glz::fix::frame(parserTestBadLength) == 0u);
      expect(not is_valid(parserTestBadLength));
   };
};

// ---------------------------------------------------------------------------------------------
// parse_fields: field order and values, from MessagesTestCase.cpp vectors
// ---------------------------------------------------------------------------------------------

suite quickfix_parse_fields = [] {
   "MessagesTestCase.cpp / MessageTests / setString / strGood fields"_test = [] {
      auto f = glz::fix::parse_fields(strGood);
      expect(f.has_value());
      if (!f) return;
      const std::vector<std::pair<uint32_t, std::string_view>> want{
         {8, "FIX.4.2"}, {9, "45"}, {35, "0"}, {34, "3"}, {49, "TW"}, {52, "20000426-12:05:06"}, {56, "ISLD"},
         {10, "218"}};
      expect(f->size() == want.size());
      for (size_t i = 0; i < want.size() && i < f->size(); ++i) {
         expect((*f)[i].tag == want[i].first);
         expect((*f)[i].value == want[i].second);
      }
   };

   "MessagesTestCase.cpp / MessageTests / setString / strNull keeps the NUL byte"_test = [] {
      auto f = glz::fix::parse_fields(strNull);
      expect(f.has_value());
      if (!f) return;
      expect(f->size() == 8u);
      if (f->size() == 8u) expect((*f)[6].value == std::string_view{"ISLD\0", 5});
   };

   "MessagesTestCase.cpp / MessageTests / rejectSetString (spaces and '!' in value)"_test = [] {
      auto f = glz::fix::parse_fields(reject);
      expect(f.has_value());
      if (!f) return;
      expect(f->size() == 6u);
      if (f->size() == 6u) {
         expect((*f)[3].tag == 45u and (*f)[3].value == "73");
         expect((*f)[4].tag == 58u and (*f)[4].value == "This Message SUCKS!!!");
      }
   };

   "MessagesTestCase.cpp / MessageTests / setStringWithGroup repeated tags preserved in order"_test = [] {
      auto f = glz::fix::parse_fields(withGroupNoDelim);
      expect(f.has_value());
      if (!f) return;
      std::vector<std::string_view> group_67;
      for (auto& x : *f) {
         if (x.tag == 67) group_67.push_back(x.value);
      }
      expect(group_67.size() == 2u);
      if (group_67.size() == 2u) {
         expect(group_67[0] == "1");
         expect(group_67[1] == "2");
      }
   };

   "parse_fields with '|' delimiter (readability form of logonGetString)"_test = [] {
      auto f = glz::fix::parse_fields("8=FIX.4.2|9=12|35=A|108=30|10=026|", '|');
      expect(f.has_value());
      if (f) expect(f->size() == 5u);
   };

   "parse_fields rejects malformed tags (MessagesTestCase.cpp / setString / strBad)"_test = [] {
      expect(not glz::fix::parse_fields("49garbled=TW\001").has_value());
      expect(not glz::fix::parse_fields("=TW\001").has_value());
      expect(not glz::fix::parse_fields("abc=TW\001").has_value());
      expect(not glz::fix::parse_fields("-1=TW\001").has_value());
      expect(not glz::fix::parse_fields("49TW\001").has_value());
      expect(glz::fix::parse_fields("").has_value());
   };
};

// ---------------------------------------------------------------------------------------------
// Struct mapping: field conversion, typed read/write, repeating groups.
// ---------------------------------------------------------------------------------------------

#if defined(GLZ_FIX_STRUCT_MAPPING)
#include "fix_quickfix_struct_tests.inl"
#else
suite quickfix_struct_mapping_skipped = [] {
   constexpr const char* why = "FIX core does not define GLZ_FIX_STRUCT_MAPPING (glz::read/write<fix_opts> not available)";
   skip("FieldConvertorsTestCase.cpp / int8,int16,uint32,int,uint64 ConvertTo/ConvertFrom", why);
   skip("FieldConvertorsTestCase.cpp / doubleConvertTo / doubleConvertFrom", why);
   skip("FieldConvertorsTestCase.cpp / charConvertTo / charConvertFrom", why);
   skip("FieldConvertorsTestCase.cpp / booleanConvertTo / booleanConvertFrom", why);
   skip("MessagesTestCase.cpp / <admin message>GetString / SetString (typed)", why);
   skip("MessagesTestCase.cpp / newOrderSingleGetString / SetString (typed)", why);
   skip("MessagesTestCase.cpp / setStringWithGroup / WithoutDelimiter / HeaderGroup (typed groups)", why);
   skip("MessagesTestCase.cpp / setString with validate_checksum=false / validate_body_length=false", why);
};
#endif

// Contract does not define UTCTimestamp / UTCDateOnly / UTCTimeOnly types yet.
suite quickfix_time_skipped = [] {
   constexpr const char* why = "contract defines no UTCTimestamp/UTCDateOnly/UTCTimeOnly C++ type; see docs/fix/sessions/fix-tests-quickfix.md";
   skip("FieldConvertorsTestCase.cpp / utcTimeStampConvertTo{Second,Milli,Micro,Nano,PrecisionBounds}", why);
   skip("FieldConvertorsTestCase.cpp / utcTimeStampConvertFrom{Second,Milli,Micro,Nano}", why);
   skip("FieldConvertorsTestCase.cpp / utcTimeOnlyConvertTo* / utcTimeOnlyConvertFrom*", why);
   skip("FieldConvertorsTestCase.cpp / utcDateConvertTo / utcDateConvertFrom", why);
   skip("UtcTimeStampTestCase.cpp / UtcTimeOnlyTestCase.cpp", why);
};

int main()
{
   // ut runs the suites and reports failures on exit.
   std::printf("fix_quickfix_test: %d test group(s) skipped\n", skipped_count);
   return 0;
}
