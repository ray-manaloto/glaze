// Glaze Library
// For the license information refer to glaze.hpp
//
// More cases ported from QuickFIX/J (quickfixj-core/src/test/java/quickfix/...) and QuickFIX/n
// (UnitTests/...). This product includes software developed by quickfixengine.org
// (http://www.quickfixengine.org/). Licences: QUICKFIXJ_LICENSE, QUICKFIXN_LICENSE.
// Where the original message has a wrong 9 or 10 (many do: QuickFIX's decoders only frame), the
// body is kept and make_msg() recomputes 9 and 10; this is stated per test.

namespace qf_more
{
   // QFJ MessageTest.testParsing / testHeaderGroupParsing: Logon with NoMsgTypes(384) and NoHops(627)
   struct MsgTypeEntry
   {
      std::string ref_msg_type; // 372
      char msg_direction{}; // 385
   };
   struct HopName
   {
      std::string hop_comp_id; // 628
   };
   struct LogonGroups
   {
      std::vector<HopName> hops; // 627
      int32_t encrypt_method{-1}; // 98
      std::vector<MsgTypeEntry> msg_types; // 384
   };

   // QFJ MessageTest.testParsing2: IOI with NoUnderlyings(711)
   struct Underlying
   {
      std::string underlying_symbol; // 311
      std::string underlying_currency; // 318
   };
   struct Ioi
   {
      std::string ioi_id; // 23
      char ioi_trans_type{}; // 28
      std::string symbol; // 55
      char side{}; // 54
      std::vector<Underlying> underlyings; // 711
   };

   // QFN MessageTests.ConstructStringTest: News with LinesOfText(33)
   struct TextLine
   {
      std::string text; // 58
   };
   struct News44
   {
      std::string headline; // 148
      std::vector<TextLine> lines; // 33
   };

   // QFJ MessageTest.testNestedRepeatingGroup: Parties(453) with nested PartySubIDs(802)
   struct PartySub
   {
      std::string party_sub_id; // 523
      int32_t party_sub_id_type{}; // 803
   };
   struct Party
   {
      std::string party_id; // 448
      char party_id_source{}; // 447
      int32_t party_role{}; // 452
      std::vector<PartySub> subs; // 802
   };
   struct OrderWithParties
   {
      std::string cl_ord_id; // 11
      std::vector<Party> parties; // 453
      std::string symbol; // 55
   };

   // QFJ RepeatingGroupTest.testWrongGroupCount: MassQuote NoQuoteSets(296) / NoQuoteEntries(295)
   struct QuoteEntry
   {
      std::string quote_entry_id; // 299
   };
   struct QuoteSet
   {
      std::string quote_set_id; // 302
      int32_t tot_no_quote_entries{}; // 304
      std::vector<QuoteEntry> entries; // 295
   };
   struct MassQuote
   {
      std::string quote_id; // 117
      std::vector<QuoteSet> sets; // 296
   };

   // QFN MessageTests.TripleNestedGroups_Issue95: QuoteRequest NoRelatedSym(146) / NoUnderlyings(711) / NoUnderlyingStips(887)
   struct UnderlyingStip
   {
      std::string type; // 888
      std::string value; // 889
   };
   struct RelUnderlying
   {
      std::string underlying_symbol; // 311
      std::string underlying_symbol_sfx; // 312
      std::vector<UnderlyingStip> stips; // 887
   };
   struct RelatedSym
   {
      std::string symbol; // 55
      std::string symbol_sfx; // 65
      std::vector<RelUnderlying> underlyings; // 711
      int32_t qty_type{}; // 854
   };
   struct QuoteRequest
   {
      std::string quote_req_id; // 131
      std::vector<RelatedSym> related; // 146
   };

   // QFJ MessageTest.testFieldWithEqualsCharacter: MarketDataSnapshot with SecurityAltID-like 461
   struct MdEntry
   {
      char md_entry_type{}; // 269
      double md_entry_px{}; // 270
      double md_entry_size{}; // 271
   };
   struct MdSnapshot
   {
      std::string md_req_id; // 262
      std::string symbol; // 55
      std::string cfi_code; // 461
      std::vector<MdEntry> entries; // 268
   };

   // QFJ MessageTest.testFirstFieldInGroupIsDelimiter: NoLegs(555) delimiter 600
   struct Leg
   {
      std::string leg_symbol; // 600
      std::string leg_security_id; // 602
   };
   struct MultilegOrder
   {
      std::string symbol; // 55
      std::vector<Leg> legs; // 555
   };

   // QFJ MessageUtilsTest.testParse / testParseMessageWithoutChecksumValidation (FIX.4.0 Logon)
   struct Logon40
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sending_time; // 52
      std::string target_comp_id; // 56
      int32_t encrypt_method{-1}; // 98
      int32_t heart_bt_int{}; // 108
   };

   // QFJ MessageTest.testMessageBytesField: RawDataLength(95) / RawData(96) without SOH in the data
   struct LogonRaw
   {
      int32_t raw_data_length{}; // 95
      std::string raw_data; // 96
   };

   // QFN MessageTests.RepeatedTagDetection / FromStringTestWithNoDataDictionary: Heartbeat with Account(1)
   struct HeartbeatAcct
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sending_time; // 52
      std::string target_comp_id; // 56
      std::string account; // 1
   };
}

#define QF_META(TYPE, MSGTYPE, ...)                                                                \
   template <>                                                                                     \
   struct glz::meta<qf_more::TYPE>                                                                 \
   {                                                                                               \
      using T = qf_more::TYPE;                                                                     \
      MSGTYPE static constexpr auto value = glz::object(__VA_ARGS__);                              \
   };
#define QF_TYPE(x) static constexpr auto fix_msg_type = x;
#define QF_GROUP

QF_META(MsgTypeEntry, QF_GROUP, "372", &T::ref_msg_type, "385", &T::msg_direction)
QF_META(HopName, QF_GROUP, "628", &T::hop_comp_id)
QF_META(LogonGroups, QF_TYPE("A"), "627", &T::hops, "98", &T::encrypt_method, "384", &T::msg_types)
QF_META(Underlying, QF_GROUP, "311", &T::underlying_symbol, "318", &T::underlying_currency)
QF_META(Ioi, QF_TYPE("6"), "23", &T::ioi_id, "28", &T::ioi_trans_type, "55", &T::symbol, "54", &T::side, "711",
        &T::underlyings)
