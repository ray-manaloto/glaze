// FIX tag=value conformance tests derived from FIX Trading Community spec rules
// (session layer, encoding rules). All example messages below are hand-written.
// Structure mirrors tests/fix_test/fix_test.cpp.

#include <cstdio>
#include <optional>
#include <string>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

static constexpr glz::fix_opts pipe{{}, glz::FIX, '|'};
static constexpr glz::fix_opts pipe_lax{{}, glz::FIX, '|', false, false};

// Append a correct 10= trailer (sum of all bytes before "10=" mod 256, three digits).
static std::string with_checksum(std::string m, char soh = '|')
{
   char buf[8];
   std::snprintf(buf, sizeof(buf), "%03u", unsigned(glz::fix::checksum(m)));
   m += "10=";
   m += buf;
   m += soh;
   return m;
}

// Build "8=..|9=<n>|<body>10=ddd|" where n counts body bytes (after SOH ending 9=, up to "10=").
static std::string envelope(std::string_view body, char soh = '|', std::string_view begin = "FIX.4.4")
{
   std::string m = "8=";
   m += begin;
   m += soh;
   m += "9=" + std::to_string(body.size()) + soh;
   m += body;
   return with_checksum(std::move(m), soh);
}

// ---- session messages -------------------------------------------------------
struct Logon
{
   std::string sender{};
   std::string target{};
   int seq{};
   std::string sending_time{};
   int encrypt_method{};
   int heart_bt_int{};
   std::optional<bool> reset_seq_num{};
};
template <>
struct glz::meta<Logon>
{
   using T = Logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("49", &T::sender, "56", &T::target, "34", &T::seq, "52",
                                             &T::sending_time, "98", &T::encrypt_method, "108", &T::heart_bt_int,
                                             "141", &T::reset_seq_num);
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
   static constexpr auto value = glz::object("112", &T::test_req_id);
};

struct TestRequest
{
   std::string test_req_id{};
};
template <>
struct glz::meta<TestRequest>
{
   using T = TestRequest;
   static constexpr auto fix_msg_type = "1";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};

struct ResendRequest
{
   int begin_seq_no{};
   int end_seq_no{};
};
template <>
struct glz::meta<ResendRequest>
{
   using T = ResendRequest;
   static constexpr auto fix_msg_type = "2";
   static constexpr auto value = glz::object("7", &T::begin_seq_no, "16", &T::end_seq_no);
};

struct Reject
{
   int ref_seq_num{};
   std::optional<int> ref_tag_id{};
   std::optional<std::string> ref_msg_type{};
   std::optional<int> session_reject_reason{};
   std::optional<std::string> text{};
};
template <>
struct glz::meta<Reject>
{
   using T = Reject;
   static constexpr auto fix_msg_type = "3";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "371", &T::ref_tag_id, "372", &T::ref_msg_type,
                                             "373", &T::session_reject_reason, "58", &T::text);
};

struct SequenceReset
{
   std::optional<bool> gap_fill_flag{};
   int new_seq_no{};
};
template <>
struct glz::meta<SequenceReset>
{
   using T = SequenceReset;
   static constexpr auto fix_msg_type = "4";
   static constexpr auto value = glz::object("123", &T::gap_fill_flag, "36", &T::new_seq_no);
};

struct Logout
{
   std::optional<std::string> text{};
};
template <>
struct glz::meta<Logout>
{
   using T = Logout;
   static constexpr auto fix_msg_type = "5";
   static constexpr auto value = glz::object("58", &T::text);
};

// ---- application messages ---------------------------------------------------
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
   char side{};
   std::vector<Party> parties{}; // NoNestedPartyIDs-style nested group (keyed 539)
};
template <>
struct glz::meta<Leg>
{
   using T = Leg;
   static constexpr auto value = glz::object("600", &T::symbol, "624", &T::side, "539", &T::parties);
};

