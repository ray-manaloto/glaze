// Glaze Library
// For the license information refer to glaze.hpp

#include <optional>
#include <string>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

struct Party
{
   std::string id{};
   char source{};
   int role{};
};

template <>
struct glz::meta<Party>
{
   using T = Party;
   static constexpr auto value = glz::object("448", &T::id, "447", &T::source, "452", &T::role);
};

struct Leg
{
   std::string symbol{};
   double ratio{};
   std::vector<Party> parties{}; // nested group, NoNestedPartyIDs-style
};

template <>
struct glz::meta<Leg>
{
   using T = Leg;
   static constexpr auto value = glz::object("600", &T::symbol, "623", &T::ratio, "539", &T::parties);
};

struct NewOrderSingle
{
   std::string sender{};
   std::string target{};
   int seq{};
   std::string sending_time{}; // UTCTimestamp kept as text
   std::string cl_ord_id{};
   std::string symbol{};
   char side{};
   std::string transact_time{};
   double order_qty{};
   char ord_type{};
   std::optional<double> price{};
   bool locate_reqd{};
   std::optional<std::string> text{};
   std::vector<Party> parties{};
};

template <>
struct glz::meta<NewOrderSingle>
{
   using T = NewOrderSingle;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value =
      glz::object("49", &T::sender, "56", &T::target, "34", &T::seq, "52", &T::sending_time, "11", &T::cl_ord_id,
                  "55", &T::symbol, "54", &T::side, "60", &T::transact_time, "38", &T::order_qty, "40", &T::ord_type,
                  "44", &T::price, "114", &T::locate_reqd, "58", &T::text, "453", &T::parties);
};

struct Multileg
{
   std::string cl_ord_id{};
   std::vector<Leg> legs{};
   uint32_t qty{};
};

template <>
struct glz::meta<Multileg>
{
   using T = Multileg;
   static constexpr auto fix_msg_type = "AB";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "555", &T::legs, "38", &T::qty);
};

struct Heartbeat
{
   std::optional<std::string> test_req_id{};
};

template <>
struct glz::meta<Heartbeat>
{
   using T = Heartbeat;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};

enum class ExecType : char { new_ = '0', trade = 'F' };

// Read-only view type: string_view members point into the input buffer.
struct ExecView
{
   std::string_view order_id{};
   char ord_status{};
   ExecType exec_type{};
};

template <>
struct glz::meta<ExecView>
{
   using T = ExecView;
   static constexpr auto fix_msg_type = "8";
   static constexpr auto value = glz::object("37", &T::order_id, "39", &T::ord_status, "150", &T::exec_type);
};

// Raw-data fields: 95 RawDataLength announces the byte count of 96 RawData, which may hold SOH.
struct RawNote
{
   std::string headline{};
   std::string raw{}; // 96; its length tag 95 is written and consumed automatically
   std::vector<Party> parties{};
};

template <>
struct glz::meta<RawNote>
{
   using T = RawNote;
   static constexpr auto fix_msg_type = "B";
   static constexpr auto value = glz::object("148", &T::headline, "96", &T::raw, "453", &T::parties);
};

// Typed values: UTCTimestamp and exact decimals.
struct Quote
{
   glz::fix::utc_timestamp sending_time{};
   glz::fix::decimal bid_px{};
   std::optional<glz::fix::decimal> offer_px{};
};

template <>
struct glz::meta<Quote>
{
   using T = Quote;
   static constexpr auto fix_msg_type = "S";
   static constexpr auto value = glz::object("52", &T::sending_time, "132", &T::bid_px, "133", &T::offer_px);
};

static constexpr glz::fix_opts pipe = glz::fix::pipe_opts;

// Builds a pipe-delimited message with correct 9 and 10 around "35=...|body".
static std::string make_msg(std::string_view begin, std::string_view body)
{
   std::string m = "8=";
   m += begin;
   m += "|9=" + std::to_string(body.size()) + "|";
   m += body;
   const auto cs = glz::fix::checksum(m);
   char buf[8];
   std::snprintf(buf, sizeof(buf), "%03u", unsigned(cs));
   m += "10=";
   m += buf;
   m += "|";
   return m;
}

