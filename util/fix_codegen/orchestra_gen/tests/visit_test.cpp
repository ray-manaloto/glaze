// The codec contract without reflection (CONTRACT.md): fix_fields + fix_visit, on all three compilers.
#include "fix44.hpp"
#include <cstdio>
#include <type_traits>

using namespace fix44;
using C = glz::fix3::count_unknown;

// Blocker #1 (Goldfish): a field marked Reserved4000Plus must hold 4000, with max() still free as "absent".
static_assert(std::is_same_v<std::underlying_type_t<PosMaintResult>, std::uint32_t>);
static_assert(static_cast<std::uint32_t>(PosMaintResult{4000}) == 4000);
static_assert(std::is_same_v<std::underlying_type_t<PartyRole>, std::uint8_t>);  // no union: stays narrow
static_assert(begin_string == "FIX.4.4" && dictionary_version == "FIX.4.4");
static_assert(tag::ClOrdID == 11 && tag::PosMaintResult == 723);

template <class T> struct is_bit_ref : std::false_type {};
template <class G, class S> struct is_bit_ref<glz::fix3::bit_ref<G, S>> : std::true_type {};

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
static_assert(contract_holds<NewOrderSingle<C>>());
static_assert(contract_holds<ExecutionReport<C>>());
static_assert(contract_holds<StandardHeader<C>>());
static_assert(contract_holds<Parties>());

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
  NewOrderSingle<C> o{};
  bool ok = set_by_tag(o, 11, std::string_view{"ORD1"}) && set_by_tag(o, 54, Side::sell);
  ok = ok && o.cl_ord_id == "ORD1" && o.side == Side::sell;
  std::size_t bit_fields = 0, data_fields = 0, groups = 0;
  ExecutionReport<C> er{};
  er.fix_visit([&](const glz::fix3::field_info& f, auto&& m) {
    if constexpr (is_bit_ref<std::remove_cvref_t<decltype(m)>>::value) { m.set(true); ok = ok && m.get(); ++bit_fields; }
    if (f.length_tag) ++data_fields;
    if (f.group) ++groups;
  });
  // TradeCaptureReport has a required Boolean (PreviouslyReported, 570): a 1-bit bit-field, reached via bit_ref
  TradeCaptureReport<C> tcr{};
  ok = ok && set_by_tag(tcr, 570, true) && tcr.previously_reported;
  tcr.fix_visit([&](const glz::fix3::field_info&, auto&& m) {
    if constexpr (is_bit_ref<std::remove_cvref_t<decltype(m)>>::value) ++bit_fields;
  });
  // A const message with a bit-field: a read-only visit compiles (bit_ref::set is glz::fix3::read_only).
  const TradeCaptureReport<C>& ctcr = tcr;
  bool read_back = false;
  ctcr.fix_visit([&](const glz::fix3::field_info& f, auto&& m) {
    if constexpr (is_bit_ref<std::remove_cvref_t<decltype(m)>>::value) { if (f.tag == 570) read_back = m.get(); }
  });
  ok = ok && read_back;
  std::printf("visit: NewOrderSingle %zu fields; ExecutionReport %zu fields, %zu groups, %zu bit-field(s) set via bit_ref (TradeCaptureReport.previously_reported), %zu data fields with a length tag; %s\n",
              NewOrderSingle<C>::fix_fields.size(), ExecutionReport<C>::fix_fields.size(), groups, bit_fields, data_fields, ok ? "ok" : "FAILED");
  return ok ? 0 : 1;
}
