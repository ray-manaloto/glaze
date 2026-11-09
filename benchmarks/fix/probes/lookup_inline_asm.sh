#!/bin/bash
# Disassemble the timed loop itself: the same -O2 build as tag_lookup_mac.sh (find_idx inlined) plus -g,
# objdump of main with source lines, cut from the timed loop line (found by grep) to the line after it.
# Loop text laid out after that line (cold blocks) is not captured. Prints instructions in that loop split by source line: lookup (the find_idx line) vs loop overhead.
# Usage: lookup_inline_asm.sh <libs dir> <out dir>   Env: GCC, CLANG, P2996, OBJDUMP.
set -u
# libc++ hardening is set explicitly: the p2996 libc++ defaults to EXTENSIVE, Homebrew LLVM to NONE.
L=$(cd "$1" && pwd) || exit 2; mkdir -p "$2" && O=$(cd "$2" && pwd) || exit 2; cd "$(dirname "$0")"; fail=0   # resolve paths before cd
GCC=${GCC:-g++-16}; CLANG=${CLANG:-/opt/homebrew/opt/llvm/bin/clang++}; P2996=${P2996:-clang++-p2996}
OBJDUMP=${OBJDUMP:-/opt/homebrew/opt/llvm/bin/llvm-objdump}
INC=(-I"$L/mph" -I"$L/compile-time-init-build/include" -I"$L/stdx/include" -I"$L/perfect_hash/include" -I"$L/frozen/include" -I/opt/homebrew/include)
loop=$(grep -n 'for (int rep = 0; rep < 200' tag_lookup_mac.cpp | cut -d: -f1); after=$((loop + 1))
printf "%-6s %-7s %6s %7s %6s %9s %s\n" compiler method insns lookup loop branches "other lines (inlined library code)"
for c in gcc clang p2996; do
  case $c in gcc) CX=("$GCC" -fconstexpr-ops-limit=4000000000);; clang) CX=("$CLANG" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);; p2996) CX=("$P2996" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);; esac
  for m in LINEAR SORTED DIRECT HAND MPH CIB FROZEN; do
    o=$O/${c}_$m.o
    "${CX[@]}" -std=c++26 -O2 -g -DNDEBUG -fno-exceptions -fno-rtti -D M_$m "${INC[@]}" -c tag_lookup_mac.cpp -o "$o" 2>/dev/null || { echo "$c $m BUILD FAILED"; fail=1; continue; }
    line=$(grep -n "M_$m\b" tag_lookup_mac.cpp | head -1 | cut -d: -f1)   # find_idx sits a few lines below its #if
    "$OBJDUMP" -d -l --no-show-raw-insn --disassemble-symbols=_main "$o" \
      | awk -v a="$loop" -v z="$after" '
          /^; .*:[0-9]+$/ { n=$0; sub(/.*\//,"",n); split(n,p,":"); f=p[1]; ln=p[2]+0;
                            if (f=="tag_lookup_mac.cpp" && ln==a) on=1; if (on && f=="tag_lookup_mac.cpp" && ln==z) exit; next }
          on && /^[[:space:]]*[0-9a-f]+:/ { sub(/^[[:space:]]*[0-9a-f]+:[[:space:]]*/,""); print f ":" ln "\t" $0 }' > "$O/${c}_$m.loop.s"
    awk -F'\t' -v c="$c" -v m="$m" -v a="$loop" -v lo="$line" '
      { n++; split($1,p,":"); if (p[1]=="tag_lookup_mac.cpp" && p[2]==a) l++; else if (p[1]=="tag_lookup_mac.cpp" && p[2]>lo && p[2]<lo+20) k++; else o[$1]++
        if ($2 ~ /^(b|b\.[a-z]+|cbn?z|tbn?z|ret|br|blr?)$/) br++; if ($2=="bl") call=1 }
      END { s=""; for (x in o) s=s x "=" o[x] " "; if (call) s="CALLS find_idx (not inlined) " s
            printf "%-6s %-7s %6d %7d %6d %9d %s\n", c, m, n, k, l, br, s }' "$O/${c}_$m.loop.s"
    if grep -q $'\tbl\t' "$O/${c}_$m.loop.s"; then   # keep the out-of-line callee next to the loop
      sym=$("${OBJDUMP%objdump}nm" "$o" | awk '/find_idx/{print $3; exit}')
      "$OBJDUMP" -d -l --no-show-raw-insn --disassemble-symbols="$sym" "$o" > "$O/${c}_$m.callee.s"
      echo "       callee $sym: $(grep -cE '^[[:space:]]*[0-9a-f]+:' "$O/${c}_$m.callee.s") instructions (see ${c}_$m.callee.s)"
    fi
  done
done
exit $fail
