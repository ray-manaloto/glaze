// Glaze Library
// For the license information refer to glaze.hpp
//
// GENERATED FILE - do not edit. Produced by util/fix_codegen/fix_codegen.py from the
// FIX Orchestra repository file for FIXT (version FIX.5.0SP2_EP247).
// Source data file: FIXTSession.xml (https://github.com/FIXTradingCommunity)
// Copyright (c) FIX Protocol Ltd., licensed under the Apache License, Version 2.0;
// see LICENSE-FIX-ORCHESTRA beside this file.

#pragma once

#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/core/common.hpp"
#include "glaze/fix/types.hpp"

namespace glz::fix::fixt11_typed
{
   inline constexpr std::string_view begin_string = "FIXT.1.1"; // tag 8 on the wire
   inline constexpr std::string_view dictionary_version = "FIXT";

   namespace tag
   {
      inline constexpr uint32_t BeginSeqNo = 7;
      inline constexpr uint32_t BeginString = 8;
      inline constexpr uint32_t BodyLength = 9;
      inline constexpr uint32_t CheckSum = 10;
      inline constexpr uint32_t EndSeqNo = 16;
      inline constexpr uint32_t MsgSeqNum = 34;
      inline constexpr uint32_t MsgType = 35;
      inline constexpr uint32_t NewSeqNo = 36;
      inline constexpr uint32_t PossDupFlag = 43;
      inline constexpr uint32_t RefSeqNum = 45;
      inline constexpr uint32_t SenderCompID = 49;
      inline constexpr uint32_t SenderSubID = 50;
      inline constexpr uint32_t SendingTime = 52;
      inline constexpr uint32_t TargetCompID = 56;
      inline constexpr uint32_t TargetSubID = 57;
      inline constexpr uint32_t Text = 58;
      inline constexpr uint32_t Signature = 89;
      inline constexpr uint32_t SecureDataLen = 90;
      inline constexpr uint32_t SecureData = 91;
      inline constexpr uint32_t SignatureLength = 93;
      inline constexpr uint32_t RawDataLength = 95;
      inline constexpr uint32_t RawData = 96;
      inline constexpr uint32_t PossResend = 97;
      inline constexpr uint32_t EncryptMethod = 98;
      inline constexpr uint32_t HeartBtInt = 108;
      inline constexpr uint32_t TestReqID = 112;
      inline constexpr uint32_t OnBehalfOfCompID = 115;
      inline constexpr uint32_t OnBehalfOfSubID = 116;
      inline constexpr uint32_t OrigSendingTime = 122;
      inline constexpr uint32_t GapFillFlag = 123;
      inline constexpr uint32_t DeliverToCompID = 128;
      inline constexpr uint32_t DeliverToSubID = 129;
      inline constexpr uint32_t ResetSeqNumFlag = 141;
      inline constexpr uint32_t SenderLocationID = 142;
      inline constexpr uint32_t TargetLocationID = 143;
      inline constexpr uint32_t OnBehalfOfLocationID = 144;
      inline constexpr uint32_t DeliverToLocationID = 145;
      inline constexpr uint32_t XmlDataLen = 212;
      inline constexpr uint32_t XmlData = 213;
      inline constexpr uint32_t MessageEncoding = 347;
      inline constexpr uint32_t EncodedTextLen = 354;
      inline constexpr uint32_t EncodedText = 355;
      inline constexpr uint32_t LastMsgSeqNumProcessed = 369;
      inline constexpr uint32_t RefTagID = 371;
      inline constexpr uint32_t RefMsgType = 372;
      inline constexpr uint32_t SessionRejectReason = 373;
      inline constexpr uint32_t MaxMessageSize = 383;
      inline constexpr uint32_t NoMsgTypes = 384;
      inline constexpr uint32_t MsgDirection = 385;
      inline constexpr uint32_t TestMessageIndicator = 464;
      inline constexpr uint32_t Username = 553;
      inline constexpr uint32_t Password = 554;
      inline constexpr uint32_t NoHops = 627;
      inline constexpr uint32_t HopCompID = 628;
      inline constexpr uint32_t HopSendingTime = 629;
      inline constexpr uint32_t HopRefID = 630;
      inline constexpr uint32_t NextExpectedMsgSeqNum = 789;
      inline constexpr uint32_t NewPassword = 925;
      inline constexpr uint32_t ApplVerID = 1128;
      inline constexpr uint32_t CstmApplVerID = 1129;
      inline constexpr uint32_t RefApplVerID = 1130;
      inline constexpr uint32_t RefCstmApplVerID = 1131;
      inline constexpr uint32_t DefaultApplVerID = 1137;
      inline constexpr uint32_t ApplExtID = 1156;
      inline constexpr uint32_t EncryptedPasswordMethod = 1400;
      inline constexpr uint32_t EncryptedPasswordLen = 1401;
      inline constexpr uint32_t EncryptedPassword = 1402;
      inline constexpr uint32_t EncryptedNewPasswordLen = 1403;
      inline constexpr uint32_t EncryptedNewPassword = 1404;
      inline constexpr uint32_t RefApplExtID = 1406;
      inline constexpr uint32_t DefaultApplExtID = 1407;
      inline constexpr uint32_t DefaultCstmApplVerID = 1408;
      inline constexpr uint32_t SessionStatus = 1409;
      inline constexpr uint32_t DefaultVerIndicator = 1410;
      inline constexpr uint32_t FIXEngineName = 1600;
      inline constexpr uint32_t FIXEngineVersion = 1601;
      inline constexpr uint32_t FIXEngineVendor = 1602;
      inline constexpr uint32_t ApplicationSystemName = 1603;
      inline constexpr uint32_t ApplicationSystemVersion = 1604;
      inline constexpr uint32_t ApplicationSystemVendor = 1605;
      inline constexpr uint32_t ApplLevelRecoveryIndicator = 1744;
      inline constexpr uint32_t NoAttachments = 2104;
      inline constexpr uint32_t AttachmentName = 2105;
      inline constexpr uint32_t AttachmentMediaType = 2106;
      inline constexpr uint32_t AttachmentClassification = 2107;
      inline constexpr uint32_t AttachmentExternalURL = 2108;
      inline constexpr uint32_t AttachmentEncodingType = 2109;
      inline constexpr uint32_t UnencodedAttachmentLen = 2110;
      inline constexpr uint32_t EncodedAttachmentLen = 2111;
      inline constexpr uint32_t EncodedAttachment = 2112;
      inline constexpr uint32_t NoAttachmentKeywords = 2113;
      inline constexpr uint32_t AttachmentKeyword = 2114;
   }

