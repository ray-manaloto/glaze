// Glaze Library
// For the license information refer to glaze.hpp
//
// FIX test cases ported from hffix (https://github.com/jamesdbrock/hffix, BSD-2-Clause),
// commit 797ce7db0bd1c240acee88fad297b69bec428778, that are NOT already covered by
// tests/fix_hffix_test/*.cpp on origin/fix/tests-hffix-fixpp. See SOURCES.md next to this file.

#include <chrono>
#include <optional>
#include <string>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
   constexpr auto opts = glz::fix::pipe_opts;

   std::string soh(std::string s)
   {
      for (auto& c : s)
         if (c == '|') c = '\x01';
      return s;
   }

   // hffix test/data/fix.5.0.set.1 (JSE market data, FIXT.1.1): first MarketDataIncrementalRefresh.
   const std::string set1_x = soh(
      "8=FIXT.1.1|9=169|35=X|52=20111124-06:28:56.151|1180=JSEFTSEP|1181=82|268=2|279=0|55=JA00|269=x|58=LIVE|"
      "273=06:30:00.000|83=1|279=0|55=JA00|269=3|270=76.79|451=1.03|273=06:30:00.000|83=1|10=105|");
   // hffix test/data/fix.5.0.set.1: first two heartbeats (identical bytes in the capture).
   const std::string set1_hb = soh("8=FIXT.1.1|9=44|35=0|52=20111124-05:33:31.763|1180=JSEFTSEP|10=095|");
   constexpr glz::fix_opts soh_opts{};

   // Build a pipe-delimited message with correct BodyLength and CheckSum from a body ("35=..|...|").
   std::string envelope(std::string_view begin, std::string_view body)
   {
      std::string m = "8=" + std::string(begin) + "|9=" + std::to_string(body.size()) + "|" + std::string(body);
      const unsigned sum = glz::fix::checksum(m);
      char buf[4]{};
      buf[0] = char('0' + sum / 100);
      buf[1] = char('0' + (sum / 10) % 10);
      buf[2] = char('0' + sum % 10);
      return m + "10=" + buf + "|";
   }

   // Minimal message is 26 bytes ("8=FIX.4.2|9=5|35=A|10=ddd|"); extra body bytes may widen tag 9.
   size_t bounds_size(size_t extra)
   {
      const size_t body = 5 + extra;
      return 26 + extra + (body >= 10 ? 1 : 0) + (body >= 100 ? 1 : 0);
   }
}

struct MDEntry
{
   char update_action{}; // 279 (group delimiter)
   std::string symbol{}; // 55
   char entry_type{}; // 269
   std::optional<std::string> text{}; // 58
   std::optional<double> px{}; // 270
   std::optional<double> net_chg{}; // 451
   std::string entry_time{}; // 273
   int rpt_seq{}; // 83
};

template <>
struct glz::meta<MDEntry>
{
   using T = MDEntry;
   static constexpr auto value = glz::object("279", &T::update_action, "55", &T::symbol, "269", &T::entry_type, "58",
                                             &T::text, "270", &T::px, "451", &T::net_chg, "273", &T::entry_time,
                                             "83", &T::rpt_seq);
};

struct MDIncremental
{
   glz::fix::utc_timestamp sending_time{}; // 52
   std::string appl_id{}; // 1180
   int appl_seq{}; // 1181
   std::vector<MDEntry> entries{}; // 268
};

template <>
struct glz::meta<MDIncremental>
{
   using T = MDIncremental;
   static constexpr auto fix_msg_type = "X";
   static constexpr auto fix_begin_string = "FIXT.1.1";
   static constexpr auto value =
      glz::object("52", &T::sending_time, "1180", &T::appl_id, "1181", &T::appl_seq, "268", &T::entries);
};

struct JseHeartbeat
{
   std::string sending_time{};
   std::string appl_id{};
};

template <>
struct glz::meta<JseHeartbeat>
{
   using T = JseHeartbeat;
   static constexpr auto fix_msg_type = "0";
   static constexpr auto fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("52", &T::sending_time, "1180", &T::appl_id);
};

// hffix msg_type_string: AccountSummaryReport is the two-character MsgType "CQ".
struct AccountSummaryReport
{
   std::string account{};
};

template <>
struct glz::meta<AccountSummaryReport>
{
   using T = AccountSummaryReport;
   static constexpr auto fix_msg_type = "CQ";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("1", &T::account);
};

// hffix message_writer_bounds / chrono_nano: one field per primitive, FIX.4.2 header.
struct Bounds
{
   std::optional<std::string> text{}; // 58
   std::optional<char> c{}; // 59
   std::optional<int> i{}; // 60
   std::optional<glz::fix::decimal> d{}; // 61
   std::optional<glz::fix::utc_timestamp> ts{}; // 52
};

