// Glaze Library
// For the license information refer to glaze.hpp

// More cases from hffix (https://github.com/jamesdbrock/hffix, licence in LICENSE-hffix):
// message types and ExecutionReports from test/data/fix.4.1.set.1 and test/data/fix.5.0.set.2,
// corruption and truncation of the writer01.fix messages (hffix's reader checks is_complete /
// is_valid), and write-then-read round trips of the writer01.cpp messages through fix/core.

#include <cstdio>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
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

   std::vector<std::string_view> split_messages(std::string_view stream)
   {
      std::vector<std::string_view> msgs;
      while (true) {
         const size_t n = glz::fix::frame(stream);
         if (n == 0 || n == glz::fix::frame_error) break;
         msgs.push_back(stream.substr(0, n));
         stream.remove_prefix(n);
      }
      return msgs;
   }

   std::string_view msg_type(std::string_view msg)
   {
      auto f = glz::fix::parse_fields(msg);
      if (!f || f->size() < 3) return {};
      return (*f)[2].value;
   }

   std::string pipes(std::string_view s)
   {
      std::string out(s);
      for (auto& c : out)
         if (c == '\x01') c = '|';
      return out;
   }

   void skip(std::string_view name, std::string_view reason)
   {
      std::printf("SKIP %.*s: %.*s\n", int(name.size()), name.data(), int(reason.size()), reason.data());
   }
}

// FIX.4.1 ExecutionReport as sent by the QuickFIX "executor" in fix.4.1.set.1
struct hffix_exec_report
{
   int msg_seq_num{};
   std::string sender_comp_id{};
   std::string sending_time{};
   std::string target_comp_id{};
   double avg_px{};
   std::string cl_ord_id{};
   int cum_qty{};
   std::string exec_id{};
   char exec_trans_type{};
   double last_px{};
   int last_shares{};
   std::string order_id{};
   int order_qty{};
   char ord_status{};
   char side{};
   std::string symbol{};
   char exec_type{};
   int leaves_qty{};
};

template <>
struct glz::meta<hffix_exec_report>
{
   using T = hffix_exec_report;
   static constexpr auto fix_msg_type = "8";
   static constexpr auto fix_begin_string = "FIX.4.1";
   static constexpr auto value = glz::object(
      "34", &T::msg_seq_num, "49", &T::sender_comp_id, "52", &T::sending_time, "56", &T::target_comp_id, "6",
      &T::avg_px, "11", &T::cl_ord_id, "14", &T::cum_qty, "17", &T::exec_id, "20", &T::exec_trans_type, "31",
      &T::last_px, "32", &T::last_shares, "37", &T::order_id, "38", &T::order_qty, "39", &T::ord_status, "54",
      &T::side, "55", &T::symbol, "150", &T::exec_type, "151", &T::leaves_qty);
};

// writer01.cpp messages (FIX.4.2)
struct hffix_w_logon
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   int msg_seq_num{};
   std::string sending_time{};
   int encrypt_method{};
   int heart_bt_int{};
};

template <>
struct glz::meta<hffix_w_logon>
{
   using T = hffix_w_logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "34", &T::msg_seq_num,
                                             "52", &T::sending_time, "98", &T::encrypt_method, "108", &T::heart_bt_int);
};

enum class hffix_side : char { buy = '1', sell = '2' };

struct hffix_w_order
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   int msg_seq_num{};
   std::string sending_time{};
   std::string cl_ord_id{};
   char handl_inst{};
   std::string symbol{};
   hffix_side side{};
   std::string transact_time{};
   int order_qty{};
   char ord_type{};
   std::optional<double> price{};
   char time_in_force{};
};

template <>
struct glz::meta<hffix_w_order>
{
   using T = hffix_w_order;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value =
      glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "34", &T::msg_seq_num, "52", &T::sending_time,
                  "11", &T::cl_ord_id, "21", &T::handl_inst, "55", &T::symbol, "54", &T::side, "60", &T::transact_time,
                  "38", &T::order_qty, "40", &T::ord_type, "44", &T::price, "59", &T::time_in_force);
};

namespace
{
   constexpr glz::fix_opts lenient()
   {
      glz::fix_opts o{};
      return o;
   }
}

