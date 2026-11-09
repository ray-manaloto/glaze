// Plain reflect-cpp, used as its docs describe (docs/content/supported_formats/xml.md):
// hand-written structs that mirror the Orchestra XML, filled by rfl::xml::load<T>(path).
// No pugixml calls, no prefix stripping, no post-processing. reflect-cpp writes no C++ code;
// this program prints what reflect-cpp read, as JSON via rfl::json::write.
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <rfl/xml.hpp>

#include <cstdio>
#include <optional>
#include <string>
#include <vector>

template <rfl::internal::StringLiteral N, class T> using El = rfl::Rename<N, T>;            // child element
template <rfl::internal::StringLiteral N, class T> using At = rfl::Rename<N, rfl::Attribute<T>>;  // attribute
template <class T> using Opt = std::optional<T>;

struct Code {
  At<"id", int> id; At<"name", std::string> name; At<"value", std::string> value;
  Opt<At<"added", std::string>> added; Opt<At<"deprecated", std::string>> deprecated;
};
struct CodeSet {
  At<"id", int> id; At<"name", std::string> name; At<"type", std::string> type;
  El<"fixr:code", std::vector<Code>> codes;
};
struct Field {
  At<"id", int> id; At<"name", std::string> name; At<"type", std::string> type;
  Opt<At<"abbrName", std::string>> abbr_name; Opt<At<"lengthId", int>> length_id;
  Opt<At<"added", std::string>> added; Opt<At<"deprecated", std::string>> deprecated;
};
struct Datatype { At<"name", std::string> name; Opt<At<"baseType", std::string>> base_type; };
struct Ref { At<"id", int> id; Opt<At<"presence", std::string>> presence; Opt<At<"value", std::string>> value; };
struct NumInGroup { At<"id", int> id; };
// The structure of a message, component or group: an interleaved sequence of three element names.
// reflect-cpp binds each name to its own vector (Reader.hpp read_array: next_sibling(name)).
struct Refs {
  El<"fixr:fieldRef", std::vector<Ref>> field_refs;
  El<"fixr:componentRef", std::vector<Ref>> component_refs;
  El<"fixr:groupRef", std::vector<Ref>> group_refs;
};
struct Component {
  At<"id", int> id; At<"name", std::string> name; Opt<At<"category", std::string>> category;
  El<"fixr:fieldRef", std::vector<Ref>> field_refs;
  El<"fixr:componentRef", std::vector<Ref>> component_refs;
  El<"fixr:groupRef", std::vector<Ref>> group_refs;
};
struct Group {
  At<"id", int> id; At<"name", std::string> name; Opt<At<"category", std::string>> category;
  El<"fixr:numInGroup", NumInGroup> num_in_group;
  El<"fixr:fieldRef", std::vector<Ref>> field_refs;
  El<"fixr:componentRef", std::vector<Ref>> component_refs;
  El<"fixr:groupRef", std::vector<Ref>> group_refs;
};
struct Message {
  At<"id", int> id; At<"name", std::string> name; At<"msgType", std::string> msg_type;
  Opt<At<"category", std::string>> category;
  El<"fixr:structure", Refs> structure;
};
// Each container element (fixr:fields, ...) is its own struct holding the repeated child element.
template <rfl::internal::StringLiteral N, class T> struct List { El<N, std::vector<T>> items; };
struct Repository {
  At<"name", std::string> name; At<"version", std::string> version;
  El<"fixr:datatypes", List<"fixr:datatype", Datatype>> datatypes;
  El<"fixr:codeSets", List<"fixr:codeSet", CodeSet>> code_sets;
  El<"fixr:fields", List<"fixr:field", Field>> fields;
  El<"fixr:components", List<"fixr:component", Component>> components;
  El<"fixr:groups", List<"fixr:group", Group>> groups;
  El<"fixr:messages", List<"fixr:message", Message>> messages;
};

int main(int argc, char** argv) {
  if (argc < 2) { std::fprintf(stderr, "usage: %s <orchestra.xml> [message name]\n", argv[0]); return 2; }
  const auto repo = rfl::xml::load<Repository>(argv[1]);
  if (!repo) { std::printf("reflect-cpp error: %s\n", repo.error().what().c_str()); return 1; }
  const auto& r = *repo;
  std::printf("repository %s %s: datatypes=%zu codeSets=%zu fields=%zu components=%zu groups=%zu messages=%zu\n",
              r.name().value().c_str(), r.version().value().c_str(), r.datatypes().items().size(),
              r.code_sets().items().size(), r.fields().items().size(), r.components().items().size(),
              r.groups().items().size(), r.messages().items().size());
  for (const auto& m : r.messages().items())
    if (m.name().value() == (argc > 2 ? argv[2] : "NewOrderSingle")) std::printf("%s\n", rfl::json::write(m, rfl::json::pretty).c_str());
  for (const auto& c : r.code_sets().items())
    if (c.name().value() == "SideCodeSet") std::printf("%s\n", rfl::json::write(c).c_str());
}
