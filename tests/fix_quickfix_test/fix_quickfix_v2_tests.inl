// Glaze Library
// For the license information refer to glaze.hpp
//
// Cases that use fix/core v2 (raw-data fields, glz::fix::utc_timestamp, glz::fix::decimal).
// Sources: QuickFIX C++ src/C++/test (MessagesTestCase.cpp, FieldConvertorsTestCase.cpp,
// ParserTestCase.cpp), QuickFIX/J MessageTest.java, QuickFIX/n MessageTests.cs.
// This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/).

namespace qf_v2
{
   // MessagesTestCase.cpp / massQuoteParseGetString: EncodedUnderlyingSecurityDescLen(364) / Desc(365)
   struct QuoteSetEnc
   {
      std::string quote_set_id; // 302
      std::string underlying_symbol; // 311
      std::string encoded_desc; // 365 (364 written automatically)
   };
   struct MassQuoteEnc
   {
      std::string quote_id; // 117
      std::vector<QuoteSetEnc> sets; // 296
   };
   // QuickFIX/J testMessageBytesField with a SOH inside RawData
   struct LogonRawData
   {
      std::string raw_data; // 96 (95 written automatically)
   };
   // QuickFIX/n ReadXmlDataTest: XmlData(213) holding a complete FIX message
   struct XmlNews
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string xml_data; // 213
   };
   struct TsCarrier
   {
      glz::fix::utc_timestamp ts; // 52
   };
   struct DecCarrier
   {
      glz::fix::decimal px; // 44
   };
}
template <>
struct glz::meta<qf_v2::QuoteSetEnc>
{
   using T = qf_v2::QuoteSetEnc;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "311", &T::underlying_symbol, "365",
                                             &T::encoded_desc);
};
template <>
struct glz::meta<qf_v2::MassQuoteEnc>
{
   using T = qf_v2::MassQuoteEnc;
   static constexpr auto fix_msg_type = "i";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("117", &T::quote_id, "296", &T::sets);
};
template <>
struct glz::meta<qf_v2::LogonRawData>
{
   using T = qf_v2::LogonRawData;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("96", &T::raw_data);
};
template <>
struct glz::meta<qf_v2::XmlNews>
{
   using T = qf_v2::XmlNews;
   static constexpr auto fix_msg_type = "n";
   static constexpr auto value = glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "213", &T::xml_data);
};
template <>
struct glz::meta<qf_v2::TsCarrier>
{
   using T = qf_v2::TsCarrier;
   static constexpr auto fix_msg_type = "U2";
   static constexpr auto value = glz::object("52", &T::ts);
};
template <>
struct glz::meta<qf_v2::DecCarrier>
{
   using T = qf_v2::DecCarrier;
   static constexpr auto fix_msg_type = "U3";
   static constexpr auto value = glz::object("44", &T::px);
};

suite quickfix_raw_data = [] {
   using namespace qf_v2;

   "MessagesTestCase.cpp / MessageTests / massQuoteSetString (365 holds SOH)"_test = [] {
      expect(is_valid(qf_vectors::parserByteMsg1));
      auto f = glz::fix::parse_fields(qf_vectors::parserByteMsg1);
      expect(f.has_value());
      MassQuoteEnc m{};
      expect(not glz::read<glz::fix_opts{}>(m, qf_vectors::parserByteMsg1));
      expect(m.quote_id == "1");
      expect(m.sets.size() == 1u);
      if (m.sets.size() == 1u) {
         expect(m.sets[0].quote_set_id == "A" and m.sets[0].underlying_symbol == "DELL");
         expect(m.sets[0].encoded_desc == "DELL\001COMP\001");
      }
   };
   "MessagesTestCase.cpp / MessageTests / massQuoteParseGetString (exact write, 364 automatic)"_test = [] {
      MassQuoteEnc m{"1", {{"A", "DELL", "DELL\001COMP\001"}}};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == qf_vectors::parserByteMsg1) << buf;
   };
   "quickfixj MessageTest.java / testMessageBytesField (RawData with SOH and '=')"_test = [] {
      LogonRawData m{std::string("raw\001da=ta")};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf.find(std::string_view{"\00195=9\00196=raw\001da=ta\001"}) != std::string::npos) << buf;
      expect(is_valid(buf));
      LogonRawData back{};
      expect(not glz::read<glz::fix_opts{}>(back, buf));
      expect(back.raw_data == m.raw_data);
   };
   "quickfixn MessageTests.cs / ReadXmlDataTest (213 holds a whole FIX message)"_test = [] {
      const auto msg = qf_more::qfjn_vector("ReadXmlDataTest");
      expect(not msg.empty() and is_valid(msg));
      expect(glz::fix::frame(msg) == msg.size());
      XmlNews m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.msg_seq_num == 31420 and m.sender_comp_id == "CME");
      expect(m.xml_data.size() == 392u);
      expect(m.xml_data.starts_with("<RTRF>8=FIX.4.2\001"));
   };
   "MessagesTestCase.cpp / setStringWithDataFieldAndGarbageAsDataLength"_test = [] {
      // 95=garbage followed by 96: a length that is not a number is a syntax error.
      const auto msg = make_msg("FIX.4.2", "35=B|148=client|95=garbage|96=\244\244\244|");
      expect(not is_valid(msg));
      LogonRawData m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, msg)));
   };
   "raw data: count past the end of the message is rejected"_test = [] {
      const auto msg = make_msg("FIX.4.4", "35=A|95=200|96=short|");
      expect(not is_valid(msg));
   };
};

