# Licence audit of third-party material in the FIX branches

Audit date: 2026-11-05. Base: `origin/main` @ `00e6ce3a`. Branches audited (tip SHAs):
`fix/tests-quickfix` @ `784aa5b7`, `fix/tests-hffix-fixpp` @ `1ebe6d70`,
`fix/tests-more-parsers` @ `d39fb04a`, `fix/dictionary` @ `5da9e09d`,
`fix/conformance-fuzz` @ `fc497ff1` (all of them also carry `fix/core` @ `e5babf6e`).

Method: `git diff --name-only --diff-filter=A origin/main...origin/<branch>` for each branch; each
upstream repository was shallow-cloned and its licence file read and compared (whitespace-insensitive
`diff`) with the copy the branch carries. Upstream SHAs below are the HEAD read during this audit;
where the branch names its own source commit that is given too.

This is an engineering audit, not legal advice.

## 1. Original work (MIT, glaze licence; no third-party notice needed)

| Branch | Paths |
|---|---|
| all (from `fix/core`) | `include/glaze/fix.hpp`, `include/glaze/fix/{codec,fix,opts,scan}.hpp`, `tests/fix_test/*`, `docs/fix/{api,design}.md`, `docs/fix/sessions/*` |
| `fix/tests-more-parsers` | `docs/fix/{api-questions,references}.md`, `tests/fix_vectors_test/{CMakeLists.txt,fix_vectors_test.cpp}`, `data/FORMAT.md`, `data/SOURCES.md`, `data/spec.fixv` (written afresh from the FIX spec; facts only) |
| `fix/dictionary` | `util/fix_codegen/fix_codegen.py`, `tests/fix_dictionary_test/*`, `docs/fix/dictionary.md` |
| `fix/conformance-fuzz` | `fuzzing/fix_*.cpp`, `fuzzing/corpus/fix/*`, `fuzzing/regressions/fix_*/*`, `tests/fix_property_test/*`, `docs/fix/conformance.md` (session notes say the seed corpus was hand-written; not checked byte-by-byte against upstream corpora) |
| `fix/tests-quickfix`, `fix/tests-hffix-fixpp` | `CMakeLists.txt` files, `.gitattributes`, `docs/fix/quickfix-tests.md`, `docs/fix/ported-tests-hffix-fixpp.md` |

## 2. Third-party material