suite hffix_more_samples = [] {
   "fix_4_1_set_1_message_types"_test = [] {
      const auto data = read_data("fix.4.1.set.1");
      std::map<std::string, int> types;
      for (auto m : split_messages(data)) ++types[std::string(msg_type(m))];
      expect(types["A"] == 2 && types["0"] == 2 && types["D"] == 3);
      expect(types["8"] == 5 && types["F"] == 2 && types["3"] == 2);
   };

   "fix_5_0_set_2_message_types"_test = [] {
      const auto data = read_data("fix.5.0.set.2");
      std::map<std::string, int> types;
      for (auto m : split_messages(data)) ++types[std::string(msg_type(m))];
      expect(types["A"] == 16 && types["5"] == 14 && types["D"] == 15);
      expect(types["0"] == 18 && types["1"] == 1 && types["2"] == 1);
   };

   // The five ExecutionReports: new (39=0) then filled (39=2) for MSFT and ORCL, new for SPY.
   "fix_4_1_execution_reports"_test = [] {
      const auto data = read_data("fix.4.1.set.1");
      std::vector<hffix_exec_report> reports;
      bool all_ok = true;
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "8") continue;
         hffix_exec_report r{};
         if (glz::read<glz::fix_opts{}>(r, m)) all_ok = false;
         reports.push_back(r);
      }
      expect(all_ok);
      expect(reports.size() == 5u);
      if (reports.size() != 5) return;
      expect(reports[0].symbol == "MSFT" && reports[0].ord_status == '0' && reports[0].cum_qty == 0);
      expect(reports[1].symbol == "MSFT" && reports[1].ord_status == '2' && reports[1].avg_px == 12.3);
      expect(reports[1].last_shares == 10000 && reports[1].cum_qty == 10000);
      expect(reports[3].symbol == "ORCL" && reports[3].last_px == 12.3);
      expect(reports[4].symbol == "SPY" && reports[4].msg_seq_num == 7);
      for (auto& r : reports) {
         expect(r.side == '1' && r.order_qty == 10000);
         expect(r.sender_comp_id == "EXEC" && r.target_comp_id == "BANZAI");
      }
   };

   // A 35=8 message read into the NewOrderSingle type is a MsgType mismatch.
   "msg_type_mismatch"_test = [] {
      const auto data = read_data("fix.4.1.set.1");
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "8") continue;
         hffix_w_order o{};
         auto ec = glz::read<lenient()>(o, m);
         expect(ec.ec == glz::error_code::invalid_header);
         break;
      }
   };

   "fix_5_0_set_2_orders"_test = [] {
      const auto data = read_data("fix.5.0.set.2");
      size_t orders = 0, read_ok = 0;
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "D") continue;
         ++orders;
         auto f = glz::fix::parse_fields(m);
         if (f && f->size() > 5) ++read_ok;
      }
      expect(orders == 15u && read_ok == orders);
   };
};

suite hffix_more_malformed = [] {
   // Every single-byte change of a valid message must be caught by validate (or the scanner).
   "single_byte_corruption_detected"_test = [] {
      const auto data = read_data("writer01.fix");
      for (auto m : split_messages(data)) {
         std::string msg(m);
         size_t undetected = 0;
         for (size_t i = 0; i < msg.size(); ++i) {
            std::string bad = msg;
            bad[i] = char(bad[i] + 1);
            if (!glz::fix::validate(bad)) ++undetected;
         }
         expect(undetected == 0u);
         if (undetected) std::printf("undetected corruption in %s\n", pipes(msg).c_str());
      }
   };

   "every_truncation_detected"_test = [] {
      const auto data = read_data("writer01.fix");
      for (auto m : split_messages(data)) {
         size_t accepted = 0;
         for (size_t n = 0; n < m.size(); ++n) {
            if (!glz::fix::validate(m.substr(0, n))) ++accepted;
            if (glz::fix::frame(m.substr(0, n)) == n && n != 0) ++accepted;
         }
         expect(accepted == 0u);
      }
   };

   "header_errors"_test = [] {
      // 9 not a number
      expect(glz::fix::validate("8=FIX.4.2|9=x|35=0|10=000|", '|').ec == glz::error_code::invalid_header);
      // 10 not 3 digits
      expect(bool(glz::fix::validate("8=FIX.4.2|9=5|35=0|10=7|", '|')));
      // 10 missing
      expect(bool(glz::fix::validate("8=FIX.4.2|9=5|35=0|", '|')));
      // empty
      expect(bool(glz::fix::validate("", '|')));
   };

   "frame_garbage"_test = [] {
      expect(glz::fix::frame("garbage|8=FIX.4.2|", '|') == glz::fix::frame_error);
      expect(glz::fix::frame("8=FIX.4.2|9=abc|", '|') == glz::fix::frame_error);
      expect(glz::fix::frame("8=FIX.4.2|9=5", '|') == 0u);
   };

   "bad_number_in_struct"_test = [] {
      hffix_w_logon l{};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(hffix_w_logon{"A", "B", 1, "t", 0, 30}, buf));
      // corrupt 108=30 into 108=3x then fix the checksum by rewriting without validation
      auto p = buf.find("\x01" "108=30");
      expect(p != std::string::npos);
      buf[p + 6] = 'x';
      glz::fix_opts o{};
      constexpr auto no_check = [] {
         glz::fix_opts x{};
         x.validate_checksum = false;
         return x;
      }();
      (void)o;
      expect(glz::read<no_check>(l, buf).ec == glz::error_code::parse_number_failure);
   };
};

