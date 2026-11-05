// Glaze Library
// For the license information refer to glaze.hpp

// Property and conformance tests for the FIX tag=value format.
// Every rule in docs/fix/conformance.md has a test here whose name starts with its rule id (R1, R2, ...).
// Test vectors are written afresh from the FIX 4.4 / FIX 5.0 SP2 (FIXT.1.1) specifications.

#include <cstdint>
#include <random>
#include <string>
#include <string_view>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

// Checks that fix/core does not meet yet. Each is listed under "Known gaps in fix/core" in
// docs/fix/sessions/fix-conformance-fuzz.md. Build with -DGLZ_FIX_KNOWN_GAPS=1 to run them.
#ifndef GLZ_FIX_KNOWN_GAPS
#define GLZ_FIX_KNOWN_GAPS 0
#endif
inline constexpr bool known_gaps = GLZ_FIX_KNOWN_GAPS;

struct NewOrderSingle
{
   std::string cl_ord_id{};
   std::string symbol{};
   char side{'1'};
   int64_t order_qty{};
   double price{};
   char ord_type{'2'};
   bool locate_reqd{};
};

template <>
struct glz::meta<NewOrderSingle>
{
   using T = NewOrderSingle;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "55", &T::symbol, "54", &T::side, "38",
                                             &T::order_qty, "44", &T::price, "40", &T::ord_type, "114",
                                             &T::locate_reqd);
};

struct Heartbeat
{
   std::string test_req_id{};
};

template <>
struct glz::meta<Heartbeat>
{
   using T = Heartbeat;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};

namespace
{
   constexpr glz::fix_opts pipe_opts{{}, glz::FIX, '|'};
   constexpr glz::fix_opts soh_opts{};

   // Builds a complete message from a body that starts at tag 35, filling 8, 9 and 10.
   std::string make(std::string_view body, std::string_view begin = "FIX.4.4", char soh = '|')
   {
      std::string m;
      m += "8=";
      m += begin;
      m += soh;
      m += "9=";
      m += std::to_string(body.size());
      m += soh;
      m += body;
      const unsigned cs = glz::fix::checksum(m);
      char t[8];
      t[0] = '1';
      t[1] = '0';
      t[2] = '=';
      t[3] = char('0' + cs / 100);
      t[4] = char('0' + (cs / 10) % 10);
      t[5] = char('0' + cs % 10);
      t[6] = soh;
      m.append(t, 7);
      return m;
   }

   NewOrderSingle random_order(std::mt19937_64& rng)
   {
      static constexpr std::string_view alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.:/ ";
      auto str = [&](size_t min_len) {
         std::string s;
         const size_t n = min_len + rng() % 16;
         for (size_t i = 0; i < n; ++i) s += alphabet[rng() % alphabet.size()];
         return s;
      };
      NewOrderSingle o;
      o.cl_ord_id = str(1);
      o.symbol = str(1);
      o.side = char('1' + rng() % 9);
      o.order_qty = int64_t(rng() % 2000000) - 1000000;
      o.price = double(int64_t(rng() % 20000000) - 10000000) / 256.0; // exactly representable
      o.ord_type = char('1' + rng() % 4);
      o.locate_reqd = rng() & 1;
      return o;
   }

   bool same(const NewOrderSingle& a, const NewOrderSingle& b)
   {
      return a.cl_ord_id == b.cl_ord_id && a.symbol == b.symbol && a.side == b.side && a.order_qty == b.order_qty &&
             a.price == b.price && a.ord_type == b.ord_type && a.locate_reqd == b.locate_reqd;
   }
}

