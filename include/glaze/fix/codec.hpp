// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

// glz::from<FIX, T> / glz::to<FIX, T> for structs mapped with glz::meta / glz::object whose keys are
// FIX tag numbers written as strings ("11", "55", ...).
//
// Member types: integers, floating point (written shortest round-trip, read as decimal text), char,
// bool (Y/N), std::string, std::string_view (read as a view into the input), std::optional of these
// (absent -> not written / left empty), and std::vector<Group> for repeating groups where the key is
// the NoXXX count tag and the group's first member is its delimiter tag. Groups nest.

#include <array>
#include <charconv>
#include <cstdlib>
#include <cstring>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

#include "glaze/core/buffer_traits.hpp"
#include "glaze/core/common.hpp"
#include "glaze/core/opts.hpp"
#include "glaze/core/read.hpp"
#include "glaze/core/reflect.hpp"
#include "glaze/core/write.hpp"
#include "glaze/fix/opts.hpp"
#include "glaze/fix/scan.hpp"
#include "glaze/util/for_each.hpp"

namespace glz::fix::detail
{
   template <class T>
   struct is_std_vector : std::false_type
   {};
   template <class T, class A>
   struct is_std_vector<std::vector<T, A>> : std::true_type
   {};

   template <class T>
   struct is_std_optional : std::false_type
   {};
   template <class T>
   struct is_std_optional<std::optional<T>> : std::true_type
   {};

   template <class T>
   concept fix_struct = glaze_object_t<T>;

   template <class T>
   concept group_t = is_std_vector<std::remove_cvref_t<T>>::value && fix_struct<typename std::remove_cvref_t<T>::value_type>;

   template <class T>
   constexpr uint32_t tag_at(size_t I)
   {
      uint32_t out{};
      const std::string_view key = [&] {
         std::string_view k{};
         for_each<reflect<T>::size>([&]<size_t J>() {
            if (J == I) k = glz::get<J>(reflect<T>::keys);
         });
         return k;
      }();
      if (!parse_uint(key, out)) {
         // A FIX mapping key must be a decimal tag number; calling abort in a constant expression makes the mistake a compile error.
         std::abort();
      }
      return out;
   }

   template <class T>
   inline constexpr auto tags = [] {
      std::array<uint32_t, reflect<T>::size> a{};
      for (size_t i = 0; i < a.size(); ++i) {
         a[i] = tag_at<T>(i);
      }
      return a;
   }();

   template <class T>
   constexpr int member_index(uint32_t tag) noexcept
   {
      for (size_t i = 0; i < tags<T>.size(); ++i) {
         if (tags<T>[i] == tag) return int(i);
      }
      return -1;
   }

   // True when `tag` is the length field of a raw-data field that T maps.
   template <class T>
   constexpr bool is_raw_length_of_mapped(uint32_t tag) noexcept
   {
      const uint32_t data_tag = raw_data_tag_for(tag);
      return data_tag != 0 && member_index<T>(data_tag) >= 0;
   }

   constexpr bool is_session_envelope_tag(uint32_t tag) noexcept
   {
      return tag == 8 || tag == 9 || tag == 35 || tag == 10;
   }

   // ---- scalar decoding -------------------------------------------------------------------

