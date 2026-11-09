#include <meta>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <stdx/optional.hpp>

enum class Side : std::uint8_t { buy, sell, buy_minus, sell_plus, sell_short, unset = 7 };  // dense index, 3 bits
enum class OrdType : std::uint8_t { market, limit, stop, stop_limit, unset = 7 };
template <> struct stdx::tombstone_traits<Side> { constexpr auto operator()() const { return Side::unset; } };

using ts_ns = std::chrono::sys_time<std::chrono::nanoseconds>;
static_assert(sizeof(ts_ns) == 8);
static_assert(sizeof(stdx::optional<Side>) == 1);
static_assert(sizeof(stdx::optional<std::uint32_t, stdx::tombstone_value<0xffffffffu>>) == 4);

struct Body {
  ts_ns transact_time;
  std::uint32_t qty;
  Side side : 3;
  OrdType ord_type : 3;
  std::uint8_t poss_dup : 2;
};
static_assert(sizeof(Body) == 16);

consteval auto members() {
  return std::define_static_array(std::meta::nonstatic_data_members_of(^^Body, std::meta::access_context::unchecked()));
}

int main() {
  Body b{};
  template for (constexpr auto m : members()) {
    if constexpr (std::meta::is_bit_field(m)) {
      b.[:m:] = static_cast<std::remove_cvref_t<decltype(b.[:m:])>>(1);
      std::printf("%s bits=%zu value=%d\n", std::meta::identifier_of(m).data(),
                  (size_t)std::meta::bit_size_of(m), (int)b.[:m:]);
    } else {
      std::printf("%s bytes=%zu\n", std::meta::identifier_of(m).data(), (size_t)std::meta::size_of(m));
    }
  }
  stdx::optional<Side> o{};
  std::printf("opt has=%d sizeof(Body)=%zu\n", (int)o.has_value(), sizeof(Body));
}
