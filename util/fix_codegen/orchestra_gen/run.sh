#!/usr/bin/env bash
# Build orchestra_gen, generate FIX code, and test both output paths on the three compilers.
#
#   ./run.sh [step ...]      steps: gen guards targets headers visit annotations oracle negative embed latest
#                            (default: all but embed and latest)
#
# Every step's exit status counts: the script exits 1 if any step failed, and prints a summary.
# Machine-specific paths come from the environment or from ./local.env (git-ignored), never from this file:
#   GCC     GCC >= 16.2                         (default: g++-16 on PATH)
#   CLANG   clang-p2996 clang++                 (default: clang++-p2996 on PATH; steps that need it are skipped if unset)
#   LLVM    upstream clang++ (no reflection)    (default: clang++ on PATH; must accept -stdlib=libc++)
#   ORCH    the orchestrations repo's "FIX Standard" folder   (required)
#   BOOST_INC  include dir holding boost/decimal.hpp          (required)
set -uo pipefail
cd "$(dirname "$0")"
[ -f local.env ] && . ./local.env
GCC=${GCC:-$(command -v g++-16 || true)}
CLANG=${CLANG:-$(command -v clang++-p2996 || true)}
LLVM=${LLVM:-$(command -v clang++ || true)}
: "${ORCH:?set ORCH to the FIX Standard folder of the orchestrations repo (or put it in local.env)}"
: "${BOOST_INC:?set BOOST_INC to an include dir with boost/decimal.hpp (or put it in local.env)}"
XML=${XML:-$ORCH/OrchestraFIX44.xml}
STDX_REV=d6e517f86d5d4997c3c4fe78a29f41433cfb5c6d   # intel/cpp-std-extensions (stdx::optional, BSL-1.0)
B=build; O=out/fix44; T=$B/tests; mkdir -p "$T"
steps=("$@"); [ ${#steps[@]} -eq 0 ] && steps=(gen guards targets headers visit annotations oracle negative)
fails=(); passes=()

timed() {  # timed LABEL CMD...: run, keep the full log, print wall time and peak memory, return the command's status
  local label=$1; shift
  local log; log=$(logname "$label")
  local t0=$SECONDS rc
  if [ "$(uname)" = Darwin ]; then /usr/bin/time -l "$@" >"$log" 2>&1; rc=$?
  else /usr/bin/time -v "$@" >"$log" 2>&1; rc=$?; fi
  local mem; mem=$(grep -E "maximum resident set size|Maximum resident set size" "$log" | grep -oE '[0-9]+' | head -1)
  [ "$(uname)" = Darwin ] || mem=$(( ${mem:-0} * 1024 ))
  printf '== %-44s %4ss  %6s MB  %s\n' "$label" $((SECONDS - t0)) $(( ${mem:-0} / 1048576 )) "$([ $rc -eq 0 ] && echo ok || echo "FAILED (log: $log)")"
  [ $rc -eq 0 ] || grep -m5 -E "error|FAIL" "$log" | sed 's/^/     /'
  return $rc
}
logname() { printf '%s/%s.log' "$T" "$(printf '%s' "$1" | tr -c 'A-Za-z0-9' _)"; }
check() { if "$@"; then passes+=("$2"); else fails+=("$2"); fi; }
need() { [ -n "${!1}" ] && [ -x "${!1}" ] || { echo "== skip: $1 not set or not executable"; return 1; }; }

[ -d $B/deps/stdx ] || { git clone -q https://github.com/intel/cpp-std-extensions $B/deps/stdx && git -C $B/deps/stdx checkout -q $STDX_REV; }
# One structs header per target compiler (owner, 2026-11-09): annotations written directly for GCC 16 and
# clang-p2996, the GLZ_FIX3_TAG macro only for upstream clang, which has no annotations.
OP=$O-p2996; OL=$O-clang23
INC=(-Isupport -I$B/deps/stdx/include -isystem "$BOOST_INC")
GF=(-std=c++26 -freflection -I"$O" "${INC[@]}")
CF=(-std=c++26 -freflection -fexpansion-statements -fannotation-attributes -stdlib=libc++ -I"$OP" "${INC[@]}")
LF=(-std=c++26 -stdlib=libc++ -I"$OL" "${INC[@]}")
GLIM=(-fconstexpr-ops-limit=4294967296 -fconstexpr-loop-limit=2147483647)
CLIM=(-fconstexpr-steps=2147483647)

compile_run() {  # compile_run LABEL OUT COMPILER FLAGS... SRC
  local label=$1 out=$2; shift 2
  timed "$label" "$@" -o "$out" && "$out" >"$out.out" 2>&1 && sed 's/^/     /' "$out.out"
}

for step in "${steps[@]}"; do case $step in
gen)
  need GCC || { fails+=(gen); continue; }
  [ -f $B/build.ninja ] || cmake -S . -B $B -G Ninja -DCMAKE_CXX_COMPILER="$GCC" -DCMAKE_BUILD_TYPE=Release >/dev/null
  check timed "build orchestra_gen (GCC)" cmake --build $B
  check timed "generate FIX 4.4 (all messages, --strict)" ./$B/orchestra_gen --xml "$XML" --namespace fix44 --out "$O" --strict on
  sed -n '1,3p' "$(logname "generate FIX 4.4 (all messages, --strict)")" | sed 's/^/     /'
  check timed "generate FIX 4.4 for clang-p2996" ./$B/orchestra_gen --xml "$XML" --namespace fix44 --out "$OP" --strict on --target p2996
  check timed "generate FIX 4.4 for upstream clang" ./$B/orchestra_gen --xml "$XML" --namespace fix44 --out "$OL" --strict on --target clang23;;
targets)  # the annotation is written directly where the compiler has annotations; the macro only where it has not
  if ! grep -q GLZ_FIX3_TAG "$O/fix44.hpp" && ! grep -q GLZ_FIX3_TAG "$OP/fix44.hpp" && grep -q '\[\[=glz::fix3::tag{11}\]\] std::string_view cl_ord_id' "$O/fix44.hpp" \
     && grep -q 'GLZ_FIX3_TAG(11) std::string_view cl_ord_id' "$OL/fix44.hpp" && ! grep -q '\[\[=' "$OL/fix44.hpp"; then
    echo "== targets: annotations direct (gcc16, p2996), macro only for clang23  ok"; passes+=(targets-text)
  else echo "== targets: generated text                          FAILED"; fails+=(targets-text); fi
  printf '#include "fix44.hpp"\nint main() {}\n' > $T/target_probe.cpp
  if need LLVM; then
    wrong=$("$LLVM" -std=c++26 -stdlib=libc++ -I"$O" "${INC[@]}" -fsyntax-only $T/target_probe.cpp 2>&1)
    if grep -q 'was generated for GCC 16' <<<"$wrong"; then echo "== targets: gcc16 header refused by upstream clang ok"; passes+=(targets-refuse-llvm)
    else echo "== targets: gcc16 header on upstream clang          FAILED: not refused"; fails+=(targets-refuse-llvm); fi
  fi
  wrong=$("$GCC" -std=c++26 -freflection -I"$OL" "${INC[@]}" -fsyntax-only $T/target_probe.cpp 2>&1)
  if grep -q 'regenerate with --target gcc16' <<<"$wrong"; then echo "== targets: clang23 header refused by GCC 16       ok"; passes+=(targets-refuse-gcc)
  else echo "== targets: clang23 header on GCC 16                FAILED: not refused"; fails+=(targets-refuse-gcc); fi
  if need CLANG; then
    wrong=$("$CLANG" -std=c++26 -freflection -fexpansion-statements -stdlib=libc++ -I"$OP" "${INC[@]}" -fsyntax-only $T/target_probe.cpp 2>&1)
    if grep -q 'needs C++26 annotations' <<<"$wrong"; then echo "== targets: p2996 header without -fannotation-attributes refused ok"; passes+=(targets-refuse-p2996)
    else echo "== targets: p2996 header without the flag          FAILED: not refused"; fails+=(targets-refuse-p2996); fi
  fi;;
headers)
  check compile_run "headers: GCC 16.2" $T/g_headers "$GCC" "${GF[@]}" tests/headers_test.cpp
  need CLANG && check compile_run "headers: clang-p2996" $T/c_headers "$CLANG" "${CF[@]}" tests/headers_test.cpp
  need LLVM && check compile_run "headers: upstream clang" $T/l_headers "$LLVM" "${LF[@]}" tests/headers_test.cpp;;