QF_META(TextLine, QF_GROUP, "58", &T::text)
QF_META(PartySub, QF_GROUP, "523", &T::party_sub_id, "803", &T::party_sub_id_type)
QF_META(Party, QF_GROUP, "448", &T::party_id, "447", &T::party_id_source, "452", &T::party_role, "802", &T::subs)
QF_META(OrderWithParties, QF_TYPE("D"), "11", &T::cl_ord_id, "453", &T::parties, "55", &T::symbol)
QF_META(QuoteEntry, QF_GROUP, "299", &T::quote_entry_id)
QF_META(QuoteSet, QF_GROUP, "302", &T::quote_set_id, "304", &T::tot_no_quote_entries, "295", &T::entries)
QF_META(MassQuote, QF_TYPE("i"), "117", &T::quote_id, "296", &T::sets)
QF_META(UnderlyingStip, QF_GROUP, "888", &T::type, "889", &T::value)
QF_META(RelUnderlying, QF_GROUP, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "887", &T::stips)
QF_META(RelatedSym, QF_GROUP, "55", &T::symbol, "65", &T::symbol_sfx, "711", &T::underlyings, "854", &T::qty_type)
QF_META(QuoteRequest, QF_TYPE("R"), "131", &T::quote_req_id, "146", &T::related)
QF_META(MdEntry, QF_GROUP, "269", &T::md_entry_type, "270", &T::md_entry_px, "271", &T::md_entry_size)
QF_META(MdSnapshot, QF_TYPE("W"), "262", &T::md_req_id, "55", &T::symbol, "461", &T::cfi_code, "268", &T::entries)
QF_META(Leg, QF_GROUP, "600", &T::leg_symbol, "602", &T::leg_security_id)
QF_META(MultilegOrder, QF_TYPE("AB"), "55", &T::symbol, "555", &T::legs)
QF_META(Logon40, QF_TYPE("A"), "34", &T::msg_seq_num, "49", &T::sender_comp_id, "52", &T::sending_time, "56",
        &T::target_comp_id, "98", &T::encrypt_method, "108", &T::heart_bt_int)
QF_META(LogonRaw, QF_TYPE("A"), "95", &T::raw_data_length, "96", &T::raw_data)
QF_META(HeartbeatAcct, QF_TYPE("0"), "34", &T::msg_seq_num, "49", &T::sender_comp_id, "52", &T::sending_time, "56",
        &T::target_comp_id, "1", &T::account)

#undef QF_META
#undef QF_TYPE
#undef QF_GROUP

template <>
struct glz::meta<qf_more::News44>
{
   using T = qf_more::News44;
   static constexpr auto fix_msg_type = "B";
   static constexpr auto fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("148", &T::headline, "33", &T::lines);
};

