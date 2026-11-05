# Session notes: `fix/tests-more-parsers`

Session 4 of 6. Goal: port parsing test vectors from more open-source FIX tag=value parsers into
`tests/fix_vectors_test/`.

## Done

- `tests/fix_vectors_test/`: a new test target (`fix_vectors_test`), registered in `tests/CMakeLists.txt`
  after `custom_formats`. It uses glaze's vendored `ut`, links `glz_test_common`, and builds and
  passes with GCC 13.3, Debug, `-fno-exceptions -fno-rtti -Werror`. It loads every
  `data/*.fixv` file at run time (path from the `GLZ_FIX_VECTORS_DIR` compile definition) and runs
  each vector as its own `ut` test against `glz::fix::parse_fields`, `validate`, `frame` and
  `checksum`. It also checks that every vector has an id, source and kind and that ids are unique.
- `data/FORMAT.md`: the `.fixv` format (blocks of `key = value`, `|` stands for SOH). It is meant to be
  reusable by other sessions and by other languages.
- 167 vectors (166 asserted, 1 `pending`):

  | file | vectors | origin |
  |---|---|---|
  | `simplefix.fixv` | 31 | da4089/simplefix, MIT |
  | `crocofix.fixv` | 32 | GaryHughes/crocofix, MIT |
  | `philadelphia.fixv` | 30 | paritytrading/philadelphia, Apache-2.0 |
  | `artio.fixv` | 23 | real-logic/artio, Apache-2.0 |
  | `fefix.fixv` | 15 | ferrumfix/ferrumfix, MIT OR Apache-2.0 |
  | `spec.fixv` | 36 | written afresh from the FIX specification |

- `data/SOURCES.md`: one row per vector with its repository, file, test name and what it checks.
  It is generated from the `.fixv` files; the generator was a throwaway script, so after editing a
  vector, either update the row by hand or rewrite the short script (it reads `id`, `kind`,
  `expect`/`frame_len`/`value`, `source`, `note`).
- `data/licenses/`: the upstream licence text for every copied source, with the copyright line.
  None of the Apache-2.0 projects has a NOTICE file.
- `docs/fix/references.md`: one section per parser (licence, test inventory, what was ported),
  covering the five above plus QuickFIX C++/J/Go and fix8, which were surveyed but not copied from.
- `docs/fix/api-questions.md`: open questions for `fix/core` (Q1 leading junk in `frame`, Q2 malformed
  headers in `frame`, Q3 empty values, Q4 tag syntax).
- `include/glaze/fix/fix.hpp`: a **local stub** of the shared contract (scanner, checksum, validate,
  frame; no struct mapping). `fix/core` had not been pushed while this session ran, so it could not
  be merged. **On merge, take `fix/core`'s version of this file**, then rebuild `fix_vectors_test`
  and look at any failures: they show where `fix/core` and the vectors disagree (see the questions).

## Where every ported vector came from

The `source` key of every vector in `tests/fix_vectors_test/data/*.fixv` gives
`<owner>/<repo>:<path>::<test name>`, and `data/SOURCES.md` lists them all. In short:

- simplefix (MIT): `test/test_parser.py` (`test_basic_fix_message`, `test_bad_tag`, `test_int_value_*`,
  `test_embedded_equals_96_no_95`, `test_cme_secdef`, `test_parse_partial_string`, `test_get_buffer`,
  `test_empty_value`, `test_leading_junk_pairs`, `test_junk_pairs`,
  `test_raw_data_ending_on_packet_boundary`) and `test/test_message.py` (`test_string_with_equals`,
  `test_string_without_equals`, `test_string_with_bad_tag`, `test_header_field`, `test_str`,
  `test_set_session_version`, `test_cooked_checksum`).
- crocofix (MIT): `libcrocofix_tests/message_tests.cpp::Message`, `order_tests.cpp::Order`,
  `order_book_tests.cpp::OrderBook` (each a Catch2 `TEST_CASE`; the note names the `SECTION`).
- Philadelphia (Apache-2.0): `libraries/core/src/test/java/com/paritytrading/philadelphia/`
  `FIXMessageTest::parse`, `FIXMessageParserTest::{read, readFixt11, readGarbledCheckSum, readPartial*,
  readGarbledBeginString, readGarbledBodyLength}`, `FIXInitiatorTest::{heartbeat, testRequest, sendLogon, ...}`.
- Artio (Apache-2.0): `artio-codecs/.../otf/OtfParserTest.java` and
  `artio-core/.../engine/framer/ReceiverEndPointTest.java`, messages from `util/TestMessages.java`.
- ferrumfix (MIT OR Apache-2.0, used under Apache-2.0): `tests/test_regression_tainted_decoder_fix44/src/lib.rs::decode`,
  `examples/00_decode_fix`, `examples/03_decode_fix_stream`, `examples/05_coinbase_codegen` (`run`).

Corrections made while porting (each is also in the vector's `note`):
- Some upstream sample messages have accidentally wrong BodyLength or CheckSum, because their parsers
  do not check them on input (simplefix, Artio's group messages, crocofix's edited messages,
  ferrumfix examples). Either the vector uses corrected values for validate/frame, or it keeps the
  original bytes as `expect = error`.
- One crocofix literal mixes `|` and an escaped SOH; both are treated as the separator.

## Not done

- Not merged with `fix/core` (it did not exist on the remote during the session).
- **Push failed for the whole session**: the git proxy refused `ray-manaloto/glaze` with 403 ("not in
  this session's authorized repository set"). The commits exist only in the session container unless
  someone recovers them; if you are reading this on the remote, a later push worked.
- No struct-mapping vectors (`glz::read<fix_opts{}>` into structs); the stub has no struct mapping.
- clang: clang 18 on this image cannot compile glaze tests against libstdc++ 13 (`std::expected` is
  missing for it), so only GCC was checked.
- ferrumfix: only a snapshot without `crates/` was available; its decoder unit tests were not reached.
- QuickFIX (C++/J/Go) and fix8: not copied (QuickFIX licence has extra conditions; fix8 is LGPL-3.0).
  Their structural cases are written afresh in `spec.fixv`.
- NexusFix: no public repository located.
- Raw-data fields (95/96, 89/93) whose value contains SOH: not expressible in the `|` format; skipped.

## Next steps

1. Merge `fix/core`, replace the stub, run `fix_vectors_test`, and settle Q1–Q4 with `fix/core`
   (then drop the `pending` key or flip expectations).
2. Add an escape for SOH inside values (for example `\x01`) to `FORMAT.md` and port the skipped
   raw-data vectors (simplefix `test_raw_data*`, crocofix data-field sections).
3. Port the QuickFIX acceptance categories (`test/definitions/server/fix44/*.def` names such as
   `14g_HeaderBodyTrailerFieldsOutOfOrder`, `14h_RepeatedTag`, `14i_RepeatingGroupCountNotEqual`) as
   fresh struct-level vectors once struct mapping exists.
4. Fetch ferrumfix's full history (or the `fefix` crate from crates.io, same licence) for the
   tagvalue decoder unit tests.
