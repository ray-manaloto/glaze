#include "model.hpp"

#include <algorithm>
#include <charconv>
#include <format>
#include <limits>
#include <map>
#include <stdexcept>

namespace gen {
namespace {

const std::set<std::string> cpp_keywords = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
    "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr",
    "constinit", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
    "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for",
    "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
    "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
    "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct",
    "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
    "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq", "unknown"};

bool upper(char c) { return c >= 'A' && c <= 'Z'; }
bool lower_or_digit(char c) { return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); }

std::string ident_fix(std::string s) {
  for (auto& c : s)
    if (!(upper(c) || lower_or_digit(c) || c == '_')) c = '_';
  if (s.empty() || (s[0] >= '0' && s[0] <= '9')) s = "f_" + s;
  if (cpp_keywords.contains(s)) s += '_';
  return s;
}

struct Builder {
  const orch::Repository& repo;
  Output out;
  std::map<std::string, std::size_t> enum_index;  // codeSet name -> out.enums index
  std::map<std::int32_t, std::string> entry_name; // group id -> entry struct name (built)
  std::set<std::string> taken;                    // every C++ type name in the namespace
  std::set<std::string> open_code_sets;           // int codeSets some field marks Reserved<N>Plus

  std::string unique_type_name(std::string base, const char* suffix) {
    base = ident_fix(base);
    if (taken.insert(base).second) return base;
    for (int i = 0;; ++i) {
      auto n = base + suffix + (i ? std::to_string(i) : "");
      if (taken.insert(n).second) return n;
    }
  }

  // Resolve a datatype name through baseType to the families the type map knows.
  std::string base_of(std::string t) const {
    static const std::set<std::string> known = {"int", "Length", "NumInGroup", "SeqNum", "TagNum", "DayOfMonth",
                                                "float", "char", "Boolean", "String", "data", "UTCTimestamp",
                                                "TZTimestamp"};
    for (int guard = 0; guard < 16 && !known.contains(t); ++guard) {
      auto it = repo.datatypes.find(t);
      if (it == repo.datatypes.end() || !it->second.baseType) break;
      t = it->second.baseType->value();
    }
    return t;
  }

  static Type plain(std::string cpp, std::string dig, int size) { return Type{cpp, dig, size, size, 0}; }

