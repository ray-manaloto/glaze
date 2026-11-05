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
* **Local contract stub** `include/glaze/fix/fix.hpp`. `fix/core` had published nothing when
  this session ran: `git ls-remote origin` showed no `fix/core` branch. The stub implements
  `glz::FIX`, `glz::fix_opts`, `glz::fix::field`, `parse_fields`, `checksum`, `validate`, `frame`,
  and `glz::read<fix_opts{...}>` / `glz::write<fix_opts{...}>` for types whose meta has
  `fix_msg_type`. glaze's own `read`/`write` need `from<FIX,T>`/`to<FIX,T>`, which the stub does
  not define, so its overloads are the only viable ones.
* **Test** `tests/fix_dictionary_test/` (registered in `tests/CMakeLists.txt`, boost-ext ut via
  `ut/ut.hpp`), 15 tests and 71 asserts, all passing with the `gcc-debug` preset (GCC 13,
  `-Werror`, ASan/UBSan on):
  * generated metadata: tags, enum wire values, enum names through glaze JSON, msg types;
  * FIX 4.4 round trips: NewOrderSingle with a Parties group, ExecutionReport,
    MarketDataSnapshotFullRefresh (byte-exact), Logon (byte-exact), a message built from scratch;
  * FIX 4.2 NewOrderSingle;
  * errors: bad checksum, wrong MsgType, an enum value outside its code set (read), a
    default-constructed required enum (write), stream framing.

## Not done

* Replacing the stub with `fix/core`'s header. When `fix/core` lands, delete
  `include/glaze/fix/fix.hpp` here and merge theirs. The test uses only contract entry points,
  plus the proposed additions `fix_begin_string` / `fix_values`, which are listed in
  `docs/fix/dictionary.md` for `fix/core` to accept or reject.
* FIXT.1.1 session layer (`FIXTSession.xml`, `FIX44Session.xml`) and ApplVerID(1128). The writer
  for 5.0 SP2 emits `8=FIX.5.0SP2`, not `8=FIXT.1.1`.
* `data` fields containing SOH (length-prefixed via the paired Length field).
* A StandardHeader member in messages (49/56/34/52 are skipped on read and not written).
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
* FIX 5.0 SP2 scratch check: passed (GCC 13, `-Werror`, about 2m20s to compile).
  Input `8=FIXT.1.1|...|35=D|11=SP2-1|453=1|448=DESK|447=D|452=3|55=VOD.L|54=2|...` was read,
  written and read back, and compared equal. The output begins `8=FIX.5.0SP2`. See "Not done"
  about FIXT.

## Next steps

1. Merge `fix/core` and drop the stub. Reconcile `fix_begin_string` / `fix_values` with
   `docs/fix/api.md`.
2. Generate the session layers (`FIX44Session.xml`, `FIXTSession.xml`) and add a
   StandardHeader member, or header handling, to messages.
3. Decide whether to commit `fix50sp2.hpp` (5.6 MB), or to generate it at build time from a
   fetched XML through a CMake option (`glaze_FIX_DICTIONARIES`).
4. Make generation lazier for compile time: a FIX Latest TU takes about 2.5 min at -O0. One
   header per message, or splitting by category, would help.
5. Required-field checking on read (presence is known at generation time).
