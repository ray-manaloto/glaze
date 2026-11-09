// Size of NewOrderSingle (FIX 4.4) under storage options; field counts from the generated fix44.hpp:
// 68 text, 7 group spans + 1 unknown span, 26 decimals, 3 timestamps, 6 ints, 46 one-byte enums.
#include <cstdint>
#include <cstdio>
#include <span>
#include <string_view>
struct dec8 { std::uint64_t bits; };            // decimal64_t is 8 bytes
struct ts8 { std::int64_t ns; };
struct ref8 { std::uint32_t off; std::uint16_t len; std::uint16_t pad; };  // offset+length into the input buffer
struct ref4 { std::uint16_t off; std::uint16_t len; };                     // when the message is < 64 KB
struct sp8 { std::uint32_t off; std::uint32_t count; };                   // group span as arena offset+count
template <class Text, class Span, int NText, int NSpan, int NDec, int NTs, int NInt, int NEnum>
struct Msg { Text t[NText]; Span s[NSpan]; dec8 d[NDec]; ts8 ts[NTs]; std::int64_t i[NInt]; char e[NEnum]; };
int main() {
  using SV = std::string_view; using SP = std::span<const int>;
  std::printf("today (generated):            %zu\n", sizeof(Msg<SV, SP, 68, 8, 26, 3, 6, 46>));
  std::printf("A  8-byte text refs + spans:  %zu\n", sizeof(Msg<ref8, sp8, 68, 8, 26, 3, 6, 46>));
  std::printf("A' 4-byte text refs (<64KB):  %zu\n", sizeof(Msg<ref4, ref4, 68, 8, 26, 3, 6, 46>));
  // B: venue subset, 20 fields: ClOrdID Account Symbol SecurityID SecurityIDSource ExDestination Currency Text ExecInst (9 text)
  //    + Parties + unknown (2 spans), OrderQty Price StopPx MinQty (4 dec), TransactTime ExpireTime (2 ts),
  //    Side OrdType TimeInForce HandlInst (4 enums) -> 21 members
  std::printf("B  venue subset, string_view: %zu\n", sizeof(Msg<SV, SP, 9, 2, 4, 2, 1, 4>));
  std::printf("B+A subset with 8-byte refs:  %zu\n", sizeof(Msg<ref8, sp8, 9, 2, 4, 2, 1, 4>));
}
