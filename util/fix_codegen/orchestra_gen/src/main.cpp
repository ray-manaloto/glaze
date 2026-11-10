// orchestra_gen: FIX Orchestra XML -> glaze-fix 3-part structs (layout rules L1-L6).
//
//   orchestra_gen --xml OrchestraFIX44.xml --namespace fix44 --out DIR [--messages D,8,...]
//                 [--lock FILE [--update-lock]]
//
// Writes DIR/<ns>_enums.hpp, DIR/<ns>.hpp, DIR/<ns>.digest and DIR/<ns>_embed.cppm.
#include "emit.hpp"
#include "lock.hpp"
#include "model.hpp"
#include "orchestra.hpp"

#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <print>
#include <string>

namespace {

void write_file(const std::filesystem::path& p, const std::string& text) {
  std::ofstream f(p, std::ios::binary);
  f << text;
  if (!f) throw std::runtime_error("cannot write " + p.string());
}

int usage() {
  std::println(stderr, "usage: orchestra_gen --xml FILE --namespace NS --out DIR [--messages D,8,...] [--strict on] [--target gcc16|p2996|clang23] [--lock FILE [--update-lock]]");
  return 2;
}

}  // namespace

int main(int argc, char** argv) {
  std::string xml, out_dir, lock_path;
  bool update_lock = false;
  gen::Options opt;
  gen::target tgt = gen::target::gcc16;
  for (int i = 1; i < argc; ++i) {
    const std::string a = argv[i];
    if (a == "--update-lock") { update_lock = true; continue; }
    if (i + 1 >= argc) return usage();
    const std::string v = argv[++i];
    if (a == "--xml") xml = v;
    else if (a == "--namespace") opt.ns = v;
    else if (a == "--out") out_dir = v;
    else if (a == "--lock") lock_path = v;
    else if (a == "--strict") { opt.strict = v == "1" || v == "on"; }
    else if (a == "--target") {
      const auto t = gen::parse_target(v);
      if (!t) { std::println(stderr, "orchestra_gen: unknown --target '{}' (gcc16, p2996 or clang23)", v); return 2; }
      tgt = *t;
    }
    else if (a == "--messages") {
      for (std::size_t p = 0; p <= v.size();) {
        const auto c = v.find(',', p);
        opt.msg_types.insert(v.substr(p, c == std::string::npos ? std::string::npos : c - p));
        if (c == std::string::npos) break;
        p = c + 1;
      }
    } else return usage();
  }
  if (xml.empty() || opt.ns.empty() || out_dir.empty() || (update_lock && lock_path.empty())) return usage();

  try {
    const auto t0 = std::chrono::steady_clock::now();
    const auto repo = orch::load(xml);
    const auto t1 = std::chrono::steady_clock::now();
    auto o = gen::build(repo, opt, std::filesystem::path(xml).filename().string());
    // Stage 2: compare with the checked-in lock before writing anything. Without --update-lock, names already
    // in the lock are kept (a rename is only reported), and any other change is refused until reviewed.
    if (!lock_path.empty()) {
      std::string before;
      const bool exists = std::filesystem::exists(lock_path);
      if (std::ifstream f(lock_path, std::ios::binary); exists && f) before.assign(std::istreambuf_iterator<char>(f), {});
      else if (!update_lock) {
        std::println(stderr, "orchestra_gen: lock file {} not found (create it with --update-lock)", lock_path);
        return 1;
      }
      if (!update_lock)
        for (const auto& k : gen::apply_lock(o, before)) std::println("lock: {}", k);
      const auto now = gen::emit_lock(o);
      const auto changes = gen::diff_lock(before, now);
      if (exists)  // a new lock lists everything: report only its size
        for (const auto& c : changes) std::println(stderr, "lock: {}", c);
      if (!changes.empty() && !update_lock) {
        std::println(stderr, "orchestra_gen: {} change(s) against {}; nothing written. Review them, then rerun with --update-lock",
                     changes.size(), lock_path);
        return 1;
      }
      gen::check_unique_names(o);  // after the refusal, so refused changes are reported first
      if (update_lock && now != before) write_file(lock_path, now);
      std::println("lock {}: {}", lock_path,
                   !exists           ? std::format("created, {} items", changes.size())
                   : changes.empty() ? std::string("unchanged")
                                     : std::format("{} change(s) accepted", changes.size()));
    }
    std::filesystem::create_directories(out_dir);
    const std::filesystem::path d = out_dir;
    write_file(d / (opt.ns + "_enums.hpp"), gen::emit_enums(o));
    write_file(d / (opt.ns + ".hpp"), gen::emit_structs(o, tgt));
    write_file(d / (opt.ns + ".digest"), gen::emit_digest(o));
    write_file(d / (opt.ns + "_embed.cppm"), gen::emit_module(o));
    const auto t2 = std::chrono::steady_clock::now();
    using ms = std::chrono::milliseconds;
    std::println("{} {}: {} datatypes, {} codeSets, {} fields, {} components, {} groups, {} messages (counts checked)",
                 repo.name, repo.version, repo.datatypes.size(), repo.code_sets.size(), repo.fields.size(),
                 repo.components.size(), repo.groups.size(), repo.messages.size());
    std::println("emitted {} messages, {} group entries, {} enums; load {} ms, generate {} ms",
                 o.messages.size(), o.entries.size(), o.enums.size(),
                 std::chrono::duration_cast<ms>(t1 - t0).count(), std::chrono::duration_cast<ms>(t2 - t1).count());
    std::string notes;
    for (const auto& n : o.notes) notes += n + "\n";
    write_file(d / (opt.ns + ".notes"), notes);  // checked in with the output, so a new note shows in a diff
    std::println("{} notes written to {}", o.notes.size(), (d / (opt.ns + ".notes")).string());
    if (opt.strict && !o.notes.empty()) {
      std::println(stderr, "orchestra_gen: --strict on and {} notes (see {}.notes)", o.notes.size(), opt.ns);
      return 1;
    }
  } catch (const std::exception& e) {
    std::println(stderr, "orchestra_gen: {}", e.what());
    return 1;
  }
  return 0;
}