suite hffix_more_roundtrip = [] {
   // writer01.cpp writes a Logon then a NewOrderSingle; round trip both through glz::write/read.
   "writer01_logon_roundtrip"_test = [] {
      const hffix_w_logon in{"AAAA", "BBBB", 1, "20170809-12:34:56.000", 0, 10};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      expect(buf.starts_with("8=FIX.4.2\x01"));
      expect(!glz::fix::validate(buf));
      hffix_w_logon out{};
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.sender_comp_id == in.sender_comp_id && out.msg_seq_num == 1 && out.heart_bt_int == 10);
   };

   "writer01_order_roundtrip"_test = [] {
      const hffix_w_order in{"AAAA", "BBBB", 2, "20170809-12:34:56.000", "A1", '1', "OIH", hffix_side::buy,
                             "20170809-12:34:56.000", 100, '2', 500.01, '1'};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      expect(buf.find("\x01" "44=500.01\x01") != std::string::npos);
      expect(buf.find("\x01" "54=1\x01") != std::string::npos);
      hffix_w_order out{};
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.side == hffix_side::buy && out.price == std::optional<double>(500.01) && out.symbol == "OIH");
   };

   // Fields of writer01.fix in hffix's order differ from declaration order only in position, so the
   // file's own NewOrderSingle reads into the same type.
   "writer01_fix_reads_into_struct"_test = [] {
      const auto data = read_data("writer01.fix");
      auto msgs = split_messages(data);
      expect(msgs.size() == 2u);
      if (msgs.size() != 2) return;
      hffix_w_order o{};
      expect(!glz::read<glz::fix_opts{}>(o, msgs[1]));
      expect(o.cl_ord_id == "A1" && o.order_qty == 100 && o.price == std::optional<double>(500.01));
   };

   "market_order_without_price"_test = [] {
      hffix_w_order in{};
      in.cl_ord_id = "M1";
      in.symbol = "SPY";
      in.side = hffix_side::sell;
      in.order_qty = 5;
      in.ord_type = '1';
      in.handl_inst = '1';
      in.time_in_force = '0';
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      expect(buf.find("\x01" "44=") == std::string::npos);
      hffix_w_order out{};
      out.price = 1.0;
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.side == hffix_side::sell && out.order_qty == 5);
   };

   "stream_of_written_messages"_test = [] {
      std::string stream;
      for (int i = 1; i <= 50; ++i) {
         hffix_w_order o{"AAAA", "BBBB", i, "20170809-12:34:56.000", "C" + std::to_string(i), '1', "OIH",
                         (i % 2) ? hffix_side::buy : hffix_side::sell, "20170809-12:34:56.000", i * 10, '2',
                         100.0 + i / 100.0, '1'};
         std::string buf;
         if (glz::write<glz::fix_opts{}>(o, buf)) break;
         stream += buf;
      }
      auto msgs = split_messages(stream);
      expect(msgs.size() == 50u);
      int good = 0;
      for (size_t i = 0; i < msgs.size(); ++i) {
         hffix_w_order o{};
         if (!glz::read<glz::fix_opts{}>(o, msgs[i]) && o.msg_seq_num == int(i + 1) &&
             o.cl_ord_id == "C" + std::to_string(i + 1) && o.order_qty == int(i + 1) * 10)
            ++good;
      }
      expect(good == 50);
   };

   "write_rejects_delimiter_in_value"_test = [] {
      hffix_w_logon in{"A\x01" "B", "C", 1, "t", 0, 30};
      std::string buf;
      expect(glz::write<glz::fix_opts{}>(in, buf).ec == glz::error_code::syntax_error);
   };

   "value_may_contain_equals"_test = [] {
      hffix_w_logon in{"A=B", "C", 1, "t", 0, 30};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      hffix_w_logon out{};
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.sender_comp_id == "A=B");
   };

   skip("writer01_byte_identical", "hffix zero-pads BodyLength (9=000063); glaze writes 9=63, so the bytes differ");
};

