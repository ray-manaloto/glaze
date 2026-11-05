// Glaze Library
// For the license information refer to glaze.hpp

// Tests ported from fixpp (https://github.com/Abc-Arbitrage/fixpp), MIT licence in LICENSE-fixpp
// (Copyright (c) 2016 ABC arbitrage). Sources:
//   tests/visitor_test.cc, tests/writer_test.cc, tests/message_test.cc (gtest names noted per test)
//   tests/data/fix42.log (copied verbatim into ./data)
// fixpp is a type-per-message library; its cases are re-expressed against the glaze FIX contract
// (docs/fix/api.md). fixpp frames use '|' as the separator, which is kept here (soh = '|').
// Several fixpp frames carry placeholder BodyLength/CheckSum values (e.g. 9=84, 9=0000, 10=213) and
// some lack the final separator after 10=NNN; the final '|' is appended here, and repair() rebuilds
// 9 and 10 where a test needs a message that validates.
//
// Struct-mapping tests are compiled only when GLZ_FIX_HAS_STRUCT_MAPPING is defined.

#include <cstdio>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
   constexpr char sep = '|';

   std::string three_digits(unsigned v)
   {
      std::string s = std::to_string(v % 1000);
      while (s.size() < 3) s.insert(s.begin(), '0');
      return s;
   }

   // Ensures the frame ends with the separator (fixpp's visitor accepted frames without it).
   std::string terminated(std::string_view f)
   {
      std::string s(f);
      if (s.empty() || s.back() != sep) s += sep;
      return s;
   }

   // Rebuilds BodyLength (9) and CheckSum (10) for a '|' separated frame.
   std::string repair(std::string_view frame)
   {
      std::string f = terminated(frame);
      const size_t e8 = f.find(sep);
      const size_t e9 = f.find(sep, e8 + 1);
      const size_t t10 = f.rfind("|10=");
      std::string body = f.substr(e9 + 1, t10 + 1 - (e9 + 1));
      std::string out = f.substr(0, e8 + 1) + "9=" + std::to_string(body.size()) + sep + body;
      out += "10=" + three_digits(glz::fix::checksum(out)) + sep;
      return out;
   }

   const glz::fix::field* find(const std::vector<glz::fix::field>& fs, uint32_t tag, size_t from = 0)
   {
      for (size_t i = from; i < fs.size(); ++i)
         if (fs[i].tag == tag) return &fs[i];
      return nullptr;
   }

   size_t count(const std::vector<glz::fix::field>& fs, uint32_t tag)
   {
      size_t n = 0;
      for (auto& f : fs) n += f.tag == tag;
      return n;
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

   void skip(std::string_view name, std::string_view reason)
   {
      std::printf("SKIP %.*s: %.*s\n", int(name.size()), name.data(), int(reason.size()), reason.data());
   }

   // visitor_test.cc frames
   constexpr std::string_view logon_frame =
      "8=FIX.4.2|9=84|35=A|34=1|49=ABC|52=20120309-16:54:02|56=TT_ORDER|96=12345678|98=0|108=60|141=Y|10=248";
   constexpr std::string_view logon_group_frame =
      "8=FIX.4.2|9=84|35=A|34=1|49=ABC|52=20120309-16:54:02|56=TT_ORDER|96=12345678|384=2|372=TEST|385=C|372=TEST|10=248";
   constexpr std::string_view custom_frame = "8=FIX.4.2|9=84|35=A|34=1|49=ABC|52=20120309-16:54:02|56=TT_ORDER|96="
                                             "12345678|2154=1212|98=0|108=60|141=Y|10=248";
   constexpr std::string_view incremental_frame =
      "8=FIX.4.2|9=407|35=X|34=002565204|52=20160908-08:42:10.359|49=Prov|56=MDABC|262=1364|268=4|"
      "279=2|55=CHF/JPY|269=0|278=0453665272|270=00104.840000|271=001000000.00|15=CHF|"
      "279=0|55=CHF/JPY|269=0|278=0453665276|270=00104.841000|271=001000000.00|15=CHF|"
      "279=2|55=CHF/JPY|269=1|278=0453665273|270=00104.855000|271=001000000.00|15=CHF|"
      "279=0|55=CHF/JPY|269=1|278=0453665277|270=00104.856000|271=001000000.00|15=CHF|"
      "10=213";
   constexpr std::string_view snapshot_frame =
      "8=FIX.4.4|9=0230|35=W|49=Prov|56=MDABC|34=2289004|52=20161229-16:18:09.098|55=AUD/CAD|262=1709|268=2|"
      "269=0|270=0.97285|271=500000|272=20170103|299=02z00000hdi:A|9063=MP|"
      "269=1|270=0.97309|271=500000|272=20170103|299=02z00000hdi:A|9063=TP|"
      "10=233|";
   constexpr std::string_view nested_frame = "8=FIX.4.4|9=0000|35=W|49=Prov|56=MDABC|55=AUD/CAD|262=1709|"
                                             "711=1|"
                                             "311=AUD/CAD|"
                                             "457=1|"
                                             "458=TESTID|459=TESTSOURCE|"
                                             "462=1|"
                                             "292=D|268=2|"
                                             "269=0|271=500000|272=20170103|299=02z00000hdi:A|"
                                             "269=1|271=500000|272=20170103|299=02z00000hdi:A|"
                                             "10=213";
   constexpr std::string_view empty_group_frame =
      "8=FIX.4.4|9=0000|35=W|49=Prov|56=MDABC|55=AUD/CAD|262=1709|268=0|10=213";
   constexpr std::string_view unknown_tags_frame = "8=FIX.4.4|9=0000|35=W|49=Prov|56=MDABC|55=AUD/CAD|262=1709|"
                                                   "10721=CUSTOM1|"
                                                   "711=1|"
                                                   "311=AUD/CAD|"
                                                   "10541=CUSTOM2|"
                                                   "457=1|"
                                                   "458=TESTID|459=TESTSOURCE|10872=CUSTOM3|10873=CUSTOM4|"
                                                   "462=1|"
                                                   "292=D|268=2|"
                                                   "269=0|271=500000|272=20170103|299=02z00000hdi:A|10331=CUSTOM5|"
                                                   "269=1|271=500000|272=20170103|299=02z00000hdi:A|10331=CUSTOM6|"
                                                   "10=213";
   constexpr std::string_view bad_version_frame = "8=FIX.5.1|9=0000|35=0|49=Prov|56=MDABC|10=213";
   constexpr std::string_view strict_unknown_frame = "8=FIX.4.2|9=0000|35=0|49=Prov|56=MDABC|221=A|10=213";
   constexpr std::string_view multichar_type_frame = "8=FIX.4.4|9=84|35=BF|923=123|924=1|553=username|10=248";
   constexpr std::string_view skip_unknown_frame =
      "8=FIX.4.4|9=0234|35=W|49=SNDR|59=ABC|34=1|52=20170609-09:27:24|55=AAA/BBB|262=123|268=2|"
      "269=0|270=1.181|271=50000|272=20170613|299=ABCDEFGH|9063=AB|"
      "269=1|270=1.1182|271=50000|272=20170613|299=ABCDEFH|9063=AB|"
      "9066=189718761|10=076|";
}

