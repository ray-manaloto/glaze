// Glaze Library
// For the license information refer to glaze.hpp

// Tests ported from hffix (https://github.com/jamesdbrock/hffix), licence in LICENSE-hffix
// (Copyright 2011, T3 IP, LLC; BSD-style). Sources:
//   test/src/unit_tests.cpp  (Boost.Test cases named in each test below)
//   test/src/reader01.cpp, test/src/writer01.cpp, test/expected/writer01.fix
//   test/data/fix.4.1.set.1, test/data/fix.5.0.set.2 (copied verbatim into ./data)
// hffix's API (message_writer / message_reader) has no direct glaze equivalent, so each case is
// re-expressed against the glaze FIX contract (docs/fix/api.md): parse_fields, checksum, validate,
// frame, and struct mapping via glz::read / glz::write with glz::fix_opts.
//
// Struct-mapping tests are compiled only when GLZ_FIX_HAS_STRUCT_MAPPING is defined (the fix/core
// branch is expected to define it once glz::read/glz::write<fix_opts> work). Otherwise they are
// reported as SKIP with a reason.

#include <cstdio>
#include <cstring>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
   // Test vectors are written with '|' for readability and converted to SOH.
   std::string soh(std::string_view s)
   {
      std::string out(s);
      for (auto& c : out)
         if (c == '|') c = '\x01';
      return out;
   }

   std::string three_digits(unsigned v)
   {
      char buf[4];
      buf[0] = char('0' + (v / 100) % 10);
      buf[1] = char('0' + (v / 10) % 10);
      buf[2] = char('0' + v % 10);
      buf[3] = 0;
      return buf;
   }

   // Builds a complete message: 8=<begin><sep>9=<len><sep><body>10=<sum><sep>.
   // body must already end with sep. body_len_width zero-pads 9 (hffix writes 6 digits).
   std::string make_msg(std::string_view begin, std::string_view body, char sep = '\x01', size_t body_len_width = 0)
   {
      std::string len = std::to_string(body.size());
      while (len.size() < body_len_width) len.insert(len.begin(), '0');
      std::string m = "8=";
      m += begin;
      m += sep;
      m += "9=";
      m += len;
      m += sep;
      m += body;
      m += "10=" + three_digits(glz::fix::checksum(m));
      m += sep;
      return m;
   }

   std::string read_file(const char* name)
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

   const glz::fix::field* find(const std::vector<glz::fix::field>& fs, uint32_t tag, size_t from = 0)
   {
      for (size_t i = from; i < fs.size(); ++i)
         if (fs[i].tag == tag) return &fs[i];
      return nullptr;
   }

   void skip(std::string_view name, std::string_view reason)
   {
      std::printf("SKIP %.*s: %.*s\n", int(name.size()), name.data(), int(reason.size()), reason.data());
   }

   // Splits a stream into messages with frame(), the way hffix's reader01 loop does with
   // message_reader::is_complete() / next_message_reader().
   std::vector<std::string_view> frame_all(std::string_view stream, size_t& leftover)
   {
      std::vector<std::string_view> msgs;
      while (true) {
         const size_t n = glz::fix::frame(stream);
         if (n == 0 || n == glz::fix::frame_error) break;
         msgs.push_back(stream.substr(0, n));
         stream.remove_prefix(n);
      }
      leftover = stream.size();
      return msgs;
   }
}

