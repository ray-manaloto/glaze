# Sources for /tmp/fixsuite/d/fix_suite_spec.cpp

All example messages, structs and expected values in `fix_suite_spec.cpp` were written by hand for
this suite. No content was copied from the FIX Orchestra repository or any other third-party
source (the Orchestra repo was not cloned; no commit to record).

The rules exercised come from the publicly described FIX tag=value session/encoding rules:

* BodyLength (9) = byte count from after the SOH ending field 9 up to and excluding `10=`.
* CheckSum (10) = sum of all bytes before `10=` modulo 256, always three digits (zero padded),
  always the last field.
* Header ordering: 8 (BeginString), 9 (BodyLength), 35 (MsgType) first, in that order.
* Repeating groups: NoXXX count field first, each entry begins with the delimiter (first) tag;
  groups nest (NoLegs 555 containing NoNestedPartyIDs 539).
* Length/Data pairs (95 RawDataLength / 96 RawData): data read by byte count, may contain SOH.
* UTCTimestamp `YYYYMMDD-HH:MM:SS[.sss...]`, LocalMktDate `YYYYMMDD`, Price/Qty decimal text.
* Session messages: Logon (A), Heartbeat (0), TestRequest (1), ResendRequest (2), Reject (3),
  SequenceReset (4), Logout (5).
* Boolean fields: `Y` / `N` only.

Local reference used for the glaze API: /home/user/glaze/docs/fix/api.md and
/home/user/glaze/tests/fix_test/fix_test.cpp (structure/includes mirrored).

Duplicates deliberately avoided: the spec vectors in `tests/fix_vectors_test/data/*.fixv`
(origin/fix/tests-more-parsers) and the property tests on origin/fix/conformance-fuzz were not
re-created; this file focuses on rule-level checks with hand-built envelopes.