| Branch | Path | Kind | Source repo @ commit | Licence (SPDX) | MIT-compatible redistribution | Notice required | Branch carries it |
|---|---|---|---|---|---|---|---|
| `fix/tests-quickfix` | `tests/fix_quickfix_test/fix_quickfix_test.cpp`, `fix_quickfix_struct_tests.inl` | port of tests (test intent + message strings; code rewritten) | quickfix/quickfix @ `386ce46e` (named in file header; matches HEAD) | QuickFIX Software License 1.0 (no SPDX id; `LicenseRef-QuickFIX-1.0`; Apache-1.1-style BSD licence) | **yes, with conditions** — permissive, but adds an acknowledgement clause and name restrictions MIT lacks | retain copyright + licence (cl. 1); end-user docs **must** say "This product includes software developed by quickfixengine.org (http://www.quickfixengine.org/)." (cl. 3); do not use "QuickFIX" to endorse or in a product name (cl. 4, 5) | yes: `QUICKFIX_LICENSE` (identical to upstream) and the acknowledgement sentence in the file header. **Missing**: acknowledgement in end-user docs/NOTICE of the integrated branch |
| `fix/tests-quickfix` | `tests/fix_quickfix_test/qfj_qfn_vectors.inl` | third-party test data (message vectors) | quickfix-j/quickfixj @ `9ac173b`; connamara/quickfixn @ `df6e100` (HEAD at audit; branch names no commit) | QuickFIX Software License 1.0 (same text; copyright "2001-2005 quickfixengine.org" / "2001-2010 quickfixengine.org") | yes, with conditions (as above) | as above | yes: `QUICKFIXJ_LICENSE`, `QUICKFIXN_LICENSE` (identical to upstream). Header should also carry the acknowledgement sentence and pin commits |
| `fix/tests-hffix-fixpp` | `tests/fix_hffix_test/fix_hffix_test.cpp` | port of tests | jamesdbrock/hffix @ `797ce7d` | BSD-2-Clause (Copyright 2011, T3 IP, LLC) | yes | retain copyright notice, conditions and disclaimer (source and binary) | yes: `LICENSE-hffix` (identical) |
| `fix/tests-hffix-fixpp` | `tests/fix_hffix_test/data/fix.4.1.set.1`, `fix.5.0.set.2`, `writer01.fix` | third-party sample messages, copied verbatim | jamesdbrock/hffix @ `797ce7d` | BSD-2-Clause | yes | as above | yes (same directory) |
| `fix/tests-hffix-fixpp` | `tests/fix_fixpp_test/fix_fixpp_test.cpp` (embeds lines of `tests/data/fix42.log`) | port of tests + sample messages | Abc-Arbitrage/fixpp @ `d99ff61` | MIT (Copyright (c) 2016 ABC arbitrage) | yes | retain copyright + permission notice | yes: `LICENSE-fixpp` (identical) |
| `fix/tests-more-parsers` | `tests/fix_vectors_test/data/artio.fixv` | test vectors (strings + expected outcomes) | real-logic/artio @ `11001bc` | Apache-2.0 | yes (Apache-2.0 code may be included in an MIT project; the Apache terms continue to apply to those files) | keep licence text; state changes (§4b); no upstream NOTICE file, so nothing to propagate (§4d) | yes: `data/licenses/artio-LICENSE` (upstream text + one added copyright line) |
| `fix/tests-more-parsers` | `data/philadelphia.fixv` | test vectors | paritytrading/philadelphia @ `6c604eb` | Apache-2.0 | yes | as artio | yes: `philadelphia-LICENSE.txt` (upstream text + one added line) |
| `fix/tests-more-parsers` | `data/fefix.fixv` | test vectors | ferrumfix/ferrumfix @ `ca2bbe4` | MIT OR Apache-2.0 (from `Cargo.toml`; no licence file at HEAD) | yes | branch elected Apache-2.0; MIT would be simpler (just keep notice) | yes: `fefix-LICENSE.txt` (explanatory header + Apache text) |
| `fix/tests-more-parsers` | `data/crocofix.fixv` | test vectors | GaryHughes/crocofix @ `c457473` | MIT (Copyright (c) 2019 Gary Hughes) | yes | keep notice | yes (identical) |
| `fix/tests-more-parsers` | `data/simplefix.fixv` | test vectors | da4089/simplefix @ `007e3d7` | MIT (upstream LICENSE has no copyright line; the branch adds "Copyright (C) 2016-2026, David Arnold" from `test/test_parser.py`) | yes | keep notice | yes |
| `fix/dictionary` | `include/glaze/fix/dict/fix42.hpp`, `fix44.hpp` | generated from third-party data (FIX Orchestra repository XML: tags, names, types, enums) | FIXTradingCommunity/orchestrations @ `cd24169`, `FIX Standard/OrchestraFIX4{2,4}.xml` | Apache-2.0 (repository `LICENSE` and README: "© Copyright 2017-2026 FIX Protocol Limited, Licensed under the Apache License, Version 2.0") | **yes, minor ambiguity** — the XML files themselves say `<dcterms:rights>Copyright (c) FIX Protocol Ltd. All Rights Reserved.</dcterms:rights>`; the repository licence grants Apache-2.0 over its contents, so we rely on that | keep Apache text; keep FIX Protocol Ltd. copyright; mark the files as modified/generated (§4b) | yes: `dict/LICENSE-FIX-ORCHESTRA` (identical to upstream) and a generated-file header. Header should pin the upstream commit |
| `fix/dictionary` | FIX 5.0 SP2 / FIX Latest dictionaries | generated on demand, **not committed** | FixRepositoryUnifiedEP247.xml / OrchestraFIXLatest.xml | Apache-2.0 (same repo) | n/a (not redistributed) | same as above if ever committed | n/a |

Not used by any branch (checked because they were named in the brief): **quickfixgo** (quickfixgo/quickfix
@ `eff945d`, QuickFIX Software License 1.0 — same terms as QuickFIX); **fix8** (clone of
`fix8org/fix8` failed with an auth prompt — repository moved or private; its licence could not be verified from the upstream repo in this session (recalled as LGPL-3.0, unverified) — no
branch copies from it, so no action needed); **fefix** = ferrumfix above.

FIX specification text: `spec.fixv` and `docs/fix/*` restate facts (tag numbers, checksum rule)
from the FIX specification in our own words. Facts are not copyrightable; no FIX specification
prose is copied. FIX Trading Community's specification terms of use do not restrict this, but
"FIX" is a trademark of FIX Protocol Ltd. — use it descriptively only.

## 3. Gaps the integrated branch must close

1. Add a top-level `NOTICE` (draft: `docs/fix/NOTICE.draft`) with the **QuickFIX acknowledgement
   sentence** — clause 3 requires it in end-user documentation, and the per-test file header alone
   does not cover the documentation shipped with the release.
2. Add the acknowledgement sentence to `qfj_qfn_vectors.inl` and pin the quickfixj/quickfixn commits.
3. Pin the orchestrations commit in the `fix42.hpp`/`fix44.hpp` headers and in `fix_codegen.py` output.
4. Do not name anything "QuickFIX" (QuickFIX licence clauses 4, 5). Target name
   `fix_quickfix_test` describes provenance only and is acceptable; do not use it in a product name.
5. Apache-2.0 §4(b): the `.fixv` and dictionary headers already say the content was ported/
   generated; keep that statement.

## 4. Files to remove or rewrite

**None.** Every third-party file found is under a permissive licence (MIT, BSD-2-Clause,
Apache-2.0, QuickFIX Software License 1.0) that permits redistribution inside an MIT-licensed
project provided the notices are kept. The only item marked *unclear* is the "All Rights Reserved"
line inside the Orchestra XML, which is overridden by the repository's Apache-2.0 grant; if the
maintainers want zero ambiguity, regenerate from the FIX Trading Community's published Orchestra
release (same licence) and record its tag.