suite hffix_checksum = [] {
   // unit_tests.cpp: checksum_empty
   "checksum_empty"_test = [] {
      // 8=FIX.4.2\x01 = 31 ; 9=000000\x01 = 151 ; (31 + 151) % 256 = 182
      expect(glz::fix::checksum(soh("8=FIX.4.2|9=000000|")) == 182);
   };

   // unit_tests.cpp: checksum
   "checksum"_test = [] {
      // 8=FIX.4.2\x01 = 31 ; 9=000007\x01 = 158 ; 58=123\x01 = 65 ; total 254
      expect(glz::fix::checksum(soh("8=FIX.4.2|9=000007|58=123|")) == 254);
      // the same message built and validated end to end
      const auto msg = make_msg("FIX.4.2", soh("58=123|"), '\x01', 6);
      expect(msg == soh("8=FIX.4.2|9=000007|58=123|10=254|"));
   };

   // unit_tests.cpp: checksum_negative (bytes >= 0x80 must be summed as unsigned)
   "checksum_negative"_test = [] {
      // 58=\x80\x01 = 43 ; with header 31 + 156 -> 230
      expect(glz::fix::checksum(soh("8=FIX.4.2|9=000005|58=\x80|")) == 230);
      expect(glz::fix::checksum("\x80\xff") == uint8_t((0x80 + 0xff) % 256));
   };

   // unit_tests.cpp: checksum_calc - the checksum of a written message matches its tag 10
   "checksum_calc"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|"));
      expect(!glz::fix::validate(msg));
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value());
      if (!fields) return;
      expect(fields->back().tag == 10u);
      const size_t trailer = msg.size() - 7;
      expect(fields->back().value == three_digits(glz::fix::checksum(std::string_view(msg).substr(0, trailer))));
   };

   "checksum_mismatch_rejected"_test = [] {
      auto msg = make_msg("FIX.4.2", soh("35=A|"));
      msg[msg.size() - 2] = msg[msg.size() - 2] == '0' ? '1' : '0';
      expect(bool(glz::fix::validate(msg)));
   };

   "body_length_mismatch_rejected"_test = [] {
      // 9=6 is off by one for "35=A|"(5 bytes)
      std::string m = soh("8=FIX.4.2|9=6|35=A|");
      m += "10=" + three_digits(glz::fix::checksum(m)) + '\x01';
      expect(bool(glz::fix::validate(m)));
   };

   "zero_padded_body_length_accepted"_test = [] {
      // hffix writes BodyLength as 6 zero padded digits (writer01.fix: 9=000063)
      expect(!glz::fix::validate(make_msg("FIX.4.2", soh("35=A|"), '\x01', 6)));
   };
};

