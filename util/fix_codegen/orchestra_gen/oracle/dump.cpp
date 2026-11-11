// Prints what the generated header actually contains, for the oracle to compare with the XML:
//   PART <struct> <msgtype or -> ; F <tag> <required> <group> <member> ; T <member> <type> ; G <member> <entry struct>
// GCC 16.2 (reflection is used only to read the generated structs, not to build them).
#include "fix44.hpp"
#include <cstdio>
#include <meta>
#include <set>
#include <string>

template <class T> struct is_span : std::false_type { using elem = void; };
template <class E> struct is_span<std::span<E>> : std::true_type { using elem = std::remove_const_t<E>; };

inline std::set<std::string> done;

template <class T> void dump() {
  constexpr auto name = std::meta::display_string_of(^^T);
  if (!done.insert(std::string(name)).second) return;
  if constexpr (requires { T::fix_msg_type; }) std::printf("PART %.*s %.*s\n", int(name.size()), name.data(), int(T::fix_msg_type.size()), T::fix_msg_type.data());
  else std::printf("PART %.*s -\n", int(name.size()), name.data());
  for (const auto& f : T::fix_fields)
    std::printf("F %u %d %d %.*s\n", unsigned(f.tag), int(f.required), int(f.group), int(f.name.size()), f.name.data());
  template for (constexpr auto m : std::define_static_array(std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::unchecked()))) {
    constexpr auto mn = std::meta::identifier_of(m);
    constexpr auto tn = std::meta::display_string_of(std::meta::type_of(m));
    std::printf("T %.*s %.*s%s\n", int(mn.size()), mn.data(), int(tn.size()), tn.data(), std::meta::is_bit_field(m) ? " :bit" : "");
    using MT = typename[:std::meta::type_of(m):];
    if constexpr (is_span<MT>::value) {
      using E = typename is_span<MT>::elem;
      constexpr auto en = std::meta::display_string_of(^^E);
      std::printf("G %.*s %.*s\n", int(mn.size()), mn.data(), int(en.size()), en.data());
    }
  }
  // entries after the parent's own lines, so every PART block is contiguous
  template for (constexpr auto m : std::define_static_array(std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::unchecked()))) {
    using MT = typename[:std::meta::type_of(m):];
    if constexpr (is_span<MT>::value) dump<typename is_span<MT>::elem>();
  }
}

int main() {
  dump<fix44::StandardHeader>();
  dump<fix44::StandardTrailer>();
  dump<fix44::Logon>();
  dump<fix44::Heartbeat>();
  dump<fix44::NewOrderSingle>();
  dump<fix44::ExecutionReport>();
  dump<fix44::OrderCancelRequest>();
  dump<fix44::OrderCancelReplaceRequest>();
  dump<fix44::MarketDataSnapshotFullRefresh>();
  // enum underlying types, for the width check
#define E(X) std::printf("ENUM %s %zu\n", #X, sizeof(std::underlying_type_t<fix44::X>));
  E(PosMaintResult) E(PartyRole) E(Side) E(OrdType) E(TargetStrategy) E(PartySubIDType)
}
