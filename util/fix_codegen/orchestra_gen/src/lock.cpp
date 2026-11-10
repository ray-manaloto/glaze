#include "lock.hpp"

#include <format>
#include <map>
#include <set>
#include <stdexcept>
#include <tuple>

namespace gen {
namespace {

std::string_view kind_name(part_kind k) {
  switch (k) {
    case part_kind::component: return "component";
    case part_kind::group: return "group";
    case part_kind::message: return "message";
  }
  return "?";
}

void add_part(std::string& s, const Part& p) {
  const auto k = kind_name(p.kind);
  s += std::format("part {} {}\t{}\t{}\n", k, p.id, p.name, p.msg_type.empty() ? "-" : p.msg_type);
  for (const auto& m : p.wire_order) s += std::format("member {} {} {}\t{}\t{}\n", k, p.id, m.tag, m.name, m.type.digest);
}

struct Item { std::string name, type; };
struct Parsed {
  std::vector<std::string> order;
  std::map<std::string, Item> items;
};

Parsed parse(std::string_view text) {
  Parsed p;
  std::size_t line_no = 0;
  for (std::size_t pos = 0; pos < text.size();) {
    auto end = text.find('\n', pos);
    if (end == std::string_view::npos) end = text.size();
    const auto line = text.substr(pos, end - pos);
    pos = end + 1;
    ++line_no;
    if (line.empty() || line.front() == '#') continue;
    const auto t1 = line.find('\t'), t2 = t1 == std::string_view::npos ? t1 : line.find('\t', t1 + 1);
    if (t2 == std::string_view::npos) throw std::runtime_error(std::format("lock line {}: expected KEY<TAB>NAME<TAB>TYPE", line_no));
    std::string key{line.substr(0, t1)};
    if (!p.items.emplace(key, Item{std::string{line.substr(t1 + 1, t2 - t1 - 1)}, std::string{line.substr(t2 + 1)}}).second)
      throw std::runtime_error(std::format("lock line {}: key '{}' appears twice", line_no, key));
    p.order.push_back(std::move(key));
  }
  return p;
}

bool ident_char(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'; }

// Replace whole identifiers (E:Side, stdx::optional<Side>, S:PartiesGrp) by their kept names.
void rename_idents(std::string& s, const std::map<std::string, std::string>& names) {
  std::string r;
  for (std::size_t i = 0; i < s.size();) {
    if (!ident_char(s[i])) { r += s[i++]; continue; }
    std::size_t j = i;
    while (j < s.size() && ident_char(s[j])) ++j;
    const std::string tok = s.substr(i, j - i);
    const auto it = names.find(tok);
    r += it == names.end() ? tok : it->second;
    i = j;
  }
  s = std::move(r);
}

void unique_in(std::set<std::string>& seen, const std::string& name, std::string_view scope) {
  if (!seen.insert(name).second) throw std::runtime_error(std::format("lock: kept name {} collides with another name in {}", name, scope));
}

}  // namespace

std::vector<std::string> apply_lock(Output& o, std::string_view lock_text) {
  const auto lock = parse(lock_text);
  std::vector<std::string> kept;
  std::map<std::string, std::string> type_names;  // new C++ type name -> kept name
  auto keep = [&](const std::string& key, std::string& name) {
    const auto it = lock.items.find(key);
    if (it == lock.items.end() || it->second.name == name) return false;
    kept.push_back(std::format("kept {}: {} (Orchestra now gives {})", key, it->second.name, name));
    name = it->second.name;
    return true;
  };
  for (auto& [tag, name] : o.tags) keep(std::format("tag {}", tag), name);
  for (auto& e : o.enums) {
    const auto before = e.name;
    if (keep(std::format("enum {}", e.id), e.name)) type_names[before] = e.name;
    for (auto& v : e.values) keep(std::format("code {} {}", e.id, v.value), v.name);
  }
  auto parts = [&](auto&& f) {
    f(o.header);
    f(o.trailer);
    for (auto& p : o.entries) f(p);
    for (auto& p : o.messages) f(p);
  };
  parts([&](Part& p) {
    const auto before = p.name;
    if (keep(std::format("part {} {}", kind_name(p.kind), p.id), p.name)) type_names[before] = p.name;
  });
  std::map<std::tuple<std::int32_t, std::string, std::string>, int> members_kept;  // (tag, kept, new) -> structs
  parts([&](Part& p) {
    for (auto* list : {&p.wire_order, &p.layout})
      for (auto& m : *list) {
        if (m.kind != member_kind::unknown)
          if (const auto it = lock.items.find(std::format("member {} {} {}", kind_name(p.kind), p.id, m.tag));
              it != lock.items.end() && it->second.name != m.name) {
            if (list == &p.wire_order) ++members_kept[{m.tag, it->second.name, m.name}];
            m.name = it->second.name;
          }
        if (!type_names.empty()) { rename_idents(m.type.cpp, type_names); rename_idents(m.type.digest, type_names); }
      }
  });
  for (const auto& [k, n] : members_kept)
    kept.push_back(std::format("kept member tag {}: {} (Orchestra now gives {}) in {} struct(s)", std::get<0>(k), std::get<1>(k),
                               std::get<2>(k), n));
  return kept;
}

void check_unique_names(const Output& o) {
  auto parts = [&](auto&& f) {
    f(o.header);
    f(o.trailer);
    for (const auto& p : o.entries) f(p);
    for (const auto& p : o.messages) f(p);
  };
  // A kept name must still be unique in its scope: the namespace's types, one enum's values, one struct's members.
  std::set<std::string> types;
  for (const auto& e : o.enums) {
    unique_in(types, e.name, o.ns);
    std::set<std::string> values;
    for (const auto& v : e.values) unique_in(values, v.name, e.name);
  }
  parts([&](const Part& p) {
    unique_in(types, p.name, o.ns);
    std::set<std::string> members;
    for (const auto& m : p.wire_order) unique_in(members, m.name, p.name);
  });
}

std::string emit_lock(const Output& o) {
  std::string s = std::format(
      "# orchestra_gen name and width lock for namespace {} ({} {}, from {}).\n"
      "# Keyed by Orchestra ids. Change it only with --update-lock after reviewing the reported changes.\n",
      o.ns, o.dictionary, o.version, o.source);
  for (const auto& [tag, name] : o.tags) s += std::format("tag {}\t{}\t-\n", tag, name);  // fix44::tags::ClOrdID
  for (const auto& e : o.enums) {
    s += std::format("enum {}\t{}\t{}\n", e.id, e.name, e.underlying);
    for (const auto& v : e.values) s += std::format("code {} {}\t{}\t-\n", e.id, v.value, v.name);
  }
  add_part(s, o.header);
  add_part(s, o.trailer);
  for (const auto& p : o.entries) add_part(s, p);
  for (const auto& p : o.messages) add_part(s, p);
  return s;
}

std::vector<std::string> diff_lock(std::string_view old_text, std::string_view new_text) {
  const auto a = parse(old_text), b = parse(new_text);
  std::vector<std::string> out;
  for (const auto& key : b.order) {
    const auto& nb = b.items.at(key);
    const auto it = a.items.find(key);
    if (it == a.items.end()) { out.push_back(std::format("added {}: {} {}", key, nb.name, nb.type)); continue; }
    const auto& na = it->second;
    if (na.name != nb.name) out.push_back(std::format("renamed {}: {} -> {}", key, na.name, nb.name));
    if (na.type != nb.type) out.push_back(std::format("type {} ({}): {} -> {}", key, nb.name, na.type, nb.type));
  }
  for (const auto& key : a.order)
    if (!b.items.contains(key)) {
      const auto& na = a.items.at(key);
      out.push_back(std::format("removed {}: {} {}", key, na.name, na.type));
    }
  return out;
}

}  // namespace gen
