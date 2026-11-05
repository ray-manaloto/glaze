// Glaze Library
// For the license information refer to glaze.hpp

// More cases from fixpp (https://github.com/Abc-Arbitrage/fixpp, MIT, licence in LICENSE-fixpp):
// struct reads of the visitor_test.cc frames (nested groups, incremental refresh, logon with
// Boolean, multi-character MsgType), the writer_test.cc heartbeat for FIX.4.2 and FIX.4.4,
// malformed repeating groups, and Quote (35=S) messages from tests/data/fix42.log, all read
// and then round-tripped through fix/core's glz::write / glz::read.
// Frames are '|' separated; repair() rebuilds 9 and 10 because fixpp's frames carry placeholders.

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
   constexpr char sep = '|';

   std::string repair2(std::string_view frame)
   {
      std::string f(frame);
      if (f.empty() || f.back() != sep) f += sep;
      const size_t e8 = f.find(sep);
      const size_t e9 = f.find(sep, e8 + 1);
      const size_t t10 = f.rfind("|10=");
      std::string body = f.substr(e9 + 1, t10 + 1 - (e9 + 1));
      std::string out = f.substr(0, e8 + 1) + "9=" + std::to_string(body.size()) + sep + body;
      std::string cs = std::to_string(glz::fix::checksum(out));
      while (cs.size() < 3) cs.insert(cs.begin(), '0');
      out += "10=" + cs + sep;
      return out;
   }

   std::string read_data(const char* name)
   {
      std::string path = std::string(FIX_TEST_DATA_DIR) + "/" + name;
      std::string out;
      std::FILE* f = std::fopen(path.c_str(), "rb");
      if (!f) return out;
      char buf[4096];
      size_t n;
      while ((n = std::fread(buf, 1, sizeof(buf), f)) > 0) out.append(buf, n);
      std::fclose(f);
      return out;
   }

   constexpr glz::fix_opts pipe_lenient()
   {
      glz::fix_opts o{};
      o.soh = '|';
      return o;
   }

   constexpr glz::fix_opts pipe_strict()
   {
      glz::fix_opts o{};
      o.soh = '|';
      o.error_on_unknown_tags = true; // fix/core's strict switch (default false: unknown tags skipped)
      return o;
   }
}

// ---- nested groups (visitor_test.cc: should_visit_nested_repeating_groups) ----
struct fp_alt_id
{
   std::string id{};
   std::string source{};
};
template <>
struct glz::meta<fp_alt_id>
{
   using T = fp_alt_id;
   static constexpr auto value = glz::object("458", &T::id, "459", &T::source);
};

struct fp_underlying
{
   std::string symbol{};
   std::vector<fp_alt_id> alt_ids{};
   int product{};
};
template <>
struct glz::meta<fp_underlying>
{
   using T = fp_underlying;
   static constexpr auto value = glz::object("311", &T::symbol, "457", &T::alt_ids, "462", &T::product);
};

struct fp_md_entry
{
   char type{};
   double size{};
   std::string date{};
   std::string quote_entry_id{};
};
template <>
struct glz::meta<fp_md_entry>
{
   using T = fp_md_entry;
   static constexpr auto value =
      glz::object("269", &T::type, "271", &T::size, "272", &T::date, "299", &T::quote_entry_id);
};

struct fp_nested_snapshot
{
   std::string sender{};
   std::string target{};
   std::string symbol{};
   std::string md_req_id{};
   std::vector<fp_underlying> underlyings{};
   char corporate_action{};
   std::vector<fp_md_entry> entries{};
};
template <>
struct glz::meta<fp_nested_snapshot>
{
   using T = fp_nested_snapshot;
   static constexpr auto fix_msg_type = "W";
   static constexpr auto value =
      glz::object("49", &T::sender, "56", &T::target, "55", &T::symbol, "262", &T::md_req_id, "711", &T::underlyings,
                  "292", &T::corporate_action, "268", &T::entries);
};

