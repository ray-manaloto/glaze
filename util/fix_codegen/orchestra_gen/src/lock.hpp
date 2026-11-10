// Name and width lock (stage 2): every generated name and type, keyed by Orchestra ids, in a checked-in
// text file. A rename in a new Orchestra file keeps the locked name; an addition, a removal or a changed
// type is refused until the change is reviewed and accepted with --update-lock.
#pragma once

#include "model.hpp"

#include <string>
#include <string_view>
#include <vector>

namespace gen {

// One line per item: KEY<TAB>NAME<TAB>TYPE, in emission order. Keys:
//   tag <tag>                          name = tag constant (ClOrdID), type = -
//   enum <codeSet id>                  name = C++ enum,       type = underlying type
//   code <codeSet id> <wire value>     name = enumerator,     type = -
//   part <component|group|message> <id>  name = C++ struct,  type = MsgType or -
//   member <part kind> <part id> <tag>    name = C++ member,  type = digest type (? = optional, also on a
//                                         group), then " open" when its codeSet accepts values beyond its codes
std::string emit_lock(const Output& o);

// Keep the locked names (owner, 2026-11-10): for every id already in the lock, use the lock's name instead
// of the one derived from the new Orchestra file, and rewrite type spellings that refer to a renamed enum or
// struct. Returns the names kept: one line per tag, enum, code or struct ("kept <key>: LOCKED (Orchestra now
// gives NEW)"), and one line per renamed member tag however many structs hold it ("kept member tag <tag>:
// LOCKED (Orchestra now gives NEW) in N struct(s)").
std::vector<std::string> apply_lock(Output& o, std::string_view lock_text);

// Throws when two names in one scope are equal (types in the namespace, values in an enum, members in a
// struct), which kept names can cause. Run after diff_lock, so refused changes are reported first.
void check_unique_names(const Output& o);

// The reviewed changes between two lock texts, one line each, in the new file's order (removals last):
//   added <key>: NAME TYPE | removed <key>: NAME TYPE | renamed <key>: OLD -> NEW | type <key> (NAME): OLD -> NEW
//   reordered part <kind> <id> (NAME): members changed wire order   (members in both files, compared in order)
std::vector<std::string> diff_lock(std::string_view old_text, std::string_view new_text);

}  // namespace gen