suite quickfixj_quickfixn_typed = [] {
   using namespace qf_more;

   "quickfixj MessageTest.java / testParsing (Logon with NoMsgTypes 384)"_test = [] {
      // Original has the right checksum written as 2 digits (10=96): rejected as is, read after
      // make_msg() rewrites it as 3 digits.
      expect(not is_valid("8=FIX.4.2\0019=40\00135=A\00198=0\001384=2\001372=D\001385=R\001372=8\001385=S\00110=96\001"));
      const auto msg = make_msg("FIX.4.2", "35=A|98=0|384=2|372=D|385=R|372=8|385=S|");
      LogonGroups m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.encrypt_method == 0);
      expect(m.msg_types.size() == 2u);
      if (m.msg_types.size() == 2u) {
         expect(m.msg_types[0].ref_msg_type == "D" and m.msg_types[0].msg_direction == 'R');
         expect(m.msg_types[1].ref_msg_type == "8" and m.msg_types[1].msg_direction == 'S');
      }
   };

   "quickfixj MessageTest.java / testHeaderGroupParsing (627 then body group 384)"_test = [] {
      // Original declares 9=40 for a 45-byte body; 9 and 10 recomputed.
      const auto msg = make_msg("FIX.4.2", "35=A|627=2|628=FOO|628=BAR|98=0|384=2|372=D|385=R|372=8|385=S|");
      LogonGroups m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.hops.size() == 2u);
      if (m.hops.size() == 2u) {
         expect(m.hops[0].hop_comp_id == "FOO");
         expect(m.hops[1].hop_comp_id == "BAR");
      }
      // 98 follows the group but belongs to the parent.
      expect(m.encrypt_method == 0);
      expect(m.msg_types.size() == 2u);
   };

   "quickfixj MessageTest.java / testParsing2 (IOI with NoUnderlyings 711, verbatim)"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.2\0019=76\00135=6\00123=IDENTIFIER\00128=N\00155=MSFT\00154=1\001"
                                       "711=2\001311=DELL\001318=USD\001311=IBM\001318=CAD\00110=037\001";
      expect(is_valid(msg));
      Ioi m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.ioi_id == "IDENTIFIER");
      expect(m.ioi_trans_type == 'N');
      expect(m.symbol == "MSFT");
      expect(m.side == '1');
      expect(m.underlyings.size() == 2u);
      if (m.underlyings.size() == 2u) {
         expect(m.underlyings[0].underlying_symbol == "DELL" and m.underlyings[0].underlying_currency == "USD");
         expect(m.underlyings[1].underlying_symbol == "IBM" and m.underlyings[1].underlying_currency == "CAD");
      }
   };

   "quickfixn MessageTests.cs / ConstructStringTest (News with LinesOfText 33, exact write)"_test = [] {
      constexpr std::string_view expected = "8=FIX.4.4\0019=43\00135=B\001148=myHeadline\00133=2\00158=line1\00158=line2\001"
                                            "10=161\001";
      News44 n{"myHeadline", {{"line1"}, {"line2"}}};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(n, buf));
      expect(buf == expected) << buf;
      News44 back{};
      expect(not glz::read<glz::fix_opts{}>(back, expected));
      expect(back.headline == "myHeadline");
      expect(back.lines.size() == 2u);
      if (back.lines.size() == 2u) expect(back.lines[1].text == "line2");
   };

   "quickfixj MessageTest.java / testNestedRepeatingGroup (453 Parties with nested 802)"_test = [] {
      // Body reduced to the fields under test; 9 and 10 computed.
      const auto msg = make_msg("FIX.4.4", "35=D|11=16H03A0000021|453=1|448=test|447=D|452=4|802=2|523=sub1|803=2|"
                                           "523=sub2|803=3|55=[N/A]|");
      OrderWithParties m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.cl_ord_id == "16H03A0000021");
      expect(m.symbol == "[N/A]"); // after both groups: returns to the top level
      expect(m.parties.size() == 1u);
      if (m.parties.size() == 1u) {
         expect(m.parties[0].party_id == "test");
         expect(m.parties[0].party_id_source == 'D');
         expect(m.parties[0].party_role == 4);
         expect(m.parties[0].subs.size() == 2u);
         if (m.parties[0].subs.size() == 2u) {
            expect(m.parties[0].subs[0].party_sub_id == "sub1" and m.parties[0].subs[0].party_sub_id_type == 2);
            expect(m.parties[0].subs[1].party_sub_id == "sub2" and m.parties[0].subs[1].party_sub_id_type == 3);
         }
      }
      // Round trip through write.
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      OrderWithParties again{};
      expect(not glz::read<glz::fix_opts{}>(again, buf));
      expect(again.parties.size() == 1u and again.parties[0].subs.size() == 2u);
   };

   "quickfixj RepeatingGroupTest.java / testWrongGroupCount (295=50 with one entry)"_test = [] {
      // Original uses 9=0 as a placeholder; 9 and 10 computed so only the group count is wrong.
      const auto bad =
         make_msg("FIX.4.4", "35=i|34=2|49=TW|52=20080203-00:29:51.453|56=ISLD|117=ID|296=1|302=X|304=5|295=50|299=QID|");
      MassQuote m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, bad)));
      // Control: the correct count reads.
      const auto good =
         make_msg("FIX.4.4", "35=i|34=2|49=TW|52=20080203-00:29:51.453|56=ISLD|117=ID|296=1|302=X|304=5|295=1|299=QID|");
      MassQuote ok{};
      expect(not glz::read<glz::fix_opts{}>(ok, good));
      expect(ok.sets.size() == 1u);
      if (ok.sets.size() == 1u) {
         expect(ok.sets[0].quote_set_id == "X");
         expect(ok.sets[0].entries.size() == 1u);
      }
   };

   "quickfixn MessageTests.cs / TripleNestedGroups_Issue95"_test = [] {
      // Original uses 9=999 / 10=999 placeholders; body extended with an 887 level, 9 and 10 computed.
      const auto msg = make_msg("FIX.4.4", "35=R|131=quotereqid|146=1|55=ABC|65=CD|711=1|311=underlyingsymbol|312=WI|"
                                           "887=2|888=A|889=1|888=B|889=2|854=1|");
      QuoteRequest m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.quote_req_id == "quotereqid");
      expect(m.related.size() == 1u);
      if (m.related.size() == 1u) {
         const auto& r = m.related[0];
         expect(r.symbol == "ABC" and r.symbol_sfx == "CD");
         expect(r.qty_type == 1); // after the nested groups, back in the 146 entry
         expect(r.underlyings.size() == 1u);
         if (r.underlyings.size() == 1u) {
            expect(r.underlyings[0].underlying_symbol == "underlyingsymbol");
            expect(r.underlyings[0].stips.size() == 2u);
            if (r.underlyings[0].stips.size() == 2u) expect(r.underlyings[0].stips[1].value == "2");
         }
      }
   };

   "quickfixj MessageTest.java / testFieldWithEqualsCharacter (461=RCSXX=0)"_test = [] {
      // Body reduced; original declares a wrong 9. A value may contain '='.
      const auto msg = make_msg("FIXT.1.1", "35=W|262=1319209757316210|55=EUR/USD|461=RCSXX=0|268=2|269=0|270=1.38898|"
                                            "271=2000000|269=1|270=1.38855|271=6000000|");
      auto f = glz::fix::parse_fields(msg);
      expect(f.has_value());
      MdSnapshot m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.cfi_code == "RCSXX=0");
      expect(m.symbol == "EUR/USD");
      expect(m.entries.size() == 2u);
      if (m.entries.size() == 2u) {
         expect(m.entries[0].md_entry_type == '0' and m.entries[0].md_entry_px == 1.38898);
         expect(m.entries[1].md_entry_type == '1' and m.entries[1].md_entry_size == 6000000.0);
      }
   };

   "quickfixj MessageTest.java / testFirstFieldInGroupIsDelimiter (555 entries start with 602)"_test = [] {
      const auto bad = make_msg("FIX.4.4", "35=AB|55=AAPL|555=2|602=111|600=AAA|602=222|600=BBB|");
      MultilegOrder m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, bad)));
      const auto good = make_msg("FIX.4.4", "35=AB|55=AAPL|555=2|600=AAA|602=111|600=BBB|602=222|");
      MultilegOrder ok{};
      expect(not glz::read<glz::fix_opts{}>(ok, good));
      expect(ok.legs.size() == 2u);
      if (ok.legs.size() == 2u) expect(ok.legs[1].leg_security_id == "222");
   };

   "quickfixj MessageUtilsTest.java / testParse (FIX.4.0 Logon, verbatim)"_test = [] {
      constexpr std::string_view msg =
         "8=FIX.4.0\0019=56\00135=A\00134=1\00149=TW\00152=20060118-16:34:19\00156=ISLD\00198=0\001108=2\00110=223\001";
      Logon40 m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.msg_seq_num == 1 and m.sender_comp_id == "TW" and m.target_comp_id == "ISLD");
      expect(m.sending_time == "20060118-16:34:19");
      expect(m.encrypt_method == 0 and m.heart_bt_int == 2);
   };

   "quickfixj MessageUtilsTest.java / testParseMessageWithoutChecksumValidation (10=283)"_test = [] {
      constexpr std::string_view msg =
         "8=FIX.4.0\0019=56\00135=A\00134=1\00149=TW\00152=20060118-16:34:19\00156=ISLD\00198=0\001108=2\00110=283\001";
      Logon40 m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, msg)));
      constexpr auto no_cs = [] {
         glz::fix_opts o{};
         o.validate_checksum = false;
         return o;
      }();
      Logon40 m2{};
      expect(not glz::read<no_cs>(m2, msg));
      expect(m2.heart_bt_int == 2);
   };

   "quickfixj MessageTest.java / testMessageBytesField (95/96, data without SOH, verbatim)"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.4\0019=21\00135=A\00195=7\00196=rawdata\00110=086\001";
      LogonRaw m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.raw_data_length == 7 and m.raw_data == "rawdata");
      skip("quickfixj MessageTest.java / testMessageBytesField with SOH inside RawData(96)",
           "fix/core does not support length-prefixed raw-data fields yet (docs/fix/api.md)");
   };

   "quickfixn MessageTests.cs / FromStringTestWithNoDataDictionary (verbatim)"_test = [] {
      constexpr std::string_view msg =
         "8=FIX.4.2\0019=55\00135=0\00134=3\00149=TW\00152=20000426-12:05:06\00156=ISLD\0011=acct123\00110=123\001";
      HeartbeatAcct m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.account == "acct123" and m.msg_seq_num == 3);
   };

   "quickfixn MessageTests.cs / RepeatedTagDetection"_test = [] {
      // Verbatim: two 10 fields -> not a valid message.
      constexpr std::string_view verbatim = "8=FIX.4.2\0019=72\00135=0\00134=3\00149=TW\00149=BOGUS\001"
                                            "52=20000426-12:05:06\00156=ISLD\0011=acct123\0011=bogus\00110=052\00110=000\001";
      HeartbeatAcct m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, verbatim)));
      expect(not is_valid(verbatim));
      skip("quickfixn MessageTests.cs / RepeatedTagDetection (duplicate 49 and 1 rejected)",
           "fix/core: a repeated top-level tag overwrites (docs/fix/api.md); QuickFIX/n reports it");
   };

   "quickfixn MessageTests.cs / GetInvalidMsgTypeTest (no 35)"_test = [] {
      const auto msg = make_msg("FIX.4.4", "34=3|49=sender|52=20110909-09:09:09.999|56=target|55=sym|268=0|");
      expect(not is_valid(msg));
      HeartbeatAcct m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, msg)));
   };

   "quickfixn ParserTest.cs / ReadFixMessageWithMissingValues (148= empty)"_test = [] {
      const auto msg = make_msg("FIX.4.4", "35=B|148=|33=0|");
      expect(not glz::fix::parse_fields(msg).has_value());
      expect(not is_valid(msg));
   };

   "quickfixn MessageTests.cs / IdentifyTypeTest msg3 (empty field '||')"_test = [] {
      expect(not glz::fix::parse_fields("8=FIX4.2\0019=12\001\00135=B\00110=031\001").has_value());
      expect(not is_valid("8=FIX4.2\0019=12\001\00135=B\00110=031\001"));
   };

   "quickfixn ParserTest.cs / ReadFixMessageWithNonAscii (byte 0xE9 counts as one byte)"_test = [] {
      // Original has placeholder 10=0; 9=19 is correct. 10 recomputed.
      const auto msg = make_msg("FIX.4.4", "35=B|148=Ol\351!|33=0|");
      expect(msg.find("\0019=19\001") != std::string::npos);
      expect(is_valid(msg));
      expect(glz::fix::frame(msg) == msg.size());
   };

   "quickfixj FIXMessageDecoderTest.java / testGarbageAtStart, testLengthFormatError, testLengthFormatError2"_test = [] {
      {
         // fix/core frames "8=!@#$%8=FIX.4.2" as BeginString (values may hold '='); the framed bytes
         // must still fail validate(). QuickFIX/J's decoder skips to the next "8=" itself.
         constexpr std::string_view g = "8=!@#$%8=FIX.4.2\0019=12\00135=X\001108=30\00110=049\001";
         const auto n = glz::fix::frame(g);
         expect(no_frame(n) or not is_valid(g.substr(0, n)));
      }
      expect(no_frame(glz::fix::frame("8=FIX.4.4\0019=058=\0018=FIX.4.4\0019=058=\001")));
      expect(no_frame(glz::fix::frame("8=FIX.4.2\0019=128=FIX.4.2\0019=8=FIX.4.2\0019=12\00135=X\001108=30\00110=049\001")));
      // testSimpleMessage, verbatim: frames and validates.
      constexpr std::string_view good = "8=FIX.4.2\0019=12\00135=X\001108=30\00110=049\001";
      expect(glz::fix::frame(good) == good.size());
      expect(is_valid(good));
   };

   "quickfixj FIXMessageDecoderTest.java / testBadLengthTooLong, testBadLengthTooShort"_test = [] {
      // Too long: frame() trusts 9 and does not find 10= where it expects -> no frame.
      expect(no_frame(glz::fix::frame("8=FIX.4.2\0019=25\00135=X\001108=30\00110=036\001")));
      // Too short: lands inside the body -> no frame (QuickFIX/J resyncs on the next 8=).
      expect(no_frame(glz::fix::frame("8=FIX.4.2\0019=10\00135=X\001108=30\00110=036\001")));
      // testBogusMessageLength: 9=10xyz.
      expect(no_frame(glz::fix::frame("8=FIX.4.2\0019=10xyz\00135=X\001108=30\00110=036\001")));
   };

   "quickfixj FIXMessageDecoderTest.java / testFailedPatternMatchAtEndOfBuffer (truncated trailer)"_test = [] {
      // "1wmyadz" where 10= should be: the decoder waits (NEED_DATA) or rejects; never a frame.
      expect(no_frame(glz::fix::frame("8=FIX.4.2\0019=12\00135=X\001108=30\0011wmyadz")));
   };

   "quickfixj FIXMessageDecoderTest.java / testWesternEuropeanDecoding (ISO-8859-1 bytes, verbatim)"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.4\0019=18\00135=B\001148=\344bcf\366d\347\351\00110=253\001";
      expect(is_valid(msg));
      News44 n{};
      expect(not glz::read<glz::fix_opts{}>(n, msg));
      expect(n.headline == "\344bcf\366d\347\351");
   };
};

