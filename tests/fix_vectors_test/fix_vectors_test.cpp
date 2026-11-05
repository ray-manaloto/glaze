// Glaze Library
// For the license information refer to glaze.hpp

// Data-driven FIX tag=value tests. Every data/*.fixv file (format: data/FORMAT.md) is loaded and each
// vector is run against the shared glz::fix API. Vector provenance is listed in data/SOURCES.md.

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "ut/ut.hpp"

using namespace ut;

namespace
{
   struct vector_case
   {
      std::string file{};
      std::map<std::string, std::string> kv{};

      std::string get(const std::string& k) const
      {
         auto it = kv.find(k);
         return it == kv.end() ? std::string{} : it->second;
      }
      bool has(const std::string& k) const { return kv.contains(k); }
   };

   std::string to_soh(std::string s)
   {
      std::replace(s.begin(), s.end(), '|', '\x01');
      return s;
   }

   std::vector<vector_case> load_all(std::vector<std::string>& load_errors)
   {
      std::vector<std::filesystem::path> files{};
      std::error_code ec{};
      for (const auto& entry : std::filesystem::directory_iterator(GLZ_FIX_VECTORS_DIR, ec)) {
         if (entry.path().extension() == ".fixv") files.push_back(entry.path());
      }
      if (ec) load_errors.push_back("cannot list " GLZ_FIX_VECTORS_DIR);
      std::sort(files.begin(), files.end());

      std::vector<vector_case> out{};
      for (const auto& path : files) {
         std::ifstream in(path, std::ios::binary);
         if (!in) {
            load_errors.push_back("cannot open " + path.string());
            continue;
         }
         vector_case cur{path.filename().string(), {}};
         auto flush = [&] {
            if (!cur.kv.empty()) out.push_back(cur);
            cur.kv.clear();
         };
         std::string line{};
         size_t line_no = 0;
         while (std::getline(in, line)) {
            ++line_no;
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (line.empty()) {
               flush();
               continue;
            }
            if (line[0] == '#') continue;
            const auto pos = line.find(" = ");
            if (pos == std::string::npos) {
               load_errors.push_back(cur.file + ":" + std::to_string(line_no) + ": expected 'key = value'");
               continue;
            }
            auto key = line.substr(0, pos);
            if (cur.kv.contains(key)) {
               load_errors.push_back(cur.file + ":" + std::to_string(line_no) + ": duplicate key " + key);
            }
            cur.kv[key] = line.substr(pos + 3);
         }
         flush();
      }
      return out;
   }

   size_t to_size(const std::string& s)
   {
      size_t v = 0;
      for (const char c : s) {
         if (c < '0' || c > '9') return size_t(-1);
         v = v * 10 + size_t(c - '0');
      }
      return s.empty() ? size_t(-1) : v;
   }

   void run_case(const vector_case& v)
   {
      const auto kind = v.get("kind");
      const auto id = v.get("id");
      if (kind == "parse") {
         const auto msg = to_soh(v.get("msg"));
         const auto res = glz::fix::parse_fields(msg, '\x01');
         if (v.get("expect") == "error") {
            expect(!res.has_value()) << id << ": expected a parse error";
            return;
         }
         expect(res.has_value()) << id << ": unexpected parse error";
         if (!res) return;
         if (v.has("count")) {
            expect(res->size() == to_size(v.get("count"))) << id << ": field count " << res->size();
         }
         if (v.has("fields")) {
            const auto want_text = to_soh(v.get("fields")); // the views in `want` point into this
            const auto want = glz::fix::parse_fields(want_text, '\x01');
            expect(want.has_value()) << id << ": malformed 'fields' in vector";
            if (!want) return;
            expect(want->size() == res->size()) << id << ": field count " << res->size();
            for (size_t i = 0; i < std::min(want->size(), res->size()); ++i) {
               expect((*want)[i].tag == (*res)[i].tag && (*want)[i].value == (*res)[i].value)
                  << id << ": field " << i << " is " << (*res)[i].tag << "=" << std::string((*res)[i].value);
            }
         }
      }
      else if (kind == "validate") {
         const auto msg = to_soh(v.get("msg"));
         const auto err = glz::fix::validate(msg, '\x01');
         if (v.get("expect") == "error") {
            expect(bool(err)) << id << ": expected a validation error";
         }
         else {
            expect(!err) << id << ": unexpected validation error: " << err.custom_error_message;
         }
      }
      else if (kind == "frame") {
         const auto stream = to_soh(v.get("stream"));
         const auto n = glz::fix::frame(stream, '\x01');
         expect(n == to_size(v.get("frame_len"))) << id << ": frame returned " << n;
      }
      else if (kind == "checksum") {
         const auto bytes = to_soh(v.get("bytes"));
         const auto cs = glz::fix::checksum(bytes);
         expect(size_t(cs) == to_size(v.get("value"))) << id << ": checksum " << size_t(cs);
      }
      else {
         expect(false) << id << ": unknown kind '" << kind << "'";
      }
   }
}

int main()
{
   std::vector<std::string> load_errors{};
   const auto cases = load_all(load_errors);

   "vector files load"_test = [&] {
      for (const auto& e : load_errors) expect(false) << e;
      expect(cases.size() > 0) << "no vectors found in " GLZ_FIX_VECTORS_DIR;
   };

   "vector metadata"_test = [&] {
      std::set<std::string> ids{};
      for (const auto& v : cases) {
         expect(v.has("id") && v.has("source") && v.has("kind")) << v.file << ": vector missing id/source/kind";
         expect(ids.insert(v.get("id")).second) << v.file << ": duplicate id " << v.get("id");
      }
   };

   for (const auto& v : cases) {
      // ids are stored in `cases`, which outlives the runner calls below.
      const auto it = v.kv.find("id");
      if (it == v.kv.end()) continue;
      if (v.has("pending")) {
         // Outcome depends on an open API-contract question (see docs/fix/api-questions.md); listed, not asserted.
         std::clog << "pending: " << it->second << " -- " << v.get("pending") << "\n";
         continue;
      }
      ut::test(it->second) = [&v] { run_case(v); };
   }

   return 0;
}
