// Glaze Library
// For the license information refer to glaze.hpp

// Micro-benchmark for glz::fix::scan: field splitting + checksum over a ~200-byte NewOrderSingle.
//   g++ -std=c++23 -O2 -Iinclude tests/fix_test/fix_scan_bench.cpp -o bench && ./bench

#include <chrono>
#include <cstdio>
#include <string>

#include "glaze/fix/scan.hpp"

int main()
{
   std::string msg =
      "8=FIX.4.4\x01"
      "9=178\x01"
      "35=D\x01"
      "34=215\x01"
      "49=SENDERCOMPID\x01"
      "52=20240101-12:00:00.000\x01"
      "56=TARGETCOMPID\x01"
      "11=ORD1234567890\x01"
      "1=ACCOUNT01\x01"
      "21=1\x01"
      "38=1000\x01"
      "40=2\x01"
      "44=123.45\x01"
      "54=1\x01"
      "55=MSFT\x01"
      "59=0\x01"
      "60=20240101-12:00:00.000\x01"
      "10=000\x01";
   constexpr int iters = 2'000'000;
   uint64_t sink = 0;
   const auto t0 = std::chrono::steady_clock::now();
   for (int i = 0; i < iters; ++i) {
      glz::fix::field_cursor c{msg};
      for (glz::fix::field f; c.next(f);) {
         sink += f.tag + f.value.size();
      }
      sink += glz::fix::checksum(std::string_view{msg}.substr(0, msg.size() - 7));
      msg[20] = char('0' + (i & 7)); // defeat hoisting
   }
   const auto t1 = std::chrono::steady_clock::now();
   const double ns = double(std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()) / iters;
   std::printf("fix scan: %.1f ns/message (%zu bytes, sink=%llu)\n", ns, msg.size(), (unsigned long long)sink);
   return 0;
}