// ---------------------------------------------------------------------------------------------
// QuickFIX C++ MessagesTestCase.cpp / MessageTests: more <x>GetString / <x>SetString pairs (FIX 4.2).
// Members are declared in tag order because QuickFIX writes body fields sorted by tag.
// ---------------------------------------------------------------------------------------------
namespace qf_more
{
   struct ExecutionReport42
   {
      double avg_px{}; // 6
      double cum_qty{}; // 14
      std::string exec_id; // 17
      char exec_trans_type{}; // 20
      std::string order_id; // 37
      char ord_status{}; // 39
      char side{}; // 54
      std::string symbol; // 55
      char exec_type{}; // 150
      double leaves_qty{}; // 151
   };
   struct DontKnowTrade42
   {
      std::string exec_id; // 17
      std::string order_id; // 37
      char side{}; // 54
      std::string symbol; // 55
      char dk_reason{}; // 127
   };
   struct OrderCancelReplace42
   {
      std::string cl_ord_id; // 11
      char handl_inst{}; // 21
      char ord_type{}; // 40
      std::string orig_cl_ord_id; // 41
      char side{}; // 54
      std::string symbol; // 55
      std::string transact_time; // 60
   };
   struct OrderCancel42
   {
      std::string cl_ord_id; // 11
      std::string orig_cl_ord_id; // 41
      char side{}; // 54
      std::string symbol; // 55
      std::string transact_time; // 60
   };
}

