#!/bin/bash
# Build and run the layout and reflect-cpp probes on the target compilers; exits non-zero if any step fails.
# Usage: run.sh <libs dir>   (libs dir holds mph, compile-time-init-build, stdx (cpp-std-extensions), mp11inc,
#                             frozen, perfect_hash, pugixml, reflect-cpp)
# Compilers: GCC=g++-16, P2996=clang++-p2996 (override with env vars). Print `$P2996 --version` with results.
set -u
L=$(cd "$1" && pwd) || exit 2; cd "$(dirname "$0")"; fail=0   # resolve the libs dir before cd
step() { "$@" || { echo "FAILED: $*" | cut -c1-200; fail=1; return 1; }; }
GCC=${GCC:-g++-16}; P2996=${P2996:-clang++-p2996}
G=("$GCC" -std=c++26 -freflection); C=("$P2996" -std=c++26 -freflection -fexpansion-statements -stdlib=libc++)
"$P2996" --version | head -1
STDX=(-I"$L/stdx/include" -I"$L/mp11inc")
for t in bitfield_reflection enum_char_bitfield; do
  for cx in G C; do eval "cmd=(\"\${$cx[@]}\")"; step "${cmd[@]}" -fno-exceptions -fno-rtti -Wall "${STDX[@]}" $t.cpp -o ${t}_$cx && step ./${t}_$cx; done
done
step "$GCC" -std=c++26 -O2 struct_size_options.cpp -o struct_size && step ./struct_size
RF=(-I"$L/reflect-cpp/include" -I"$L/pugixml/src" "$L/reflect-cpp/src/reflectcpp.cpp" "$L/reflect-cpp/src/reflectcpp_xml.cpp" "$L/pugixml/src/pugixml.cpp")
step "${G[@]}" -DREFLECTCPP_USE_CPP26_REFLECTION -O1 reflect_cpp_order.cpp "${RF[@]}" -o rfl_gcc && step ./rfl_gcc
step "$P2996" -std=c++26 -stdlib=libc++ -O1 reflect_cpp_order.cpp "${RF[@]}" -o rfl_p2996 && step ./rfl_p2996   # C++20 path; the C++26 backend crashes p2996
exit $fail