suite hffix_basic = [] {
   // unit_tests.cpp: basic - write header, MsgType A, trailer; read back; compare values
   "basic"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|"));
      expect(glz::fix::frame(msg) == msg.size());
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value());
      if (!fields) return;
      expect(fields->size() == 4u);
      const auto* mt = find(*fields, 35);
      expect(mt != nullptr);
      if (!mt) return;
      expect(mt->value == "A");
      expect(mt->value != "B");
      expect(std::string(mt->value) == std::string("A"));
   };

   // unit_tests.cpp: basic - message_writer preconditions (trailer without header,
   // header twice). Here: validate rejects field order violations.
   "basic_preconditions"_test = [] {
      // no header at all
      std::string m = soh("35=A|");
      m += "10=" + three_digits(glz::fix::checksum(m)) + '\x01';
      expect(bool(glz::fix::validate(m)));
      // header twice
      expect(bool(glz::fix::validate(make_msg("FIX.4.2", soh("8=FIX.4.2|35=A|")))));
      // 35 not third
      expect(bool(glz::fix::validate(make_msg("FIX.4.2", soh("49=X|35=A|")))));
   };

   // unit_tests.cpp: null_field_value - hffix iterates over an empty value (37=). The glaze contract
   // (docs/fix/api.md) requires non-empty values, so the message is rejected as a malformed field.
   "null_field_value"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|37=|38=whatever|"));
      auto fields = glz::fix::parse_fields(msg);
      expect(!fields.has_value());
      if (!fields) expect(fields.error().ec == glz::error_code::syntax_error);
      expect(bool(glz::fix::validate(msg)));
   };

   // unit_tests.cpp: data_length - RawDataLength(95)/RawData(96) and
   // EncodedUnderlyingProvisionTextLen(40980)/EncodedUnderlyingProvisionText(40981)
   "data_length"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|95=5|96=datum|40980=5|40981=datum|"));
      expect(!glz::fix::validate(msg));
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value());
      if (!fields) return;
      const auto* raw = find(*fields, 96);
      const auto* enc = find(*fields, 40981);
      expect(raw != nullptr && raw->value == "datum");
      expect(enc != nullptr && enc->value == "datum");
   };

   // unit_tests.cpp: data_length - hffix uses the length field so binary data may contain SOH.
   skip("data_with_embedded_soh",
        "the contract does not yet say whether parse_fields honours length-prefixed data fields (95/96) "
        "containing SOH; expected: 95=3|96=a\\x01b| yields 96 = \"a\\x01b\"");

   // unit_tests.cpp: iterating - ten messages back to back, each with exactly one body field
   "iterating"_test = [] {
      std::string stream;
      for (int i = 0; i < 10; ++i) stream += make_msg("FIX.4.2", soh("35=A|"));
      size_t leftover = 1;
      auto msgs = frame_all(stream, leftover);
      expect(msgs.size() == 10u);
      expect(leftover == 0u);
      unsigned valid = 0;
      for (auto m : msgs) {
         if (glz::fix::validate(m)) continue;
         auto fields = glz::fix::parse_fields(m);
         // hffix iterates the body only (between 9 and 10): one field, 35
         if (fields && fields->size() - 3 == 1) ++valid;
      }
      expect(valid == 10u);
   };

   // unit_tests.cpp: msg_type_string - hffix ships a generated MsgType dictionary
   skip("msg_type_string", "glaze FIX has no FIX dictionary of message/field names (hffix_fields.hpp)");

   // unit_tests.cpp: header - writing the BeginString from const char* vs string_view gives the same bytes
   "header"_test = [] {
      const char* cp = "FIX.4.2";
      std::string_view sv = cp;
      expect(make_msg(cp, soh("35=A|")) == make_msg(sv, soh("35=A|")));
   };

   // unit_tests.cpp: read_string
   "read_string"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|"));
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value() && (*fields)[2].tag == 35u && (*fields)[2].value == "A");
   };

   // unit_tests.cpp: chrono / chrono_nano - timestamp text forms
   "chrono_text"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=A|52=20170809-12:34:56.123|273=12:34:00.789|"));
      auto fields = glz::fix::parse_fields(msg);
      expect(fields.has_value());
      if (!fields) return;
      expect(find(*fields, 52)->value == "20170809-12:34:56.123");
      expect(find(*fields, 273)->value == "12:34:00.789");
      const auto nano = make_msg("FIX.4.2", soh("35=A|52=20170809-12:34:56.123456789|273=12:34:00.789456123|"));
      auto nf = glz::fix::parse_fields(nano);
      expect(nf.has_value() && find(*nf, 52)->value == "20170809-12:34:56.123456789");
      expect(nf.has_value() && find(*nf, 273)->value == "12:34:00.789456123");
   };
   skip("chrono_typed", "the contract defines no mapping of FIX UTCTimestamp/UTCTimeOnly to std::chrono types; "
                        "hffix expects 1502282096123 ms <-> 20170809-12:34:56.123 and 12:34:00.789 <-> 45240789 ms");

   // unit_tests.cpp: message_writer_bounds - hffix writes into fixed buffers and throws on overflow.
   skip("message_writer_bounds", "glz::write targets a growable buffer; fixed-size buffer overflow behaviour of the "
                                 "FIX writer is not specified by the contract");
};

suite hffix_framing = [] {
   "incomplete_prefixes"_test = [] {
      const auto msg = make_msg("FIX.4.2", soh("35=D|11=A1|55=OIH|54=1|38=100|"));
      bool all_zero = true;
      for (size_t n = 0; n < msg.size(); ++n)
         if (glz::fix::frame(std::string_view(msg).substr(0, n)) != 0) all_zero = false;
      expect(all_zero);
      expect(glz::fix::frame(msg) == msg.size());
      expect(glz::fix::frame(msg + "8=FIX") == msg.size());
   };

   "custom_separator"_test = [] {
      const auto msg = make_msg("FIX.4.2", "35=A|", '|');
      expect(glz::fix::frame(msg, '|') == msg.size());
      expect(!glz::fix::validate(msg, '|'));
      auto fields = glz::fix::parse_fields(msg, '|');
      expect(fields.has_value() && fields->size() == 4u);
   };
};