suite scanner = [] {
   "parse_fields"_test = [] {
      auto r = glz::fix::parse_fields("8=FIX.4.4|35=D|55=IBM|", '|');
      expect(r.has_value());
      expect(r->size() == 3u);
      expect((*r)[2].tag == 55u);
      expect((*r)[2].value == "IBM");
   };
   "soh_known_vector"_test = [] {
      // Same message with a real SOH (0x01) delimiter: 1298 - 3 * (0x7C - 0x01) = 929, 929 % 256 = 161.
      const std::string head = "8=FIX.4.2\x01" "9=5\x01" "35=0\x01";
      expect(glz::fix::checksum(head) == 161);
      expect(!glz::fix::validate(head + "10=161\x01"));
   };
   "parse_fields_soh"_test = [] {
      auto r = glz::fix::parse_fields("8=FIX.4.4\x01" "35=0\x01");
      expect(r.has_value() && r->size() == 2u);
   };
   "parse_fields_errors"_test = [] {
      expect(!glz::fix::parse_fields("8=FIX.4.4|35=D", '|').has_value()); // no trailing delimiter
      expect(!glz::fix::parse_fields("8=FIX.4.4|=D|", '|').has_value()); // empty tag
      expect(!glz::fix::parse_fields("8=FIX.4.4|3x=D|", '|').has_value()); // non-digit tag
      expect(!glz::fix::parse_fields("8=FIX.4.4|35=|", '|').has_value()); // empty value
      expect(!glz::fix::parse_fields("8=FIX.4.4|35D|", '|').has_value()); // no '='
      expect(!glz::fix::parse_fields("", '|').has_value());
   };
   "value_may_contain_equals"_test = [] {
      auto r = glz::fix::parse_fields("58=a=b|", '|');
      expect(r.has_value() && (*r)[0].value == "a=b");
   };
   "checksum"_test = [] {
      expect(glz::fix::checksum("") == 0);
      expect(glz::fix::checksum("A") == 65);
      expect(glz::fix::checksum(std::string(256, '\x01')) == 0);
      static_assert(glz::fix::checksum("AB") == 131);
   };
   "validate_ok"_test = [] {
      const auto m = make_msg("FIX.4.4", "35=0|49=A|56=B|");
      expect(!glz::fix::validate(m, '|'));
   };
   "validate_known_vector"_test = [] {
      // Hand-computed: body "35=0|" is 5 bytes; 8=FIX.4.2|9=5|35=0| sums to 1298, 1298 % 256 = 18
      // (with '|' as delimiter). Recomputed here to guard the arithmetic.
      const std::string head = "8=FIX.4.2|9=5|35=0|";
      expect(glz::fix::checksum(head) == 18) << int(glz::fix::checksum(head));
      expect(!glz::fix::validate(head + "10=018|", '|'));
   };
   "validate_errors"_test = [] {
      const auto m = make_msg("FIX.4.4", "35=0|49=A|");
      expect(glz::fix::validate("9=5|8=FIX.4.4|35=0|10=000|", '|') == glz::error_code::invalid_header);
      expect(glz::fix::validate("8=FIX.4.4|35=0|9=5|10=000|", '|') == glz::error_code::invalid_header);
      expect(glz::fix::validate("8=FIX.4.4|9=5|49=A|35=0|10=000|", '|') == glz::error_code::invalid_header);
      std::string bad_cs = m;
      bad_cs[bad_cs.size() - 2] = bad_cs[bad_cs.size() - 2] == '0' ? '1' : '0';
      auto e = glz::fix::validate(bad_cs, '|');
      expect(e == glz::error_code::invalid_body);
      expect(e.custom_error_message == "fix: CheckSum (10) mismatch");
      expect(!glz::fix::validate(bad_cs, '|', true, false)); // checksum check disabled
      std::string bad_len = m;
      bad_len.replace(bad_len.find("9=") + 2, 2, "99");
      e = glz::fix::validate(bad_len, '|', true, false);
      expect(e == glz::error_code::invalid_body);
      expect(e.custom_error_message == "fix: BodyLength (9) mismatch");
      expect(glz::fix::validate("8=FIX.4.4|9=5|35=0|", '|') == glz::error_code::invalid_body); // no 10
      expect(glz::fix::validate(m + "1=x|", '|') == glz::error_code::invalid_body); // 10 not last
      expect(glz::fix::validate("8=FIX.4.4|9=5|35=0|10=1|", '|', false, false) == glz::error_code::invalid_body);
   };
   "frame"_test = [] {
      const auto a = make_msg("FIX.4.4", "35=0|49=A|");
      const auto b = make_msg("FIX.4.4", "35=1|112=X|");
      const auto stream = a + b;
      expect(glz::fix::frame(stream, '|') == a.size());
      expect(glz::fix::frame(std::string_view{stream}.substr(a.size()), '|') == b.size());
      for (size_t n = 0; n < a.size(); ++n) {
         expect(glz::fix::frame(std::string_view{a}.substr(0, n), '|') == 0u) << n;
      }
      expect(glz::fix::frame("X=1|", '|') == glz::fix::frame_error);
      expect(glz::fix::frame("8=FIX.4.4|35=0|", '|') == glz::fix::frame_error);
      expect(glz::fix::frame("8=FIX.4.4|9=5|35=0|XX=000|", '|') == glz::fix::frame_error);
   };
};

