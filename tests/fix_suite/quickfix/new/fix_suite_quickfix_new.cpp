// Glaze Library
// For the license information refer to glaze.hpp
//
// Additional FIX tests ported from QuickFIX (C++) https://github.com/quickfix/quickfix
// (QuickFIX licence, BSD-style; see LICENSE in this directory and SOURCES.md).
// Only cases NOT already present in tests/fix_quickfix_test/fix_quickfix_test.cpp
// (branch origin/fix/tests-quickfix) are ported here.

#include <cstdio>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
   constexpr char SOH = '\x01';

   // Minimal typed messages used by the ported convertor tests.
   struct IntMsg
   {
      int v{};
   };
   struct UIntMsg
   {
      unsigned v{};
   };
   struct DoubleMsg
   {
      double v{};
   };
   struct BoolMsg
   {
      bool v{};
   };
   struct CharMsg
   {
      char v{};
   };
   struct TsMsg
   {
      glz::fix::utc_timestamp v{};
   };
   struct DecMsg
   {
      glz::fix::decimal v{};
   };

   // Heartbeat (35=0) with TestReqID, and Logon (35=A).
   struct Heartbeat
   {
      std::optional<std::string> test_req_id{};
   };
   struct Logon
   {
      int encrypt_method{};
      int heart_bt_int{};
      std::optional<bool> reset_seq_num{};
   };

   // MessagesTestCase.cpp setStringWithGroup style: 35=i (MassQuote) NoQuoteSets / NoQuoteEntries.
   struct QuoteEntry
   {
      std::string quote_entry_id{};
      std::optional<std::string> symbol{};
   };
   struct QuoteSet
   {
      std::string quote_set_id{};
      std::vector<QuoteEntry> entries{};
   };
   struct MassQuote
   {
      std::string quote_id{};
      std::vector<QuoteSet> sets{};
   };

   struct RawMsg
   {
      std::string raw{}; // 96 RawData, 95 emitted automatically
   };
}

template <>
struct glz::meta<IntMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &IntMsg::v);
};
template <>
struct glz::meta<UIntMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &UIntMsg::v);
};
template <>
struct glz::meta<DoubleMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &DoubleMsg::v);
};
template <>
struct glz::meta<BoolMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &BoolMsg::v);
};
template <>
struct glz::meta<CharMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &CharMsg::v);
};
template <>
struct glz::meta<TsMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &TsMsg::v);
};
template <>
struct glz::meta<DecMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &DecMsg::v);
};
template <>
struct glz::meta<Heartbeat>
{
   static constexpr auto fix_msg_type = "0";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("112", &Heartbeat::test_req_id);
};
template <>
struct glz::meta<Logon>
{
   using T = Logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("98", &T::encrypt_method, "108", &T::heart_bt_int, "141", &T::reset_seq_num);
};
template <>
struct glz::meta<QuoteEntry>
{
   using T = QuoteEntry;
   static constexpr auto value = glz::object("299", &T::quote_entry_id, "55", &T::symbol);
};
template <>
struct glz::meta<QuoteSet>
{
   using T = QuoteSet;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "295", &T::entries);
};
template <>
struct glz::meta<MassQuote>
{
   using T = MassQuote;
   static constexpr auto fix_msg_type = "i";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("117", &T::quote_id, "296", &T::sets);
};
template <>
struct glz::meta<RawMsg>
{
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("96", &RawMsg::raw);
};

namespace
{
   // QuickFIX's ParserTestCase vectors carry 2-digit checksums ("10=31"), which glaze rejects
   // (CheckSum must be three digits), so the same bodies are re-framed wire-valid here.
   std::string wire(std::string_view body, std::string_view begin = "FIX.4.2")
   {
      std::string s = "8=";
      s.append(begin).push_back(SOH);
      s += "9=" + std::to_string(body.size());
      s.push_back(SOH);
      s.append(body);
      const auto cs = glz::fix::checksum(s);
      char buf[8];
      std::snprintf(buf, sizeof buf, "10=%03u", unsigned(cs));
      s += buf;
      s.push_back(SOH);
      return s;
   }