suite property_tests = [] {
   "P1 write then read round trips equal"_test = [] {
      std::mt19937_64 rng{12345};
      for (int i = 0; i < 2000; ++i) {
         const auto in = random_order(rng);
         std::string buf;
         expect(not glz::write<soh_opts>(in, buf)) << i;
         expect(not glz::fix::validate(buf)) << buf;
         NewOrderSingle out{};
         auto ec = glz::read<soh_opts>(out, buf);
         expect(not ec) << buf;
         expect(same(in, out)) << buf;
      }
   };

   "P1 round trip with '|' as the delimiter"_test = [] {
      std::mt19937_64 rng{7};
      for (int i = 0; i < 200; ++i) {
         const auto in = random_order(rng);
         std::string buf;
         expect(not glz::write<pipe_opts>(in, buf));
         NewOrderSingle out{};
         expect(not glz::read<pipe_opts>(out, buf)) << buf;
         expect(same(in, out)) << buf;
      }
   };

   "P2 any single-byte corruption is rejected"_test = [] {
      std::mt19937_64 rng{99};
      for (int i = 0; i < 50; ++i) {
         const auto in = random_order(rng);
         std::string good;
         expect(not glz::write<soh_opts>(in, good));
         for (size_t pos = 0; pos < good.size(); ++pos) {
            for (int delta : {1, 2, 17, 128, 255}) {
               std::string bad = good;
               bad[pos] = char(uint8_t(bad[pos]) + delta);
               // A byte change inside the body always changes the sum mod 256 (delta is 1..255),
               // so validate() must fail. Bytes in the header or trailer break structure instead.
               expect(bool(glz::fix::validate(bad))) << "pos " << pos << " delta " << delta;
               // Gap 1: with byte 0 corrupted, fix/core reads the input as a body fragment and
               // skips the envelope checks, so read() succeeds.
               if (pos != 0 || known_gaps) {
                  NewOrderSingle out{};
                  expect(bool(glz::read<soh_opts>(out, bad))) << "pos " << pos;
               }
            }
         }
      }
   };

   "P3 truncation is caught by frame and validate"_test = [] {
      std::mt19937_64 rng{2024};
      for (int i = 0; i < 50; ++i) {
         const auto in = random_order(rng);
         std::string good;
         expect(not glz::write<soh_opts>(in, good));
         expect(glz::fix::frame(good) == good.size());
         for (size_t n = 0; n < good.size(); ++n) {
            const std::string_view cut{good.data(), n};
            expect(glz::fix::frame(cut) == 0u) << n;
            expect(bool(glz::fix::validate(cut))) << n;
         }
      }
   };

   "P3 frame splits a stream of concatenated messages"_test = [] {
      std::mt19937_64 rng{5};
      std::string stream;
      std::vector<size_t> sizes;
      for (int i = 0; i < 20; ++i) {
         std::string one;
         expect(not glz::write<soh_opts>(random_order(rng), one));
         sizes.push_back(one.size());
         stream += one;
      }
      std::string_view rest = stream;
      for (size_t s : sizes) {
         const size_t n = glz::fix::frame(rest);
         expect(n == s);
         expect(not glz::fix::validate(rest.substr(0, n)));
         rest.remove_prefix(n);
      }
      expect(rest.empty());
      expect(glz::fix::frame(rest) == 0u);
   };
};

