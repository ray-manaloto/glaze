// FIX tag=value: validate() and frame() on arbitrary bytes. When validate() accepts a message,
// frame() must find exactly that message, and the checksum must agree with the trailer.
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <glaze/fix/fix.hpp>
#include <string_view>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
   if (Size < 1) return 0;
   const char soh = (Data[0] & 1) ? '|' : '\x01';
   const std::string_view input{reinterpret_cast<const char*>(Data + 1), Size - 1};

   const auto ec = glz::fix::validate(input, soh);
   const size_t n = glz::fix::frame(input, soh);
   if (n != glz::fix::frame_error && n > input.size()) std::abort();
   if (!ec) {
#if !defined(GLZ_FIX_KNOWN_GAPS) || !GLZ_FIX_KNOWN_GAPS
      // Known fix/core gap 2 (docs/fix/sessions/fix-conformance-fuzz.md): validate reads a
      // zero-padded tag such as "010=" as CheckSum while frame does not. Skip it so the fuzzer
      // keeps looking for other bugs; regression input: fuzzing/regressions/fix_validate/.
      if (input.size() >= 7 && input.substr(input.size() - 7, 3) != "10=") return 0;
      if (input.size() >= 8 && input[input.size() - 8] != soh) return 0;
      // Same gap for the header: "08=" / "09=" read as BeginString / BodyLength.
      if (!input.starts_with("8=")) return 0;
      if (const auto e = input.find(soh); e == std::string_view::npos || input.substr(e + 1, 2) != "9=") return 0;
#endif
      if (n != input.size()) std::abort();
      const auto pos = input.size() - 7;
      const unsigned declared =
         unsigned(input[pos + 3] - '0') * 100 + unsigned(input[pos + 4] - '0') * 10 + unsigned(input[pos + 5] - '0');
      if (declared != glz::fix::checksum(input.substr(0, pos))) std::abort();
   }
   return 0;
}