suite hffix_samples = [] {
   // reader01.cpp over test/expected/writer01.fix (the output of writer01.cpp).
   // Expected values from test/expected/reader01.txt.
   "reader01_writer01_fix"_test = [] {
      const auto data = read_file("writer01.fix");
      expect(!data.empty());
      size_t leftover = 1;
      auto msgs = frame_all(data, leftover);
      expect(msgs.size() == 2u);
      expect(leftover == 0u);
      if (msgs.size() != 2) return;
      for (auto m : msgs) expect(!glz::fix::validate(m));

      auto logon = glz::fix::parse_fields(msgs[0]);
      expect(logon.has_value());
      if (!logon) return;
      expect(find(*logon, 35)->value == "A");
      expect(find(*logon, 49)->value == "AAAA");
      expect(find(*logon, 34)->value == "1");
      expect(find(*logon, 52)->value == "20170809-12:34:56.000");
      // "The next field is EncryptMethod = 0"
      size_t i = 0;
      while ((*logon)[i].tag != 52) ++i;
      expect((*logon)[i + 1].tag == 98u && (*logon)[i + 1].value == "0");

      auto nos = glz::fix::parse_fields(msgs[1]);
      expect(nos.has_value());
      if (!nos) return;
      // "Buy OIH 100 @ $50001E-2"
      expect(find(*nos, 35)->value == "D");
      expect(find(*nos, 54)->value == "1");
      expect(find(*nos, 55)->value == "OIH");
      expect(find(*nos, 38)->value == "100");
      expect(find(*nos, 44)->value == "500.01");
   };

   // reader01.cpp reads stdin in 4096 byte chunks; here the chunk size varies from 1 byte up and
   // every chunking must yield the same messages.
   "streaming_chunks"_test = [] {
      const auto data = read_file("fix.4.1.set.1");
      size_t leftover = 0;
      const auto whole = frame_all(data, leftover);
      for (size_t chunk : {size_t(1), size_t(7), size_t(64), size_t(4096)}) {
         std::string buffer;
         size_t pos = 0, count = 0;
         bool same = true;
         while (pos < data.size()) {
            buffer.append(data, pos, chunk);
            pos += chunk;
            for (size_t n; (n = glz::fix::frame(buffer)) != 0 && n != glz::fix::frame_error;) {
               if (count >= whole.size() || buffer.compare(0, n, whole[count]) != 0) same = false;
               ++count;
               buffer.erase(0, n);
            }
         }
         expect(same);
         expect(count == whole.size());
      }
   };

   // test/data/fix.4.1.set.1: 16 FIX.4.1 messages followed by a newline
   "data_fix_4_1_set_1"_test = [] {
      const auto data = read_file("fix.4.1.set.1");
      expect(!data.empty());
      size_t leftover = 0;
      auto msgs = frame_all(data, leftover);
      expect(msgs.size() == 16u);
      expect(leftover == 1u); // trailing '\n'
      size_t ok = 0, orders = 0;
      for (auto m : msgs) {
         if (!glz::fix::validate(m)) ++ok;
         auto f = glz::fix::parse_fields(m);
         if (f && find(*f, 8)->value == "FIX.4.1" && find(*f, 35)->value == "D") ++orders;
      }
      expect(ok == msgs.size());
      expect(orders >= 1u);
   };

   // test/data/fix.5.0.set.2: 65 FIXT.1.1 messages
   "data_fix_5_0_set_2"_test = [] {
      const auto data = read_file("fix.5.0.set.2");
      expect(!data.empty());
      size_t leftover = 1;
      auto msgs = frame_all(data, leftover);
      expect(msgs.size() == 65u);
      expect(leftover == 0u);
      size_t ok = 0;
      for (auto m : msgs) {
         if (!glz::fix::validate(m)) ++ok;
         auto f = glz::fix::parse_fields(m);
         expect(f.has_value() && (*f)[0].value == "FIXT.1.1");
      }
      expect(ok == msgs.size());
   };

   skip("data_fix_5_0_set_1", "2 MB sample file from hffix test/data was not copied into the repository");
};