suite fixpp_visitor = [] {
   // visitor_test.cc: should_visit_logon_frame
   "should_visit_logon_frame"_test = [] {
      const auto m = terminated(logon_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      expect(f->size() == 12u);
      expect(find(*f, 35)->value == "A");
      expect(find(*f, 96)->value == "12345678");
      expect(find(*f, 108)->value == "60");
      expect(find(*f, 141)->value == "Y");
      // the original frame's 9 and 10 are placeholders; a repaired frame validates
      expect(bool(glz::fix::validate(terminated(logon_frame), sep)));
      expect(!glz::fix::validate(repair(logon_frame), sep));
   };

   // visitor_test.cc: should_visit_repeating_group_in_logon_frame
   "should_visit_repeating_group_in_logon_frame"_test = [] {
      const auto m = terminated(logon_group_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      expect(find(*f, 384)->value == "2");
      expect(count(*f, 372) == 2u);
      expect(count(*f, 385) == 1u); // 385 is optional in the NoMsgTypes group
   };

   // visitor_test.cc: should_visit_custom_message (user defined tag 2154)
   "should_visit_custom_message"_test = [] {
      const auto m = terminated(custom_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value() && find(*f, 2154) && find(*f, 2154)->value == "1212");
   };

   // visitor_test.cc: should_visit_incremental_refresh_frame / should_convert_from_ref
   "should_visit_incremental_refresh_frame"_test = [] {
      const auto m = terminated(incremental_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      expect(find(*f, 268)->value == "4");
      expect(count(*f, 279) == 4u);
      expect(count(*f, 55) == 4u);
      expect(find(*f, 34)->value == "002565204"); // leading zeros are preserved in the raw value
      expect(find(*f, 270)->value == "00104.840000");
      expect(!glz::fix::validate(repair(incremental_frame), sep));
   };

   // visitor_test.cc: should_visit_snapshot_frame
   "should_visit_snapshot_frame"_test = [] {
      auto f = glz::fix::parse_fields(snapshot_frame, sep);
      expect(f.has_value());
      if (!f) return;
      expect(find(*f, 8)->value == "FIX.4.4");
      expect(find(*f, 268)->value == "2");
      expect(count(*f, 269) == 2u);
      expect(count(*f, 9063) == 2u);
      expect(f->back().tag == 10u && f->back().value == "233");
   };

   // visitor_test.cc: should_visit_nested_repeating_groups
   "should_visit_nested_repeating_groups"_test = [] {
      const auto m = terminated(nested_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      expect(find(*f, 711)->value == "1");
      expect(find(*f, 457)->value == "1");
      expect(find(*f, 458)->value == "TESTID");
      expect(find(*f, 459)->value == "TESTSOURCE");
      expect(find(*f, 292)->value == "D");
      expect(count(*f, 269) == 2u);
      expect(!glz::fix::validate(repair(nested_frame), sep));
   };

   // visitor_test.cc: should_visit_empty_repeating_group
   "should_visit_empty_repeating_group"_test = [] {
      const auto m = terminated(empty_group_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value() && find(*f, 268) && find(*f, 268)->value == "0" && count(*f, 269) == 0u);
   };

   // visitor_test.cc: should_visit_unknown_tags_in_non_strict_mode
   "should_visit_unknown_tags_in_non_strict_mode"_test = [] {
      const auto m = terminated(unknown_tags_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      expect(find(*f, 10721)->value == "CUSTOM1");
      expect(find(*f, 10541)->value == "CUSTOM2");
      expect(find(*f, 10873)->value == "CUSTOM4");
      expect(count(*f, 10331) == 2u);
   };

   // visitor_test.cc: should_stop_when_encountering_invalid_fix_version
   // The scanner does not check BeginString values; only the struct reader could.
   "should_stop_when_encountering_invalid_fix_version"_test = [] {
      const auto m = terminated(bad_version_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value() && (*f)[0].value == "FIX.5.1");
   };
   skip("should_stop_when_encountering_invalid_fix_version (reader)",
        "the contract does not say whether glz::read rejects an unsupported BeginString such as FIX.5.1");

   // visitor_test.cc: should_visit_message_with_multiple_chars_message_type
   "should_visit_message_with_multiple_chars_message_type"_test = [] {
      const auto m = terminated(multichar_type_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value() && (*f)[2].tag == 35u && (*f)[2].value == "BF");
      expect(!glz::fix::validate(repair(multichar_type_frame), sep));
   };

   // visitor_test.cc: should_skip_unknown_tags
   "should_skip_unknown_tags"_test = [] {
      auto f = glz::fix::parse_fields(skip_unknown_frame, sep);
      expect(f.has_value() && find(*f, 9066) && find(*f, 9066)->value == "189718761");
   };

   // visitor_test.cc: should_visit_tag / should_try_get_fields_after_parsing
   "should_visit_tag"_test = [] {
      const auto m = terminated(logon_group_frame);
      auto f = glz::fix::parse_fields(m, sep);
      expect(f.has_value());
      if (!f) return;
      const auto* sender = find(*f, 49);
      const auto* time = find(*f, 52);
      expect(sender && sender->value == "ABC");
      expect(time && time->value == "20120309-16:54:02");
   };

   "missing_final_separator_is_incomplete"_test = [] {
      const auto r = repair(logon_frame);
      expect(glz::fix::frame(r, sep) == r.size());
      expect(glz::fix::frame(std::string_view(r).substr(0, r.size() - 1), sep) == 0u);
      expect(!glz::fix::parse_fields(std::string_view(r).substr(0, r.size() - 1), sep).has_value());
   };

   "malformed_fields_rejected"_test = [] {
      expect(!glz::fix::parse_fields("8=FIX.4.2|abc=1|", sep).has_value());
      expect(!glz::fix::parse_fields("8=FIX.4.2|35A|", sep).has_value());
      expect(!glz::fix::parse_fields("8=FIX.4.2|=A|", sep).has_value());
   };

   // visitor_test.cc: should_parse_utc_date / _time / _timestamp (+ milli/microseconds)
   skip("should_parse_utc_date/time/timestamp",
        "the contract defines no typed FIX UTCDate/UTCTimeOnly/UTCTimestamp; vectors: 20171105, 14:09:30, "
        "14:09:30.123, 14:09:30.123456, 20171105-14:09:30 (.123, .123456)");
};

suite fixpp_writer = [] {
   // writer_test.cc: should_compute_proper_length_and_checksum - fixpp recomputes 9 and 10 the same
   // way validate() checks them. Checked here on a hand-built heartbeat.
   "should_compute_proper_length_and_checksum"_test = [] {
      const auto hb = repair("8=FIX.4.2|9=0|35=0|49=SNDR|56=TRGT|112=TestReq|10=000|");
      expect(hb == "8=FIX.4.2|9=33|35=0|49=SNDR|56=TRGT|112=TestReq|10=" +
                       three_digits(glz::fix::checksum("8=FIX.4.2|9=33|35=0|49=SNDR|56=TRGT|112=TestReq|")) + "|");
      expect(!glz::fix::validate(hb, sep));
      expect(glz::fix::frame(hb, sep) == hb.size());
   };

   // writer_test.cc: should_write_bool/char/float/utc_timestamp/int field - wire forms, read side
   "field_wire_forms"_test = [] {
      auto f = glz::fix::parse_fields("43=Y|43=N|39=4|44=17.35|44=1234567.45|44=1000000|52=20170516-13:45:30|"
                                      "52=20170516-13:45:30.123|52=20170516-13:45:30.123456|34=25|",
                                      sep);
      expect(f.has_value() && f->size() == 10u);
      if (!f || f->size() != 10u) return;
      expect((*f)[0].value == "Y" && (*f)[1].value == "N");
      expect((*f)[2].tag == 39u && (*f)[2].value == "4");
      expect((*f)[5].value == "1000000");
      expect((*f)[8].value == "20170516-13:45:30.123456");
      expect((*f)[9].tag == 34u && (*f)[9].value == "25");
   };
};

suite fixpp_samples = [] {
   // tests/data/fix42.log (used by bench_test.cc): 330 FIX.4.2 frames, one per line, '|' separated.
   // Its BodyLength/CheckSum values do not match the (anonymised) content, so the stream is split
   // on newlines rather than with frame(), and repaired copies are validated.
   "fix42_log"_test = [] {
      const auto data = read_file("fix42.log");
      expect(!data.empty());
      size_t lines = 0, parsed = 0, repaired_ok = 0, quotes = 0;
      std::string_view rest = data;
      while (!rest.empty()) {
         const size_t nl = rest.find('\n');
         std::string_view line = rest.substr(0, nl);
         rest.remove_prefix(nl == std::string_view::npos ? rest.size() : nl + 1);
         if (line.empty()) continue;
         ++lines;
         auto f = glz::fix::parse_fields(line, sep);
         if (f && (*f)[0].tag == 8u && (*f)[1].tag == 9u && (*f)[2].tag == 35u && f->back().tag == 10u) ++parsed;
         if (f && (*f)[2].value == "S") ++quotes;
         if (!glz::fix::validate(repair(line), sep)) ++repaired_ok;
      }
      expect(lines == 330u);
      expect(parsed == lines);
      expect(repaired_ok == lines);
      expect(quotes >= 1u);
   };

   "fix42_log_streaming"_test = [] {
      // Concatenate repaired frames and feed them in small chunks through frame().
      const auto data = read_file("fix42.log");
      std::string stream;
      size_t lines = 0;
      std::string_view rest = data;
      while (!rest.empty()) {
         const size_t nl = rest.find('\n');
         std::string_view line = rest.substr(0, nl);
         rest.remove_prefix(nl == std::string_view::npos ? rest.size() : nl + 1);
         if (line.empty()) continue;
         stream += repair(line);
         ++lines;
      }
      std::string buffer;
      size_t got = 0, valid = 0;
      for (size_t pos = 0; pos < stream.size(); pos += 13) {
         buffer.append(stream, pos, 13);
         for (size_t n; (n = glz::fix::frame(buffer, sep)) != 0 && n != glz::fix::frame_error;) {
            ++got;
            if (!glz::fix::validate(std::string_view(buffer).substr(0, n), sep)) ++valid;
            buffer.erase(0, n);
         }
      }
      expect(got == lines);
      expect(valid == lines);
      expect(buffer.empty());
   };
};

// message_test.cc: should_get_and_set_tags, should_create_repeating_group, should_throw_when_missing_fields_in_
// repeating_group, should_throw_when_getting_not_present_tag, should_extend_message_properly,
// should_optionally_get, should_overwrite_tags_in_message, should_set_tag_if_defined
// writer_test.cc: should_write_heartbeat_message_42/44, should_write_repeating_groups,
// should_write_nested_repeating_groups
#ifdef GLZ_FIX_HAS_STRUCT_MAPPING
#include <optional>

struct md_entry
{
   char md_entry_type{};
   double md_entry_px{};
   double md_entry_size{};
   std::string md_entry_date{};
   std::string quote_entry_id{};
};

template <>
struct glz::meta<md_entry>
{
   using T = md_entry;
   static constexpr auto value = glz::object("269", &T::md_entry_type, "270", &T::md_entry_px, "271",
                                             &T::md_entry_size, "272", &T::md_entry_date, "299", &T::quote_entry_id);
};

struct snapshot
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   std::string symbol{};
   std::string md_req_id{};
   std::vector<md_entry> entries{};
};

template <>
struct glz::meta<snapshot>
{
   using T = snapshot;
   static constexpr auto fix_msg_type = "W";
   static constexpr auto value = glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "55", &T::symbol,
                                             "262", &T::md_req_id, "268", &T::entries);
};

struct msg_type_entry
{
   std::string ref_msg_type{};
   std::optional<char> msg_direction{};
};

template <>
struct glz::meta<msg_type_entry>
{
   using T = msg_type_entry;
   static constexpr auto value = glz::object("372", &T::ref_msg_type, "385", &T::msg_direction);
};

struct logon
{
   std::string sender_comp_id{};
   std::string target_comp_id{};
   int encrypt_method{};
   int heart_bt_int{};
   std::vector<msg_type_entry> msg_types{};
};

template <>
struct glz::meta<logon>
{
   using T = logon;
   static constexpr auto fix_msg_type = "A";
   static constexpr auto value = glz::object("49", &T::sender_comp_id, "56", &T::target_comp_id, "98",
                                             &T::encrypt_method, "108", &T::heart_bt_int, "384", &T::msg_types);
};

namespace
{
   constexpr glz::fix_opts pipe_opts()
   {
      glz::fix_opts o{};
      o.soh = '|';
      o.error_on_unknown_keys = false;
      return o;
   }
}

suite fixpp_struct_mapping = [] {
   "should_visit_snapshot_frame_struct"_test = [] {
      snapshot s{};
      expect(!glz::read<pipe_opts()>(s, repair(snapshot_frame)));
      expect(s.symbol == "AUD/CAD" && s.md_req_id == "1709");
      expect(s.entries.size() == 2u);
      if (s.entries.size() != 2) return;
      expect(s.entries[0].md_entry_type == '0' && s.entries[0].md_entry_px == 0.97285);
      expect(s.entries[1].md_entry_type == '1' && s.entries[1].md_entry_px == 0.97309);
   };

   "should_visit_empty_repeating_group_struct"_test = [] {
      snapshot s{};
      s.entries.resize(3);
      expect(!glz::read<pipe_opts()>(s, repair(empty_group_frame)));
      expect(s.entries.empty());
   };

   "should_write_repeating_groups"_test = [] {
      logon l{"SNDR", "TRGT", 0, 60, {{"TESTREF1", 'S'}, {"TESTREF2", 'S'}}};
      std::string buffer;
      expect(!glz::write<pipe_opts()>(l, buffer));
      expect(!glz::fix::validate(buffer, '|'));
      expect(buffer.find("|35=A|") != std::string::npos);
      expect(buffer.find("|98=0|") != std::string::npos);
      expect(buffer.find("|108=60|") != std::string::npos);
      expect(buffer.find("|384=2|372=TESTREF1|385=S|372=TESTREF2|385=S|") != std::string::npos);
      logon back{};
      expect(!glz::read<pipe_opts()>(back, buffer));
      expect(back.msg_types.size() == 2u && back.msg_types[1].ref_msg_type == "TESTREF2");
   };

   "should_visit_repeating_group_with_optional_field"_test = [] {
      logon l{};
      expect(!glz::read<pipe_opts()>(l, repair(logon_group_frame)));
      expect(l.msg_types.size() == 2u);
      if (l.msg_types.size() != 2) return;
      expect(l.msg_types[0].msg_direction == std::optional<char>('C'));
      expect(!l.msg_types[1].msg_direction.has_value());
   };

   // visitor_test.cc: should_stop_in_strict_mode_when_encountering_an_unknown_tag
   "should_stop_in_strict_mode_when_encountering_an_unknown_tag"_test = [] {
      constexpr auto strict = [] {
         glz::fix_opts o{};
         o.soh = '|';
         return o;
      }();
      logon l{};
      expect(bool(glz::read<strict>(l, repair(strict_unknown_frame))));
   };

   // writer_test.cc: should_write_float_field
   "should_write_float_field"_test = [] {
      snapshot s{};
      s.entries.push_back({'0', 17.35, 1234567.45, "20170103", "x"});
      s.entries.push_back({'1', 1000000.0, 0.0, "20170103", "y"});
      std::string buffer;
      expect(!glz::write<pipe_opts()>(s, buffer));
      expect(buffer.find("|270=17.35|") != std::string::npos);
      expect(buffer.find("|271=1234567.45|") != std::string::npos);
      expect(buffer.find("|270=1000000|") != std::string::npos);
   };

   // incomplete group: count says 4 but only 2 entries are present
   "group_count_mismatch_rejected"_test = [] {
      snapshot s{};
      std::string f(snapshot_frame);
      f.replace(f.find("268=2"), 5, "268=4");
      expect(bool(glz::read<pipe_opts()>(s, repair(f))));
   };
};
#else
suite fixpp_struct_mapping_skipped = [] {
   skip("fixpp struct mapping (snapshot/logon groups, strict unknown tag, float write, group count mismatch)",
        "need glz::read/glz::write<glz::fix_opts{}> from fix/core; define GLZ_FIX_HAS_STRUCT_MAPPING to build them");
};
#endif

int main() { return 0; }