// FIXT.1.1 messages from test/data/fix.5.0.set.2 (a CME iLink style session)
struct hffix_t_order
{
   int msg_seq_num{};
   std::string sender_comp_id{};
   std::string sending_time{};
   std::string target_comp_id{};
   std::string account{};
   std::string cl_ord_id{};
   int order_qty{};
   char ord_type{};
   std::optional<double> price{};
   char side{};
   std::string symbol{};
   char time_in_force{};
   std::string transact_time{};
   std::string security_desc{};
   std::string security_type{};
   std::string security_exchange{};
};

template <>
struct glz::meta<hffix_t_order>
{
   using T = hffix_t_order;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object(
      "34", &T::msg_seq_num, "49", &T::sender_comp_id, "52", &T::sending_time, "56", &T::target_comp_id, "1",
      &T::account, "11", &T::cl_ord_id, "38", &T::order_qty, "40", &T::ord_type, "44", &T::price, "54", &T::side,
      "55", &T::symbol, "59", &T::time_in_force, "60", &T::transact_time, "107", &T::security_desc, "167",
      &T::security_type, "207", &T::security_exchange);
};

struct hffix_t_logon
{
   int msg_seq_num{};
   int encrypt_method{};
   int heart_bt_int{};
   std::string default_appl_ver_id{};
};

template <>
struct glz::meta<hffix_t_logon>
{
   using T = hffix_t_logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("34", &T::msg_seq_num, "98", &T::encrypt_method, "108", &T::heart_bt_int,
                                             "1137", &T::default_appl_ver_id);
};

struct hffix_t_resend
{
   int msg_seq_num{};
   int begin_seq_no{};
   int end_seq_no{};
};

template <>
struct glz::meta<hffix_t_resend>
{
   using T = hffix_t_resend;
   static constexpr auto fix_msg_type = "2";
   static constexpr auto fix_begin_string = "FIXT.1.1";
   static constexpr auto value =
      glz::object("34", &T::msg_seq_num, "7", &T::begin_seq_no, "16", &T::end_seq_no);
};

suite hffix_more_fixt = [] {
   "fixt_orders_read_and_roundtrip"_test = [] {
      const auto data = read_data("fix.5.0.set.2");
      size_t orders = 0, ok = 0, rt = 0;
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "D") continue;
         ++orders;
         hffix_t_order o{};
         if (glz::read<glz::fix_opts{}>(o, m)) continue;
         if (o.security_type == "FUT" && o.security_exchange == "XLOF" && o.cl_ord_id.size() == 36 && o.order_qty > 0 &&
             o.price.has_value())
            ++ok;
         std::string buf;
         hffix_t_order back{};
         if (!glz::write<glz::fix_opts{}>(o, buf) && buf.starts_with("8=FIXT.1.1\x01") &&
             !glz::read<glz::fix_opts{}>(back, buf) && back.cl_ord_id == o.cl_ord_id && back.price == o.price &&
             back.security_desc == o.security_desc && back.msg_seq_num == o.msg_seq_num)
            ++rt;
      }
      expect(orders == 15u);
      expect(ok == orders);
      expect(rt == orders);
   };

   "fixt_logons"_test = [] {
      const auto data = read_data("fix.5.0.set.2");
      size_t logons = 0, ok = 0;
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "A") continue;
         ++logons;
         hffix_t_logon l{};
         if (!glz::read<glz::fix_opts{}>(l, m) && l.default_appl_ver_id == "7" && l.heart_bt_int == 60) ++ok;
      }
      expect(logons == 16u && ok == logons);
   };

   "fixt_resend_request"_test = [] {
      const auto data = read_data("fix.5.0.set.2");
      size_t n = 0;
      for (auto m : split_messages(data)) {
         if (msg_type(m) != "2") continue;
         hffix_t_resend r{};
         expect(!glz::read<glz::fix_opts{}>(r, m));
         expect(r.msg_seq_num == 49 && r.begin_seq_no == 48 && r.end_seq_no == 0);
         ++n;
      }
      expect(n == 1u);
   };
};