   // ApplLevelRecoveryIndicatorCodeSet (int)
   enum class ApplLevelRecoveryIndicator : int32_t {
      NoApplRecoveryNeeded = 0,
      ApplRecoveryNeeded = 1,
   };
   // ApplVerIDCodeSet (String)
   enum class ApplVerID : uint16_t {
      FIX27 = 0,
      FIX30 = 1,
      FIX40 = 2,
      FIX41 = 3,
      FIX42 = 4,
      FIX43 = 5,
      FIX44 = 6,
      FIX50 = 7,
      FIX50SP1 = 8,
      FIX50SP2 = 9,
      FIXLatest = 10,
   };
   // AttachmentEncodingTypeCodeSet (int)
   enum class AttachmentEncodingType : int32_t {
      Base64 = 0,
      RawBinary = 1,
   };
   // EncryptMethodCodeSet (int)
   enum class EncryptMethod : int32_t {
      None = 0,
      PKCS = 1,
      DES = 2,
      PKCSDES = 3,
      PGPDES = 4,
      PGPDESMD5 = 5,
      PEM = 6,
   };
   // GapFillFlagCodeSet (Boolean)
   enum class GapFillFlag : uint16_t {
      SequenceReset = 0,
      GapFillMessage = 1,
   };
   // MsgDirectionCodeSet (char)
   enum class MsgDirection : char {
      Receive = 'R',
      Send = 'S',
   };
   // MsgTypeCodeSet (String)
   enum class MsgType : uint16_t {
      Heartbeat = 0,
      TestRequest = 1,
      ResendRequest = 2,
      Reject = 3,
      SequenceReset = 4,
      Logout = 5,
      Logon = 6,
      BusinessMessageReject = 7,
      XMLnonFIX = 8,
   };
   // PossDupFlagCodeSet (Boolean)
   enum class PossDupFlag : uint16_t {
      OriginalTransmission = 0,
      PossibleDuplicate = 1,
   };
   // PossResendCodeSet (Boolean)
   enum class PossResend : uint16_t {
      OriginalTransmission = 0,
      PossibleResend = 1,
   };
   // ResetSeqNumFlagCodeSet (Boolean)
   enum class ResetSeqNumFlag : uint16_t {
      No = 0,
      Yes = 1,
   };
   // SessionRejectReasonCodeSet (int)
   enum class SessionRejectReason : int32_t {
      InvalidTagNumber = 0,
      RequiredTagMissing = 1,
      TagNotDefinedForThisMessageType = 2,
      UndefinedTag = 3,
      TagSpecifiedWithoutAValue = 4,
      ValueIsIncorrect = 5,
      IncorrectDataFormatForValue = 6,
      DecryptionProblem = 7,
      SignatureProblem = 8,
      CompIDProblem = 9,
      SendingTimeAccuracyProblem = 10,
      InvalidMsgType = 11,
      XMLValidationError = 12,
      TagAppearsMoreThanOnce = 13,
      TagSpecifiedOutOfRequiredOrder = 14,
      RepeatingGroupFieldsOutOfOrder = 15,
      IncorrectNumInGroupCountForRepeatingGroup = 16,
      FieldDelimiterInFieldValue = 17,
      InvalidUnsupportedAppVersion = 18,
      Other = 99,
   };
   // SessionStatusCodeSet (int)
   enum class SessionStatus : int32_t {
      SessionActive = 0,
      SessionPasswordChanged = 1,
      SessionPasswordDueToExpire = 2,
      NewSessionPasswordDoesNotComplyWithPolicy = 3,
      SessionLogoutComplete = 4,
      InvalidUsernameOrPassword = 5,
      AccountLocked = 6,
      LogonsAreNotAllowedAtThisTime = 7,
      PasswordExpired = 8,
      ReceivedMsgSeqNumTooLow = 9,
      ReceivedNextExpectedMsgSeqNumTooHigh = 10,
   };
   // TestMessageIndicatorCodeSet (Boolean)
   enum class TestMessageIndicator : uint16_t {
      False = 0,
      True = 1,
   };

