#include "orchestra.hpp"

#include <pugixml.hpp>

#include <cstring>
#include <format>
#include <stdexcept>
#include <set>
#include <string_view>
#include <vector>

namespace orch {
namespace {

[[noreturn]] void fail(std::string msg) { throw std::runtime_error(std::move(msg)); }

std::string_view local(const char* qname) {
  std::string_view s{qname};
  const auto c = s.find(':');
  return c == std::string_view::npos ? s : s.substr(c + 1);
}

// ---- attribute allowlist --------------------------------------------------------------------------
// Every attribute of every element the generator reads is either used or ignored on purpose. Anything
// else stops the run, so a new Orchestra attribute cannot change meaning without being looked at.
struct attr_rule { const char* element; std::set<std::string_view> used, ignored; };
const std::vector<attr_rule>& attr_rules() {
  static const std::set<std::string_view> life = {"added", "addedEP", "updated", "updatedEP", "deprecatedEP", "issue"};
  static const auto with_life = [](std::set<std::string_view> s) { s.insert(life.begin(), life.end()); return s; };
  static const std::vector<attr_rule> r = {
      {"datatype", {"name", "baseType"}, with_life({})},
      {"codeSet", {"id", "name", "type"}, with_life({"deprecated", "scenario", "specUrl"})},
      {"code", {"name", "value"}, with_life({"id", "sort", "group", "deprecated", "scenario"})},
      {"field", {"id", "name", "type", "lengthId", "unionDataType", "deprecated"},
       with_life({"abbrName", "baseCategory", "baseCategoryAbbrName", "discriminatorId", "scenario"})},
      {"component", {"id", "name"}, with_life({"abbrName", "category", "deprecated", "scenario"})},
      {"group", {"id", "name", "implMaxOccurs"}, with_life({"abbrName", "category", "deprecated", "scenario", "implMinOccurs"})},
      {"message", {"id", "name", "msgType"}, with_life({"abbrName", "category", "flow", "scenario"})},
      {"fieldRef", {"id", "presence"}, with_life({"deprecated", "scenario"})},
      {"componentRef", {"id", "presence"}, with_life({"deprecated", "scenario"})},
      {"groupRef", {"id", "presence"}, with_life({"deprecated", "scenario", "implMinOccurs", "implMaxOccurs"})},
      {"numInGroup", {"id"}, with_life({"deprecated", "scenario"})},
  };
  return r;
}

void check_attributes(pugi::xml_node root) {
  for (const auto& rule : attr_rules())
    for (const auto& xn : root.select_nodes(std::format("//{}", rule.element).c_str())) {
      const auto n = xn.node();
      for (auto a = n.first_attribute(); a; a = a.next_attribute()) {
        const std::string_view an = a.name();
        if (an == "scenario" && std::string_view(a.value()) != "base")
          fail(std::format("<{} {}>: scenario '{}' is not supported (only the base scenario)", rule.element,
                           n.attribute("name").value(), a.value()));
        if (!rule.used.contains(an) && !rule.ignored.contains(an))
          fail(std::format("<{} {}>: unknown attribute {}=\"{}\" (add it to the allowlist in orchestra.cpp)",
                           rule.element, n.attribute("name").value(), an, a.value()));
      }
    }
}

// Strip every element prefix, so reflect-cpp binds on local names ("field", not "fixr:field").
void strip_prefixes(pugi::xml_node n) {
  for (auto c = n.first_child(); c; c = c.next_sibling()) {
    if (c.type() != pugi::node_element) continue;
    const auto l = local(c.name());
    if (l.size() != std::strlen(c.name())) c.set_name(std::string(l).c_str());
    strip_prefixes(c);
  }
}

template <class T>
T bind(pugi::xml_node n) {
  auto r = rfl::xml::read<T>(rfl::xml::InputVarType(n));
  if (!r) fail(std::format("line ~{}: cannot bind <{}>: {}", n.offset_debug(), n.name(), r.error().what()));
  return std::move(*r);
}

presence parse_presence(const std::optional<rfl::Attribute<std::string>>& p) {
  if (!p) return presence::optional;
  const auto& v = p->value();
  if (v == "optional") return presence::optional;
  if (v == "required") return presence::required;
  if (v == "forbidden") return presence::forbidden;
  if (v == "ignored") return presence::ignored;
  if (v == "constant") return presence::constant;
  fail("unknown presence '" + v + "'");
}

Ref bind_ref(pugi::xml_node n, ref_kind k) {
  const auto a = bind<RefAttrs>(n);
  // reflect-cpp drops a failed optional attribute silently; check the raw value is the one bound.
  const auto raw = n.attribute("presence");
  if (raw && (!a.presence || a.presence->value() != raw.value()))
    fail(std::format("byte {}: presence=\"{}\" was not bound", n.offset_debug(), raw.value()));
  if (a.id.value() != n.attribute("id").as_int()) fail(std::format("byte {}: ref id not bound", n.offset_debug()));
  return Ref{k, a.id.value(), parse_presence(a.presence)};
}

// The hybrid: walk the children in document order ourselves, let reflect-cpp bind each one.
Structure bind_structure(pugi::xml_node item, pugi::xml_node refs_parent, std::size_t& ref_count) {
  const auto a = bind<NamedAttrs>(item);
  Structure s{a.id.value(), a.name.value(), a.msgType ? a.msgType->value() : std::string{}, {}, 0, {}};
  if (a.implMaxOccurs && a.implMaxOccurs->value() != "unbounded") s.max_occurs = std::stoi(a.implMaxOccurs->value());
  for (auto c = refs_parent.first_child(); c; c = c.next_sibling()) {
    const std::string_view n = c.name();
    if (n == "fieldRef") s.refs.push_back(bind_ref(c, ref_kind::field));
    else if (n == "componentRef") s.refs.push_back(bind_ref(c, ref_kind::component));
    else if (n == "groupRef") s.refs.push_back(bind_ref(c, ref_kind::group));
    else if (n == "numInGroup") s.num_in_group = bind_ref(c, ref_kind::field);
    else continue;
    ++ref_count;
  }
  return s;
}

std::size_t count_elements(pugi::xml_node root, const char* name) {
  return root.select_nodes(std::format("//{}", name).c_str()).size();
}

}  // namespace

Repository load(const std::string& path) {
  pugi::xml_document doc;
  const auto res = doc.load_file(path.c_str());
  if (!res) fail(std::format("{}: XML parse error at byte {}: {}", path, res.offset, res.description()));
  auto root = doc.document_element();
  if (local(root.name()) != "repository") fail(path + ": root element is not <repository>");
  bool ns_ok = false;
  for (auto at = root.first_attribute(); at; at = at.next_attribute()) {
    const std::string_view v = at.value();
    if (std::string_view(at.name()).starts_with("xmlns") &&
        (v == "http://fixprotocol.io/2020/orchestra/repository" || v == "http://fixprotocol.io/2026/orchestra/repository"))
      ns_ok = true;
  }
  if (!ns_ok) fail(path + ": no Orchestra repository namespace (/2020/ or /2026/)");
  root.set_name("repository");
  strip_prefixes(root);
  check_attributes(root);

  Repository repo;
  repo.name = root.attribute("name").value();
  repo.version = root.attribute("version").value();

  std::size_t n_dt = 0, n_cs = 0, n_code = 0, n_field = 0, n_comp = 0, n_grp = 0, n_msg = 0, n_ref = 0;
  for (auto n : root.child("datatypes").children("datatype")) {
    auto d = bind<Datatype>(n);
    repo.datatypes.emplace(d.name.value(), std::move(d));
    ++n_dt;
  }
  std::size_t n_code_unique = 0;
  for (auto n : root.child("codeSets").children("codeSet")) {
    auto cs = bind<CodeSet>(n);
    n_code += cs.code ? cs.code->size() : 0;
    std::set<std::string> values;
    for (const auto& c : cs.code ? *cs.code : std::vector<Code>{}) values.insert(c.value.value());
    n_code_unique += values.size();
    repo.code_sets.emplace(cs.name.value(), std::move(cs));
    ++n_cs;
  }
  for (auto n : root.child("fields").children("field")) {
    auto f = bind<Field>(n);
    // optional attributes: a failed bind leaves nullopt with no error, so compare with the raw XML
    if (n.attribute("lengthId") && (!f.lengthId || f.lengthId->value() != n.attribute("lengthId").as_int()))
      fail(std::format("field {}: lengthId not bound", f.name.value()));
    if (n.attribute("unionDataType") && !f.unionDataType) fail(std::format("field {}: unionDataType not bound", f.name.value()));
    if (n.attribute("deprecated") && !f.deprecated) fail(std::format("field {}: deprecated not bound", f.name.value()));
    repo.fields.emplace(f.id.value(), std::move(f));
    ++n_field;
  }
  for (auto n : root.child("components").children("component")) {
    auto s = bind_structure(n, n, n_ref);
    repo.components.emplace(s.id, std::move(s));
    ++n_comp;
  }
  for (auto n : root.child("groups").children("group")) {
    auto s = bind_structure(n, n, n_ref);
    if (!s.num_in_group) fail("group " + s.name + " has no <numInGroup>");
    repo.groups.emplace(s.id, std::move(s));
    ++n_grp;
  }
  for (auto n : root.child("messages").children("message")) {
    repo.messages.push_back(bind_structure(n, n.child("structure"), n_ref));
    ++n_msg;
  }

  // Guard: every element pugixml sees must have been bound (and kept: no duplicate ids or names).
  const auto check = [&](const char* what, std::size_t bound, std::size_t kept, std::size_t seen) {
    if (bound != seen || kept != seen)
      fail(std::format("{}: {} {} in the file, {} bound, {} kept (duplicate key?)", path, seen, what, bound, kept));
  };
  check("datatypes", n_dt, repo.datatypes.size(), count_elements(root, "datatypes/datatype"));
  check("codeSets", n_cs, repo.code_sets.size(), count_elements(root, "codeSets/codeSet"));
  check("codes", n_code, n_code_unique, count_elements(root, "codeSets/codeSet/code"));
  check("fields", n_field, repo.fields.size(), count_elements(root, "fields/field"));
  check("components", n_comp, repo.components.size(), count_elements(root, "components/component"));
  check("groups", n_grp, repo.groups.size(), count_elements(root, "groups/group"));
  check("messages", n_msg, repo.messages.size(), count_elements(root, "messages/message"));
  const std::size_t refs_seen = count_elements(root, "fieldRef") + count_elements(root, "componentRef") +
                                count_elements(root, "groupRef") + count_elements(root, "numInGroup");
  check("refs", n_ref, n_ref, refs_seen);
  return repo;
}

}  // namespace orch
