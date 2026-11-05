# FIX tag=value conformance checklist

Rules for the FIX tag=value message format and session-layer framing, written from the
FIX 4.4 specification (Volume 1, "FIX Message Format" and "Data Types") and FIX 5.0 SP2 / FIXT.1.1
(the FIX Transport session protocol). Each rule has a test in
`tests/fix_property_test/fix_property_test.cpp` whose name starts with the rule id.

| Id | Rule | Where it is enforced | Test |
|----|------|----------------------|------|
| R1 | BeginString (8) is the first field. | `validate` | `R1 ...` |
| R2 | BodyLength (9) is the second field. | `validate` | `R2 ...` |
| R3 | MsgType (35) is the third field. | `validate` | `R3 ...` |
| R4 | CheckSum (10) is the last field. | `validate` | `R4 ...` |
| R5 | BodyLength counts the bytes after the SOH that ends field 9, up to and including the SOH before `10=`. | `validate`, writer | `R5 ...` |
| R6 | A BodyLength that does not match is rejected, even when the checksum is right. | `validate` | `R6 ...` |
| R7 | CheckSum is the sum of every byte before `10=`, modulo 256. | `checksum` | `R7 ...` |
| R8 | The CheckSum value is always exactly three digits, zero padded (`10=007`). | `validate`, writer | `R8 ...` |
| R9 | Every field, CheckSum included, ends with SOH. | `parse_fields`, `frame` | `R9 ...` |
| R10 | A field may not have an empty value. | `parse_fields` | `R10 ...` |
| R11 | A tag is a positive integer with no sign and no leading zeros. | `parse_fields` | `R11 ...` |
| R12 | A field without `=` is malformed. | `parse_fields` | `R12 ...` |
| R13 | A value runs to the next SOH, so `=` may appear inside a value. | `parse_fields` | `R13 ...` |
| R14 | Data fields (e.g. RawData 96) may contain SOH; their byte count comes from the Length field that precedes them (RawDataLength 95). The same applies to 90/91, 93/89, 212/213, 348/349, 350/351, 352/353, 354/355, 356/357, 358/359, 360/361, 362/363, 364/365, 445/446, 618/619, 621/622. A wrong or overlong length is rejected. | `parse_fields` | `R14 ...` (two tests) |
| R15 | Header and trailer tags (8, 9, 35, 10) do not repeat. | `validate` | `R15 ...` |
| R16 | A tag does not repeat outside a repeating group. | struct read | `R16 ...` |
| R17 | No bytes follow CheckSum inside one message; `frame` leaves trailing bytes for the next message. | `validate`, `frame` | `R17 ...` |
| R18 | `int`: optional `-`, digits, leading zeros permitted (`00023` = 23); no `+`, no decimal point, no thousands separator. | struct read | `R18 ...` |
| R19 | `float` (Qty, Price, Amt, ...): optional `-`, digits, optional `.`; leading and trailing zeros permitted; no exponent, no `+`. The writer never emits an exponent. | struct read / write | `R19 ...` (three tests) |
| R20 | `Boolean` is `Y` or `N` (case sensitive). | struct read | `R20 ...` |
| R21 | `char` is a single byte, any byte but the delimiter. | struct read / write | `R21 ...` (two tests) |
| R22 | MsgType must match the struct being read (`glz::meta<T>::fix_msg_type`). | struct read | `R22 ...` |
| R23 | The writer omits empty strings (R10) and refuses a delimiter inside a non-data field. | writer | `R23 ...` |
| R24 | FIX 5.0 SP2 messages use BeginString `FIXT.1.1` and are framed identically. | `validate`, `frame` | `R24 ...` |
| R25 | `fix_opts::validate_checksum` / `validate_body_length` turn the two checks off. | struct read | `R25 ...` |

Against `fix/core` as merged on 2026-11-05, R11 (in part), R14, R15 (in part), R16 and R19
(exponents) are not met yet. Their checks are guarded by `GLZ_FIX_KNOWN_GAPS`; see
`docs/fix/sessions/fix-conformance-fuzz.md` for the list.

## Properties

| Id | Property | Test |
|----|----------|------|
| P1 | `write` then `read` gives back equal values (random structs, SOH and `|`). | `P1 ...` |
| P2 | Changing any single byte of a valid message by any non-zero amount makes `validate` and `read` fail. | `P2 ...` |
| P3 | Every strict prefix of a valid message is reported incomplete by `frame` and rejected by `validate`; `frame` splits a stream of concatenated messages exactly. | `P3 ...` (two tests) |

## Not yet covered

- Repeating groups (NoXXX count tags, group delimiter field first, group field order).
- Field order inside the standard header beyond 8/9/35 (49, 56, 34, 52 position is not enforced).
- UTCTimestamp, LocalMktDate, MonthYear, MultipleValueString formats.
- Session-level rules that need state (sequence numbers, PossDupFlag, resend, logon).
