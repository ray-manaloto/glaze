#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <string_view>
#include <charconv>
#include <string_view>
#include "tags.hpp"
// Normal builds force the lookup inline (GCC 16.2 at -O2 otherwise calls sorted and frozen out of line).
// -DLOOKUP_ASM keeps it as its own symbol so its assembly can be read.
#ifdef LOOKUP_ASM
#define LOOKUP_ATTR extern "C" __attribute__((noinline))
#else
#define LOOKUP_ATTR [[gnu::always_inline]] static inline
#endif
constexpr int N = int(tags.size());

#if defined(M_LINEAR)
LOOKUP_ATTR int find_idx(std::uint32_t t) { for (int i = 0; i < N; ++i) if (tags[i] == t) return i; return -1; }
static constexpr const char* name = "linear (today)";
#elif defined(M_SORTED)
struct E { std::uint32_t t; std::uint16_t i; };
static constexpr auto sorted = [] { std::array<E, N> a{}; for (int i = 0; i < N; ++i) a[i] = {tags[i], std::uint16_t(i)};
  std::sort(a.begin(), a.end(), [](E x, E y) { return x.t < y.t; }); return a; }();
LOOKUP_ATTR int find_idx(std::uint32_t t) { auto it = std::lower_bound(sorted.begin(), sorted.end(), t, [](E e, std::uint32_t v) { return e.t < v; });
  return (it != sorted.end() && it->t == t) ? it->i : -1; }
static constexpr const char* name = "sorted + binary search";
#elif defined(M_DIRECT)
static constexpr std::uint32_t maxtag = *std::max_element(tags.begin(), tags.end());
static constexpr auto direct = [] { std::array<std::uint8_t, maxtag + 1> a{}; a.fill(0xFF); for (int i = 0; i < N; ++i) a[tags[i]] = std::uint8_t(i); return a; }();
LOOKUP_ATTR int find_idx(std::uint32_t t) { if (t > maxtag) return -1; auto s = direct[t]; return s == 0xFF ? -1 : int(s); }
static constexpr const char* name = "direct-index array (tag -> slot)";
#elif defined(M_HAND)
struct H { std::uint32_t k; unsigned shift; std::array<std::uint16_t, 16384> slot; unsigned bits; };
static constexpr H hash = [] {
  for (unsigned bits = 13; bits <= 14; ++bits)
    for (std::uint32_t k = 2654435761u, n = 0; n < 200; ++n, k += 0x9E3779B9u) {
      H h{k, 32 - bits, {}, bits}; h.slot.fill(0xFFFF); bool ok = true;
      for (int i = 0; i < N && ok; ++i) { auto s = std::uint32_t(tags[i] * k) >> h.shift; if (h.slot[s] != 0xFFFF) ok = false; else h.slot[s] = std::uint16_t(i); }
      if (ok) return h;
    }
  return H{0, 0, {}, 0};
}();
static_assert(hash.k != 0, "no perfect hash found");
LOOKUP_ATTR int find_idx(std::uint32_t t) { auto s = hash.slot[std::uint32_t(t * hash.k) >> hash.shift]; return (s != 0xFFFF && tags[s] == t) ? int(s) : -1; }
static constexpr const char* name = "hand-rolled multiplicative hash";
#elif defined(M_MPH)
#include "mph"
static constexpr auto entries = [] { std::array<std::pair<std::uint32_t, std::uint16_t>, N> a{}; for (int i = 0; i < N; ++i) a[i] = {tags[i], std::uint16_t(i + 1)}; return a; }();
LOOKUP_ATTR int find_idx(std::uint32_t t) { auto r = mph::find<entries>(t); return r ? int(*r) - 1 : -1; }
static constexpr const char* name = "qlibs/mph find";
#elif defined(M_CIB)
#include <lookup/lookup.hpp>
#include <stdx/ct_conversions.hpp>
#include <stdx/utility.hpp>
static constexpr auto in = [] { std::array<lookup::entry<std::uint32_t, std::uint16_t>, N> a{}; for (int i = 0; i < N; ++i) a[i] = {tags[i], std::uint16_t(i + 1)};
  return lookup::input<std::uint32_t, std::uint16_t, N>{0, a}; }();
static constexpr auto lk = lookup::make(CX_VALUE(in));
LOOKUP_ATTR int find_idx(std::uint32_t t) { return int(lk[t]) - 1; }
static constexpr const char* name = "intel cib lookup";
#elif defined(M_FROZEN)
#include <frozen/unordered_map.h>
static constexpr auto fz = [] { std::array<std::pair<std::uint16_t, std::uint16_t>, N> a{}; for (int i = 0; i < N; ++i) a[i] = {std::uint16_t(tags[i]), std::uint16_t(i)}; return a; }();
static constexpr auto fmap = frozen::make_unordered_map(fz);
LOOKUP_ATTR int find_idx(std::uint32_t t) { if (t > 0xFFFF) return -1; auto it = fmap.find(std::uint16_t(t)); return it == fmap.end() ? -1 : int(it->second); }
static constexpr const char* name = "frozen unordered_map";
#elif defined(M_PH)
#include <ConstexprCore/perfect_hash.h>
static constexpr auto ph = ConstexprCore::make_wide_perfect_index_map<tag_strs>();
LOOKUP_ATTR int find_idx(std::uint32_t t) { char b[12]; auto r = std::to_chars(b, b + 12, t); auto o = ph.lookup(std::string_view(b, r.ptr)); return o ? int(*o) : -1; }
static constexpr const char* name = "ConstexprCore/perfect_hash (digits as key)";
#endif

#if defined(__APPLE__)
#include <libproc.h>
#include <sys/resource.h>
#include <unistd.h>
// Instructions and cycles the kernel counted for this process (Apple silicon PMU, no sudo).
static void counters(std::uint64_t& ins, std::uint64_t& cyc) {
  rusage_info_v4 ri{}; proc_pid_rusage(getpid(), RUSAGE_INFO_V4, reinterpret_cast<rusage_info_t*>(&ri));
  ins = ri.ri_instructions; cyc = ri.ri_cycles;
}
#else
static void counters(std::uint64_t& ins, std::uint64_t& cyc) { ins = cyc = 0; }
#endif

int main() {
  int bad = 0;
  for (int i = 0; i < N; ++i) if (find_idx(tags[i]) != i) ++bad;
  for (std::uint32_t t = 0; t < 20000; ++t) if (std::find(tags.begin(), tags.end(), t) == tags.end() && find_idx(t) != -1) ++bad;
  for (std::uint32_t t : {100000u, 4294967295u, 65536u + 49u}) if (find_idx(t) != -1) ++bad;
  static std::uint32_t q[1 << 16]; std::uint32_t x = 12345;
  for (auto& v : q) { x = x * 1664525u + 1013904223u; v = (x >> 28) < 14 ? tags[(x >> 8) % N] : (x >> 10) % 20000; }
  long sink = 0; std::uint64_t i0, c0, i1, c1; counters(i0, c0); auto t0 = std::chrono::steady_clock::now();
  for (int rep = 0; rep < 200; ++rep) for (auto v : q) sink += find_idx(v);
  auto t1 = std::chrono::steady_clock::now(); counters(i1, c1);
  const double n = 200.0 * (1 << 16);
  auto ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / n;
  std::printf("%-44s errors=%d  %.2f ns/lookup  %.2f cyc/lookup  %.2f instr/lookup (sink %ld)\n", name, bad, ns,
              double(c1 - c0) / n, double(i1 - i0) / n, sink & 1);
  return bad != 0;  // wrong lookups fail the run
}