// ---- incremental refresh (visitor_test.cc: should_visit_incremental_refresh_frame) ----
struct fp_inc_entry
{
   char update_action{};
   std::string symbol{};
   char type{};
   std::string entry_id{};
   double px{};
   double size{};
   std::string currency{};
};
template <>
struct glz::meta<fp_inc_entry>
{
   using T = fp_inc_entry;
   static constexpr auto value = glz::object("279", &T::update_action, "55", &T::symbol, "269", &T::type, "278",
                                             &T::entry_id, "270", &T::px, "271", &T::size, "15", &T::currency);
};

struct fp_incremental
{
   uint64_t seq{};
   std::string sending_time{};
   std::string sender{};
   std::string target{};
   std::string md_req_id{};
   std::vector<fp_inc_entry> entries{};
};
template <>
struct glz::meta<fp_incremental>
{
   using T = fp_incremental;
   static constexpr auto fix_msg_type = "X";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("34", &T::seq, "52", &T::sending_time, "49", &T::sender, "56", &T::target,
                                             "262", &T::md_req_id, "268", &T::entries);
};

// ---- logon with Boolean and data (visitor_test.cc: should_visit_logon_frame) ----
struct fp_logon
{
   int seq{};
   std::string sender{};
   std::string sending_time{};
   std::string target{};
   std::string raw_data{};
   int encrypt_method{};
   int heart_bt_int{};
   std::optional<bool> reset_seq_num{};
};
template <>
struct glz::meta<fp_logon>
{
   using T = fp_logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value =
      glz::object("34", &T::seq, "49", &T::sender, "52", &T::sending_time, "56", &T::target, "96", &T::raw_data, "98",
                  &T::encrypt_method, "108", &T::heart_bt_int, "141", &T::reset_seq_num);
};

// ---- heartbeat (writer_test.cc: should_write_heartbeat_message_42 / _44) ----
struct fp_heartbeat42
{
   std::string sender{};
   std::string target{};
   std::string test_req_id{};
};
template <>
struct glz::meta<fp_heartbeat42>
{
   using T = fp_heartbeat42;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("49", &T::sender, "56", &T::target, "112", &T::test_req_id);
};
struct fp_heartbeat44
{
   std::string sender{};
   std::string target{};
   std::string test_req_id{};
};
template <>
struct glz::meta<fp_heartbeat44>
{
   using T = fp_heartbeat44;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto value = glz::object("49", &T::sender, "56", &T::target, "112", &T::test_req_id);
};

// ---- multi-character MsgType (visitor_test.cc: should_visit_message_with_multiple_chars_message_type) ----
struct fp_user_response
{
   std::string user_request_id{};
   int user_status{};
   std::string username{};
};
template <>
struct glz::meta<fp_user_response>
{
   using T = fp_user_response;
   static constexpr auto fix_msg_type = "BF";
   static constexpr auto value = glz::object("923", &T::user_request_id, "924", &T::user_status, "553", &T::username);
};

// ---- Quote (35=S) from tests/data/fix42.log ----
struct fp_quote
{
   std::string sender{};
   std::string target{};
   uint64_t seq{};
   std::string sending_time{};
   std::string on_behalf_of{};
   std::string deliver_to_sub_id{};
   std::string symbol{};
   std::string transact_time{};
   char settl_type{};
   std::string settl_date{};
   std::string quote_id{};
   std::string quote_req_id{};
   double bid_px{};
   double offer_px{};
   double bid_size{};
   double offer_size{};
   int quote_request_type{};
   int quote_type{};
};
template <>
struct glz::meta<fp_quote>
{
   using T = fp_quote;
   static constexpr auto fix_msg_type = "S";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object(
      "49", &T::sender, "56", &T::target, "34", &T::seq, "52", &T::sending_time, "115", &T::on_behalf_of, "142",
      &T::deliver_to_sub_id, "55", &T::symbol, "60", &T::transact_time, "63", &T::settl_type, "64", &T::settl_date,
      "117", &T::quote_id, "131", &T::quote_req_id, "132", &T::bid_px, "133", &T::offer_px, "134", &T::bid_size, "135",
      &T::offer_size, "303", &T::quote_request_type, "537", &T::quote_type);
};

