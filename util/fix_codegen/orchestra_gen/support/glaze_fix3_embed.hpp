// The #embed path: define the 3-part structs at compile time from an orchestra_gen digest with
// C++26 reflection (define_aggregate). GCC 16.2 and clang-p2996 only.
#pragma once

#include "glaze_fix3_support.hpp"

#include <meta>
#include <string>
#include <string_view>
#include <vector>
#if defined(__cpp_lib_constexpr_exceptions)
#include <stdexcept>
#endif

namespace glz::fix3::embed {

// Aliases, because ^^std::uint64_t names a using-declaration (rejected by both compilers).
using u64 = std::uint64_t; using u32 = std::uint32_t; using u16 = std::uint16_t; using u8 = std::uint8_t;
using i64 = std::int64_t;

void digest_error_is_not_a_constant_expression(const char*);  // never defined

// A malformed digest stops the build. GCC 16.2 has constexpr exceptions (P3068), so its error
// message names the problem; clang-p2996 reports a call to a non-constexpr function instead.
consteval void fail(const std::string& msg) {
#if defined(__cpp_lib_constexpr_exceptions)
  throw std::invalid_argument(msg);
#else
  digest_error_is_not_a_constant_expression(msg.c_str());
#endif
}

consteval std::meta::info find_in(std::meta::info ns, std::string_view name) {
  for (auto m : std::meta::members_of(ns, std::meta::access_context::unchecked()))
    if (std::meta::has_identifier(m) && std::meta::identifier_of(m) == name) return m;
  fail("digest: no declaration named '" + std::string(name) + "' in " + std::string(std::meta::identifier_of(ns)));
  return {};
}

consteval std::meta::info decode_type(std::string_view t, std::meta::info enums_ns, std::meta::info parts_ns) {
  using namespace std::meta;
  if (t.starts_with("?")) {
    const auto inner = decode_type(t.substr(1), enums_ns, parts_ns);
    if (t == "?char") return ^^glz::fix3::opt_char;
    const bool integral = t == "?u64" || t == "?u32" || t == "?u16" || t == "?u8" || t == "?i64";
    return integral ? substitute(^^glz::fix3::opt_int, {inner}) : substitute(^^stdx::optional, {inner});
  }
  if (t == "sv") return ^^std::string_view;
  if (t == "dec64") return ^^boost::decimal::decimal64_t;
  if (t == "ts") return ^^glz::fix3::timestamp;
  if (t == "u64") return ^^u64;
  if (t == "u32") return ^^u32;
  if (t == "u16") return ^^u16;
  if (t == "u8") return ^^u8;
  if (t == "i64") return ^^i64;
  if (t == "char") return ^^char;
  if (t == "bool") return ^^bool;
  if (t == "yn") return ^^glz::fix3::yes_no;
  if (t.starts_with("E:")) return find_in(enums_ns, t.substr(2));
  if (t.starts_with("S:")) return substitute(^^std::span, {add_const(find_in(parts_ns, t.substr(2)))});
  fail("digest: unknown type code '" + std::string(t) + "'");
  return {};
}

struct line_reader {
  std::span<const unsigned char> d;
  std::size_t pos = 0;
  consteval bool done() const { return pos >= d.size(); }
  consteval std::vector<std::string> next() {  // split one line on spaces
    std::vector<std::string> words(1);
    for (; pos < d.size() && d[pos] != '\n'; ++pos)
      if (d[pos] == ' ') words.emplace_back();
      else words.back() += static_cast<char>(d[pos]);
    ++pos;
    return words;
  }
};

consteval int to_int(const std::string& s) {
  int v = 0;
  bool neg = false;
  for (std::size_t i = 0; i < s.size(); ++i) {
    if (i == 0 && s[i] == '-') { neg = true; continue; }
    if (s[i] < '0' || s[i] > '9') fail("digest: '" + s + "' is not a number");
    v = v * 10 + (s[i] - '0');
  }
  return neg ? -v : v;
}

consteval std::string to_str(std::size_t v) {  // std::to_string is not constexpr in libc++ yet
  std::string s;
  do { s.insert(s.begin(), static_cast<char>('0' + v % 10)); v /= 10; } while (v);
  return s;
}

struct part_line { std::string name; std::size_t size, align; std::vector<std::vector<std::string>> members; };

consteval void define_one(std::meta::info target, const part_line& p, std::meta::info enums_ns, std::meta::info parts_ns) {
  using namespace std::meta;
  std::vector<info> specs;
  for (const auto& m : p.members) {
    data_member_options o{.name = m[1]};
    const int bits = to_int(m[4]);
#if defined(__clang__)
    if (bits) o.width = bits;
#else
    if (bits) o.bit_width = bits;
    o.annotations.push_back(reflect_constant(glz::fix3::tag{static_cast<std::uint16_t>(to_int(m[3]))}));
#endif
    specs.push_back(data_member_spec(decode_type(m[2], enums_ns, parts_ns), o));
  }
  define_aggregate(target, specs);
  if (size_of(target) != p.size || alignment_of(target) != p.align)
    fail("digest: " + p.name + " laid out as " + to_str(size_of(target)) + " bytes (align " +
         to_str(alignment_of(target)) + "), digest says " + to_str(p.size) + " (align " + to_str(p.align) + ")");
}

// Define every struct the digest lists, in digest order (group entries come before their users).
// parts_ns holds the declarations, enums_ns the codeSet enums written by orchestra_gen.
template <std::size_t N>
consteval void define_all(std::meta::info parts_ns, std::meta::info enums_ns, const unsigned char (&digest)[N]) {
  line_reader r{std::span<const unsigned char>(digest, N)};
  const auto v = r.next();
  if (v.size() != 3 || v[0] != "V" || v[1] != "2") fail("digest: missing or unknown version line");
  std::vector<part_line> parts;
  while (!r.done()) {
    auto w = r.next();
    if (w.size() == 1 && w[0].empty()) continue;
    if (w[0] == "P" && w.size() == 4)
      parts.push_back({w[1], static_cast<std::size_t>(to_int(w[2])), static_cast<std::size_t>(to_int(w[3])), {}});
    else if (w[0] == "M" && w.size() == 5 && !parts.empty()) parts.back().members.push_back(std::move(w));
    else fail("digest: bad line starting '" + w[0] + "'");
  }
  for (const auto& p : parts) define_one(find_in(parts_ns, p.name), p, enums_ns, parts_ns);
}

}  // namespace glz::fix3::embed