template <>
struct glz::meta<Bounds>
{
   using T = Bounds;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto fix_begin_string = "FIX.4.2";
   static constexpr auto value =
      glz::object("58", &T::text, "59", &T::c, "60", &T::i, "61", &T::d, "52", &T::ts);
};

suite hffix_set1_data = [] {
   // hffix test/data/fix.5.0.set.1 (JSE FIXT.1.1 capture): checksums and body lengths validate as captured.
   "set1_market_data_validate"_test = [] {
      expect(!glz::fix::validate(set1_x));
      expect(!glz::fix::validate(set1_hb));
      expect(glz::fix::frame(set1_x) == set1_x.size());
      expect(glz::fix::frame(set1_hb) == set1_hb.size());
      auto fields = glz::fix::parse_fields(set1_x);
      expect(fields.has_value());
      expect(fields->size() == 21u);
      expect(fields->front().tag == 8u && fields->back().tag == 10u);
      expect((*fields)[6].tag == 268u && (*fields)[6].value == "2");
   };

   // fix.5.0.set.1: the heartbeats of the capture carry 1180 ApplID; read into a struct and round-trip.
   "set1_heartbeat_struct_roundtrip"_test = [] {
      JseHeartbeat hb{};
      expect(!glz::read<soh_opts>(hb, set1_hb));
      expect(hb.sending_time == "20111124-05:33:31.763");
      expect(hb.appl_id == "JSEFTSEP");
      std::string out{};
      expect(!glz::write<soh_opts>(hb, out));
      expect(out == set1_hb);
   };

   // fix.5.0.set.1: NoMDEntries(268) group with 279 as delimiter, optional 58/270/451 per entry.
   "set1_market_data_group_read"_test = [] {
      MDIncremental m{};
      expect(!glz::read<soh_opts>(m, set1_x));
      expect(m.appl_id == "JSEFTSEP");
      expect(m.appl_seq == 82);
      expect(m.sending_time.precision == 3);
      expect(m.entries.size() == 2u);
      expect(m.entries[0].update_action == '0');
      expect(m.entries[0].symbol == "JA00");
      expect(m.entries[0].entry_type == 'x');
      expect(m.entries[0].text.has_value() && *m.entries[0].text == "LIVE");
      expect(!m.entries[0].px.has_value());
      expect(m.entries[0].entry_time == "06:30:00.000");
      expect(m.entries[0].rpt_seq == 1);
      expect(m.entries[1].entry_type == '3');
      expect(m.entries[1].px.has_value() && *m.entries[1].px == 76.79);
      expect(m.entries[1].net_chg.has_value() && *m.entries[1].net_chg == 1.03);
      expect(!m.entries[1].text.has_value());
   };

   // Writing the struct back reproduces the capture byte for byte (fields were captured in declaration order).
   "set1_market_data_exact_rewrite"_test = [] {
      MDIncremental m{};
      expect(!glz::read<soh_opts>(m, set1_x));
      std::string out{};
      expect(!glz::write<soh_opts>(m, out));
      expect(out == set1_x);
      expect(!glz::fix::validate(out));
   };

   // The capture is a stream: heartbeat, heartbeat, incremental. Frame each in turn with SOH delimiters.
   "set1_stream_framing"_test = [] {
      const std::string stream = set1_hb + set1_hb + set1_x;
      std::string_view rest = stream;
      std::vector<size_t> lens{};
      while (!rest.empty()) {
         const auto n = glz::fix::frame(rest);
         expect(n != 0u && n != glz::fix::frame_error);
         expect(!glz::fix::validate(rest.substr(0, n)));
         lens.push_back(n);
         rest.remove_prefix(n);
      }
      expect(lens.size() == 3u);
      expect(lens[0] == set1_hb.size() && lens[1] == set1_hb.size() && lens[2] == set1_x.size());
      // A partial tail of the third message is reported as "need more".
      std::string_view partial(stream.data(), stream.size() - 5);
      partial.remove_prefix(2 * set1_hb.size());
      expect(glz::fix::frame(partial) == 0u);
   };

   // MsgType mismatch against the capture: reading an X as a heartbeat is rejected.
   "set1_wrong_msg_type_rejected"_test = [] {
      JseHeartbeat hb{};
      expect(bool(glz::read<soh_opts>(hb, set1_x)));
      MDIncremental m{};
      expect(bool(glz::read<soh_opts>(m, set1_hb)));
   };
};

