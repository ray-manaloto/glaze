#!/usr/bin/env python3
# Glaze Library
# For the license information refer to glaze.hpp
"""Generate header-only C++ FIX dictionary types for glaze from FIX Orchestra XML.

Input: an Orchestra repository file published by the FIX Trading Community, e.g.
OrchestraFIX42.xml, OrchestraFIX44.xml or OrchestraFIXLatest.xml from
https://github.com/FIXTradingCommunity/orchestrations ("FIX Standard" directory,
Apache License 2.0).

Output: one header holding
  * tag number constants        (namespace <ns>::tag)
  * enum class per code set     (with glz::meta: glz::enumerate names + fix_values wire strings)
  * a struct per repeating group, per component and per message, each with a glz::meta
    that maps FIX tag numbers (as strings) to members, as described in docs/fix/api.md.

Components are flattened into the structs that use them (FIX tag=value has no
component boundary on the wire). Repeating groups become std::vector<Group> members keyed
by their NumInGroup tag. Optional fields become std::optional<T>. StandardHeader and
StandardTrailer are omitted from messages: the FIX writer fills 8, 9, 35 and 10 itself.

Python 3 standard library only.

Usage:
  fix_codegen.py --xml OrchestraFIX44.xml --namespace fix44 --out include/glaze/fix/dict/fix44.hpp
"""

from __future__ import annotations

import argparse
import re
import sys
import xml.etree.ElementTree as ET

NS = {"fixr": "http://fixprotocol.io/2020/orchestra/repository"}
F = "{http://fixprotocol.io/2020/orchestra/repository}"

INT_TYPES = {"int", "Length", "SeqNum", "TagNum", "DayOfMonth", "NumInGroup"}
FLOAT_TYPES = {"float", "Price", "Qty", "Amt", "Percentage", "PriceOffset"}
MULTI_TYPES = {"MultipleValueString", "MultipleCharValue", "MultipleStringValue"}

CPP_KEYWORDS = set(
    """alignas alignof and and_eq asm auto bitand bitor bool break case catch char char8_t char16_t
    char32_t class compl concept const consteval constexpr constinit const_cast continue co_await
    co_return co_yield decltype default delete do double dynamic_cast else enum explicit export
    extern false float for friend goto if inline int long mutable namespace new noexcept not not_eq
    nullptr operator or or_eq private protected public register reinterpret_cast requires return
    short signed sizeof static static_assert static_cast struct switch template this thread_local
    throw true try typedef typeid typename union unsigned using virtual void volatile wchar_t while
    xor xor_eq""".split()
)


def snake(name: str) -> str:
    name = re.sub(r"IDs(?=[A-Z]|$)", "Ids", name)
    s = re.sub(r"(?<=[a-z0-9])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])", "_", name)
    s = re.sub(r"[^0-9A-Za-z_]", "_", s).lower()
    if not s or s[0].isdigit():
        s = "f_" + s
    if s in CPP_KEYWORDS:
        s += "_"
    return s


def ident(name: str) -> str:
    s = re.sub(r"[^0-9A-Za-z_]", "_", name)
    if not s or s[0].isdigit():
        s = "_" + s
    if s in CPP_KEYWORDS or s == "NULL":
        s += "_"
    return s


def cpp_char(c: str) -> str:
    if c == "'":
        return "'\\''"
    if c == "\\":
        return "'\\\\'"
    return f"'{c}'"


def cpp_str(s: str) -> str:
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


class Repo:
    def __init__(self, path: str):
        root = ET.parse(path).getroot()
        self.name = root.get("name", "")
        self.version = root.get("version", "")
        self.codesets = {}  # name -> (type, [(name, value)])
        for cs in root.iter(F + "codeSet"):
            codes = [(c.get("name"), c.get("value")) for c in cs.findall(F + "code")]
            self.codesets[cs.get("name")] = (cs.get("type"), codes)
        self.fields = {}  # id -> (name, type)
        for f in root.iter(F + "field"):
            self.fields[int(f.get("id"))] = (f.get("name"), f.get("type"))
        self.components = {}  # id -> (name, element)
        for c in root.iter(F + "component"):
            self.components[int(c.get("id"))] = (c.get("name"), c)
        self.groups = {}  # id -> (name, numInGroup tag, element)
        for g in root.iter(F + "group"):
            nig = g.find(F + "numInGroup")
            self.groups[int(g.get("id"))] = (g.get("name"), int(nig.get("id")), g)
        self.messages = []  # (name, msgType, structure element)
        for m in root.iter(F + "message"):
            # Orchestra may hold several scenarios of one message; keep the base scenario only.
            if m.get("scenario", "base") != "base":
                continue
            self.messages.append((m.get("name"), m.get("msgType"), m.find(F + "structure")))