#ifdef GLZ_FIX_HAS_STRUCT_MAPPING
// writer01.cpp / reader01.cpp messages as glaze structs
struct hffix_logon
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   int msg_seq_num{};
   std::string sending_time{};
   int encrypt_method{};
   int heart_bt_int{};
};

template <>
struct glz::meta<hffix_logon>
{
   using T = hffix_logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "34", &T::msg_seq_num,
                                             "52", &T::sending_time, "98", &T::encrypt_method, "108", &T::heart_bt_int);
};

struct hffix_new_order
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   int msg_seq_num{};
   std::string sending_time{};
   std::string cl_ord_id{};
   char handl_inst{};
   std::string symbol{};
   char side{};
   std::string transact_time{};
   int order_qty{};
   char ord_type{};
   double price{};
   char time_in_force{};
};

template <>
struct glz::meta<hffix_new_order>
{
   using T = hffix_new_order;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value =
      glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "34", &T::msg_seq_num, "52", &T::sending_time,
                  "11", &T::cl_ord_id, "21", &T::handl_inst, "55", &T::symbol, "54", &T::side, "60", &T::transact_time,
                  "38", &T::order_qty, "40", &T::ord_type, "44", &T::price, "59", &T::time_in_force);
};

suite hffix_struct_mapping = [] {
   "reader01_struct"_test = [] {
      const auto data = read_file("writer01.fix");
      size_t leftover = 0;
      auto msgs = frame_all(data, leftover);
      expect(msgs.size() == 2u);
      if (msgs.size() != 2) return;
      hffix_logon logon{};
      expect(!glz::read<glz::fix_opts{}>(logon, msgs[0]));
      expect(logon.sender_comp_id == "AAAA");
      expect(logon.msg_seq_num == 1);
      expect(logon.heart_bt_int == 10);
      hffix_new_order nos{};
      expect(!glz::read<glz::fix_opts{}>(nos, msgs[1]));
      expect(nos.side == '1');
      expect(nos.symbol == "OIH");
      expect(nos.order_qty == 100);
      expect(nos.price == 500.01);
   };

   // writer01.cpp: write the same two messages and read them back (byte equality with
   // writer01.fix is not expected: hffix zero pads BodyLength to 6 digits)
   "writer01_roundtrip"_test = [] {
      hffix_new_order nos{"AAAA", "BBBB", 2, "20170809-12:34:56.000", "A1", '1', "OIH", '1',
                          "20170809-12:34:56.000", 100, '2', 500.01, '1'};
      std::string buffer;
      expect(!glz::write<glz::fix_opts{}>(nos, buffer));
      expect(!glz::fix::validate(buffer));
      hffix_new_order back{};
      expect(!glz::read<glz::fix_opts{}>(back, buffer));
      expect(back.cl_ord_id == "A1" && back.price == 500.01 && back.order_qty == 100);
   };

   // unit_tests.cpp: message_writer_bounds - field encodings
   "field_encodings"_test = [] {
      hffix_new_order nos{};
      nos.price = 123.456;
      nos.order_qty = 55;
      nos.side = 'a';
      std::string buffer;
      expect(!glz::write<glz::fix_opts{}>(nos, buffer));
      expect(buffer.find(soh("|44=123.456|")) != std::string::npos);
      expect(buffer.find(soh("|38=55|")) != std::string::npos);
      expect(buffer.find(soh("|54=a|")) != std::string::npos);
   };
};
#else
suite hffix_struct_mapping_skipped = [] {
   skip("reader01_struct / writer01_roundtrip / field_encodings",
        "need glz::read/glz::write<glz::fix_opts{}> from fix/core; define GLZ_FIX_HAS_STRUCT_MAPPING to build them");
};
#endif

int main() { return 0; }
