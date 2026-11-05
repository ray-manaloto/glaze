// Glaze Library
// For the license information refer to glaze.hpp
//
// LOCAL STUB of the shared FIX API contract (docs/fix/api.md), kept on branch fix/dictionary
// until branch fix/core publishes the real header. When fix/core lands, replace this file with
// fix/core's version. It implements just enough of the contract (scanner, checksum, validate,
// frame, struct read/write via glz::meta tag mappings) for the dictionary round-trip tests.

#pragma once

#include <array>
#include <charconv>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

#include "glaze/core/common.hpp"
#include "glaze/core/context.hpp"
#include "glaze/core/opts.hpp"
#include "glaze/core/reflect.hpp"
#include "glaze/util/expected.hpp"
#include "glaze/util/for_each.hpp"

namespace glz
{
   inline constexpr uint32_t FIX = 65536 + 9; // custom format id (>= 65536 per glaze #1619)

   struct fix_opts : opts
   {
      uint32_t format = FIX;
      char soh = '\x01';
      bool validate_checksum = true; // tag 10
      bool validate_body_length = true; // tag 9
   };
}

namespace glz::fix
{
   struct field
   {
      uint32_t tag{};
      std::string_view value{};
   };

   inline expected<std::vector<field>, error_ctx> parse_fields(std::string_view msg, char soh = '\x01')
   {
      std::vector<field> out;
      size_t i = 0;
      while (i < msg.size()) {
         const size_t start = i;
         uint32_t tag = 0;
         while (i < msg.size() && msg[i] >= '0' && msg[i] <= '9') {
            tag = tag * 10 + uint32_t(msg[i] - '0');
            ++i;
         }
         if (i == start || i >= msg.size() || msg[i] != '=') {
            return unexpected(error_ctx{i, error_code::syntax_error, "expected tag="});
         }
         ++i;
         const size_t vstart = i;
         while (i < msg.size() && msg[i] != soh) ++i;
         if (i >= msg.size()) {
            return unexpected(error_ctx{i, error_code::unexpected_end, "field not terminated by SOH"});
         }
         out.push_back(field{tag, msg.substr(vstart, i - vstart)});
         ++i;
      }
      return out;
   }

   inline uint8_t checksum(std::string_view bytes_before_tag10)
   {
      uint32_t sum = 0;
      for (const char c : bytes_before_tag10) sum += uint8_t(c);
      return uint8_t(sum % 256);
   }

