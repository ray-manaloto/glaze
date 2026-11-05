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
   if (n > input.size()) std::abort();
   if (!ec) {
      if (n != input.size()) std::abort();
      const auto pos = input.size() - 7;
      const unsigned declared =
         unsigned(input[pos + 3] - '0') * 100 + unsigned(input[pos + 4] - '0') * 10 + unsigned(input[pos + 5] - '0');
      if (declared != glz::fix::checksum(input.substr(0, pos))) std::abort();
   }
   return 0;
}
