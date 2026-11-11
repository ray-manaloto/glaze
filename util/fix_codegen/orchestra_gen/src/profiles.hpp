// Partner profiles (stage 3): per-gateway write settings, read from JSON and emitted as constexpr types.
// A codec is instantiated once per profile; the session picks the instantiation by name once, at logon,
// so encoding has no runtime branch on the settings.
#pragma once
#include "orchestra.hpp"

#include <filesystem>
#include <string>

namespace gen {
// Reads every DIR/*.json (sorted by file name), checks each field name against the dictionary, and
// returns <ns>_profiles.hpp. Throws with the file and the problem on any error.
std::string emit_profiles(const orch::Repository& repo, const std::string& ns, const std::string& source,
                          const std::filesystem::path& dir);
}  // namespace gen