   // ---- repeating groups ----
   struct HopGrp
   {
      std::optional<std::string> hop_comp_id{};
      std::optional<glz::fix::utc_timestamp> hop_sending_time{};
      std::optional<int64_t> hop_ref_id{};
      bool operator==(const HopGrp&) const = default;
   };
   struct MsgTypeGrp
   {
      std::optional<std::string> ref_msg_type{};
      std::optional<MsgDirection> msg_direction{};
      std::optional<std::string> ref_appl_ver_id{};
      std::optional<int64_t> ref_appl_ext_id{};
      std::optional<std::string> ref_cstm_appl_ver_id{};
      std::optional<bool> default_ver_indicator{};
      bool operator==(const MsgTypeGrp&) const = default;
   };
   struct AttachmentKeywordGrp
   {
      std::optional<std::string> attachment_keyword{};
      bool operator==(const AttachmentKeywordGrp&) const = default;
   };
   struct AttachmentGrp
   {
      std::optional<std::string> attachment_name{};
      std::optional<std::string> attachment_media_type{};
      std::optional<std::string> attachment_classification{};
      std::optional<std::string> attachment_external_url{};
      std::optional<AttachmentEncodingType> attachment_encoding_type{};
      std::optional<int64_t> unencoded_attachment_len{};
      std::optional<int64_t> encoded_attachment_len{};
      std::optional<std::string> encoded_attachment{};
      std::vector<AttachmentKeywordGrp> no_attachment_keywords{};
      bool operator==(const AttachmentGrp&) const = default;
   };

   // ---- components (flattened) ----
   struct StandardHeader
   {
      std::string begin_string{};
      int64_t body_length{};
      std::string msg_type{};
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      bool operator==(const StandardHeader&) const = default;
   };
   struct StandardTrailer
   {
      std::optional<int64_t> signature_length{};
      std::optional<std::string> signature{};
      std::string check_sum{};
      bool operator==(const StandardTrailer&) const = default;
   };

