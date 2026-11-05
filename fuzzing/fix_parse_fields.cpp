// FIX tag=value: the low-level scanner must never read out of bounds, and every field it returns
// must be a view inside the input whose bytes do not include the delimiter (unless it is a
// Length-prefixed data field).
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

   auto fields = glz::fix::parse_fields(input, soh);
   if (fields) {
      size_t consumed = 0;
      for (const auto& f : *fields) {
         if (f.tag == 0) std::abort();
         if (f.value.empty()) std::abort();
         if (f.value.data() < input.data() || f.value.data() + f.value.size() > input.data() + input.size()) {
            std::abort();
         }
         consumed = size_t(f.value.data() - input.data()) + f.value.size() + 1;
      }
      // A successful scan accounts for every byte.
      if (consumed != input.size()) std::abort();
   }
   return 0;
}
