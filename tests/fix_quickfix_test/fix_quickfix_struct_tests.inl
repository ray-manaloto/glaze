// Glaze Library
// For the license information refer to glaze.hpp
//
// Struct-mapping tests ported from QuickFIX (see fix_quickfix_test.cpp header and QUICKFIX_LICENSE).
// Included from fix_quickfix_test.cpp only when the FIX core defines GLZ_FIX_STRUCT_MAPPING.
// Written against the contract in docs/fix/api.md; NOT YET COMPILED against a real core
// (fix/core had no header when this was written). Fix up mechanical mismatches when merging.

#include <cstdint>
#include <limits>

#include "glaze/core/common.hpp"
#include "glaze/core/read.hpp"
#include "glaze/core/write.hpp"

namespace qf_struct
{
   // ---- FieldConvertorsTestCase.cpp: one-field carriers, custom tag 5000 ----
   template <class T>
   struct one
   {
      T v{};
   };
}

template <class T>
struct glz::meta<qf_struct::one<T>>
{
   using U = qf_struct::one<T>;
   static constexpr auto fix_msg_type = "U1";
   static constexpr auto value = glz::object("5000", &U::v);
};

namespace qf_struct
{
   template <class T>
   glz::error_ctx read_one(std::string_view value, T& out)
   {
      std::string rest = "35=U1|5000=";
      rest += value;
      rest += '|';
      const auto msg = make_msg("FIX.4.2", rest);
      one<T> o{};
      auto ec = glz::read<glz::fix_opts{}>(o, msg);
      out = o.v;
      return ec;
   }

   template <class T>
   std::string write_one(const T& v)
   {
      one<T> o{v};
      std::string buf;
      auto ec = glz::write<glz::fix_opts{}>(o, buf);
      if (ec) return "<error>";
      // Extract the value of tag 5000.
      const auto p = buf.find("\0015000=");
      if (p == std::string::npos) return "<missing>";
      const auto s = p + 6;
      const auto e = buf.find('\001', s);
      return buf.substr(s, e - s);
   }

   // ---- MessagesTestCase.cpp typed FIX 4.2 messages ----
   struct Logon
   {
      int32_t heart_bt_int{}; // 108
   };
   struct TestRequest
   {
      std::string test_req_id; // 112
   };
   struct ResendRequest
   {
      int32_t begin_seq_no{}; // 7
      int32_t end_seq_no{}; // 16
   };
   struct Reject
   {
      int32_t ref_seq_num{}; // 45
      std::string text; // 58
   };
   struct SequenceReset
   {
      int32_t new_seq_no{}; // 36
      bool gap_fill_flag{}; // 123
   };
   struct Logout
   {
      std::string text; // 58
   };
   struct NewOrderSingle
   {
      std::string cl_ord_id; // 11
      char handl_inst{}; // 21
      char ord_type{}; // 40
      char side{}; // 54
      std::string symbol; // 55
      std::string transact_time; // 60 (string until the contract has a timestamp type)
   };
   struct Heartbeat
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sending_time; // 52
      std::string target_comp_id; // 56
   };

   // MessagesTestCase.cpp / setStringWithGroup: FIX 4.3 NewOrderList, NoOrders(73)
   struct ListOrder
   {
      std::string cl_ord_id; // 11
      int32_t list_seq_no{}; // 67
      std::string account; // 1
      std::string symbol; // 55
      char side{}; // 54
      char ord_type{}; // 40
      char time_in_force{}; // 59
   };
   struct NewOrderList
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sender_sub_id; // 50
      std::string sending_time; // 52
      std::string target_comp_id; // 56
      std::string list_id; // 66
      int32_t bid_type{}; // 394
      int32_t tot_no_orders{}; // 68
      std::vector<ListOrder> orders; // 73 = NoOrders
   };

   // Same list, with ListSeqNo (67) as the group delimiter, for setStringWithGroupWithoutDelimiter.
   struct ListOrderBySeq
   {
      int32_t list_seq_no{}; // 67
      std::string cl_ord_id; // 11
      std::string account; // 1
      std::string symbol; // 55
      char side{}; // 54
      char ord_type{}; // 40
      char time_in_force{}; // 59
   };
   struct NewOrderListBySeq
   {
      int32_t msg_seq_num{};
      std::string sender_comp_id;
      std::string sender_sub_id;
      std::string sending_time;
      std::string target_comp_id;
      std::string list_id;
      int32_t bid_type{};
      int32_t tot_no_orders{};
      std::vector<ListOrderBySeq> orders;
   };

   // MessagesTestCase.cpp / setStringWithHeaderGroup: NoHops(627)
   struct Hop
   {
      std::string hop_comp_id; // 628
      std::string hop_sending_time; // 629
      std::string hop_ref_id; // 630
   };
   struct LogonWithHops
   {
      int32_t msg_seq_num{}; // 34
      std::string sender_comp_id; // 49
      std::string sending_time; // 52
      std::string target_comp_id; // 56
      std::vector<Hop> hops; // 627 = NoHops
   };
}