suite hffix_unit_tests_more = [] {
   // hffix msg_type_string: a two-character MsgType ("CQ") is written and checked on read.
   "msg_type_two_chars"_test = [] {
      AccountSummaryReport r{"ACC-1"};
      std::string out{};
      expect(!glz::write<opts>(r, out));
      expect(out == "8=FIX.4.2|9=14|35=CQ|1=ACC-1|10=181|") << out;
      expect(!glz::fix::validate(out, '|'));
      AccountSummaryReport back{};
      expect(!glz::read<opts>(back, out));
      expect(back.account == "ACC-1");
      // "C" alone is a different message type.
      expect(bool(glz::read<opts>(back, envelope("FIX.4.2", "35=C|1=ACC-1|"))));
   };

   // hffix message_writer_bounds: header "8=FIX.4.2|9=...|" plus "35=A|" and "10=ddd|" is the minimal message.
   "writer_bounds_header_trailer"_test = [] {
      Bounds b{};
      std::string out{};
      expect(!glz::write<opts>(b, out));
      // 8=FIX.4.2| (10) + 9=5| (4) + 35=A| (5) + 10=ddd| (7)
      expect(out.size() == 26u) << out;
      expect(out.starts_with("8=FIX.4.2|9=5|35=A|"));
      expect(out.ends_with("|") && out.substr(out.size() - 7, 3) == "10=");
      expect(!glz::fix::validate(out, '|'));
   };

   // hffix message_writer_bounds: push_back_string(58, "string literal") occupies 4 + 14 bytes.
   "writer_bounds_string_char_int"_test = [] {
      Bounds b{};
      b.text = "string literal";
      std::string out{};
      expect(!glz::write<opts>(b, out));
      expect(out.find("|58=string literal|") != std::string::npos);
      expect(out.size() == bounds_size(4u + 14u)) << out;

      b = {};
      b.c = 'a';
      out.clear();
      expect(!glz::write<opts>(b, out));
      expect(out.find("|59=a|") != std::string::npos);
      expect(out.size() == bounds_size(5u));

      b = {};
      b.i = 55;
      out.clear();
      expect(!glz::write<opts>(b, out));
      expect(out.find("|60=55|") != std::string::npos);
      expect(out.size() == bounds_size(6u));
   };

   // hffix message_writer_bounds: push_back_decimal(58, 123456, -3) -> "58=123.456|" (11 bytes);
   // push_back_decimal(58, 123456, 0) -> "58=123456|" (10 bytes).
   "writer_bounds_decimal"_test = [] {
      Bounds b{};
      b.d = glz::fix::decimal{123456, -3};
      std::string out{};
      expect(!glz::write<opts>(b, out));
      expect(out.find("|61=123.456|") != std::string::npos) << out;
      expect(out.size() == bounds_size(11u));

      b.d = glz::fix::decimal{123456, 0};
      out.clear();
      expect(!glz::write<opts>(b, out));
      expect(out.find("|61=123456|") != std::string::npos) << out;
      expect(out.size() == bounds_size(10u));

      Bounds back{};
      expect(!glz::read<opts>(back, out));
      expect(back.d.has_value() && back.d->mantissa == 123456 && back.d->exponent == 0);
   };

   // hffix message_writer_bounds: timestamps "YYYYMMDD-HH:MM:SS" (21 bytes) and ".sss" (25 bytes).
   "writer_bounds_timestamp"_test = [] {
      using namespace std::chrono;
      Bounds b{};
      glz::fix::utc_timestamp ts{};
      ts.time = sys_time<nanoseconds>{sys_days{1970y / 1 / 1} + 23h + 59min + 59s + 999ms};
      ts.precision = 0;
      b.ts = ts;
      std::string out{};
      expect(!glz::write<opts>(b, out));
      expect(out.find("|52=19700101-23:59:59|") != std::string::npos) << out;
      expect(out.size() == bounds_size(21u));

      ts.precision = 3;
      b.ts = ts;
      out.clear();
      expect(!glz::write<opts>(b, out));
      expect(out.find("|52=19700101-23:59:59.999|") != std::string::npos) << out;
      expect(out.size() == bounds_size(25u));
   };

   // hffix chrono_nano: 2017-08-09 12:34:56.123456789 written with nanoseconds and read back exactly.
   "chrono_nano_roundtrip"_test = [] {
      using namespace std::chrono;
      const sys_time<nanoseconds> tsend{nanoseconds(1502282096123456789LL)};
      Bounds b{};
      b.ts = glz::fix::utc_timestamp{tsend, 9};
      std::string out{};
      expect(!glz::write<opts>(b, out));
      expect(out.find("|52=20170809-12:34:56.123456789|") != std::string::npos) << out;
      Bounds back{};
      expect(!glz::read<opts>(back, out));
      expect(back.ts.has_value());
      expect(back.ts->time == tsend);
      expect(back.ts->precision == 9);
   };

   // hffix chrono_nano: the nanosecond text form parses standalone too, and 10 fractional digits do not.
   "chrono_nano_parse"_test = [] {
      using namespace std::chrono;
      glz::fix::utc_timestamp t{};
      expect(glz::fix::parse_utc_timestamp("20170809-12:34:56.123456789", t));
      expect(t.time == sys_time<nanoseconds>{nanoseconds(1502282096123456789LL)});
      expect(t.precision == 9);
      expect(!glz::fix::parse_utc_timestamp("20170809-12:34:56.1234567890", t));
      expect(!glz::fix::parse_utc_timestamp("20170809-12:34:56.", t));
   };

   // hffix message_writer_bounds: the writer refuses to overrun its buffer; here the equivalent contract is
   // that BodyLength and CheckSum account for every byte written, including a 3-digit zero-padded checksum.
   "checksum_zero_padded_three_digits"_test = [] {
      // Choose a body whose checksum is < 100 so the padding matters.
      std::string msg = "8=FIX.4.2|9=5|35=A|";
      uint8_t sum = glz::fix::checksum(msg);
      // 10 = "10=" + 3 digits + delimiter; validate must accept exactly three digits.
      char buf[4]{};
      buf[0] = char('0' + sum / 100);
      buf[1] = char('0' + (sum / 10) % 10);
      buf[2] = char('0' + sum % 10);
      std::string full = msg + "10=" + buf + "|";
      expect(!glz::fix::validate(full, '|')) << full;
      // Two-digit checksum text is rejected even if numerically equal.
      std::string two = msg + "10=" + std::to_string(unsigned(sum)) + "|";
      if (sum < 100) {
         expect(bool(glz::fix::validate(two, '|')));
      }
   };

   // hffix basic / null_field_value: a trailer-less message is not a complete message.
   "missing_trailer_rejected"_test = [] {
      expect(bool(glz::fix::validate("8=FIX.4.2|9=5|35=A|", '|')));
      expect(glz::fix::frame("8=FIX.4.2|9=5|35=A|", '|') == 0u);
      Bounds b{};
      expect(bool(glz::read<opts>(b, "8=FIX.4.2|9=5|35=A|")));
   };

   // hffix data_length: BodyLength that claims more bytes than the message holds means "incomplete".
   "body_length_beyond_end_is_incomplete"_test = [] {
      const std::string m = "8=FIX.4.2|9=500|35=A|10=000|";
      expect(glz::fix::frame(m, '|') == 0u);
      expect(bool(glz::fix::validate(m, '|')));
   };

   // hffix iterating: unknown tags (1180 ApplID, 1181 ApplSeqNum) are skipped at the top level by
   // default and rejected with error_on_unknown_tags.
   "unknown_fixt_tags_skipped_or_rejected"_test = [] {
      Bounds b{};
      const std::string msg = envelope("FIX.4.2", "35=A|1180=JSEFTSEP|1181=82|58=hi|");
      expect(!glz::fix::validate(msg, '|')) << msg;
      expect(!glz::read<opts>(b, msg));
      expect(b.text.has_value() && *b.text == "hi");
      constexpr glz::fix_opts strict{{}, glz::FIX, '|', true, true, true};
      Bounds s{};
      expect(bool(glz::read<strict>(s, msg)));
   };

   // fix.5.0.set.1 shape: a group entry that does not start with the delimiter tag (279) is an error.
   "group_entry_must_start_with_delimiter"_test = [] {
      MDIncremental m{};
      const std::string msg = "8=FIXT.1.1|9=62|35=X|52=20111124-06:28:56.151|1180=JSEFTSEP|268=1|55=JA00|279=0|10=000|";
      constexpr glz::fix_opts lax{{}, glz::FIX, '|', false, false, false, true};
      expect(bool(glz::read<lax>(m, msg)));
   };

   // fix.5.0.set.1 shape: group count larger than the entries present is an error, smaller leaves the
   // extra entry's fields as unknown top-level tags.
   "group_count_vs_entries"_test = [] {
      constexpr glz::fix_opts lax{{}, glz::FIX, '|', false, false, false, true};
      MDIncremental m{};
      expect(bool(glz::read<lax>(m, "8=FIXT.1.1|9=0|35=X|268=3|279=0|55=A|269=0|273=1|83=1|279=0|55=B|269=0|273=1|83=2|10=000|")));
      MDIncremental n{};
      expect(!glz::read<lax>(n, "8=FIXT.1.1|9=0|35=X|268=1|279=0|55=A|269=0|273=1|83=1|279=0|55=B|269=0|273=1|83=2|10=000|"));
      expect(n.entries.size() == 1u);
   };
};

int main() { return 0; }