   template <class V>
   bool decode_scalar(V& v, std::string_view s, context& ctx)
   {
      using T = std::remove_cvref_t<V>;
      if constexpr (is_std_optional<T>::value) {
         auto& x = v.emplace();
         return decode_scalar(x, s, ctx);
      }
      else if constexpr (std::same_as<T, bool>) {
         if (s == "Y") v = true;
         else if (s == "N") v = false;
         else {
            ctx.error = error_code::expected_true_or_false;
            ctx.custom_error_message = "fix: Boolean must be Y or N";
            return false;
         }
         return true;
      }
      else if constexpr (std::same_as<T, char>) {
         if (s.size() != 1) {
            ctx.error = error_code::syntax_error;
            ctx.custom_error_message = "fix: char field must be one character";
            return false;
         }
         v = s[0];
         return true;
      }
      else if constexpr (std::same_as<T, std::string>) {
         v.assign(s.data(), s.size());
         return true;
      }
      else if constexpr (std::same_as<T, std::string_view>) {
         v = s;
         return true;
      }
      else if constexpr (std::is_enum_v<T>) {
         std::underlying_type_t<T> u{};
         if (!decode_scalar(u, s, ctx)) return false;
         v = T(u);
         return true;
      }
      else if constexpr (std::is_arithmetic_v<T>) {
         const char* first = s.data();
         const char* last = s.data() + s.size();
         if constexpr (std::is_unsigned_v<T>) {
            if (*first == '-') {
               ctx.error = error_code::parse_number_failure;
               ctx.custom_error_message = "fix: negative value for unsigned field";
               return false;
            }
         }
         if constexpr (std::is_floating_point_v<T>) {
            if (*first == '+') {
               ctx.error = error_code::parse_number_failure;
               return false;
            }
         }
         auto [p, ec] = std::from_chars(first, last, v);
         if (ec != std::errc{} || p != last) {
            ctx.error = error_code::parse_number_failure;
            ctx.custom_error_message = "fix: invalid number";
            return false;
         }
         return true;
      }
      else {
         static_assert(sizeof(T) == 0, "glz::fix: unsupported member type");
         return false;
      }
   }

   // ---- struct decoding -------------------------------------------------------------------

   template <auto Opts, class T>
   void decode_struct(T& value, const std::vector<field>& fields, size_t& idx, context& ctx, bool top);

   template <auto Opts, class V>
   void decode_group(V& vec, const std::vector<field>& fields, size_t& idx, context& ctx)
   {
      using G = typename std::remove_cvref_t<V>::value_type;
      size_t count{};
      if (!parse_size(fields[idx].value, count)) {
         ctx.error = error_code::parse_number_failure;
         ctx.custom_error_message = "fix: invalid repeating group count";
         return;
      }
      ++idx;
      if (count > fields.size() - idx) {
         ctx.error = error_code::syntax_error;
         ctx.custom_error_message = "fix: repeating group count exceeds the remaining fields";
         return;
      }
      vec.clear();
      vec.resize(count);
      for (size_t k = 0; k < count; ++k) {
         if (idx >= fields.size() || fields[idx].tag != tags<G>[0]) {
            ctx.error = error_code::syntax_error;
            ctx.custom_error_message = "fix: repeating group count does not match its entries";
            return;
         }
         decode_struct<Opts>(vec[k], fields, idx, ctx, false);
         if (bool(ctx.error)) return;
      }
   }

   template <auto Opts, class T>
   void decode_struct(T& value, const std::vector<field>& fields, size_t& idx, context& ctx, bool top)
   {
      bool first_seen = false;
      while (idx < fields.size()) {
         const auto& f = fields[idx];
         const int m = member_index<T>(f.tag);
         if (m < 0 && is_raw_length_of_mapped<T>(f.tag)) {
            ++idx; // the scanner already used it to size the data field
            continue;
         }
         if (m < 0) {
            if (!top) return; // an unknown tag ends the group entry
            if (is_session_envelope_tag(f.tag) || !Opts.error_on_unknown_tags) {
               ++idx;
               continue;
            }
            ctx.error = error_code::unknown_key;
            ctx.custom_error_message = "fix: unknown tag";
            return;
         }
         if (!top) {
            if (m == 0) {
               if (first_seen) return; // delimiter again: next entry starts
               first_seen = true;
            }
         }
         bool handled = false;
         for_each<reflect<T>::size>([&]<size_t I>() {
            if (handled || int(I) != m) return;
            handled = true;
            auto& member = get_member(value, glz::get<I>(reflect<T>::values));
            using M = std::remove_cvref_t<decltype(member)>;
            if constexpr (group_t<M>) {
               decode_group<Opts>(member, fields, idx, ctx);
            }
            else {
               if (decode_scalar(member, f.value, ctx)) ++idx;
            }
         });
         if (bool(ctx.error)) return;
      }
   }

   // ---- encoding --------------------------------------------------------------------------