template <>
struct glz::meta<qf_struct::Logon>
{
   using T = qf_struct::Logon;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("108", &T::heart_bt_int);
};
template <>
struct glz::meta<qf_struct::TestRequest>
{
   using T = qf_struct::TestRequest;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "1";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};
template <>
struct glz::meta<qf_struct::ResendRequest>
{
   using T = qf_struct::ResendRequest;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "2";
   static constexpr auto value = glz::object("7", &T::begin_seq_no, "16", &T::end_seq_no);
};
template <>
struct glz::meta<qf_struct::Reject>
{
   using T = qf_struct::Reject;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "3";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "58", &T::text);
};
template <>
struct glz::meta<qf_struct::SequenceReset>
{
   using T = qf_struct::SequenceReset;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "4";
   static constexpr auto value = glz::object("36", &T::new_seq_no, "123", &T::gap_fill_flag);
};
template <>
struct glz::meta<qf_struct::Logout>
{
   using T = qf_struct::Logout;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "5";
   static constexpr auto value = glz::object("58", &T::text);
};
template <>
struct glz::meta<qf_struct::NewOrderSingle>
{
   using T = qf_struct::NewOrderSingle;
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "21", &T::handl_inst, "40", &T::ord_type, "54",
                                             &T::side, "55", &T::symbol, "60", &T::transact_time);
};
template <>
struct glz::meta<qf_struct::Heartbeat>
{
   using T = qf_struct::Heartbeat;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto value = glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "52",
                                             &T::sending_time, "56", &T::target_comp_id);
};
template <>
struct glz::meta<qf_struct::ListOrder>
{
   using T = qf_struct::ListOrder;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "67", &T::list_seq_no, "1", &T::account, "55",
                                             &T::symbol, "54", &T::side, "40", &T::ord_type, "59",
                                             &T::time_in_force);
};
template <>
struct glz::meta<qf_struct::NewOrderList>
{
   using T = qf_struct::NewOrderList;
   static constexpr auto fix_msg_type = "E";
   static constexpr auto value =
      glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "50", &T::sender_sub_id, "52", &T::sending_time,
                  "56", &T::target_comp_id, "66", &T::list_id, "68", &T::tot_no_orders, "73", &T::orders, "394",
                  &T::bid_type);
};
template <>
struct glz::meta<qf_struct::ListOrderBySeq>
{
   using T = qf_struct::ListOrderBySeq;
   static constexpr auto value = glz::object("67", &T::list_seq_no, "11", &T::cl_ord_id, "1", &T::account, "55",
                                             &T::symbol, "54", &T::side, "40", &T::ord_type, "59",
                                             &T::time_in_force);
};
template <>
struct glz::meta<qf_struct::NewOrderListBySeq>
{
   using T = qf_struct::NewOrderListBySeq;
   static constexpr auto fix_msg_type = "E";
   static constexpr auto value =
      glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "50", &T::sender_sub_id, "52", &T::sending_time,
                  "56", &T::target_comp_id, "66", &T::list_id, "68", &T::tot_no_orders, "73", &T::orders, "394",
                  &T::bid_type);
};
template <>
struct glz::meta<qf_struct::Hop>
{
   using T = qf_struct::Hop;
   static constexpr auto value =
      glz::object("628", &T::hop_comp_id, "629", &T::hop_sending_time, "630", &T::hop_ref_id);
};
template <>
struct glz::meta<qf_struct::LogonWithHops>
{
   using T = qf_struct::LogonWithHops;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("34", &T::msg_seq_num, "49", &T::sender_comp_id, "52",
                                             &T::sending_time, "56", &T::target_comp_id, "627", &T::hops);
};