template <>
struct glz::meta<qf_more::ExecutionReport42>
{
   using T = qf_more::ExecutionReport42;
   static constexpr auto fix_msg_type = "8";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("6", &T::avg_px, "14", &T::cum_qty, "17", &T::exec_id, "20",
                                             &T::exec_trans_type, "37", &T::order_id, "39", &T::ord_status, "54",
                                             &T::side, "55", &T::symbol, "150", &T::exec_type, "151", &T::leaves_qty);
};
template <>
struct glz::meta<qf_more::DontKnowTrade42>
{
   using T = qf_more::DontKnowTrade42;
   static constexpr auto fix_msg_type = "Q";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("17", &T::exec_id, "37", &T::order_id, "54", &T::side, "55", &T::symbol,
                                             "127", &T::dk_reason);
};
template <>
struct glz::meta<qf_more::OrderCancelReplace42>
{
   using T = qf_more::OrderCancelReplace42;
   static constexpr auto fix_msg_type = "G";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "21", &T::handl_inst, "40", &T::ord_type, "41",
                                             &T::orig_cl_ord_id, "54", &T::side, "55", &T::symbol, "60",
                                             &T::transact_time);
};
template <>
struct glz::meta<qf_more::OrderCancel42>
{
   using T = qf_more::OrderCancel42;
   static constexpr auto fix_msg_type = "F";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "41", &T::orig_cl_ord_id, "54", &T::side, "55",
                                             &T::symbol, "60", &T::transact_time);
};

suite quickfix_more_message_strings = [] {
   using namespace qf_more;

   constexpr std::string_view execReport = "8=FIX.4.2\0019=77\00135=8\0016=23.4\00114=300\001"
                                           "17=EXECID\00120=1\00137=ORDERID\00139=3\00154=4\00155=MSFT\001"
                                           "150=2\001151=200\00110=052\001";
   "MessagesTestCase.cpp / MessageTests / executionReportGetString"_test = [&] {
      ExecutionReport42 m{23.4, 300, "EXECID", '1', "ORDERID", '3', '4', "MSFT", '2', 200};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == execReport) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / executionReportSetString"_test = [&] {
      ExecutionReport42 m{};
      expect(not glz::read<glz::fix_opts{}>(m, execReport));
      expect(m.order_id == "ORDERID" and m.exec_id == "EXECID");
      expect(m.exec_trans_type == '1' and m.exec_type == '2' and m.ord_status == '3');
      expect(m.symbol == "MSFT" and m.side == '4');
      expect(m.leaves_qty == 200.0 and m.cum_qty == 300.0 and m.avg_px == 23.4);
   };

   constexpr std::string_view dkTrade = "8=FIX.4.2\0019=45\00135=Q\00117=EXECID\00137=ORDERID\001"
                                        "54=2\00155=MSFT\001127=1\00110=195\001";
   "MessagesTestCase.cpp / MessageTests / dontKnowTradeGetString"_test = [&] {
      DontKnowTrade42 m{"EXECID", "ORDERID", '2', "MSFT", '1'};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == dkTrade) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / dontKnowTradeSetString"_test = [&] {
      DontKnowTrade42 m{};
      expect(not glz::read<glz::fix_opts{}>(m, dkTrade));
      expect(m.order_id == "ORDERID" and m.exec_id == "EXECID" and m.dk_reason == '1');
      expect(m.symbol == "MSFT" and m.side == '2');
   };

   "MessagesTestCase.cpp / MessageTests / orderCancelReplaceGetString"_test = [] {
      constexpr std::string_view expected = "8=FIX.4.2\0019=75\00135=G\00111=CLIENTID\00121=1\001"
                                            "40=3\00141=ORIGINALID\00154=2\00155=MSFT\001"
                                            "60=19000101-00:00:00\00110=179\001";
      OrderCancelReplace42 m{"CLIENTID", '1', '3', "ORIGINALID", '2', "MSFT", "19000101-00:00:00"};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == expected) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / orderCancelReplaceRequestSetString"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.2\0019=63\00135=G\00111=CLIENTID\00121=1\001"
                                       "40=3\00141=ORIGINALID\00154=2\00155=MSFT\00160=TODAY\001"
                                       "10=228\001";
      OrderCancelReplace42 m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.orig_cl_ord_id == "ORIGINALID" and m.cl_ord_id == "CLIENTID" and m.handl_inst == '1');
      expect(m.symbol == "MSFT" and m.side == '2' and m.ord_type == '3');
   };

   "MessagesTestCase.cpp / MessageTests / orderCancelRequestGetString"_test = [] {
      constexpr std::string_view expected = "8=FIX.4.2\0019=65\00135=F\00111=CLIENTID\00141=ORIGINALID\001"
                                            "54=1\00155=MSFT\00160=19000101-00:00:00\00110=009\001";
      OrderCancel42 m{"CLIENTID", "ORIGINALID", '1', "MSFT", "19000101-00:00:00"};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == expected) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / orderCancelRequestSetString"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.2\0019=53\00135=F\00111=CLIENTID\00141=ORIGINALID\001"
                                       "54=1\00155=MSFT\00160=TODAY\00110=058\001";
      OrderCancel42 m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.orig_cl_ord_id == "ORIGINALID" and m.cl_ord_id == "CLIENTID");
      expect(m.symbol == "MSFT" and m.side == '1' and m.transact_time == "TODAY");
   };

   "MessagesTestCase.cpp / MessageTests / <x>SetString: 35 must match the target type"_test = [&] {
      // Reading an ExecutionReport into a DontKnowTrade is a MsgType mismatch (validate_msg_type).
      DontKnowTrade42 m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, execReport)));
   };
};

