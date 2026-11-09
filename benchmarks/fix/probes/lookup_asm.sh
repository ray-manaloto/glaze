#!/bin/bash
# Disassemble each tag-lookup method's find_idx (built with -DLOOKUP_ASM so it is not inlined) and model it
# with llvm-mca for Apple M2. Usage: lookup_asm.sh <libs dir> <out dir>   Env: GCC, CLANG, P2996, MCA, OBJDUMP.
set -u
# libc++ hardening is set explicitly: the p2996 libc++ defaults to EXTENSIVE, Homebrew LLVM to NONE.
L=$(cd "$1" && pwd) || exit 2; mkdir -p "$2" && O=$(cd "$2" && pwd) || exit 2; cd "$(dirname "$0")"; fail=0   # resolve paths before cd
GCC=${GCC:-g++-16}; CLANG=${CLANG:-/opt/homebrew/opt/llvm/bin/clang++}; P2996=${P2996:-clang++-p2996}
MCA=${MCA:-/opt/homebrew/opt/llvm/bin/llvm-mca}; OBJDUMP=${OBJDUMP:-/opt/homebrew/opt/llvm/bin/llvm-objdump}
INC=(-I"$L/mph" -I"$L/compile-time-init-build/include" -I"$L/stdx/include" -I"$L/perfect_hash/include" -I"$L/frozen/include" -I/opt/homebrew/include)
printf "%-6s %-7s %6s %6s %8s %10s\n" compiler method insns bytes branches mca_rthru
for c in gcc clang p2996; do
  case $c in gcc) CX=("$GCC" -fconstexpr-ops-limit=4000000000);; clang) CX=("$CLANG" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);; p2996) CX=("$P2996" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);; esac
  for m in LINEAR SORTED DIRECT HAND MPH CIB FROZEN; do
    o=$O/${c}_$m.o
    "${CX[@]}" -std=c++26 -O2 -DNDEBUG -fno-exceptions -fno-rtti -DLOOKUP_ASM -D M_$m "${INC[@]}" -c tag_lookup_mac.cpp -o "$o" 2>/dev/null || { echo "$c $m BUILD FAILED"; fail=1; continue; }
    "$OBJDUMP" -d --no-show-raw-insn --no-leading-addr --disassemble-symbols=_find_idx "$o" | awk 'NF && !/:$/ && !/file format/ && !/Disassembly/' > "$O/${c}_$m.s"
    n=$(wc -l < "$O/${c}_$m.s" | tr -d ' ')
    br=$(grep -cE '^\s*(b|b\.[a-z]+|cbn?z|tbn?z|ret|br|blr?)\s' "$O/${c}_$m.s")
    bytes=$((n * 4))
    # llvm-mca needs assemblable text: branch targets and adrp pages become one label; ret is dropped.
    # It models the whole function as one straight-line block (both branch paths), so read it as an upper bound.
    rt=$( (echo "Ltgt:"; sed -E 's/^[[:space:]]+//; s/;.*$//; s/^(adrp[[:space:]]+[a-z0-9]+,)[[:space:]]*0x[0-9a-f]+ <[^>]*>/\1 Ltgt@PAGE/; s/0x[0-9a-f]+ <[^>]*>/Ltgt/g' "$O/${c}_$m.s" | grep -v '^ret') \
         | "$MCA" -mtriple=arm64-apple-macos -mcpu=apple-m2 -iterations=100 2>/dev/null | awk '/Block RThroughput/{print $3}')
    printf "%-6s %-7s %6s %6s %8s %10s\n" "$c" "$m" "$n" "$bytes" "$br" "${rt:-n/a}"
  done
done
exit $fail