visit)
  check compile_run "contract (fix_visit): GCC 16.2" $T/g_visit "$GCC" "${GF[@]}" tests/visit_test.cpp
  need CLANG && check compile_run "contract (fix_visit): clang-p2996" $T/c_visit "$CLANG" "${CF[@]}" tests/visit_test.cpp
  need LLVM && check compile_run "contract (fix_visit): upstream clang" $T/l_visit "$LLVM" "${LF[@]}" tests/visit_test.cpp;;
annotations)
  check compile_run "annotations: GCC 16.2" $T/g_anno "$GCC" "${GF[@]}" tests/annotation_test.cpp
  need CLANG && check compile_run "annotations: clang-p2996" $T/c_anno "$CLANG" "${CF[@]}" tests/annotation_test.cpp;;
oracle)  # independent check against the XML; oracle/check.py shares no code with the generator
  if compile_run "oracle dump: GCC 16.2" $T/dump "$GCC" "${GF[@]}" oracle/dump.cpp >/dev/null; then
    $T/dump > $T/dump.txt && cp "$O/fix44_enums.hpp" $T/enums.hpp
    echo "== oracle: compiled header vs the XML (${ORACLE_MESSAGES:-A 0 D 8 F G W})"
    if python3 -I oracle/check.py "$XML" $T/dump.txt ${ORACLE_MESSAGES:-A 0 D 8 F G W} | sed 's/^/     /'; then passes+=(oracle); else fails+=(oracle); fi
    # plant two errors in the first NewOrderSingle block: ClOrdID made optional, Side removed
    python3 -I -c "import sys; t=open(sys.argv[1]).read(); i=t.index('PART fix44::NewOrderSingle'); h=t[i:].replace('F 11 1 0 cl_ord_id','F 11 0 0 cl_ord_id',1).replace('F 54 1 0 side\n','',1); open(sys.argv[2],'w').write(t[:i]+h)" $T/dump.txt $T/dump_mut.txt
    mut=$(python3 -I oracle/check.py "$XML" $T/dump_mut.txt D)
    if grep -q "tag 54 (Side) missing" <<<"$mut" && grep -q "tag 11 (ClOrdID) expected required=True" <<<"$mut"; then
      echo "== oracle self-test (planted: ClOrdID optional, Side removed) ok"; passes+=(oracle-selftest)
    else echo "== oracle self-test                                 FAILED: planted error not reported"; fails+=(oracle-selftest); fi
  else fails+=(oracle); fi;;
