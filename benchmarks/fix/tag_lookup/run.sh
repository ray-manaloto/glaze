#!/bin/bash
# Usage: run.sh <libs dir> <compiler> [extra flags...]   (libs dir holds mph, compile-time-init-build, cpp-std-extensions, frozen)
L=$1; CXX=$2; shift 2
cd "$(dirname "$0")"
status=0
INC=(-I"$L/mph" -I"$L/compile-time-init-build/include" -I"$L/cpp-std-extensions/include" -I"$L/frozen/include")
for m in LINEAR SORTED DIRECT HAND MPH CIB FROZEN; do
  st=$(date +%s)
  if out=$("$CXX" -std=c++23 -O2 -DNDEBUG -fno-exceptions -fno-rtti "$@" -D M_$m "${INC[@]}" tag_lookup.cpp -o tl_$m 2>&1); then
    ct=$(( $(date +%s) - st ))
    if res=$(./tl_$m); then echo "compile ${ct}s  $res"; else echo "compile ${ct}s  $res  RUN FAILED"; status=1; fi
  else
    echo "M_$m BUILD FAILED: $(echo "$out" | grep -m1 error | cut -c1-200)"; status=1
  fi
done
exit $status
