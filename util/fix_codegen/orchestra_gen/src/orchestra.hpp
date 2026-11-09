// Orchestra repository model, bound from XML with reflect-cpp (pugixml underneath).
#pragma once

#include <rfl.hpp>
#include <rfl/xml.hpp>

#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace orch {

// ---- leaf elements: bound by reflect-cpp, one struct per element kind --------------------------
// Element and attribute names are local names: the loader strips the namespace prefix ("fixr:")
// from every node first, so the binding works for the /2020/ and /2026/ namespaces and any prefix.
struct Datatype {
  rfl::Attribute<std::string> name;
  std::optional<rfl::Attribute<std::string>> baseType;
};
struct Code {
  rfl::Attribute<std::string> name;
  rfl::Attribute<std::string> value;
};
struct CodeSet {
  rfl::Attribute<std::int32_t> id;
  rfl::Attribute<std::string> name;
  rfl::Attribute<std::string> type;
  std::optional<std::vector<Code>> code;  // field name = element name: reflect-cpp binds same-name siblings
};
struct Field {
  rfl::Attribute<std::int32_t> id;
  rfl::Attribute<std::string> name;
  rfl::Attribute<std::string> type;  // a datatype name or a codeSet name
  std::optional<rfl::Attribute<std::int32_t>> lengthId;        // data field: the tag holding its length
  std::optional<rfl::Attribute<std::string>> unionDataType;    // e.g. Reserved4000Plus: values beyond the codes
  std::optional<rfl::Attribute<std::string>> deprecated;
};
struct RefAttrs {
  rfl::Attribute<std::int32_t> id;
  std::optional<rfl::Attribute<std::string>> presence;
};
struct NamedAttrs {  // message / component / group header attributes
  rfl::Attribute<std::int32_t> id;
  rfl::Attribute<std::string> name;
  std::optional<rfl::Attribute<std::string>> msgType;
  std::optional<rfl::Attribute<std::string>> implMaxOccurs;  // groups
};

// ---- ordered structures: walked by hand so the interleaved ref order survives -----------------
enum class ref_kind : char { field = 'f', component = 'c', group = 'g' };
enum class presence : char { optional = 'o', required = 'r', forbidden = 'x', ignored = 'i', constant = 'k' };

struct Ref {
  ref_kind kind;
  std::int32_t id;
  orch::presence presence;
};
struct Structure {  // component, group or message
  std::int32_t id;
  std::string name;
  std::string msg_type;          // messages only
  std::optional<Ref> num_in_group;  // groups only
  std::int32_t max_occurs = 0;      // groups: implMaxOccurs, 0 = unbounded
  std::vector<Ref> refs;         // document order
};

struct Repository {
  std::string name, version;
  std::map<std::string, Datatype> datatypes;
  std::map<std::string, CodeSet> code_sets;  // by name
  std::map<std::int32_t, Field> fields;      // by id
  std::map<std::int32_t, Structure> components, groups;
  std::vector<Structure> messages;
};

// Load and bind a file. Throws std::runtime_error on a malformed file, a binding error, or when the
// bound counts differ from a direct pugixml count (reflect-cpp's read_object drops per-field errors,
// so this check is the guard against silently lost elements).
Repository load(const std::string& path);

}  // namespace orch