// ---- fix/core v2: raw-data fields and typed timestamps ----
struct hffix_raw_msg
{
   std::string raw{};
   std::string text{};
};
template <>
struct glz::meta<hffix_raw_msg>
{
   using T = hffix_raw_msg;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("96", &T::raw, "58", &T::text);
};

struct hffix_timed
{
   glz::fix::utc_timestamp sending_time{};
};
template <>
struct glz::meta<hffix_timed>
{
   using T = hffix_timed;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("52", &T::sending_time);
};

suite hffix_more_v2 = [] {
   // unit_tests.cpp: data_length - the data value is taken by byte count, so it may contain SOH
   "data_with_embedded_soh"_test = [] {
      std::string body = std::string("35=A\x01" "95=3\x01" "96=a\x01" "b\x01" "58=t\x01");
      std::string msg = "8=FIX.4.2\x01" "9=" + std::to_string(body.size()) + "\x01" + body;
      std::string cs = std::to_string(glz::fix::checksum(msg));
      while (cs.size() < 3) cs.insert(cs.begin(), '0');
      msg += "10=" + cs + "\x01";
      expect(!glz::fix::validate(msg));
      auto f = glz::fix::parse_fields(msg);
      expect(f.has_value());
      if (f) {
         bool found = false;
         for (auto& x : *f)
            if (x.tag == 96) found = x.value == std::string_view("a\x01" "b", 3);
         expect(found);
      }
      hffix_raw_msg m{};
      expect(!glz::read<glz::fix_opts{}>(m, msg));
      expect(m.raw == std::string("a\x01" "b", 3) && m.text == "t");
   };

   "raw_data_roundtrip"_test = [] {
      hffix_raw_msg in{std::string("bin\x01=\0data", 10), "x"};
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      expect(buf.find("\x01" "95=10\x01" "96=") != std::string::npos);
      expect(!glz::fix::validate(buf));
      hffix_raw_msg out{};
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.raw == in.raw && out.text == "x");
   };

   "raw_data_length_past_end"_test = [] {
      auto f = glz::fix::parse_fields("95=50|96=abc|", '|');
      expect(!f.has_value());
   };

   // unit_tests.cpp: chrono - 1502282096123 ms <-> 20170809-12:34:56.123
   "chrono_timestamp"_test = [] {
      using namespace std::chrono;
      hffix_timed in{};
      in.sending_time.time = sys_time<nanoseconds>(milliseconds(1502282096123ULL));
      in.sending_time.precision = 3;
      std::string buf;
      expect(!glz::write<glz::fix_opts{}>(in, buf));
      expect(buf.find("\x01" "52=20170809-12:34:56.123\x01") != std::string::npos);
      hffix_timed out{};
      expect(!glz::read<glz::fix_opts{}>(out, buf));
      expect(out.sending_time == in.sending_time);
   };

   // unit_tests.cpp: chrono_nano - 1502282096123456789 ns <-> 20170809-12:34:56.123456789
   "chrono_nano_timestamp"_test = [] {
      using namespace std::chrono;
      glz::fix::utc_timestamp t{};
      expect(glz::fix::parse_utc_timestamp("20170809-12:34:56.123456789", t));
      expect(t.time == sys_time<nanoseconds>(nanoseconds(1502282096123456789ULL)) && t.precision == 9);
      std::string out;
      glz::fix::append_utc_timestamp(out, t);
      expect(out == "20170809-12:34:56.123456789");
   };

   "chrono_bad_timestamp"_test = [] {
      glz::fix::utc_timestamp t{};
      expect(!glz::fix::parse_utc_timestamp("20170230-12:34:56", t)); // no 30 February
      expect(!glz::fix::parse_utc_timestamp("20170809-24:00:00", t));
      expect(!glz::fix::parse_utc_timestamp("20170809 12:34:56", t));
   };
};
