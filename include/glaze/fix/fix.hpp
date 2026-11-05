// Glaze Library
// For the license information refer to glaze.hpp

// LOCAL STUB of the shared FIX API contract (see docs/fix/api.md on branch fix/core).
// Branch fix/conformance-fuzz carries this only so that its fuzzers and property tests compile
// before fix/core lands. When fix/core's header exists, delete this file and take that one.
//
// Scope of the stub: parse_fields, checksum, validate, frame, and a flat struct mapping
// (std::string, integers, floating point, char, bool as Y/N). Repeating groups are not here.

#pragma once

#include <charconv>
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

#include "glaze/core/common.hpp"
#include "glaze/core/opts.hpp"
#include "glaze/core/read.hpp"
#include "glaze/core/reflect.hpp"
#include "glaze/core/write.hpp"
#include "glaze/util/expected.hpp"
#include "glaze/util/for_each.hpp"

namespace glz
{
   inline constexpr uint32_t FIX = 65536 + 9;

   struct fix_opts : opts
   {
      uint32_t format = FIX;
      char soh = '\x01';
      bool validate_checksum = true;
      bool validate_body_length = true;
   };
}

namespace glz::fix
{
   struct field
   {
      uint32_t tag{};
      std::string_view value{};
   };

   // FIX data fields whose value may hold any byte, SOH included. The value of the preceding
   // Length field gives the number of bytes. Pairs are {length tag, data tag}.
   inline constexpr std::pair<uint32_t, uint32_t> length_data_pairs[] = {
      {90, 91}, // SecureDataLen / SecureData
      {93, 89}, // SignatureLength / Signature
      {95, 96}, // RawDataLength / RawData
      {212, 213}, // XmlDataLen / XmlData
      {348, 349}, // EncodedIssuerLen / EncodedIssuer
      {350, 351}, // EncodedSecurityDescLen / EncodedSecurityDesc
      {352, 353}, // EncodedListExecInstLen / EncodedListExecInst
      {354, 355}, // EncodedTextLen / EncodedText
      {356, 357}, // EncodedSubjectLen / EncodedSubject
      {358, 359}, // EncodedHeadlineLen / EncodedHeadline
      {360, 361}, // EncodedAllocTextLen / EncodedAllocText
      {362, 363}, // EncodedUnderlyingIssuerLen / EncodedUnderlyingIssuer
      {364, 365}, // EncodedUnderlyingSecurityDescLen / EncodedUnderlyingSecurityDesc
      {445, 446}, // EncodedListStatusTextLen / EncodedListStatusText
      {618, 619}, // EncodedLegIssuerLen / EncodedLegIssuer
      {621, 622}, // EncodedLegSecurityDescLen / EncodedLegSecurityDesc
   };

   constexpr uint32_t data_tag_for_length(uint32_t length_tag) noexcept
   {
      for (auto [l, d] : length_data_pairs) {
         if (l == length_tag) return d;
      }
      return 0;
   }

   namespace detail
   {
      inline glz::error_ctx fail(glz::error_code ec, size_t at, std::string_view msg) noexcept
      {
         return {at, ec, msg};
      }

      // Parses an unsigned decimal of at most 9 digits, no sign, no leading zeros unless "0".
      constexpr bool parse_tag(std::string_view s, uint32_t& out) noexcept
      {
         if (s.empty() || s.size() > 9) return false;
         if (s[0] == '0') return false; // tags are positive and carry no leading zeros
         uint32_t v = 0;
         for (char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + uint32_t(c - '0');
         }
         out = v;
         return true;
      }

      // Unsigned length value (BodyLength, Length fields). Leading zeros are accepted.
      constexpr bool parse_length(std::string_view s, size_t& out) noexcept
      {
         if (s.empty() || s.size() > 9) return false;
         size_t v = 0;
         for (char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + size_t(c - '0');
         }
         out = v;
         return true;
      }
   }

