#!/usr/bin/env bash
# Build and run the glaze-fix benchmark. Usage: benchmarks/fix/run.sh [build-dir]
# Set QUICKFIX=OFF to skip the QuickFIX C++ comparison (saves ~1 min of build).
set -euo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
build="${1:-$here/../../build-fix-bench}"
python3 "$here/gen_corpus.py" "$here/data/corpus.fix"   # deterministic; regenerates identical bytes
git -C "$here" diff --quiet -- data/corpus.fix || echo "WARNING: regenerated corpus differs from committed copy" >&2
cmake -S "$here" -B "$build" -DCMAKE_BUILD_TYPE=Release -DFIX_BENCH_QUICKFIX="${QUICKFIX:-ON}"
cmake --build "$build" -j"$(nproc)"
echo "## Machine"; lscpu | grep -E 'Model name|^CPU\(s\)|Thread|Core|Socket|MHz|L1d|L2|L3' || true
echo "compiler: $(${CXX:-c++} --version | head -1)"
echo; echo "## Results"
"$build/fix_bench" "$here/data/corpus.fix"
