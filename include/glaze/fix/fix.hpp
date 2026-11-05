// Glaze Library
// For the license information refer to glaze.hpp

// LOCAL STUB of the shared FIX API contract (branch fix/core owns the real header).
// It implements only the low-level scanner functions (parse_fields, checksum, validate, frame)
// so the ported hffix/fixpp tests can run. Replace this file with fix/core's version when it lands.
// Struct mapping (glz::read/glz::write with fix_opts) is NOT provided here; tests that need it are
// compiled only when GLZ_FIX_HAS_STRUCT_MAPPING is defined.

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
      inline error_ctx fail(size_t at, std::string_view why) noexcept
      {
         return error_ctx{at, error_code::syntax_error, why};
      }

      // Parses "digits" into out, returns false on empty / non-digit / overflow.
      inline bool parse_uint(std::string_view s, uint64_t& out) noexcept
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

   inline glz::expected<std::vector<field>, error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t i = 0;
      while (i < msg.size()) {
         const size_t eq = msg.find('=', i);
         if (eq == std::string_view::npos) return glz::unexpected(detail::fail(i, "missing '='"));
         uint64_t tag{};
         if (!detail::parse_uint(msg.substr(i, eq - i), tag) || tag == 0 || tag > 0xFFFFFFFFull)
            return glz::unexpected(detail::fail(i, "invalid tag"));
         const size_t end = msg.find(soh, eq + 1);
         if (end == std::string_view::npos) return glz::unexpected(error_ctx{eq + 1, error_code::unexpected_end, "missing SOH"});
         out.push_back(field{uint32_t(tag), msg.substr(eq + 1, end - eq - 1)});
         i = end + 1;
      }
      return out;
   }

   inline uint8_t checksum(std::string_view bytes) noexcept
   {
      uint32_t sum = 0;
      for (char c : bytes) sum += static_cast<unsigned char>(c);
      return static_cast<uint8_t>(sum & 0xFF);
   }

   inline error_ctx validate(std::string_view msg, char soh = '\x01')
   {
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      const auto& f = *fields;
      if (f.size() < 4) return detail::fail(0, "message too short");
      if (f[0].tag != 8) return detail::fail(0, "tag 8 must be first");
      if (f[1].tag != 9) return detail::fail(0, "tag 9 must be second");
      if (f[2].tag != 35) return detail::fail(0, "tag 35 must be third");
      if (f.back().tag != 10) return detail::fail(0, "tag 10 must be last");
      for (size_t k = 0; k + 1 < f.size(); ++k)
         if (f[k].tag == 10) return detail::fail(0, "tag 10 must be last");

      // offsets via the views (they point into msg)
      const size_t body_begin = size_t(f[1].value.data() + f[1].value.size() + 1 - msg.data());
      const size_t trailer_begin = size_t(f.back().value.data() - msg.data()) - 3; // start of "10="
      uint64_t body_len{};
      if (!detail::parse_uint(f[1].value, body_len)) return detail::fail(body_begin, "invalid BodyLength");
      if (body_len != trailer_begin - body_begin)
         return error_ctx{body_begin, error_code::constraint_violated, "BodyLength mismatch"};
      uint64_t cs{};
      if (f.back().value.size() != 3 || !detail::parse_uint(f.back().value, cs))
         return detail::fail(trailer_begin, "invalid CheckSum");
      if (cs != checksum(msg.substr(0, trailer_begin)))
         return error_ctx{trailer_begin, error_code::constraint_violated, "CheckSum mismatch"};
      return {};
   }

   // Returns the size of the first complete message in stream, or 0 if more bytes are needed
   // (or the stream does not start with a well formed 8=...<soh>9=...<soh> header).
   inline size_t frame(std::string_view stream, char soh = '\x01') noexcept
   {
      if (stream.size() < 2 || stream[0] != '8' || stream[1] != '=') return 0;
      const size_t e8 = stream.find(soh);
      if (e8 == std::string_view::npos || stream.size() < e8 + 3) return 0;
      if (stream[e8 + 1] != '9' || stream[e8 + 2] != '=') return 0;
      const size_t e9 = stream.find(soh, e8 + 3);
      if (e9 == std::string_view::npos) return 0;
      uint64_t body_len{};
      if (!detail::parse_uint(stream.substr(e8 + 3, e9 - e8 - 3), body_len)) return 0;
      const size_t total = e9 + 1 + size_t(body_len) + 7; // "10=NNN" + soh
      if (stream.size() < total) return 0;
      return total;
   }
}