   // Scan one complete message into tag=value fields. Values are views into `msg`.
   inline glz::expected<std::vector<field>, glz::error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t i = 0;
      uint32_t pending_data_tag = 0;
      size_t pending_data_len = 0;
      while (i < msg.size()) {
         const size_t eq = msg.find('=', i);
         if (eq == std::string_view::npos) {
            return glz::unexpected(detail::fail(error_code::syntax_error, i, "fix: field without '='"));
         }
         uint32_t tag{};
         if (!detail::parse_tag(msg.substr(i, eq - i), tag)) {
            return glz::unexpected(detail::fail(error_code::syntax_error, i, "fix: invalid tag number"));
         }
         const size_t vstart = eq + 1;
         size_t vend{};
         if (pending_data_tag != 0 && tag == pending_data_tag) {
            if (pending_data_len > msg.size() - vstart) {
               return glz::unexpected(detail::fail(error_code::unexpected_end, vstart, "fix: data field truncated"));
            }
            vend = vstart + pending_data_len;
            if (vend >= msg.size() || msg[vend] != soh) {
               return glz::unexpected(
                  detail::fail(error_code::syntax_error, vend, "fix: data field length does not match its Length tag"));
            }
         }
         else {
            vend = msg.find(soh, vstart);
            if (vend == std::string_view::npos) {
               return glz::unexpected(detail::fail(error_code::unexpected_end, vstart, "fix: field not terminated"));
            }
         }
         pending_data_tag = 0;
         if (vend == vstart) {
            return glz::unexpected(detail::fail(error_code::syntax_error, vstart, "fix: empty field value"));
         }
         const std::string_view value = msg.substr(vstart, vend - vstart);
         if (const uint32_t d = data_tag_for_length(tag); d != 0) {
            if (!detail::parse_length(value, pending_data_len)) {
               return glz::unexpected(detail::fail(error_code::syntax_error, vstart, "fix: invalid Length value"));
            }
            pending_data_tag = d;
         }
         out.push_back({tag, value});
         i = vend + 1;
      }
      if (pending_data_tag != 0) {
         return glz::unexpected(detail::fail(error_code::unexpected_end, msg.size(), "fix: Length tag without data"));
      }
      return out;
   }

   inline uint8_t checksum(std::string_view bytes_before_tag10)
   {
      uint32_t sum = 0;
      for (unsigned char c : bytes_before_tag10) sum += c;
      return uint8_t(sum & 0xFF);
   }

   // Session-layer structure check of one complete message:
   // 8 first, 9 second, 35 third, 10 last; 9 equals the body length and 10 the checksum.
   inline glz::error_ctx validate_impl(std::string_view msg, char soh, bool check_body_length, bool check_sum)
   {
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      const auto& f = *fields;
      if (f.size() < 4) return detail::fail(error_code::invalid_header, 0, "fix: too few fields");
      if (f[0].tag != 8) return detail::fail(error_code::invalid_header, 0, "fix: BeginString(8) must be first");
      if (f[1].tag != 9) return detail::fail(error_code::invalid_header, 0, "fix: BodyLength(9) must be second");
      if (f[2].tag != 35) return detail::fail(error_code::invalid_header, 0, "fix: MsgType(35) must be third");
      if (f.back().tag != 10) return detail::fail(error_code::invalid_body, 0, "fix: CheckSum(10) must be last");
      for (size_t k = 3; k + 1 < f.size(); ++k) {
         const auto t = f[k].tag;
         if (t == 8 || t == 9 || t == 35 || t == 10) {
            return detail::fail(error_code::invalid_header, size_t(f[k].value.data() - msg.data()),
                                "fix: header or trailer tag repeated or out of place");
         }
      }
      const size_t body_start = size_t(f[1].value.data() - msg.data()) + f[1].value.size() + 1;
      const size_t trailer_start = size_t(f.back().value.data() - msg.data()) - 3; // "10="
      if (check_body_length) {
         size_t declared{};
         if (!detail::parse_length(f[1].value, declared)) {
            return detail::fail(error_code::invalid_length, body_start, "fix: BodyLength is not a number");
         }
         if (declared != trailer_start - body_start) {
            return detail::fail(error_code::invalid_length, body_start, "fix: BodyLength mismatch");
         }
      }
      const auto cs = f.back().value;
      if (cs.size() != 3 || cs[0] < '0' || cs[0] > '9' || cs[1] < '0' || cs[1] > '9' || cs[2] < '0' ||
          cs[2] > '9') {
         return detail::fail(error_code::invalid_body, trailer_start, "fix: CheckSum must be three digits");
      }
      if (check_sum) {
         const unsigned declared = unsigned(cs[0] - '0') * 100 + unsigned(cs[1] - '0') * 10 + unsigned(cs[2] - '0');
         if (declared != checksum(msg.substr(0, trailer_start))) {
            return detail::fail(error_code::invalid_body, trailer_start, "fix: CheckSum mismatch");
         }
      }
      if (msg.size() != trailer_start + 3 + 3 + 1) {
         return detail::fail(error_code::syntax_error, trailer_start, "fix: bytes after CheckSum");
      }
      return {};
   }

   inline glz::error_ctx validate(std::string_view msg, char soh = '\x01') { return validate_impl(msg, soh, true, true); }

   // Length of the first complete message at the start of `stream`, or 0 if it is incomplete
   // or does not start with "8=...<soh>9=<digits><soh>".
   inline size_t frame(std::string_view stream, char soh = '\x01')
   {
      if (stream.size() < 2 || stream[0] != '8' || stream[1] != '=') return 0;
      const size_t e8 = stream.find(soh, 2);
      if (e8 == std::string_view::npos) return 0;
      if (stream.size() < e8 + 3 || stream[e8 + 1] != '9' || stream[e8 + 2] != '=') return 0;
      const size_t e9 = stream.find(soh, e8 + 3);
      if (e9 == std::string_view::npos) return 0;
      size_t len{};
      if (!detail::parse_length(stream.substr(e8 + 3, e9 - (e8 + 3)), len)) return 0;
      const size_t total = e9 + 1 + len + 7; // "10=nnn<soh>"
      if (total > stream.size()) return 0;
      const auto tr = stream.substr(e9 + 1 + len, 7);
      if (tr[0] != '1' || tr[1] != '0' || tr[2] != '=' || tr[6] != soh) return 0;
      return total;
   }
}

