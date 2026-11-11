// The two paths agree: every struct define_aggregate built from the #embed'ed digest has the same
// member names, types, offsets, bit widths, size and alignment as the generated header's struct.
#include "fix44.hpp"
#include <meta>
#include <cstdio>
import fix44_embed;

consteval bool same_type(std::meta::info a, std::meta::info b) {
  using namespace std::meta;
  a = dealias(a); b = dealias(b);
  if (a == b) return true;
  // span<const fix44::X> vs span<const fix44_embed::X>: compare the entry types by name and layout
  if (has_template_arguments(a) && has_template_arguments(b) && template_of(a) == template_of(b)) {
    const auto ea = template_arguments_of(a)[0], eb = template_arguments_of(b)[0];
    if (!is_type(ea) || !is_type(eb)) return false;
    const auto ra = remove_const(ea), rb = remove_const(eb);
    return is_const_type(ea) == is_const_type(eb) && identifier_of(ra) == identifier_of(rb) && size_of(ra) == size_of(rb);
  }
  return false;
}

consteval bool same_layout(std::meta::info a, std::meta::info b) {
  using namespace std::meta;
  const auto ctx = access_context::unchecked();
  const auto ma = nonstatic_data_members_of(a, ctx), mb = nonstatic_data_members_of(b, ctx);
  if (ma.size() != mb.size() || size_of(a) != size_of(b) || alignment_of(a) != alignment_of(b)) return false;
  for (std::size_t i = 0; i < ma.size(); ++i)
    if (identifier_of(ma[i]) != identifier_of(mb[i]) || !same_type(type_of(ma[i]), type_of(mb[i])) ||
        offset_of(ma[i]) != offset_of(mb[i]) || bit_size_of(ma[i]) != bit_size_of(mb[i]))
      return false;
  return true;
}

consteval int compare_all() {
  using namespace std::meta;
  int n = 0;
  for (auto e : members_of(^^fix44_embed, access_context::unchecked())) {
    if (!has_identifier(e)) continue;
    info h{};
    for (auto c : members_of(^^fix44, access_context::unchecked()))
      if (has_identifier(c) && identifier_of(c) == identifier_of(e) && is_type(c) && is_class_type(c)) h = c;
    if (h == info{}) throw "no header struct for an embed struct";
    if (!same_layout(h, e)) throw "layout differs";
    ++n;
  }
  return n;
}

constexpr int compared = compare_all();
int main() { std::printf("diff: %d structs layout-identical (members, types, offsets, bit widths, size, alignment) between the header and #embed paths; static members and clang annotations are not compared\n", compared); }