namespace
{
   constexpr std::string_view nested_frame2 = "8=FIX.4.4|9=0000|35=W|49=Prov|56=MDABC|55=AUD/CAD|262=1709|"
                                              "711=1|311=AUD/CAD|457=1|458=TESTID|459=TESTSOURCE|462=1|"
                                              "292=D|268=2|"
                                              "269=0|271=500000|272=20170103|299=02z00000hdi:A|"
                                              "269=1|271=500000|272=20170103|299=02z00000hdi:A|"
                                              "10=213";
   constexpr std::string_view incremental_frame2 =
      "8=FIX.4.2|9=407|35=X|34=002565204|52=20160908-08:42:10.359|49=Prov|56=MDABC|262=1364|268=4|"
      "279=2|55=CHF/JPY|269=0|278=0453665272|270=00104.840000|271=001000000.00|15=CHF|"
      "279=0|55=CHF/JPY|269=0|278=0453665276|270=00104.841000|271=001000000.00|15=CHF|"
      "279=2|55=CHF/JPY|269=1|278=0453665273|270=00104.855000|271=001000000.00|15=CHF|"
      "279=0|55=CHF/JPY|269=1|278=0453665277|270=00104.856000|271=001000000.00|15=CHF|"
      "10=213";
   constexpr std::string_view logon_frame2 =
      "8=FIX.4.2|9=84|35=A|34=1|49=ABC|52=20120309-16:54:02|56=TT_ORDER|96=12345678|98=0|108=60|141=Y|10=248";
}

suite fixpp_more_groups = [] {
   "nested_groups_struct"_test = [] {
      fp_nested_snapshot s{};
      expect(!glz::read<pipe_strict()>(s, repair2(nested_frame2)));
      expect(s.symbol == "AUD/CAD" && s.md_req_id == "1709" && s.corporate_action == 'D');
      expect(s.underlyings.size() == 1u);
      if (s.underlyings.size() == 1) {
         expect(s.underlyings[0].symbol == "AUD/CAD" && s.underlyings[0].product == 1);
         expect(s.underlyings[0].alt_ids.size() == 1u);
         if (s.underlyings[0].alt_ids.size() == 1)
            expect(s.underlyings[0].alt_ids[0].id == "TESTID" && s.underlyings[0].alt_ids[0].source == "TESTSOURCE");
      }
      expect(s.entries.size() == 2u);
      if (s.entries.size() == 2) expect(s.entries[1].type == '1' && s.entries[1].size == 500000.0);
   };

   // writer_test.cc: should_write_nested_repeating_groups, then read back
   "nested_groups_roundtrip"_test = [] {
      fp_nested_snapshot in{"Prov", "MDABC", "AUD/CAD", "1709",
                            {{"AUD/CAD", {{"TESTID", "TESTSOURCE"}, {"ID2", "SRC2"}}, 1}, {"EUR/USD", {}, 2}},
                            'D', {{'0', 500000, "20170516", "q0"}, {'1', 250000.5, "20170516", "q1"}}};
      std::string buf;
      expect(!glz::write<pipe_strict()>(in, buf));
      expect(!glz::fix::validate(buf, '|'));
      expect(buf.find("|711=2|311=AUD/CAD|457=2|458=TESTID|459=TESTSOURCE|458=ID2|459=SRC2|462=1|311=EUR/USD|462=2|") !=
             std::string::npos);
      fp_nested_snapshot out{};
      expect(!glz::read<pipe_strict()>(out, buf));
      expect(out.underlyings.size() == 2u);
      if (out.underlyings.size() == 2) {
         expect(out.underlyings[0].alt_ids.size() == 2u && out.underlyings[0].alt_ids[1].source == "SRC2");
         expect(out.underlyings[1].alt_ids.empty() && out.underlyings[1].product == 2);
      }
      expect(out.entries.size() == 2u && out.entries[1].size == 250000.5);
      expect(out.corporate_action == 'D');
   };

   "incremental_refresh_struct"_test = [] {
      fp_incremental m{};
      expect(!glz::read<pipe_strict()>(m, repair2(incremental_frame2)));
      expect(m.seq == 2565204u && m.md_req_id == "1364");
      expect(m.entries.size() == 4u);
      if (m.entries.size() != 4) return;
      expect(m.entries[0].update_action == '2' && m.entries[0].px == 104.84 && m.entries[0].size == 1000000.0);
      expect(m.entries[3].update_action == '0' && m.entries[3].type == '1' && m.entries[3].entry_id == "0453665277");
      for (auto& e : m.entries) expect(e.symbol == "CHF/JPY" && e.currency == "CHF");
   };

   "incremental_refresh_roundtrip"_test = [] {
      fp_incremental m{};
      expect(!glz::read<pipe_strict()>(m, repair2(incremental_frame2)));
      std::string buf;
      expect(!glz::write<pipe_strict()>(m, buf));
      fp_incremental back{};
      expect(!glz::read<pipe_strict()>(back, buf));
      expect(back.entries.size() == 4u && back.seq == m.seq);
      if (back.entries.size() == 4) expect(back.entries[2].px == 104.855 && back.entries[2].entry_id == "0453665273");
   };

   "empty_group_omitted_on_write"_test = [] {
      fp_nested_snapshot in{};
      in.symbol = "AUD/CAD";
      std::string buf;
      expect(!glz::write<pipe_strict()>(in, buf));
      expect(buf.find("|268=") == std::string::npos && buf.find("|711=") == std::string::npos);
      fp_nested_snapshot out{};
      expect(!glz::read<pipe_strict()>(out, buf));
      expect(out.entries.empty() && out.symbol == "AUD/CAD");
   };
};