// ---------------------------------------------------------------------------------------------
// Flat struct mapping (stub). glz::meta<T>::value = glz::object("11", &T::a, ...), with an
// optional static constexpr fix_msg_type and fix_begin_string.
namespace glz::fix::detail
{
   template <class T>
   constexpr std::string_view msg_type_of()
   {
      if constexpr (requires { meta<T>::fix_msg_type; }) {
         return std::string_view{meta<T>::fix_msg_type};
      }
      else {
         return {};
      }
   }

   template <class T>
   constexpr std::string_view begin_string_of()
   {
      if constexpr (requires { meta<T>::fix_begin_string; }) {
         return std::string_view{meta<T>::fix_begin_string};
      }
      else {
         return "FIX.4.4";
      }
   }

   constexpr uint32_t key_tag(std::string_view k)
   {
      uint32_t v = 0;
      for (char c : k) v = v * 10 + uint32_t(c - '0');
      return v;
   }

   template <class V>
   bool read_value(V& v, std::string_view s)
   {
      using T = std::remove_cvref_t<V>;
      if constexpr (std::same_as<T, bool>) {
         if (s == "Y") v = true;
         else if (s == "N") v = false;
         else return false;
         return true;
      }
      else if constexpr (std::same_as<T, char>) {
         if (s.size() != 1) return false;
         v = s[0];
         return true;
      }
      else if constexpr (std::integral<T>) {
         // FIX int: optional '-', digits, leading zeros permitted, no '+'.
         if (s.empty() || s[0] == '+') return false;
         auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), v);
         return ec == std::errc{} && p == s.data() + s.size();
      }
      else if constexpr (std::floating_point<T>) {
         // FIX float: optional '-', digits with optional '.', no exponent, no '+'.
         if (s.empty() || s[0] == '+') return false;
         for (char c : s) {
            if (!((c >= '0' && c <= '9') || c == '.' || c == '-')) return false;
         }
         auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), v, std::chars_format::fixed);
         return ec == std::errc{} && p == s.data() + s.size();
      }
      else if constexpr (std::assignable_from<T&, std::string_view>) {
         v = s;
         return true;
      }
      else {
         static_assert(false_v<T>, "fix stub: unsupported member type");
      }
   }

   template <class V>
   bool write_value(const V& v, std::string& out, char soh)
   {
      using T = std::remove_cvref_t<V>;
      char buf[512]; // fixed notation of DBL_MAX or the smallest denormal needs over 300 digits
      if constexpr (std::same_as<T, bool>) {
         out.push_back(v ? 'Y' : 'N');
      }
      else if constexpr (std::same_as<T, char>) {
         if (v == soh) return false; // FIX char: any byte but the delimiter
         out.push_back(v);
      }
      else if constexpr (std::integral<T>) {
         auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), v);
         out.append(buf, p);
      }
      else if constexpr (std::floating_point<T>) {
         auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), v, std::chars_format::fixed);
         if (ec != std::errc{}) return false;
         out.append(buf, p);
      }
      else {
         const std::string_view s{v};
         if (s.empty() || s.find(soh) != std::string_view::npos) return false;
         out.append(s);
      }
      return true;
   }
}

namespace glz
{
   template <>
   struct parse<FIX>
   {
      template <auto Opts, class T, is_context Ctx, class It0, class It1>
      static void op(T&& value, Ctx&& ctx, It0&& it, It1 end)
      {
         from<FIX, std::remove_cvref_t<T>>::template op<Opts>(std::forward<T>(value), std::forward<Ctx>(ctx),
                                                             std::forward<It0>(it), end);
      }
   };

