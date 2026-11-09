#!/bin/bash
# Tag-lookup benchmark on the three Mac compilers, best of N runs per method.
# Usage: tag_lookup_mac.sh <libs dir> [runs]   (libs: mph (patched), compile-time-init-build, stdx, perfect_hash, frozen)
# Compilers: GCC=g++-16, CLANG=Homebrew clang++, P2996=clang++-p2996 (override with env vars).
set -u
# libc++ hardening is set explicitly: the p2996 libc++ defaults to EXTENSIVE, Homebrew LLVM to NONE.
L=$(cd "$1" && pwd) || exit 2; N=${2:-5}; cd "$(dirname "$0")"; fail=0   # resolve paths before cd
GCC=${GCC:-g++-16}; CLANG=${CLANG:-/opt/homebrew/opt/llvm/bin/clang++}; P2996=${P2996:-clang++-p2996}
INC=(-I"$L/mph" -I"$L/compile-time-init-build/include" -I"$L/stdx/include" -I"$L/perfect_hash/include" -I"$L/frozen/include" -I/opt/homebrew/include)
for c in gcc clang p2996; do
  case $c in
    gcc)   CX=("$GCC" -fconstexpr-ops-limit=4000000000);;
    clang) CX=("$CLANG" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);;
    p2996) CX=("$P2996" -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE -fconstexpr-steps=400000000);;
  esac
  echo "### $c: $("${CX[0]}" --version | head -1)"
  for m in LINEAR SORTED DIRECT HAND MPH CIB FROZEN; do
    if ! out=$("${CX[@]}" -std=c++26 -O2 -DNDEBUG -fno-exceptions -fno-rtti -D M_$m "${INC[@]}" tag_lookup_mac.cpp -o tl_${c}_$m 2>&1); then
      echo "$c $m BUILD FAILED: $(echo "$out" | grep -m1 error | cut -c1-200)"; fail=1; continue; fi
    best=; bcyc=; ins=; errs=
    for r in $(seq "$N"); do
      line=$(./tl_${c}_$m) || fail=1   # non-zero exit = wrong lookups
      ns=$(echo "$line" | sed -E 's/.* ([0-9.]+) ns\/lookup.*/\1/'); cyc=$(echo "$line" | sed -E 's/.* ([0-9.]+) cyc\/lookup.*/\1/')
      ins=$(echo "$line" | sed -E 's/.* ([0-9.]+) instr\/lookup.*/\1/'); errs=$(echo "$line" | sed -E 's/.*errors=([0-9]+).*/\1/')
      if [ -z "$best" ] || awk "BEGIN{exit !($ns < $best)}"; then best=$ns; fi
      if [ -z "$bcyc" ] || awk "BEGIN{exit !($cyc < $bcyc)}"; then bcyc=$cyc; fi
    done
    echo "$c $m errors=$errs min_ns=$best min_cyc=$bcyc instr=$ins"
  done
done
exit $fail