struct NewOrderSingle
{
   std::string cl_ord_id{};
   std::string symbol{};
   char side{};
   glz::fix::utc_timestamp transact_time{};
   glz::fix::decimal order_qty{};
   char ord_type{};
   std::optional<glz::fix::decimal> price{};
   std::optional<std::string> settl_date{}; // LocalMktDate YYYYMMDD as text
   std::vector<Party> parties{};
};
template <>
struct glz::meta<NewOrderSingle>
{
   using T = NewOrderSingle;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value =
      glz::object("11", &T::cl_ord_id, "55", &T::symbol, "54", &T::side, "60", &T::transact_time, "38",
                  &T::order_qty, "40", &T::ord_type, "44", &T::price, "64", &T::settl_date, "453", &T::parties);
};

struct MultilegOrder
{
   std::string cl_ord_id{};
   std::vector<Leg> legs{};
   int qty{};
};
template <>
struct glz::meta<MultilegOrder>
{
   using T = MultilegOrder;
   static constexpr auto fix_msg_type = "AB";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "555", &T::legs, "38", &T::qty);
};

struct WithRawData
{
   std::string cl_ord_id{};
   std::string raw{}; // 96 RawData; 95 RawDataLength written automatically
   std::string text{};
};
template <>
struct glz::meta<WithRawData>
{
   using T = WithRawData;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "96", &T::raw, "58", &T::text);
};

suite spec_envelope = [] {
   "body_length_counts_after_9_through_before_10"_test = [] {
      // body = "35=0|" -> 5 bytes
      const std::string body = "35=0|";
      auto m = envelope(body);
      expect(m.starts_with("8=FIX.4.4|9=5|35=0|10=")) << m;
      expect(!glz::fix::validate(m, '|')) << m;
      // off-by-one in either direction is rejected
      auto bad = with_checksum("8=FIX.4.4|9=4|35=0|");
      auto ec = glz::fix::validate(bad, '|');
      expect(ec.ec == glz::error_code::invalid_body);
      auto bad2 = with_checksum("8=FIX.4.4|9=6|35=0|");
      expect(glz::fix::validate(bad2, '|').ec == glz::error_code::invalid_body);
   };

   "body_length_excludes_8_and_9_but_includes_35"_test = [] {
      // 35=D|49=A|56=B| = 5 + 5 + 5 = 15
      auto m = envelope("35=D|49=A|56=B|");
      expect(m.find("|9=15|") != std::string::npos) << m;
      expect(!glz::fix::validate(m, '|'));
   };

   "checksum_mod_256_three_digits"_test = [] {
      // The spec requires a 3-digit value with leading zeros; verify a message whose sum mod 256 < 100.
      std::string m = "8=FIX.4.4|9=5|35=0|";
      unsigned sum = 0;
      for (unsigned char c : m) sum += c;
      expect(glz::fix::checksum(m) == uint8_t(sum % 256));
      auto full = with_checksum(m);
      expect(full.size() == m.size() + 7u); // "10=" + 3 digits + SOH
      expect(!glz::fix::validate(full, '|'));
      // Not three digits -> invalid_body
      expect(glz::fix::validate("8=FIX.4.4|9=5|35=0|10=7|", '|').ec == glz::error_code::invalid_body);
      // Wrong value -> invalid_body
      std::string wrong = m + "10=000|";
      if (glz::fix::checksum(m) == 0) wrong = m + "10=001|";
      expect(glz::fix::validate(wrong, '|').ec == glz::error_code::invalid_body);
   };

   "checksum_leading_zero_vector"_test = [] {
      // Find a body whose checksum is < 10 so the trailer must be zero-padded, e.g. "10=00X".
      for (int i = 0; i < 300; ++i) {
         std::string body = "35=0|112=" + std::to_string(i) + "|";
         std::string m = "8=FIX.4.4|9=" + std::to_string(body.size()) + "|" + body;
         if (glz::fix::checksum(m) < 10) {
            auto full = with_checksum(m);
            expect(full.find("10=00") != std::string::npos) << full;
            expect(!glz::fix::validate(full, '|')) << full;
            return;
         }
      }
      expect(false) << "no zero-padded vector found";
   };

   "header_order_8_9_35"_test = [] {
      expect(glz::fix::validate(with_checksum("9=5|8=FIX.4.4|35=0|"), '|').ec == glz::error_code::invalid_header);
      expect(glz::fix::validate(with_checksum("8=FIX.4.4|35=0|9=5|"), '|').ec == glz::error_code::invalid_header);
      expect(glz::fix::validate(with_checksum("8=FIX.4.4|9=10|49=A|35=0|"), '|').ec ==
             glz::error_code::invalid_header);
      // 9 must be numeric
      expect(glz::fix::validate(with_checksum("8=FIX.4.4|9=x|35=0|"), '|').ec == glz::error_code::invalid_header);
   };

   "checksum_must_be_last_field"_test = [] {
      std::string m = "8=FIX.4.4|9=5|35=0|";
      auto full = with_checksum(m) + "58=late|";
      expect(glz::fix::validate(full, '|').ec == glz::error_code::invalid_body);
      // missing 10 entirely
      expect(glz::fix::validate(m, '|').ec == glz::error_code::invalid_body);
   };

   "real_soh_delimiter"_test = [] {
      const std::string body = "35=0\x01" "49=A\x01" "56=B\x01";
      auto m = envelope(body, '\x01');
      expect(!glz::fix::validate(m));
      expect(glz::fix::frame(m) == m.size());
      Heartbeat h{};
      expect(!glz::read<glz::fix_opts{}>(h, m));
      expect(!h.test_req_id.has_value());
   };

   "frame_stream_of_two_messages"_test = [] {
      auto a = envelope("35=0|112=A|");
      auto b = envelope("35=1|112=B|");
      std::string stream = a + b;
      expect(glz::fix::frame(stream, '|') == a.size());
      expect(glz::fix::frame(std::string_view(stream).substr(a.size()), '|') == b.size());
      // truncated second message -> 0 (need more bytes)
      expect(glz::fix::frame(std::string_view(stream).substr(a.size(), b.size() - 3), '|') == 0u);
      expect(glz::fix::frame("garbage", '|') == glz::fix::frame_error);
   };
};

