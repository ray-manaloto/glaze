# orchestra_gen (spike)

Reads a FIX Orchestra repository file and writes the glaze-fix 3-part structs (layout rules L1–L6).
It is a build-time C++26 tool and runs on GCC 16.2 only. It reads the XML with
[reflect-cpp](https://github.com/munich-data-engineering/reflect-cpp) v0.27.1, which uses pugixml v1.16
underneath, built with reflect-cpp's C++26 backend (`REFLECTCPP_USE_CPP26_REFLECTION=ON`, `-freflection`).

## What it writes (`--out DIR`)

| File | Used by | Contents |
|---|---|---|
| `<ns>_enums.hpp` | both paths | codeSet enums. char codeSets: `enum class X : char`, value = wire char. int codeSets: smallest integer type with `max()` free for "absent" (L5) |
| `<ns>.hpp` | headers path (all three compilers) | group entries, `StandardHeader<U>`, `StandardTrailer<U>`, one `template <unknown_policy U>` per message (L1), tag annotations (D4): `[[=glz::fix3::tag{n}]]` written directly for `--target gcc16` (default) and `--target p2996`, the `GLZ_FIX3_TAG(n)` macro only for `--target clang23` (no annotations); the header stops with `#error` on any other compiler, a `fix_fields` tag table in wire order, `static_assert` on `sizeof`/`alignof` for both policies (L6) |
| `<ns>.digest` | `#embed` path | the same layout as text: `P` part lines, `M` member lines |
| `<ns>_embed.cppm` | `#embed` path (GCC 16.2, clang-p2996) | a module that `#embed`s the digest; `define_aggregate` builds every struct at compile time |

## Name and width lock (`--lock FILE`, stage 2)

`lock/fix44.lock` and `lock/fixlatest.lock` (FIX Latest EP312, used by `run.sh latest`) are checked in. Each holds every generated C++ name and type, one line per item, keyed by
Orchestra ids: `tag <tag>` (tag constants), `enum <codeSet id>` (name and underlying type), `code <codeSet id>
<value>` (enumerator), `part <component|group|message> <id>` (struct) and `member <part kind> <part id> <tag>`
(member name and type; `?` marks an optional field or group, and ` open` a codeSet field (enum or string) that accepts values beyond its
codes). It is compared before anything is written:

- **Renamed** (same id, new Orchestra name): the locked name is kept (owner, 2026-11-10) and the run goes on.
  Each kept name is printed as `lock: kept ...`; type spellings that mention a kept enum or struct name follow it.
  The FIX-name strings (`fix_fields` entries and a struct's own `fix_name`) are not C++ names and show the
  new Orchestra name.
- **Added, removed, a changed type, width or presence, or members in a new wire order:** refused with one `lock: added|removed|type|reordered ...` line each, and
  nothing is written. After review, `--update-lock` writes the new lock and adopts the new names on purpose.

A missing lock file is an error unless `--update-lock` is given, which creates it.

## How the XML is read

- Every element prefix is stripped first, so the binding works for the `/2020/` and `/2026/` namespaces and any prefix.
- Leaf elements (datatype, codeSet + codes, field, ref attributes) are bound by `rfl::xml::read<T>(node)`.
- Ordered structures (message `structure`, component, group) are walked in document order with pugixml, and each
  ref is bound by reflect-cpp (the hybrid), so the interleaved ref order is kept.
- **Count guard:** reflect-cpp's `Reader::read_object` ignores per-field errors. The loader compares every bound
  count with a pugixml XPath count and stops on a mismatch. It caught a real case on the first run: codes bound
  through `std::optional<rfl::Rename<"code", std::vector<Code>>>` came back empty (0 of 1,728) with no error.

## Run

Put machine paths in `local.env` (git-ignored), or export them: `GCC`, `CLANG` (clang-p2996), `LLVM` (upstream
clang), `ORCH` (the orchestrations repo's `FIX Standard` folder), `BOOST_INC`. Then:

```sh
./run.sh                 # gen lock guards targets headers visit annotations oracle negative
./run.sh embed latest    # opt-in: the #embed module + layout diff (~45 s each, GCC up to 6.4 GB); FIX Latest
./run.sh oracle          # one step; ORACLE_MESSAGES="D 8" picks messages
```

Every step counts: the script prints `passed: N   failed: M` and exits 1 on any failure. Full compiler logs are
in `build/tests/*.log`. `gen` always writes every FIX 4.4 message with `--strict on`, once per target: `out/fix44` (gcc16), `out/fix44-p2996`, `out/fix44-clang23`; each compiler's tests use its own. `targets` checks the generated text and that each header refuses the wrong compiler.

The codec contract for the output is in `CONTRACT.md`.

## Tests

| Test | Compilers | Checks |
|---|---|---|
| `tests/headers_test.cpp` | GCC 16.2, clang-p2996, LLVM 23.1.5 | generated header compiles; layout asserts; L4 tombstone sizes; L5 enum values and widths; a NewOrderSingle built and read |
| `tests/annotation_test.cpp` | GCC 16.2, clang-p2996 | tags read back from the generated annotations by reflection |
| `tests/visit_test.cpp` | GCC 16.2, clang-p2996, LLVM 23.1.5 | the contract without reflection: `fix_visit` covers `fix_fields` in order, member indices are distinct, members set and read by tag (a bit-field through `bit_ref`), Reserved-range enums hold 4000, per-version constants |
| `tests/diff_test.cpp` | GCC 16.2, clang-p2996 | layout only: every struct from the `#embed` module has the same members, types, offsets, bit widths, size and alignment as the header's (static members and clang annotations are not compared) |
| `run.sh guards` | GCC 16.2 | an unknown attribute is refused; FIXReferenceData (non-base scenario) is refused; two runs are byte-identical |
| `run.sh negative` | GCC 16.2 | a digest naming a missing enum is rejected at compile time |
| `run.sh lock` | GCC 16.2 (generator only) | a synthetic EP (`tests/synthetic_ep.py`: Side code Z added, OrdType code 1 renamed, PartyRole code 256) is refused with exactly 3 changes and writes nothing, keeping the renamed code's name; renames only (ClOrdID field, Side codeSet, OrdType code) keep all 4 locked names and give the same output as `out/fix44`; `--update-lock` accepts the EP into a copy, after which the run is clean; a group turned required plus two swapped fields in NewOrderSingle are refused as 1 type change and 1 reordered part |

## Independent check against the XML (`oracle/`)

`oracle/check.py` reads the Orchestra file with the Python standard library and derives each message's
expected fields from the spec rules on its own; it shares no code or model with the generator.
`oracle/dump.cpp` prints what the *compiled* header contains (GCC 16.2 reflection reads the structs).
`./run.sh oracle` (after `MESSAGES=all ./run.sh gen`) compares, for Logon, Heartbeat, NewOrderSingle,
ExecutionReport, OrderCancelRequest, OrderCancelReplaceRequest and MarketDataSnapshotFullRefresh plus the
header, trailer and every group entry they reach: tags in wire order, required/optional, group nesting,
each member's type family (L2-L5) and the optional wrapper (L4), and int enum widths against the legal
range including `unionDataType` Reserved<N>Plus. A self-test feeds it a dump with ClOrdID made optional and
Side removed, and checks that both are reported.

## Not done yet

- The rest of stage 2: one naming pass, `[[deprecated]]` from
  the `deprecated` attribute, checked-in output with a regenerate-and-diff CI job.
- L3 per-field timestamp write format (s/ms/us/ns) is not emitted; the strict-vs-lenient question is open.
- Unknown tags inside group entries (entries are not templated over the policy).
- Codec integration: nothing reads or writes these structs yet.
- CMake for the generated output and for modules (the tests are driven by `run.sh`).
- `std::string_view` members take 16 bytes each, so the FIX 4.4 NewOrderSingle is 1,536 bytes (keep policy).