   namespace detail
   {
      inline bool parse_uint(std::string_view s, size_t& v)
      {
         if (s.empty()) return false;
         auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), v);
         return ec == std::errc{} && p == s.data() + s.size();
      }
   }

   // Checks: 8 first, 9 second, 35 third, 10 last; 9 (BodyLength) and 10 (CheckSum) correct.
   inline error_ctx validate(std::string_view msg, char soh = '\x01', bool check_body_length = true,
                             bool check_checksum = true)
   {
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      const auto& f = *fields;
      if (f.size() < 4 || f[0].tag != 8 || f[1].tag != 9 || f[2].tag != 35 || f.back().tag != 10) {
         return {0, error_code::syntax_error, "FIX header/trailer order (8, 9, 35 ... 10)"};
      }
      const size_t body_start = size_t(f[1].value.data() - msg.data()) + f[1].value.size() + 1;
      const size_t trailer_start = size_t(f.back().value.data() - msg.data()) - 3; // "10="
      if (check_body_length) {
         size_t len{};
         if (!detail::parse_uint(f[1].value, len) || len != trailer_start - body_start) {
            return {body_start, error_code::syntax_error, "BodyLength(9) mismatch"};
         }
      }
      if (check_checksum) {
         size_t sum{};
         if (f.back().value.size() != 3 || !detail::parse_uint(f.back().value, sum) ||
             sum != checksum(msg.substr(0, trailer_start))) {
            return {trailer_start, error_code::syntax_error, "CheckSum(10) mismatch"};
         }
      }
      return {};
   }

   // Returns the size of the first complete message in the stream, or 0 if incomplete/malformed.
   inline size_t frame(std::string_view stream, char soh = '\x01')
   {
      if (!stream.starts_with("8=")) return 0;
      const size_t e8 = stream.find(soh);
      if (e8 == std::string_view::npos || stream.substr(e8 + 1, 2) != "9=") return 0;
      const size_t e9 = stream.find(soh, e8 + 3);
      if (e9 == std::string_view::npos) return 0;
      size_t len{};
      if (!detail::parse_uint(stream.substr(e8 + 3, e9 - e8 - 3), len)) return 0;
      const size_t trailer = e9 + 1 + len;
      if (stream.size() < trailer + 7) return 0;
      if (stream.substr(trailer, 3) != "10=" || stream[trailer + 6] != soh) return 0;
      return trailer + 7;
   }

   // ---------------------------------------------------------------------------------------------
   // Struct codec (stub)
   namespace detail
   {
      template <class T>
      struct is_optional : std::false_type
      {};
      template <class T>
      struct is_optional<std::optional<T>> : std::true_type
      {};
      template <class T>
      struct is_vector : std::false_type
      {};
      template <class T, class A>
      struct is_vector<std::vector<T, A>> : std::true_type
      {};

      template <class E>
      concept fix_enum = std::is_enum_v<E> && requires { glz::meta<E>::fix_values; };

      constexpr uint32_t key_tag(std::string_view k)
      {
         uint32_t t = 0;
         for (char c : k) t = t * 10 + uint32_t(c - '0');
         return t;
      }

      template <class T>
      constexpr auto tags_of()
      {
         constexpr auto N = reflect<T>::size;
         std::array<uint32_t, N> a{};
         for (size_t i = 0; i < N; ++i) a[i] = key_tag(reflect<T>::keys[i]);
         return a;
      }

      template <class T>
      inline constexpr auto tags_v = tags_of<T>();

      template <class T>
      constexpr size_t tag_index(uint32_t tag)
      {
         for (size_t i = 0; i < tags_v<T>.size(); ++i)
            if (tags_v<T>[i] == tag) return i;
         return size_t(-1);
      }

      template <class V>
      void write_value(const V& v, std::string& out)
      {
         if constexpr (std::same_as<V, std::string>) {
            out.append(v);
         }
         else if constexpr (std::same_as<V, bool>) {
            out.push_back(v ? 'Y' : 'N');
         }
         else if constexpr (std::same_as<V, char>) {
            out.push_back(v);
         }
         else if constexpr (fix_enum<V>) {
            using U = std::underlying_type_t<V>;
            if constexpr (std::same_as<U, char>) {
               out.push_back(char(v));
            }
            else if constexpr (std::same_as<U, int32_t>) {
               write_value(int64_t(v), out);
            }
            else {
               out.append(glz::meta<V>::fix_values[size_t(v)]);
            }
         }
         else if constexpr (std::is_floating_point_v<V>) {
            // FIX float fields are plain decimal: no exponent. Shortest round-trip fixed form.
            char buf[400];
            auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), v, std::chars_format::fixed);
            out.append(buf, size_t(p - buf));
         }
         else if constexpr (std::is_arithmetic_v<V>) {
            char buf[32];
            auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), v);
            out.append(buf, size_t(p - buf));
         }
         else {
            static_assert(sizeof(V) == 0, "unsupported FIX member type");
         }
      }

      template <class V>
      bool read_value(V& v, std::string_view s)
      {
         if constexpr (std::same_as<V, std::string>) {
            v.assign(s);
            return true;
         }
         else if constexpr (std::same_as<V, bool>) {
            if (s == "Y") v = true;
            else if (s == "N") v = false;
            else return false;
            return true;
         }
         else if constexpr (std::same_as<V, char>) {
            if (s.size() != 1) return false;
            v = s[0];
            return true;
         }
         else if constexpr (fix_enum<V>) {
            constexpr auto& vals = glz::meta<V>::fix_values;
            for (size_t i = 0; i < vals.size(); ++i) {
               if (vals[i] == s) {
                  using U = std::underlying_type_t<V>;
                  if constexpr (std::same_as<U, char>) v = V(s[0]);
                  else if constexpr (std::same_as<U, int32_t>) {
                     int32_t x{};
                     std::from_chars(s.data(), s.data() + s.size(), x);
                     v = V(x);
                  }
                  else v = V(U(i));
                  return true;
               }
            }
            return false;
         }
         else if constexpr (std::is_arithmetic_v<V>) {
            if (s.empty()) return false;
            auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), v);
            return ec == std::errc{} && p == s.data() + s.size();
         }
         else {
            static_assert(sizeof(V) == 0, "unsupported FIX member type");
         }
      }

      template <class T>
      void write_body(const T& obj, std::string& out, char soh)
      {
         for_each<reflect<T>::size>([&]<size_t I>() {
            const auto& m = get_member(obj, get<I>(reflect<T>::values));
            using M = std::remove_cvref_t<decltype(m)>;
            constexpr auto key = reflect<T>::keys[I];
            auto put_key = [&] {
               out.append(key);
               out.push_back('=');
            };
            if constexpr (is_vector<M>::value) {
               if (!m.empty()) {
                  put_key();
                  write_value(int64_t(m.size()), out);
                  out.push_back(soh);
                  for (const auto& e : m) write_body(e, out, soh);
               }
            }
            else if constexpr (is_optional<M>::value) {
               if (m) {
                  put_key();
                  write_value(*m, out);
                  out.push_back(soh);
               }
            }
            else {
               put_key();
               write_value(m, out);
               out.push_back(soh);
            }
         });
      }

      // Reads fields of T starting at pos. In a group (top_level == false) reading stops at the
      // first tag that T does not own or that repeats (which starts the next group instance).
      template <class T>
      error_ctx read_body(T& obj, const std::vector<field>& f, size_t& pos, bool top_level)
      {
         constexpr auto N = reflect<T>::size;
         std::array<bool, N> seen{};
         while (pos < f.size()) {
            const size_t idx = tag_index<T>(f[pos].tag);
            if (idx == size_t(-1)) {
               if (!top_level) return {};
               ++pos; // unknown tag at message level: ignored
               continue;
            }
            if (seen[idx]) {
               if (!top_level) return {};
               return {pos, error_code::syntax_error, "duplicate FIX tag"};
            }
            seen[idx] = true;
            error_ctx err{};
            visit<N>(
               [&]<size_t I>() {
                  auto& m = get_member(obj, get<I>(reflect<T>::values));
                  using M = std::remove_cvref_t<decltype(m)>;
                  const auto value = f[pos].value;
                  ++pos;
                  if constexpr (is_vector<M>::value) {
                     size_t n{};
                     if (!parse_uint(value, n)) {
                        err = {pos - 1, error_code::parse_number_failure, "bad NumInGroup"};
                        return;
                     }
                     m.clear();
                     m.resize(n);
                     for (size_t k = 0; k < n; ++k) {
                        const size_t before = pos;
                        err = read_body(m[k], f, pos, false);
                        if (err) return;
                        if (pos == before) {
                           err = {pos, error_code::syntax_error, "repeating group shorter than NumInGroup"};
                           return;
                        }
                     }
                  }
                  else if constexpr (is_optional<M>::value) {
                     m.emplace();
                     if (!read_value(*m, value)) err = {pos - 1, error_code::syntax_error, "bad FIX value"};
                  }
                  else {
                     if (!read_value(m, value)) err = {pos - 1, error_code::syntax_error, "bad FIX value"};
                  }
               },
               idx);
            if (err) return err;
         }
         return {};
      }

      template <class T>
      constexpr std::string_view begin_string_of()
      {
         if constexpr (requires { glz::meta<T>::fix_begin_string; }) return glz::meta<T>::fix_begin_string;
         else return "FIX.4.4";
      }
   }

   template <auto Opts = fix_opts{}, class T>
   error_ctx write_message(const T& obj, std::string& out)
   {
      constexpr char soh = Opts.soh;
      std::string body;
      body.append("35=");
      body.append(glz::meta<T>::fix_msg_type);
      body.push_back(soh);
      detail::write_body(obj, body, soh);
      out.clear();
      out.append("8=");
      out.append(detail::begin_string_of<T>());
      out.push_back(soh);
      out.append("9=");
      detail::write_value(int64_t(body.size()), out);
      out.push_back(soh);
      out.append(body);
      const uint8_t cs = checksum(out);
      out.append("10=");
      out.push_back(char('0' + cs / 100));
      out.push_back(char('0' + (cs / 10) % 10));
      out.push_back(char('0' + cs % 10));
      out.push_back(soh);
      return {out.size(), error_code::none, {}};
   }

   template <auto Opts = fix_opts{}, class T>
   error_ctx read_message(T& obj, std::string_view msg)
   {
      constexpr char soh = Opts.soh;
      if (auto e = validate(msg, soh, Opts.validate_body_length, Opts.validate_checksum)) return e;
      auto fields = parse_fields(msg, soh);
      if (!fields) return fields.error();
      if ((*fields)[2].value != glz::meta<T>::fix_msg_type) {
         return {0, error_code::syntax_error, "MsgType(35) does not match the target type"};
      }
      size_t pos = 3;
      fields->pop_back(); // drop 10
      return detail::read_body(obj, *fields, pos, true);
   }
}

namespace glz
{
   // Contract entry points: glz::read<glz::fix_opts{}>(obj, msg) / glz::write<glz::fix_opts{}>(obj, buf).
   // glaze's own read/write overloads require from<FIX, T>/to<FIX, T>, which this stub does not
   // define, so these are the only viable overloads for Opts.format == FIX.
   template <auto Opts, class T>
      requires(Opts.format == FIX && requires { glz::meta<std::remove_cvref_t<T>>::fix_msg_type; })
   [[nodiscard]] error_ctx read(T& value, std::string_view msg)
   {
      return fix::read_message<Opts>(value, msg);
   }

   template <auto Opts, class T>
      requires(Opts.format == FIX && requires { glz::meta<std::remove_cvref_t<T>>::fix_msg_type; })
   [[nodiscard]] error_ctx write(const T& value, std::string& buffer)
   {
      return fix::write_message<Opts>(value, buffer);
   }
}