class Gen:
    def __init__(self, repo: Repo, ns: str):
        self.r = repo
        self.ns = ns
        self.used_names: set[str] = set()
        self.enum_names: dict[str, str] = {}  # codeset name -> C++ enum name
        self.enum_kind: dict[str, str] = {}  # codeset name -> char|int|string|multi
        self.group_structs: dict[int, str] = {}
        self.out_groups: list[str] = []
        self.skip_components = {
            cid for cid, (n, _) in repo.components.items() if n in ("StandardHeader", "StandardTrailer")
        }

    def unique(self, base: str) -> str:
        name = ident(base)
        n = name
        i = 2
        while n in self.used_names:
            n = f"{name}{i}"
            i += 1
        self.used_names.add(n)
        return n

    # ---- enums --------------------------------------------------------------------------------
    def build_enums(self) -> list[str]:
        used_cs = set()
        for _, t in self.r.fields.values():
            if t in self.r.codesets:
                used_cs.add(t)
        out = []
        for cs_name in sorted(used_cs):
            cs_type, codes = self.r.codesets[cs_name]
            if not codes:
                continue
            base = cs_name[: -len("CodeSet")] if cs_name.endswith("CodeSet") else cs_name
            ename = self.unique(base)
            self.enum_names[cs_name] = ename
            values = [v for _, v in codes]
            if cs_type in MULTI_TYPES:
                kind = "multi"
            elif cs_type == "char" and all(len(v) == 1 for v in values):
                kind = "char"
            elif cs_type in INT_TYPES and all(re.fullmatch(r"-?\d+", v) for v in values):
                kind = "int"
            else:
                kind = "string"
            self.enum_kind[cs_name] = kind
            seen = set()
            items = []
            for cname, v in codes:
                en = ident(cname)
                while en in seen:
                    en += "_"
                seen.add(en)
                items.append((en, v))
            underlying = {"char": "char", "int": "int32_t"}.get(kind, "uint16_t")
            out.append(f"   // {cs_name} ({cs_type})")
            out.append(f"   enum class {ename} : {underlying} {{")
            for i, (en, v) in enumerate(items):
                if kind == "char":
                    out.append(f"      {en} = {cpp_char(v)},")
                elif kind == "int":
                    out.append(f"      {en} = {int(v)},")
                else:
                    out.append(f"      {en} = {i},")
            out.append("   };")
            self.enum_items = getattr(self, "enum_items", {})
            self.enum_items[ename] = items
        return out

    def enum_metas(self) -> list[str]:
        out = []
        for ename, items in self.enum_items.items():
            full = f"glz::fix::{self.ns}::{ename}"
            out.append("template <>")
            out.append(f"struct glz::meta<{full}>")
            out.append("{")
            out.append(f"   using enum {full};")
            out.append("   static constexpr auto value = glz::enumerate(" + ", ".join(e for e, _ in items) + ");")
            out.append(
                f"   static constexpr std::array<std::string_view, {len(items)}> fix_values{{"
                + ", ".join(cpp_str(v) for _, v in items)
                + "};"
            )
            out.append("};")
        return out

    # ---- member types -------------------------------------------------------------------------
    def field_type(self, fid: int) -> str:
        _, t = self.r.fields[fid]
        if t in self.r.codesets and t in self.enum_names:
            if self.enum_kind[t] == "multi":
                return "std::string"
            return self.enum_names[t]
        if t in INT_TYPES:
            return "int64_t"
        if t in FLOAT_TYPES:
            return "double"
        if t == "char":
            return "char"
        if t == "Boolean":
            return "bool"
        return "std::string"

    # ---- structure flattening -----------------------------------------------------------------
    def collect(self, elem, members, seen_tags, required_ctx=True):
        """Flatten an Orchestra structure into [(kind, tag, cpp_type, name, required)]."""
        for child in elem:
            tagname = child.tag.replace(F, "")
            req = child.get("presence") == "required" and required_ctx
            if tagname == "fieldRef":
                fid = int(child.get("id"))
                if fid in seen_tags or fid not in self.r.fields:
                    continue
                seen_tags.add(fid)
                members.append(("field", fid, self.field_type(fid), snake(self.r.fields[fid][0]), req))
            elif tagname == "componentRef":
                cid = int(child.get("id"))
                if cid in self.skip_components or cid not in self.r.components:
                    continue
                self.collect(self.r.components[cid][1], members, seen_tags, req)
            elif tagname == "groupRef":
                gid = int(child.get("id"))
                if gid not in self.r.groups:
                    continue
                gname, nig, _ = self.r.groups[gid]
                if nig in seen_tags:
                    continue
                seen_tags.add(nig)
                sname = self.group_struct(gid)
                members.append(("group", nig, f"std::vector<{sname}>", snake(self.r.fields[nig][0]), False))
        return members

    def group_struct(self, gid: int) -> str:
        if gid in self.group_structs:
            return self.group_structs[gid]
        gname, nig, elem = self.r.groups[gid]
        sname = self.unique(gname + "Grp" if not gname.endswith("Grp") else gname)
        self.group_structs[gid] = sname  # register before recursing (nested groups)
        members = self.collect([c for c in elem if c.tag != F + "numInGroup"], [], set())
        self.out_groups.append(self.emit_struct(sname, members, None))
        return sname

    def emit_struct(self, sname, members, msg_type):
        lines = [f"   struct {sname}", "   {"]
        names = set()
        fixed = []
        for kind, tag, ctype, mname, req in members:
            while mname in names:
                mname += "_"
            names.add(mname)
            fixed.append((kind, tag, ctype, mname, req))
            if kind == "group" or req:
                lines.append(f"      {ctype} {mname}{{}};")
            else:
                lines.append(f"      std::optional<{ctype}> {mname}{{}};")
        lines.append("   };")
        self.metas.append((sname, fixed, msg_type))
        return "\n".join(lines)

    def meta_for(self, sname, members, msg_type) -> list[str]:
        full = f"glz::fix::{self.ns}::{sname}"
        out = ["template <>", f"struct glz::meta<{full}>", "{", f"   using T = {full};"]
        if msg_type is not None:
            out.append(f"   static constexpr std::string_view fix_msg_type = {cpp_str(msg_type)};")
        if members:
            pairs = ", ".join(f'"{tag}", &T::{m}' for _, tag, _, m, _ in members)
            out.append(f"   static constexpr auto value = glz::object({pairs});")
        else:
            out.append("   static constexpr auto value = glz::object();")
        out.append("};")
        return out

    def run(self) -> str:
        self.metas = []
        enums = self.build_enums()
        comps = []
        for cid, (cname, elem) in sorted(self.r.components.items()):
            if cid in self.skip_components:
                continue
            members = self.collect(elem, [], set())
            comps.append(self.emit_struct(self.unique(cname), members, None))
        msgs = []
        for mname, mtype, structure in self.r.messages:
            if structure is None:
                continue
            members = self.collect(structure, [], set())
            msgs.append(self.emit_struct(self.unique(mname), members, mtype))

        o = []
        o.append("// Glaze Library")
        o.append("// For the license information refer to glaze.hpp")
        o.append("//")
        o.append("// GENERATED FILE - do not edit. Produced by util/fix_codegen/fix_codegen.py from the")
        o.append(f"// FIX Orchestra repository file for {self.r.name} (version {self.r.version}).")
        o.append("// Source data: https://github.com/FIXTradingCommunity/orchestrations")
        o.append("// Copyright (c) FIX Protocol Ltd., licensed under the Apache License, Version 2.0;")
        o.append("// see LICENSE-FIX-ORCHESTRA beside this file.")
        o.append("")
        o.append("#pragma once")
        o.append("")
        o.append("#include <array>")
        o.append("#include <cstdint>")
        o.append("#include <optional>")
        o.append("#include <string>")
        o.append("#include <string_view>")
        o.append("#include <vector>")
        o.append("")
        o.append('#include "glaze/core/common.hpp"')
        o.append("")
        o.append(f"namespace glz::fix::{self.ns}")
        o.append("{")
        o.append(f"   inline constexpr std::string_view begin_string = {cpp_str(self.r.name)};")
        o.append("")
        o.append("   namespace tag")
        o.append("   {")
        tag_names = set()
        for fid, (fname, _) in sorted(self.r.fields.items()):
            n = ident(fname)
            if n in tag_names:
                continue
            tag_names.add(n)
            o.append(f"      inline constexpr uint32_t {n} = {fid};")
        o.append("   }")
        o.append("")
        o.extend(enums)
        o.append("")
        o.append("   // ---- repeating groups ----")
        o.extend(self.out_groups)
        o.append("")
        o.append("   // ---- components (flattened) ----")
        o.extend(comps)
        o.append("")
        o.append("   // ---- messages ----")
        o.extend(msgs)
        o.append("}")
        o.append("")
        o.extend(self.enum_metas())
        o.append("")
        for sname, members, mt in self.metas:
            o.extend(self.meta_for(sname, members, mt))
        o.append("")
        return "\n".join(o)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--xml", required=True, help="Orchestra repository XML file")
    ap.add_argument("--namespace", required=True, help="C++ namespace under glz::fix, e.g. fix44")
    ap.add_argument("--out", required=True, help="output header path")
    a = ap.parse_args(argv)
    text = Gen(Repo(a.xml), a.namespace).run()
    with open(a.out, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