  std::optional<std::size_t> enum_for(const orch::CodeSet& cs) {
    if (auto it = enum_index.find(cs.name.value()); it != enum_index.end()) return it->second;
    const auto& t = cs.type.value();
    if (!cs.code || cs.code->empty()) return std::nullopt;
    Enum e;
    e.id = cs.id.value();
    std::string nm = cs.name.value();
    if (nm.ends_with("CodeSet")) nm.resize(nm.size() - 7);
    if (t == "char" || base_of(t) == "char") {
      e.kind = enum_kind::char_;
      e.underlying = "char";
      for (const auto& c : *cs.code)
        if (c.value.value().size() != 1) {
          out.notes.push_back(std::format("codeSet {}: code '{}' is not one char; field stays string_view",
                                          cs.name.value(), c.value.value()));
          return std::nullopt;
        }
    } else if (t == "int" || base_of(t) == "int") {
      e.kind = enum_kind::int_;
      long long lo = 0, hi = 0;
      for (const auto& c : *cs.code) {
        long long v = 0;
        const auto& s = c.value.value();
        const auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), v);
        if (ec != std::errc{} || p != s.data() + s.size()) {
          out.notes.push_back(std::format("codeSet {}: code '{}' is not an integer", cs.name.value(), s));
          return std::nullopt;
        }
        lo = std::min(lo, v);
        hi = std::max(hi, v);
      }
      // L5: the smallest integer type that holds every *legal* value and leaves max() free as "absent".
      // A field with unionDataType Reserved<N>Plus allows any value from N up, so its enum is 32-bit.
      // Each width is chosen only if hi < max(), so no legal code can equal the "absent" sentinel.
      const bool open = open_code_sets.contains(cs.name.value());
      if (hi == std::numeric_limits<long long>::max())  // no integer type could tell it from "absent": refuse
        throw std::runtime_error(std::format("codeSet {}: code {} equals the int64 absence sentinel (L4)", cs.name.value(), hi));
      if (lo >= 0) {
        e.underlying = !open && hi < 0xff ? "std::uint8_t" : !open && hi < 0xffff ? "std::uint16_t"
                       : hi < 0xffffffffLL ? "std::uint32_t" : "std::uint64_t";
      } else {
        e.underlying = !open && lo >= -128 && hi < 127       ? "std::int8_t"
                       : !open && lo >= -32768 && hi < 32767 ? "std::int16_t"
                       : lo >= -2147483648LL && hi < 2147483647LL ? "std::int32_t" : "std::int64_t";
      }
    } else {
      return std::nullopt;  // String / MultipleCharValue / Boolean codeSets: no enum
    }
    e.name = unique_type_name(nm, "Code");
    std::set<std::string> used;
    for (const auto& c : *cs.code) {
      auto n = ident_fix(snake(c.name.value()));
      if (!used.insert(n).second) n += "_" + ident_fix(c.value.value());
      used.insert(n);
      e.values.push_back({n, c.value.value()});
    }
    out.enums.push_back(std::move(e));
    enum_index[cs.name.value()] = out.enums.size() - 1;
    return out.enums.size() - 1;
  }

  // L2-L5: the member type of one field.
  Type field_type(const orch::Field& f, bool required) {
    std::string t = f.type.value();
    Type ty;
    bool done = false;
    if (auto cs = repo.code_sets.find(t); cs != repo.code_sets.end()) {
      if (auto ei = enum_for(cs->second)) {
        const auto& e = out.enums[*ei];
        const int sz = e.underlying == "char" || e.underlying.ends_with("int8_t") ? 1
                       : e.underlying.ends_with("16_t") ? 2 : e.underlying.ends_with("32_t") ? 4 : 8;
        ty = plain(e.name, "E:" + e.name, sz);
        done = true;
      } else {
        t = cs->second.type.value();  // no enum (Boolean, String, ... codeSet): map its datatype
      }
    }
    if (!done) {
      const auto b = base_of(t);
      if (t == "SeqNum") ty = plain("std::uint64_t", "u64", 8);
      else if (t == "Length") ty = plain("std::uint32_t", "u32", 4);
      else if (t == "NumInGroup" || t == "TagNum") ty = plain("std::uint16_t", "u16", 2);
      else if (t == "DayOfMonth") ty = plain("std::uint8_t", "u8", 1);
      else if (b == "int") ty = plain("std::int64_t", "i64", 8);
      else if (b == "float") ty = plain("dec::decimal64_t", "dec64", 8);
      else if (t == "Boolean" || b == "Boolean") {
        if (required) return Type{"bool", "bool", 1, 1, 1};  // L5: a bit-field where every code fits
        ty = plain("glz::fix3::yes_no", "yn", 1);
      } else if (b == "char") ty = plain("char", "char", 1);
      else if (t == "UTCTimestamp" || t == "TZTimestamp") ty = plain("glz::fix3::timestamp", "ts", 8);
      else {
        if (b != "String" && b != "data")
          out.notes.push_back(std::format("field {} ({}): datatype '{}' unmapped, using string_view", f.name.value(), f.id.value(), t));
        ty = plain("std::string_view", "sv", 16);
        ty.align = 8;
      }
    }
    if (!required) {  // L4: stdx::optional, "absent" is a tombstone value, same size as T
      const bool integral = ty.digest == "u64" || ty.digest == "u32" || ty.digest == "u16" || ty.digest == "u8" ||
                            ty.digest == "i64";
      ty.cpp = ty.digest == "char" ? "glz::fix3::opt_char"
               : integral          ? "glz::fix3::opt_int<" + ty.cpp + ">"
                                   : "stdx::optional<" + ty.cpp + ">";
      ty.digest = "?" + ty.digest;
    }
    return ty;
  }

  void flatten(const std::vector<orch::Ref>& refs, bool optional_ctx, Part& p, std::set<std::int32_t>& tags,
               const std::set<std::int32_t>& excluded, bool skip_session_components) {
    for (const auto& r : refs) {
      if (r.presence == orch::presence::forbidden || r.presence == orch::presence::ignored) continue;
      const bool req = !optional_ctx && r.presence == orch::presence::required;
      if (r.kind == orch::ref_kind::component) {
        const auto it = repo.components.find(r.id);
        if (it == repo.components.end()) throw std::runtime_error(std::format("componentRef {} unknown", r.id));
        if (skip_session_components && (it->second.name == "StandardHeader" || it->second.name == "StandardTrailer")) continue;
        flatten(it->second.refs, optional_ctx || !req, p, tags, excluded, false);
        continue;
      }
      if (r.kind == orch::ref_kind::group) {
        const auto it = repo.groups.find(r.id);
        if (it == repo.groups.end()) throw std::runtime_error(std::format("groupRef {} unknown", r.id));
        const auto& g = it->second;
        const auto& nf = repo.fields.at(g.num_in_group->id);
        if (!tags.insert(nf.id.value()).second) {
          out.notes.push_back(std::format("{}: group {} repeats tag {}; dropped", p.fix_name, g.name, nf.id.value()));
          continue;
        }
        const auto entry = build_entry(g);
        Member m{ident_fix(snake(g.name)), nf.id.value(), req, member_kind::group,
                 Type{"std::span<const " + entry + ">", "S:" + entry, 16, 8, 0}};
        m.fix_name = g.name;
        m.max_entries = g.max_occurs;
        p.wire_order.push_back(m);
        continue;
      }
      const auto fit = repo.fields.find(r.id);
      if (fit == repo.fields.end()) throw std::runtime_error(std::format("fieldRef {} unknown", r.id));
      const auto& f = fit->second;
      if (excluded.contains(f.id.value())) continue;
      if (!tags.insert(f.id.value()).second) {
        out.notes.push_back(std::format("{}: tag {} ({}) appears twice; second dropped", p.fix_name, f.id.value(), f.name.value()));
        continue;
      }
      Member m{ident_fix(snake(f.name.value())), f.id.value(), req, member_kind::field, field_type(f, req)};
      m.fix_name = f.name.value();
      m.length_tag = f.lengthId ? f.lengthId->value() : 0;
      m.deprecated = f.deprecated.has_value();
      m.open_enum = f.unionDataType && open_code_sets.contains(f.type.value());
      const auto cs = repo.code_sets.find(f.type.value());
      m.datatype = cs != repo.code_sets.end() ? cs->second.type.value() : f.type.value();
      p.wire_order.push_back(std::move(m));
    }
  }

  std::string build_entry(const orch::Structure& g) {
    if (auto it = entry_name.find(g.id); it != entry_name.end()) return it->second;
    Part p;
    p.kind = part_kind::group;
    p.id = g.id;
    p.fix_name = g.name;
    std::set<std::int32_t> tags;
    flatten(g.refs, false, p, tags, {}, false);
    // FIX: the first field of an entry is its delimiter and must be present in every entry.
    if (!p.wire_order.empty() && p.wire_order.front().kind == member_kind::field && !p.wire_order.front().required) {
      auto& m = p.wire_order.front();
      m.required = true;
      m.type = field_type(repo.fields.at(m.tag), true);
    }
    p.name = unique_type_name(g.name, "Grp");
    entry_name[g.id] = p.name;
    finish(p);
    out.entries.push_back(std::move(p));
    return entry_name[g.id];
  }

  static int layout_size(const std::vector<Member>& ms, int& align_out) {
    int off = 0, align = 1, bits = 0;
    for (const auto& m : ms) {
      if (m.type.bits > 0) { ++bits; continue; }  // bit-fields come last (L6)
      off = (off + m.type.align - 1) / m.type.align * m.type.align + m.type.size;
      align = std::max(align, m.type.align);
    }
    off += (bits + 7) / 8;
    align_out = align;
    return std::max(1, (off + align - 1) / align * align);  // an empty struct still takes 1 byte
  }

  // L6: members ordered by alignment (8, 4, 2, 1), then the bit-fields; stable within a class.
  void finish(Part& p) {
    p.layout = p.wire_order;
    std::stable_sort(p.layout.begin(), p.layout.end(), [](const Member& a, const Member& b) {
      const int ka = a.type.bits ? 0 : a.type.align, kb = b.type.bits ? 0 : b.type.align;
      return ka > kb;
    });
    for (const auto& w : p.wire_order) {
      const auto it = std::ranges::find_if(p.layout, [&](const Member& m) { return m.tag == w.tag; });
      p.member_index.push_back(static_cast<int>(it - p.layout.begin()));
    }
    p.size = layout_size(p.layout, p.align);
  }

  Part session_part(const char* name, std::set<std::int32_t> excluded) {
    const auto it = std::ranges::find_if(repo.components, [&](const auto& kv) { return kv.second.name == name; });
    if (it == repo.components.end()) throw std::runtime_error(std::string("no component ") + name);
    Part p;
    p.name = unique_type_name(name, "Part");
    p.kind = part_kind::component;
    p.id = it->first;
    p.fix_name = name;
    std::set<std::int32_t> tags;
    flatten(it->second.refs, false, p, tags, excluded, false);
    finish(p);
    return p;
  }
};

}  // namespace

