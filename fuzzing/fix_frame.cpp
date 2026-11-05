// FIX tag=value: split an arbitrary byte stream with frame(). Every frame it reports must be
// within the stream and, for a prefix of a framed message, frame() must report incomplete.
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <glaze/fix/fix.hpp>
#include <string_view>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
   if (Size < 1) return 0;
   const char soh = (Data[0] & 1) ? '|' : '\x01';
   std::string_view rest{reinterpret_cast<const char*>(Data + 1), Size - 1};

   while (!rest.empty()) {
      const size_t n = glz::fix::frame(rest, soh);
      if (n == 0 || n == glz::fix::frame_error) break; // incomplete, or not a FIX message
      if (n > rest.size()) std::abort();
      // Any strict prefix of a frame is incomplete.
      if (const size_t p = glz::fix::frame(rest.substr(0, n - 1), soh); p != 0 && p != glz::fix::frame_error) {
         std::abort();
      }
      [[maybe_unused]] auto ec = glz::fix::validate(rest.substr(0, n), soh);
      rest.remove_prefix(n);
   }
   return 0;
}