suite fixpp_more_malformed = [] {
   "group_count_too_small"_test = [] {
      std::string f(nested_frame2);
      f.replace(f.find("268=2"), 5, "268=1");
      fp_nested_snapshot s{};
      // strict: the surplus entry's tags are unknown at the top level
      expect(bool(glz::read<pipe_strict()>(s, repair2(f))));
      // default fix/core behaviour: the surplus entry's tags are skipped as unknown top-level tags
      fp_nested_snapshot lenient{};
      expect(!glz::read<pipe_lenient()>(lenient, repair2(f)));
      expect(lenient.entries.size() == 1u);
   };

   "group_count_too_large"_test = [] {
      std::string f(nested_frame2);
      f.replace(f.find("268=2"), 5, "268=3");
      fp_nested_snapshot s{};
      expect(bool(glz::read<pipe_strict()>(s, repair2(f))));
   };

   "group_entry_without_delimiter"_test = [] {
      // the entry starts with 271 instead of the delimiter 269
      fp_nested_snapshot s{};
      const auto f = repair2("8=FIX.4.4|9=0|35=W|268=1|271=1|269=0|10=000|");
      expect(bool(glz::read<pipe_strict()>(s, f)));
   };

   "group_count_not_a_number"_test = [] {
      fp_nested_snapshot s{};
      expect(bool(glz::read<pipe_strict()>(s, repair2("8=FIX.4.4|9=0|35=W|268=x|269=0|10=000|"))));
      expect(bool(glz::read<pipe_strict()>(s, repair2("8=FIX.4.4|9=0|35=W|268=-1|269=0|10=000|"))));
   };

   "bad_boolean"_test = [] {
      std::string f(logon_frame2);
      f.replace(f.find("141=Y"), 5, "141=X");
      fp_logon l{};
      expect(glz::read<pipe_strict()>(l, repair2(f)).ec == glz::error_code::expected_true_or_false);
   };

   "bad_char_length"_test = [] {
      fp_nested_snapshot s{};
      expect(bool(glz::read<pipe_strict()>(s, repair2("8=FIX.4.4|9=0|35=W|292=DD|10=000|"))));
   };

   "msg_type_mismatch"_test = [] {
      fp_heartbeat42 h{};
      expect(glz::read<pipe_lenient()>(h, repair2(logon_frame2)).ec == glz::error_code::invalid_header);
   };

   "unknown_tag_strict_vs_lenient"_test = [] {
      const auto f = repair2("8=FIX.4.2|9=0|35=0|49=Prov|56=MDABC|221=A|10=000|");
      fp_heartbeat42 h{};
      expect(bool(glz::read<pipe_strict()>(h, f)));
      fp_heartbeat42 h2{};
      expect(!glz::read<pipe_lenient()>(h2, f));
      expect(h2.sender == "Prov" && h2.target == "MDABC");
   };

   "repeated_tag_overwrites"_test = [] {
      fp_heartbeat42 h{};
      expect(!glz::read<pipe_strict()>(h, repair2("8=FIX.4.2|9=0|35=0|49=A|49=B|10=000|")));
      expect(h.sender == "B");
   };

   "fields_in_any_order"_test = [] {
      fp_logon l{};
      expect(!glz::read<pipe_strict()>(l, repair2("8=FIX.4.2|9=0|35=A|141=N|108=30|49=X|34=7|10=000|")));
      expect(l.seq == 7 && l.sender == "X" && l.heart_bt_int == 30 && l.reset_seq_num == std::optional<bool>(false));
   };
};

