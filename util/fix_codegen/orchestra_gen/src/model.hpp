// What the generator emits, independent of the output format (headers or #embed digest).
#pragma once

#include "orchestra.hpp"

#include <cstdint>
#include <set>
#include <string>
#include <vector>

namespace gen {

enum class enum_kind { char_, int_ };
struct Enumerator { std::string name; std::string value; };  // value: wire char or integer text
struct Enum {
  std::int32_t id = 0;         // Orchestra codeSet id (the lock file's key)
  std::string name;            // C++ name (codeSet name without "CodeSet")
  enum_kind kind;
  std::string underlying;      // char, std::uint8_t, std::uint16_t, std::uint32_t, std::int32_t...
  std::vector<Enumerator> values;
};

// The C++ type of one member, with its size and alignment on LP64 (checked by the static_asserts
// the generator writes, so a wrong model fails the build of the generated header).
struct Type {
  std::string cpp;     // spelling in the generated header
  std::string digest;  // spelling in the digest (decoded by the #embed path)
  int size = 0, align = 0;
  int bits = 0;        // > 0: a bit-field of this width
};

enum class member_kind { field, group };
struct Member {
  std::string name;
  std::int32_t tag = 0;  // FIX tag; for groups the NumInGroup tag
  bool required = false;
  member_kind kind = member_kind::field;
  Type type;
  std::string fix_name;       // Orchestra field name (ClOrdID), or the group name
  std::int32_t length_tag = 0;  // data fields: the Length tag before it (lengthId)
  std::int32_t max_entries = 0; // groups: implMaxOccurs, 0 = unbounded
  bool deprecated = false;
  bool open_enum = false;     // int enum whose field allows values beyond its codes (unionDataType)
  std::string datatype;       // Orchestra datatype (a codeSet field: the codeSet's datatype); empty for groups
};

enum class part_kind { component, group, message };
struct Part {
  part_kind kind = part_kind::message;
  std::int32_t id = 0;     // Orchestra id of the component, group or message (the lock file's key)
  std::string name;        // C++ struct name
  std::string fix_name;    // Orchestra name
  std::string msg_type;    // messages only
  std::vector<Member> wire_order;  // dictionary order (the tag table)
  std::vector<Member> layout;      // L6 member order: alignment 8, 4, 2, 1, then bit-fields
  std::vector<int> member_index;   // wire_order[i] is layout member member_index[i]
  int size = 0, align = 0;         // computed layout (checked by the emitted static_assert)
};

struct Output {
  std::string ns, source, version;
  std::string dictionary, begin_string, appl_ver_id;  // per-version constants for the codec
  std::vector<std::pair<std::int32_t, std::string>> tags;     // every field: tag, FIX name
  std::vector<std::pair<std::int32_t, std::int32_t>> length_data;  // (length tag, data tag) pairs
  std::vector<Enum> enums;
  std::vector<Part> entries;  // repeating-group entries, dependencies first
  Part header, trailer;
  std::vector<Part> messages;
  std::vector<std::string> notes;  // dropped duplicates, unmapped datatypes...
};

struct Options {
  std::string ns;
  bool strict = false;  // notes are errors
  std::set<std::string> msg_types;  // empty = every message
};

Output build(const orch::Repository& repo, const Options& opt, const std::string& source);

std::string snake(std::string_view pascal);

}  // namespace gen