// MessagesTestCase.cpp / MessageTests / newOrderListGetString, newOrderListSetString (FIX 4.2 NoOrders 73)
namespace qf_more
{
   struct ListOrder42
   {
      std::string cl_ord_id; // 11
      int32_t list_seq_no{}; // 67
      std::string symbol; // 55
      char side{}; // 54
   };
   struct NewOrderList42
   {
      std::string list_id; // 66
      int32_t tot_no_orders{}; // 68
      std::vector<ListOrder42> orders; // 73
      int32_t bid_type{-1}; // 394
   };
}
template <>
struct glz::meta<qf_more::ListOrder42>
{
   using T = qf_more::ListOrder42;
   static constexpr auto value =
      glz::object("11", &T::cl_ord_id, "67", &T::list_seq_no, "55", &T::symbol, "54", &T::side);
};
template <>
struct glz::meta<qf_more::NewOrderList42>
{
   using T = qf_more::NewOrderList42;
   static constexpr auto fix_msg_type = "E";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value =
      glz::object("66", &T::list_id, "68", &T::tot_no_orders, "73", &T::orders, "394", &T::bid_type);
};

suite quickfix_more_groups = [] {
   using namespace qf_more;

   "MessagesTestCase.cpp / MessageTests / newOrderListGetString"_test = [] {
      constexpr std::string_view expected = "8=FIX.4.2\0019=95\00135=E\00166=1\00168=3\00173=3\001"
                                            "11=A\00167=1\00155=DELL\00154=1\001"
                                            "11=B\00167=2\00155=LNUX\00154=2\001"
                                            "11=C\00167=3\00155=RHAT\00154=3\001"
                                            "394=0\00110=233\001";
      NewOrderList42 m{"1", 3, {{"A", 1, "DELL", '1'}, {"B", 2, "LNUX", '2'}, {"C", 3, "RHAT", '3'}}, 0};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == expected) << buf;
   };

   "MessagesTestCase.cpp / MessageTests / newOrderListSetString (fields in other order inside entries)"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.2\0019=95\00135=E\00166=1\00168=3\00173=3\001"
                                       "11=A\00154=1\00155=DELL\00167=1\001"
                                       "11=B\00154=2\00155=LNUX\00167=2\001"
                                       "11=C\00154=3\00155=RHAT\00167=3\001"
                                       "394=0\00110=233\001";
      NewOrderList42 m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.list_id == "1" and m.tot_no_orders == 3 and m.bid_type == 0);
      expect(m.orders.size() == 3u);
      if (m.orders.size() == 3u) {
         expect(m.orders[0].cl_ord_id == "A" and m.orders[0].list_seq_no == 1 and m.orders[0].symbol == "DELL" and
                m.orders[0].side == '1');
         expect(m.orders[1].cl_ord_id == "B" and m.orders[1].list_seq_no == 2 and m.orders[1].symbol == "LNUX" and
                m.orders[1].side == '2');
         expect(m.orders[2].cl_ord_id == "C" and m.orders[2].list_seq_no == 3 and m.orders[2].symbol == "RHAT" and
                m.orders[2].side == '3');
      }
   };

   "MessagesTestCase.cpp / MessageTests / newOrderListSetString (73=0)"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.2\0019=26\00135=E\00166=1\00168=3\00173=0\001394=0\00110=137\001";
      expect(is_valid(msg));
      NewOrderList42 m{};
      m.orders.resize(2);
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.orders.empty());
      expect(m.bid_type == 0);
   };

   "MessagesTestCase.cpp / MessageTests / newOrderList: count 3 with 2 entries is rejected"_test = [] {
      const auto msg = make_msg("FIX.4.2", "35=E|66=1|68=3|73=3|11=A|67=1|55=DELL|54=1|11=B|67=2|55=LNUX|54=2|394=0|");
      NewOrderList42 m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, msg)));
   };

   "MessagesTestCase.cpp / MessageTests / massQuoteParseGetString, massQuoteSetString"_test = [] {
      skip("MessagesTestCase.cpp / massQuoteParseGetString / massQuoteSetString (364/365 encoded data with SOH)",
           "fix/core does not support length-prefixed data fields yet (docs/fix/api.md)");
   };
};

// MessagesTestCase.cpp / MessageTests / newOrderCross*, allocationInstruction* (FIX 4.4, nested and header groups)
namespace qf_more
{
   struct CrossParty
   {
      std::string party_id; // 448
      char party_id_source{}; // 447
      int32_t party_role{}; // 452
   };
   struct CrossSide
   {
      char side{}; // 54
      std::vector<CrossParty> parties; // 453
      double order_qty{}; // 38
   };
   struct NewOrderCross44
   {
      std::vector<CrossSide> sides; // 552
   };
   struct AllocHop
   {
      std::string hop_comp_id; // 628
      std::string hop_sending_time; // 629
      int32_t hop_ref_id{}; // 630
   };
   struct AllocationInstruction44
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sending_time; // 52
      std::string target_comp_id; // 56
      std::vector<AllocHop> hops; // 627
      double avg_px{}; // 6
      double quantity{}; // 53
      std::string alloc_id; // 70
      char alloc_trans_type{}; // 71
      std::string trade_date; // 75
      int32_t alloc_type{}; // 626
      int32_t alloc_no_orders_type{-1}; // 857
   };
}
template <>
struct glz::meta<qf_more::CrossParty>
{
   using T = qf_more::CrossParty;
   static constexpr auto value = glz::object("448", &T::party_id, "447", &T::party_id_source, "452", &T::party_role);
};
template <>
struct glz::meta<qf_more::CrossSide>
{
   using T = qf_more::CrossSide;
   static constexpr auto value = glz::object("54", &T::side, "453", &T::parties, "38", &T::order_qty);
};
template <>
struct glz::meta<qf_more::NewOrderCross44>
{
   using T = qf_more::NewOrderCross44;
   static constexpr auto fix_msg_type = "s";
   static constexpr auto fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("552", &T::sides);
};
template <>
struct glz::meta<qf_more::AllocHop>
{
   using T = qf_more::AllocHop;
   static constexpr auto value =
      glz::object("628", &T::hop_comp_id, "629", &T::hop_sending_time, "630", &T::hop_ref_id);
};
template <>
struct glz::meta<qf_more::AllocationInstruction44>
{
   using T = qf_more::AllocationInstruction44;
   static constexpr auto fix_msg_type = "J";
   static constexpr auto fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object(
      "34", &T::msg_seq_num, "49", &T::sender_comp_id, "52", &T::sending_time, "56", &T::target_comp_id, "627",
      &T::hops, "6", &T::avg_px, "53", &T::quantity, "70", &T::alloc_id, "71", &T::alloc_trans_type, "75",
      &T::trade_date, "626", &T::alloc_type, "857", &T::alloc_no_orders_type);
};