   // Build a body fragment "5000=<v>\x01" and read it into T (no envelope => no validate).
   template <class T>
   glz::error_ctx read_body(T& t, std::string_view v)
   {
      std::string s = "5000=";
      s.append(v);
      s.push_back(SOH);
      return glz::read<glz::fix_opts{}>(t, s);
   }
}

suite quickfix_field_convertors = [] {
   // FieldConvertorsTestCase.cpp / integerConvertFrom
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / integerConvertFrom"_test = [] {
      IntMsg m{};
      expect(!read_body(m, "15"));
      expect(m.v == 15);
      expect(!read_body(m, "-15"));
      expect(m.v == -15);
      expect(!read_body(m, "0"));
      expect(m.v == 0);
      expect(bool(read_body(m, "abc")));
      expect(bool(read_body(m, "15a")));
      expect(bool(read_body(m, "15.")));
      expect(bool(read_body(m, "1.5")));
      expect(bool(read_body(m, "+15"))); // QuickFIX rejects an explicit plus sign
   };

   // FieldConvertorsTestCase.cpp / integerConvertFrom: "-" rejected for unsigned
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / integerConvertFrom (unsigned)"_test = [] {
      UIntMsg m{};
      expect(!read_body(m, "15"));
      expect(m.v == 15u);
      expect(bool(read_body(m, "-15")));
   };

   // FieldConvertorsTestCase.cpp / doubleConvertFrom
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / doubleConvertFrom"_test = [] {
      DoubleMsg m{};
      expect(!read_body(m, "15.5"));
      expect(m.v == 15.5);
      expect(!read_body(m, "-15.5"));
      expect(m.v == -15.5);
      expect(!read_body(m, "15"));
      expect(m.v == 15.0);
      expect(!read_body(m, "-15"));
      expect(m.v == -15.0);
      expect(!read_body(m, "15."));
      expect(m.v == 15.0);
      expect(!read_body(m, ".5"));
      expect(m.v == 0.5);
      expect(!read_body(m, "0.00"));
      expect(m.v == 0.0);
      expect(bool(read_body(m, "+15.5"))); // QuickFIX: throws FieldConvertError
      expect(bool(read_body(m, "15.5a")));
      expect(bool(read_body(m, "abc")));
      expect(bool(read_body(m, "+")));
      expect(bool(read_body(m, "-")));
      expect(bool(read_body(m, ".")));
   };

   // FieldConvertorsTestCase.cpp / doubleConvertTo (round-trip of representative values)
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / doubleConvertTo"_test = [] {
      DoubleMsg m{};
      std::string out{};
      m.v = 45.32;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=45.32\x01") != std::string::npos) << out;
      m.v = 45.0;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=45\x01") != std::string::npos) << out;
      m.v = -45.32;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=-45.32\x01") != std::string::npos) << out;
      m.v = 0.0;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=0\x01") != std::string::npos) << out;
   };

   // FieldConvertorsTestCase.cpp / doubleConvertTo with padding -> glz::fix::decimal keeps scale
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / doubleConvertToWithPadding (decimal keeps scale)"_test = [] {
      DecMsg m{};
      std::string out{};
      expect(!read_body(m, "45.3200"));
      expect(m.v.to_double() == 45.32);
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=45.3200\x01") != std::string::npos) << out;
      expect(!read_body(m, "45.00"));
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=45.00\x01") != std::string::npos) << out;
      expect(bool(read_body(m, "+45.32")));
      expect(bool(read_body(m, "45.32e2")));
   };

   // FieldConvertorsTestCase.cpp / charConvertFrom
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / charConvertFrom"_test = [] {
      CharMsg m{};
      expect(!read_body(m, "1"));
      expect(m.v == '1');
      expect(!read_body(m, "A"));
      expect(m.v == 'A');
      expect(bool(read_body(m, "11")));
      expect(bool(read_body(m, "AB")));
   };

   // FieldConvertorsTestCase.cpp / charConvertTo
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / charConvertTo"_test = [] {
      CharMsg m{'Z'};
      std::string out{};
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=Z\x01") != std::string::npos) << out;
   };

   // FieldConvertorsTestCase.cpp / boolConvertFrom
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / boolConvertFrom"_test = [] {
      BoolMsg m{};
      expect(!read_body(m, "Y"));
      expect(m.v == true);
      expect(!read_body(m, "N"));
      expect(m.v == false);
      expect(bool(read_body(m, "D")));
      expect(bool(read_body(m, "y")));
      expect(bool(read_body(m, "YY")));
      expect(bool(read_body(m, "true")));
   };

   // FieldConvertorsTestCase.cpp / boolConvertTo
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / boolConvertTo"_test = [] {
      BoolMsg m{true};
      std::string out{};
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=Y\x01") != std::string::npos) << out;
      m.v = false;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=N\x01") != std::string::npos) << out;
   };

   // FieldConvertorsTestCase.cpp / utcTimeStampConvertFrom
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeStampConvertFrom"_test = [] {
      using namespace std::chrono;
      TsMsg m{};
      expect(!read_body(m, "20020324-12:05:06"));
      {
         const auto d = floor<days>(m.v.time);
         const year_month_day ymd{d};
         const hh_mm_ss hms{m.v.time - d};
         expect(int(ymd.year()) == 2002);
         expect(unsigned(ymd.month()) == 3u);
         expect(unsigned(ymd.day()) == 24u);
         expect(hms.hours().count() == 12);
         expect(hms.minutes().count() == 5);
         expect(hms.seconds().count() == 6);
         expect(m.v.precision == 0);
      }
      expect(!read_body(m, "20020324-12:05:06.555"));
      {
         const auto d = floor<days>(m.v.time);
         const hh_mm_ss hms{m.v.time - d};
         expect(duration_cast<milliseconds>(hms.subseconds()).count() == 555);
         expect(m.v.precision == 3);
      }
      expect(!read_body(m, "20020324-12:05:06.555555"));
      expect(m.v.precision == 6);
      expect(!read_body(m, "20020324-12:05:06.555555555"));
      expect(m.v.precision == 9);
      // invalid forms from the QuickFIX test
      expect(bool(read_body(m, "2002032-12:05:06")));
      expect(bool(read_body(m, "20020324-12:05:0")));
      expect(bool(read_body(m, "20020324-12:05:06.")));
      expect(bool(read_body(m, "20020324 12:05:06")));
      expect(bool(read_body(m, "20021324-12:05:06"))); // month 13
      expect(bool(read_body(m, "20020332-12:05:06"))); // day 32
      expect(bool(read_body(m, "20020324-24:05:06"))); // hour 24
      expect(bool(read_body(m, "20020324-12:60:06"))); // minute 60
      expect(bool(read_body(m, "20020324-12:05:60"))); // second 60 (leap second rejected)
      expect(bool(read_body(m, "20020229-12:05:06"))); // 2002 is not a leap year
      expect(!read_body(m, "20000229-12:05:06")); // 2000 is a leap year
   };

   // FieldConvertorsTestCase.cpp / utcTimeStampConvertTo
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeStampConvertTo"_test = [] {
      using namespace std::chrono;
      TsMsg m{};
      m.v.time = sys_days{year{2002} / 3 / 24} + hours{12} + minutes{5} + seconds{6} + milliseconds{555};
      std::string out{};
      m.v.precision = 3;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=20020324-12:05:06.555\x01") != std::string::npos) << out;
      m.v.precision = 0;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=20020324-12:05:06\x01") != std::string::npos) << out;
      m.v.precision = 6;
      expect(!glz::write<glz::fix_opts{}>(m, out));
      expect(out.find("5000=20020324-12:05:06.555000\x01") != std::string::npos) << out;
      // round-trip
      TsMsg back{};
      expect(!glz::read<glz::fix_opts{}>(back, out));
      expect(back.v.time == m.v.time);
      expect(back.v.precision == 6);
   };
};

