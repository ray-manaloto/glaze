# Session notes: `fix/dictionary`

Scope: a FIX data-dictionary layer built from the FIX Trading Community's public repositories.
It has a generator (`util/fix_codegen/`), generated headers (`include/glaze/fix/dict/`) and a
round-trip test (`tests/fix_dictionary_test/`). The design is in `docs/fix/dictionary.md`.

## Done

* **Licence check** of the source data, recorded in `docs/fix/dictionary.md`. The orchestrations,
  fix-orchestra and fix-repository repositories are all Apache-2.0 (© FIX Protocol Limited).
  `include/glaze/fix/dict/LICENSE-FIX-ORCHESTRA` is a verbatim copy of the licence. Every
  generated header names its source file and copyright holder. No XML is committed.
* **Generator** `util/fix_codegen/fix_codegen.py` (Python 3, stdlib only). It reads:
  * Orchestra repository XML (`OrchestraFIX42.xml`, `OrchestraFIX44.xml`, `OrchestraFIXLatest.xml`);
  * FIX Repository 2010 Edition Unified XML (`FixRepositoryUnifiedEP247.xml` = FIX.5.0SP2_EP247).

  It emits tag constants; an `enum class` per code set with `glz::meta` holding `glz::enumerate`
  names and `fix_values` wire strings; and structs for repeating groups, components (flattened)
  and messages, each with `glz::meta` mapping tag-number keys to members. Groups are
  `std::vector<Grp>` keyed by the NumInGroup tag. Optional fields are `std::optional`. Message
  metas carry `fix_msg_type` and `fix_begin_string`. Structs have a defaulted `operator==`.
* **Committed headers:** `include/glaze/fix/dict/fix42.hpp` and `fix44.hpp`. FIX 5.0 SP2
  (~5.6 MB) and FIX Latest (~6 MB) are generated on demand: see "Regenerating" in
  `docs/fix/dictionary.md`. Both were generated and compiled with GCC 13
  (`-std=c++23 -fno-exceptions -fno-rtti -Wall -Wextra -Werror`). A 5.0 SP2 NewOrderSingle with
  a Parties group was read, written and read back, and compared equal (scratch program, not
  committed; result below under "Verification").
* **Header fields and the session layer** (second pass, 07:31–07:57 UTC). The generator
  flattens the StandardHeader (all but 8/9/35) into every message, so sender/target/seq
  num/sending time read and write through the generated structs. The session messages were
  already in the Orchestra 4.2/4.4 files and are now tested. `--no-header` restores the old
  output.
* **FIXT.1.1 for FIX 5.x.** For FIX.5.x and FIX.Latest dictionaries, `fix_begin_string` is
  `FIXT.1.1`. For 5.0 / SP1 / SP2, the namespace constants and message metas also carry the
  ApplVerID value (`fix_appl_ver_id`, `"9"` for SP2), and the namespace has
  `dictionary_version`. What `fix/core` would need for full FIXT support is recorded in
  `docs/fix/dictionary.md` ("Needed from `fix/core` for FIXT"). `fix/core` itself is unchanged.
* **Merged `fix/core`** (07:17 UTC). The local contract stub this branch used until then was
  replaced by `fix/core`'s `include/glaze/fix/fix.hpp`. To fit `fix/core`'s enum handling
  (underlying value), the generator now emits `bool` for Boolean code sets and `std::string` for
  String code sets. Only char and int code sets are enum members.