suite quickfix_more_nested = [] {
   using namespace qf_more;
   constexpr std::string_view cross = "8=FIX.4.4\0019=75\00135=s\001552=1\00154=1\001453=2\001448=PARTY1\001"
                                      "447=D\001452=3\001448=PARTY2\001447=D\001452=3\00138=100\00110=223\001";

   "MessagesTestCase.cpp / MessageTests / newOrderCrossGetString"_test = [&] {
      NewOrderCross44 m{{{'1', {{"PARTY1", 'D', 3}, {"PARTY2", 'D', 3}}, 100}}};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == cross) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / newOrderCrossSetString"_test = [&] {
      NewOrderCross44 m{};
      expect(not glz::read<glz::fix_opts{}>(m, cross));
      expect(m.sides.size() == 1u);
      if (m.sides.size() != 1u) return;
      const auto& s = m.sides[0];
      expect(s.side == '1');
      expect(s.order_qty == 100.0); // 38 follows the nested 453 group, still in the 552 entry
      expect(s.parties.size() == 2u);
      if (s.parties.size() == 2u) {
         expect(s.parties[0].party_id == "PARTY1" and s.parties[0].party_id_source == 'D' and
                s.parties[0].party_role == 3);
         expect(s.parties[1].party_id == "PARTY2" and s.parties[1].party_id_source == 'D' and
                s.parties[1].party_role == 3);
      }
   };

   "MessagesTestCase.cpp / MessageTests / allocationInstructionParseGetString"_test = [] {
      constexpr std::string_view expected =
         "8=FIX.4.4\0019=121\00135=J\00134=1\00149=SENDER\00156=TARGET\001627=2\001"
         "628=HOP1\001630=1\001628=HOP2\001630=2\0016=23.1\00153=100\00170=Alloc001\001"
         "71=0\00175=20170317\001626=1\001857=0\00110=159\001";
      AllocationInstruction44 m{};
      m.msg_seq_num = 1;
      m.sender_comp_id = "SENDER";
      m.target_comp_id = "TARGET";
      m.hops = {{"HOP1", "", 1}, {"HOP2", "", 2}}; // empty strings are not written
      m.avg_px = 23.1;
      m.quantity = 100;
      m.alloc_id = "Alloc001";
      m.alloc_trans_type = '0';
      m.trade_date = "20170317";
      m.alloc_type = 1;
      m.alloc_no_orders_type = 0;
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == expected) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / allocationInstructionString"_test = [] {
      constexpr std::string_view msg =
         "8=FIX.4.4\0019=198\00135=J\00134=1\00149=SENDER\00152=20170317-15:55:23.685\001"
         "56=TARGET\001627=2\001628=HOP1\001629=20170317-15:55:23.685\001630=1\001"
         "628=HOP2\001629=20170317-15:55:23.685\001630=2\0016=23.1\00153=100\001"
         "70=Alloc001\00171=0\00175=20170317\001626=1\001857=0\00110=196\001";
      expect(is_valid(msg));
      AllocationInstruction44 m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.sender_comp_id == "SENDER" and m.target_comp_id == "TARGET" and m.msg_seq_num == 1);
      expect(m.sending_time == "20170317-15:55:23.685");
      expect(m.hops.size() == 2u);
      if (m.hops.size() == 2u) {
         expect(m.hops[0].hop_comp_id == "HOP1" and m.hops[0].hop_ref_id == 1);
         expect(m.hops[1].hop_comp_id == "HOP2" and m.hops[1].hop_sending_time == "20170317-15:55:23.685" and
                m.hops[1].hop_ref_id == 2);
      }
      expect(m.alloc_id == "Alloc001" and m.alloc_trans_type == '0' and m.alloc_type == 1);
      expect(m.alloc_no_orders_type == 0 and m.quantity == 100.0 and m.avg_px == 23.1);
      expect(m.trade_date == "20170317");
   };
};

// Typed reads of the long wire-valid QuickFIX/J vectors (verbatim, from qfj_qfn_vectors.inl).
// Top-level tags not mapped are skipped (fix/core default); groups must be mapped in full.
namespace qf_more
{
   inline std::string_view qfjn_vector(std::string_view method, size_t nth = 0)
   {
      for (const auto& v : qfjn_vectors::all) {
         const std::string_view src = v.source;
         if (src.size() >= method.size() && src.substr(src.size() - method.size()) == method) {
            if (nth == 0) return v.msg;
            --nth;
         }
      }
      return {};
   }