   template <auto Opts>
   void put_tag(std::string& out, uint32_t tag)
   {
      char buf[16];
      auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), tag);
      (void)ec;
      out.append(buf, p);
      out.push_back('=');
   }

   template <class V>
   bool encode_scalar(std::string& out, const V& v)
   {
      using T = std::remove_cvref_t<V>;
      if constexpr (std::same_as<T, bool>) {
         out.push_back(v ? 'Y' : 'N');
      }
      else if constexpr (std::same_as<T, char>) {
         out.push_back(v);
      }
      else if constexpr (std::same_as<T, std::string> || std::same_as<T, std::string_view>) {
         out.append(v.data(), v.size());
      }
      else if constexpr (std::is_enum_v<T>) {
         return encode_scalar(out, std::underlying_type_t<T>(v));
      }
      else if constexpr (std::is_arithmetic_v<T>) {
         char buf[64];
         auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), v);
         if (ec != std::errc{}) return false;
         out.append(buf, p);
      }
      else {
         static_assert(sizeof(T) == 0, "glz::fix: unsupported member type");
      }
      return true;
   }

   template <class T>
   bool value_is_empty(const T& v)
   {
      if constexpr (std::same_as<T, std::string> || std::same_as<T, std::string_view>) return v.empty();
      else return false;
   }

   // Encodes one value plus its delimiter. A value may not contain the delimiter (or be an empty char).
   template <auto Opts, class V>
   void encode_checked(std::string& out, const V& v, context& ctx)
   {
      const size_t start = out.size();
      if (!encode_scalar(out, v)) {
         ctx.error = error_code::dump_int_error;
         return;
      }
      if (std::string_view{out}.substr(start).find(Opts.soh) != std::string_view::npos) {
         ctx.error = error_code::syntax_error;
         ctx.custom_error_message = "fix: value contains the field delimiter";
         return;
      }
      out.push_back(Opts.soh);
   }

   // Writes "tag=value<soh>". A raw-data field (e.g. 96) gets its length field (e.g. 95) written in
   // front of it from the value's byte count, and may contain the delimiter.
   template <auto Opts, uint32_t Tag, class V>
   void encode_field(std::string& out, const V& v, context& ctx)
   {
      if constexpr (raw_length_tag_for(Tag) != 0) {
         using T = std::remove_cvref_t<V>;
         static_assert(std::same_as<T, std::string> || std::same_as<T, std::string_view>,
                       "glz::fix: a raw-data field must be std::string or std::string_view");
         put_tag<Opts>(out, raw_length_tag_for(Tag));
         encode_scalar(out, v.size());
         out.push_back(Opts.soh);
         put_tag<Opts>(out, Tag);
         out.append(v.data(), v.size());
         out.push_back(Opts.soh);
         (void)ctx;
      }
      else {
         put_tag<Opts>(out, Tag);
         encode_checked<Opts>(out, v, ctx);
      }
   }

   template <auto Opts, class T>
   void encode_struct(std::string& out, const T& value, context& ctx)
   {
      for_each<reflect<T>::size>([&]<size_t I>() {
         if (bool(ctx.error)) return;
         static constexpr uint32_t tag = tags<T>[I];
         const auto& member = get_member(value, glz::get<I>(reflect<T>::values));
         using M = std::remove_cvref_t<decltype(member)>;
         if constexpr (is_raw_length_of_mapped<T>(tag)) {
            return; // written automatically in front of its data field
         }
         else if constexpr (group_t<M>) {
            if (member.empty()) return;
            put_tag<Opts>(out, tag);
            encode_scalar(out, member.size());
            out.push_back(Opts.soh);
            for (const auto& entry : member) {
               encode_struct<Opts>(out, entry, ctx);
               if (bool(ctx.error)) return;
            }
         }
         else if constexpr (is_std_optional<M>::value) {
            if (!member || value_is_empty(*member)) return;
            encode_field<Opts, tag>(out, *member, ctx);
         }
         else {
            // FIX forbids empty values, so an empty string is treated as "not present"
            if (value_is_empty(member)) return;
            encode_field<Opts, tag>(out, member, ctx);
         }
      });
   }

   template <class T>
   constexpr std::string_view begin_string_of()
   {
      if constexpr (requires { meta<T>::fix_begin_string; }) return meta<T>::fix_begin_string;
      else return "FIX.4.4";
   }

   template <class T>
   constexpr bool has_msg_type = requires { meta<T>::fix_msg_type; };
}

