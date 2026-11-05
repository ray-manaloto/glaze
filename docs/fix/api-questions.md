# Open questions on the FIX API contract (from branch fix/tests-more-parsers)

**Status after merging fix/core (e5babf6):** Q1 and Q2 are settled by `glz::fix::frame_error` (no
skipping; a front that cannot start a message is an error), and Q3 is settled (empty values are a
`syntax_error`). Q4 is still open: `fix/core` accepts leading zeros in tags, and `spec.parse_leading_zero_tag`
is `pending` until that is decided. The text below is the original wording.

The FIX vector tests in `tests/fix_vectors_test/` run against the shared contract in
`include/glaze/fix/fix.hpp`. Some vectors from other parsers need a decision that the contract does
not make yet. Branch `fix/core` owns the contract; these are suggestions for it to settle and record in
`docs/fix/api.md`. Vectors that depend on an open question carry a `pending = Qn: ...` key; the runner
lists them and does not assert them.

- **Q1. Leading bytes before `8=` in `frame()`.** simplefix skips junk fields before BeginString
  (`test_leading_junk_pairs`). Should `frame()` skip them, and if so does its result count the skipped
  bytes (that is, return the end offset of the first message, so a caller can consume that many bytes)?
  The local stub returns 0 when the stream does not start with `8=`. Suggestion: return the end offset,
  so the result is always "bytes to consume", and document that a non-`8=` prefix is discarded.
- **Q2. `frame()` on a malformed but complete header** (for example a non-numeric `9=`). Returning 0
  makes it look like "need more data" for ever. Suggestion: a separate error result, or a documented
  rule that the caller treats 0 after N bytes as an error.
- **Q3. Empty values (`29=|`).** The FIX spec says fields without values should not be sent;
  simplefix accepts them only with an option. The stub's `parse_fields` accepts them. No asserted
  vector depends on the answer yet.
- **Q4. Tag syntax.** The stub rejects leading zeros (`035=`), tag 0 and tags above 2^32-1; the
  `spec.*` vectors assert that. If `fix/core` chooses to be lenient, those vectors need a `pending` key.