guards)  # stage 0 acceptance: the generator refuses what it does not understand, and is deterministic
  mkdir -p $T/guard
  python3 -I -c "import sys; t=open(sys.argv[1]).read(); open(sys.argv[2],'w').write(t.replace('<fixr:field id=\"11\" ','<fixr:field newAttr=\"x\" id=\"11\" ',1))" "$XML" $T/guard/attr.xml
  out=$(./$B/orchestra_gen --xml $T/guard/attr.xml --namespace g --out $T/guard/o 2>&1)
  if [ $? -ne 0 ] && grep -q 'unknown attribute newAttr' <<<"$out"; then echo "== guard: unknown attribute refused                ok"; passes+=(guard-attr)
  else echo "== guard: unknown attribute                         FAILED: $out"; fails+=(guard-attr); fi
  out=$(./$B/orchestra_gen --xml "$ORCH/FIXReferenceData.xml" --namespace g --out $T/guard/o 2>&1)
  if [ $? -ne 0 ] && grep -q "scenario" <<<"$out"; then echo "== guard: non-base scenario refused (FIXReferenceData) ok"; passes+=(guard-scenario)
  else echo "== guard: scenario                                  FAILED: $out"; fails+=(guard-scenario); fi
  ./$B/orchestra_gen --xml "$XML" --namespace fix44 --out $T/guard/r1 >/dev/null && ./$B/orchestra_gen --xml "$XML" --namespace fix44 --out $T/guard/r2 >/dev/null
  if diff -r $T/guard/r1 $T/guard/r2 >/dev/null && diff -r $T/guard/r1 "$O" >/dev/null; then echo "== guard: two runs byte-identical, match out/fix44  ok"; passes+=(guard-deterministic)
  else echo "== guard: output differs between runs              FAILED"; fails+=(guard-deterministic); fi;;
