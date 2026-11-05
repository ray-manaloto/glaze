# Session notes: fix/licences

Done (2026-11-05, ~30 min before deadline):
- Listed added files on fix/tests-quickfix, fix/tests-hffix-fixpp, fix/tests-more-parsers,
  fix/dictionary, fix/conformance-fuzz (and fix/core) against origin/main.
- Shallow-cloned upstreams (quickfix, quickfixj, quickfixn, quickfixgo, hffix, fixpp, artio,
  crocofix, ferrumfix, philadelphia, simplefix, FIX orchestrations, fix-orchestra) and diffed each
  branch's licence copy against upstream: all identical, or upstream text plus an added copyright line.
- Wrote docs/fix/licences.md (audit table), docs/fix/NOTICE.draft, docs/fix/licences/*.txt.

Result: no file needs removing. Gaps: QuickFIX acknowledgement must go into end-user docs/NOTICE;
qfj_qfn_vectors.inl and dictionary headers should pin upstream commits.

Failed / left:
- fix8: clone of fix8org/fix8 asked for credentials; licence not verified. No branch uses fix8.
- Fuzz seed corpus provenance taken from session notes, not byte-checked.
- No build run (docs-only change).
- Philadelphia/simplefix copyright lines in the branch were not individually re-verified.