* **Test** `tests/fix_dictionary_test/` (registered in `tests/CMakeLists.txt`, boost-ext ut via
  `ut/ut.hpp`), 23 tests and 145 asserts, all passing against `fix/core`'s codec with the `gcc-debug` preset (GCC 13,
  `-Werror`, ASan/UBSan on):
  * generated metadata: tags, enum wire values, enum names through glaze JSON, msg types;
  * FIX 4.4 round trips: NewOrderSingle with a Parties group, ExecutionReport,
    MarketDataSnapshotFullRefresh (byte-exact), Logon (byte-exact), a message built from scratch;
  * FIX 4.2 NewOrderSingle and Logon;
  * session layer (FIX 4.4): Logon, Heartbeat, TestRequest, ResendRequest, Reject,
    SequenceReset and Logout, each read, checked (header 49/56/34/52 plus body fields) and
    written back byte for byte; a Heartbeat built from scratch; PossDupFlag/OrigSendingTime
    round trip;
  * errors: bad checksum, wrong MsgType, stream framing.
  * Before the merge, two more tests checked enum code-set validation in the stub. They were
    removed because `fix/core` does not validate enums (see `docs/fix/dictionary.md`).

## Not done

* Enum code-set validation in the codec (proposal: `meta<E>::fix_values`). Doubles are written
  as `1e+06` by `fix/core` (exponent); this is reported in `docs/fix/dictionary.md`, and the MD
  byte-exact sample uses 1500/2500 for now.
* The FIXT.1.1 session dictionary (`FIXTSession.xml`: Logon with DefaultApplVerID(1137) and so
  on) has not been generated or tested yet. The FIX 4.4 session messages are tested.
* The codec does not fill ApplVerID(1128) or check tag 8 on read (needs `fix/core`; see
  `docs/fix/dictionary.md`).
* Required-field presence is not checked on read. A message without 49/56 reads as empty
  strings.
* `data` fields containing SOH (length-prefixed via the paired Length field).
* clang build: the system clang here (with libstdc++ 13) fails inside glaze's own headers
  (`std::expected`, `[[assume]]`). These errors do not come from the FIX code. Not investigated.
* Pushing was refused by the git proxy at first. It worked once the repository was attached to
  the session (07:16 UTC), and every commit is on `origin/fix/dictionary`.

## Provenance of tests

No tests were ported from another project. Every test vector in
`tests/fix_dictionary_test/fix_dictionary_test.cpp` was written fresh in this session. Each
follows the message layouts of the FIX 4.2 / 4.4 / 5.0 SP2 data files named above. BodyLength(9)
and CheckSum(10) were computed over the `'|'`-delimited text, which is the same text the test
validates. Field values (order IDs, symbols, prices) are made up.

| Test | Source |
|------|--------|
| all of `fix_dictionary_test.cpp` | original, this session; layouts from OrchestraFIX44.xml / OrchestraFIX42.xml (Apache-2.0) |

## Verification

* `cmake --preset gcc-debug && cmake --build build/debug-gcc --target fix_dictionary_test`
  (needs CMake ≥ 3.31; `pip install --user cmake` was used here), then run
  `build/debug-gcc/tests/fix_dictionary_test/fix_dictionary_test`.
* FIX 5.0 SP2 scratch check: passed, both with the stub and again after merging `fix/core` (GCC 13, `-Werror`, about 2m20s to compile).
  Input `8=FIXT.1.1|...|35=D|11=SP2-1|453=1|448=DESK|447=D|452=3|55=VOD.L|54=2|...` was read,
  written and read back, and compared equal. The output begins `8=FIX.5.0SP2`. See "Not done"
  about FIXT.

## Next steps

1. Keep merging `fix/core`. Ask it to adopt `fix_values` (enum validation, String code-set
   enums) and fixed-notation float writing. Then restore the 1000000-sized MD sample.
2. Generate `FIXTSession.xml` as `glz::fix::fixt11` and test a FIXT Logon (1137=9). Ask
   `fix/core` for the three FIXT items in `docs/fix/dictionary.md`.
3. Decide whether to commit `fix50sp2.hpp` (5.6 MB), or to generate it at build time from a
   fetched XML through a CMake option (`glaze_FIX_DICTIONARIES`).
4. Make generation lazier for compile time: a FIX Latest TU takes about 2.5 min at -O0. One
   header per message, or splitting by category, would help.
5. Required-field checking on read (presence is known at generation time).