suite quickfix_utc_timestamp = [] {
   using namespace qf_v2;
   using namespace std::chrono;
   const auto base = sys_days{year{2000} / April / 26} + hours{12} + minutes{5} + seconds{6};

   "FieldConvertorsTestCase.cpp / utcTimeStampConvertFrom{Second,Milli,Micro,Nano}"_test = [&] {
      glz::fix::utc_timestamp t{};
      expect(glz::fix::parse_utc_timestamp("20000426-12:05:06", t) and t.time == base and t.precision == 0);
      expect(glz::fix::parse_utc_timestamp("20000426-12:05:06.555", t) and t.time == base + milliseconds{555} and
             t.precision == 3);
      expect(glz::fix::parse_utc_timestamp("20000426-12:05:06.555555", t) and
             t.time == base + microseconds{555555} and t.precision == 6);
      expect(glz::fix::parse_utc_timestamp("20000426-12:05:06.555555555", t) and
             t.time == base + nanoseconds{555555555} and t.precision == 9);
   };
   "FieldConvertorsTestCase.cpp / utcTimeStampConvertTo{Second,Milli,Micro,Nano}"_test = [&] {
      auto put = [](sys_time<nanoseconds> tp, uint8_t prec) {
         std::string s;
         glz::fix::append_utc_timestamp(s, glz::fix::utc_timestamp{tp, prec});
         return s;
      };
      const auto t = base + nanoseconds{555555555};
      expect(put(base, 0) == "20000426-12:05:06");
      expect(put(t, 0) == "20000426-12:05:06");
      expect(put(t, 3) == "20000426-12:05:06.555");
      expect(put(t, 6) == "20000426-12:05:06.555555");
      expect(put(t, 9) == "20000426-12:05:06.555555555");
   };
   "FieldConvertorsTestCase.cpp / utcTimeStamp as a message field (read and write)"_test = [&] {
      const auto msg = make_msg("FIX.4.4", "35=U2|52=20000426-12:05:06.555|");
      TsCarrier m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.ts.time == base + milliseconds{555} and m.ts.precision == 3);
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == msg) << buf;
      // utcDateConvertFrom's out-of-range month / day, applied to the date part of a timestamp.
      for (auto bad : {"20001526-12:05:06", "20000438-12:05:06", "20000426-24:00:00", "20000426-12:05:60",
                       "20000426 12:05:06", "2000042-12:05:06"}) {
         const auto b = make_msg("FIX.4.4", std::string("35=U2|52=") + bad + "|");
         TsCarrier x{};
         expect(bool(glz::read<glz::fix_opts{}>(x, b))) << bad;
      }
   };
};

suite quickfix_decimal = [] {
   using namespace qf_v2;
   "FieldConvertorsTestCase.cpp / doubleConvertFrom with glz::fix::decimal (exact)"_test = [] {
      auto val = [](std::string_view s, double& out) {
         glz::fix::decimal d{};
         const bool ok = glz::fix::parse_decimal(s, d);
         out = d.to_double();
         return ok;
      };
      double v{};
      expect(val("45.32", v) and v == 45.32);
      expect(val("45.3200", v) and v == 45.32);
      {
         // Exact representation; to_double() of 340244000e-11 is not correctly rounded to 0.00340244.
         glz::fix::decimal d{};
         expect(glz::fix::parse_decimal("0.00340244000", d) and d.mantissa == 340244000 and d.exponent == -11);
      }
      expect(val("-12.000000000001", v) and v == -12.000000000001);
      expect(val("0045.32", v) and v == 45.32);
      expect(val("000.06", v) and v == 0.06);
      expect(val("-0.00001", v) and v == -0.00001);
      expect(val("-1050", v) and v == -1050.0);
      // Rejected as by QuickFIX, including the exponent form that double accepts (divergence 2).
      for (auto bad : {"abc", "123.A", "123.45.67", "1e5", "+200", ""}) {
         glz::fix::decimal d{};
         expect(not glz::fix::parse_decimal(bad, d)) << bad;
      }
   };
   "FieldConvertorsTestCase.cpp / doubleConvertTo with glz::fix::decimal (no exponent, scale kept)"_test = [] {
      auto rt = [](std::string_view s) {
         glz::fix::decimal d{};
         std::string out;
         if (!glz::fix::parse_decimal(s, d)) return std::string("<bad>");
         glz::fix::append_decimal(out, d);
         return out;
      };
      expect(rt("0.00001") == "0.00001");
      expect(rt("-0.00001") == "-0.00001");
      expect(rt("100000000000000") == "100000000000000");
      expect(rt("45.3200") == "45.3200"); // scale kept as written
      expect(rt("1.500") == "1.500"); // doubleConvertTo(1.5, 3)
      const auto msg = make_msg("FIX.4.4", "35=U3|44=0.00001|");
      DecCarrier m{};
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(buf == msg) << buf;
   };
};
