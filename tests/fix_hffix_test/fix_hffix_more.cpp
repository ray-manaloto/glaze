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
      o.error_on_unknown_keys = false;
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