namespace glz
{
   template <>
   struct parse<FIX>
   {
      template <auto Opts, class T, is_context Ctx, class It0, class It1>
      static void op(T&& value, Ctx&& ctx, It0&& it, It1 end)
      {
         from<FIX, std::remove_cvref_t<T>>::template op<Opts>(value, ctx, it, end);
      }
   };

   template <>
   struct serialize<FIX>
   {
      template <auto Opts, class T, is_context Ctx, class B, class IX>
      static void op(T&& value, Ctx&& ctx, B&& b, IX&& ix)
      {
         to<FIX, std::remove_cvref_t<T>>::template op<Opts>(value, ctx, b, ix);
      }
   };

   template <fix::detail::fix_struct T>
   struct from<FIX, T>
   {
      template <auto Opts>
      static void op(T& value, is_context auto&& ctx, auto&& it, auto end)
      {
         const std::string_view msg{it, size_t(end - it)};
         auto fields = fix::parse_fields(msg, Opts.soh);
         if (!fields) {
            ctx.error = fields.error().ec;
            ctx.custom_error_message = fields.error().custom_error_message;
            it += fields.error().count;
            return;
         }
         auto& fs = *fields;
         if (fs.front().tag == 8) {
            // a complete message: check the envelope
            const auto e = fix::validate(msg, Opts.soh, Opts.validate_body_length, Opts.validate_checksum);
            if (e) {
               ctx.error = e.ec;
               ctx.custom_error_message = e.custom_error_message;
               it += e.count;
               return;
            }
            if constexpr (fix::detail::has_msg_type<T>) {
               if (Opts.validate_msg_type && fs[2].value != std::string_view{meta<T>::fix_msg_type}) {
                  ctx.error = error_code::invalid_header;
                  ctx.custom_error_message = "fix: MsgType (35) does not match the target type";
                  return;
               }
            }
         }
         context c{};
         size_t idx = 0;
         fix::detail::decode_struct<Opts>(value, fs, idx, c, true);
         if (bool(c.error)) {
            ctx.error = c.error;
            ctx.custom_error_message = c.custom_error_message;
            return;
         }
         it = end;
      }
   };

   template <fix::detail::fix_struct T>
   struct to<FIX, T>
   {
      template <auto Opts, class B>
      static void op(const T& value, is_context auto&& ctx, B&& b, auto& ix)
      {
         static_assert(fix::detail::has_msg_type<T>,
                       "glz::write<fix_opts>: the top-level type needs glz::meta<T>::fix_msg_type (tag 35)");
         std::string body;
         body.reserve(256);
         body += "35=";
         body += std::string_view{meta<T>::fix_msg_type};
         body.push_back(Opts.soh);
         context c{};
         fix::detail::encode_struct<Opts>(body, value, c);
         if (bool(c.error)) {
            ctx.error = c.error;
            ctx.custom_error_message = c.custom_error_message;
            return;
         }
         std::string msg;
         msg.reserve(body.size() + 40);
         msg += "8=";
         msg += fix::detail::begin_string_of<T>();
         msg.push_back(Opts.soh);
         msg += "9=";
         fix::detail::encode_scalar(msg, body.size());
         msg.push_back(Opts.soh);
         msg += body;
         const uint8_t cs = fix::checksum(msg);
         msg += "10=";
         msg.push_back(char('0' + cs / 100));
         msg.push_back(char('0' + (cs / 10) % 10));
         msg.push_back(char('0' + cs % 10));
         msg.push_back(Opts.soh);

         if (!ensure_space(ctx, b, ix + msg.size() + write_padding_bytes)) [[unlikely]] {
            return;
         }
         std::memcpy(&b[ix], msg.data(), msg.size());
         ix += msg.size();
      }
   };
}
