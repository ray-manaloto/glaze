// Glaze Library
// For the license information refer to glaze.hpp

// LOCAL STUB of the shared FIX API contract (see docs/fix/api.md on branch fix/core).
// Branch fix/tests-more-parsers keeps this stub only until fix/core publishes the real header;
// on merge, take fix/core's version of this file. Only the low-level scanner, checksum,
// validate and frame entry points are stubbed; struct mapping (glz::read/write) is not.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>
#include <vector>

#include "glaze/core/context.hpp"
#include "glaze/core/opts.hpp"
#include "glaze/util/expected.hpp"

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

   namespace detail
   {
      // Parses a tag: one or more ASCII digits, no leading zero, value in 1..UINT32_MAX.
      inline bool parse_tag(std::string_view s, uint32_t& out) noexcept
      {
         if (s.empty() || s.size() > 10 || s[0] == '0') return false;
         uint64_t v = 0;
         for (const char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + uint64_t(c - '0');
         }
         if (v > 0xFFFFFFFFull) return false;
         out = uint32_t(v);
         return true;
      }

      inline bool parse_uint(std::string_view s, size_t& out) noexcept
      {
         if (s.empty() || s.size() > 9) return false;
         size_t v = 0;
         for (const char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + size_t(c - '0');
         }
         out = v;
         return true;
      }
   }

   // Scans one complete message into tag=value fields. Every field must be terminated by soh.
   inline glz::expected<std::vector<field>, glz::error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out{};
      size_t i = 0;
      while (i < msg.size()) {
         const size_t eq = msg.find('=', i);
         const size_t end = msg.find(soh, i);
         if (end == std::string_view::npos) {
            return glz::unexpected(glz::error_ctx{i, glz::error_code::unexpected_end, "field not terminated"});
         }
         if (eq == std::string_view::npos || eq > end) {
            return glz::unexpected(glz::error_ctx{i, glz::error_code::syntax_error, "missing '='"});
         }
         field f{};
         if (!detail::parse_tag(msg.substr(i, eq - i), f.tag)) {
            return glz::unexpected(glz::error_ctx{i, glz::error_code::syntax_error, "invalid tag"});
         }
         f.value = msg.substr(eq + 1, end - eq - 1);
         out.push_back(f);
         i = end + 1;
      }
      return out;
   }

   inline uint8_t checksum(std::string_view bytes_before_tag10)
   {
      uint32_t sum = 0;
      for (const char c : bytes_before_tag10) sum += uint8_t(c);
      return uint8_t(sum & 0xFF);
   }

   inline glz::error_ctx validate(std::string_view msg, char soh = '\x01')
   {
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      const auto& f = *fields;
      if (f.size() < 4 || f[0].tag != 8 || f[1].tag != 9 || f[2].tag != 35 || f.back().tag != 10) {
         return {0, glz::error_code::invalid_header, "expected 8, 9, 35 first and 10 last"};
      }
      for (size_t k = 1; k + 1 < f.size(); ++k) {
         if (f[k].tag == 8 || f[k].tag == 10 || (k != 1 && f[k].tag == 9)) {
            return {0, glz::error_code::invalid_header, "header or trailer tag out of place"};
         }
      }
      if (f[0].value.empty()) return {0, glz::error_code::invalid_header, "empty BeginString"};
      // Offsets: views point into msg.
      const size_t body_begin = size_t(f[1].value.data() + f[1].value.size() + 1 - msg.data());
      const size_t trailer_begin = size_t(f.back().value.data() - msg.data()) - 3; // "10="
      size_t body_len{};
      if (!detail::parse_uint(f[1].value, body_len) || body_len != trailer_begin - body_begin) {
         return {body_begin, glz::error_code::invalid_length, "BodyLength(9) mismatch"};
      }
      size_t cs{};
      const auto cs_text = f.back().value;
      if (cs_text.size() != 3 || !detail::parse_uint(cs_text, cs) ||
          cs != checksum(msg.substr(0, trailer_begin))) {
         return {trailer_begin, glz::error_code::constraint_violated, "CheckSum(10) mismatch"};
      }
      return {};
   }

   // Length of the first complete message at the start of stream; 0 if incomplete or not framed.
   inline size_t frame(std::string_view stream, char soh = '\x01')
   {
      if (!stream.starts_with("8=")) return 0;
      const size_t e8 = stream.find(soh);
      if (e8 == std::string_view::npos) return 0;
      const size_t p9 = e8 + 1;
      if (stream.substr(p9, 2) != "9=") return 0;
      const size_t e9 = stream.find(soh, p9);
      if (e9 == std::string_view::npos) return 0;
      size_t len{};
      if (!detail::parse_uint(stream.substr(p9 + 2, e9 - p9 - 2), len)) return 0;
      const size_t p10 = e9 + 1 + len;
      if (stream.size() < p10 + 7) return 0;
      if (stream.substr(p10, 3) != "10=" || stream[p10 + 6] != soh) return 0;
      return p10 + 7;
   }
}
