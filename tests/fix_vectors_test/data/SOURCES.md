# Sources of the FIX test vectors

Generated from the `.fixv` files (`id`, `source`, `note` keys). Each vector's `source` key names the
upstream repository, file and test it was ported from; `spec` means written afresh from the FIX
specification. Values were copied as test data only (message strings and expected outcomes); no
upstream code is included. See `docs/fix/references.md` for the survey and `FORMAT.md` for the format.

| file | upstream | licence | licence file | vectors |
|---|---|---|---|---|
| `artio.fixv` | [real-logic/artio](https://github.com/real-logic/artio) | Apache-2.0 (no NOTICE file upstream) | `licenses/artio-LICENSE` | 23 |
| `artio_more.fixv` | [real-logic/artio](https://github.com/real-logic/artio) | Apache-2.0 (no NOTICE file upstream) | `licenses/artio-LICENSE` | 25 |
| `crocofix.fixv` | [GaryHughes/crocofix](https://github.com/GaryHughes/crocofix) | MIT | `licenses/crocofix-LICENSE.txt` | 32 |
| `fefix.fixv` | [ferrumfix/ferrumfix](https://github.com/ferrumfix/ferrumfix) | MIT OR Apache-2.0 (used under Apache-2.0) | `licenses/fefix-LICENSE.txt` | 15 |
| `fefix_crate.fixv` | [fefix crate (crates.io)](https://crates.io/crates/fefix) | MIT OR Apache-2.0 (used under Apache-2.0) | `licenses/fefix-LICENSE.txt` | 66 |
| `philadelphia.fixv` | [paritytrading/philadelphia](https://github.com/paritytrading/philadelphia) | Apache-2.0 (no NOTICE file upstream) | `licenses/philadelphia-LICENSE.txt` | 30 |
| `philadelphia_more.fixv` | [paritytrading/philadelphia](https://github.com/paritytrading/philadelphia) | Apache-2.0 (no NOTICE file upstream) | `licenses/philadelphia-LICENSE.txt` | 23 |
| `simplefix.fixv` | [da4089/simplefix](https://github.com/da4089/simplefix) | MIT | `licenses/simplefix-LICENSE` | 31 |
| `spec.fixv` | written afresh (FIX 4.4 Vol. 2 / FIX Session Layer) | part of this repository (MIT) | - | 36 |
| `spec_more.fixv` | written afresh (FIX 4.4 Vol. 2 / FIX Session Layer) | part of this repository (MIT) | - | 78 |

## artio.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `artio.eg_message_validate` | validate | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameValidFixMessage` | NewOrderSingle EG_MESSAGE: BodyLength 146, CheckSum 195; framed with status OK |
| `artio.logon_message_validate` | validate | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldNotifyDuplicateSession` | LOGON_MESSAGE: BodyLength 64, CheckSum 161 |
| `artio.eg_message_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfValidMessageFields` | fields 8, 9, 35, 34 first, then 15 more (19 in total), no onError |
| `artio.eg_message_checksum` | checksum | 195 | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfValidMessageEnd` | EG_MESSAGE CheckSum 195 accepted by OtfParser |
| `artio.frame_complete` | frame | len 169 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameValidFixMessage` | one complete message is framed at MSG_LEN |
| `artio.frame_incomplete` | frame | len 0 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldOnlyFrameCompleteFixMessage` | MSG_LEN - 8 bytes: nothing framed |
| `artio.frame_two_complete` | frame | len 169 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameTwoCompleteFixMessagesInOnePacket` | two back-to-back messages; first frame is MSG_LEN |
| `artio.frame_complete_then_incomplete` | frame | len 169 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameOneCompleteMessageWhenTheSecondMessageIsIncomplete` | complete message followed by MSG_LEN - 8 bytes of the next; first frame is MSG_LEN |
| `artio.frame_logon` | frame | len 86 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldNotifyDuplicateSession` | Logon framed at LOGON_MESSAGE.length |
| `artio.invalid_checksum_validate` | validate | error | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfInvalidChecksum` | CheckSum 155 is wrong (actual 172); onError(INVALID_CHECKSUM) also asserted by ReceiverEndPointTest.invalidChecksumMessageRecorded |
| `artio.body_length_too_short_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldIgnoreMessageWithBodyLengthTooShort` | BodyLength 5 is far shorter than the body (actual 50); saved as INVALID_BODYLENGTH |
| `artio.invalid_message_parse` | parse | error | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfInvalidMessage` | run of empty fields (consecutive SOH) after 11=...; onError(PARSE_ERROR) |
| `artio.invalid_message_validate` | validate | error | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfInvalidMessage` | same message: empty fields, and BodyLength/CheckSum do not match |
| `artio.out_of_required_order_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::fieldOutOfOrderMessageRecordedOnce` | MsgType(35) before BeginString(8); saved as INVALID (TAG_SPECIFIED_OUT_OF_REQUIRED_ORDER_MESSAGE from ExampleDictionary.java) |
| `artio.execution_report_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfRepeatingGroup` | ExecutionReport with one-entry ContraBrokers group (382=1); parses without error (BodyLength stale upstream; not a validate vector) |
| `artio.zero_repeating_group_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfOnlyHeaderForEmptyGroup` | 382=0 empty group; parses without error (BodyLength stale upstream; not a validate vector) |
| `artio.repeating_group_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfMultiElementRepeatingGroup` | NoOrders(73)=2 group with two entries; parses without error (BodyLength stale upstream; not a validate vector) |
| `artio.nested_repeating_group_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfNestedRepeatingGroup` | NoOrders group containing nested NoAllocs(78)=2 group; parses without error (BodyLength stale upstream; not a validate vector) |
| `artio.execution_report_checksum` | checksum | 13 | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfRepeatingGroup` | EXECUTION_REPORT CheckSum 013 is correct (OtfParser checks it, no onError) |
| `artio.repeating_group_checksum` | checksum | 21 | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfMultiElementRepeatingGroup` | REPEATING_GROUP CheckSum 021 is correct (OtfParser checks it, no onError) |
| `artio.nested_repeating_group_checksum` | checksum | 76 | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::notifiesAcceptorOfNestedRepeatingGroup` | NESTED_REPEATING_GROUP CheckSum 076 is correct (OtfParser checks it, no onError) |
| `artio.zero_checksum_parse` | parse | ok | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::parsesZeroChecksumMessages` | Heartbeat whose CheckSum is 000; parses without error |
| `artio.zero_checksum_checksum` | checksum | 0 | `real-logic/artio:artio-codecs/src/test/java/uk/co/real_logic/artio/otf/OtfParserTest.java::parsesZeroChecksumMessages` | bytes sum to 0 mod 256 (CheckSum 000 is genuinely correct) |

## artio_more.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `artio.ioi_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/BusinessRejectRefIdExtractorTest.java::shouldExtractBusinessRejectRefId` | IOI (35=6) message; tag=value scan succeeds (15 fields) |
| `artio.ioi_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/BusinessRejectRefIdExtractorTest.java::shouldExtractBusinessRejectRefId` | stated BodyLength 154 but actual body is 101 bytes (CheckSum 170 also wrong, actual 123); extractor does not validate |
| `artio.possdup_second_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/PossDupFinderTest.java::shouldFindLengthOfPossDupMessage` | Logout with PossDupFlag; BodyLength value written with leading zeros (0065) |
| `artio.possdup_second_checksum` | checksum | 88 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/PossDupFinderTest.java::shouldFindLengthOfPossDupMessage` | SECOND_MESSAGE CheckSum 088 is correct |
| `artio.possdup_first_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/PossDupFinderTest.java::shouldOnlyReturnPossDupAtLength` | FIRST_MESSAGE is SECOND_MESSAGE without 43=Y but keeps its header and trailer: body is 60 bytes (not 65), CheckSum actual 090 (not 088) |
| `artio.password_logon_validate` | validate | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordFromLogon` | Logon with Username/Password; BodyLength 99 and CheckSum 062 both correct |
| `artio.password_logon_frame` | frame | len 121 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordFromLogon` | Logon with password frames at its full length |
| `artio.password_logon_checksum` | checksum | 62 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordFromLogon` | Logon CheckSum 062 |
| `artio.no_password_logon_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldNotChangeLogonWithoutPassword` | BodyLength 78 correct but the fixture reuses CheckSum 062 (actual 081) |
| `artio.short_password_logon_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordFromLogonWithShortNamePassword` | stated BodyLength 98 but actual body is 100 bytes (and CheckSum 062 is stale) |
| `artio.empty_password_logon_parse` | parse | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordFromLogonWithEmptyPassword` | Password field 554 has an empty value; parse_fields rejects empty values |
| `artio.user_request_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordsFromUserRequest` | UserRequest (35=BE, two-character MsgType) parses as 13 fields |
| `artio.user_request_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/PasswordCleanerTest.java::shouldCleanPasswordsFromUserRequest` | BodyLength 116 correct, CheckSum 062 stale (actual 185) |
| `artio.header_eg_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/logger/FixMessagePredicateTest.java::shouldMatchHeader` | Logon with five-digit custom tags 35002 and 35003 |
| `artio.header_eg_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/logger/FixMessagePredicateTest.java::shouldMatchHeader` | BodyLength 110 correct, CheckSum 047 wrong (actual 168) |
| `artio.header_eg_checksum` | checksum | 168 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/logger/FixMessagePredicateTest.java::shouldMatchHeader` | actual CheckSum of HEADER_EG is 168 |
| `artio.missing_msg_seq_num_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldNotifySessionOfMissingMsgSeqNum` | header-only News message, no BodyLength and no CheckSum; tag=value scan succeeds |
| `artio.missing_msg_seq_num_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldNotifySessionOfMissingMsgSeqNum` | second field is 35, not 9 (no BodyLength, no CheckSum) |
| `artio.unknown_msg_type_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldNotifySessionOfUnknownMessageType` | MsgType value * is a legal tag=value value |
| `artio.unknown_msg_type_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldNotifySessionOfUnknownMessageType` | no BodyLength and no CheckSum |
| `artio.wrong_comp_id_validate` | validate | error | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldValidateCompId` | EG_MESSAGE with CompIDs replaced by WRONG keeps BodyLength 146 (actual 143) and CheckSum 195 (actual 116) |
| `artio.wrong_comp_id_parse` | parse | ok | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/session/SessionParserTest.java::shouldValidateCompId` | same message parses as 19 fields |
| `artio.frame_logon_then_eg` | frame | len 86 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameLogonMessageWhenLoggerBehind` | LOGON_MESSAGE followed by EG_MESSAGE; first frame is the 86-byte Logon |
| `artio.frame_split_prefix` | frame | len 0 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldFrameSplitFixMessage` | a prefix of EG_MESSAGE ending after 11=NF 0542/03232009 (as when the message arrives split) is incomplete |
| `artio.frame_eg_without_final_soh` | frame | len 0 | `real-logic/artio:artio-core/src/test/java/uk/co/real_logic/artio/engine/framer/ReceiverEndPointTest.java::shouldOnlyFrameCompleteFixMessage` | EG_MESSAGE missing only its final SOH is incomplete |

## crocofix.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `crocofix.parse.complete_message` | parse | ok | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Decode a complete message": 18 fields decoded |
| `crocofix.parse.invalid_tag` | parse | error | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Invalid tag throws": non-numeric tag "A" is rejected |
| `crocofix.parse.admin_logon` | parse | ok | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "is_admin is true for an admin message": 35=A message decodes to 18 fields |
| `crocofix.parse.no_msgtype` | parse | ok | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "MsgType lookup throws for a message with no MsgType": message without 35 still decodes (17 fields) |
| `crocofix.parse.no_bodylength` | parse | ok | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "encode does not add BodyLength if it is not present": message without 9 decodes (17 fields) |
| `crocofix.parse.exec_report_merged_field` | parse | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "key_for_message ExecutionReport": the source literal mixes \| and an escaped SOH between 34 and 52; both are the separator here, giving 23 fields |
| `crocofix.validate.complete_message` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Decode a complete message"/"encode a message": encode recomputes 9=149 and 10=021 and matches |
| `crocofix.validate.no_msgtype` | validate | error | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "MsgType lookup throws for a message with no MsgType": 35 absent from third position |
| `crocofix.validate.no_bodylength` | validate | error | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "encode does not add BodyLength if it is not present": 9 absent |
| `crocofix.validate.no_checksum` | validate | error | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "encode does not add CheckSum if it is not present": 10 absent |
| `crocofix.validate.admin_logon_stale_checksum` | validate | error | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "is_admin is true for an admin message": 35=D edited to 35=A without updating 10=021 (actual 018); crocofix decode does not verify CheckSum |
| `crocofix.validate.unsupported_msgtype_stale_checksum` | validate | error | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "MessageWithUnsupportedMsgTypeIgnored": 35=S edited in without updating 10=021 (actual 036) |
| `crocofix.validate.exec_report_new` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "NewOrderSingleAndExecutionReports": message decoded complete with consumed == length |
| `crocofix.validate.exec_report_partial` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "NewOrderSingleAndExecutionReports": message decoded complete with consumed == length |
| `crocofix.validate.exec_report_filled` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "NewOrderSingleAndExecutionReports": message decoded complete with consumed == length |
| `crocofix.validate.order_cancel_request` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "key_for_message OrderCancelRequest": message decoded complete with consumed == length |
| `crocofix.validate.order_cancel_replace_request` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_tests.cpp::Order` | SECTION "key_for_message OrderCancelReplaceRequest": message decoded complete with consumed == length |
| `crocofix.validate.unknown_exec_report` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "UnknownExecutionReport": message decoded complete with consumed == length |
| `crocofix.validate.cancel_replace_unknown_order` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelReplaceRequestForUnknownOrder": message decoded complete with consumed == length |
| `crocofix.validate.cancel_request_unknown_order` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelRequestForUnknownOrder": message decoded complete with consumed == length |
| `crocofix.validate.cancel_reject_unknown_order` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelRejectForUnknownOrder": message decoded complete with consumed == length |
| `crocofix.validate.new_order_single_fix44` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "NewOrderSingleAcknowledged": message decoded complete with consumed == length |
| `crocofix.validate.fixt_new_order_single` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelRequestForKnownOrderAccepted": message decoded complete with consumed == length |
| `crocofix.validate.fixt_cancel_request` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelRequestForKnownOrderAccepted": message decoded complete with consumed == length |
| `crocofix.validate.fixt_cancel_reject` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelRequestForKnownOrderRejected": message decoded complete with consumed == length |
| `crocofix.validate.fixt_cancel_replace` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelReplaceRequestForKnownOrderRejected": message decoded complete with consumed == length |
| `crocofix.validate.fixt_exec_report_replace_rejected` | validate | ok | `GaryHughes/crocofix:libcrocofix_tests/order_book_tests.cpp::OrderBook` | SECTION "OrderCancelReplaceRequestForKnownOrderRejected": message decoded complete with consumed == length |
| `crocofix.frame.complete_message` | frame | len 172 | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Decode a complete message": complete, consumed == text length |
| `crocofix.frame.split_on_field_boundary` | frame | len 0 | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Decode a complete message in two pieces aligned on a field boundary": first piece incomplete |
| `crocofix.frame.split_mid_field` | frame | len 0 | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "Decode a complete message in two pieces not aligned on a field boundary": first piece ends in "55=B", incomplete |
| `crocofix.frame.no_checksum` | frame | len 0 | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "encode does not add CheckSum if it is not present": no 10 so decode is incomplete |
| `crocofix.checksum.complete_message` | checksum | 21 | `GaryHughes/crocofix:libcrocofix_tests/message_tests.cpp::Message` | SECTION "encode a message": encode recomputes CheckSum 021 over the NewOrderSingle |

## fefix.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `fefix.tainted_md_snapshot_parse` | parse | ok | `ferrumfix/ferrumfix:tests/test_regression_tainted_decoder_fix44/src/lib.rs::decode` | MarketDataSnapshot sample decodes and MsgType is readable (verify_checksum = false upstream) |
| `fefix.tainted_md_snapshot_validate` | validate | error | `ferrumfix/ferrumfix:tests/test_regression_tainted_decoder_fix44/src/lib.rs::decode` | BodyLength 176 correct, CheckSum 157 wrong (actual 051); upstream disables checksum verification |
| `fefix.tainted_security_status_parse` | parse | ok | `ferrumfix/ferrumfix:tests/test_regression_tainted_decoder_fix44/src/lib.rs::decode` | SecurityStatus (35=f) sample decodes and MsgType is readable (verify_checksum = false upstream) |
| `fefix.tainted_security_status_validate` | validate | error | `ferrumfix/ferrumfix:tests/test_regression_tainted_decoder_fix44/src/lib.rs::decode` | BodyLength 227 correct, CheckSum 098 wrong (actual 248); upstream disables checksum verification |
| `fefix.md_incremental_parse` | parse | ok | `ferrumfix/ferrumfix:examples/00_decode_fix/src/main.rs::run` | MarketDataIncrementalRefresh with two-entry NoMDEntries group; test asserts 8, 35, 49, 56, 34, 262 and both group entries, so the full ordered field list is given |
| `fefix.md_incremental_validate` | validate | ok | `ferrumfix/ferrumfix:examples/00_decode_fix/src/main.rs::run` | same message: BodyLength 196 and CheckSum 171 correct |
| `fefix.md_incremental_checksum` | checksum | 171 | `ferrumfix/ferrumfix:examples/00_decode_fix/src/main.rs::run` | CheckSum of the message up to 10= is 171 |
| `fefix.stream_ioi_validate` | validate | ok | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | first stream message (35=6 IOI): BodyLength 97, CheckSum 248 correct |
| `fefix.stream_ioi_checksum` | checksum | 248 | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | CheckSum of the first stream message is 248 |
| `fefix.stream_two_messages_frame` | frame | len 119 | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | streaming decoder over two concatenated messages; first frame is the IOI |
| `fefix.stream_partial_frame` | frame | len 0 | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | streaming decoder fed less than one message reports still-parsing (None) |
| `fefix.stream_order_parse` | parse | ok | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | second stream message (NewOrderSingle) decodes; BeginString FIX.4.2 |
| `fefix.stream_order_validate` | validate | error | `ferrumfix/ferrumfix:examples/03_decode_fix_stream/src/main.rs::run` | BodyLength 40 correct, CheckSum 091 wrong (actual 254); upstream decoder accepted it |
| `fefix.coinbase_exec_report_parse` | parse | ok | `ferrumfix/ferrumfix:examples/05_coinbase_codegen/src/main.rs::run` | custom-dictionary fields 1003=123 and 1057=Y decode |
| `fefix.coinbase_exec_report_validate` | validate | error | `ferrumfix/ferrumfix:examples/05_coinbase_codegen/src/main.rs::run` | BodyLength 21 correct, CheckSum 090 wrong (actual 211); upstream decoder accepted it |

## fefix_crate.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `fefix.crate_raw_sample_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::sample_message_is_valid` | upstream asserts begin string FIX.4.2 and payload 35=D..59=0 (checksum not verified) |
| `fefix.crate_raw_sample_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::sample_message_is_valid` | BodyLength 40 correct; 091 was summed over literal '\|' bytes, with SOH the sum is 254 |
| `fefix.crate_raw_sample_soh_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::sample_message_is_valid` | same message with CheckSum recomputed over SOH separators |
| `fefix.crate_raw_sample_checksum` | checksum | 254 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::sample_message_is_valid` |  |
| `fefix.crate_raw_msg_type_only_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_only_msg_type_tag_is_valid` |  |
| `fefix.crate_raw_msg_type_only_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_only_msg_type_tag_is_valid` | BodyLength 5 correct; CheckSum 183 is the '\|' sum, SOH sum is 070 |
| `fefix.crate_raw_msg_type_only_soh_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_only_msg_type_tag_is_valid` | minimal message: 8, 9, 35 and 10 only; CheckSum recomputed over SOH |
| `fefix.crate_raw_msg_type_only_frame` | frame | len 20 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_only_msg_type_tag_is_valid` |  |
| `fefix.crate_raw_empty_payload_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_empty_payload_is_invalid` | well-formed fields; the invalidity is structural (see validate) |
| `fefix.crate_raw_empty_payload_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_empty_payload_is_invalid` | no MsgType (35) third; upstream DecodeError::Invalid |
| `fefix.crate_raw_bad_checksum_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::message_with_bad_checksum_is_invalid` | BodyLength correct, CheckSum 000 wrong (actual 254); upstream DecodeError::CheckSum |
| `fefix.crate_raw_edge_empty_begin_string_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty value for tag 8; upstream only requires no panic |
| `fefix.crate_raw_edge_empty_checksum_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty values for tags 8 and 10 |
| `fefix.crate_raw_edge_equals_run_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | 8 has value "===" (allowed) but 10 is empty |
| `fefix.crate_raw_edge_leading_separators_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty fields at the front |
| `fefix.crate_raw_edge_leading_separators_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | front is SOH, cannot start a message |
| `fefix.crate_raw_edge_digits_no_equals_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | no '=' and no SOH |
| `fefix.crate_raw_edge_digits_no_equals_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | front is '9', not "8=" |
| `fefix.crate_raw_edge_negative_digits_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` |  |
| `fefix.crate_raw_edge_negative_digits_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` |  |
| `fefix.crate_raw_edge_all_equals_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty tag |
| `fefix.crate_raw_edge_all_equals_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` |  |
| `fefix.crate_raw_edge_digits_soh_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | field without '=' |
| `fefix.crate_raw_edge_digits_soh_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` |  |
| `fefix.crate_raw_edge_huge_tag_empty_value_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty first field, then a 12-digit tag (> 999999999) with empty value |
| `fefix.crate_raw_edge_huge_value_trailing_equals_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` | empty first field and a trailing "=" with no tag, value or SOH |
| `fefix.crate_raw_edge_huge_value_trailing_equals_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::edge_cases_dont_cause_panic` |  |
| `fefix.crate_raw_buffered_repeated_frame` | frame | len 62 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::new_buffered_decoder` | upstream streams 42 back-to-back copies (CheckSum 091 there; 254 here, the SOH sum); 3 copies kept |
| `fefix.crate_raw_buffered_partial_header_frame` | frame | len 0 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::new_buffered_decoder` | buffered decoder has no frame until enough bytes are supplied |
| `fefix.crate_raw_buffered_missing_last_soh_frame` | frame | len 0 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::new_buffered_decoder` | 61 of 62 bytes: trailer SOH not yet arrived |
| `fefix.crate_raw_buffered_begin_only_frame` | frame | len 0 | `fefix crate 0.7.0:src/tagvalue/raw_decoder.rs::new_buffered_decoder_has_no_current_frame` | only BeginString received |
| `fefix.crate_dec_simple_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::can_parse_simple_message` | checksum verification off in the upstream test decoder |
| `fefix.crate_dec_foobar_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::skip_checksum_verification` | unknown BeginString, accepted upstream with checksum verification off |
| `fefix.crate_dec_foobar_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::no_skip_checksum_verification` | BodyLength 5 correct; CheckSum 000 wrong (actual 198); upstream errors with verification on |
| `fefix.crate_dec_foobar_soh_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::no_skip_checksum_verification` | same message with correct CheckSum; validate does not check the BeginString value |
| `fefix.crate_dec_group_entries_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::repeating_group_entries` | NoMDEntries (268) = 2; upstream asserts group length 2 and entry 0 has 278=BID |
| `fefix.crate_dec_empty_group_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::top_level_tag_after_empty_group` | 268=0 (empty group) followed by top-level 346=1 |
| `fefix.crate_dec_empty_group_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::top_level_tag_after_empty_group` | BodyLength 17 correct; CheckSum 171 wrong (actual 024) |
| `fefix.crate_dec_empty_group_soh_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::top_level_tag_after_empty_group` | same message with CheckSum recomputed |
| `fefix.crate_dec_random_heartbeat_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::heartbeat_message_fields_are_ok` | upstream asserts 35=0, 8=FIX.4.2, 34=12 |
| `fefix.crate_dec_random_heartbeat_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[0] Heartbeat; 9 and 10 correct |
| `fefix.crate_dec_random_heartbeat_checksum` | checksum | 185 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` |  |
| `fefix.crate_dec_random_trading_session_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[1] IOI (35=6); 9 and 10 correct |
| `fefix.crate_dec_random_trade_capture_req_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[2] TradeCaptureReportRequest (two-character MsgType AD) |
| `fefix.crate_dec_random_trade_capture_req_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` |  |
| `fefix.crate_dec_random_reject_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[3] Reject (35=3) |
| `fefix.crate_dec_random_reject_checksum` | checksum | 58 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` |  |
| `fefix.crate_dec_random_seq_reset_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[4] SequenceReset (35=4) |
| `fefix.crate_dec_random_new_order_validate` | validate | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[5] NewOrderSingle |
| `fefix.crate_dec_random_new_order_checksum` | checksum | 72 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` |  |
| `fefix.crate_dec_random_md_incremental_frame` | frame | len 219 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[6] (219 bytes) followed by RANDOM_MESSAGES[0] |
| `fefix.crate_dec_random_pair_second_frame` | frame | len 64 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::assortment_of_random_messages_is_ok` | RANDOM_MESSAGES[0] (64 bytes) followed by a partial second message |
| `fefix.crate_dec_no_final_separator_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_final_separator` | last field has no SOH |
| `fefix.crate_dec_no_final_separator_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_final_separator` | otherwise correct 9 and 10; only the trailing SOH is missing |
| `fefix.crate_dec_no_final_separator_frame` | frame | len 0 | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_final_separator` | 144 of 145 bytes; the frame is incomplete until the final SOH arrives |
| `fefix.crate_dec_must_end_with_separator_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_must_end_with_separator` | no trailing SOH (BodyLength 41 is correct; CheckSum 127 is the '\|' sum, SOH sum is 115) |
| `fefix.crate_dec_must_end_with_separator_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_must_end_with_separator` |  |
| `fefix.crate_dec_without_checksum_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_checksum` | no CheckSum (10) field |
| `fefix.crate_dec_without_checksum_parse` | parse | ok | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_checksum` | fields are well formed; only validate rejects it |
| `fefix.crate_dec_without_header_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_standard_header` | no BeginString (8) / BodyLength (9) |
| `fefix.crate_dec_without_header_frame` | frame | len error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::message_without_standard_header` | front is "35=", cannot start a message |
| `fefix.crate_dec_incorrect_body_length_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/decoder.rs::detect_incorrect_checksum` | despite the test name, BodyLength 43 is wrong (actual 40); CheckSum 146 also wrong (actual 001) |
| `fefix.crate_utils_checksum_digits_letters_validate` | validate | error | `fefix crate 0.7.0:src/tagvalue/utils.rs::correct_retrieval_of_checksum_digits` | upstream only extracts the last three bytes; "..." has no '=' and 10=ABC is not digits |
| `fefix.crate_utils_checksum_digits_parse` | parse | error | `fefix crate 0.7.0:src/tagvalue/utils.rs::correct_retrieval_of_checksum_digits` | field "..." has no '=' |
| `fefix.crate_checksum_single_soh` | checksum | 1 | `fefix crate 0.7.0:src/fix_values/checksum.rs::edges_cases` | CheckSum::compute(&[1]) == 1 (byte 0x01 is SOH) |
| `fefix.crate_checksum_two_soh` | checksum | 2 | `fefix crate 0.7.0:src/fix_values/checksum.rs::edges_cases` | derived from the [1] case: sum of two 0x01 bytes |

## philadelphia.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `philadelphia.message_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageTest.java::parse` | FIXMessage.fromString round-trips the body fields in order (no header/trailer) |
| `philadelphia.read_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::read` | minimal FIX.4.2 message with BodyLength 5 and CheckSum 181 is accepted |
| `philadelphia.read_fixt11_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readFixt11` | minimal FIXT.1.1 message (BeginString FIXT.1.1) is accepted |
| `philadelphia.read_frame` | frame | len 26 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::read` | whole buffer consumed as one message |
| `philadelphia.read_fixt11_frame` | frame | len 27 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readFixt11` | whole FIXT.1.1 buffer consumed as one message |
| `philadelphia.read_checksum` | checksum | 181 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::read` | CheckSum of 8=FIX.4.2\|9=5\|35=D\| is 181 |
| `philadelphia.read_fixt11_checksum` | checksum | 5 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readFixt11` | CheckSum of 8=FIXT.1.1\|9=5\|35=D\| is 5 |
| `philadelphia.garbled_checksum_validate` | validate | error | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readGarbledCheckSum` | CheckSum 000 is wrong (correct is 181); parser rejects with checksum enabled |
| `philadelphia.partial_begin_string_tag_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBeginStringTag` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_begin_string_value_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBeginStringValue` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_body_length_missing_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBodyLengthMissing` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_body_length_tag_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBodyLengthTag` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_body_length_value_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBodyLengthValue` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_body_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialBody` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_check_sum_missing_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialCheckSumMissing` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_check_sum_tag_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialCheckSumTag` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_check_sum_value_missing_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialCheckSumValueMissing` | truncated input: parser returns false and consumes nothing |
| `philadelphia.partial_check_sum_value_frame` | frame | len 0 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readPartialCheckSumValue` | truncated input: parser returns false and consumes nothing |
| `philadelphia.garbled_begin_string_frame` | frame | len error | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readGarbledBeginString` | 9= before 8=: no message produced; glz::fix::frame reports frame_error for a front that cannot start a message (docs/fix/api.md) |
| `philadelphia.garbled_body_length_frame` | frame | len error | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageParserTest.java::readGarbledBodyLength` | second field is 8= instead of 9=: no message produced; glz::fix::frame reports frame_error for a front that cannot start a message (docs/fix/api.md) |
| `philadelphia.heartbeat_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::heartbeat` | Heartbeat sent by initiator; exact wire bytes asserted by the test |
| `philadelphia.test_request_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::testRequest` | TestRequest sent by initiator; exact wire bytes asserted by the test |
| `philadelphia.receive_message_without_msg_seq_num_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveMessageWithoutMsgSeqNum` | Logout with Text containing spaces and parentheses; exact wire bytes asserted by the test |
| `philadelphia.receive_test_request_without_test_req_i_d_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveTestRequestWithoutTestReqID` | session-level Reject; exact wire bytes asserted by the test |
| `philadelphia.receive_resend_request_with_end_seq_no_smaller_than_last_msg_seq_num_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithEndSeqNoSmallerThanLastMsgSeqNum` | SequenceReset-GapFill; exact wire bytes asserted by the test |
| `philadelphia.receive_message_with_too_high_msg_seq_num_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveMessageWithTooHighMsgSeqNum` | ResendRequest; exact wire bytes asserted by the test |
| `philadelphia.send_logon_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::sendLogon` | Logon; CheckSum with leading zeros (004); exact wire bytes asserted by the test |
| `philadelphia.send_logon_with_reset_seq_num_flag_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::sendLogonWithResetSeqNumFlag` | Logon with ResetSeqNumFlag; exact wire bytes asserted by the test |
| `philadelphia.send_application_message_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::sendApplicationMessage` | NewOrderSingle, 3-digit BodyLength; exact wire bytes asserted by the test |
| `philadelphia.send_application_message_frame` | frame | len 94 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::sendApplicationMessage` | Logon followed by NewOrderSingle on the wire; first frame is the Logon |

## philadelphia_more.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `philadelphia.test_request_heartbeat_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::testRequest` | Heartbeat at 32.500 s sent before the TestRequest; SendingTime with non-zero millis, CheckSum 225 |
| `philadelphia.test_request_two_message_frame` | frame | len 82 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::testRequest` | Heartbeat followed by TestRequest on the wire; first frame is the 82-byte Heartbeat |
| `philadelphia.test_request_second_message_frame` | frame | len 108 | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::testRequest` | the TestRequest alone frames at its full length (86-byte body) |
| `philadelphia.receive_test_request_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveTestRequest` | Heartbeat answering TestRequest, echoes TestReqID(112)=foo |
| `philadelphia.resend_request_end_seq_no_equal_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithEndSeqNoEqualToLastMsgSeqNum` | SequenceReset-GapFill with NewSeqNo 5 |
| `philadelphia.resend_request_end_seq_no_larger_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithEndSeqNoLargerThanLastMsgSeqNum` | SequenceReset-GapFill with NewSeqNo 5 (EndSeqNo larger than last sent) |
| `philadelphia.resend_request_zero_end_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithZeroEndSeqNo` | SequenceReset-GapFill with NewSeqNo 3 (EndSeqNo 0 = infinity) |
| `philadelphia.resend_request_too_high_end_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithTooHighEndSeqNo` | SequenceReset-GapFill with NewSeqNo 3 (EndSeqNo beyond last sent) |
| `philadelphia.resend_request_without_begin_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithoutBeginSeqNo` | session Reject, SessionRejectReason 1, Text with spaces and parentheses |
| `philadelphia.resend_request_without_end_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithoutEndSeqNo` | session Reject for missing EndSeqNo |
| `philadelphia.resend_request_too_high_begin_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithTooHighBeginSeqNo` | session Reject, SessionRejectReason 5 (value out of range) |
| `philadelphia.sequence_reset_without_new_seq_no_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveSequenceResetResetWithoutNewSeqNo` | session Reject for SequenceReset without NewSeqNo |
| `philadelphia.logon_too_low_msg_seq_num_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveLogonWithTooLowMsgSeqNum` | Logout sent when Logon MsgSeqNum is too low |
| `philadelphia.logout_too_high_msg_seq_num_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveLogoutWithTooHighMsgSeqNum` | ResendRequest sent when Logout MsgSeqNum is too high |
| `philadelphia.send_logout_validate` | validate | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::sendLogout` | plain Logout with no Text |
| `philadelphia.body_without_msg_type_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveMessageWithoutMsgType` | one-field body (MsgType missing); tag=value scan succeeds |
| `philadelphia.body_sequence_reset_gap_fill_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveSequenceResetGapFill` | SequenceReset-GapFill body fields |
| `philadelphia.body_resend_request_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveResendRequestWithEndSeqNoSmallerThanLastMsgSeqNum` | ResendRequest body fields |
| `philadelphia.body_logon_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveLogon` | Logon body with CompIDs |
| `philadelphia.body_test_request_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveTestRequest` | TestRequest body with TestReqID |
| `philadelphia.body_full_buffer_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveFullBuffer` | Logout body with a 512-byte Text value |
| `philadelphia.body_too_long_unterminated_parse` | parse | error | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXInitiatorTest.java::receiveTooLongMessage` | 1024-byte Text with no closing SOH; last field is unterminated |
| `philadelphia.exceed_max_capacity_parse` | parse | ok | `paritytrading/philadelphia:libraries/core/src/test/java/com/paritytrading/philadelphia/FIXMessageTest.java::exceedMaxCapacityOnGet` | nine fields incl. tag 1 (Account); upstream overflows the FIXMessage field capacity, plain tag=value scan succeeds |

## simplefix.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `simplefix.basic_fix_message` | parse | ok | `da4089/simplefix:test/test_parser.py::test_basic_fix_message` | FixMessage(8=FIX.4.2,35=D,29=A).encode() parsed back; 8, 35, 29 values recovered |
| `simplefix.bad_tag` | parse | error | `da4089/simplefix:test/test_parser.py::test_bad_tag` | non-numeric tag 'xx' raises TagNotNumberError |
| `simplefix.int_value_zero` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_zero` | value 0 in 34; no 9 and loose 10=0, tag=value scan only |
| `simplefix.int_value_one` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_one` | value 1 in 34 |
| `simplefix.int_value_32bit` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_32bit` | value 2^32-1 kept verbatim |
| `simplefix.int_value_33bit` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_33bit` | value 2^32 kept verbatim |
| `simplefix.int_value_64bit` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_64bit` | value 2^64-1 kept verbatim |
| `simplefix.int_value_65bit` | parse | ok | `da4089/simplefix:test/test_parser.py::test_int_value_65bit` | value 2^64 kept verbatim (value text is not range-limited) |
| `simplefix.embedded_equals` | parse | ok | `da4089/simplefix:test/test_parser.py::test_embedded_equals_96_no_95` | only the first '=' splits tag from value: 96=ABC=DE; original (loose) 9 and 10 kept, scan only |
| `simplefix.cme_secdef_no_begin_string` | parse | ok | `da4089/simplefix:test/test_parser.py::test_cme_secdef` | first record of CME secdef file: no 8/9/10, repeated tags 865/1145; tag=value scan succeeds |
| `simplefix.string_with_equals` | parse | ok | `da4089/simplefix:test/test_message.py::test_string_with_equals` | single tag=value string; append_string("8=FIX.4.2") |
| `simplefix.string_without_equals` | parse | error | `da4089/simplefix:test/test_message.py::test_string_without_equals` | field with no '=' is rejected (ValueError) |
| `simplefix.string_with_bad_tag` | parse | error | `da4089/simplefix:test/test_message.py::test_string_with_bad_tag` | non-numeric tag 'foo' is rejected (ValueError) |
| `simplefix.header_field_order` | parse | ok | `da4089/simplefix:test/test_message.py::test_header_field` | raw-mode encoding output; field order preserved as on the wire |
| `simplefix.str_values` | parse | ok | `da4089/simplefix:test/test_message.py::test_str` | str(msg) output '1=1\|2=foo\|3=bar\|4=3.1415679' with SOH terminator added on last field |
| `simplefix.set_session_version` | validate | ok | `da4089/simplefix:test/test_message.py::test_set_session_version` | minimal heartbeat as encoded by simplefix; 9=5 and 10=163 verified |
| `simplefix.cooked_checksum` | validate | ok | `da4089/simplefix:test/test_message.py::test_cooked_checksum` | encoded message with BodyLength 16 and zero-padded CheckSum 048; verified |
| `simplefix.basic_fix_message_valid` | validate | ok | `da4089/simplefix:test/test_parser.py::test_basic_fix_message` | encode() output of 8=FIX.4.2,35=D,29=A (computed with python3, test builds it via FixMessage) |
| `simplefix.partial_string_complete` | validate | ok | `da4089/simplefix:test/test_parser.py::test_parse_partial_string` | message reassembled from two fragments; 9=5 and 10=161 verified |
| `simplefix.embedded_equals_fixed` | validate | ok | `da4089/simplefix:test/test_parser.py::test_embedded_equals_96_no_95` | Logon with '=' inside value 96; simplefix's loose 9=169/10=166 fixed to 9=101/10=088 |
| `simplefix.partial_string_first_fragment` | frame | len 0 | `da4089/simplefix:test/test_parser.py::test_parse_partial_string` | fragment ending inside BodyLength gives no message |
| `simplefix.partial_string_reassembled` | frame | len 26 | `da4089/simplefix:test/test_parser.py::test_parse_partial_string` | both fragments appended form one complete message |
| `simplefix.get_buffer_after_message` | frame | len 26 | `da4089/simplefix:test/test_parser.py::test_get_buffer` | whole buffer consumed by the message (get_buffer() returns empty afterwards) |
| `simplefix.empty_value_frame` | frame | len 30 | `da4089/simplefix:test/test_parser.py::test_empty_value` | message with empty value 29= frames normally; original 9=9 and 10=098 verified correct |
| `simplefix.leading_junk_pairs` | frame | len error | `da4089/simplefix:test/test_parser.py::test_leading_junk_pairs` | junk fields before 8= are skipped; frame_len is the length of the message itself; simplefix skips junk before 8=; glz::fix::frame does not skip and reports frame_error (docs/fix/api.md, Q1 settled by fix/core) |
| `simplefix.junk_pairs_only` | frame | len error | `da4089/simplefix:test/test_parser.py::test_junk_pairs` | stream of junk fields with no 8= gives no message; simplefix skips junk and waits; glz::fix::frame reports frame_error instead (docs/fix/api.md) |
| `simplefix.raw_data_packet_boundary_first` | frame | len 0 | `da4089/simplefix:test/test_parser.py::test_raw_data_ending_on_packet_boundary` | first packet ends right after raw data 96 (before its SOH): incomplete; 9 fixed from loose 169 to 84 |
| `simplefix.raw_data_packet_boundary_full` | frame | len 106 | `da4089/simplefix:test/test_parser.py::test_raw_data_ending_on_packet_boundary` | both packets: complete message with 95=6/96=ABC=DE; loose 9=169/10=166 fixed to 9=84/10=217 |
| `simplefix.checksum_heartbeat_44` | checksum | 163 | `da4089/simplefix:test/test_message.py::test_set_session_version` | expected 10=163 from encode() |
| `simplefix.checksum_cooked` | checksum | 48 | `da4089/simplefix:test/test_message.py::test_cooked_checksum` | expected 10=048 from encode() (two-digit value, zero-padded on the wire) |
| `simplefix.checksum_heartbeat_42` | checksum | 161 | `da4089/simplefix:test/test_parser.py::test_parse_partial_string` | 10=161 in the reassembled message |

## spec.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `spec.heartbeat_ok` | validate | ok | `spec` | minimal FIX.4.2 Heartbeat with correct 9 and 10 |
| `spec.new_order_single_ok` | validate | ok | `spec` | FIX.4.4 NewOrderSingle with correct 9 and 10 |
| `spec.fixt_logon_ok` | validate | ok | `spec` | FIXT.1.1 Logon (BeginString FIXT.1.1, 1137 DefaultApplVerID) |
| `spec.repeated_tag_ok` | validate | ok | `spec` | repeating group entries repeat a tag (55); framing still valid |
| `spec.bad_checksum` | validate | error | `spec` | CheckSum(10) off by one |
| `spec.bad_body_length_short` | validate | error | `spec` | BodyLength(9) one less than actual |
| `spec.bad_body_length_long` | validate | error | `spec` | BodyLength(9) one more than actual |
| `spec.body_length_non_numeric` | validate | error | `spec` | BodyLength(9) is not an integer |
| `spec.msgtype_not_third` | validate | error | `spec` | 35 must be the third field |
| `spec.begin_string_not_first` | validate | error | `spec` | 8 must be the first field |
| `spec.checksum_not_last` | validate | error | `spec` | a field after CheckSum(10) |
| `spec.checksum_two_digits` | validate | error | `spec` | CheckSum must be exactly three digits |
| `spec.missing_trailing_soh` | validate | error | `spec` | message must end with SOH after 10=nnn |
| `spec.missing_checksum` | validate | error | `spec` | no 10 field at all |
| `spec.empty_input` | validate | error | `spec` | empty message |
| `spec.parse_heartbeat_fields` | parse | ok | `spec` | scanner returns fields in order including header and trailer |
| `spec.parse_value_with_equals` | parse | ok | `spec` | only the first '=' splits tag from value |
| `spec.parse_long_tag` | parse | ok | `spec` | tags above 9999 are legal (user-defined range) |
| `spec.parse_missing_equals` | parse | error | `spec` | field without '=' |
| `spec.parse_empty_tag` | parse | error | `spec` | field with empty tag |
| `spec.parse_alpha_tag` | parse | error | `spec` | non-numeric tag |
| `spec.parse_negative_tag` | parse | error | `spec` | sign is not part of a tag |
| `spec.parse_leading_zero_tag` | parse | error (pending) | `spec` | tags are positive integers without leading zeros |
| `spec.parse_zero_tag` | parse | error | `spec` | tag 0 is not a valid tag |
| `spec.parse_unterminated` | parse | error | `spec` | last field missing SOH |
| `spec.frame_one` | frame | len 63 | `spec` | one complete message |
| `spec.frame_two` | frame | len 63 | `spec` | two messages back to back: length of the first |
| `spec.frame_trailing_partial` | frame | len 134 | `spec` | complete message followed by a partial one |
| `spec.frame_prefix_1` | frame | len 0 | `spec` | only the first 1 bytes of a message: incomplete |
| `spec.frame_prefix_2` | frame | len 0 | `spec` | only the first 2 bytes of a message: incomplete |
| `spec.frame_prefix_10` | frame | len 0 | `spec` | only the first 10 bytes of a message: incomplete |
| `spec.frame_prefix_56` | frame | len 0 | `spec` | only the first 56 bytes of a message: incomplete |
| `spec.frame_prefix_62` | frame | len 0 | `spec` | only the first 62 bytes of a message: incomplete |
| `spec.checksum_heartbeat` | checksum | 119 | `spec` | sum of all bytes before 10= mod 256 |
| `spec.checksum_empty` | checksum | 0 | `spec` | empty input sums to 0 |
| `spec.checksum_wraps` | checksum | 0 | `spec` | 256 bytes of 0x01 wrap to 0 |

## spec_more.fixv

| id | kind | expect | source | what it checks |
|---|---|---|---|---|
| `spec.cks_plus_one` | validate | error | `spec` | category from quickfixgo validation_test: CheckSum one above the true sum |
| `spec.cks_minus_one` | validate | error | `spec` | category from quickfixgo validation_test: CheckSum one below the true sum |
| `spec.cks_above_255` | validate | error | `spec` | category from quickfixgo validation_test: CheckSum value 256..999 can never match |
| `spec.cks_zero_mismatch` | validate | error | `spec` | category from quickfixgo validation_test: CheckSum 000 when the sum is not zero |
| `spec.cks_non_digit` | validate | error | `spec` | category from quickfixgo parser_test: CheckSum with a non-digit character |
| `spec.cks_four_digits` | validate | error | `spec` | category from fix8 utests/message_test: CheckSum written with four digits (leading zero) |
| `spec.cks_one_digit` | validate | error | `spec` | category from fix8 utests/message_test: CheckSum with a single digit (three are required) |
| `spec.cks_missing_value` | validate | error | `spec` | category from quickfixgo parser_test: CheckSum tag present with empty value |
| `spec.cks_trailer_absent` | validate | error | `spec` | category from quickfixgo parser_test: message ends without the CheckSum trailer |
| `spec.cks_signed` | validate | error | `spec` | category from quickfixgo validation_test: CheckSum with a leading plus sign |
| `spec.cks_bytes_logout` | checksum | 252 | `spec` | checksum over a Logout prefix (sum mod 256) |
| `spec.cks_bytes_soh_only` | checksum | 1 | `spec` | checksum of a single SOH byte is 1 |
| `spec.cks_bytes_wrap_exact` | checksum | 0 | `spec` | four 0x40 bytes sum to 256, which wraps to 0 |
| `spec.bl_zero` | validate | error | `spec` | category from quickfixgo validation_test: BodyLength 0 while a body is present |
| `spec.bl_negative` | validate | error | `spec` | category from quickfixgo parser_test: negative BodyLength |
| `spec.bl_huge` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength larger than any real message |
| `spec.bl_ten_digits` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength with ten digits (overflow range) |
| `spec.bl_leading_plus` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength with a leading plus sign |
| `spec.bl_leading_space` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength with a leading space |
| `spec.bl_trailing_space` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength with a trailing space |
| `spec.bl_empty` | validate | error | `spec` | category from quickfixgo parser_test: BodyLength tag with empty value |
| `spec.soh_missing_after_9` | validate | error | `spec` | category from quickfixgo parser_test: SOH missing between BodyLength and MsgType |
| `spec.parse_soh_missing` | parse | ok | `spec` | category from quickfixgo parser_test: SOH missing between fields: the second field becomes part of the first value |
| `spec.double_soh` | validate | error | `spec` | category from quickfixgo parser_test: two SOH in a row (empty field) in the body |
| `spec.equals_first` | validate | error | `spec` | category from quickfixgo parser_test: a field that starts with '=' (no tag) |
| `spec.body_length_repeated` | validate | error | `spec` | category from quickfixgo validation_test: BodyLength (9) appears twice in the header |
| `spec.msgtype_missing` | validate | error | `spec` | category from quickfixgo validation_test: MsgType (35) absent; 49 comes third |
| `spec.msgtype_empty` | validate | error | `spec` | category from quickfixgo validation_test: MsgType (35) present with empty value |
| `spec.begin_string_empty` | validate | error | `spec` | category from quickfixgo validation_test: BeginString (8) with empty value |
| `spec.value_with_spaces_ok` | validate | ok | `spec` | category from fix8 utests/message_test: free text value containing spaces is legal |
| `spec.fixt_heartbeat_ok` | validate | ok | `spec` | category from quickfix test/definitions/server/fix44 (FIXT.1.1 session): FIXT.1.1 Heartbeat with TestReqID |
| `spec.fixt_exec_report_ok` | validate | ok | `spec` | category from quickfix test/definitions/server/fix44 (FIXT.1.1 app): FIXT.1.1 ExecutionReport with ApplVerID 1128 |
| `spec.fixt_bad_checksum` | validate | error | `spec` | category from quickfix test/definitions/server/fix44 (FIXT.1.1 session): FIXT.1.1 Logon with corrupted CheckSum |
| `spec.parse_value_spaces` | parse | ok | `spec` | category from fix8 utests/message_test: value with embedded and edge spaces is kept verbatim |
| `spec.parse_tag_leading_space` | parse | error | `spec` | category from quickfixgo parser_test: tag with a leading space |
| `spec.parse_tag_trailing_space` | parse | error | `spec` | category from quickfixgo parser_test: tag with a trailing space before = |
| `spec.parse_tag_inner_space` | parse | error | `spec` | category from quickfixgo parser_test: tag with a space between digits |
| `spec.parse_double_soh` | parse | error | `spec` | category from quickfixgo parser_test: empty field between two SOH |
| `spec.parse_leading_soh` | parse | error | `spec` | category from quickfixgo parser_test: message starts with SOH |
| `spec.parse_empty_value` | parse | error | `spec` | category from quickfixgo message_test: tag with empty value |
| `spec.parse_max_tag` | parse | ok | `spec` | largest accepted tag number 999999999 |
| `spec.parse_body_length_repeated` | parse | ok | `spec` | category from quickfixgo validation_test: repeated 9 is not a scan error (structure is validate's job) |
| `spec.rg_md_snapshot_valid` | validate | ok | `spec` | category from quickfixgo repeating_group_test: NoMDEntries=3 with three entries starting at 269 |
| `spec.rg_md_snapshot_fields` | parse | ok | `spec` | category from quickfixgo repeating_group_test: NoMDEntries=3 with three entries starting at 269; exact field list in wire order |
| `spec.rg_zero_count_valid` | validate | ok | `spec` | category from quickfixgo repeating_group_test: NoPartyIDs=0 with no entries |
| `spec.rg_zero_count_fields` | parse | ok | `spec` | category from quickfixgo repeating_group_test: NoPartyIDs=0 with no entries; exact field list in wire order |
| `spec.rg_nested_valid` | validate | ok | `spec` | category from quickfixgo repeating_group_test: nested group NoPartyIDs=2, second party with NoPartySubIDs=2 |
| `spec.rg_nested_fields` | parse | ok | `spec` | category from quickfixgo repeating_group_test: nested group NoPartyIDs=2, second party with NoPartySubIDs=2; exact field list in wire order |
| `spec.rg_fixt_alloc_valid` | validate | ok | `spec` | category from quickfixgo repeating_group_test: FIXT.1.1 message with NoAllocs=2 then fields after the group |
| `spec.rg_fixt_alloc_fields` | parse | ok | `spec` | category from quickfixgo repeating_group_test: FIXT.1.1 message with NoAllocs=2 then fields after the group; exact field list in wire order |
| `spec.rg_body_length_off` | validate | error | `spec` | category from quickfixgo repeating_group_test: otherwise valid group message whose BodyLength misses one entry byte |
| `spec.frame_garbage_before` | frame | len error | `spec` | category from quickfixgo parser_test: garbage bytes before the first message |
| `spec.frame_garbage_between` | frame | len 69 | `spec` | category from quickfixgo parser_test: garbage between messages does not affect the first frame |
| `spec.frame_garbage_after_first` | frame | len error | `spec` | category from quickfixgo parser_test: stream positioned at garbage left between two messages |
| `spec.frame_soh_before` | frame | len error | `spec` | category from quickfixgo parser_test: stray SOH before the message |
| `spec.frame_split_after_begin` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 10 |
| `spec.frame_split_mid_9_tag` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 11 |
| `spec.frame_split_after_9_eq` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 12 |
| `spec.frame_split_mid_9_value` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 13 |
| `spec.frame_split_after_body_length` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 15 |
| `spec.frame_split_after_msgtype` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 20 |
| `spec.frame_split_before_trailer` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 62 |
| `spec.frame_split_after_10_eq` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 65 |
| `spec.frame_split_before_last_soh` | frame | len 0 | `spec` | category from quickfixgo parser_test: message split across reads, first read ends at byte 68 |
| `spec.frame_split_then_complete` | frame | len 69 | `spec` | category from quickfixgo parser_test: message split across reads, second read completes it |
| `spec.frame_body_length_past_end` | frame | len 0 | `spec` | category from quickfixgo parser_test: BodyLength points past the end of the available bytes |
| `spec.frame_body_length_short` | frame | len error | `spec` | category from quickfixgo parser_test: BodyLength too small so 10= is not where it says |
| `spec.frame_body_length_plus` | frame | len error | `spec` | category from quickfixgo parser_test: BodyLength with leading plus cannot frame |
| `spec.frame_body_length_space` | frame | len error | `spec` | category from quickfixgo parser_test: BodyLength with leading space cannot frame |
| `spec.frame_body_length_negative` | frame | len error | `spec` | category from quickfixgo parser_test: negative BodyLength cannot frame |
| `spec.frame_body_length_empty` | frame | len error | `spec` | category from quickfixgo parser_test: empty BodyLength cannot frame |
| `spec.frame_body_length_huge_unterminated` | frame | len error | `spec` | category from quickfixgo parser_test: BodyLength digits run past nine bytes without SOH |
| `spec.frame_body_length_huge` | frame | len 0 | `spec` | category from quickfixgo parser_test: nine-digit BodyLength waits for more bytes |
| `spec.frame_second_not_9` | frame | len error | `spec` | category from quickfixgo parser_test: second field is 35 instead of 9 |
| `spec.frame_first_not_8` | frame | len error | `spec` | category from quickfixgo parser_test: stream starts with tag 9 |
| `spec.frame_fixt_one` | frame | len 79 | `spec` | FIXT.1.1 message frames on BodyLength |
| `spec.frame_group_message` | frame | len 223 | `spec` | category from quickfixgo repeating_group_test: message with nested repeating groups frames whole |
| `spec.frame_two_digit_checksum` | frame | len error | `spec` | category from fix8 utests/message_test: trailer "10=" with two digits misplaces the final SOH |
