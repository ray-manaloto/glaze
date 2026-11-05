# Sources for fix_suite_more_parsers.cpp

| Library | Repository | Commit | Licence (file beside this) |
|---|---|---|---|
| quickfixgo | https://github.com/quickfixgo/quickfix | eff945dd59a41caeaed20f71916f08d37e0fda99 | quickfixgo-LICENSE (QuickFIX licence) |
| ferrumfix / fefix | https://github.com/ferrumfix/ferrumfix | ca2bbe4c6461108646f35f7cc9245bf1848ec368 | MIT/Apache-2.0 (no LICENSE file at repo root in the depth-1 clone) |
| simplefix | https://github.com/da4089/simplefix | 007e3d7ffe904bcb2cfbfcb7ee8a4c13c5f3ea0a | simplefix-LICENSE (MIT) |
| artio | https://github.com/real-logic/artio | 11001bc7d3be58eacb0964c901c19103ed18914a | artio-LICENSE (Apache-2.0) |
| philadelphia | https://github.com/paritytrading/philadelphia | (not cloned; vector from FIXMessageParser tests, Apache-2.0) | see tests/fix_vectors_test/data/licenses/philadelphia-LICENSE.txt |

## Test -> source file

| Test | Source |
|---|---|
| qf_parse_message_validates, qf_custom_and_unknown_tags_skipped, qf_fix40_vector, qf_build_logon_expected_bytes, qf_xml_data_with_embedded_soh | quickfix/message_test.go |
| qf_parser_partial_stream_needs_more, qf_parser_garbage_before_begin_string | quickfix/parser_test.go |
| SKIP qf_parse_message_typed, qf_round_trip_rebuilds_identical_bytes, qf_parser_two_messages_in_stream | quickfix/message_test.go, parser_test.go (vectors not byte-exact) |
| artio_* | artio-codecs/src/test/java/uk/co/real_logic/artio/dictionary/generation/AbstractDecoderGeneratorTest.java (+ group/validation tests) |
| fefix_* | ferrumfix/crates/fefix/src/tagvalue (decoder/encoder tests), fefix Decimal/Timestamp tests |
| simplefix_checksum_known_values | simplefix/tests/test_message.py |
| philadelphia_empty_value_rejected | philadelphia FIXMessageParserTest |