   // ---- messages ----
   struct Heartbeat
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      std::optional<std::string> test_req_id{};
      bool operator==(const Heartbeat&) const = default;
   };
   struct TestRequest
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      std::string test_req_id{};
      bool operator==(const TestRequest&) const = default;
   };
   struct ResendRequest
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      int64_t begin_seq_no{};
      int64_t end_seq_no{};
      bool operator==(const ResendRequest&) const = default;
   };
   struct Reject
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      int64_t ref_seq_num{};
      std::optional<int64_t> ref_tag_id{};
      std::optional<std::string> ref_msg_type{};
      std::optional<std::string> ref_appl_ver_id{};
      std::optional<int64_t> ref_appl_ext_id{};
      std::optional<std::string> ref_cstm_appl_ver_id{};
      std::optional<SessionRejectReason> session_reject_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Reject&) const = default;
   };
   struct SequenceReset
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      std::optional<bool> gap_fill_flag{};
      int64_t new_seq_no{};
      std::optional<ApplLevelRecoveryIndicator> appl_level_recovery_indicator{};
      bool operator==(const SequenceReset&) const = default;
   };
   struct Logout
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      std::optional<SessionStatus> session_status{};
      std::optional<int64_t> next_expected_msg_seq_num{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Logout&) const = default;
   };
   struct Logon
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      EncryptMethod encrypt_method{};
      int64_t heart_bt_int{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      std::optional<bool> reset_seq_num_flag{};
      std::optional<int64_t> next_expected_msg_seq_num{};
      std::optional<int64_t> max_message_size{};
      std::vector<MsgTypeGrp> no_msg_types{};
      std::optional<bool> test_message_indicator{};
      std::optional<std::string> username{};
      std::optional<std::string> password{};
      std::optional<std::string> new_password{};
      std::optional<int64_t> encrypted_password_method{};
      std::optional<int64_t> encrypted_password_len{};
      std::optional<std::string> encrypted_password{};
      std::optional<int64_t> encrypted_new_password_len{};
      std::optional<std::string> encrypted_new_password{};
      std::optional<SessionStatus> session_status{};
      std::string default_appl_ver_id{};
      std::optional<int64_t> default_appl_ext_id{};
      std::optional<std::string> default_cstm_appl_ver_id{};
      std::optional<std::string> fix_engine_name{};
      std::optional<std::string> fix_engine_version{};
      std::optional<std::string> fix_engine_vendor{};
      std::optional<std::string> application_system_name{};
      std::optional<std::string> application_system_version{};
      std::optional<std::string> application_system_vendor{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Logon&) const = default;
   };
   struct XMLnonFIX
   {
      std::optional<std::string> appl_ver_id{};
      std::optional<int64_t> appl_ext_id{};
      std::optional<std::string> cstm_appl_ver_id{};
      std::string sender_comp_id{};
      std::string target_comp_id{};
      std::optional<std::string> on_behalf_of_comp_id{};
      std::optional<std::string> deliver_to_comp_id{};
      std::optional<int64_t> secure_data_len{};
      std::optional<std::string> secure_data{};
      int64_t msg_seq_num{};
      std::optional<std::string> sender_sub_id{};
      std::optional<std::string> sender_location_id{};
      std::optional<std::string> target_sub_id{};
      std::optional<std::string> target_location_id{};
      std::optional<std::string> on_behalf_of_sub_id{};
      std::optional<std::string> on_behalf_of_location_id{};
      std::optional<std::string> deliver_to_sub_id{};
      std::optional<std::string> deliver_to_location_id{};
      std::optional<bool> poss_dup_flag{};
      std::optional<bool> poss_resend{};
      glz::fix::utc_timestamp sending_time{};
      std::optional<glz::fix::utc_timestamp> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::vector<HopGrp> no_hops{};
      std::vector<AttachmentGrp> no_attachments{};
      bool operator==(const XMLnonFIX&) const = default;
   };
}

