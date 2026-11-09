#pragma once
#include "model.hpp"

#include <optional>
#include <string>
#include <string_view>

namespace gen {
// The compiler the structs header is generated for (owner, 2026-11-09): members carry the C++26
// annotation [[=glz::fix3::tag{N}]] directly where the target supports annotations, and the
// GLZ_FIX3_TAG(N) macro only for a target without them. The header refuses any other compiler.
enum class target { gcc16, p2996, clang23 };
std::optional<target> parse_target(std::string_view s);
std::string_view target_name(target t);
std::string emit_enums(const Output& o);   // <ns>_enums.hpp: codeSet enums (both paths use them)
std::string emit_structs(const Output& o, target t); // <ns>.hpp: plain structs (headers path, every compiler)
std::string emit_digest(const Output& o);  // <ns>.digest: the same layout as text, for #embed
std::string emit_module(const Output& o);  // <ns>_embed.cppm: #embed + define_aggregate (C++26 path)
}  // namespace gen