suite struct_mapping = [] {
   "roundtrip_new_order_single"_test = [] {
      NewOrderSingle o{};
      o.sender = "CLIENT";
      o.target = "BROKER";
      o.seq = 215;
      o.sending_time = "20261105-07:00:00.123";
      o.cl_ord_id = "ORD-1";
      o.symbol = "IBM";
      o.side = '1';
      o.transact_time = "20261105-07:00:00";
      o.order_qty = 100;
      o.ord_type = '2';
      o.price = 123.25;
      o.locate_reqd = true;
      o.parties = {{"P1", 'D', 1}, {"P2", 'D', 3}};

      std::string buf;
      expect(!glz::write<pipe>(o, buf));
      expect(buf.starts_with("8=FIX.4.4|9=")) << buf;
      expect(buf.find("|35=D|49=CLIENT|56=BROKER|34=215|") != std::string::npos) << buf;
      expect(buf.find("|114=Y|") != std::string::npos);
      expect(buf.find("|44=123.25|") != std::string::npos);
      expect(buf.find("58=") == std::string::npos); // nullopt is not written
      expect(buf.find("|453=2|448=P1|447=D|452=1|448=P2|447=D|452=3|") != std::string::npos) << buf;
      expect(!glz::fix::validate(buf, '|')) << buf;

      NewOrderSingle r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.sender == "CLIENT");
      expect(r.seq == 215);
      expect(r.sending_time == o.sending_time);
      expect(r.side == '1');
      expect(r.order_qty == 100.0);
      expect(r.price.has_value() && *r.price == 123.25);
      expect(r.locate_reqd);
      expect(!r.text.has_value());
      expect(r.parties.size() == 2u);
      expect(r.parties[1].id == "P2" && r.parties[1].role == 3);
   };
   "default_soh"_test = [] {
      Heartbeat h{"TEST1"};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(h, buf));
      expect(buf.starts_with("8=FIX.4.2\x01" "9="));
      expect(!glz::fix::validate(buf));
      expect(glz::fix::frame(buf) == buf.size());
      Heartbeat r{};
      expect(!glz::read<glz::fix_opts{}>(r, buf));
      expect(r.test_req_id == "TEST1");
   };
   "exact_bytes"_test = [] {
      Heartbeat h{};
      std::string buf;
      expect(!glz::write<pipe>(h, buf));
      expect(buf == "8=FIX.4.2|9=5|35=0|10=018|") << buf;
   };
   "nested_groups"_test = [] {
      Multileg m{"ML1", {{"AAA", 1.5, {{"X", 'C', 7}}}, {"BBB", -2, {}}, {"CCC", 0.25, {{"Y", 'D', 1}, {"Z", 'D', 2}}}}, 10};
      std::string buf;
      expect(!glz::write<pipe>(m, buf));
      expect(buf.find("|555=3|600=AAA|623=1.5|539=1|448=X|447=C|452=7|600=BBB|623=-2|600=CCC|") !=
             std::string::npos)
         << buf;
      Multileg r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.cl_ord_id == "ML1");
      expect(r.qty == 10u); // field after the group goes back to the parent
      expect(r.legs.size() == 3u);
      expect(r.legs[0].parties.size() == 1u && r.legs[0].parties[0].role == 7);
      expect(r.legs[1].symbol == "BBB" && r.legs[1].ratio == -2.0 && r.legs[1].parties.empty());
      expect(r.legs[2].parties.size() == 2u && r.legs[2].parties[1].id == "Z");
   };
   "group_count_mismatch"_test = [] {
      Multileg r{};
      // says 2 entries, has 1
      auto m = make_msg("FIX.4.4", "35=AB|11=A|555=2|600=AAA|38=5|");
      expect(glz::read<pipe>(r, m) == glz::error_code::syntax_error);
      // group entry must start with its delimiter tag
      m = make_msg("FIX.4.4", "35=AB|11=A|555=1|623=1|600=AAA|");
      expect(glz::read<pipe>(r, m) == glz::error_code::syntax_error);
   };
   "unknown_tags"_test = [] {
      const auto m = make_msg("FIX.4.4", "35=AB|11=A|9999=zzz|38=5|");
      Multileg r{};
      expect(!glz::read<pipe>(r, m));
      expect(r.qty == 5u);
      static constexpr glz::fix_opts strict{{}, glz::FIX, '|', true, true, true};
      expect(glz::read<strict>(r, m) == glz::error_code::unknown_key);
   };
   "envelope_errors"_test = [] {
      Multileg r{};
      auto m = make_msg("FIX.4.4", "35=AB|11=A|");
      std::string bad = m;
      bad[bad.size() - 2] = bad[bad.size() - 2] == '0' ? '1' : '0';
      expect(glz::read<pipe>(r, bad) == glz::error_code::invalid_body);
      static constexpr glz::fix_opts no_cs{{}, glz::FIX, '|', false};
      expect(!glz::read<no_cs>(r, bad));
      expect(glz::read<pipe>(r, make_msg("FIX.4.4", "35=D|11=A|")) == glz::error_code::invalid_header);
   };
   "body_only"_test = [] {
      // Without tag 8 first, the input is treated as a body fragment: no envelope checks.
      Multileg r{};
      expect(!glz::read<pipe>(r, std::string_view{"11=Q|38=7|"}));
      expect(r.cl_ord_id == "Q" && r.qty == 7u);
   };
   "write_rejects_delimiter_in_value"_test = [] {
      Multileg m{"A|B", {}, 1};
      std::string buf;
      auto ec = glz::write<pipe>(m, buf);
      expect(ec == glz::error_code::syntax_error);
      expect(ec.custom_error_message == "fix: value contains the field delimiter");
   };
   "empty_values_not_written"_test = [] {
      Multileg m{"", {}, 3};
      std::string buf;
      expect(!glz::write<pipe>(m, buf));
      expect(buf.find("|11=") == std::string::npos);
      expect(buf.find("|38=3|") != std::string::npos);
   };
   "string_view_members_are_views"_test = [] {
      const auto m = make_msg("FIX.4.4", "35=8|37=EX-9|39=2|150=F|");
      ExecView v{};
      expect(!glz::read<pipe>(v, m));
      expect(v.order_id == "EX-9");
      expect(v.order_id.data() >= m.data() && v.order_id.data() < m.data() + m.size()); // zero copy
      expect(v.ord_status == '2');
      expect(v.exec_type == ExecType::trade);
   };
   "truncated_and_corrupted_inputs_fail_cleanly"_test = [] {
      Multileg m{"ML1", {{"AAA", 1.5, {{"X", 'C', 7}}}, {"BBB", 2, {}}}, 10};
      std::string full;
      expect(!glz::write<pipe>(m, full));
      for (size_t n = 1; n < full.size(); ++n) {
         Multileg r{};
         const std::string prefix = full.substr(0, n); // owned copy so sanitizers catch over-reads
         expect(bool(glz::read<pipe>(r, prefix))) << n;
         expect(glz::fix::frame(prefix, '|') == 0u) << n;
      }
      for (size_t i = 0; i < full.size(); ++i) {
         std::string bad = full;
         bad[i] = char(bad[i] ^ 0x20); // changes the byte sum by +-32, never a multiple of 256
         Multileg r{};
         expect(bool(glz::read<pipe>(r, bad))) << i; // the checksum catches every single-byte change
      }
   };
   "raw_data_scanner"_test = [] {
      // 96 holds the delimiter and an '=' ; 95 says it is 7 bytes long
      auto r = glz::fix::parse_fields("35=B|95=7|96=a|b=c|d|58=x|", '|');
      expect(r.has_value());
      expect(r->size() == 4u);
      expect((*r)[2].tag == 96u && (*r)[2].value == "a|b=c|d");
      expect((*r)[3].tag == 58u);
      expect(glz::fix::raw_data_tag_for(95) == 96u && glz::fix::raw_length_tag_for(96) == 95u);
      expect(glz::fix::raw_data_tag_for(212) == 213u && glz::fix::raw_data_tag_for(55) == 0u);
      // length disagrees with the data: byte 7 after "96=" is not the delimiter
      expect(!glz::fix::parse_fields("95=3|96=a|b=c|", '|').has_value());
      // length runs past the end
      expect(!glz::fix::parse_fields("95=30|96=abc|", '|').has_value());
      // length is not a number
      expect(!glz::fix::parse_fields("95=x|96=abc|", '|').has_value());
      // a length field not followed by its data field is an ordinary field
      r = glz::fix::parse_fields("95=3|58=abc|", '|');
      expect(r.has_value() && r->size() == 2u);
   };
   "raw_data_validate_and_frame"_test = [] {
      const auto m = make_msg("FIX.4.4", "35=B|95=5|96=1|2|3|");
      expect(!glz::fix::validate(m, '|')) << m;
      expect(glz::fix::frame(m + "8=FIX", '|') == m.size());
   };
   "raw_data_roundtrip"_test = [] {
      std::string raw = "bin";
      raw += '\x01';
      raw += "ary|with=delims";
      raw += '\0';
      raw += "end"; // 23 bytes holding SOH, '|', '=' and NUL
      RawNote n{"News", raw, {{"P", 'D', 1}}};
      std::string buf;
      expect(!glz::write<pipe>(n, buf));
      expect(buf.find("|95=23|96=bin") != std::string::npos) << buf;
      expect(!glz::fix::validate(buf, '|'));
      RawNote r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.raw == n.raw);
      expect(r.headline == "News" && r.parties.size() == 1u);
      // also with the real SOH delimiter
      buf.clear();
      expect(!glz::write<glz::fix_opts{}>(n, buf));
      RawNote r2{};
      expect(!glz::read<glz::fix_opts{}>(r2, buf));
      expect(r2.raw == n.raw);
      // a strict reader accepts the automatic length field
      static constexpr glz::fix_opts strict{{}, glz::FIX, '|', true, true, true};
      RawNote r3{};
      expect(!glz::read<strict>(r3, make_msg("FIX.4.4", "35=B|95=3|96=a|b|")));
      expect(r3.raw == "a|b");
   };
   "utc_timestamp"_test = [] {
      using namespace std::chrono;
      glz::fix::utc_timestamp t{};
      expect(glz::fix::parse_utc_timestamp("20261105-07:30:59.123456789", t));
      expect(t.precision == 9);
      const auto day = sys_days{year{2026} / November / 5};
      expect(t.time == day + 7h + 30min + 59s + 123456789ns);
      std::string out;
      glz::fix::append_utc_timestamp(out, t);
      expect(out == "20261105-07:30:59.123456789") << out;
      t.precision = 3;
      out.clear();
      glz::fix::append_utc_timestamp(out, t);
      expect(out == "20261105-07:30:59.123") << out; // truncated, not rounded
      t.precision = 0;
      out.clear();
      glz::fix::append_utc_timestamp(out, t);
      expect(out == "20261105-07:30:59");
      expect(glz::fix::parse_utc_timestamp("20240229-00:00:00", t) && t.precision == 0); // leap day
      expect(glz::fix::parse_utc_timestamp("19691231-23:59:59.5", t) && t.precision == 1); // before epoch
      out.clear();
      glz::fix::append_utc_timestamp(out, t);
      expect(out == "19691231-23:59:59.5") << out;
      expect(!glz::fix::parse_utc_timestamp("20230229-00:00:00", t)); // not a leap year
      expect(!glz::fix::parse_utc_timestamp("20261305-00:00:00", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-24:00:00", t));
      expect(!glz::fix::parse_utc_timestamp("20261105 07:30:59", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-07:30:59.", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-07:30:59.1234567890", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-07:30", t));
   };
   "decimal"_test = [] {
      glz::fix::decimal d{};
      expect(glz::fix::parse_decimal("123.4500", d));
      expect(d.mantissa == 1234500 && d.exponent == -4);
      expect(d.to_double() == 123.45);
      auto text = [](glz::fix::decimal x) {
         std::string s;
         glz::fix::append_decimal(s, x);
         return s;
      };
      expect(text(d) == "123.4500");
      expect(glz::fix::parse_decimal("-0.001", d) && d.mantissa == -1 && d.exponent == -3);
      expect(text(d) == "-0.001") << text(d);
      expect(glz::fix::parse_decimal("42", d) && d.exponent == 0 && text(d) == "42");
      expect(glz::fix::parse_decimal(".5", d) && text(d) == "0.5");
      expect(glz::fix::parse_decimal("5.", d) && d.mantissa == 5 && d.exponent == 0);
      expect(text({15, 2}) == "1500");
      expect(text({0, -2}) == "0.00");
      expect(text({INT64_MIN, -1}) == "-922337203685477580.8");
      expect(glz::fix::parse_decimal("999999999999999999", d)); // 18 digits
      expect(!glz::fix::parse_decimal("1234567890123456789", d)); // 19 digits
      expect(!glz::fix::parse_decimal("1.2.3", d));
      expect(!glz::fix::parse_decimal("-", d));
      expect(!glz::fix::parse_decimal("+1", d));
      expect(!glz::fix::parse_decimal("1e5", d));
      expect(!glz::fix::parse_decimal("", d));
   };
   "typed_values_roundtrip"_test = [] {
      Quote q{};
      expect(glz::fix::parse_utc_timestamp("20261105-07:30:00.250", q.sending_time));
      q.bid_px = {10025, -2};
      std::string buf;
      expect(!glz::write<pipe>(q, buf));
      expect(buf.find("|52=20261105-07:30:00.250|132=100.25|") != std::string::npos) << buf;
      expect(buf.find("133=") == std::string::npos);
      Quote r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.sending_time == q.sending_time);
      expect(r.bid_px == q.bid_px);
      expect(!r.offer_px.has_value());
      expect(glz::read<pipe>(r, std::string_view{"133=1.0|"}) == glz::error_code::none);
      expect(r.offer_px && r.offer_px->mantissa == 10 && r.offer_px->exponent == -1);
      expect(glz::read<pipe>(r, std::string_view{"132=1,5|"}) == glz::error_code::parse_number_failure);
      expect(glz::read<pipe>(r, std::string_view{"52=2026-11-05|"}) == glz::error_code::syntax_error);
   };
   "field_cursor"_test = [] {
      constexpr std::string_view msg = "8=FIX.4.4|9=5|35=0|95=3|96=a|b|10=000|";
      glz::fix::field_cursor c{msg, '|'};
      std::vector<uint32_t> tags;
      for (glz::fix::field f; c.next(f);) tags.push_back(f.tag);
      expect(!c.error());
      expect(c.done());
      expect(tags == std::vector<uint32_t>{8, 9, 35, 95, 96, 10});
      // usable in constant expressions, so it cannot allocate
      static_assert([] {
         glz::fix::field_cursor k{"35=D|55=IBM|", '|'};
         glz::fix::field f{};
         return k.next(f) && f.tag == 35 && k.next(f) && f.value == "IBM" && !k.next(f);
      }());
      glz::fix::field_cursor bad{"35=D|5x=1|55=A|", '|'};
      glz::fix::field f{};
      expect(bad.next(f));
      expect(!bad.next(f));
      expect(bad.error() == glz::error_code::syntax_error);
      expect(bad.error().count == 5u); // offset of the bad field
      expect(!bad.next(f)); // stays stopped
   };
   "for_each_field"_test = [] {
      size_t n = 0;
      std::string_view sym{};
      auto e = glz::fix::for_each_field("35=D|55=IBM|54=1|", '|', [&](const glz::fix::field& f) {
         ++n;
         if (f.tag == 55) sym = f.value;
      });
      expect(!e && n == 3u && sym == "IBM");
      n = 0;
      e = glz::fix::for_each_field("35=D|55=IBM|54=1|", '|', [&](const glz::fix::field& f) {
         ++n;
         return f.tag != 55; // stop at 55
      });
      expect(!e && n == 2u);
      e = glz::fix::for_each_field("35=D|55=IBM", '|', [](const glz::fix::field&) {});
      expect(e == glz::error_code::unexpected_end);
   };
   "huge_group_count_rejected"_test = [] {
      Multileg r{};
      expect(glz::read<pipe>(r, std::string_view{"555=4000000000|600=A|"}) == glz::error_code::parse_number_failure);
      expect(glz::read<pipe>(r, std::string_view{"555=99999999|600=A|"}) == glz::error_code::syntax_error);
   };
   "value_errors"_test = [] {
      NewOrderSingle r{};
      expect(glz::read<pipe>(r, std::string_view{"114=X|"}) == glz::error_code::expected_true_or_false);
      expect(glz::read<pipe>(r, std::string_view{"34=12a|"}) == glz::error_code::parse_number_failure);
      expect(glz::read<pipe>(r, std::string_view{"54=12|"}) == glz::error_code::syntax_error);
      Multileg m{};
      expect(glz::read<pipe>(m, std::string_view{"38=-1|"}) == glz::error_code::parse_number_failure);
      expect(glz::read<pipe>(r, std::string_view{"114=N|44=1.5e2|"}) == glz::error_code::none);
      expect(!r.locate_reqd && *r.price == 150.0);
   };
};

int main() { return 0; }
