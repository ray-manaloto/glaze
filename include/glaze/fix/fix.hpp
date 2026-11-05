// Glaze Library
// For the license information refer to glaze.hpp

// LOCAL STUB of the shared FIX API contract (see docs/fix/api.md once fix/core lands).
// It implements only the low-level layer (parse_fields, checksum, validate, frame) so the
// tests in tests/fix_quickfix_test can run. Struct mapping (glz::read/glz::write with
// fix_opts) is NOT implemented here. Replace this file with fix/core's version when it lands.

#pragma once

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
      uint32_t tag;
      std::string_view value;
   };

   namespace detail
   {
      inline error_ctx make_err(error_code ec, std::string_view msg, size_t at = 0)
      {
         return error_ctx{at, ec, msg};
      }
      // Parses a non-negative decimal integer with no sign and no leading '+'.
      inline bool to_uint(std::string_view s, uint64_t& out)
      {
         if (s.empty() || s.size() > 18) return false;
         uint64_t v = 0;
         for (char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + uint64_t(c - '0');
         }
         out = v;
         return true;
      }
   }

   inline glz::expected<std::vector<field>, glz::error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t i = 0;
      while (i < msg.size()) {
         const size_t eq = msg.find('=', i);
         if (eq == std::string_view::npos) return glz::unexpected(detail::make_err(error_code::parse_error, "missing '='", i));
         uint64_t tag{};
         const auto tag_sv = msg.substr(i, eq - i);
         if (tag_sv.size() > 1 && tag_sv[0] == '0') return glz::unexpected(detail::make_err(error_code::parse_error, "leading zero in tag", i));
         if (!detail::to_uint(tag_sv, tag) || tag == 0 || tag > 0xFFFFFFFFu)
            return glz::unexpected(detail::make_err(error_code::parse_error, "invalid tag", i));
         const size_t end = msg.find(soh, eq + 1);
         if (end == std::string_view::npos) return glz::unexpected(detail::make_err(error_code::unexpected_end, "missing SOH", eq));
         out.push_back(field{uint32_t(tag), msg.substr(eq + 1, end - eq - 1)});
         i = end + 1;
      }
      return out;
   }

   inline uint8_t checksum(std::string_view bytes_before_tag10)
   {
      uint32_t sum = 0;
      for (unsigned char c : bytes_before_tag10) sum += c;
      return uint8_t(sum % 256);
   }

   inline glz::error_ctx validate(std::string_view msg, char soh = '\x01')
   {
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      auto& f = *fields;
      if (f.size() < 4) return detail::make_err(error_code::parse_error, "too few fields");
      if (f[0].tag != 8 || f[0].value.empty()) return detail::make_err(error_code::parse_error, "8 must be first");
      if (f[1].tag != 9) return detail::make_err(error_code::parse_error, "9 must be second");
      if (f[2].tag != 35 || f[2].value.empty()) return detail::make_err(error_code::parse_error, "35 must be third");
      if (f.back().tag != 10) return detail::make_err(error_code::parse_error, "10 must be last");
      for (size_t k = 3; k + 1 < f.size(); ++k) {
         if (f[k].tag == 8 || f[k].tag == 9 || f[k].tag == 35 || f[k].tag == 10)
            return detail::make_err(error_code::parse_error, "misplaced header/trailer tag");
      }
      uint64_t body_len{};
      if (!detail::to_uint(f[1].value, body_len)) return detail::make_err(error_code::parse_error, "invalid BodyLength");
      // Body starts after "9=...<SOH>" and ends at the SOH before "10=".
      const size_t body_start = size_t(f[1].value.data() + f[1].value.size() + 1 - msg.data());
      const size_t trailer_start = size_t(f.back().value.data() - 3 - msg.data());
      if (trailer_start < body_start || trailer_start - body_start != body_len)
         return detail::make_err(error_code::parse_error, "BodyLength mismatch");
      const auto cs = f.back().value;
      if (cs.size() != 3) return detail::make_err(error_code::parse_error, "CheckSum must be 3 digits");
      uint64_t cs_val{};
      if (!detail::to_uint(cs, cs_val)) return detail::make_err(error_code::parse_error, "invalid CheckSum");
      if (cs_val != checksum(msg.substr(0, trailer_start))) return detail::make_err(error_code::parse_error, "CheckSum mismatch");
      return {};
   }

   inline size_t frame(std::string_view stream, char soh = '\x01')
   {
      // Expect "8=...<SOH>9=<len><SOH>" then <len> body bytes then "10=xxx<SOH>".
      if (stream.size() < 2) return 0;
      const size_t e8 = stream.find(soh);
      if (e8 == std::string_view::npos) return 0;
      const size_t s9 = e8 + 1;
      if (stream.size() < s9 + 2) return 0;
      if (stream.substr(s9, 2) != "9=") return 0;
      const size_t e9 = stream.find(soh, s9 + 2);
      if (e9 == std::string_view::npos) return 0;
      uint64_t len{};
      if (!detail::to_uint(stream.substr(s9 + 2, e9 - s9 - 2), len)) return 0;
      const size_t t = e9 + 1 + size_t(len);
      if (stream.size() < t + 3) return 0;
      if (stream.substr(t, 3) != "10=") return 0;
      const size_t e10 = stream.find(soh, t + 3);
      if (e10 == std::string_view::npos) return 0;
      return e10 + 1;
   }
}
