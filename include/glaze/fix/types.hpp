// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

// Typed FIX value types: UTCTimestamp and an exact fixed-point decimal.

#include <chrono>
#include <cstdint>
#include <string>
#include <string_view>

namespace glz::fix
{
   // FIX UTCTimestamp: "YYYYMMDD-HH:MM:SS" with an optional fraction of 1 to 9 digits.
   // `precision` is the number of fractional digits written, and is set by a read to the digits seen.
   struct utc_timestamp
   {
      std::chrono::sys_time<std::chrono::nanoseconds> time{};
      uint8_t precision = 3; // 0..9; FIX uses 0 (seconds), 3 (ms), 6 (us) or 9 (ns)

      bool operator==(const utc_timestamp&) const = default;
   };

   // Exact decimal for FIX Price, Qty, Amt and friends: value = mantissa * 10^exponent.
   // Reading keeps the scale as written ("1.50" -> {150, -2}), so writing it back gives the same text.
   struct decimal
   {
      int64_t mantissa{};
      int32_t exponent{};

      bool operator==(const decimal&) const = default; // representation equality: 1.5 != 1.50

      constexpr double to_double() const noexcept
      {
         double v = double(mantissa);
         if (exponent < 0) {
            for (int32_t i = 0; i < -exponent; ++i) v /= 10.0;
         }
         else {
            for (int32_t i = 0; i < exponent; ++i) v *= 10.0;
         }
         return v;
      }
   };

   namespace detail
   {
      constexpr bool digits_to(std::string_view s, uint32_t& out) noexcept
      {
         if (s.empty()) return false;
         uint32_t v = 0;
         for (const char c : s) {
            if (c < '0' || c > '9') return false;
            v = v * 10 + uint32_t(c - '0');
         }
         out = v;
         return true;
      }

      inline void append_padded(std::string& out, uint64_t v, int width)
      {
         char buf[24];
         int n = 0;
         do {
            buf[n++] = char('0' + v % 10);
            v /= 10;
         } while (v != 0);
         for (int i = n; i < width; ++i) out.push_back('0');
         while (n > 0) out.push_back(buf[--n]);
      }
   }

   inline bool parse_utc_timestamp(std::string_view s, utc_timestamp& out) noexcept
   {
      using namespace std::chrono;
      if (s.size() < 17 || s[8] != '-' || s[11] != ':' || s[14] != ':') return false;
      uint32_t y{}, mo{}, d{}, h{}, mi{}, sec{};
      if (!detail::digits_to(s.substr(0, 4), y) || !detail::digits_to(s.substr(4, 2), mo) ||
          !detail::digits_to(s.substr(6, 2), d) || !detail::digits_to(s.substr(9, 2), h) ||
          !detail::digits_to(s.substr(12, 2), mi) || !detail::digits_to(s.substr(15, 2), sec)) {
         return false;
      }
      const year_month_day ymd{year{int(y)}, month{mo}, day{d}};
      if (!ymd.ok() || h > 23 || mi > 59 || sec > 59) return false;
      uint32_t frac = 0;
      uint8_t precision = 0;
      if (s.size() > 17) {
         const auto f = s.substr(18);
         if (s[17] != '.' || f.empty() || f.size() > 9 || !detail::digits_to(f, frac)) return false;
         precision = uint8_t(f.size());
         for (size_t i = f.size(); i < 9; ++i) frac *= 10;
      }
      out.time = sys_days{ymd} + hours{h} + minutes{mi} + seconds{sec} + nanoseconds{frac};
      out.precision = precision;
      return true;
   }

   inline void append_utc_timestamp(std::string& out, const utc_timestamp& t)
   {
      using namespace std::chrono;
      const auto dp = floor<days>(t.time);
      const year_month_day ymd{dp};
      const hh_mm_ss hms{t.time - dp};
      detail::append_padded(out, uint64_t(int(ymd.year())), 4);
      detail::append_padded(out, unsigned(ymd.month()), 2);
      detail::append_padded(out, unsigned(ymd.day()), 2);
      out.push_back('-');
      detail::append_padded(out, uint64_t(hms.hours().count()), 2);
      out.push_back(':');
      detail::append_padded(out, uint64_t(hms.minutes().count()), 2);
      out.push_back(':');
      detail::append_padded(out, uint64_t(hms.seconds().count()), 2);
      const uint8_t p = t.precision > 9 ? 9 : t.precision;
      if (p > 0) {
         uint64_t ns = uint64_t(hms.subseconds().count());
         for (int i = p; i < 9; ++i) ns /= 10; // truncate to the requested precision
         out.push_back('.');
         detail::append_padded(out, ns, p);
      }
   }

   inline bool parse_decimal(std::string_view s, decimal& out) noexcept
   {
      if (s.empty()) return false;
      bool neg = false;
      size_t i = 0;
      if (s[0] == '-') {
         neg = true;
         i = 1;
      }
      uint64_t m = 0;
      int digits = 0;
      int frac = 0;
      bool dot = false;
      for (; i < s.size(); ++i) {
         const char c = s[i];
         if (c == '.') {
            if (dot) return false;
            dot = true;
            continue;
         }
         if (c < '0' || c > '9') return false;
         if (++digits > 18) return false; // keeps the mantissa inside int64_t
         m = m * 10 + uint64_t(c - '0');
         if (dot) ++frac;
      }
      if (digits == 0) return false;
      out.mantissa = neg ? -int64_t(m) : int64_t(m);
      out.exponent = -frac;
      return true;
   }

   inline void append_decimal(std::string& out, const decimal& d)
   {
      const bool neg = d.mantissa < 0;
      const uint64_t m = neg ? uint64_t(0) - uint64_t(d.mantissa) : uint64_t(d.mantissa);
      if (neg && m != 0) out.push_back('-');
      if (d.exponent >= 0) {
         detail::append_padded(out, m, 1);
         if (m != 0) {
            for (int32_t i = 0; i < d.exponent; ++i) out.push_back('0');
         }
         return;
      }
      const int scale = -d.exponent;
      std::string digits;
      detail::append_padded(digits, m, scale + 1);
      out.append(digits, 0, digits.size() - size_t(scale));
      out.push_back('.');
      out.append(digits, digits.size() - size_t(scale), std::string::npos);
   }
}