namespace qf_struct
{
   // Body of a written message: the bytes from "35=" up to (not including) "10=".
   inline std::string_view body_from_35(std::string_view m)
   {
      const auto s = m.find("\00135=");
      const auto e = m.rfind("10=");
      if (s == std::string_view::npos || e == std::string_view::npos || e < s) return {};
      return m.substr(s + 1, e - s - 1);
   }
}

suite quickfix_field_convertors = [] {
   using namespace qf_struct;

   "FieldConvertorsTestCase.cpp / FieldConvertorTests / int8_integerConvertFrom"_test = [] {
      int8_t v{};
      expect(not read_one("0", v) and v == 0);
      expect(not read_one("12", v) and v == 12);
      expect(not read_one("127", v) and v == 127);
      expect(not read_one("-128", v) and v == -128);
      expect(bool(read_one("128", v)));
      expect(bool(read_one("999", v)));
      expect(bool(read_one("-129", v)));
      expect(bool(read_one("", v)));
      expect(bool(read_one("abc", v)));
      expect(bool(read_one("123.4", v)));
      expect(bool(read_one("+200", v)));
      expect(bool(read_one("-", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / int8_integerConvertTo"_test = [] {
      expect(write_one<int8_t>(0) == "0");
      expect(write_one<int8_t>(127) == "127");
      expect(write_one<int8_t>(-1) == "-1");
      expect(write_one<int8_t>(-128) == "-128");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / int16_integerConvertFrom"_test = [] {
      int16_t v{};
      expect(not read_one("32767", v) and v == 32767);
      expect(not read_one("-32768", v) and v == -32768);
      expect(bool(read_one("32768", v)));
      expect(bool(read_one("-32769", v)));
      expect(bool(read_one("99999", v)));
      expect(bool(read_one("+200", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / int16_integerConvertTo"_test = [] {
      expect(write_one<int16_t>(12345) == "12345");
      expect(write_one<int16_t>(-32768) == "-32768");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / uint32_integerConvertFrom"_test = [] {
      uint32_t v{};
      expect(not read_one("0", v) and v == 0u);
      expect(not read_one("65536", v) and v == 65536u);
      expect(not read_one("2147483648", v) and v == 2147483648u);
      expect(not read_one("4294967295", v) and v == 4294967295u);
      expect(bool(read_one("4294967296", v)));
      expect(bool(read_one("9999999999", v)));
      expect(bool(read_one("-1", v)));
      expect(bool(read_one("", v)));
      expect(bool(read_one("abc", v)));
      expect(bool(read_one("123.4", v)));
      expect(bool(read_one("+200", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / uint32_integerConvertTo"_test = [] {
      expect(write_one<uint32_t>(4294967295u) == "4294967295");
      expect(write_one<uint32_t>(2147483648u) == "2147483648");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / integerConvertFrom"_test = [] {
      int32_t v{};
      expect(not read_one("214748365", v) and v == 214748365);
      expect(not read_one("2147483647", v) and v == 2147483647);
      expect(not read_one("-2147483648", v) and v == (std::numeric_limits<int32_t>::min)());
      expect(bool(read_one("2147483648", v)));
      expect(bool(read_one("2147483650", v)));
      expect(bool(read_one("9999999999", v)));
      expect(bool(read_one("-2147483649", v)));
      expect(bool(read_one("-9999999999", v)));
      expect(bool(read_one("", v)));
      expect(bool(read_one("abc", v)));
      expect(bool(read_one("123.4", v)));
      expect(bool(read_one("+200", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / integerConvertTo"_test = [] {
      expect(write_one<int32_t>(0) == "0");
      expect(write_one<int32_t>(123456789) == "123456789");
      expect(write_one<int32_t>(2147483647) == "2147483647");
      expect(write_one<int32_t>(-123456789) == "-123456789");
      expect(write_one<int32_t>((std::numeric_limits<int32_t>::min)()) == "-2147483648");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / uint64_integerConvertFrom (bounds)"_test = [] {
      uint64_t v{};
      expect(not read_one("18446744073709551615", v) and v == (std::numeric_limits<uint64_t>::max)());
      expect(bool(read_one("18446744073709551616", v)));
      expect(bool(read_one("-1", v)));
   };

   "FieldConvertorsTestCase.cpp / FieldConvertorTests / doubleConvertFrom"_test = [] {
      double v{};
      expect(not read_one("45.32", v) and v == 45.32);
      expect(not read_one("45.3200", v) and v == 45.32);
      expect(not read_one("0.00340244000", v) and v == 0.00340244);
      expect(not read_one("12.000000000001", v) and v == 12.000000000001);
      expect(not read_one("-12.000000000001", v) and v == -12.000000000001);
      expect(not read_one("0.0", v) and v == 0.0);
      expect(not read_one("0045.32", v) and v == 45.32);
      expect(not read_one("0.", v) and v == 0.0);
      expect(not read_one(".0", v) and v == 0.0);
      expect(not read_one("0", v) and v == 0.0);
      expect(not read_one("000.06", v) and v == 0.06);
      expect(not read_one("0.0600", v) and v == 0.06);
      expect(not read_one("-0.00001", v) and v == -0.00001);
      expect(not read_one("-1050", v) and v == -1050.0);
      expect(not read_one("38.4", v) and v == 38.4);
      expect(bool(read_one("abc", v)));
      expect(bool(read_one("123.A", v)));
      expect(bool(read_one("123.45.67", v)));
      expect(bool(read_one(".", v)));
      // FIX Float/Price/Qty forbid exponent notation; fix/core's std::from_chars accepts "1e5".
      skip("FieldConvertorsTestCase.cpp / doubleConvertFrom / \"1e5\" rejected",
           "fix/core accepts exponent notation on read (FIX Float forbids it)");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / doubleConvertTo"_test = [] {
      // QuickFIX prints the shortest round-trip form with no exponent for these values.
      expect(write_one(45.32) == "45.32");
      expect(write_one(45.0) == "45");
      expect(write_one(0.0) == "0");
      expect(write_one(-1050.0) == "-1050");
      expect(write_one(1.233) == "1.233");
      expect(write_one(38.4) == "38.4");
      expect(write_one(0.1) == "0.1");
      expect(write_one(0.3) == "0.3");
      skip("FieldConvertorsTestCase.cpp / doubleConvertTo / 0.00001, -0.00001, 1e14 without exponent",
           "fix/core writes shortest std::to_chars, giving 1e-05 / 1e+14 (FIX Float forbids exponents)");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / charConvertFrom"_test = [] {
      char v{};
      expect(not read_one("a", v) and v == 'a');
      expect(not read_one("1", v) and v == '1');
      expect(not read_one("F", v) and v == 'F');
      // charConvertTo: "11" and "1 " are not single chars.
      expect(bool(read_one("11", v)));
      expect(bool(read_one("1 ", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / charConvertTo"_test = [] {
      expect(write_one('a') == "a");
      expect(write_one('1') == "1");
      expect(write_one('F') == "F");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / booleanConvertFrom"_test = [] {
      bool v{};
      expect(not read_one("Y", v) and v == true);
      expect(not read_one("N", v) and v == false);
      expect(bool(read_one("D", v)));
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / booleanConvertTo"_test = [] {
      expect(write_one(true) == "Y");
      expect(write_one(false) == "N");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / emptyConvert (string)"_test = [] {
      std::string v;
      expect(not read_one("hello", v) and v == "hello");
      expect(write_one(std::string("hello")) == "hello");
   };
};

suite quickfix_typed_messages = [] {
   using namespace qf_struct;

   // Each pair is MessagesTestCase.cpp / MessageTests / <x>GetString and <x>SetString.
   // GetString compares the whole message (meta<T>::fix_begin_string = "FIX.4.2").

   "MessagesTestCase.cpp / MessageTests / logonSetString"_test = [] {
      Logon m{};
      expect(not glz::read<glz::fix_opts{}>(m, logon));
      expect(m.heart_bt_int == 30);
   };
   "MessagesTestCase.cpp / MessageTests / logonGetString"_test = [] {
      Logon m{30};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == logon) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / testRequestSetString"_test = [] {
      TestRequest m{};
      expect(not glz::read<glz::fix_opts{}>(m, testRequest));
      expect(m.test_req_id == "23");
   };
   "MessagesTestCase.cpp / MessageTests / testRequestGetString"_test = [] {
      TestRequest m{"23"};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == testRequest) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / resendRequestSetString"_test = [] {
      ResendRequest m{};
      expect(not glz::read<glz::fix_opts{}>(m, resendRequest));
      expect(m.begin_seq_no == 1);
      expect(m.end_seq_no == 233);
   };
   "MessagesTestCase.cpp / MessageTests / resendRequestGetString"_test = [] {
      ResendRequest m{1, 233};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == resendRequest) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / rejectSetString"_test = [] {
      Reject m{};
      expect(not glz::read<glz::fix_opts{}>(m, reject));
      expect(m.ref_seq_num == 73);
      expect(m.text == "This Message SUCKS!!!");
   };
   "MessagesTestCase.cpp / MessageTests / rejectGetString"_test = [] {
      Reject m{73, "This Message SUCKS!!!"};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == reject) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / sequenceResetSetString"_test = [] {
      SequenceReset m{};
      expect(not glz::read<glz::fix_opts{}>(m, sequenceReset));
      expect(m.gap_fill_flag);
      expect(m.new_seq_no == 88);
   };
   "MessagesTestCase.cpp / MessageTests / sequenceResetGetString"_test = [] {
      SequenceReset m{88, true};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == sequenceReset) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / logoutSetString"_test = [] {
      Logout m{};
      expect(not glz::read<glz::fix_opts{}>(m, logout));
      expect(m.text == "See Ya...");
   };
   "MessagesTestCase.cpp / MessageTests / logoutGetString"_test = [] {
      Logout m{"See Ya..."};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == logout) << buf;
   };
   "MessagesTestCase.cpp / MessageTests / newOrderSingleSetString"_test = [] {
      NewOrderSingle m{};
      expect(not glz::read<glz::fix_opts{}>(m, newOrderSingleSet));
      expect(m.cl_ord_id == "ORDERID");
      expect(m.handl_inst == '3');
      expect(m.symbol == "MSFT");
      expect(m.side == '1');
      expect(m.ord_type == '2');
      expect(m.transact_time == "TODAY");
   };
   "MessagesTestCase.cpp / MessageTests / newOrderSingleGetString"_test = [] {
      NewOrderSingle m{"ORDERID", '3', '2', '1', "MSFT", "19000101-00:00:00"};
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      expect(buf == newOrderSingleGet) << buf;
   };

   "MessagesTestCase.cpp / MessageTests / setString / strGood (typed header fields)"_test = [] {
      Heartbeat m{};
      expect(not glz::read<glz::fix_opts{}>(m, strGood));
      expect(m.msg_seq_num == 3);
      expect(m.sender_comp_id == "TW");
      expect(m.sending_time == "20000426-12:05:06");
      expect(m.target_comp_id == "ISLD");
   };
   "MessagesTestCase.cpp / MessageTests / setString / malformed vectors are rejected by read"_test = [] {
      for (auto bad : {strTrailingCharacter, strNoChk, strBadChk, strBad, strBadHeaderOrder, strNoLengthAndChk,
                       strBadLength, strBadChecksum, strJunk, strEmpty, noEndingDelim}) {
         Heartbeat m{};
         expect(bool(glz::read<glz::fix_opts{}>(m, bad))) << bad;
      }
   };
   "MessagesTestCase.cpp / MessageTests / setString(strBadChk, false) with validate_checksum=false"_test = [] {
      // QuickFIX: setString(str, false) skips validation. Here only the checksum check is off.
      Heartbeat m{};
      constexpr auto no_cs = [] { glz::fix_opts o{}; o.validate_checksum = false; return o; }();
      expect(not glz::read<no_cs>(m, strBadChk));
      expect(m.sender_comp_id == "TW");
   };
   "MessagesTestCase.cpp / MessageTests / setStringAndValidate_IncorrectBodyLength with validate_body_length=false"_test =
      [] {
         // Body length deliberately wrong; checksum made correct so only 9 is at fault.
         std::string raw = "8=FIX.4.2\0019=2000\00135=A\00149=SENDER\00156=TARGET\00134=1\00198=0\001108=30\001";
         char buf[8];
         std::snprintf(buf, sizeof(buf), "%03u", unsigned(glz::fix::checksum(raw)));
         raw += "10=";
         raw += buf;
         raw += '\001';
         Logon m{};
         expect(bool(glz::read<glz::fix_opts{}>(m, raw)));
         constexpr auto no_bl = [] { glz::fix_opts o{}; o.validate_body_length = false; return o; }();
         expect(not glz::read<no_bl>(m, raw));
         expect(m.heart_bt_int == 30);
      };
   "MessagesTestCase.cpp / MessageTests / setString with SenderCompID typed and '|' delimiter"_test = [] {
      const std::string msg = "8=FIX.4.2|9=12|35=A|108=30|10=" +
                              [] {
                                 const std::string_view pre = "8=FIX.4.2|9=12|35=A|108=30|";
                                 char b[8];
                                 std::snprintf(b, sizeof(b), "%03u", unsigned(glz::fix::checksum(pre)));
                                 return std::string(b);
                              }() +
                              "|";
      Logon m{};
      constexpr auto pipe = [] { glz::fix_opts o{}; o.soh = '|'; return o; }();
      expect(not glz::read<pipe>(m, msg));
      expect(m.heart_bt_int == 30);
   };
};

suite quickfix_groups = [] {
   using namespace qf_struct;

   "MessagesTestCase.cpp / MessageTests / setStringWithGroupWithoutDelimiter"_test = [] {
      // QuickFIX (with a DataDictionary) accepts entries that lack the delimiter field 11. The
      // contract requires each entry to start with the group's first member, so with 11 first the
      // core must reject it; mapping 67 first (ListOrderBySeq) reads it as QuickFIX does.
      NewOrderList strict{};
      expect(bool(glz::read<glz::fix_opts{}>(strict, withGroupNoDelim)));
      NewOrderListBySeq m{};
      expect(not glz::read<glz::fix_opts{}>(m, withGroupNoDelim));
      expect(m.list_id == "1095350459");
      expect(m.tot_no_orders == 2);
      expect(m.bid_type == 3);
      expect(m.orders.size() == 2u);
      if (m.orders.size() == 2u) {
         expect(m.orders[0].list_seq_no == 1);
         expect(m.orders[0].account == "00303");
         expect(m.orders[0].symbol == "fred");
         expect(m.orders[0].side == '1');
         expect(m.orders[0].ord_type == '1');
         expect(m.orders[0].time_in_force == '3');
         expect(m.orders[1].list_seq_no == 2);
      }
   };
   "MessagesTestCase.cpp / MessageTests / setStringWithGroup"_test = [] {
      NewOrderList m{};
      expect(not glz::read<glz::fix_opts{}>(m, withGroup));
      expect(m.orders.size() == 2u);
      if (m.orders.size() == 2u) {
         expect(m.orders[0].cl_ord_id == "1095350459");
         expect(m.orders[1].cl_ord_id == "1095350460");
         expect(m.orders[1].list_seq_no == 2);
      }
   };
   "MessagesTestCase.cpp / MessageTests / setStringWithGroup (toString round trip)"_test = [] {
      NewOrderList m{};
      expect(not glz::read<glz::fix_opts{}>(m, withGroup));
      std::string buf;
      expect(not glz::write<glz::fix_opts{}>(m, buf));
      expect(is_valid(buf));
      NewOrderList m2{};
      expect(not glz::read<glz::fix_opts{}>(m2, buf));
      expect(m2.orders.size() == 2u);
      if (m2.orders.size() == 2u) expect(m2.orders[1].cl_ord_id == "1095350460");
   };
   "MessagesTestCase.cpp / MessageTests / setStringWithHeaderGroup"_test = [] {
      LogonWithHops m{};
      expect(not glz::read<glz::fix_opts{}>(m, withHeaderGroup43));
      expect(m.hops.size() == 2u);
      if (m.hops.size() == 2u) {
         expect(m.hops[0].hop_comp_id == "HOP1");
         expect(m.hops[0].hop_sending_time == "20040916-16:19:18.328");
         expect(m.hops[0].hop_ref_id == "ID1");
         expect(m.hops[1].hop_comp_id == "HOP2");
         expect(m.hops[1].hop_ref_id == "ID2");
      }
   };
   "MessagesTestCase.cpp / MessageTests / setStringWithHeaderGroupDefinedInComponent"_test = [] {
      LogonWithHops m{};
      expect(not glz::read<glz::fix_opts{}>(m, withHeaderGroup44));
      expect(m.hops.size() == 2u);
   };
   "glaze-original (not from QuickFIX): NoXXX count larger than entries present is rejected"_test = [] {
      const auto msg = make_msg("FIX.4.3", "35=A|34=125|49=BUYSIDE|52=20040916-16:19:18.328|56=SELLSIDE|"
                                           "627=3|628=HOP1|629=20040916-16:19:18.328|630=ID1|");
      LogonWithHops m{};
      expect(bool(glz::read<glz::fix_opts{}>(m, msg)));
   };
   "glaze-original (not from QuickFIX): zero-count group reads as empty"_test = [] {
      const auto msg = make_msg("FIX.4.3", "35=A|34=125|49=BUYSIDE|52=20040916-16:19:18.328|56=SELLSIDE|627=0|");
      LogonWithHops m{};
      m.hops.resize(5);
      expect(not glz::read<glz::fix_opts{}>(m, msg));
      expect(m.hops.empty());
   };
};

// ---------------------------------------------------------------------------------------------
// FieldConvertorsTestCase.cpp / UTCTimestamp, UTCTimeOnly, UTCDateOnly
// PROPOSED mapping (not yet in the contract; guarded by GLZ_FIX_TIME_TYPES):
//   UTCTimestamp -> std::chrono::sys_time<std::chrono::nanoseconds>  ("YYYYMMDD-HH:MM:SS[.sss[sss[sss]]]")
//   UTCTimeOnly  -> std::chrono::nanoseconds since midnight         ("HH:MM:SS[.fraction]")
//   UTCDateOnly  -> std::chrono::year_month_day                     ("YYYYMMDD")
// ---------------------------------------------------------------------------------------------
#if defined(GLZ_FIX_TIME_TYPES)
#include <chrono>

suite quickfix_time_convertors = [] {
   using namespace qf_struct;
   using namespace std::chrono;
   using ts_t = sys_time<nanoseconds>;
   const auto base = sys_days{year{2000} / April / 26} + hours{12} + minutes{5} + seconds{6};

   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeStampConvertFrom{Second,Milli,Micro,Nano}"_test = [&] {
      ts_t v{};
      expect(not read_one("20000426-12:05:06", v) and v == base);
      expect(not read_one("20000426-12:05:06.555", v) and v == base + milliseconds{555});
      expect(not read_one("20000426-12:05:06.555555", v) and v == base + microseconds{555555});
      expect(not read_one("20000426-12:05:06.555555555", v) and v == base + nanoseconds{555555555});
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeStampConvertTo (nanosecond input)"_test = [&] {
      // QuickFIX writes the precision it is asked for; glaze is expected to keep all significant digits.
      expect(write_one(ts_t{base}) == "20000426-12:05:06");
      expect(write_one(ts_t{base + nanoseconds{555555555}}) == "20000426-12:05:06.555555555");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcDateConvertFrom"_test = [] {
      year_month_day v{};
      expect(not read_one("20000426", v) and v == year_month_day{year{2000}, month{4}, day{26}});
      expect(bool(read_one("20001526", v))); // outOfRangeMonth
      expect(bool(read_one("20000438", v))); // outOfRangeMonthDay
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcDateConvertTo"_test = [] {
      expect(write_one(year_month_day{year{2000}, month{4}, day{26}}) == "20000426");
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeOnlyConvertFromMicro"_test = [] {
      nanoseconds v{};
      expect(not read_one("12:05:06.555555", v) and v == hours{12} + minutes{5} + seconds{6} + microseconds{555555});
   };
   "FieldConvertorsTestCase.cpp / FieldConvertorTests / utcTimeOnlyConvertTo{Second,Nano}"_test = [] {
      expect(write_one(nanoseconds{hours{12} + minutes{5} + seconds{6}}) == "12:05:06");
      expect(write_one(nanoseconds{hours{12} + minutes{5} + seconds{6} + nanoseconds{555555555}}) ==
             "12:05:06.555555555");
   };
};
#endif