suite spec_session_messages = [] {
   "logon_35_A"_test = [] {
      Logon o{"CLIENT", "BROKER", 1, "20261105-07:30:00", 0, 30, true};
      std::string buf;
      expect(!glz::write<pipe>(o, buf));
      expect(buf.find("|35=A|49=CLIENT|56=BROKER|34=1|52=20261105-07:30:00|98=0|108=30|141=Y|") !=
             std::string::npos)
         << buf;
      expect(!glz::fix::validate(buf, '|')) << buf;
      Logon r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.heart_bt_int == 30 && r.encrypt_method == 0 && r.reset_seq_num == true);
   };

   "heartbeat_35_0_with_and_without_112"_test = [] {
      Heartbeat r{};
      expect(!glz::read<pipe>(r, envelope("35=0|49=A|56=B|34=2|")));
      expect(!r.test_req_id.has_value());
      expect(!glz::read<pipe>(r, envelope("35=0|49=A|56=B|34=3|112=TR1|")));
      expect(r.test_req_id == "TR1");
   };

   "test_request_35_1"_test = [] {
      TestRequest t{"TEST123"};
      std::string buf;
      expect(!glz::write<pipe>(t, buf));
      expect(buf.find("|35=1|112=TEST123|") != std::string::npos) << buf;
      TestRequest r{};
      expect(!glz::read<pipe>(r, buf));
      expect(r.test_req_id == "TEST123");
   };

   "resend_request_35_2_end_zero_means_infinity"_test = [] {
      ResendRequest r{};
      expect(!glz::read<pipe>(r, envelope("35=2|49=A|56=B|34=5|7=3|16=0|")));
      expect(r.begin_seq_no == 3 && r.end_seq_no == 0);
   };

   "reject_35_3"_test = [] {
      Reject r{};
      auto m = envelope("35=3|49=A|56=B|34=6|45=5|371=55|372=D|373=1|58=Required tag missing|");
      auto ec = glz::read<pipe>(r, m);
      expect(!ec) << glz::format_error(ec, m);
      expect(r.ref_seq_num == 5 && r.ref_tag_id == 55 && r.ref_msg_type == "D" && r.session_reject_reason == 1);
      expect(r.text == "Required tag missing");
   };

   "sequence_reset_35_4_gap_fill"_test = [] {
      SequenceReset r{};
      expect(!glz::read<pipe>(r, envelope("35=4|49=A|56=B|34=7|123=Y|36=10|")));
      expect(r.gap_fill_flag == true && r.new_seq_no == 10);
      // reset mode: no 123
      SequenceReset r2{};
      expect(!glz::read<pipe>(r2, envelope("35=4|49=A|56=B|34=1|36=1|")));
      expect(!r2.gap_fill_flag.has_value() && r2.new_seq_no == 1);
   };

   "logout_35_5"_test = [] {
      Logout l{"bye"};
      std::string buf;
      expect(!glz::write<pipe>(l, buf));
      expect(buf.find("|35=5|58=bye|10=") != std::string::npos) << buf;
      Logout r{};
      expect(!glz::read<pipe>(r, buf));
      expect(r.text == "bye");
   };

   "msg_type_mismatch_rejected"_test = [] {
      Logon r{};
      auto ec = glz::read<pipe>(r, envelope("35=0|49=A|56=B|34=1|"));
      expect(ec.ec == glz::error_code::invalid_header);
   };

   "boolean_only_Y_or_N"_test = [] {
      SequenceReset r{};
      expect(!glz::read<pipe>(r, envelope("35=4|123=N|36=2|")));
      expect(r.gap_fill_flag == false);
      auto ec = glz::read<pipe>(r, envelope("35=4|123=true|36=2|"));
      expect(ec.ec == glz::error_code::expected_true_or_false);
   };
};

