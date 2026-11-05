// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

// Low-level FIX tag=value scanning: field splitting, checksum, structural validation and framing.
// None of these allocate except parse_fields, which returns a vector of views into the input.

#include <cstddef>
#include <cstdint>
#include <limits>
#include <string_view>
#include <vector>

#include "glaze/core/context.hpp"
#include "glaze/util/expected.hpp"

namespace glz::fix
{
   struct field
   {
      uint32_t tag{};
      std::string_view value{};
   };

   // Returned by frame() when the bytes at the front of the stream cannot start a FIX message.
   inline constexpr size_t frame_error = (std::numeric_limits<size_t>::max)();

   namespace detail
   {
      // Parses a decimal unsigned tag number. Returns false on empty, non-digit or overflow.
      constexpr bool parse_uint(std::string_view s, uint32_t& out) noexcept
      {
         if (s.empty() || s.size() > 9) {
            return false;
         }
         uint32_t v = 0;
         for (const char c : s) {
            if (c < '0' || c > '9') {
               return false;
            }
            v = v * 10 + uint32_t(c - '0');
         }
         out = v;
         return true;
      }

      constexpr bool parse_size(std::string_view s, size_t& out) noexcept
      {
         uint32_t v{};
         if (!parse_uint(s, v)) {
            return false;
         }
         out = v;
         return true;
      }

      // Scans one field starting at pos. On success sets f, advances pos past the SOH, and returns none.
      constexpr error_code next_field(std::string_view msg, size_t& pos, char soh, field& f) noexcept
      {
         const size_t eq = msg.find('=', pos);
         if (eq == std::string_view::npos) {
            return error_code::syntax_error;
         }
         const size_t end = msg.find(soh, eq + 1);
         if (end == std::string_view::npos) {
            return error_code::unexpected_end;
         }
         const auto tag = msg.substr(pos, eq - pos);
         // a tag never contains the delimiter; reject "a|b=c" style corruption
         if (tag.find(soh) != std::string_view::npos || !parse_uint(tag, f.tag) || f.tag == 0) {
            return error_code::syntax_error;
         }
         f.value = msg.substr(eq + 1, end - eq - 1);
         if (f.value.empty()) {
            return error_code::syntax_error; // FIX forbids empty values
         }
         pos = end + 1;
         return error_code::none;
      }
   }

   // Splits one message into its fields. Every field must be "tag=value<soh>", including the last one.
   inline glz::expected<std::vector<field>, glz::error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t pos = 0;
      while (pos < msg.size()) {
         field f{};
         const auto ec = detail::next_field(msg, pos, soh, f);
         if (ec != error_code::none) {
            return glz::unexpected(error_ctx{pos, ec, "fix: malformed field"});
         }
         out.push_back(f);
      }
      if (out.empty()) {
         return glz::unexpected(error_ctx{0, error_code::no_read_input, "fix: empty message"});
      }
      return out;
   }

   // Sum of all bytes modulo 256 (the value of tag 10 for the bytes before "10=").
   constexpr uint8_t checksum(std::string_view bytes_before_tag10) noexcept
   {
      uint32_t sum = 0;
      for (const char c : bytes_before_tag10) {
         sum += uint8_t(c);
      }
      return uint8_t(sum & 0xFF);
   }

   // Structural validation of one complete message:
   // 8 first, 9 second, 35 third, 10 last; 9 equals the body length and 10 the checksum (3 digits).
   // `check_body_length` and `check_checksum` allow the value comparisons to be switched off.
   constexpr error_ctx validate(std::string_view msg, char soh = '\x01', bool check_body_length = true,
                                bool check_checksum = true) noexcept
   {
      size_t pos = 0;
      field f{};
      auto fail = [&](error_code ec, std::string_view what) { return error_ctx{pos, ec, what}; };

      if (msg.empty()) {
         return fail(error_code::no_read_input, "fix: empty message");
      }
      if (detail::next_field(msg, pos, soh, f) != error_code::none) {
         return fail(error_code::syntax_error, "fix: malformed field");
      }
      if (f.tag != 8) {
         return fail(error_code::invalid_header, "fix: BeginString (8) must be the first field");
      }
      if (detail::next_field(msg, pos, soh, f) != error_code::none) {
         return fail(error_code::syntax_error, "fix: malformed field");
      }
      if (f.tag != 9) {
         return fail(error_code::invalid_header, "fix: BodyLength (9) must be the second field");
      }
      size_t body_length{};
      if (!detail::parse_size(f.value, body_length)) {
         return fail(error_code::invalid_header, "fix: BodyLength (9) is not a number");
      }
      const size_t body_start = pos;
      if (detail::next_field(msg, pos, soh, f) != error_code::none) {
         return fail(error_code::syntax_error, "fix: malformed field");
      }
      if (f.tag != 35) {
         return fail(error_code::invalid_header, "fix: MsgType (35) must be the third field");
      }
      size_t trailer_start = pos;
      while (pos < msg.size()) {
         trailer_start = pos;
         if (detail::next_field(msg, pos, soh, f) != error_code::none) {
            return fail(error_code::syntax_error, "fix: malformed field");
         }
         if (f.tag == 10) {
            break;
         }
      }
      if (f.tag != 10) {
         return fail(error_code::invalid_body, "fix: CheckSum (10) missing");
      }
      if (pos != msg.size()) {
         return fail(error_code::invalid_body, "fix: CheckSum (10) must be the last field");
      }
      if (check_body_length && trailer_start - body_start != body_length) {
         return fail(error_code::invalid_body, "fix: BodyLength (9) mismatch");
      }
      uint32_t sum{};
      if (f.value.size() != 3 || !detail::parse_uint(f.value, sum)) {
         return fail(error_code::invalid_body, "fix: CheckSum (10) must be three digits");
      }
      if (check_checksum && sum != checksum(msg.substr(0, trailer_start))) {
         return fail(error_code::invalid_body, "fix: CheckSum (10) mismatch");
      }
      return {pos, error_code::none, {}};
   }

   // Finds the end of the first complete message at the front of `stream`.
   // Returns its length, 0 if more bytes are needed, or frame_error if the front cannot be a FIX message.
   // Framing relies on BodyLength only; call validate() on the framed bytes to check the rest.
   constexpr size_t frame(std::string_view stream, char soh = '\x01') noexcept
   {
      // "8=" ... soh "9=" digits soh body "10=" ddd soh
      if (stream.size() < 2) {
         return (stream.empty() || stream[0] == '8') ? 0 : frame_error;
      }
      if (stream[0] != '8' || stream[1] != '=') {
         return frame_error;
      }
      const size_t s1 = stream.find(soh);
      if (s1 == std::string_view::npos) {
         return 0;
      }
      const auto rest = stream.substr(s1 + 1);
      if (rest.size() < 2) {
         return (rest.empty() || rest[0] == '9') ? 0 : frame_error;
      }
      if (rest[0] != '9' || rest[1] != '=') {
         return frame_error;
      }
      const size_t s2 = stream.find(soh, s1 + 1);
      if (s2 == std::string_view::npos) {
         return (stream.size() - (s1 + 3) > 9) ? frame_error : 0;
      }
      size_t body_length{};
      if (!detail::parse_size(stream.substr(s1 + 3, s2 - (s1 + 3)), body_length)) {
         return frame_error;
      }
      const size_t trailer = s2 + 1 + body_length;
      const size_t total = trailer + 7; // "10=ddd" + soh
      if (stream.size() < total) {
         return 0;
      }
      if (stream.substr(trailer, 3) != "10=" || stream[total - 1] != soh) {
         return frame_error;
      }
      return total;
   }
}
