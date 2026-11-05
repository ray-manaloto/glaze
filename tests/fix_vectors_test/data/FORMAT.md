# `.fixv` test vector format

Plain text, UTF-8. One vector per block; blocks are separated by one or more blank lines.
Lines starting with `#` are comments. Every other line is `key = value` (the first ` = ` splits;
the value runs to end of line, with no trimming of the right side other than the newline).

In `msg`, `stream` and `bytes` values the character `|` stands for the FIX field separator
(SOH, 0x01). Vectors therefore never contain a literal `|` inside a field value.
The escape `\n` is not supported; vectors never contain raw newlines.

Keys:

| key        | required | meaning |
|------------|----------|---------|
| `id`       | yes      | unique id, `<source>.<short_name>` |
| `source`   | yes      | origin: `repo:path::test_name`, or `spec` when written afresh |
| `kind`     | yes      | `parse`, `validate`, `frame` or `checksum` |
| `msg`      | parse/validate | one message |
| `stream`   | frame    | bytes possibly holding 0, 1 or more messages |
| `bytes`    | checksum | bytes the checksum is computed over |
| `expect`   | parse/validate | `ok` or `error` |
| `fields`   | optional (parse, expect=ok) | expected `tag=value` list, `|`-separated, in order |
| `count`    | optional (parse, expect=ok) | expected number of fields |
| `frame_len`| frame    | length of the first complete message, `0` if incomplete |
| `value`    | checksum | expected checksum, decimal 0..255 |
| `note`     | optional | what the vector checks |
| `pending`  | optional | the expected outcome depends on an open API-contract question (text says which); the runner lists the vector but does not assert it |

Semantics follow the shared API in `include/glaze/fix/fix.hpp`:
`parse` -> `glz::fix::parse_fields(msg, '|')` (tag=value scan only, no header/trailer checks);
`validate` -> `glz::fix::validate(msg, '|')` (8 first, 9 second, 35 third, 10 last, 9 and 10 correct);
`frame` -> `glz::fix::frame(stream, '|')`; `checksum` -> `glz::fix::checksum(bytes with | as SOH)`.
