// Headers path: the generated structs compile and behave on every compiler (no reflection needed).
#include "fix44.hpp"
#include <cstdio>

using namespace fix44;
using K = glz::fix3::keep_unknown;
using C = glz::fix3::count_unknown;
using Order = NewOrderSingle;

static_assert(sizeof(stdx::optional<Side>) == 1);                         // L4: tombstone, no extra bool
static_assert(sizeof(stdx::optional<std::string_view>) == sizeof(std::string_view));
static_assert(sizeof(glz::fix3::opt_int<std::uint32_t>) == 4);
static_assert(static_cast<char>(Side::sell) == '2');                     // L5: value = wire char
static_assert(std::is_same_v<std::underlying_type_t<PartyRole>, std::uint8_t>);  // largest code < 255
static_assert(Order::fix_msg_type == "D");
static_assert(Order::fix_fields[0].tag == 11);                          // tag table in wire order
static_assert(std::is_aggregate_v<Order>);
static_assert(std::is_trivially_copyable_v<Order>);
// L1 on the envelope: the parts carry no policy; only message<H, B, T, U> differs between policies.
static_assert(sizeof(NewOrderSingle_message<K>) - sizeof(NewOrderSingle_message<C>) == 8);
static_assert(std::is_same_v<decltype(NewOrderSingle_message<K>::unknown), std::span<const glz::fix3::unknown_field>>);

int main() {
  Order o{};
  o.cl_ord_id = "ORD1";
  o.side = Side::buy;
  o.ord_type = OrdType::limit;
  o.price = stdx::optional<dec::decimal64_t>{dec::decimal64_t{15, -1}};
  const bool ok = !o.symbol.has_value() && o.price.has_value() && !o.order_qty.has_value();
  NewOrderSingle_message<K> m{};
  m.header.sender_comp_id = "ACME";
  m.header.poss_dup_flag = stdx::optional<glz::fix3::yes_no>{glz::fix3::yes_no::yes};
  // Shape only (the codec fills it): the envelope holds unknown tags with their position in the message.
  const glz::fix3::unknown_field seen[] = {{14, 9999, "x"}};
  m.unknown = seen;
  const bool ok2 = ok && m.unknown.size() == 1 && m.unknown[0].position == 14;
  std::printf("headers: sizeof NewOrderSingle=%zu, StandardHeader=%zu, message keep=%zu count=%zu; checks %s\n",
              sizeof(Order), sizeof(StandardHeader), sizeof(NewOrderSingle_message<K>), sizeof(NewOrderSingle_message<C>),
              ok2 ? "ok" : "FAILED");
  return ok2 ? 0 : 1;
}
