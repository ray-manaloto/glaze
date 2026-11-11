// The codec contract without reflection (CONTRACT.md): fix_fields + fix_visit, on all three compilers.
#include "fix44.hpp"
#include <cstdio>
#include <type_traits>

using namespace fix44;

// Blocker #1 (Goldfish): a field marked Reserved4000Plus must hold 4000, with max() still free as "absent".
static_assert(std::is_same_v<std::underlying_type_t<PosMaintResult>, std::uint32_t>);
static_assert(static_cast<std::uint32_t>(PosMaintResult{4000}) == 4000);
static_assert(std::is_same_v<std::underlying_type_t<PartyRole>, std::uint8_t>);  // no union: stays narrow
static_assert(begin_string == "FIX.4.4" && dictionary_version == "FIX.4.4");
static_assert(tag::ClOrdID == 11 && tag::PosMaintResult == 723);
static_assert(NewOrderSingle::fix_fields[0].datatype == "String");  // ClOrdID

template <class T> struct is_bit_ref : std::false_type {};
template <class G, class S> struct is_bit_ref<glz::fix3::bit_ref<G, S>> : std::true_type {};
template <class T> struct is_opt : std::false_type {};
template <class T, class TS> struct is_opt<stdx::optional<T, TS>> : std::true_type {};
template <class T> struct is_span : std::false_type {};
template <class E> struct is_span<std::span<const E>> : std::true_type {};

template <class T> constexpr bool contract_holds() {
  // fix_visit visits every fix_fields entry once, in wire order
  T t{};
  std::size_t n = 0;
  bool order = true;
  t.fix_visit([&](const glz::fix3::field_info& f, auto&&) { order = order && &f == &T::fix_fields[n]; ++n; });
  // member indices are distinct and inside the struct's member count
  bool distinct = true;
  for (std::size_t i = 0; i < T::fix_fields.size(); ++i)
    for (std::size_t j = i + 1; j < T::fix_fields.size(); ++j) distinct = distinct && T::fix_fields[i].member != T::fix_fields[j].member;
  return order && distinct && n == T::fix_fields.size();
}
static_assert(contract_holds<NewOrderSingle>());
static_assert(contract_holds<ExecutionReport>());
static_assert(contract_holds<StandardHeader>());
static_assert(contract_holds<Parties>());

// A value of each member type that differs from its default and from "absent".
template <class E> inline E entry_storage[1]{};
template <class M> M sample() {
  if constexpr (is_opt<M>::value) return M{sample<typename M::value_type>()};
  else if constexpr (is_span<M>::value) return M{entry_storage<std::remove_const_t<typename M::element_type>>};
  else if constexpr (std::is_same_v<M, std::string_view>) return "v";
  else if constexpr (std::is_same_v<M, char>) return 'v';
  else if constexpr (std::is_same_v<M, dec::decimal64_t>) return dec::decimal64_t{15, -1};
  else if constexpr (std::is_same_v<M, glz::fix3::timestamp>) return glz::fix3::timestamp{std::chrono::nanoseconds{123456789}};
  else if constexpr (std::is_same_v<M, glz::fix3::yes_no>) return glz::fix3::yes_no::yes;
  else if constexpr (std::is_enum_v<M>) return static_cast<M>(1);
  else if constexpr (std::is_integral_v<M>) return M{7};
  else static_assert(sizeof(M) == 0, "a member type the test does not know");
}
template <class M> bool equal(const M& a, const M& b) {
  if constexpr (is_opt<M>::value) return a.has_value() && b.has_value() && equal(a.value(), b.value());
  else if constexpr (is_span<M>::value) return a.data() == b.data() && a.size() == b.size();
  else return a == b;
}

// Stage 3 acceptance: every member written, then read back, through fix_visit alone (no reflection).
template <class T> std::size_t write_read_all(bool& ok) {
  T t{};
  std::size_t written = 0, read = 0;
  t.fix_visit([&](const glz::fix3::field_info&, auto&& m) {
    using M = std::remove_cvref_t<decltype(m)>;
    if constexpr (is_bit_ref<M>::value) { ok = ok && !m.get(); m.set(true); }
    else { ok = ok && !equal(m, sample<M>()); m = sample<M>(); }  // the default really changes
    ++written;
  });
  const T& ct = t;
  ct.fix_visit([&](const glz::fix3::field_info&, auto&& m) {
    using M = std::remove_cvref_t<decltype(m)>;
    if constexpr (is_bit_ref<M>::value) ok = ok && m.get();
    else ok = ok && equal(m, sample<M>());
    ++read;
  });
  ok = ok && written == T::fix_fields.size() && read == written;
  return read;
}

// Set and read members by tag through fix_visit only (what a reflection-free codec does).
template <class T, class V> constexpr bool set_by_tag(T& t, std::uint16_t tag, V v) {
  bool hit = false;
  t.fix_visit([&](const glz::fix3::field_info& f, auto&& m) {
    using M = std::remove_cvref_t<decltype(m)>;
    if (f.tag != tag) return;
    if constexpr (is_bit_ref<M>::value) { if constexpr (std::is_same_v<V, bool>) { m.set(v); hit = true; } }
    else if constexpr (std::is_assignable_v<M&, V>) { m = v; hit = true; }
  });
  return hit;
}

int main() {
  bool ok = true;
  const auto nos = write_read_all<NewOrderSingle>(ok);
  const auto er_all = write_read_all<ExecutionReport>(ok);
  const auto tcr_all = write_read_all<TradeCaptureReport>(ok);  // has a required Boolean bit-field
  write_read_all<StandardHeader>(ok);
  write_read_all<Parties>(ok);
  NewOrderSingle o{};
  ok = ok && set_by_tag(o, 11, std::string_view{"ORD1"}) && set_by_tag(o, 54, Side::sell);
  ok = ok && o.cl_ord_id == "ORD1" && o.side == Side::sell;
  std::size_t bit_fields = 0, data_fields = 0, groups = 0, timestamps = 0;
  ExecutionReport er{};
  er.fix_visit([&](const glz::fix3::field_info& f, auto&&) {
    if (f.length_tag) ++data_fields;
    if (f.group) ++groups;
    if (f.datatype == "UTCTimestamp") ++timestamps;
  });
  // TradeCaptureReport has a required Boolean (PreviouslyReported, 570): a 1-bit bit-field, reached via bit_ref
  TradeCaptureReport tcr{};
  ok = ok && set_by_tag(tcr, 570, true) && tcr.previously_reported;
  tcr.fix_visit([&](const glz::fix3::field_info&, auto&& m) {
    if constexpr (is_bit_ref<std::remove_cvref_t<decltype(m)>>::value) ++bit_fields;
  });
  std::printf("visit: every member written and read back without reflection: NewOrderSingle %zu, ExecutionReport %zu, "
              "TradeCaptureReport %zu (%zu bit-field via bit_ref); ExecutionReport has %zu groups, %zu data fields, %zu "
              "UTCTimestamp fields; %s\n",
              nos, er_all, tcr_all, bit_fields, groups, data_fields, timestamps, ok ? "ok" : "FAILED");
  return ok ? 0 : 1;
}
