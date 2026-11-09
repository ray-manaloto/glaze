// Headers path: the generated structs compile and behave on every compiler (no reflection needed).
#include "fix44.hpp"
#include <cstdio>

using namespace fix44;
using K = glz::fix3::keep_unknown;
using C = glz::fix3::count_unknown;

static_assert(sizeof(stdx::optional<Side>) == 1);                         // L4: tombstone, no extra bool
static_assert(sizeof(stdx::optional<std::string_view>) == sizeof(std::string_view));
static_assert(sizeof(glz::fix3::opt_int<std::uint32_t>) == 4);
static_assert(static_cast<char>(Side::sell) == '2');                     // L5: value = wire char
static_assert(std::is_same_v<std::underlying_type_t<PartyRole>, std::uint8_t>);  // largest code < 255
static_assert(NewOrderSingle<K>::fix_msg_type == "D");
static_assert(NewOrderSingle<K>::fix_fields[0].tag == 11);              // tag table in wire order
static_assert(std::is_aggregate_v<NewOrderSingle<C>>);
static_assert(std::is_trivially_copyable_v<NewOrderSingle<C>>);

int main() {
  NewOrderSingle<C> o{};
  o.cl_ord_id = "ORD1";
  o.side = Side::buy;
  o.ord_type = OrdType::limit;
  o.price = stdx::optional<dec::decimal64_t>{dec::decimal64_t{15, -1}};
  const bool ok = !o.symbol.has_value() && o.price.has_value() && !o.order_qty.has_value() && o.unknown == 0;
  NewOrderSingle_message<K> m{};
  m.header.sender_comp_id = "ACME";
  m.header.poss_dup_flag = stdx::optional<glz::fix3::yes_no>{glz::fix3::yes_no::yes};
  std::printf("headers: sizeof NewOrderSingle keep=%zu count=%zu, StandardHeader keep=%zu; checks %s\n",
              sizeof(NewOrderSingle<K>), sizeof(NewOrderSingle<C>), sizeof(StandardHeader<K>), ok ? "ok" : "FAILED");
  return ok ? 0 : 1;
}