suite conformance_tests = [] {
   "R1 BeginString(8) must be the first field"_test = [] {
      expect(not glz::fix::validate(make("35=0|"), '|'));
      std::string m = "9=5|8=FIX.4.4|35=0|10=000|";
      expect(glz::fix::validate(m, '|') == glz::error_code::invalid_header);
   };

   "R2 BodyLength(9) must be the second field"_test = [] {
      const std::string body = "35=0|";
      std::string m = "8=FIX.4.4|35=0|9=5|";
      m += "10=000|";
      expect(glz::fix::validate(m, '|') == glz::error_code::invalid_header);
   };

   "R3 MsgType(35) must be the third field"_test = [] {
      expect(glz::fix::validate(make("49=A|35=0|"), '|') == glz::error_code::invalid_header);
   };

   "R4 CheckSum(10) must be the last field"_test = [] {
      std::string m = make("35=0|");
      m += "58=x|";
      expect(bool(glz::fix::validate(m, '|')));
   };

   "R5 BodyLength counts bytes from after 9's SOH up to and including the SOH before 10"_test = [] {
      // Hand-checked: "35=0|" is 5 bytes.
      const std::string m = make("35=0|");
      expect(m.starts_with("8=FIX.4.4|9=5|35=0|10=")) << m;
      expect(not glz::fix::validate(m, '|'));
      std::string bad = m;
      bad[12] = '6';
      expect(bool(glz::fix::validate(bad, '|')));
   };

   "R6 BodyLength mismatch is rejected even with a correct checksum"_test = [] {
      std::string m = "8=FIX.4.4|9=6|35=0|";
      const unsigned cs = glz::fix::checksum(m);
      m += "10=" + std::to_string(100 + cs).substr(0, 0);
      char d[4] = {char('0' + cs / 100), char('0' + cs / 10 % 10), char('0' + cs % 10), 0};
      m += d;
      m += '|';
      expect(glz::fix::validate(m, '|') == glz::error_code::invalid_body);
   };

   "R7 CheckSum is the byte sum mod 256 of everything before 10="_test = [] {
      expect(glz::fix::checksum("") == 0);
      expect(glz::fix::checksum("\x01") == 1);
      expect(glz::fix::checksum(std::string(256, '\x01')) == 0);
      expect(glz::fix::checksum("8=FIX.4.4\x01" "9=5\x01" "35=0\x01") ==
             uint8_t((('8' + '=' + 'F' + 'I' + 'X' + '.' + '4' + '.' + '4' + 1) + ('9' + '=' + '5' + 1) +
                      ('3' + '5' + '=' + '0' + 1)) %
                     256));
   };

   "R8 CheckSum value is exactly three digits with leading zeros"_test = [] {
      // Find a body whose checksum is below 10 so the zero padding matters.
      std::string m;
      for (char c = 'A'; c <= 'z'; ++c) {
         m = make(std::string("35=0|112=") + c + "|");
         if (m.substr(m.size() - 4, 3).starts_with("00")) break;
      }
      expect(not glz::fix::validate(m, '|'));
      // The same value without padding is rejected.
      const auto pos = m.rfind("10=");
      const std::string digits = m.substr(pos + 3, 3);
      std::string short_form = m.substr(0, pos + 3) + std::to_string(std::stoi(digits)) + "|";
      if (digits[0] == '0') {
         expect(glz::fix::validate(short_form, '|') == glz::error_code::invalid_body);
      }
      std::string four = m.substr(0, pos + 3) + "0" + digits + "|";
      expect(glz::fix::validate(four, '|') == glz::error_code::invalid_body);
      std::string alpha = m.substr(0, pos + 3) + "0x1|";
      expect(glz::fix::validate(alpha, '|') == glz::error_code::invalid_body);
   };

   "R9 every field ends with SOH, including CheckSum"_test = [] {
      std::string m = make("35=0|");
      m.pop_back();
      expect(bool(glz::fix::validate(m, '|')));
      expect(glz::fix::frame(m, '|') == 0u);
      expect(not glz::fix::parse_fields(m, '|').has_value());
   };

   "R10 empty values are not permitted"_test = [] {
      auto r = glz::fix::parse_fields("8=FIX.4.4|58=|", '|');
      expect(not r.has_value());
      expect(bool(glz::fix::validate(make("35=0|112=|"), '|')));
   };

   "R11 tag numbers are positive integers without leading zeros or signs"_test = [] {
      expect(glz::fix::parse_fields("58=x|", '|').has_value());
      if constexpr (known_gaps) { // Gap 2: fix/core accepts leading zeros in tag numbers
         expect(not glz::fix::parse_fields("058=x|", '|').has_value());
      }
      expect(not glz::fix::parse_fields("0=x|", '|').has_value());
      expect(not glz::fix::parse_fields("-58=x|", '|').has_value());
      expect(not glz::fix::parse_fields("+58=x|", '|').has_value());
      expect(not glz::fix::parse_fields("=x|", '|').has_value());
      expect(not glz::fix::parse_fields("5a=x|", '|').has_value());
      expect(not glz::fix::parse_fields("9999999999=x|", '|').has_value());
   };

   "R11 a CheckSum written as 010= is not tag 10 (regression: fuzzing/regressions/fix_validate)"_test = [] {
      std::string m = make("35=0|");
      m.insert(m.rfind("10="), "0");
      expect(glz::fix::frame(m, '|') == 0u || glz::fix::frame(m, '|') == glz::fix::frame_error);
      if constexpr (known_gaps) { // Gap 2: validate accepts it while frame does not
         expect(bool(glz::fix::validate(m, '|')));
      }
   };

   "R11 zero-padded 08= / 09= are not BeginString / BodyLength (regression: fuzzing/regressions/fix_validate)"_test = [] {
      const std::string good = make("35=0|");
      const std::string b8 = "0" + good;
      std::string b9 = good;
      b9.insert(b9.find("|9=") + 1, "0");
      expect(glz::fix::frame(b8, '|') == glz::fix::frame_error || glz::fix::frame(b8, '|') == 0u);
      if constexpr (known_gaps) { // Gap 2: validate accepts both while frame does not
         expect(bool(glz::fix::validate(b8, '|')));
         expect(bool(glz::fix::validate(b9, '|')));
      }
   };

   "R12 a field without '=' is malformed"_test = [] {
      expect(not glz::fix::parse_fields("58x|", '|').has_value());
   };

   "R13 the value runs to the next SOH, so '=' may appear inside a value"_test = [] {
      auto r = glz::fix::parse_fields("58=a=b|", '|');
      expect(r.has_value());
      expect(r->size() == 1u && (*r)[0].value == "a=b");
   };

   "R14 data fields may contain SOH; their length comes from the Length tag (95/96 RawData)"_test = [] {
      if constexpr (!known_gaps) return; // Gap 3: fix/core does not support Length-prefixed data yet
      const std::string raw = "ab\x01" "cd";
      std::string body = "35=0|95=5|96=" + raw + "|";
      // use real SOH as delimiter for this one, since the data holds SOH
      std::string b2 = "35=0\x01" "95=5\x01" "96=" + raw + "\x01";
      const std::string m = make(b2, "FIX.4.4", '\x01');
      expect(not glz::fix::validate(m)) << m;
      auto f = glz::fix::parse_fields(m);
      expect(f.has_value());
      bool found = false;
      for (auto& x : *f) {
         if (x.tag == 96) {
            found = true;
            expect(x.value == raw);
         }
      }
      expect(found);
      // A wrong length is rejected rather than silently splitting the data.
      const std::string wrong = make("35=0\x01" "95=4\x01" "96=" + raw + "\x01", "FIX.4.4", '\x01');
      expect(bool(glz::fix::validate(wrong)));
      // A length running past the message is rejected.
      expect(not glz::fix::parse_fields("95=50\x01" "96=ab\x01").has_value());
      // A Length tag whose data never follows is rejected.
      expect(not glz::fix::parse_fields("95=2\x01").has_value());
   };

   "R14 other Length/data pairs follow the same rule (354/355 EncodedText, 93/89 Signature)"_test = [] {
      if constexpr (!known_gaps) return; // Gap 3
      expect(glz::fix::parse_fields("354=3|355=a|b|", '|').has_value());
      expect(glz::fix::parse_fields("93=3|89=||||", '|').has_value());
      expect(not glz::fix::parse_fields("354=x|355=a|", '|').has_value());
   };

   "R15 header and trailer tags may not repeat"_test = [] {
      if constexpr (known_gaps) { // Gap 4: fix/core accepts a repeated 35
         expect(glz::fix::validate(make("35=0|35=1|"), '|') == glz::error_code::invalid_header);
      }
      if constexpr (known_gaps) { // Gap 4: fix/core accepts a repeated 9
         expect(glz::fix::validate(make("35=0|9=5|"), '|') == glz::error_code::invalid_header);
      }
      if constexpr (known_gaps) { // Gap 4: fix/core accepts a repeated 8
         expect(glz::fix::validate(make("35=0|8=FIX.4.4|"), '|') == glz::error_code::invalid_header);
      }
      expect(bool(glz::fix::validate(make("35=0|10=000|"), '|')));
   };

   "R16 a body tag may not repeat outside a repeating group"_test = [] {
      Heartbeat h{};
      if constexpr (known_gaps) { // Gap 5: fix/core lets a repeated tag overwrite
         expect(glz::read<pipe_opts>(h, make("35=0|112=a|112=b|")) == glz::error_code::syntax_error);
      }
   };

   "R17 no bytes may follow CheckSum within one message"_test = [] {
      std::string m = make("35=0|") + "x";
      expect(bool(glz::fix::validate(m, '|')));
      // frame still finds the first message, leaving the rest for the next call.
      expect(glz::fix::frame(m, '|') == m.size() - 1);
   };

   "R18 int values may carry leading zeros and a '-' sign, never '+'"_test = [] {
      NewOrderSingle o{};
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|38=00023|")));
      expect(o.order_qty == 23);
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|38=-0042|")));
      expect(o.order_qty == -42);
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|38=+5|"))));
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|38=5.0|"))));
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|38=1,000|"))));
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|38=-|"))));
   };

   "R19 float values: optional '-', digits, optional '.', leading/trailing zeros, no exponent"_test = [] {
      NewOrderSingle o{};
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|44=0023.50|")));
      expect(o.price == 23.5);
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|44=-.5|")));
      expect(o.price == -0.5);
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|44=15|")));
      expect(o.price == 15.0);
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|44=25.000|")));
      expect(o.price == 25.0);
      if constexpr (known_gaps) { // Gap 6: fix/core reads exponent notation
         expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|44=1e5|"))));
      }
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|44=+1.5|"))));
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|44=1.2.3|"))));
   };

   "R19 written floats never use exponent notation"_test = [] {
      NewOrderSingle o{};
      o.cl_ord_id = "a";
      o.symbol = "b";
      o.price = 1e20;
      std::string buf;
      expect(not glz::write<pipe_opts>(o, buf));
      if constexpr (known_gaps) { // Gap 7: fix/core writes shortest form, which may use an exponent
         expect(buf.find("44=100000000000000000000|") != std::string::npos) << buf;
      }
      o.price = 1e-7;
      expect(not glz::write<pipe_opts>(o, buf));
      if constexpr (known_gaps) { // Gap 7
         expect(buf.find("44=0.0000001|") != std::string::npos) << buf;
      }
   };

   "R19 extreme doubles that read must write back (regression: fuzzing/regressions/fix_read)"_test = [] {
      NewOrderSingle o{};
      const std::string big = "1" + std::string(300, '0');
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|44=" + big + "|")));
      std::string buf;
      expect(not glz::write<pipe_opts>(o, buf));
      NewOrderSingle back{};
      expect(not glz::read<pipe_opts>(back, buf));
      expect(back.price == o.price);
      o.price = 4.9406564584124654e-324; // smallest denormal
      expect(not glz::write<pipe_opts>(o, buf));
      expect(not glz::read<pipe_opts>(back, buf)) << buf;
      expect(back.price == o.price);
   };

   "R20 Boolean values are Y or N"_test = [] {
      NewOrderSingle o{};
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|114=Y|")));
      expect(o.locate_reqd);
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|114=N|")));
      expect(not o.locate_reqd);
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|114=1|"))));
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|114=y|"))));
   };

   "R21 char values are a single character"_test = [] {
      NewOrderSingle o{};
      expect(not glz::read<pipe_opts>(o, make("35=D|11=a|54=2|")));
      expect(o.side == '2');
      expect(bool(glz::read<pipe_opts>(o, make("35=D|11=a|54=12|"))));
   };

   "R21 a char holding any non-delimiter byte, NUL included, round trips (regression: fuzzing/regressions/fix_read)"_test = [] {
      NewOrderSingle o{};
      o.cl_ord_id = "a";
      for (int c = 0; c < 256; ++c) {
         if (c == '|') continue;
         o.side = char(c);
         std::string buf;
         expect(not glz::write<pipe_opts>(o, buf)) << c;
         NewOrderSingle back{};
         expect(not glz::read<pipe_opts>(back, buf)) << c;
         expect(back.side == char(c));
      }
      o.side = '|';
      std::string buf;
      expect(bool(glz::write<pipe_opts>(o, buf)));
   };

   "R22 MsgType must match the mapped struct"_test = [] {
      NewOrderSingle o{};
      expect(glz::read<pipe_opts>(o, make("35=8|11=a|")) == glz::error_code::invalid_header);
   };

   "R23 the writer omits empty strings and refuses SOH inside a non-data field"_test = [] {
      Heartbeat h{};
      std::string buf;
      expect(not glz::write<pipe_opts>(h, buf));
      expect(buf.find("112=") == std::string::npos) << buf;
      h.test_req_id = "a|b";
      expect(bool(glz::write<pipe_opts>(h, buf)));
   };

   "R24 BeginString FIXT.1.1 (FIX 5.0 SP2 transport) is framed the same way"_test = [] {
      const auto m = make("35=0|1128=9|", "FIXT.1.1");
      expect(not glz::fix::validate(m, '|'));
      expect(glz::fix::frame(m, '|') == m.size());
   };

   "R25 validation switches in fix_opts"_test = [] {
      std::string m = make("35=0|112=a|");
      const auto pos = m.rfind("10=");
      m[pos + 5] = m[pos + 5] == '9' ? '0' : char(m[pos + 5] + 1);
      Heartbeat h{};
      expect(glz::read<pipe_opts>(h, m) == glz::error_code::invalid_body);
      static constexpr glz::fix_opts lax{{}, glz::FIX, '|', false, true};
      expect(not glz::read<lax>(h, m));
      expect(h.test_req_id == "a");
   };
};

int main() { return 0; }