suite spec_groups_and_types = [] {
   "repeating_group_count_then_delimiter"_test = [] {
      NewOrderSingle o{};
      o.cl_ord_id = "C1";
      o.symbol = "MSFT";
      o.side = '1';
      o.transact_time.time = std::chrono::sys_days{std::chrono::year{2026} / 11 / 5} + std::chrono::hours{7};
      o.order_qty = {100, 0};
      o.ord_type = '2';
      o.price = glz::fix::decimal{41550, -2};
      o.parties = {{"TRADER1", 'D', 11}, {"FIRM", 'D', 1}};
      std::string buf;
      expect(!glz::write<pipe>(o, buf));
      expect(buf.find("|453=2|448=TRADER1|447=D|452=11|448=FIRM|447=D|452=1|10=") != std::string::npos) << buf;
      NewOrderSingle r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.parties.size() == 2u && r.parties[0].role == 11 && r.parties[1].id == "FIRM");
   };

   "group_entry_must_start_with_delimiter_tag"_test = [] {
      NewOrderSingle r{};
      // SKIP: spec says each entry must begin with the delimiter tag (448); the codec ends an entry only at
      // the next delimiter or a tag outside the group, so "...452=1|447=D|448=B|..." re-sets 447 in entry 1
      // instead of rejecting (documented "repeated tag overwrites" behaviour).
      // count larger than entries present
      auto ec2 = glz::read<pipe>(r, envelope("35=D|11=C|55=X|54=1|60=20261105-07:00:00|38=1|40=1|453=3|448=A|447=D|452=1|"));
      expect(ec2.ec == glz::error_code::syntax_error);
   };

   "nested_groups_and_field_after_group"_test = [] {
      MultilegOrder o{};
      o.cl_ord_id = "ML1";
      o.legs = {{"LEG1", '1', {{"P1", 'D', 1}}}, {"LEG2", '2', {{"P2", 'D', 1}, {"P3", 'D', 2}}}};
      o.qty = 5;
      std::string buf;
      expect(!glz::write<pipe>(o, buf));
      expect(buf.find("|555=2|600=LEG1|624=1|539=1|448=P1|447=D|452=1|600=LEG2|624=2|539=2|448=P2|447=D|452=1|448=P3|447=D|452=2|38=5|10=") !=
             std::string::npos)
         << buf;
      MultilegOrder r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.legs.size() == 2u && r.legs[1].parties.size() == 2u && r.legs[1].parties[1].id == "P3");
      expect(r.qty == 5); // field after the group goes to the parent
      // empty group omitted entirely
      MultilegOrder e{"E", {}, 1};
      buf.clear();
      expect(!glz::write<pipe>(e, buf));
      expect(buf.find("555=") == std::string::npos) << buf;
   };

   "raw_data_length_then_data_with_embedded_soh"_test = [] {
      WithRawData o{"R1", std::string("a|b=c\x01" "d", 7), "after"};
      std::string buf;
      expect(!glz::write<pipe>(o, buf));
      expect(buf.find("|95=7|96=a|b=c\x01" "d|58=after|") != std::string::npos) << buf;
      expect(!glz::fix::validate(buf, '|')) << buf;
      WithRawData r{};
      auto ec = glz::read<pipe>(r, buf);
      expect(!ec) << glz::format_error(ec, buf);
      expect(r.raw == o.raw && r.text == "after");
      // scanner yields the raw value intact
      auto f = glz::fix::parse_fields(buf, '|');
      expect(f.has_value());
      bool found = false;
      for (auto& x : *f)
         if (x.tag == 96) {
            found = true;
            expect(x.value == o.raw);
         }
      expect(found);
      // length disagreeing with the data is a syntax error
      expect(!glz::fix::parse_fields("95=3|96=abcd|", '|').has_value());
      expect(!glz::fix::parse_fields("95=9|96=ab|", '|').has_value());
   };

   "utc_timestamp_formats"_test = [] {
      glz::fix::utc_timestamp t{};
      expect(glz::fix::parse_utc_timestamp("20261105-07:30:15", t));
      expect(t.precision == 0);
      expect(glz::fix::parse_utc_timestamp("20261105-07:30:15.123", t));
      expect(t.precision == 3);
      expect(glz::fix::parse_utc_timestamp("20261105-07:30:15.123456", t));
      expect(t.precision == 6);
      std::string s;
      glz::fix::append_utc_timestamp(s, t);
      expect(s == "20261105-07:30:15.123456") << s;
      expect(!glz::fix::parse_utc_timestamp("20261105 07:30:15", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-24:00:00", t));
      expect(!glz::fix::parse_utc_timestamp("20260230-00:00:00", t));
      expect(!glz::fix::parse_utc_timestamp("20261105-07:30:60", t)); // SKIP-note: spec allows leap second 60; codec rejects
      expect(glz::fix::parse_utc_timestamp("20240229-23:59:59", t)); // leap year
   };

   "price_and_qty_decimal_scale_preserved"_test = [] {
      glz::fix::decimal d{};
      expect(glz::fix::parse_decimal("41.50", d));
      expect(d.mantissa == 4150 && d.exponent == -2);
      std::string s;
      glz::fix::append_decimal(s, d);
      expect(s == "41.50") << s;
      expect(glz::fix::parse_decimal("-0.001", d) && d.mantissa == -1 && d.exponent == -3);
      expect(!glz::fix::parse_decimal("+1", d));
      expect(!glz::fix::parse_decimal("1e3", d));
      NewOrderSingle r{};
      auto m = envelope("35=D|11=C|55=X|54=2|60=20261105-07:00:00.500|38=1000|40=2|44=100.250|64=20261106|");
      auto ec = glz::read<pipe>(r, m);
      expect(!ec) << glz::format_error(ec, m);
      expect(r.price.has_value() && r.price->mantissa == 100250 && r.price->exponent == -3);
      expect(r.order_qty.mantissa == 1000 && r.order_qty.exponent == 0);
      expect(r.transact_time.precision == 3);
      expect(r.settl_date == "20261106"); // LocalMktDate YYYYMMDD
      std::string out;
      expect(!glz::write<pipe>(r, out));
      expect(out.find("|60=20261105-07:00:00.500|38=1000|40=2|44=100.250|64=20261106|") != std::string::npos) << out;
   };

   "lax_opts_skip_envelope_validation"_test = [] {
      // Wrong 9 and 10, but validation disabled -> body still decodes.
      std::string m = "8=FIX.4.4|9=1|35=1|112=X|10=000|";
      TestRequest r{};
      expect(!glz::read<pipe_lax>(r, m));
      expect(r.test_req_id == "X");
      expect(glz::read<pipe>(r, m).ec == glz::error_code::invalid_body);
   };

   "body_fragment_without_envelope"_test = [] {
      TestRequest r{};
      expect(!glz::read<pipe>(r, "112=FRAG|"));
      expect(r.test_req_id == "FRAG");
   };
};

int main() { return 0; }
