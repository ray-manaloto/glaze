#include <meta>
#include <cstdint>
#include <cstdio>
#include <stdx/optional.hpp>
enum class Side : char { buy = '1', sell = '2', sell_short = '5', cross = '8', opposite = 'C', lend = 'F', absent = '\0' };
template <> struct stdx::tombstone_traits<Side> { constexpr auto operator()() const { return Side::absent; } };
static_assert(sizeof(Side) == 1 && sizeof(stdx::optional<Side>) == 1);
struct B { std::uint64_t qty; Side side : 7; Side side2 : 7; Side side3 : 7; };
enum class USide : unsigned char { buy = '1', opposite = 'C', absent = 0 };
struct U { USide s : 7; };
int main() {
  U u{}; u.s = USide::opposite; std::printf("unsigned char 7-bit: wire='%c'\n", static_cast<char>(u.s));
  std::printf("char is %s here\n", static_cast<char>(-1) < 0 ? "signed" : "unsigned");
  B b{}; b.side = Side::opposite; b.side2 = static_cast<Side>('H'); b.side3 = Side::absent;
  template for (constexpr auto m : std::define_static_array(std::meta::nonstatic_data_members_of(^^B, std::meta::access_context::unchecked())))
    if constexpr (std::meta::is_bit_field(m)) std::printf("%s bits=%zu wire='%c'\n", std::meta::identifier_of(m).data(), (size_t)std::meta::bit_size_of(m), (int)static_cast<char>(b.[:m:]) == 0 ? '0' : static_cast<char>(b.[:m:]));
  std::printf("sizeof(B)=%zu\n", sizeof(B));
}