template <>
struct glz::meta<glz::fix::fixt11_typed::ApplLevelRecoveryIndicator>
{
   using enum glz::fix::fixt11_typed::ApplLevelRecoveryIndicator;
   static constexpr auto value = glz::enumerate(NoApplRecoveryNeeded, ApplRecoveryNeeded);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::ApplVerID>
{
   using enum glz::fix::fixt11_typed::ApplVerID;
   static constexpr auto value = glz::enumerate(FIX27, FIX30, FIX40, FIX41, FIX42, FIX43, FIX44, FIX50, FIX50SP1, FIX50SP2, FIXLatest);
   static constexpr std::array<std::string_view, 11> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::AttachmentEncodingType>
{
   using enum glz::fix::fixt11_typed::AttachmentEncodingType;
   static constexpr auto value = glz::enumerate(Base64, RawBinary);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::EncryptMethod>
{
   using enum glz::fix::fixt11_typed::EncryptMethod;
   static constexpr auto value = glz::enumerate(None, PKCS, DES, PKCSDES, PGPDES, PGPDESMD5, PEM);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::GapFillFlag>
{
   using enum glz::fix::fixt11_typed::GapFillFlag;
   static constexpr auto value = glz::enumerate(SequenceReset, GapFillMessage);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::MsgDirection>
{
   using enum glz::fix::fixt11_typed::MsgDirection;
   static constexpr auto value = glz::enumerate(Receive, Send);
   static constexpr std::array<std::string_view, 2> fix_values{"R", "S"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::MsgType>
{
   using enum glz::fix::fixt11_typed::MsgType;
   static constexpr auto value = glz::enumerate(Heartbeat, TestRequest, ResendRequest, Reject, SequenceReset, Logout, Logon, BusinessMessageReject, XMLnonFIX);
   static constexpr std::array<std::string_view, 9> fix_values{"0", "1", "2", "3", "4", "5", "A", "j", "n"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::PossDupFlag>
{
   using enum glz::fix::fixt11_typed::PossDupFlag;
   static constexpr auto value = glz::enumerate(OriginalTransmission, PossibleDuplicate);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::PossResend>
{
   using enum glz::fix::fixt11_typed::PossResend;
   static constexpr auto value = glz::enumerate(OriginalTransmission, PossibleResend);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::ResetSeqNumFlag>
{
   using enum glz::fix::fixt11_typed::ResetSeqNumFlag;
   static constexpr auto value = glz::enumerate(No, Yes);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::SessionRejectReason>
{
   using enum glz::fix::fixt11_typed::SessionRejectReason;
   static constexpr auto value = glz::enumerate(InvalidTagNumber, RequiredTagMissing, TagNotDefinedForThisMessageType, UndefinedTag, TagSpecifiedWithoutAValue, ValueIsIncorrect, IncorrectDataFormatForValue, DecryptionProblem, SignatureProblem, CompIDProblem, SendingTimeAccuracyProblem, InvalidMsgType, XMLValidationError, TagAppearsMoreThanOnce, TagSpecifiedOutOfRequiredOrder, RepeatingGroupFieldsOutOfOrder, IncorrectNumInGroupCountForRepeatingGroup, FieldDelimiterInFieldValue, InvalidUnsupportedAppVersion, Other);
   static constexpr std::array<std::string_view, 20> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "99"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::SessionStatus>
{
   using enum glz::fix::fixt11_typed::SessionStatus;
   static constexpr auto value = glz::enumerate(SessionActive, SessionPasswordChanged, SessionPasswordDueToExpire, NewSessionPasswordDoesNotComplyWithPolicy, SessionLogoutComplete, InvalidUsernameOrPassword, AccountLocked, LogonsAreNotAllowedAtThisTime, PasswordExpired, ReceivedMsgSeqNumTooLow, ReceivedNextExpectedMsgSeqNumTooHigh);
   static constexpr std::array<std::string_view, 11> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
};
template <>
struct glz::meta<glz::fix::fixt11_typed::TestMessageIndicator>
{
   using enum glz::fix::fixt11_typed::TestMessageIndicator;
   static constexpr auto value = glz::enumerate(False, True);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};

template <>
struct glz::meta<glz::fix::fixt11_typed::HopGrp>
{
   using T = glz::fix::fixt11_typed::HopGrp;
   static constexpr auto value = glz::object("628", &T::hop_comp_id, "629", &T::hop_sending_time, "630", &T::hop_ref_id);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::StandardHeader>
{
   using T = glz::fix::fixt11_typed::StandardHeader;
   static constexpr auto value = glz::object("8", &T::begin_string, "9", &T::body_length, "35", &T::msg_type, "1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::StandardTrailer>
{
   using T = glz::fix::fixt11_typed::StandardTrailer;
   static constexpr auto value = glz::object("93", &T::signature_length, "89", &T::signature, "10", &T::check_sum);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::Heartbeat>
{
   using T = glz::fix::fixt11_typed::Heartbeat;
   static constexpr std::string_view fix_msg_type = "0";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::TestRequest>
{
   using T = glz::fix::fixt11_typed::TestRequest;
   static constexpr std::string_view fix_msg_type = "1";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::ResendRequest>
{
   using T = glz::fix::fixt11_typed::ResendRequest;
   static constexpr std::string_view fix_msg_type = "2";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "7", &T::begin_seq_no, "16", &T::end_seq_no);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::Reject>
{
   using T = glz::fix::fixt11_typed::Reject;
   static constexpr std::string_view fix_msg_type = "3";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "45", &T::ref_seq_num, "371", &T::ref_tag_id, "372", &T::ref_msg_type, "1130", &T::ref_appl_ver_id, "1406", &T::ref_appl_ext_id, "1131", &T::ref_cstm_appl_ver_id, "373", &T::session_reject_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::SequenceReset>
{
   using T = glz::fix::fixt11_typed::SequenceReset;
   static constexpr std::string_view fix_msg_type = "4";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "123", &T::gap_fill_flag, "36", &T::new_seq_no, "1744", &T::appl_level_recovery_indicator);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::Logout>
{
   using T = glz::fix::fixt11_typed::Logout;
   static constexpr std::string_view fix_msg_type = "5";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "1409", &T::session_status, "789", &T::next_expected_msg_seq_num, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::MsgTypeGrp>
{
   using T = glz::fix::fixt11_typed::MsgTypeGrp;
   static constexpr auto value = glz::object("372", &T::ref_msg_type, "385", &T::msg_direction, "1130", &T::ref_appl_ver_id, "1406", &T::ref_appl_ext_id, "1131", &T::ref_cstm_appl_ver_id, "1410", &T::default_ver_indicator);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::Logon>
{
   using T = glz::fix::fixt11_typed::Logon;
   static constexpr std::string_view fix_msg_type = "A";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "98", &T::encrypt_method, "108", &T::heart_bt_int, "95", &T::raw_data_length, "96", &T::raw_data, "141", &T::reset_seq_num_flag, "789", &T::next_expected_msg_seq_num, "383", &T::max_message_size, "384", &T::no_msg_types, "464", &T::test_message_indicator, "553", &T::username, "554", &T::password, "925", &T::new_password, "1400", &T::encrypted_password_method, "1401", &T::encrypted_password_len, "1402", &T::encrypted_password, "1403", &T::encrypted_new_password_len, "1404", &T::encrypted_new_password, "1409", &T::session_status, "1137", &T::default_appl_ver_id, "1407", &T::default_appl_ext_id, "1408", &T::default_cstm_appl_ver_id, "1600", &T::fix_engine_name, "1601", &T::fix_engine_version, "1602", &T::fix_engine_vendor, "1603", &T::application_system_name, "1604", &T::application_system_version, "1605", &T::application_system_vendor, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::AttachmentKeywordGrp>
{
   using T = glz::fix::fixt11_typed::AttachmentKeywordGrp;
   static constexpr auto value = glz::object("2114", &T::attachment_keyword);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::AttachmentGrp>
{
   using T = glz::fix::fixt11_typed::AttachmentGrp;
   static constexpr auto value = glz::object("2105", &T::attachment_name, "2106", &T::attachment_media_type, "2107", &T::attachment_classification, "2108", &T::attachment_external_url, "2109", &T::attachment_encoding_type, "2110", &T::unencoded_attachment_len, "2111", &T::encoded_attachment_len, "2112", &T::encoded_attachment, "2113", &T::no_attachment_keywords);
};
template <>
struct glz::meta<glz::fix::fixt11_typed::XMLnonFIX>
{
   using T = glz::fix::fixt11_typed::XMLnonFIX;
   static constexpr std::string_view fix_msg_type = "n";
   static constexpr std::string_view fix_begin_string = "FIXT.1.1";
   static constexpr auto value = glz::object("1128", &T::appl_ver_id, "1156", &T::appl_ext_id, "1129", &T::cstm_appl_ver_id, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops, "2104", &T::no_attachments);
};