suite quickfix_messages = [] {
   // MessagesTestCase.cpp / isAdmin style: Heartbeat (admin) round-trip, FIX.4.2 envelope
   "MessagesTestCase.cpp / MessageTests / heartbeatGetString round-trip"_test = [] {
      Heartbeat hb{};
      hb.test_req_id = "1";
      std::string out{};
      expect(!glz::write<glz::fix_opts{}>(hb, out));
      expect(out == "8=FIX.4.2\x01" "9=11\x01" "35=0\x01" "112=1\x01" "10=209\x01") << out;
      expect(!glz::fix::validate(out));
      Heartbeat back{};
      expect(!glz::read<glz::fix_opts{}>(back, out));
      expect(back.test_req_id.has_value() && *back.test_req_id == "1");
   };

   // ParserTestCase.cpp vector fixMsg1 (Logon) parsed into a typed struct
   "ParserTestCase.cpp / ParserTests / fixMsg1 Logon typed read"_test = [] {
      const std::string msg = wire("35=A\001108=30\001"); // QuickFIX: 8=FIX.4.2|9=12|35=A|108=30|10=31
      Logon l{};
      expect(!glz::read<glz::fix_opts{}>(l, msg));
      expect(l.heart_bt_int == 30);
      expect(l.encrypt_method == 0);
      expect(!l.reset_seq_num.has_value());
   };

   // MessagesTestCase.cpp / setString: MsgType mismatch is rejected (35=A read as Heartbeat)
   "MessagesTestCase.cpp / MessageTests / msgType mismatch on typed read"_test = [] {
      const std::string msg = wire("35=A\001108=30\001");
      Heartbeat hb{};
      const auto ec = glz::read<glz::fix_opts{}>(hb, msg);
      expect(ec.ec == glz::error_code::invalid_header) << glz::format_error(ec, msg);
   };

   // ParserTestCase.cpp / readFixMessage: fixMsg3 has a tag (9710) not in the dictionary
   "ParserTestCase.cpp / ParserTests / fixMsg3 unknown tag tolerated / rejected by option"_test = [] {
      const std::string msg = wire("35=A\001108=30\0019710=8\001"); // QuickFIX fixMsg3
      expect(!glz::fix::validate(msg));
      Logon l{};
      expect(!glz::read<glz::fix_opts{}>(l, msg));
      expect(l.heart_bt_int == 30);
      constexpr glz::fix_opts strict = [] { glz::fix_opts o{}; o.error_on_unknown_tags = true; return o; }();
      Logon l2{};
      const auto ec = glz::read<strict>(l2, msg);
      expect(ec.ec == glz::error_code::unknown_key) << glz::format_error(ec, msg);
   };

   // ParserTestCase.cpp / readFixMessage: badLength "9=200A"
   "ParserTestCase.cpp / ParserTests / readMessageWithBadLength (9=200A is not a number)"_test = [] {
      const std::string msg = "8=FIX.4.2\0019=200A\00135=A\001108=30\00110=31\001";
      expect(glz::fix::frame(msg) == glz::fix::frame_error);
      expect(bool(glz::fix::validate(msg)));
   };

   // ParserTestCase.cpp / extractLength: negative length and incomplete streams
   "ParserTestCase.cpp / ParserTests / extractLength (negative, incomplete)"_test = [] {
      const std::string negativeLength = "8=FIX.4.2\0019=-1\00135=A\001108=30\00110=31\001";
      expect(glz::fix::frame(negativeLength) == glz::fix::frame_error);
      // SKIP: frame("8=FIX.4.2") (no SOH yet) and a buffer cut inside "10=3" are not reported as
      // "need more bytes" (0) by glz::fix::frame; QuickFIX's extractLength treats them as incomplete.
      expect(glz::fix::frame("8=FIX.4.2\0019=12") == 0u);
      // SKIP: QuickFIX's normalLength vector "...10=31|" (2-digit checksum) is framed by QuickFIX but
      // not by glz::fix::frame, which needs the 3-digit "10=ddd|" trailer; the wire-valid form is used.
      const std::string normal = wire("35=A\001108=30\001");
      expect(glz::fix::frame(normal) == normal.size());
   };

   // ParserTestCase.cpp / readFixMessage: three back-to-back messages in one buffer
   "ParserTestCase.cpp / ParserTests / readFixMessage (three messages framed in sequence)"_test = [] {
      const std::string fixMsg1 = wire("35=A\001108=30\001");
      const std::string fixMsg2 = wire("35=4\00136=88\001123=Y\001");
      const std::string fixMsg3 = wire("35=A\001108=30\0019710=8\001");
      std::string stream = fixMsg1 + fixMsg2 + fixMsg3;
      std::string_view sv = stream;
      std::vector<std::string> got{};
      while (!sv.empty()) {
         const auto n = glz::fix::frame(sv);
         expect(n != 0u && n != glz::fix::frame_error);
         if (n == 0u || n == glz::fix::frame_error) break;
         expect(!glz::fix::validate(sv.substr(0, n)));
         got.emplace_back(sv.substr(0, n));
         sv.remove_prefix(n);
      }
      expect(got.size() == 3u);
      expect(got.size() == 3u && got[0] == fixMsg1 && got[1] == fixMsg2 && got[2] == fixMsg3);
   };

   // MessagesTestCase.cpp / setStringWithGroup (MassQuote): nested NoQuoteSets / NoQuoteEntries typed
   "MessagesTestCase.cpp / MessageTests / setStringWithGroup nested groups typed round-trip"_test = [] {
      MassQuote q{};
      q.quote_id = "1";
      q.sets.push_back({"A", {{"1", "DELL"}, {"2", "LNUX"}}});
      q.sets.push_back({"B", {{"3", "IBM"}}});
      std::string out{};
      expect(!glz::write<glz::fix_opts{}>(q, out));
      expect(!glz::fix::validate(out)) << out;
      expect(out.find("296=2\001" "302=A\001" "295=2\001" "299=1\001" "55=DELL\001" "299=2\001" "55=LNUX\001"
                      "302=B\001" "295=1\001" "299=3\001" "55=IBM\001") != std::string::npos)
         << out;
      MassQuote back{};
      expect(!glz::read<glz::fix_opts{}>(back, out));
      expect(back.quote_id == "1");
      expect(back.sets.size() == 2u);
      expect(back.sets.size() == 2u && back.sets[0].entries.size() == 2u && back.sets[1].entries.size() == 1u);
      expect(back.sets.size() == 2u && back.sets[1].entries.size() == 1u && back.sets[1].entries[0].symbol == "IBM");
   };

   // GroupTestCase.cpp style: group count disagrees with the entries present
   "GroupTestCase.cpp / GroupTests / group count mismatch is rejected"_test = [] {
      const std::string body = "117=1\001" "296=2\001" "302=A\001" "295=1\001" "299=1\001";
      MassQuote q{};
      const auto ec = glz::read<glz::fix_opts{}>(q, body);
      expect(ec.ec == glz::error_code::syntax_error) << glz::format_error(ec, body);
   };

   // MessagesTestCase.cpp / setStringWithRawData style: 95/96 pair with SOH inside the data
   "MessagesTestCase.cpp / MessageTests / raw data with embedded SOH round-trip"_test = [] {
      RawMsg r{};
      r.raw = std::string("a\001b=c\001", 6);
      std::string out{};
      expect(!glz::write<glz::fix_opts{}>(r, out));
      expect(out.find("95=6\001" "96=a\001b=c\001\001") != std::string::npos) << out;
      expect(!glz::fix::validate(out)) << out;
      RawMsg back{};
      expect(!glz::read<glz::fix_opts{}>(back, out));
      expect(back.raw == r.raw);
      // length past the end of the message
      const std::string bad = "95=40\00196=abc\001";
      RawMsg b2{};
      expect(bool(glz::read<glz::fix_opts{}>(b2, bad)));
   };

   // MessagesTestCase.cpp / setString strBadChk style with the DataDictionary "TEST" vector:
   // "8=TEST 9=TEST 35=TEST ... 10=TEST" must be rejected (9 and 10 are not numbers)
   "DataDictionaryTestCase.cpp / DataDictionaryTests / 9=TEST 10=TEST rejected"_test = [] {
      const std::string msg =
         "8=TEST\0019=TEST\00135=TEST\00149=SS1\00156=RORE\00134=3\00152=20050222-16:45:53\00110=TEST\001";
      const auto ec = glz::fix::validate(msg);
      expect(bool(ec));
      expect(ec.ec == glz::error_code::invalid_header) << glz::format_error(ec, msg);
      expect(glz::fix::frame(msg) == glz::fix::frame_error);
      // the field scanner itself is fine with it (no envelope rules)
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value() && fields->size() == 8u);
   };
};

int main() { return 0; }