   struct ExecReportParties
   {
      std::string exec_id; // 17
      char exec_type{}; // 150
      std::string symbol; // 55
      double price{}; // 44
      std::vector<CrossParty> parties; // 453
      std::string transact_time; // 60
   };
   struct CrossSideSum
   {
      std::string symbol; // 55
      std::string cross_id; // 548
      int32_t cross_type{}; // 549
      int32_t cross_prioritization{-1}; // 550
      std::vector<CrossSide> sides; // 552
   };
   struct TcrSideParty
   {
      std::string party_id; // 448
      char party_id_source{}; // 447
      int32_t party_role{}; // 452
   };
   struct ClearingInstr
   {
      int32_t clearing_instruction{-1}; // 577
   };
   struct TcrSide
   {
      char side{}; // 54
      std::vector<TcrSideParty> parties; // 453
      std::string account; // 1
      std::vector<ClearingInstr> clearing; // 576
      std::string cl_ord_id; // 11
   };
   struct TradeCaptureReport
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string on_behalf_of_comp_id; // 115
      std::vector<AllocHop> hops; // 627
      std::string symbol; // 55
      double last_px{}; // 31
      double last_qty{}; // 32
      std::vector<TcrSide> sides; // 552
   };
}
template <>
struct glz::meta<qf_more::ExecReportParties>
{
   using T = qf_more::ExecReportParties;
   static constexpr auto fix_msg_type = "8";
   static constexpr auto value = glz::object("17", &T::exec_id, "150", &T::exec_type, "55", &T::symbol, "44",
                                             &T::price, "453", &T::parties, "60", &T::transact_time);
};
template <>
struct glz::meta<qf_more::CrossSideSum>
{
   using T = qf_more::CrossSideSum;
   static constexpr auto fix_msg_type = "s";
   static constexpr auto value = glz::object("55", &T::symbol, "548", &T::cross_id, "549", &T::cross_type, "550",
                                             &T::cross_prioritization, "552", &T::sides);
};
template <>
struct glz::meta<qf_more::TcrSideParty>
{
   using T = qf_more::TcrSideParty;
   static constexpr auto value = glz::object("448", &T::party_id, "447", &T::party_id_source, "452", &T::party_role);
};
template <>
struct glz::meta<qf_more::ClearingInstr>
{
   using T = qf_more::ClearingInstr;
   static constexpr auto value = glz::object("577", &T::clearing_instruction);
};
template <>
struct glz::meta<qf_more::TcrSide>
{
   using T = qf_more::TcrSide;
   static constexpr auto value = glz::object("54", &T::side, "453", &T::parties, "1", &T::account, "576",
                                             &T::clearing, "11", &T::cl_ord_id);
};
template <>
struct glz::meta<qf_more::TradeCaptureReport>
{
   using T = qf_more::TradeCaptureReport;
   static constexpr auto fix_msg_type = "AE";
   static constexpr auto value =
      glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "115", &T::on_behalf_of_comp_id, "627", &T::hops,
                  "55", &T::symbol, "31", &T::last_px, "32", &T::last_qty, "552", &T::sides);
};

suite quickfixj_long_vectors = [] {
   using namespace qf_more;

   "quickfixj MessageTest.java / testValidation (ExecutionReport, 453 Parties=3)"_test = [] {
      const auto msg = qfjn_vector("testValidation");
      expect(not msg.empty() and is_valid(msg));
      ExecReportParties m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.exec_id == "X-B-WOW-1494E9A0:58BD3F9D-1109" and m.exec_type == 'D' and m.symbol == "WOW");
      expect(m.price == 15.0);
      expect(m.transact_time == "20060320-03:34:29"); // after the group
      expect(m.parties.size() == 3u);
      if (m.parties.size() == 3u) {
         expect(m.parties[0].party_id == "AAA35791" and m.parties[0].party_role == 3);
         expect(m.parties[1].party_id == "8" and m.parties[1].party_role == 4);
         expect(m.parties[2].party_id == "FIX11" and m.parties[2].party_role == 36);
      }
      // error_on_unknown_tags: the unmapped top-level tags are now errors.
      constexpr auto strict = [] {
         glz::fix_opts o{};
         o.error_on_unknown_tags = true;
         return o;
      }();
      ExecReportParties m2{};
      expect(bool(glz::read<strict>(m2, msg)));
   };

   "quickfixj MessageTest.java / testCalculateStringWithNestedGroups (552 Sides, nested 453)"_test = [] {
      const auto msg = qfjn_vector("testCalculateStringWithNestedGroups");
      expect(not msg.empty() and is_valid(msg));
      CrossSideSum m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.symbol == "ABC" and m.cross_id == "184214" and m.cross_type == 2 and m.cross_prioritization == 0);
      expect(m.sides.size() == 2u);
      if (m.sides.size() == 2u) {
         expect(m.sides[0].side == '1' and m.sides[0].order_qty == 9.0 and m.sides[0].parties.size() == 2u);
         expect(m.sides[1].side == '2' and m.sides[1].parties.size() == 2u);
         if (m.sides[1].parties.size() == 2u) expect(m.sides[1].parties[1].party_id == "aaa");
      }
   };

   "quickfixj MessageTest.java / testValidateFieldsOutOfOrderFIXT11 (orderedData)"_test = [] {
      const auto msg = qfjn_vector("testValidateFieldsOutOfOrderFIXT11", 0);
      expect(not msg.empty() and is_valid(msg));
      TradeCaptureReport m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.msg_seq_num == 545 and m.sender_comp_id == "SENDER" and m.on_behalf_of_comp_id == "ON_BHEHALF");
      expect(m.hops.size() == 2u);
      expect(m.symbol == "ANZ" and m.last_px == 27.0 and m.last_qty == 5000.0);
      expect(m.sides.size() == 2u);
      if (m.sides.size() == 2u) {
         expect(m.sides[0].side == '1' and m.sides[0].account == "1040445");
         expect(m.sides[0].parties.size() == 1u and m.sides[0].clearing.size() == 1u);
         expect(m.sides[0].cl_ord_id == "7533509260093758035");
         expect(m.sides[1].side == '2' and m.sides[1].cl_ord_id == "7533509260093757876");
      }
   };

   "quickfixj MessageTest.java / testValidateFieldsOutOfOrderFIXT11 (unorderedData: header tags after body)"_test = [] {
      // QuickFIX/J rejects this with validateFieldsOutOfOrder=true. fix/core has no header/body
      // split and reads it; the wire framing (8, 9, 35 ... 10) is still valid.
      const auto msg = qfjn_vector("testValidateFieldsOutOfOrderFIXT11", 1);
      expect(not msg.empty() and is_valid(msg));
      TradeCaptureReport m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.sides.size() == 2u and m.hops.size() == 2u and m.msg_seq_num == 545);
      skip("quickfixj MessageTest.java / testValidateFieldsOutOfOrderFIXT11 (header field after body rejected)",
           "needs a data dictionary of header tags; the contract checks only 8, 9, 35 and 10");
   };
};
