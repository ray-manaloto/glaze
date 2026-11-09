// Spike support types for headers written by orchestra_gen (glaze-fix 3-part model, rules L1-L6).
// Compiles on GCC 16.2, clang-p2996 and upstream Clang 23 (no reflection needed by this header).
#pragma once

#include <array>
#include <chrono>
#include <cstdint>
#include <limits>
#include <span>
#include <string_view>
#include <type_traits>

#include <boost/decimal.hpp>
#include <stdx/optional.hpp>

namespace glz::fix3 {

// L3: one 8-byte time point, always nanoseconds.
using timestamp = std::chrono::sys_time<std::chrono::nanoseconds>;
static_assert(sizeof(timestamp) == 8);

enum class yes_no : char { no = 'N', yes = 'Y' };  // an optional Boolean (a required one is a 1-bit bit-field)

struct tag { std::uint16_t value; };                     // annotation: [[=glz::fix3::tag{49}]]
struct field { std::uint16_t tag; std::string_view value; };
struct field_info {
  std::uint16_t tag;          // FIX tag (the NumInGroup tag for a group)
  std::uint16_t member;       // index in declaration order (fix_visit / reflection)
  std::string_view name;      // C++ member name
  std::string_view fix_name;  // Orchestra name: ClOrdID, Parties
  bool required;
  bool group;
  std::uint16_t length_tag;   // data field: its Length tag, else 0
  std::uint16_t max_entries;  // group: implMaxOccurs, 0 = unbounded
  bool deprecated;
  bool open_enum;             // int enum that also accepts values beyond its codes
};

// fix_visit's stand-in for a bit-field member (it has no address).
template <class Get, class Set> struct bit_ref {
  Get get;
  Set set;
};
template <class G, class S> bit_ref(G, S) -> bit_ref<G, S>;
struct read_only {};  // bit_ref::set when fix_visit runs on a const message: calling it does not compile

// L1: the unknown-tag policy. Each message is one template over it.
struct keep_unknown { using member_type = std::span<const field>; };  // rule A, wire order
struct count_unknown { using member_type = std::uint16_t; };          // how many were skipped
template <class U> concept unknown_policy = requires { typename U::member_type; };
template <class U> using unknown_t = typename U::member_type;

// L4: integers use max() as "absent" (stdx forbids tombstone_traits for plain integral types).
template <class I> using opt_int = stdx::optional<I, stdx::tombstone_value<std::numeric_limits<I>::max()>>;
using opt_char = stdx::optional<char, stdx::tombstone_value<'\0'>>;  // a plain char: '\0' is never a FIX value

template <class H, class B, class T> struct message { H header; B body; T trailer; };

}  // namespace glz::fix3

// L4: "absent" tombstones for the other member types.
template <> struct stdx::tombstone_traits<std::string_view> {
  constexpr auto operator()() const { return std::string_view{}; }  // FIX forbids empty values
};
template <> struct stdx::tombstone_traits<glz::fix3::timestamp> {
  constexpr auto operator()() const { return glz::fix3::timestamp::min(); }
};
template <> struct stdx::tombstone_traits<boost::decimal::decimal64_t> {
  constexpr auto operator()() const { return std::numeric_limits<boost::decimal::decimal64_t>::infinity(); }
};
template <class E> struct stdx::tombstone_traits<E, std::enable_if_t<std::is_enum_v<E>>> {
  constexpr auto operator()() const {  // char enums: '\0' (never a FIX value); int enums: max() (kept free by L5)
    using T = std::underlying_type_t<E>;
    if constexpr (std::is_same_v<T, char>) return E{};
    else return static_cast<E>(std::numeric_limits<T>::max());
  }
};

// D4: orchestra_gen writes [[=glz::fix3::tag{N}]] directly for compilers with C++26 annotations
// (--target gcc16, --target p2996). Only a header generated for a compiler without them
// (--target clang23) uses this macro, and there it expands to nothing: tags come from fix_fields.
#ifndef GLZ_FIX3_TAG
#define GLZ_FIX3_TAG(N)
#endif
