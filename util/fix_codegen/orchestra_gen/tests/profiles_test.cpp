// Partner profiles (orchestra_gen --profiles tests/profiles): settings are constants of a type, chosen
// once at runtime by name; the code that runs for a profile has no branch on its settings.
#include "fix44_profiles.hpp"
#include <cstdio>

using namespace fix44;
namespace pr = fix44::profiles;

static_assert(pr::millis::timestamp_digits(tag::TransactTime) == 9);  // per-field override
static_assert(pr::millis::timestamp_digits(tag::SendingTime) == 6);
static_assert(pr::millis::timestamp_digits(tag::ExpireTime) == 3);    // the profile's default
static_assert(pr::nanos::timestamp_digits(tag::TransactTime) == 9);
static_assert(pr::all::names.size() == 2 && pr::all::names[0] == "millis");

// What a codec does: for each timestamp field, the digits are a template-time constant.
template <class P, class Part> consteval std::size_t digits_total() {
  std::size_t n = 0;
  for (const auto& f : Part::fix_fields)
    if (f.datatype == "UTCTimestamp" || f.datatype == "TZTimestamp") n += P::timestamp_digits(f.tag);
  return n;
}

int main() {
  std::size_t chosen = 0;
  // The one runtime choice (e.g. at logon): pick the instantiation by the partner's profile name.
  const bool found = pr::all::with("millis", [&]<class P>() { chosen = digits_total<P, NewOrderSingle>(); });
  const bool missing = pr::all::with("nope", [&]<class P>() { chosen = 0; });
  constexpr auto m = digits_total<pr::millis, NewOrderSingle>(), n = digits_total<pr::nanos, NewOrderSingle>();
  const bool ok = found && !missing && chosen == m && m != n;
  std::printf("profiles: %zu profiles; NewOrderSingle timestamp digits millis=%zu nanos=%zu; unknown name refused; %s\n",
              pr::all::names.size(), m, n, ok ? "ok" : "FAILED");
  return ok ? 0 : 1;
}