suite fixpp_more_messages = [] {
   "logon_struct"_test = [] {
      fp_logon l{};
      expect(!glz::read<pipe_strict()>(l, repair2(logon_frame2)));
      expect(l.seq == 1 && l.sender == "ABC" && l.target == "TT_ORDER" && l.raw_data == "12345678");
      expect(l.heart_bt_int == 60 && l.reset_seq_num == std::optional<bool>(true));
      std::string buf;
      expect(!glz::write<pipe_strict()>(l, buf));
      expect(buf.find("|141=Y|") != std::string::npos);
      fp_logon back{};
      expect(!glz::read<pipe_strict()>(back, buf));
      expect(back.sending_time == "20120309-16:54:02" && back.reset_seq_num == std::optional<bool>(true));
   };

   "heartbeat_42_and_44"_test = [] {
      std::string b42, b44;
      expect(!glz::write<pipe_strict()>(fp_heartbeat42{"SNDR", "TRGT", "TestReq"}, b42));
      expect(!glz::write<pipe_strict()>(fp_heartbeat44{"SNDR", "TRGT", "TestReq"}, b44));
      expect(b42.starts_with("8=FIX.4.2|") && b44.starts_with("8=FIX.4.4|"));
      expect(b42.find("|35=0|49=SNDR|56=TRGT|112=TestReq|10=") != std::string::npos);
      expect(!glz::fix::validate(b42, '|') && !glz::fix::validate(b44, '|'));
   };

   "multi_char_msg_type"_test = [] {
      fp_user_response u{};
      expect(!glz::read<pipe_strict()>(u, repair2("8=FIX.4.4|9=84|35=BF|923=123|924=1|553=username|10=248")));
      expect(u.user_request_id == "123" && u.user_status == 1 && u.username == "username");
      std::string buf;
      expect(!glz::write<pipe_strict()>(u, buf));
      expect(buf.find("|35=BF|") != std::string::npos);
   };

   // tests/data/fix42.log: 330 Quote messages. Unknown tag 11325 needs the lenient reader.
   "fix42_log_quotes"_test = [] {
      const auto data = read_data("fix42.log");
      std::string_view rest = data;
      size_t total = 0, read_ok = 0, strict_rejected = 0, roundtrip_ok = 0, sane = 0;
      while (!rest.empty()) {
         const size_t nl = rest.find('\n');
         std::string_view line = rest.substr(0, nl);
         rest.remove_prefix(nl == std::string_view::npos ? rest.size() : nl + 1);
         if (line.empty()) continue;
         ++total;
         const auto msg = repair2(line);
         fp_quote q{};
         if (glz::read<pipe_lenient()>(q, msg)) continue;
         ++read_ok;
         fp_quote strict{};
         if (glz::read<pipe_strict()>(strict, msg)) ++strict_rejected;
         if (q.sender == "FIXPROV" && !q.symbol.empty() && !q.quote_id.empty() && q.seq > 0) ++sane;
         std::string buf;
         fp_quote back{};
         if (!glz::write<pipe_strict()>(q, buf) && !glz::read<pipe_strict()>(back, buf) && back.quote_id == q.quote_id &&
             back.bid_px == q.bid_px && back.offer_px == q.offer_px && back.seq == q.seq && back.symbol == q.symbol)
            ++roundtrip_ok;
      }
      expect(total == 330u);
      expect(read_ok == total);
      expect(strict_rejected == total); // every line carries custom tag 11325
      expect(sane == total);
      expect(roundtrip_ok == total);
   };
};
