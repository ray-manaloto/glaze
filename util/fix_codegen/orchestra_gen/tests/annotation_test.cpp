// GCC 16.2 / clang-p2996: the GLZ_FIX3_TAG annotations on generated members read back by reflection.
#include "fix44.hpp"
#include <meta>
#include <cstdio>

template <class T> consteval std::uint16_t tag_of(std::string_view member) {
  for (auto m : std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::unchecked()))
    if (std::meta::identifier_of(m) == member)
      for (auto a : std::meta::annotations_of(m))
        if (std::meta::remove_cvref(std::meta::type_of(a)) == ^^glz::fix3::tag)
          return std::meta::extract<glz::fix3::tag>(a).value;
  return 0;
}
using K = glz::fix3::keep_unknown;
static_assert(tag_of<fix44::NewOrderSingle<K>>("cl_ord_id") == 11);
static_assert(tag_of<fix44::NewOrderSingle<K>>("side") == 54);
static_assert(tag_of<fix44::StandardHeader<K>>("sender_comp_id") == 49);
static_assert(tag_of<fix44::Parties>("party_role") == 452);
int main() { std::puts("annotations: tags read back by reflection ok"); }