   template <class T>
      requires glaze_object_t<T>
   struct from<FIX, T>
   {
      template <auto Opts, class Ctx, class It0, class It1>
      static void op(T& value, Ctx& ctx, It0& it, It1 end)
      {
         constexpr char soh = [] {
            if constexpr (requires { Opts.soh; }) return Opts.soh;
            else return '\x01';
         }();
         constexpr bool check_len = [] {
            if constexpr (requires { Opts.validate_body_length; }) return Opts.validate_body_length;
            else return true;
         }();
         constexpr bool check_sum = [] {
            if constexpr (requires { Opts.validate_checksum; }) return Opts.validate_checksum;
            else return true;
         }();
         const std::string_view msg{&*it, size_t(end - it)};
         if (auto e = fix::validate_impl(msg, soh, check_len, check_sum)) {
            ctx.error = e.ec;
            ctx.custom_error_message = e.custom_error_message;
            return;
         }
         auto fields = fix::parse_fields(msg, soh);
         constexpr auto expected_type = fix::detail::msg_type_of<T>();
         if constexpr (!expected_type.empty()) {
            if ((*fields)[2].value != expected_type) {
               ctx.error = error_code::invalid_header;
               ctx.custom_error_message = "fix: MsgType(35) does not match the struct";
               return;
            }
         }
         static constexpr auto N = reflect<T>::size;
         uint64_t seen[(N + 63) / 64 + 1]{};
         for (size_t k = 3; k + 1 < fields->size(); ++k) {
            const auto& fld = (*fields)[k];
            bool matched = false;
            bool ok = true;
            bool dup = false;
            for_each<N>([&]<size_t I>() {
               static constexpr uint32_t tag = fix::detail::key_tag(reflect<T>::keys[I]);
               if (!matched && fld.tag == tag) {
                  matched = true;
                  if (seen[I / 64] & (uint64_t(1) << (I % 64))) {
                     dup = true;
                     return;
                  }
                  seen[I / 64] |= uint64_t(1) << (I % 64);
                  ok = fix::detail::read_value(get_member(value, get<I>(reflect<T>::values)), fld.value);
               }
            });
            if (dup) {
               ctx.error = error_code::syntax_error;
               ctx.custom_error_message = "fix: duplicate tag";
               return;
            }
            if (!ok) {
               ctx.error = error_code::parse_number_failure;
               ctx.custom_error_message = "fix: invalid value for the member type";
               return;
            }
            if (!matched && Opts.error_on_unknown_keys) {
               // Length tags are carried implicitly with their data member.
               if (fix::data_tag_for_length(fld.tag) == 0) {
                  ctx.error = error_code::unknown_key;
                  ctx.custom_error_message = "fix: unknown tag";
                  return;
               }
            }
         }
         it = end;
      }
   };

   template <class T>
      requires glaze_object_t<T>
   struct to<FIX, T>
   {
      template <auto Opts, class Ctx, class B, class IX>
      static void op(const T& value, Ctx& ctx, B& b, IX& ix)
      {
         constexpr char soh = [] {
            if constexpr (requires { Opts.soh; }) return Opts.soh;
            else return '\x01';
         }();
         std::string body;
         body.append("35=");
         body.append(fix::detail::msg_type_of<T>().empty() ? std::string_view{"0"} : fix::detail::msg_type_of<T>());
         body.push_back(soh);
         static constexpr auto N = reflect<T>::size;
         bool ok = true;
         for_each<N>([&]<size_t I>() {
            if (!ok) return;
            static constexpr auto key = reflect<T>::keys[I];
            const auto& member = get_member(value, get<I>(reflect<T>::values));
            using M = std::remove_cvref_t<decltype(member)>;
            if constexpr (!std::integral<M> && !std::floating_point<M>) {
               if constexpr (requires { std::string_view{member}.empty(); }) {
                  if (std::string_view{member}.empty()) return; // FIX has no empty values: omit
               }
            }
            body.append(key);
            body.push_back('=');
            ok = fix::detail::write_value(member, body, soh);
            body.push_back(soh);
         });
         if (!ok) {
            ctx.error = error_code::syntax_error;
            ctx.custom_error_message = "fix: value cannot be written (SOH inside or not representable)";
            return;
         }
         std::string msg;
         msg.append("8=");
         msg.append(fix::detail::begin_string_of<T>());
         msg.push_back(soh);
         msg.append("9=");
         msg.append(std::to_string(body.size()));
         msg.push_back(soh);
         msg.append(body);
         const unsigned cs = fix::checksum(msg);
         msg.append("10=");
         msg.push_back(char('0' + cs / 100));
         msg.push_back(char('0' + (cs / 10) % 10));
         msg.push_back(char('0' + cs % 10));
         msg.push_back(soh);
         if (b.size() < ix + msg.size()) b.resize(ix + msg.size());
         std::memcpy(b.data() + ix, msg.data(), msg.size());
         ix += msg.size();
      }
   };
}