std::string snake(std::string_view in) {
  std::string name{in};
  for (std::size_t i = 0; (i = name.find("IDs", i)) != std::string::npos; i += 3)
    if (i + 3 == name.size() || upper(name[i + 3])) name.replace(i, 3, "Ids");
  std::string s;
  for (std::size_t i = 0; i < name.size(); ++i) {
    const char c = name[i];
    if (i > 0 && upper(c) &&
        (lower_or_digit(name[i - 1]) || (upper(name[i - 1]) && i + 1 < name.size() && name[i + 1] >= 'a' && name[i + 1] <= 'z')))
      s += '_';
    s += upper(c) ? char(c - 'A' + 'a') : c;
  }
  return s;
}

Output build(const orch::Repository& repo, const Options& opt, const std::string& source) {
  Builder b{repo, {}, {}, {}, {}, {}};
  b.out.ns = opt.ns;
  b.out.source = source;
  b.out.version = repo.version;
  b.out.dictionary = repo.name;
  // FIX 5.0 and later run over FIXT.1.1: 8=FIXT.1.1 on the wire, the version travels in ApplVerID(1128).
  const bool fixt = repo.name.starts_with("FIX.5") || repo.name.starts_with("FIX.Latest") || repo.name.starts_with("FIXT");
  b.out.begin_string = fixt ? "FIXT.1.1" : repo.name;
  static const std::map<std::string, std::string> appl_ver = {{"FIX.5.0", "7"}, {"FIX.5.0SP1", "8"}, {"FIX.5.0SP2", "9"}};
  if (auto it = appl_ver.find(repo.name); it != appl_ver.end()) b.out.appl_ver_id = it->second;
  for (const auto& [id, f] : repo.fields) {
    if (id > 65535) throw std::runtime_error(std::format("field {} has tag {} > 65535", f.name.value(), id));
    if (f.unionDataType && f.unionDataType->value().starts_with("Reserved") && repo.code_sets.contains(f.type.value()))
      b.open_code_sets.insert(f.type.value());
    b.out.tags.emplace_back(id, f.name.value());
    if (f.lengthId) b.out.length_data.emplace_back(f.lengthId->value(), id);
  }
  // The codec owns 8, 9, 35 and 10 (never members).
  b.out.header = b.session_part("StandardHeader", {8, 9, 35});
  b.out.trailer = b.session_part("StandardTrailer", {10});
  for (const auto& m : repo.messages) {
    if (!opt.msg_types.empty() && !opt.msg_types.contains(m.msg_type)) continue;
    Part p;
    p.kind = part_kind::message;
    p.id = m.id;
    p.fix_name = m.name;
    p.msg_type = m.msg_type;
    p.name = b.unique_type_name(m.name, "Msg");
    std::set<std::int32_t> tags;
    b.flatten(m.refs, false, p, tags, {8, 9, 35, 10}, true);
    b.finish(p);
    b.out.messages.push_back(std::move(p));
  }
  if (!opt.msg_types.empty() && b.out.messages.size() != opt.msg_types.size())
    throw std::runtime_error("some requested MsgTypes are not in the file");
  return std::move(b.out);
}

}  // namespace gen
