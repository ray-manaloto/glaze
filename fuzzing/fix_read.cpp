// FIX tag=value: glz::read<fix_opts> into a mapped struct. A successful read must write back to
// a message that validates and reads back to the same values.
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <glaze/fix/fix.hpp>
#include <string>
#include <string_view>

struct fuzz_order
{
   std::string cl_ord_id{};
   std::string symbol{};
   char side{'1'};
   int64_t qty{};
   double price{};
   bool flag{};
   uint32_t seq{};
};

template <>
struct glz::meta<fuzz_order>
{
   using T = fuzz_order;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "55", &T::symbol, "54", &T::side, "38", &T::qty,
                                             "44", &T::price, "114", &T::flag, "34", &T::seq);
};

template <glz::fix_opts Opts>
static void run(std::string_view input)
{
   fuzz_order obj{};
   if (glz::read<Opts>(obj, input)) return;
   if (obj.price != obj.price) return; // NaN cannot come from FIX text, but stay safe
   std::string out;
   if (glz::write<Opts>(obj, out)) {
      // Only strings holding the delimiter cannot be written, and the reader never yields those.
      std::abort();
   }
   if (glz::fix::validate(out, Opts.soh)) std::abort();
   fuzz_order again{};
   if (glz::read<Opts>(again, out)) std::abort();
   if (again.cl_ord_id != obj.cl_ord_id || again.symbol != obj.symbol || again.side != obj.side ||
       again.qty != obj.qty || again.price != obj.price || again.flag != obj.flag || again.seq != obj.seq) {
      std::abort();
   }
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
   if (Size < 1) return 0;
   const uint8_t mode = Data[0];
   const std::string_view input{reinterpret_cast<const char*>(Data + 1), Size - 1};
   constexpr glz::fix_opts soh_strict{{.error_on_unknown_keys = false}};
   constexpr glz::fix_opts pipe_lax{{.error_on_unknown_keys = false}, glz::FIX, '|', false, false};
   if (mode & 1) {
      run<pipe_lax>(input);
   }
   else {
      run<soh_strict>(input);
   }
   return 0;
}