negative)  # a corrupted digest must stop the build
  mkdir -p $T/bad && sed 's/ E:Side / E:Sidee /' "$O/fix44.digest" > $T/bad/fix44.digest && cp "$O/fix44_embed.cppm" $T/bad/
  neg=$("$GCC" "${GF[@]}" -fmodules --embed-dir=$T/bad "${GLIM[@]}" -fsyntax-only -x c++ $T/bad/fix44_embed.cppm 2>&1)
  if grep -q "no declaration named 'Sidee'" <<<"$neg"; then
    echo "== negative digest: GCC 16.2 names the error         ok"; passes+=(negative-gcc)
  else echo "== negative digest: GCC 16.2                         FAILED: not rejected with a message"; fails+=(negative-gcc); fi;;
embed)  # opt-in: the #embed + define_aggregate module and the layout differential test (~45 s, GCC up to 6.7 GB)
  rm -rf gcm.cache
  check timed "embed module: GCC 16.2" "$GCC" "${GF[@]}" -fmodules --embed-dir="$O" "${GLIM[@]}" -c -x c++ "$O/fix44_embed.cppm" -o $T/g_embed.o
  check compile_run "layout diff: GCC 16.2" $T/g_diff "$GCC" "${GF[@]}" -fmodules "${GLIM[@]}" tests/diff_test.cpp $T/g_embed.o
  if need CLANG; then
    check timed "embed module: clang-p2996" "$CLANG" "${CF[@]}" --embed-dir="$O" "${CLIM[@]}" --precompile -x c++-module "$O/fix44_embed.cppm" -o $T/fix44_embed.pcm
    check compile_run "layout diff: clang-p2996" $T/c_diff "$CLANG" "${CF[@]}" "${CLIM[@]}" -fmodule-file=fix44_embed=$T/fix44_embed.pcm tests/diff_test.cpp $T/fix44_embed.pcm
  fi;;
latest)  # FIX Latest EP312, every message, headers path on three compilers
  for tg in gcc16 p2996 clang23; do
    check timed "generate FIX Latest for $tg" ./$B/orchestra_gen --xml "$ORCH/OrchestraFIXLatest.xml" --namespace fixlatest --out out/fixlatest-$tg --target $tg
  done
  printf '#include "fixlatest.hpp"\nint main() { return sizeof(fixlatest::NewOrderSingle<glz::fix3::count_unknown>) == 0; }\n' > $T/latest.cpp
  check compile_run "FIX Latest headers: GCC 16.2" $T/g_latest "$GCC" "${GF[@]}" -Iout/fixlatest-gcc16 $T/latest.cpp
  need CLANG && check compile_run "FIX Latest headers: clang-p2996" $T/c_latest "$CLANG" "${CF[@]}" -Iout/fixlatest-p2996 $T/latest.cpp
  need LLVM && check compile_run "FIX Latest headers: upstream clang" $T/l_latest "$LLVM" "${LF[@]}" -Iout/fixlatest-clang23 $T/latest.cpp;;
*) echo "unknown step '$step'"; fails+=("$step");;
esac; done

echo
echo "passed: ${#passes[@]}   failed: ${#fails[@]}${fails:+  (${fails[*]})}"
[ ${#fails[@]} -eq 0 ]
