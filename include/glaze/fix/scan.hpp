// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

// Low-level FIX tag=value scanning: field splitting, checksum, structural validation and framing.
// None of these allocate except parse_fields, which returns a vector of views into the input.

#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string_view>
#include <type_traits>
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

   // Standard FIX length/data field pairs (Length type followed by a data field that may hold SOH).
   // Returns the data tag for a length tag, or 0 if `length_tag` is not a standard length field.
   constexpr uint32_t raw_data_tag_for(uint32_t length_tag) noexcept
   {
      switch (length_tag) {
      case 90: return 91; // SecureDataLen -> SecureData
      case 93: return 89; // SignatureLength -> Signature
      case 95: return 96; // RawDataLength -> RawData
      case 212: return 213; // XmlDataLen -> XmlData
      case 348: return 349; // EncodedIssuerLen
      case 350: return 351; // EncodedSecurityDescLen
      case 352: return 353; // EncodedListExecInstLen
      case 354: return 355; // EncodedTextLen
      case 356: return 357; // EncodedSubjectLen
      case 358: return 359; // EncodedHeadlineLen
      case 360: return 361; // EncodedAllocTextLen
      case 362: return 363; // EncodedUnderlyingIssuerLen
      case 364: return 365; // EncodedUnderlyingSecurityDescLen
      case 445: return 446; // EncodedListStatusTextLen
      case 618: return 619; // EncodedLegIssuerLen
      case 621: return 622; // EncodedLegSecurityDescLen
      default: return 0;
      }
   }

   // The length tag that announces `data_tag`, or 0.
   constexpr uint32_t raw_length_tag_for(uint32_t data_tag) noexcept
   {
      constexpr uint32_t lens[] = {90, 93, 95, 212, 348, 350, 352, 354, 356, 358, 360, 362, 364, 445, 618, 621};
      for (const auto l : lens) {
         if (raw_data_tag_for(l) == data_tag) return l;
      }
      return 0;
   }

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

      // 8-byte SWAR helpers. Both fall back to byte loops at compile time and on big-endian targets.
      inline constexpr bool swar_enabled = std::endian::native == std::endian::little;

      // Position of the first `c` in s at or after `from`, or npos. Branch-light: one 64-bit compare per 8 bytes.
      inline constexpr size_t find_byte(std::string_view s, size_t from, char c) noexcept
      {
         const size_t n = s.size();
         if (from >= n) return std::string_view::npos;
         if (std::is_constant_evaluated() || !swar_enabled) {
            for (size_t i = from; i < n; ++i) {
               if (s[i] == c) return i;
            }
            return std::string_view::npos;
         }
         const char* p = s.data();
         constexpr uint64_t lo = 0x0101010101010101ULL;
         constexpr uint64_t hi = 0x8080808080808080ULL;
         const uint64_t pat = lo * uint8_t(c);
         size_t i = from;
         for (; i + 8 <= n; i += 8) {
            uint64_t x;
            std::memcpy(&x, p + i, 8);
            x ^= pat;
            const uint64_t z = (x - lo) & ~x & hi; // high bit set in every zero byte
            if (z) return i + size_t(std::countr_zero(z) >> 3);
         }
         for (; i < n; ++i) {
            if (p[i] == c) return i;
         }
         return std::string_view::npos;
      }

      // Sum of all bytes (no modulo). Eight bytes at a time: lanes are split into even/odd bytes so each
      // 16-bit lane sums without carry into its neighbour; the lanes are folded at the end.
      inline constexpr uint32_t byte_sum(std::string_view s) noexcept
      {
         uint32_t sum = 0;
         size_t i = 0;
         const size_t n = s.size();
         if (!std::is_constant_evaluated() && swar_enabled) {
            const char* p = s.data();
            constexpr uint64_t even = 0x00FF00FF00FF00FFULL;
            constexpr size_t block = 8 * 128; // 128 adds of two 0xFF bytes (65280) fit a 16-bit lane
            while (i + 8 <= n) {
               const size_t stop = (n - i >= block) ? i + block : i + ((n - i) & ~size_t(7));
               uint64_t acc = 0;
               for (; i < stop; i += 8) {
                  uint64_t x;
                  std::memcpy(&x, p + i, 8);
                  acc += (x & even) + ((x >> 8) & even);
               }
               acc = (acc & 0x0000FFFF0000FFFFULL) + ((acc >> 16) & 0x0000FFFF0000FFFFULL);
               sum += uint32_t(acc & 0xFFFFFFFFULL) + uint32_t(acc >> 32);
            }
         }
         for (; i < n; ++i) {
            sum += uint8_t(s[i]);
         }
         return sum;
      }

      // Carries a pending raw-data length from a length field (e.g. 95) to its data field (e.g. 96).
      struct scan_state
      {
         uint32_t raw_tag{};
         size_t raw_len{};
      };

      // Scans one field starting at pos. On success sets f, advances pos past the SOH, and returns none.
      // A data field that directly follows its length field is read by byte count and may hold SOH.
      constexpr error_code next_field(std::string_view msg, size_t& pos, char soh, field& f,
                                      scan_state& st) noexcept
      {
         const size_t eq = find_byte(msg, pos, '=');
         if (eq == std::string_view::npos) {
            return error_code::syntax_error;
         }
         if (st.raw_tag != 0) {
            const auto pending = st;
            st = {};
            uint32_t t{};
            if (parse_uint(msg.substr(pos, eq - pos), t) && t == pending.raw_tag) {
               const size_t vend = eq + 1 + pending.raw_len;
               if (vend >= msg.size()) {
                  return error_code::unexpected_end;
               }
               if (msg[vend] != soh) {
                  return error_code::syntax_error; // the length field disagrees with the data
               }
               f.tag = t;
               f.value = msg.substr(eq + 1, pending.raw_len);
               pos = vend + 1;
               return error_code::none;
            }
         }
         const size_t end = find_byte(msg, eq + 1, soh);
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
         if (const uint32_t data_tag = raw_data_tag_for(f.tag); data_tag != 0) {
            size_t len{};
            if (!parse_size(f.value, len)) {
               return error_code::syntax_error; // a length field must be a number
            }
            st = {data_tag, len};
         }
         return error_code::none;
      }

      constexpr error_code next_field(std::string_view msg, size_t& pos, char soh, field& f) noexcept
      {
         scan_state st{};
         return next_field(msg, pos, soh, f, st);
      }
   }

   // Zero-allocation forward scanner over one message. Raw-data fields are handled as in parse_fields.
   //   glz::fix::field_cursor c{msg, '|'};
   //   for (glz::fix::field f; c.next(f);) { ... }
   //   if (c.error()) { ... }
   class field_cursor
   {
     public:
      constexpr field_cursor() = default;
      constexpr explicit field_cursor(std::string_view msg, char soh = '\x01') noexcept : msg_(msg), soh_(soh) {}

      // Reads the next field into f. Returns false at the end of the message or on a malformed field.
      constexpr bool next(field& f) noexcept
      {
         if (ec_ != error_code::none || pos_ >= msg_.size()) return false;
         const size_t start = pos_;
         ec_ = detail::next_field(msg_, pos_, soh_, f, st_);
         if (ec_ != error_code::none) {
            pos_ = start;
            return false;
         }
         return true;
      }

      // none, or why scanning stopped early. `count` is the byte offset of the bad field.
      constexpr error_ctx error() const noexcept
      {
         if (ec_ == error_code::none) return {pos_, ec_, {}};
         return {pos_, ec_, "fix: malformed field"};
      }

      constexpr size_t position() const noexcept { return pos_; } // byte offset of the next field
      constexpr bool done() const noexcept { return pos_ >= msg_.size() || ec_ != error_code::none; }

     private:
      std::string_view msg_{};
      size_t pos_{};
      char soh_{'\x01'};
      error_code ec_{error_code::none};
      detail::scan_state st_{};
   };

   // Calls fn(const field&) for every field without allocating. If fn returns bool, false stops early.
   // Returns the scanner's error, if any.
   template <class Fn>
   constexpr error_ctx for_each_field(std::string_view msg, char soh, Fn&& fn)
   {
      field_cursor c{msg, soh};
      for (field f; c.next(f);) {
         if constexpr (std::is_same_v<decltype(fn(f)), bool>) {
            if (!fn(f)) break;
         }
         else {
            fn(f);
         }
      }
      return c.error();
   }

   // Splits one message into its fields. Every field must be "tag=value<soh>", including the last one.
   inline glz::expected<std::vector<field>, glz::error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t pos = 0;
      detail::scan_state st{};
      while (pos < msg.size()) {
         field f{};
         const auto ec = detail::next_field(msg, pos, soh, f, st);
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
      return uint8_t(detail::byte_sum(bytes_before_tag10) & 0xFF);
   }

   // Structural validation of one complete message:
   // 8 first, 9 second, 35 third, 10 last; 9 equals the body length and 10 the checksum (3 digits).
   // `check_body_length` and `check_checksum` allow the value comparisons to be switched off.
   constexpr error_ctx validate(std::string_view msg, char soh = '\x01', bool check_body_length = true,
                                bool check_checksum = true) noexcept
   {
      size_t pos = 0;
      field f{};
      detail::scan_state st{};
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
         if (detail::next_field(msg, pos, soh, f, st) != error_code::none) {
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
      const size_t s1 = detail::find_byte(stream, 0, soh);
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
      const size_t s2 = detail::find_byte(stream, s1 + 1, soh);
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
