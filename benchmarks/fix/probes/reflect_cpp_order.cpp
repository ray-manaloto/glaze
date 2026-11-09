#include <rfl.hpp>
#include <rfl/xml.hpp>
#include <pugixml.hpp>
#include <cstdio>
#include <string>
#include <variant>
#include <vector>

constexpr const char* kXml = R"(<?xml version="1.0"?>
<fixr:message xmlns:fixr="http://fixprotocol.io/2020/orchestra/repository" name="NewOrderSingle" id="14" msgType="D">
  <fixr:structure>
    <fixr:componentRef id="1024" presence="required"/>
    <fixr:fieldRef id="11" presence="required"/>
    <fixr:groupRef id="2048"/>
    <fixr:fieldRef id="55"/>
    <fixr:componentRef id="1025" presence="required"/>
  </fixr:structure>
</fixr:message>)";

struct FieldRef     { rfl::Attribute<int> id; std::optional<rfl::Attribute<std::string>> presence; };
struct ComponentRef { rfl::Attribute<int> id; std::optional<rfl::Attribute<std::string>> presence; };
struct GroupRef     { rfl::Attribute<int> id; std::optional<rfl::Attribute<std::string>> presence; };

// (a) plain reflect-cpp binding: one vector per element name
struct StructureA {
  rfl::Rename<"fixr:fieldRef", std::vector<FieldRef>> fields;
  rfl::Rename<"fixr:componentRef", std::vector<ComponentRef>> components;
  rfl::Rename<"fixr:groupRef", std::vector<GroupRef>> groups;
};
struct MessageA {
  rfl::Attribute<std::string> name; rfl::Attribute<int> id; rfl::Attribute<std::string> msgType;
  rfl::Rename<"fixr:structure", StructureA> structure;
};

using Ref = std::variant<FieldRef, ComponentRef, GroupRef>;

int main() {
  // (a)
  auto a = rfl::xml::read<MessageA>(kXml);
  if (!a) { std::printf("(a) error: %s\n", a.error().what().c_str()); }
  else {
    auto& s = a->structure.get();
    std::printf("(a) %s: fields=%zu components=%zu groups=%zu -> interleaving lost\n",
                a->name.value().c_str(), s.fields.get().size(), s.components.get().size(), s.groups.get().size());
  }
  // (b) hybrid: pugixml walks children in document order, reflect-cpp binds each one
  pugi::xml_document doc; doc.load_string(kXml);
  std::vector<Ref> refs;
  for (auto c : doc.child("fixr:message").child("fixr:structure").children()) {
    std::string_view n = c.name();
    auto local = n.substr(n.find(':') + 1);   // namespace-prefix tolerant
    auto bind = [&]<class T>(std::type_identity<T>) {
      auto r = rfl::xml::read<T>(rfl::xml::InputVarType(c));
      if (r) refs.emplace_back(std::move(*r)); else std::printf("bind error %s\n", r.error().what().c_str());
    };
    if (local == "fieldRef") bind(std::type_identity<FieldRef>{});
    else if (local == "componentRef") bind(std::type_identity<ComponentRef>{});
    else if (local == "groupRef") bind(std::type_identity<GroupRef>{});
  }
  std::printf("(b) order:");
  for (auto& r : refs) std::visit([](auto& x) {
      using T = std::remove_cvref_t<decltype(x)>;
      const char* k = std::is_same_v<T, FieldRef> ? "field" : std::is_same_v<T, ComponentRef> ? "component" : "group";
      std::printf(" %s:%d", k, x.id.value()); }, r);
  std::printf("\n");
}
