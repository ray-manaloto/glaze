// Glaze Library
// For the license information refer to glaze.hpp
//
// GENERATED FILE - do not edit. Produced by util/fix_codegen/fix_codegen.py from the
// FIX Orchestra repository file for FIX.4.2 (version FIX.4.2_EP310).
// Source data file: OrchestraFIX42.xml (https://github.com/FIXTradingCommunity)
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

namespace glz::fix::fix42
{
   inline constexpr std::string_view begin_string = "FIX.4.2";

   namespace tag
   {
      inline constexpr uint32_t Account = 1;
      inline constexpr uint32_t AdvId = 2;
      inline constexpr uint32_t AdvRefID = 3;
      inline constexpr uint32_t AdvSide = 4;
      inline constexpr uint32_t AdvTransType = 5;
      inline constexpr uint32_t AvgPx = 6;
      inline constexpr uint32_t BeginSeqNo = 7;
      inline constexpr uint32_t BeginString = 8;
      inline constexpr uint32_t BodyLength = 9;
      inline constexpr uint32_t CheckSum = 10;
      inline constexpr uint32_t ClOrdID = 11;
      inline constexpr uint32_t Commission = 12;
      inline constexpr uint32_t CommType = 13;
      inline constexpr uint32_t CumQty = 14;
      inline constexpr uint32_t Currency = 15;
      inline constexpr uint32_t EndSeqNo = 16;
      inline constexpr uint32_t ExecID = 17;
      inline constexpr uint32_t ExecInst = 18;
      inline constexpr uint32_t ExecRefID = 19;
      inline constexpr uint32_t ExecTransType = 20;
      inline constexpr uint32_t HandlInst = 21;
      inline constexpr uint32_t IDSource = 22;
      inline constexpr uint32_t IOIID = 23;
      inline constexpr uint32_t IOIOthSvc = 24;
      inline constexpr uint32_t IOIQltyInd = 25;
      inline constexpr uint32_t IOIRefID = 26;
      inline constexpr uint32_t IOIShares = 27;
      inline constexpr uint32_t IOITransType = 28;
      inline constexpr uint32_t LastCapacity = 29;
      inline constexpr uint32_t LastMkt = 30;
      inline constexpr uint32_t LastPx = 31;
      inline constexpr uint32_t LastShares = 32;
      inline constexpr uint32_t LinesOfText = 33;
      inline constexpr uint32_t MsgSeqNum = 34;
      inline constexpr uint32_t MsgType = 35;
      inline constexpr uint32_t NewSeqNo = 36;
      inline constexpr uint32_t OrderID = 37;
      inline constexpr uint32_t OrderQty = 38;
      inline constexpr uint32_t OrdStatus = 39;
      inline constexpr uint32_t OrdType = 40;
      inline constexpr uint32_t OrigClOrdID = 41;
      inline constexpr uint32_t OrigTime = 42;
      inline constexpr uint32_t PossDupFlag = 43;
      inline constexpr uint32_t Price = 44;
      inline constexpr uint32_t RefSeqNum = 45;
      inline constexpr uint32_t RelatdSym = 46;
      inline constexpr uint32_t Rule80A = 47;
      inline constexpr uint32_t SecurityID = 48;
      inline constexpr uint32_t SenderCompID = 49;
      inline constexpr uint32_t SenderSubID = 50;
      inline constexpr uint32_t SendingDate = 51;
      inline constexpr uint32_t SendingTime = 52;
      inline constexpr uint32_t Shares = 53;
      inline constexpr uint32_t Side = 54;
      inline constexpr uint32_t Symbol = 55;
      inline constexpr uint32_t TargetCompID = 56;
      inline constexpr uint32_t TargetSubID = 57;
      inline constexpr uint32_t Text = 58;
      inline constexpr uint32_t TimeInForce = 59;
      inline constexpr uint32_t TransactTime = 60;
      inline constexpr uint32_t Urgency = 61;
      inline constexpr uint32_t ValidUntilTime = 62;
      inline constexpr uint32_t SettlmntTyp = 63;
      inline constexpr uint32_t FutSettDate = 64;
      inline constexpr uint32_t SymbolSfx = 65;
      inline constexpr uint32_t ListID = 66;
      inline constexpr uint32_t ListSeqNo = 67;
      inline constexpr uint32_t TotNoOrders = 68;
      inline constexpr uint32_t ListExecInst = 69;
      inline constexpr uint32_t AllocID = 70;
      inline constexpr uint32_t AllocTransType = 71;
      inline constexpr uint32_t RefAllocID = 72;
      inline constexpr uint32_t NoOrders = 73;
      inline constexpr uint32_t AvgPrxPrecision = 74;
      inline constexpr uint32_t TradeDate = 75;
      inline constexpr uint32_t ExecBroker = 76;
      inline constexpr uint32_t OpenClose = 77;
      inline constexpr uint32_t NoAllocs = 78;
      inline constexpr uint32_t AllocAccount = 79;
      inline constexpr uint32_t AllocShares = 80;
      inline constexpr uint32_t ProcessCode = 81;
      inline constexpr uint32_t NoRpts = 82;
      inline constexpr uint32_t RptSeq = 83;
      inline constexpr uint32_t CxlQty = 84;
      inline constexpr uint32_t NoDlvyInst = 85;
      inline constexpr uint32_t DlvyInst = 86;
      inline constexpr uint32_t AllocStatus = 87;
      inline constexpr uint32_t AllocRejCode = 88;
      inline constexpr uint32_t Signature = 89;
      inline constexpr uint32_t SecureDataLen = 90;
      inline constexpr uint32_t SecureData = 91;
      inline constexpr uint32_t BrokerOfCredit = 92;
      inline constexpr uint32_t SignatureLength = 93;
      inline constexpr uint32_t EmailType = 94;
      inline constexpr uint32_t RawDataLength = 95;
      inline constexpr uint32_t RawData = 96;
      inline constexpr uint32_t PossResend = 97;
      inline constexpr uint32_t EncryptMethod = 98;
      inline constexpr uint32_t StopPx = 99;
      inline constexpr uint32_t ExDestination = 100;
      inline constexpr uint32_t CxlRejReason = 102;
      inline constexpr uint32_t OrdRejReason = 103;
      inline constexpr uint32_t IOIQualifier = 104;
      inline constexpr uint32_t WaveNo = 105;
      inline constexpr uint32_t Issuer = 106;
      inline constexpr uint32_t SecurityDesc = 107;
      inline constexpr uint32_t HeartBtInt = 108;
      inline constexpr uint32_t ClientID = 109;
      inline constexpr uint32_t MinQty = 110;
      inline constexpr uint32_t MaxFloor = 111;
      inline constexpr uint32_t TestReqID = 112;
      inline constexpr uint32_t ReportToExch = 113;
      inline constexpr uint32_t LocateReqd = 114;
      inline constexpr uint32_t OnBehalfOfCompID = 115;
      inline constexpr uint32_t OnBehalfOfSubID = 116;
      inline constexpr uint32_t QuoteID = 117;
      inline constexpr uint32_t NetMoney = 118;
      inline constexpr uint32_t SettlCurrAmt = 119;
      inline constexpr uint32_t SettlCurrency = 120;
      inline constexpr uint32_t ForexReq = 121;
      inline constexpr uint32_t OrigSendingTime = 122;
      inline constexpr uint32_t GapFillFlag = 123;
      inline constexpr uint32_t NoExecs = 124;
      inline constexpr uint32_t CxlType = 125;
      inline constexpr uint32_t ExpireTime = 126;
      inline constexpr uint32_t DKReason = 127;
      inline constexpr uint32_t DeliverToCompID = 128;
      inline constexpr uint32_t DeliverToSubID = 129;
      inline constexpr uint32_t IOINaturalFlag = 130;
      inline constexpr uint32_t QuoteReqID = 131;
      inline constexpr uint32_t BidPx = 132;
      inline constexpr uint32_t OfferPx = 133;
      inline constexpr uint32_t BidSize = 134;
      inline constexpr uint32_t OfferSize = 135;
      inline constexpr uint32_t NoMiscFees = 136;
      inline constexpr uint32_t MiscFeeAmt = 137;
      inline constexpr uint32_t MiscFeeCurr = 138;
      inline constexpr uint32_t MiscFeeType = 139;
      inline constexpr uint32_t PrevClosePx = 140;
      inline constexpr uint32_t ResetSeqNumFlag = 141;
      inline constexpr uint32_t SenderLocationID = 142;
      inline constexpr uint32_t TargetLocationID = 143;
      inline constexpr uint32_t OnBehalfOfLocationID = 144;
      inline constexpr uint32_t DeliverToLocationID = 145;
      inline constexpr uint32_t NoRelatedSym = 146;
      inline constexpr uint32_t Subject = 147;
      inline constexpr uint32_t Headline = 148;
      inline constexpr uint32_t URLLink = 149;
      inline constexpr uint32_t ExecType = 150;
      inline constexpr uint32_t LeavesQty = 151;
      inline constexpr uint32_t CashOrderQty = 152;
      inline constexpr uint32_t AllocAvgPx = 153;
      inline constexpr uint32_t AllocNetMoney = 154;
      inline constexpr uint32_t SettlCurrFxRate = 155;
      inline constexpr uint32_t SettlCurrFxRateCalc = 156;
      inline constexpr uint32_t NumDaysInterest = 157;
      inline constexpr uint32_t AccruedInterestRate = 158;
      inline constexpr uint32_t AccruedInterestAmt = 159;
      inline constexpr uint32_t SettlInstMode = 160;
      inline constexpr uint32_t AllocText = 161;
      inline constexpr uint32_t SettlInstID = 162;
      inline constexpr uint32_t SettlInstTransType = 163;
      inline constexpr uint32_t EmailThreadID = 164;
      inline constexpr uint32_t SettlInstSource = 165;
      inline constexpr uint32_t SettlLocation = 166;
      inline constexpr uint32_t SecurityType = 167;
      inline constexpr uint32_t EffectiveTime = 168;
      inline constexpr uint32_t StandInstDbType = 169;
      inline constexpr uint32_t StandInstDbName = 170;
      inline constexpr uint32_t StandInstDbID = 171;
      inline constexpr uint32_t SettlDeliveryType = 172;
      inline constexpr uint32_t SettlDepositoryCode = 173;
      inline constexpr uint32_t SettlBrkrCode = 174;
      inline constexpr uint32_t SettlInstCode = 175;
      inline constexpr uint32_t SecuritySettlAgentName = 176;
      inline constexpr uint32_t SecuritySettlAgentCode = 177;
      inline constexpr uint32_t SecuritySettlAgentAcctNum = 178;
      inline constexpr uint32_t SecuritySettlAgentAcctName = 179;
      inline constexpr uint32_t SecuritySettlAgentContactName = 180;
      inline constexpr uint32_t SecuritySettlAgentContactPhone = 181;
      inline constexpr uint32_t CashSettlAgentName = 182;
      inline constexpr uint32_t CashSettlAgentCode = 183;
      inline constexpr uint32_t CashSettlAgentAcctNum = 184;
      inline constexpr uint32_t CashSettlAgentAcctName = 185;
      inline constexpr uint32_t CashSettlAgentContactName = 186;
      inline constexpr uint32_t CashSettlAgentContactPhone = 187;
      inline constexpr uint32_t BidSpotRate = 188;
      inline constexpr uint32_t BidForwardPoints = 189;
      inline constexpr uint32_t OfferSpotRate = 190;
      inline constexpr uint32_t OfferForwardPoints = 191;
      inline constexpr uint32_t OrderQty2 = 192;
      inline constexpr uint32_t FutSettDate2 = 193;
      inline constexpr uint32_t LastSpotRate = 194;
      inline constexpr uint32_t LastForwardPoints = 195;
      inline constexpr uint32_t AllocLinkID = 196;
      inline constexpr uint32_t AllocLinkType = 197;
      inline constexpr uint32_t SecondaryOrderID = 198;
      inline constexpr uint32_t NoIOIQualifiers = 199;
      inline constexpr uint32_t MaturityMonthYear = 200;
      inline constexpr uint32_t PutOrCall = 201;
      inline constexpr uint32_t StrikePrice = 202;
      inline constexpr uint32_t CoveredOrUncovered = 203;
      inline constexpr uint32_t CustomerOrFirm = 204;
      inline constexpr uint32_t MaturityDay = 205;
      inline constexpr uint32_t OptAttribute = 206;
      inline constexpr uint32_t SecurityExchange = 207;
      inline constexpr uint32_t NotifyBrokerOfCredit = 208;
      inline constexpr uint32_t AllocHandlInst = 209;
      inline constexpr uint32_t MaxShow = 210;
      inline constexpr uint32_t PegDifference = 211;
      inline constexpr uint32_t XmlDataLen = 212;
      inline constexpr uint32_t XmlData = 213;
      inline constexpr uint32_t SettlInstRefID = 214;
      inline constexpr uint32_t NoRoutingIDs = 215;
      inline constexpr uint32_t RoutingType = 216;
      inline constexpr uint32_t RoutingID = 217;
      inline constexpr uint32_t SpreadToBenchmark = 218;
      inline constexpr uint32_t Benchmark = 219;
      inline constexpr uint32_t CouponRate = 223;
      inline constexpr uint32_t ContractMultiplier = 231;
      inline constexpr uint32_t MDReqID = 262;
      inline constexpr uint32_t SubscriptionRequestType = 263;
      inline constexpr uint32_t MarketDepth = 264;
      inline constexpr uint32_t MDUpdateType = 265;
      inline constexpr uint32_t AggregatedBook = 266;
      inline constexpr uint32_t NoMDEntryTypes = 267;
      inline constexpr uint32_t NoMDEntries = 268;
      inline constexpr uint32_t MDEntryType = 269;
      inline constexpr uint32_t MDEntryPx = 270;
      inline constexpr uint32_t MDEntrySize = 271;
      inline constexpr uint32_t MDEntryDate = 272;
      inline constexpr uint32_t MDEntryTime = 273;
      inline constexpr uint32_t TickDirection = 274;
      inline constexpr uint32_t MDMkt = 275;
      inline constexpr uint32_t QuoteCondition = 276;
      inline constexpr uint32_t TradeCondition = 277;
      inline constexpr uint32_t MDEntryID = 278;
      inline constexpr uint32_t MDUpdateAction = 279;
      inline constexpr uint32_t MDEntryRefID = 280;
      inline constexpr uint32_t MDReqRejReason = 281;
      inline constexpr uint32_t MDEntryOriginator = 282;
      inline constexpr uint32_t LocationID = 283;
      inline constexpr uint32_t DeskID = 284;
      inline constexpr uint32_t DeleteReason = 285;
      inline constexpr uint32_t OpenCloseSettleFlag = 286;
      inline constexpr uint32_t SellerDays = 287;
      inline constexpr uint32_t MDEntryBuyer = 288;
      inline constexpr uint32_t MDEntrySeller = 289;
      inline constexpr uint32_t MDEntryPositionNo = 290;
      inline constexpr uint32_t FinancialStatus = 291;
      inline constexpr uint32_t CorporateAction = 292;
      inline constexpr uint32_t DefBidSize = 293;
      inline constexpr uint32_t DefOfferSize = 294;
      inline constexpr uint32_t NoQuoteEntries = 295;
      inline constexpr uint32_t NoQuoteSets = 296;
      inline constexpr uint32_t QuoteAckStatus = 297;
      inline constexpr uint32_t QuoteCancelType = 298;
      inline constexpr uint32_t QuoteEntryID = 299;
      inline constexpr uint32_t QuoteRejectReason = 300;
      inline constexpr uint32_t QuoteResponseLevel = 301;
      inline constexpr uint32_t QuoteSetID = 302;
      inline constexpr uint32_t QuoteRequestType = 303;
      inline constexpr uint32_t TotQuoteEntries = 304;
      inline constexpr uint32_t UnderlyingIDSource = 305;
      inline constexpr uint32_t UnderlyingIssuer = 306;
      inline constexpr uint32_t UnderlyingSecurityDesc = 307;
      inline constexpr uint32_t UnderlyingSecurityExchange = 308;
      inline constexpr uint32_t UnderlyingSecurityID = 309;
      inline constexpr uint32_t UnderlyingSecurityType = 310;
      inline constexpr uint32_t UnderlyingSymbol = 311;
      inline constexpr uint32_t UnderlyingSymbolSfx = 312;
      inline constexpr uint32_t UnderlyingMaturityMonthYear = 313;
      inline constexpr uint32_t UnderlyingMaturityDay = 314;
      inline constexpr uint32_t UnderlyingPutOrCall = 315;
      inline constexpr uint32_t UnderlyingStrikePrice = 316;
      inline constexpr uint32_t UnderlyingOptAttribute = 317;
      inline constexpr uint32_t UnderlyingCurrency = 318;
      inline constexpr uint32_t RatioQty = 319;
      inline constexpr uint32_t SecurityReqID = 320;
      inline constexpr uint32_t SecurityRequestType = 321;
      inline constexpr uint32_t SecurityResponseID = 322;
      inline constexpr uint32_t SecurityResponseType = 323;
      inline constexpr uint32_t SecurityStatusReqID = 324;
      inline constexpr uint32_t UnsolicitedIndicator = 325;
      inline constexpr uint32_t SecurityTradingStatus = 326;
      inline constexpr uint32_t HaltReason = 327;
      inline constexpr uint32_t InViewOfCommon = 328;
      inline constexpr uint32_t DueToRelated = 329;
      inline constexpr uint32_t BuyVolume = 330;
      inline constexpr uint32_t SellVolume = 331;
      inline constexpr uint32_t HighPx = 332;
      inline constexpr uint32_t LowPx = 333;
      inline constexpr uint32_t Adjustment = 334;
      inline constexpr uint32_t TradSesReqID = 335;
      inline constexpr uint32_t TradingSessionID = 336;
      inline constexpr uint32_t ContraTrader = 337;
      inline constexpr uint32_t TradSesMethod = 338;
      inline constexpr uint32_t TradSesMode = 339;
      inline constexpr uint32_t TradSesStatus = 340;
      inline constexpr uint32_t TradSesStartTime = 341;
      inline constexpr uint32_t TradSesOpenTime = 342;
      inline constexpr uint32_t TradSesPreCloseTime = 343;
      inline constexpr uint32_t TradSesCloseTime = 344;
      inline constexpr uint32_t TradSesEndTime = 345;
      inline constexpr uint32_t NumberOfOrders = 346;
      inline constexpr uint32_t MessageEncoding = 347;
      inline constexpr uint32_t EncodedIssuerLen = 348;
      inline constexpr uint32_t EncodedIssuer = 349;
      inline constexpr uint32_t EncodedSecurityDescLen = 350;
      inline constexpr uint32_t EncodedSecurityDesc = 351;
      inline constexpr uint32_t EncodedListExecInstLen = 352;
      inline constexpr uint32_t EncodedListExecInst = 353;
      inline constexpr uint32_t EncodedTextLen = 354;
      inline constexpr uint32_t EncodedText = 355;
      inline constexpr uint32_t EncodedSubjectLen = 356;
      inline constexpr uint32_t EncodedSubject = 357;
      inline constexpr uint32_t EncodedHeadlineLen = 358;
      inline constexpr uint32_t EncodedHeadline = 359;
      inline constexpr uint32_t EncodedAllocTextLen = 360;
      inline constexpr uint32_t EncodedAllocText = 361;
      inline constexpr uint32_t EncodedUnderlyingIssuerLen = 362;
      inline constexpr uint32_t EncodedUnderlyingIssuer = 363;
      inline constexpr uint32_t EncodedUnderlyingSecurityDescLen = 364;
      inline constexpr uint32_t EncodedUnderlyingSecurityDesc = 365;
      inline constexpr uint32_t AllocPrice = 366;
      inline constexpr uint32_t QuoteSetValidUntilTime = 367;
      inline constexpr uint32_t QuoteEntryRejectReason = 368;
      inline constexpr uint32_t LastMsgSeqNumProcessed = 369;
      inline constexpr uint32_t OnBehalfOfSendingTime = 370;
      inline constexpr uint32_t RefTagID = 371;
      inline constexpr uint32_t RefMsgType = 372;
      inline constexpr uint32_t SessionRejectReason = 373;
      inline constexpr uint32_t BidRequestTransType = 374;
      inline constexpr uint32_t ContraBroker = 375;
      inline constexpr uint32_t ComplianceID = 376;
      inline constexpr uint32_t SolicitedFlag = 377;
      inline constexpr uint32_t ExecRestatementReason = 378;
      inline constexpr uint32_t BusinessRejectRefID = 379;
      inline constexpr uint32_t BusinessRejectReason = 380;
      inline constexpr uint32_t GrossTradeAmt = 381;
      inline constexpr uint32_t NoContraBrokers = 382;
      inline constexpr uint32_t MaxMessageSize = 383;
      inline constexpr uint32_t NoMsgTypes = 384;
      inline constexpr uint32_t MsgDirection = 385;
      inline constexpr uint32_t NoTradingSessions = 386;
      inline constexpr uint32_t TotalVolumeTraded = 387;
      inline constexpr uint32_t DiscretionInst = 388;
      inline constexpr uint32_t DiscretionOffset = 389;
      inline constexpr uint32_t BidID = 390;
      inline constexpr uint32_t ClientBidID = 391;
      inline constexpr uint32_t ListName = 392;
      inline constexpr uint32_t TotalNumSecurities = 393;
      inline constexpr uint32_t BidType = 394;
      inline constexpr uint32_t NumTickets = 395;
      inline constexpr uint32_t SideValue1 = 396;
      inline constexpr uint32_t SideValue2 = 397;
      inline constexpr uint32_t NoBidDescriptors = 398;
      inline constexpr uint32_t BidDescriptorType = 399;
      inline constexpr uint32_t BidDescriptor = 400;
      inline constexpr uint32_t SideValueInd = 401;
      inline constexpr uint32_t LiquidityPctLow = 402;
      inline constexpr uint32_t LiquidityPctHigh = 403;
      inline constexpr uint32_t LiquidityValue = 404;
      inline constexpr uint32_t EFPTrackingError = 405;
      inline constexpr uint32_t FairValue = 406;
      inline constexpr uint32_t OutsideIndexPct = 407;
      inline constexpr uint32_t ValueOfFutures = 408;
      inline constexpr uint32_t LiquidityIndType = 409;
      inline constexpr uint32_t WtAverageLiquidity = 410;
      inline constexpr uint32_t ExchangeForPhysical = 411;
      inline constexpr uint32_t OutMainCntryUIndex = 412;
      inline constexpr uint32_t CrossPercent = 413;
      inline constexpr uint32_t ProgRptReqs = 414;
      inline constexpr uint32_t ProgPeriodInterval = 415;
      inline constexpr uint32_t IncTaxInd = 416;
      inline constexpr uint32_t NumBidders = 417;
      inline constexpr uint32_t TradeType = 418;
      inline constexpr uint32_t BasisPxType = 419;
      inline constexpr uint32_t NoBidComponents = 420;
      inline constexpr uint32_t Country = 421;
      inline constexpr uint32_t TotNoStrikes = 422;
      inline constexpr uint32_t PriceType = 423;
      inline constexpr uint32_t DayOrderQty = 424;
      inline constexpr uint32_t DayCumQty = 425;
      inline constexpr uint32_t DayAvgPx = 426;
      inline constexpr uint32_t GTBookingInst = 427;
      inline constexpr uint32_t NoStrikes = 428;
      inline constexpr uint32_t ListStatusType = 429;
      inline constexpr uint32_t NetGrossInd = 430;
      inline constexpr uint32_t ListOrderStatus = 431;
      inline constexpr uint32_t ExpireDate = 432;
      inline constexpr uint32_t ListExecInstType = 433;
      inline constexpr uint32_t CxlRejResponseTo = 434;
      inline constexpr uint32_t UnderlyingCouponRate = 435;
      inline constexpr uint32_t UnderlyingContractMultiplier = 436;
      inline constexpr uint32_t ContraTradeQty = 437;
      inline constexpr uint32_t ContraTradeTime = 438;
      inline constexpr uint32_t ClearingFirm = 439;
      inline constexpr uint32_t ClearingAccount = 440;
      inline constexpr uint32_t LiquidityNumSecurities = 441;
      inline constexpr uint32_t MultiLegReportingType = 442;
      inline constexpr uint32_t StrikeTime = 443;
      inline constexpr uint32_t ListStatusText = 444;
      inline constexpr uint32_t EncodedListStatusTextLen = 445;
      inline constexpr uint32_t EncodedListStatusText = 446;
   }

   // AdjustmentCodeSet (int)
   enum class Adjustment : int32_t {
      Cancel = 1,
      Error = 2,
      Correction = 3,
   };
   // AdvSideCodeSet (char)
   enum class AdvSide : char {
      Buy = 'B',
      Sell = 'S',
      Trade = 'T',
      Cross = 'X',
   };
   // AdvTransTypeCodeSet (String)
   enum class AdvTransType : uint16_t {
      Cancel = 0,
      New = 1,
      Replace = 2,
   };
   // AggregatedBookCodeSet (Boolean)
   enum class AggregatedBook : uint16_t {
      BookEntriesShouldNotBeAggregated = 0,
      BookEntriesToBeAggregated = 1,
   };
   // AllocHandlInstCodeSet (int)
   enum class AllocHandlInst : int32_t {
      Match = 1,
      Forward = 2,
      ForwardAndMatch = 3,
   };
   // AllocLinkTypeCodeSet (int)
   enum class AllocLinkType : int32_t {
      FXNetting = 0,
      FXSwap = 1,
   };
   // AllocRejCodeCodeSet (int)
   enum class AllocRejCode : int32_t {
      UnknownAccount = 0,
      IncorrectQuantity = 1,
      IncorrectAveragePrice = 2,
      UnknownExecutingBrokerMnemonic = 3,
      CommissionDifference = 4,
      UnknownOrderID = 5,
      UnknownListID = 6,
      OtherSeeText = 7,
   };
   // AllocStatusCodeSet (int)
   enum class AllocStatus : int32_t {
      Accepted = 0,
      BlockLevelReject = 1,
      AccountLevelReject = 2,
      Received = 3,
   };
   // AllocTransTypeCodeSet (char)
   enum class AllocTransType : char {
      New = '0',
      Replace = '1',
      Cancel = '2',
      Preliminary = '3',
      Calculated = '4',
      CalculatedWithoutPreliminary = '5',
   };
   // BasisPxTypeCodeSet (char)
   enum class BasisPxType : char {
      ClosingPriceAtMorningSession = '2',
      ClosingPrice = '3',
      CurrentPrice = '4',
      SQ = '5',
      VWAPThroughADay = '6',
      VWAPThroughAMorningSession = '7',
      VWAPThroughAnAfternoonSession = '8',
      VWAPThroughADayExcept = '9',
      VWAPThroughAMorningSessionExcept = 'A',
      VWAPThroughAnAfternoonSessionExcept = 'B',
      Strike = 'C',
      Open = 'D',
      Others = 'Z',
   };
   // BenchmarkCodeSet (char)
   enum class Benchmark : char {
      CURVE = '1',
      FiveYR = '2',
      OLD5 = '3',
      TenYR = '4',
      OLD10 = '5',
      ThirtyYR = '6',
      OLD30 = '7',
      ThreeMOLIBOR = '8',
      SixMOLIBOR = '9',
   };
   // BidDescriptorTypeCodeSet (int)
   enum class BidDescriptorType : int32_t {
      Sector = 1,
      Country = 2,
      Index = 3,
   };
   // BidRequestTransTypeCodeSet (char)
   enum class BidRequestTransType : char {
      Cancel = 'C',
      New = 'N',
   };
   // BidTypeCodeSet (int)
   enum class BidType : int32_t {
      NonDisclosed = 1,
      Disclosed = 2,
      NoBiddingProcess = 3,
   };
   // BusinessRejectReasonCodeSet (int)
   enum class BusinessRejectReason : int32_t {
      Other = 0,
      UnknownID = 1,
      UnknownSecurity = 2,
      UnsupportedMessageType = 3,
      ApplicationNotAvailable = 4,
      ConditionallyRequiredFieldMissing = 5,
   };
   // CommTypeCodeSet (char)
   enum class CommType : char {
      PerUnit = '1',
      Percent = '2',
      Absolute = '3',
   };
   // CorporateActionCodeSet (char)
   enum class CorporateAction : char {
      ExDividend = 'A',
      ExDistribution = 'B',
      ExRights = 'C',
      New = 'D',
      ExInterest = 'E',
   };
   // CoveredOrUncoveredCodeSet (int)
   enum class CoveredOrUncovered : int32_t {
      Covered = 0,
      Uncovered = 1,
   };
   // CustomerOrFirmCodeSet (int)
   enum class CustomerOrFirm : int32_t {
      Customer = 0,
      Firm = 1,
   };
   // CxlRejReasonCodeSet (int)
   enum class CxlRejReason : int32_t {
      TooLateToCancel = 0,
      UnknownOrder = 1,
      BrokerCredit = 2,
      OrderAlreadyInPendingStatus = 3,
   };
   // CxlRejResponseToCodeSet (char)
   enum class CxlRejResponseTo : char {
      OrderCancelRequest = '1',
      OrderCancel = '2',
   };
   // DKReasonCodeSet (char)
   enum class DKReason : char {
      UnknownSymbol = 'A',
      WrongSide = 'B',
      QuantityExceedsOrder = 'C',
      NoMatchingOrder = 'D',
      PriceExceedsLimit = 'E',
      Other = 'Z',
   };
   // DeleteReasonCodeSet (char)
   enum class DeleteReason : char {
      Cancellation = '0',
      Error = '1',
   };
   // DiscretionInstCodeSet (char)
   enum class DiscretionInst : char {
      RelatedToDisplayedPrice = '0',
      RelatedToMarketPrice = '1',
      RelatedToPrimaryPrice = '2',
      RelatedToLocalPrimaryPrice = '3',
      RelatedToMidpointPrice = '4',
      RelatedToLastTradePrice = '5',
   };
   // DueToRelatedCodeSet (Boolean)
   enum class DueToRelated : uint16_t {
      NotRelatedToSecurityHalt = 0,
      RelatedToSecurityHalt = 1,
   };
   // EmailTypeCodeSet (char)
   enum class EmailType : char {
      New = '0',
      Reply = '1',
      AdminReply = '2',
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
   // ExchangeForPhysicalCodeSet (Boolean)
   enum class ExchangeForPhysical : uint16_t {
      False = 0,
      True = 1,
   };
   // ExecInstCodeSet (MultipleValueString)
   enum class ExecInst : uint16_t {
      StayOnOfferSide = 0,
      NotHeld = 1,
      Work = 2,
      GoAlong = 3,
      OverTheDay = 4,
      Held = 5,
      ParticipateDoNotInitiate = 6,
      StrictScale = 7,
      TryToScale = 8,
      StayOnBidSide = 9,
      NoCross = 10,
      OKToCross = 11,
      CallFirst = 12,
      PercentOfVolume = 13,
      DoNotIncrease = 14,
      DoNotReduce = 15,
      AllOrNone = 16,
      InstitutionsOnly = 17,
      LastPeg = 18,
      MidPricePeg = 19,
      NonNegotiable = 20,
      OpeningPeg = 21,
      MarketPeg = 22,
      PrimaryPeg = 23,
      Suspend = 24,
      FixedPegToLocalBestBidOrOfferAtTimeOfOrder = 25,
      CustomerDisplayInstruction = 26,
      Netting = 27,
      PegToVWAP = 28,
   };
   // ExecRestatementReasonCodeSet (int)
   enum class ExecRestatementReason : int32_t {
      GTCorporateAction = 0,
      GTRenewal = 1,
      VerbalChange = 2,
      RepricingOfOrder = 3,
      BrokerOption = 4,
      PartialDeclineOfOrderQty = 5,
   };
   // ExecTransTypeCodeSet (char)
   enum class ExecTransType : char {
      New = '0',
      Cancel = '1',
      Correct = '2',
      Status = '3',
   };
   // ExecTypeCodeSet (char)
   enum class ExecType : char {
      New = '0',
      PartialFill = '1',
      Fill = '2',
      DoneForDay = '3',
      Canceled = '4',
      Replaced = '5',
      PendingCancel = '6',
      Stopped = '7',
      Rejected = '8',
      Suspended = '9',
      PendingNew = 'A',
      Calculated = 'B',
      Expired = 'C',
      Restated = 'D',
      PendingReplace = 'E',
   };
   // FinancialStatusCodeSet (char)
   enum class FinancialStatus : char {
      Bankrupt = '1',
   };
   // ForexReqCodeSet (Boolean)
   enum class ForexReq : uint16_t {
      DoNotExecuteForexAfterSecurityTrade = 0,
      ExecuteForexAfterSecurityTrade = 1,
   };
   // GTBookingInstCodeSet (int)
   enum class GTBookingInst : int32_t {
      BookOutAllTradesOnDayOfExecution = 0,
      AccumulateUntilFilledOrExpired = 1,
      AccumulateUntilVerballlyNotifiedOtherwise = 2,
   };
   // GapFillFlagCodeSet (Boolean)
   enum class GapFillFlag : uint16_t {
      SequenceReset = 0,
      GapFillMessage = 1,
   };
   // HaltReasonCodeSet (char)
   enum class HaltReason : char {
      NewsDissemination = 'D',
      OrderInflux = 'E',
      OrderImbalance = 'I',
      AdditionalInformation = 'M',
      NewsPending = 'P',
      EquipmentChangeover = 'X',
   };
   // HandlInstCodeSet (char)
   enum class HandlInst : char {
      AutomatedExecutionNoIntervention = '1',
      AutomatedExecutionInterventionOK = '2',
      ManualOrder = '3',
   };
   // IDSourceCodeSet (String)
   enum class IDSource : uint16_t {
      CUSIP = 0,
      SEDOL = 1,
      QUIK = 2,
      ISINNumber = 3,
      RICCode = 4,
      ISOCurrencyCode = 5,
      ISOCountryCode = 6,
      ExchangeSymbol = 7,
      ConsolidatedTapeAssociation = 8,
   };
   // IOINaturalFlagCodeSet (Boolean)
   enum class IOINaturalFlag : uint16_t {
      NotNatural = 0,
      Natural = 1,
   };
   // IOIQltyIndCodeSet (char)
   enum class IOIQltyInd : char {
      High = 'H',
      Low = 'L',
      Medium = 'M',
   };
   // IOIQualifierCodeSet (char)
   enum class IOIQualifier : char {
      AllOrNone = 'A',
      AtTheClose = 'C',
      InTouchWith = 'I',
      Limit = 'L',
      MoreBehind = 'M',
      AtTheOpen = 'O',
      TakingAPosition = 'P',
      AtTheMarket = 'Q',
      ReadyToTrade = 'R',
      PortfolioShown = 'S',
      ThroughTheDay = 'T',
      Versus = 'V',
      Indication = 'W',
      CrossingOpportunity = 'X',
      AtTheMidpoint = 'Y',
      PreOpen = 'Z',
   };
   // IOISharesCodeSet (String)
   enum class IOIShares : uint16_t {
      Large = 0,
      Medium = 1,
      Small = 2,
   };
   // IOITransTypeCodeSet (char)
   enum class IOITransType : char {
      Cancel = 'C',
      New = 'N',
      Replace = 'R',
   };
   // InViewOfCommonCodeSet (Boolean)
   enum class InViewOfCommon : uint16_t {
      HaltWasNotRelatedToAHaltOfTheCommonStock = 0,
      HaltWasDueToCommonStockBeingHalted = 1,
   };
   // IncTaxIndCodeSet (int)
   enum class IncTaxInd : int32_t {
      Net = 1,
      Gross = 2,
   };
   // LastCapacityCodeSet (char)
   enum class LastCapacity : char {
      Agent = '1',
      CrossAsAgent = '2',
      CrossAsPrincipal = '3',
      Principal = '4',
   };
   // LiquidityIndTypeCodeSet (int)
   enum class LiquidityIndType : int32_t {
      FiveDayMovingAverage = 1,
      TwentyDayMovingAverage = 2,
      NormalMarketSize = 3,
      Other = 4,
   };
   // ListExecInstTypeCodeSet (char)
   enum class ListExecInstType : char {
      Immediate = '1',
      WaitForInstruction = '2',
   };
   // ListOrderStatusCodeSet (int)
   enum class ListOrderStatus : int32_t {
      InBiddingProcess = 1,
      ReceivedForExecution = 2,
      Executing = 3,
      Canceling = 4,
      Alert = 5,
      AllDone = 6,
      Reject = 7,
   };
   // ListStatusTypeCodeSet (int)
   enum class ListStatusType : int32_t {
      Ack = 1,
      Response = 2,
      Timed = 3,
      ExecStarted = 4,
      AllDone = 5,
      Alert = 6,
   };
   // LocateReqdCodeSet (Boolean)
   enum class LocateReqd : uint16_t {
      No = 0,
      Yes = 1,
   };
   // MDEntryTypeCodeSet (char)
   enum class MDEntryType : char {
      Bid = '0',
      Offer = '1',
      Trade = '2',
      IndexValue = '3',
      OpeningPrice = '4',
      ClosingPrice = '5',
      SettlementPrice = '6',
      TradingSessionHighPrice = '7',
      TradingSessionLowPrice = '8',
      TradingSessionVWAPPrice = '9',
   };
   // MDReqRejReasonCodeSet (char)
   enum class MDReqRejReason : char {
      UnknownSymbol = '0',
      DuplicateMDReqID = '1',
      InsufficientBandwidth = '2',
      InsufficientPermissions = '3',
      UnsupportedSubscriptionRequestType = '4',
      UnsupportedMarketDepth = '5',
      UnsupportedMDUpdateType = '6',
      UnsupportedAggregatedBook = '7',
      UnsupportedMDEntryType = '8',
   };
   // MDUpdateActionCodeSet (char)
   enum class MDUpdateAction : char {
      New = '0',
      Change = '1',
      Delete = '2',
   };
   // MDUpdateTypeCodeSet (int)
   enum class MDUpdateType : int32_t {
      FullRefresh = 0,
      IncrementalRefresh = 1,
   };
   // MessageEncodingCodeSet (String)
   enum class MessageEncoding : uint16_t {
      EUCJP = 0,
      ISO2022JP = 1,
      ShiftJIS = 2,
      UTF8 = 3,
   };
   // MiscFeeTypeCodeSet (char)
   enum class MiscFeeType : char {
      Regulatory = '1',
      Tax = '2',
      LocalCommission = '3',
      ExchangeFees = '4',
      Stamp = '5',
      Levy = '6',
      Other = '7',
      Markup = '8',
      ConsumptionTax = '9',
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
      IOI = 6,
      Advertisement = 7,
      ExecutionReport = 8,
      OrderCancelReject = 9,
      Logon = 10,
      News = 11,
      Email = 12,
      NewOrderSingle = 13,
      NewOrderList = 14,
      OrderCancelRequest = 15,
      OrderCancelReplaceRequest = 16,
      OrderStatusRequest = 17,
      Allocation = 18,
      ListCancelRequest = 19,
      ListExecute = 20,
      ListStatusRequest = 21,
      ListStatus = 22,
      AllocationAck = 23,
      DontKnowTrade = 24,
      QuoteRequest = 25,
      Quote = 26,
      SettlementInstructions = 27,
      MarketDataRequest = 28,
      MarketDataSnapshotFullRefresh = 29,
      MarketDataIncrementalRefresh = 30,
      MarketDataRequestReject = 31,
      QuoteCancel = 32,
      QuoteStatusRequest = 33,
      QuoteAcknowledgement = 34,
      SecurityDefinitionRequest = 35,
      SecurityDefinition = 36,
      SecurityStatusRequest = 37,
      SecurityStatus = 38,
      TradingSessionStatusRequest = 39,
      TradingSessionStatus = 40,
      MassQuote = 41,
      BusinessMessageReject = 42,
      BidRequest = 43,
      BidResponse = 44,
      ListStrikePrice = 45,
   };
   // MultiLegReportingTypeCodeSet (char)
   enum class MultiLegReportingType : char {
      SingleSecurity = '1',
      IndividualLegOfAMultiLegSecurity = '2',
      MultiLegSecurity = '3',
   };
   // NetGrossIndCodeSet (int)
   enum class NetGrossInd : int32_t {
      Net = 1,
      Gross = 2,
   };
   // NotifyBrokerOfCreditCodeSet (Boolean)
   enum class NotifyBrokerOfCredit : uint16_t {
      DetailsShouldNotBeCommunicated = 0,
      DetailsShouldBeCommunicated = 1,
   };
   // OpenCloseCodeSet (char)
   enum class OpenClose : char {
      Close = 'C',
      Open = 'O',
   };
   // OpenCloseSettleFlagCodeSet (char)
   enum class OpenCloseSettleFlag : char {
      DailyOpen = '0',
      SessionOpen = '1',
      DeliverySettlementEntry = '2',
   };
   // OrdRejReasonCodeSet (int)
   enum class OrdRejReason : int32_t {
      BrokerCredit = 0,
      UnknownSymbol = 1,
      ExchangeClosed = 2,
      OrderExceedsLimit = 3,
      TooLateToEnter = 4,
      UnknownOrder = 5,
      DuplicateOrder = 6,
      DuplicateOfAVerballyCommunicatedOrder = 7,
      StaleOrder = 8,
   };
   // OrdStatusCodeSet (char)
   enum class OrdStatus : char {
      New = '0',
      PartiallyFilled = '1',
      Filled = '2',
      DoneForDay = '3',
      Canceled = '4',
      Replaced = '5',
      PendingCancel = '6',
      Stopped = '7',
      Rejected = '8',
      Suspended = '9',
      PendingNew = 'A',
      Calculated = 'B',
      Expired = 'C',
      AcceptedForBidding = 'D',
      PendingReplace = 'E',
   };
   // OrdTypeCodeSet (char)
   enum class OrdType : char {
      Market = '1',
      Limit = '2',
      Stop = '3',
      StopLimit = '4',
      MarketOnClose = '5',
      WithOrWithout = '6',
      LimitOrBetter = '7',
      LimitWithOrWithout = '8',
      OnBasis = '9',
      OnClose = 'A',
      LimitOnClose = 'B',
      ForexMarket = 'C',
      PreviouslyQuoted = 'D',
      PreviouslyIndicated = 'E',
      ForexLimit = 'F',
      ForexSwap = 'G',
      ForexPreviouslyQuoted = 'H',
      Funari = 'I',
      Pegged = 'P',
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
   // PriceTypeCodeSet (int)
   enum class PriceType : int32_t {
      Percentage = 1,
      PerUnit = 2,
      FixedAmount = 3,
   };
   // ProcessCodeCodeSet (char)
   enum class ProcessCode : char {
      Regular = '0',
      SoftDollar = '1',
      StepIn = '2',
      StepOut = '3',
      SoftDollarStepIn = '4',
      SoftDollarStepOut = '5',
      PlanSponsor = '6',
   };
   // ProgRptReqsCodeSet (int)
   enum class ProgRptReqs : int32_t {
      BuySideRequests = 1,
      SellSideSends = 2,
      RealTimeExecutionReports = 3,
   };
   // PutOrCallCodeSet (int)
   enum class PutOrCall : int32_t {
      Put = 0,
      Call = 1,
   };
   // QuoteAckStatusCodeSet (int)
   enum class QuoteAckStatus : int32_t {
      Accepted = 0,
      CancelForSymbol = 1,
      CanceledForSecurityType = 2,
      CanceledForUnderlying = 3,
      CanceledAll = 4,
      Rejected = 5,
   };
   // QuoteCancelTypeCodeSet (int)
   enum class QuoteCancelType : int32_t {
      CancelForOneOrMoreSecurities = 1,
      CancelForSecurityType = 2,
      CancelForUnderlyingSecurity = 3,
      CancelAllQuotes = 4,
   };
   // QuoteConditionCodeSet (MultipleValueString)
   enum class QuoteCondition : uint16_t {
      Open = 0,
      Closed = 1,
      ExchangeBest = 2,
      ConsolidatedBest = 3,
      Locked = 4,
      Crossed = 5,
      Depth = 6,
      FastTrading = 7,
      NonFirm = 8,
   };
   // QuoteEntryRejectReasonCodeSet (int)
   enum class QuoteEntryRejectReason : int32_t {
      UnknownSymbol = 1,
      Exchange = 2,
      QuoteExceedsLimit = 3,
      TooLateToEnter = 4,
      UnknownQuote = 5,
      DuplicateQuote = 6,
      InvalidBidAskSpread = 7,
      InvalidPrice = 8,
      NotAuthorizedToQuoteSecurity = 9,
   };
   // QuoteRejectReasonCodeSet (int)
   enum class QuoteRejectReason : int32_t {
      UnknownSymbol = 1,
      Exchange = 2,
      QuoteRequestExceedsLimit = 3,
      TooLateToEnter = 4,
      UnknownQuote = 5,
      DuplicateQuote = 6,
      InvalidBid = 7,
      InvalidPrice = 8,
      NotAuthorizedToQuoteSecurity = 9,
   };
   // QuoteRequestTypeCodeSet (int)
   enum class QuoteRequestType : int32_t {
      Manual = 1,
      Automatic = 2,
   };
   // QuoteResponseLevelCodeSet (int)
   enum class QuoteResponseLevel : int32_t {
      NoAcknowledgement = 0,
      AcknowledgeOnlyNegativeOrErroneousQuotes = 1,
      AcknowledgeEachQuoteMessage = 2,
   };
   // ReportToExchCodeSet (Boolean)
   enum class ReportToExch : uint16_t {
      SenderReports = 0,
      ReceiverReports = 1,
   };
   // ResetSeqNumFlagCodeSet (Boolean)
   enum class ResetSeqNumFlag : uint16_t {
      No = 0,
      Yes = 1,
   };
   // RoutingTypeCodeSet (int)
   enum class RoutingType : int32_t {
      TargetFirm = 1,
      TargetList = 2,
      BlockFirm = 3,
      BlockList = 4,
   };
   // Rule80ACodeSet (char)
   enum class Rule80A : char {
      AgencySingleOrder = 'A',
      ShortExemptTransactionAType = 'B',
      ProprietaryNonAlgo = 'C',
      ProgramOrderMember = 'D',
      ShortExemptTransactionForPrincipal = 'E',
      ShortExemptTransactionWType = 'F',
      ShortExemptTransactionIType = 'H',
      IndividualInvestor = 'I',
      ProprietaryAlgo = 'J',
      AgencyAlgo = 'K',
      ShortExemptTransactionMemberAffliated = 'L',
      ProgramOrderOtherMember = 'M',
      AgentForOtherMember = 'N',
      ProprietaryTransactionAffiliated = 'O',
      Principal = 'P',
      TransactionNonMember = 'R',
      SpecialistTrades = 'S',
      TransactionUnaffiliatedMember = 'T',
      AgencyIndexArb = 'U',
      AllOtherOrdersAsAgentForOtherMember = 'W',
      ShortExemptTransactionMemberNotAffliated = 'X',
      AgencyNonAlgo = 'Y',
      ShortExemptTransactionNonMember = 'Z',
   };
   // SecurityRequestTypeCodeSet (int)
   enum class SecurityRequestType : int32_t {
      RequestSecurityIdentityAndSpecifications = 0,
      RequestSecurityIdentityForSpecifications = 1,
      RequestListSecurityTypes = 2,
      RequestListSecurities = 3,
   };
   // SecurityResponseTypeCodeSet (int)
   enum class SecurityResponseType : int32_t {
      AcceptAsIs = 1,
      AcceptWithRevisions = 2,
      ListOfSecurityTypesReturnedPerRequest = 3,
      ListOfSecuritiesReturnedPerRequest = 4,
      RejectSecurityProposal = 5,
      CannotMatchSelectionCriteria = 6,
   };
   // SecurityTradingStatusCodeSet (int)
   enum class SecurityTradingStatus : int32_t {
      OpeningDelay = 1,
      MarketOnCloseImbalanceSell = 10,
      NoMarketImbalance = 12,
      NoMarketOnCloseImbalance = 13,
      ITSPreOpening = 14,
      NewPriceIndication = 15,
      TradeDisseminationTime = 16,
      ReadyToTrade = 17,
      NotAvailableForTrading = 18,
      NotTradedOnThisMarket = 19,
      TradingHalt = 2,
      UnknownOrInvalid = 20,
      Resume = 3,
      NoOpen = 4,
      PriceIndication = 5,
      TradingRangeIndication = 6,
      MarketImbalanceBuy = 7,
      MarketImbalanceSell = 8,
      MarketOnCloseImbalanceBuy = 9,
   };
   // SecurityTypeCodeSet (String)
   enum class SecurityType : uint16_t {
      Wildcard = 0,
      BankersAcceptance = 1,
      ConvertibleBond = 2,
      CertificateOfDeposit = 3,
      CollateralizedMortgageObligation = 4,
      CorporateBond = 5,
      CommercialPaper = 6,
      CorporatePrivatePlacement = 7,
      CommonStock = 8,
      FederalHousingAuthority = 9,
      FederalHomeLoan = 10,
      FederalNationalMortgageAssociation = 11,
      ForeignExchangeContract = 12,
      Future = 13,
      GovernmentNationalMortgageAssociation = 14,
      TreasuriesAgencyDebenture = 15,
      IOETTEMortgage = 16,
      MutualFund = 17,
      MortgageInterestOnly = 18,
      MortgagePrincipalOnly = 19,
      MortgagePrivatePlacement = 20,
      MiscellaneousPassThrough = 21,
      MunicipalBond = 22,
      NoSecurityType = 23,
      Option = 24,
      PreferredStock = 25,
      RepurchaseAgreement = 26,
      ReverseRepurchaseAgreement = 27,
      StudentLoanMarketingAssociation = 28,
      TimeDeposit = 29,
      USTreasuryBillOld = 30,
      Warrant = 31,
      CatsTigersAndLions = 32,
   };
   // SessionRejectReasonCodeSet (int)
   enum class SessionRejectReason : int32_t {
      InvalidTagNumber = 0,
      RequiredTagMissing = 1,
      SendingTimeAccuracyProblem = 10,
      InvalidMsgType = 11,
      TagNotDefinedForThisMessageType = 2,
      UndefinedTag = 3,
      TagSpecifiedWithoutAValue = 4,
      ValueIsIncorrect = 5,
      IncorrectDataFormatForValue = 6,
      DecryptionProblem = 7,
      SignatureProblem = 8,
      CompIDProblem = 9,
   };
   // SettlCurrFxRateCalcCodeSet (char)
   enum class SettlCurrFxRateCalc : char {
      Multiply = 'M',
      Divide = 'D',
   };
   // SettlDeliveryTypeCodeSet (int)
   enum class SettlDeliveryType : int32_t {
      Versus = 0,
      Free = 1,
   };
   // SettlInstModeCodeSet (char)
   enum class SettlInstMode : char {
      Default = '0',
      StandingInstructionsProvided = '1',
      SpecificAllocationAccountOverriding = '2',
      SpecificAllocationAccountStanding = '3',
   };
   // SettlInstSourceCodeSet (char)
   enum class SettlInstSource : char {
      BrokerCredit = '1',
      Institution = '2',
   };
   // SettlInstTransTypeCodeSet (char)
   enum class SettlInstTransType : char {
      Cancel = 'C',
      New = 'N',
      Replace = 'R',
   };
   // SettlLocationCodeSet (String)
   enum class SettlLocation : uint16_t {
      CEDEL = 0,
      DepositoryTrustCompany = 1,
      EuroClear = 2,
      FederalBookEntry = 3,
      LocalMarketSettleLocation = 4,
      Physical = 5,
      ParticipantTrustCompany = 6,
   };
   // SettlmntTypCodeSet (char)
   enum class SettlmntTyp : char {
      Regular = '0',
      Cash = '1',
      NextDay = '2',
      TPlus2 = '3',
      TPlus3 = '4',
      TPlus4 = '5',
      Future = '6',
      WhenAndIfIssued = '7',
      SellersOption = '8',
      TPlus5 = '9',
   };
   // SideCodeSet (char)
   enum class Side : char {
      Buy = '1',
      Sell = '2',
      BuyMinus = '3',
      SellPlus = '4',
      SellShort = '5',
      SellShortExempt = '6',
      Undisclosed = '7',
      Cross = '8',
      CrossShort = '9',
   };
   // SideValueIndCodeSet (int)
   enum class SideValueInd : int32_t {
      SideValue1 = 1,
      SideValue2 = 2,
   };
   // SolicitedFlagCodeSet (Boolean)
   enum class SolicitedFlag : uint16_t {
      WasNotSolicited = 0,
      WasSolicited = 1,
   };
   // StandInstDbTypeCodeSet (int)
   enum class StandInstDbType : int32_t {
      Other = 0,
      DTCSID = 1,
      ThomsonALERT = 2,
      AGlobalCustodian = 3,
   };
   // SubscriptionRequestTypeCodeSet (char)
   enum class SubscriptionRequestType : char {
      Snapshot = '0',
      SnapshotAndUpdates = '1',
      DisablePreviousSnapshot = '2',
   };
   // TickDirectionCodeSet (char)
   enum class TickDirection : char {
      PlusTick = '0',
      ZeroPlusTick = '1',
      MinusTick = '2',
      ZeroMinusTick = '3',
   };
   // TimeInForceCodeSet (char)
   enum class TimeInForce : char {
      Day = '0',
      GoodTillCancel = '1',
      AtTheOpening = '2',
      ImmediateOrCancel = '3',
      FillOrKill = '4',
      GoodTillCrossing = '5',
      GoodTillDate = '6',
   };
   // TradSesMethodCodeSet (int)
   enum class TradSesMethod : int32_t {
      Electronic = 1,
      OpenOutcry = 2,
      TwoParty = 3,
   };
   // TradSesModeCodeSet (int)
   enum class TradSesMode : int32_t {
      Testing = 1,
      Simulated = 2,
      Production = 3,
   };
   // TradSesStatusCodeSet (int)
   enum class TradSesStatus : int32_t {
      Halted = 1,
      Open = 2,
      Closed = 3,
      PreOpen = 4,
      PreClose = 5,
   };
   // TradeConditionCodeSet (MultipleValueString)
   enum class TradeCondition : uint16_t {
      Cash = 0,
      AveragePriceTrade = 1,
      CashTrade = 2,
      NextDay = 3,
      Opening = 4,
      IntradayTradeDetail = 5,
      Rule127Trade = 6,
      Rule155Trade = 7,
      SoldLast = 8,
      NextDayTrade = 9,
      Opened = 10,
      Seller = 11,
      Sold = 12,
      StoppedStock = 13,
   };
   // TradeTypeCodeSet (char)
   enum class TradeType : char {
      Agency = 'A',
      VWAPGuarantee = 'G',
      GuaranteedClose = 'J',
      RiskTrade = 'R',
   };
   // UnsolicitedIndicatorCodeSet (Boolean)
   enum class UnsolicitedIndicator : uint16_t {
      MessageIsBeingSentAsAResultOfAPriorRequest = 0,
      MessageIsBeingSentUnsolicited = 1,
   };
   // UrgencyCodeSet (char)
   enum class Urgency : char {
      Normal = '0',
      Flash = '1',
      Background = '2',
   };

   // ---- repeating groups ----
   struct IOIQualGrp
   {
      std::optional<IOIQualifier> ioi_qualifier{};
      bool operator==(const IOIQualGrp&) const = default;
   };
   struct RoutingGrp
   {
      std::optional<RoutingType> routing_type{};
      std::optional<std::string> routing_id{};
      bool operator==(const RoutingGrp&) const = default;
   };
   struct ContraGrp
   {
      std::optional<std::string> contra_broker{};
      std::optional<std::string> contra_trader{};
      std::optional<double> contra_trade_qty{};
      std::optional<std::string> contra_trade_time{};
      bool operator==(const ContraGrp&) const = default;
   };
   struct MsgTypeGrp
   {
      std::optional<std::string> ref_msg_type{};
      std::optional<MsgDirection> msg_direction{};
      bool operator==(const MsgTypeGrp&) const = default;
   };
   struct InstrmtGrp
   {
      std::optional<std::string> relatd_sym{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      bool operator==(const InstrmtGrp&) const = default;
   };
   struct LinesOfTextGrp
   {
      std::string text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const LinesOfTextGrp&) const = default;
   };
   struct PreAllocGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<double> alloc_shares{};
      bool operator==(const PreAllocGrp&) const = default;
   };
   struct TrdgSesGrp
   {
      std::optional<std::string> trading_session_id{};
      bool operator==(const TrdgSesGrp&) const = default;
   };
   struct ListOrdGrp
   {
      std::string cl_ord_id{};
      int64_t list_seq_no{};
      std::optional<SettlInstMode> settl_inst_mode{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::optional<std::string> account{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> prev_close_px{};
      Side side{};
      std::optional<SideValueInd> side_value_ind{};
      std::optional<bool> locate_reqd{};
      std::optional<std::string> transact_time{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<OrdType> ord_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<bool> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<Rule80A> rule80_a{};
      std::optional<bool> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<OpenClose> open_close{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<CustomerOrFirm> customer_or_firm{};
      std::optional<double> max_show{};
      std::optional<double> peg_difference{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset{};
      std::optional<std::string> clearing_firm{};
      std::optional<std::string> clearing_account{};
      bool operator==(const ListOrdGrp&) const = default;
   };
   struct OrdAllocGrp
   {
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> list_id{};
      std::optional<std::string> wave_no{};
      bool operator==(const OrdAllocGrp&) const = default;
   };
   struct ExecAllocGrp
   {
      std::optional<double> last_shares{};
      std::optional<std::string> exec_id{};
      std::optional<double> last_px{};
      std::optional<LastCapacity> last_capacity{};
      bool operator==(const ExecAllocGrp&) const = default;
   };
   struct MiscFeesGrp
   {
      std::optional<double> misc_fee_amt{};
      std::optional<std::string> misc_fee_curr{};
      std::optional<MiscFeeType> misc_fee_type{};
      bool operator==(const MiscFeesGrp&) const = default;
   };
   struct AllocGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<double> alloc_price{};
      double alloc_shares{};
      std::optional<ProcessCode> process_code{};
      std::optional<std::string> broker_of_credit{};
      std::optional<bool> notify_broker_of_credit{};
      std::optional<AllocHandlInst> alloc_handl_inst{};
      std::optional<std::string> alloc_text{};
      std::optional<int64_t> encoded_alloc_text_len{};
      std::optional<std::string> encoded_alloc_text{};
      std::optional<std::string> exec_broker{};
      std::optional<std::string> client_id{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<double> alloc_avg_px{};
      std::optional<double> alloc_net_money{};
      std::optional<double> settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<double> accrued_interest_amt{};
      std::optional<SettlInstMode> settl_inst_mode{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      bool operator==(const AllocGrp&) const = default;
   };
   struct OrdListStatGrp
   {
      std::string cl_ord_id{};
      double cum_qty{};
      OrdStatus ord_status{};
      double leaves_qty{};
      double cxl_qty{};
      double avg_px{};
      std::optional<OrdRejReason> ord_rej_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrdListStatGrp&) const = default;
   };
   struct QuotReqGrp
   {
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> prev_close_px{};
      std::optional<QuoteRequestType> quote_request_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<Side> side{};
      std::optional<double> order_qty{};
      std::optional<std::string> fut_sett_date{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> currency{};
      bool operator==(const QuotReqGrp&) const = default;
   };
   struct MDReqGrp
   {
      MDEntryType md_entry_type{};
      bool operator==(const MDReqGrp&) const = default;
   };
   struct InstrmtMDReqGrp
   {
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> trading_session_id{};
      bool operator==(const InstrmtMDReqGrp&) const = default;
   };
   struct MDFullGrp
   {
      MDEntryType md_entry_type{};
      double md_entry_px{};
      std::optional<std::string> currency{};
      std::optional<double> md_entry_size{};
      std::optional<std::string> md_entry_date{};
      std::optional<std::string> md_entry_time{};
      std::optional<TickDirection> tick_direction{};
      std::optional<std::string> md_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> quote_condition{};
      std::optional<std::string> trade_condition{};
      std::optional<std::string> md_entry_originator{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      std::optional<OpenCloseSettleFlag> open_close_settle_flag{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<double> min_qty{};
      std::optional<std::string> exec_inst{};
      std::optional<int64_t> seller_days{};
      std::optional<std::string> order_id{};
      std::optional<std::string> quote_entry_id{};
      std::optional<std::string> md_entry_buyer{};
      std::optional<std::string> md_entry_seller{};
      std::optional<int64_t> number_of_orders{};
      std::optional<int64_t> md_entry_position_no{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const MDFullGrp&) const = default;
   };
   struct MDIncGrp
   {
      MDUpdateAction md_update_action{};
      std::optional<DeleteReason> delete_reason{};
      std::optional<MDEntryType> md_entry_type{};
      std::optional<std::string> md_entry_id{};
      std::optional<std::string> md_entry_ref_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<FinancialStatus> financial_status{};
      std::optional<CorporateAction> corporate_action{};
      std::optional<double> md_entry_px{};
      std::optional<std::string> currency{};
      std::optional<double> md_entry_size{};
      std::optional<std::string> md_entry_date{};
      std::optional<std::string> md_entry_time{};
      std::optional<TickDirection> tick_direction{};
      std::optional<std::string> md_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> quote_condition{};
      std::optional<std::string> trade_condition{};
      std::optional<std::string> md_entry_originator{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      std::optional<OpenCloseSettleFlag> open_close_settle_flag{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<double> min_qty{};
      std::optional<std::string> exec_inst{};
      std::optional<int64_t> seller_days{};
      std::optional<std::string> order_id{};
      std::optional<std::string> quote_entry_id{};
      std::optional<std::string> md_entry_buyer{};
      std::optional<std::string> md_entry_seller{};
      std::optional<int64_t> number_of_orders{};
      std::optional<int64_t> md_entry_position_no{};
      std::optional<double> total_volume_traded{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const MDIncGrp&) const = default;
   };
   struct QuotCxlEntriesGrp
   {
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> underlying_symbol{};
      bool operator==(const QuotCxlEntriesGrp&) const = default;
   };
   struct QuotEntryAckGrp
   {
      std::optional<std::string> quote_entry_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<QuoteEntryRejectReason> quote_entry_reject_reason{};
      bool operator==(const QuotEntryAckGrp&) const = default;
   };
   struct QuotSetAckGrp
   {
      std::optional<std::string> quote_set_id{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<std::string> underlying_id_source{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<int64_t> underlying_maturity_day{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<double> underlying_strike_price{};
      std::optional<char> underlying_opt_attribute{};
      std::optional<double> underlying_contract_multiplier{};
      std::optional<double> underlying_coupon_rate{};
      std::optional<std::string> underlying_security_exchange{};
      std::optional<std::string> underlying_issuer{};
      std::optional<int64_t> encoded_underlying_issuer_len{};
      std::optional<std::string> encoded_underlying_issuer{};
      std::optional<std::string> underlying_security_desc{};
      std::optional<int64_t> encoded_underlying_security_desc_len{};
      std::optional<std::string> encoded_underlying_security_desc{};
      std::optional<int64_t> tot_quote_entries{};
      std::vector<QuotEntryAckGrp> no_quote_entries{};
      bool operator==(const QuotSetAckGrp&) const = default;
   };
   struct UndInstrmtGrp
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<std::string> underlying_id_source{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<int64_t> underlying_maturity_day{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<double> underlying_strike_price{};
      std::optional<char> underlying_opt_attribute{};
      std::optional<double> underlying_contract_multiplier{};
      std::optional<double> underlying_coupon_rate{};
      std::optional<std::string> underlying_security_exchange{};
      std::optional<std::string> underlying_issuer{};
      std::optional<int64_t> encoded_underlying_issuer_len{};
      std::optional<std::string> encoded_underlying_issuer{};
      std::optional<std::string> underlying_security_desc{};
      std::optional<int64_t> encoded_underlying_security_desc_len{};
      std::optional<std::string> encoded_underlying_security_desc{};
      std::optional<double> ratio_qty{};
      std::optional<Side> side{};
      std::optional<std::string> underlying_currency{};
      bool operator==(const UndInstrmtGrp&) const = default;
   };
   struct QuotEntryGrp
   {
      std::optional<std::string> quote_entry_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> bid_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> fut_sett_date{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      bool operator==(const QuotEntryGrp&) const = default;
   };
   struct QuotSetGrp
   {
      std::string quote_set_id{};
      std::string underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<std::string> underlying_id_source{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<int64_t> underlying_maturity_day{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<double> underlying_strike_price{};
      std::optional<char> underlying_opt_attribute{};
      std::optional<double> underlying_contract_multiplier{};
      std::optional<double> underlying_coupon_rate{};
      std::optional<std::string> underlying_security_exchange{};
      std::optional<std::string> underlying_issuer{};
      std::optional<int64_t> encoded_underlying_issuer_len{};
      std::optional<std::string> encoded_underlying_issuer{};
      std::optional<std::string> underlying_security_desc{};
      std::optional<int64_t> encoded_underlying_security_desc_len{};
      std::optional<std::string> encoded_underlying_security_desc{};
      std::optional<std::string> quote_set_valid_until_time{};
      int64_t tot_quote_entries{};
      std::vector<QuotEntryGrp> no_quote_entries{};
      bool operator==(const QuotSetGrp&) const = default;
   };
   struct BidDescReqGrp
   {
      std::optional<BidDescriptorType> bid_descriptor_type{};
      std::optional<std::string> bid_descriptor{};
      std::optional<SideValueInd> side_value_ind{};
      std::optional<double> liquidity_value{};
      std::optional<int64_t> liquidity_num_securities{};
      std::optional<double> liquidity_pct_low{};
      std::optional<double> liquidity_pct_high{};
      std::optional<double> efp_tracking_error{};
      std::optional<double> fair_value{};
      std::optional<double> outside_index_pct{};
      std::optional<double> value_of_futures{};
      bool operator==(const BidDescReqGrp&) const = default;
   };
   struct BidCompReqGrp
   {
      std::optional<std::string> list_id{};
      std::optional<Side> side{};
      std::optional<std::string> trading_session_id{};
      std::optional<NetGrossInd> net_gross_ind{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      std::optional<std::string> account{};
      bool operator==(const BidCompReqGrp&) const = default;
   };
   struct BidCompRspGrp
   {
      double commission{};
      CommType comm_type{};
      std::optional<std::string> list_id{};
      std::optional<std::string> country{};
      std::optional<Side> side{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> fair_value{};
      std::optional<NetGrossInd> net_gross_ind{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const BidCompRspGrp&) const = default;
   };
   struct InstrmtStrkPxGrp
   {
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> prev_close_px{};
      std::optional<std::string> cl_ord_id{};
      std::optional<Side> side{};
      double price{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const InstrmtStrkPxGrp&) const = default;
   };

   // ---- components (flattened) ----
   struct StandardHeader
   {
      std::string begin_string{};
      int64_t body_length{};
      std::string msg_type{};
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
      std::string sending_time{};
      std::optional<std::string> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<std::string> message_encoding{};
      std::optional<int64_t> last_msg_seq_num_processed{};
      std::optional<std::string> on_behalf_of_sending_time{};
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
      std::optional<std::string> test_req_id{};
      bool operator==(const Heartbeat&) const = default;
   };
   struct TestRequest
   {
      std::string test_req_id{};
      bool operator==(const TestRequest&) const = default;
   };
   struct ResendRequest
   {
      int64_t begin_seq_no{};
      int64_t end_seq_no{};
      bool operator==(const ResendRequest&) const = default;
   };
   struct Reject
   {
      int64_t ref_seq_num{};
      std::optional<int64_t> ref_tag_id{};
      std::optional<std::string> ref_msg_type{};
      std::optional<SessionRejectReason> session_reject_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Reject&) const = default;
   };
   struct SequenceReset
   {
      std::optional<bool> gap_fill_flag{};
      int64_t new_seq_no{};
      bool operator==(const SequenceReset&) const = default;
   };
   struct Logout
   {
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Logout&) const = default;
   };
   struct IOI
   {
      std::string ioiid{};
      IOITransType ioi_trans_type{};
      std::optional<std::string> ioi_ref_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      std::string ioi_shares{};
      std::optional<double> price{};
      std::optional<std::string> currency{};
      std::optional<std::string> valid_until_time{};
      std::optional<IOIQltyInd> ioi_qlty_ind{};
      std::optional<bool> ioi_natural_flag{};
      std::vector<IOIQualGrp> no_ioi_qualifiers{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> url_link{};
      std::vector<RoutingGrp> no_routing_ids{};
      std::optional<double> spread_to_benchmark{};
      std::optional<Benchmark> benchmark{};
      bool operator==(const IOI&) const = default;
   };
   struct Advertisement
   {
      std::string adv_id{};
      std::string adv_trans_type{};
      std::optional<std::string> adv_ref_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      AdvSide adv_side{};
      double shares{};
      std::optional<double> price{};
      std::optional<std::string> currency{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> url_link{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trading_session_id{};
      bool operator==(const Advertisement&) const = default;
   };
   struct ExecutionReport
   {
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> orig_cl_ord_id{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::vector<ContraGrp> no_contra_brokers{};
      std::optional<std::string> list_id{};
      std::string exec_id{};
      ExecTransType exec_trans_type{};
      std::optional<std::string> exec_ref_id{};
      ExecType exec_type{};
      OrdStatus ord_status{};
      std::optional<OrdRejReason> ord_rej_reason{};
      std::optional<ExecRestatementReason> exec_restatement_reason{};
      std::optional<std::string> account{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<OrdType> ord_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> peg_difference{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<bool> solicited_flag{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> exec_inst{};
      std::optional<Rule80A> rule80_a{};
      std::optional<double> last_shares{};
      std::optional<double> last_px{};
      std::optional<double> last_spot_rate{};
      std::optional<double> last_forward_points{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<LastCapacity> last_capacity{};
      double leaves_qty{};
      double cum_qty{};
      double avg_px{};
      std::optional<double> day_order_qty{};
      std::optional<double> day_cum_qty{};
      std::optional<double> day_avg_px{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> transact_time{};
      std::optional<bool> report_to_exch{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<double> gross_trade_amt{};
      std::optional<double> settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<HandlInst> handl_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<OpenClose> open_close{};
      std::optional<double> max_show{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> clearing_firm{};
      std::optional<std::string> clearing_account{};
      std::optional<MultiLegReportingType> multi_leg_reporting_type{};
      bool operator==(const ExecutionReport&) const = default;
   };
   struct OrderCancelReject
   {
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::string cl_ord_id{};
      std::string orig_cl_ord_id{};
      OrdStatus ord_status{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::optional<std::string> list_id{};
      std::optional<std::string> account{};
      std::optional<std::string> transact_time{};
      CxlRejResponseTo cxl_rej_response_to{};
      std::optional<CxlRejReason> cxl_rej_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrderCancelReject&) const = default;
   };
   struct Logon
   {
      EncryptMethod encrypt_method{};
      int64_t heart_bt_int{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      std::optional<bool> reset_seq_num_flag{};
      std::optional<int64_t> max_message_size{};
      std::vector<MsgTypeGrp> no_msg_types{};
      bool operator==(const Logon&) const = default;
   };
   struct News
   {
      std::optional<std::string> orig_time{};
      std::optional<Urgency> urgency{};
      std::string headline{};
      std::optional<int64_t> encoded_headline_len{};
      std::optional<std::string> encoded_headline{};
      std::vector<RoutingGrp> no_routing_ids{};
      std::vector<InstrmtGrp> no_related_sym{};
      std::vector<LinesOfTextGrp> lines_of_text{};
      std::optional<std::string> url_link{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      bool operator==(const News&) const = default;
   };
   struct Email
   {
      std::string email_thread_id{};
      EmailType email_type{};
      std::optional<std::string> orig_time{};
      std::string subject{};
      std::optional<int64_t> encoded_subject_len{};
      std::optional<std::string> encoded_subject{};
      std::vector<RoutingGrp> no_routing_ids{};
      std::vector<InstrmtGrp> no_related_sym{};
      std::optional<std::string> order_id{};
      std::optional<std::string> cl_ord_id{};
      std::vector<LinesOfTextGrp> lines_of_text{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      bool operator==(const Email&) const = default;
   };
   struct NewOrderSingle
   {
      std::string cl_ord_id{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::optional<std::string> account{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      HandlInst handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> prev_close_px{};
      Side side{};
      std::optional<bool> locate_reqd{};
      std::string transact_time{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      OrdType ord_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<bool> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<Rule80A> rule80_a{};
      std::optional<bool> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<OpenClose> open_close{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<CustomerOrFirm> customer_or_firm{};
      std::optional<double> max_show{};
      std::optional<double> peg_difference{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset{};
      std::optional<std::string> clearing_firm{};
      std::optional<std::string> clearing_account{};
      bool operator==(const NewOrderSingle&) const = default;
   };
   struct NewOrderList
   {
      std::string list_id{};
      std::optional<std::string> bid_id{};
      std::optional<std::string> client_bid_id{};
      std::optional<ProgRptReqs> prog_rpt_reqs{};
      BidType bid_type{};
      std::optional<int64_t> prog_period_interval{};
      std::optional<ListExecInstType> list_exec_inst_type{};
      std::optional<std::string> list_exec_inst{};
      std::optional<int64_t> encoded_list_exec_inst_len{};
      std::optional<std::string> encoded_list_exec_inst{};
      int64_t tot_no_orders{};
      std::vector<ListOrdGrp> no_orders{};
      bool operator==(const NewOrderList&) const = default;
   };
   struct OrderCancelRequest
   {
      std::string orig_cl_ord_id{};
      std::optional<std::string> order_id{};
      std::string cl_ord_id{};
      std::optional<std::string> list_id{};
      std::optional<std::string> account{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      std::string transact_time{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<std::string> compliance_id{};
      std::optional<bool> solicited_flag{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrderCancelRequest&) const = default;
   };
   struct OrderCancelReplaceRequest
   {
      std::optional<std::string> order_id{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::string orig_cl_ord_id{};
      std::string cl_ord_id{};
      std::optional<std::string> list_id{};
      std::optional<std::string> account{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      HandlInst handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      std::string transact_time{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      OrdType ord_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> peg_difference{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset{};
      std::optional<std::string> compliance_id{};
      std::optional<bool> solicited_flag{};
      std::optional<std::string> currency{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<Rule80A> rule80_a{};
      std::optional<bool> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<OpenClose> open_close{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<CustomerOrFirm> customer_or_firm{};
      std::optional<double> max_show{};
      std::optional<bool> locate_reqd{};
      std::optional<std::string> clearing_firm{};
      std::optional<std::string> clearing_account{};
      bool operator==(const OrderCancelReplaceRequest&) const = default;
   };
   struct OrderStatusRequest
   {
      std::optional<std::string> order_id{};
      std::string cl_ord_id{};
      std::optional<std::string> client_id{};
      std::optional<std::string> account{};
      std::optional<std::string> exec_broker{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      bool operator==(const OrderStatusRequest&) const = default;
   };
   struct Allocation
   {
      std::string alloc_id{};
      AllocTransType alloc_trans_type{};
      std::optional<std::string> ref_alloc_id{};
      std::optional<std::string> alloc_link_id{};
      std::optional<AllocLinkType> alloc_link_type{};
      std::vector<OrdAllocGrp> no_orders{};
      std::vector<ExecAllocGrp> no_execs{};
      Side side{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      double shares{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trading_session_id{};
      double avg_px{};
      std::optional<std::string> currency{};
      std::optional<int64_t> avg_prx_precision{};
      std::string trade_date{};
      std::optional<std::string> transact_time{};
      std::optional<SettlmntTyp> settlmnt_typ{};
      std::optional<std::string> fut_sett_date{};
      std::optional<double> gross_trade_amt{};
      std::optional<double> net_money{};
      std::optional<OpenClose> open_close{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<int64_t> num_days_interest{};
      std::optional<double> accrued_interest_rate{};
      std::vector<AllocGrp> no_allocs{};
      bool operator==(const Allocation&) const = default;
   };
   struct ListCancelRequest
   {
      std::string list_id{};
      std::string transact_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const ListCancelRequest&) const = default;
   };
   struct ListExecute
   {
      std::string list_id{};
      std::optional<std::string> client_bid_id{};
      std::optional<std::string> bid_id{};
      std::string transact_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const ListExecute&) const = default;
   };
   struct ListStatusRequest
   {
      std::string list_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const ListStatusRequest&) const = default;
   };
   struct ListStatus
   {
      std::string list_id{};
      ListStatusType list_status_type{};
      int64_t no_rpts{};
      ListOrderStatus list_order_status{};
      int64_t rpt_seq{};
      std::optional<std::string> list_status_text{};
      std::optional<int64_t> encoded_list_status_text_len{};
      std::optional<std::string> encoded_list_status_text{};
      std::optional<std::string> transact_time{};
      int64_t tot_no_orders{};
      std::vector<OrdListStatGrp> no_orders{};
      bool operator==(const ListStatus&) const = default;
   };
   struct AllocationAck
   {
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::string alloc_id{};
      std::string trade_date{};
      std::optional<std::string> transact_time{};
      AllocStatus alloc_status{};
      std::optional<AllocRejCode> alloc_rej_code{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const AllocationAck&) const = default;
   };
   struct DontKnowTrade
   {
      std::string order_id{};
      std::string exec_id{};
      DKReason dk_reason{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      Side side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> last_shares{};
      std::optional<double> last_px{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const DontKnowTrade&) const = default;
   };
   struct QuoteRequest
   {
      std::string quote_req_id{};
      std::vector<QuotReqGrp> no_related_sym{};
      bool operator==(const QuoteRequest&) const = default;
   };
   struct Quote
   {
      std::optional<std::string> quote_req_id{};
      std::string quote_id{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::optional<std::string> trading_session_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> bid_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> fut_sett_date{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> fut_sett_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      bool operator==(const Quote&) const = default;
   };
   struct SettlementInstructions
   {
      std::string settl_inst_id{};
      SettlInstTransType settl_inst_trans_type{};
      std::string settl_inst_ref_id{};
      SettlInstMode settl_inst_mode{};
      SettlInstSource settl_inst_source{};
      std::string alloc_account{};
      std::optional<std::string> settl_location{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> alloc_id{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<Side> side{};
      std::optional<std::string> security_type{};
      std::optional<std::string> effective_time{};
      std::string transact_time{};
      std::optional<std::string> client_id{};
      std::optional<std::string> exec_broker{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<std::string> settl_depository_code{};
      std::optional<std::string> settl_brkr_code{};
      std::optional<std::string> settl_inst_code{};
      std::optional<std::string> security_settl_agent_name{};
      std::optional<std::string> security_settl_agent_code{};
      std::optional<std::string> security_settl_agent_acct_num{};
      std::optional<std::string> security_settl_agent_acct_name{};
      std::optional<std::string> security_settl_agent_contact_name{};
      std::optional<std::string> security_settl_agent_contact_phone{};
      std::optional<std::string> cash_settl_agent_name{};
      std::optional<std::string> cash_settl_agent_code{};
      std::optional<std::string> cash_settl_agent_acct_num{};
      std::optional<std::string> cash_settl_agent_acct_name{};
      std::optional<std::string> cash_settl_agent_contact_name{};
      std::optional<std::string> cash_settl_agent_contact_phone{};
      bool operator==(const SettlementInstructions&) const = default;
   };
   struct MarketDataRequest
   {
      std::string md_req_id{};
      SubscriptionRequestType subscription_request_type{};
      int64_t market_depth{};
      std::optional<MDUpdateType> md_update_type{};
      std::optional<bool> aggregated_book{};
      std::vector<MDReqGrp> no_md_entry_types{};
      std::vector<InstrmtMDReqGrp> no_related_sym{};
      bool operator==(const MarketDataRequest&) const = default;
   };
   struct MarketDataSnapshotFullRefresh
   {
      std::optional<std::string> md_req_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<FinancialStatus> financial_status{};
      std::optional<CorporateAction> corporate_action{};
      std::optional<double> total_volume_traded{};
      std::vector<MDFullGrp> no_md_entries{};
      bool operator==(const MarketDataSnapshotFullRefresh&) const = default;
   };
   struct MarketDataIncrementalRefresh
   {
      std::optional<std::string> md_req_id{};
      std::vector<MDIncGrp> no_md_entries{};
      bool operator==(const MarketDataIncrementalRefresh&) const = default;
   };
   struct MarketDataRequestReject
   {
      std::string md_req_id{};
      std::optional<MDReqRejReason> md_req_rej_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const MarketDataRequestReject&) const = default;
   };
   struct QuoteCancel
   {
      std::optional<std::string> quote_req_id{};
      std::string quote_id{};
      QuoteCancelType quote_cancel_type{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::optional<std::string> trading_session_id{};
      std::vector<QuotCxlEntriesGrp> no_quote_entries{};
      bool operator==(const QuoteCancel&) const = default;
   };
   struct QuoteStatusRequest
   {
      std::optional<std::string> quote_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<Side> side{};
      std::optional<std::string> trading_session_id{};
      bool operator==(const QuoteStatusRequest&) const = default;
   };
   struct QuoteAcknowledgement
   {
      std::optional<std::string> quote_req_id{};
      std::optional<std::string> quote_id{};
      QuoteAckStatus quote_ack_status{};
      std::optional<QuoteRejectReason> quote_reject_reason{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> text{};
      std::vector<QuotSetAckGrp> no_quote_sets{};
      bool operator==(const QuoteAcknowledgement&) const = default;
   };
   struct SecurityDefinitionRequest
   {
      std::string security_req_id{};
      SecurityRequestType security_request_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::vector<UndInstrmtGrp> no_related_sym{};
      bool operator==(const SecurityDefinitionRequest&) const = default;
   };
   struct SecurityDefinition
   {
      std::string security_req_id{};
      std::string security_response_id{};
      std::optional<SecurityResponseType> security_response_type{};
      int64_t total_num_securities{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> currency{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<UndInstrmtGrp> no_related_sym{};
      bool operator==(const SecurityDefinition&) const = default;
   };
   struct SecurityStatusRequest
   {
      std::string security_status_req_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> currency{};
      SubscriptionRequestType subscription_request_type{};
      std::optional<std::string> trading_session_id{};
      bool operator==(const SecurityStatusRequest&) const = default;
   };
   struct SecurityStatus
   {
      std::optional<std::string> security_status_req_id{};
      std::string symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<std::string> id_source{};
      std::optional<std::string> security_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<int64_t> maturity_day{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<double> strike_price{};
      std::optional<char> opt_attribute{};
      std::optional<double> contract_multiplier{};
      std::optional<double> coupon_rate{};
      std::optional<std::string> security_exchange{};
      std::optional<std::string> issuer{};
      std::optional<int64_t> encoded_issuer_len{};
      std::optional<std::string> encoded_issuer{};
      std::optional<std::string> security_desc{};
      std::optional<int64_t> encoded_security_desc_len{};
      std::optional<std::string> encoded_security_desc{};
      std::optional<std::string> currency{};
      std::optional<std::string> trading_session_id{};
      std::optional<bool> unsolicited_indicator{};
      std::optional<SecurityTradingStatus> security_trading_status{};
      std::optional<FinancialStatus> financial_status{};
      std::optional<CorporateAction> corporate_action{};
      std::optional<HaltReason> halt_reason{};
      std::optional<bool> in_view_of_common{};
      std::optional<bool> due_to_related{};
      std::optional<double> buy_volume{};
      std::optional<double> sell_volume{};
      std::optional<double> high_px{};
      std::optional<double> low_px{};
      std::optional<double> last_px{};
      std::optional<std::string> transact_time{};
      std::optional<Adjustment> adjustment{};
      bool operator==(const SecurityStatus&) const = default;
   };
   struct TradingSessionStatusRequest
   {
      std::string trad_ses_req_id{};
      std::optional<std::string> trading_session_id{};
      std::optional<TradSesMethod> trad_ses_method{};
      std::optional<TradSesMode> trad_ses_mode{};
      SubscriptionRequestType subscription_request_type{};
      bool operator==(const TradingSessionStatusRequest&) const = default;
   };
   struct TradingSessionStatus
   {
      std::optional<std::string> trad_ses_req_id{};
      std::string trading_session_id{};
      std::optional<TradSesMethod> trad_ses_method{};
      std::optional<TradSesMode> trad_ses_mode{};
      std::optional<bool> unsolicited_indicator{};
      TradSesStatus trad_ses_status{};
      std::optional<std::string> trad_ses_start_time{};
      std::optional<std::string> trad_ses_open_time{};
      std::optional<std::string> trad_ses_pre_close_time{};
      std::optional<std::string> trad_ses_close_time{};
      std::optional<std::string> trad_ses_end_time{};
      std::optional<double> total_volume_traded{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const TradingSessionStatus&) const = default;
   };
   struct MassQuote
   {
      std::optional<std::string> quote_req_id{};
      std::string quote_id{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::optional<double> def_bid_size{};
      std::optional<double> def_offer_size{};
      std::vector<QuotSetGrp> no_quote_sets{};
      bool operator==(const MassQuote&) const = default;
   };
   struct BusinessMessageReject
   {
      std::optional<int64_t> ref_seq_num{};
      std::string ref_msg_type{};
      std::optional<std::string> business_reject_ref_id{};
      BusinessRejectReason business_reject_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const BusinessMessageReject&) const = default;
   };
   struct BidRequest
   {
      std::optional<std::string> bid_id{};
      std::string client_bid_id{};
      BidRequestTransType bid_request_trans_type{};
      std::optional<std::string> list_name{};
      int64_t total_num_securities{};
      BidType bid_type{};
      std::optional<int64_t> num_tickets{};
      std::optional<std::string> currency{};
      std::optional<double> side_value1{};
      std::optional<double> side_value2{};
      std::vector<BidDescReqGrp> no_bid_descriptors{};
      std::vector<BidCompReqGrp> no_bid_components{};
      std::optional<LiquidityIndType> liquidity_ind_type{};
      std::optional<double> wt_average_liquidity{};
      std::optional<bool> exchange_for_physical{};
      std::optional<double> out_main_cntry_u_index{};
      std::optional<double> cross_percent{};
      std::optional<ProgRptReqs> prog_rpt_reqs{};
      std::optional<int64_t> prog_period_interval{};
      std::optional<IncTaxInd> inc_tax_ind{};
      std::optional<bool> forex_req{};
      std::optional<int64_t> num_bidders{};
      std::optional<std::string> trade_date{};
      TradeType trade_type{};
      BasisPxType basis_px_type{};
      std::optional<std::string> strike_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const BidRequest&) const = default;
   };
   struct BidResponse
   {
      std::optional<std::string> bid_id{};
      std::optional<std::string> client_bid_id{};
      std::vector<BidCompRspGrp> no_bid_components{};
      bool operator==(const BidResponse&) const = default;
   };
   struct ListStrikePrice
   {
      std::string list_id{};
      int64_t tot_no_strikes{};
      std::vector<InstrmtStrkPxGrp> no_strikes{};
      bool operator==(const ListStrikePrice&) const = default;
   };
}

template <>
struct glz::meta<glz::fix::fix42::Adjustment>
{
   using enum glz::fix::fix42::Adjustment;
   static constexpr auto value = glz::enumerate(Cancel, Error, Correction);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::AdvSide>
{
   using enum glz::fix::fix42::AdvSide;
   static constexpr auto value = glz::enumerate(Buy, Sell, Trade, Cross);
   static constexpr std::array<std::string_view, 4> fix_values{"B", "S", "T", "X"};
};
template <>
struct glz::meta<glz::fix::fix42::AdvTransType>
{
   using enum glz::fix::fix42::AdvTransType;
   static constexpr auto value = glz::enumerate(Cancel, New, Replace);
   static constexpr std::array<std::string_view, 3> fix_values{"C", "N", "R"};
};
template <>
struct glz::meta<glz::fix::fix42::AggregatedBook>
{
   using enum glz::fix::fix42::AggregatedBook;
   static constexpr auto value = glz::enumerate(BookEntriesShouldNotBeAggregated, BookEntriesToBeAggregated);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::AllocHandlInst>
{
   using enum glz::fix::fix42::AllocHandlInst;
   static constexpr auto value = glz::enumerate(Match, Forward, ForwardAndMatch);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::AllocLinkType>
{
   using enum glz::fix::fix42::AllocLinkType;
   static constexpr auto value = glz::enumerate(FXNetting, FXSwap);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::AllocRejCode>
{
   using enum glz::fix::fix42::AllocRejCode;
   static constexpr auto value = glz::enumerate(UnknownAccount, IncorrectQuantity, IncorrectAveragePrice, UnknownExecutingBrokerMnemonic, CommissionDifference, UnknownOrderID, UnknownListID, OtherSeeText);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix42::AllocStatus>
{
   using enum glz::fix::fix42::AllocStatus;
   static constexpr auto value = glz::enumerate(Accepted, BlockLevelReject, AccountLevelReject, Received);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::AllocTransType>
{
   using enum glz::fix::fix42::AllocTransType;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel, Preliminary, Calculated, CalculatedWithoutPreliminary);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::BasisPxType>
{
   using enum glz::fix::fix42::BasisPxType;
   static constexpr auto value = glz::enumerate(ClosingPriceAtMorningSession, ClosingPrice, CurrentPrice, SQ, VWAPThroughADay, VWAPThroughAMorningSession, VWAPThroughAnAfternoonSession, VWAPThroughADayExcept, VWAPThroughAMorningSessionExcept, VWAPThroughAnAfternoonSessionExcept, Strike, Open, Others);
   static constexpr std::array<std::string_view, 13> fix_values{"2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "Z"};
};
template <>
struct glz::meta<glz::fix::fix42::Benchmark>
{
   using enum glz::fix::fix42::Benchmark;
   static constexpr auto value = glz::enumerate(CURVE, FiveYR, OLD5, TenYR, OLD10, ThirtyYR, OLD30, ThreeMOLIBOR, SixMOLIBOR);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::BidDescriptorType>
{
   using enum glz::fix::fix42::BidDescriptorType;
   static constexpr auto value = glz::enumerate(Sector, Country, Index);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::BidRequestTransType>
{
   using enum glz::fix::fix42::BidRequestTransType;
   static constexpr auto value = glz::enumerate(Cancel, New);
   static constexpr std::array<std::string_view, 2> fix_values{"C", "N"};
};
template <>
struct glz::meta<glz::fix::fix42::BidType>
{
   using enum glz::fix::fix42::BidType;
   static constexpr auto value = glz::enumerate(NonDisclosed, Disclosed, NoBiddingProcess);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::BusinessRejectReason>
{
   using enum glz::fix::fix42::BusinessRejectReason;
   static constexpr auto value = glz::enumerate(Other, UnknownID, UnknownSecurity, UnsupportedMessageType, ApplicationNotAvailable, ConditionallyRequiredFieldMissing);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::CommType>
{
   using enum glz::fix::fix42::CommType;
   static constexpr auto value = glz::enumerate(PerUnit, Percent, Absolute);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::CorporateAction>
{
   using enum glz::fix::fix42::CorporateAction;
   static constexpr auto value = glz::enumerate(ExDividend, ExDistribution, ExRights, New, ExInterest);
   static constexpr std::array<std::string_view, 5> fix_values{"A", "B", "C", "D", "E"};
};
template <>
struct glz::meta<glz::fix::fix42::CoveredOrUncovered>
{
   using enum glz::fix::fix42::CoveredOrUncovered;
   static constexpr auto value = glz::enumerate(Covered, Uncovered);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::CustomerOrFirm>
{
   using enum glz::fix::fix42::CustomerOrFirm;
   static constexpr auto value = glz::enumerate(Customer, Firm);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::CxlRejReason>
{
   using enum glz::fix::fix42::CxlRejReason;
   static constexpr auto value = glz::enumerate(TooLateToCancel, UnknownOrder, BrokerCredit, OrderAlreadyInPendingStatus);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::CxlRejResponseTo>
{
   using enum glz::fix::fix42::CxlRejResponseTo;
   static constexpr auto value = glz::enumerate(OrderCancelRequest, OrderCancel);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::DKReason>
{
   using enum glz::fix::fix42::DKReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, WrongSide, QuantityExceedsOrder, NoMatchingOrder, PriceExceedsLimit, Other);
   static constexpr std::array<std::string_view, 6> fix_values{"A", "B", "C", "D", "E", "Z"};
};
template <>
struct glz::meta<glz::fix::fix42::DeleteReason>
{
   using enum glz::fix::fix42::DeleteReason;
   static constexpr auto value = glz::enumerate(Cancellation, Error);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::DiscretionInst>
{
   using enum glz::fix::fix42::DiscretionInst;
   static constexpr auto value = glz::enumerate(RelatedToDisplayedPrice, RelatedToMarketPrice, RelatedToPrimaryPrice, RelatedToLocalPrimaryPrice, RelatedToMidpointPrice, RelatedToLastTradePrice);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::DueToRelated>
{
   using enum glz::fix::fix42::DueToRelated;
   static constexpr auto value = glz::enumerate(NotRelatedToSecurityHalt, RelatedToSecurityHalt);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::EmailType>
{
   using enum glz::fix::fix42::EmailType;
   static constexpr auto value = glz::enumerate(New, Reply, AdminReply);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::EncryptMethod>
{
   using enum glz::fix::fix42::EncryptMethod;
   static constexpr auto value = glz::enumerate(None, PKCS, DES, PKCSDES, PGPDES, PGPDESMD5, PEM);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix42::ExchangeForPhysical>
{
   using enum glz::fix::fix42::ExchangeForPhysical;
   static constexpr auto value = glz::enumerate(False, True);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::ExecInst>
{
   using enum glz::fix::fix42::ExecInst;
   static constexpr auto value = glz::enumerate(StayOnOfferSide, NotHeld, Work, GoAlong, OverTheDay, Held, ParticipateDoNotInitiate, StrictScale, TryToScale, StayOnBidSide, NoCross, OKToCross, CallFirst, PercentOfVolume, DoNotIncrease, DoNotReduce, AllOrNone, InstitutionsOnly, LastPeg, MidPricePeg, NonNegotiable, OpeningPeg, MarketPeg, PrimaryPeg, Suspend, FixedPegToLocalBestBidOrOfferAtTimeOfOrder, CustomerDisplayInstruction, Netting, PegToVWAP);
   static constexpr std::array<std::string_view, 29> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "I", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "W"};
};
template <>
struct glz::meta<glz::fix::fix42::ExecRestatementReason>
{
   using enum glz::fix::fix42::ExecRestatementReason;
   static constexpr auto value = glz::enumerate(GTCorporateAction, GTRenewal, VerbalChange, RepricingOfOrder, BrokerOption, PartialDeclineOfOrderQty);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::ExecTransType>
{
   using enum glz::fix::fix42::ExecTransType;
   static constexpr auto value = glz::enumerate(New, Cancel, Correct, Status);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::ExecType>
{
   using enum glz::fix::fix42::ExecType;
   static constexpr auto value = glz::enumerate(New, PartialFill, Fill, DoneForDay, Canceled, Replaced, PendingCancel, Stopped, Rejected, Suspended, PendingNew, Calculated, Expired, Restated, PendingReplace);
   static constexpr std::array<std::string_view, 15> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E"};
};
template <>
struct glz::meta<glz::fix::fix42::FinancialStatus>
{
   using enum glz::fix::fix42::FinancialStatus;
   static constexpr auto value = glz::enumerate(Bankrupt);
   static constexpr std::array<std::string_view, 1> fix_values{"1"};
};
template <>
struct glz::meta<glz::fix::fix42::ForexReq>
{
   using enum glz::fix::fix42::ForexReq;
   static constexpr auto value = glz::enumerate(DoNotExecuteForexAfterSecurityTrade, ExecuteForexAfterSecurityTrade);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::GTBookingInst>
{
   using enum glz::fix::fix42::GTBookingInst;
   static constexpr auto value = glz::enumerate(BookOutAllTradesOnDayOfExecution, AccumulateUntilFilledOrExpired, AccumulateUntilVerballlyNotifiedOtherwise);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::GapFillFlag>
{
   using enum glz::fix::fix42::GapFillFlag;
   static constexpr auto value = glz::enumerate(SequenceReset, GapFillMessage);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::HaltReason>
{
   using enum glz::fix::fix42::HaltReason;
   static constexpr auto value = glz::enumerate(NewsDissemination, OrderInflux, OrderImbalance, AdditionalInformation, NewsPending, EquipmentChangeover);
   static constexpr std::array<std::string_view, 6> fix_values{"D", "E", "I", "M", "P", "X"};
};
template <>
struct glz::meta<glz::fix::fix42::HandlInst>
{
   using enum glz::fix::fix42::HandlInst;
   static constexpr auto value = glz::enumerate(AutomatedExecutionNoIntervention, AutomatedExecutionInterventionOK, ManualOrder);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::IDSource>
{
   using enum glz::fix::fix42::IDSource;
   static constexpr auto value = glz::enumerate(CUSIP, SEDOL, QUIK, ISINNumber, RICCode, ISOCurrencyCode, ISOCountryCode, ExchangeSymbol, ConsolidatedTapeAssociation);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::IOINaturalFlag>
{
   using enum glz::fix::fix42::IOINaturalFlag;
   static constexpr auto value = glz::enumerate(NotNatural, Natural);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::IOIQltyInd>
{
   using enum glz::fix::fix42::IOIQltyInd;
   static constexpr auto value = glz::enumerate(High, Low, Medium);
   static constexpr std::array<std::string_view, 3> fix_values{"H", "L", "M"};
};
template <>
struct glz::meta<glz::fix::fix42::IOIQualifier>
{
   using enum glz::fix::fix42::IOIQualifier;
   static constexpr auto value = glz::enumerate(AllOrNone, AtTheClose, InTouchWith, Limit, MoreBehind, AtTheOpen, TakingAPosition, AtTheMarket, ReadyToTrade, PortfolioShown, ThroughTheDay, Versus, Indication, CrossingOpportunity, AtTheMidpoint, PreOpen);
   static constexpr std::array<std::string_view, 16> fix_values{"A", "C", "I", "L", "M", "O", "P", "Q", "R", "S", "T", "V", "W", "X", "Y", "Z"};
};
template <>
struct glz::meta<glz::fix::fix42::IOIShares>
{
   using enum glz::fix::fix42::IOIShares;
   static constexpr auto value = glz::enumerate(Large, Medium, Small);
   static constexpr std::array<std::string_view, 3> fix_values{"L", "M", "S"};
};
template <>
struct glz::meta<glz::fix::fix42::IOITransType>
{
   using enum glz::fix::fix42::IOITransType;
   static constexpr auto value = glz::enumerate(Cancel, New, Replace);
   static constexpr std::array<std::string_view, 3> fix_values{"C", "N", "R"};
};
template <>
struct glz::meta<glz::fix::fix42::InViewOfCommon>
{
   using enum glz::fix::fix42::InViewOfCommon;
   static constexpr auto value = glz::enumerate(HaltWasNotRelatedToAHaltOfTheCommonStock, HaltWasDueToCommonStockBeingHalted);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::IncTaxInd>
{
   using enum glz::fix::fix42::IncTaxInd;
   static constexpr auto value = glz::enumerate(Net, Gross);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::LastCapacity>
{
   using enum glz::fix::fix42::LastCapacity;
   static constexpr auto value = glz::enumerate(Agent, CrossAsAgent, CrossAsPrincipal, Principal);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix42::LiquidityIndType>
{
   using enum glz::fix::fix42::LiquidityIndType;
   static constexpr auto value = glz::enumerate(FiveDayMovingAverage, TwentyDayMovingAverage, NormalMarketSize, Other);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix42::ListExecInstType>
{
   using enum glz::fix::fix42::ListExecInstType;
   static constexpr auto value = glz::enumerate(Immediate, WaitForInstruction);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::ListOrderStatus>
{
   using enum glz::fix::fix42::ListOrderStatus;
   static constexpr auto value = glz::enumerate(InBiddingProcess, ReceivedForExecution, Executing, Canceling, Alert, AllDone, Reject);
   static constexpr std::array<std::string_view, 7> fix_values{"1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix42::ListStatusType>
{
   using enum glz::fix::fix42::ListStatusType;
   static constexpr auto value = glz::enumerate(Ack, Response, Timed, ExecStarted, AllDone, Alert);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix42::LocateReqd>
{
   using enum glz::fix::fix42::LocateReqd;
   static constexpr auto value = glz::enumerate(No, Yes);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::MDEntryType>
{
   using enum glz::fix::fix42::MDEntryType;
   static constexpr auto value = glz::enumerate(Bid, Offer, Trade, IndexValue, OpeningPrice, ClosingPrice, SettlementPrice, TradingSessionHighPrice, TradingSessionLowPrice, TradingSessionVWAPPrice);
   static constexpr std::array<std::string_view, 10> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::MDReqRejReason>
{
   using enum glz::fix::fix42::MDReqRejReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, DuplicateMDReqID, InsufficientBandwidth, InsufficientPermissions, UnsupportedSubscriptionRequestType, UnsupportedMarketDepth, UnsupportedMDUpdateType, UnsupportedAggregatedBook, UnsupportedMDEntryType);
   static constexpr std::array<std::string_view, 9> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix42::MDUpdateAction>
{
   using enum glz::fix::fix42::MDUpdateAction;
   static constexpr auto value = glz::enumerate(New, Change, Delete);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::MDUpdateType>
{
   using enum glz::fix::fix42::MDUpdateType;
   static constexpr auto value = glz::enumerate(FullRefresh, IncrementalRefresh);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::MessageEncoding>
{
   using enum glz::fix::fix42::MessageEncoding;
   static constexpr auto value = glz::enumerate(EUCJP, ISO2022JP, ShiftJIS, UTF8);
   static constexpr std::array<std::string_view, 4> fix_values{"EUC-JP", "ISO-2022-JP", "Shift_JIS", "UTF-8"};
};
template <>
struct glz::meta<glz::fix::fix42::MiscFeeType>
{
   using enum glz::fix::fix42::MiscFeeType;
   static constexpr auto value = glz::enumerate(Regulatory, Tax, LocalCommission, ExchangeFees, Stamp, Levy, Other, Markup, ConsumptionTax);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::MsgDirection>
{
   using enum glz::fix::fix42::MsgDirection;
   static constexpr auto value = glz::enumerate(Receive, Send);
   static constexpr std::array<std::string_view, 2> fix_values{"R", "S"};
};
template <>
struct glz::meta<glz::fix::fix42::MsgType>
{
   using enum glz::fix::fix42::MsgType;
   static constexpr auto value = glz::enumerate(Heartbeat, TestRequest, ResendRequest, Reject, SequenceReset, Logout, IOI, Advertisement, ExecutionReport, OrderCancelReject, Logon, News, Email, NewOrderSingle, NewOrderList, OrderCancelRequest, OrderCancelReplaceRequest, OrderStatusRequest, Allocation, ListCancelRequest, ListExecute, ListStatusRequest, ListStatus, AllocationAck, DontKnowTrade, QuoteRequest, Quote, SettlementInstructions, MarketDataRequest, MarketDataSnapshotFullRefresh, MarketDataIncrementalRefresh, MarketDataRequestReject, QuoteCancel, QuoteStatusRequest, QuoteAcknowledgement, SecurityDefinitionRequest, SecurityDefinition, SecurityStatusRequest, SecurityStatus, TradingSessionStatusRequest, TradingSessionStatus, MassQuote, BusinessMessageReject, BidRequest, BidResponse, ListStrikePrice);
   static constexpr std::array<std::string_view, 46> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
};
template <>
struct glz::meta<glz::fix::fix42::MultiLegReportingType>
{
   using enum glz::fix::fix42::MultiLegReportingType;
   static constexpr auto value = glz::enumerate(SingleSecurity, IndividualLegOfAMultiLegSecurity, MultiLegSecurity);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::NetGrossInd>
{
   using enum glz::fix::fix42::NetGrossInd;
   static constexpr auto value = glz::enumerate(Net, Gross);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::NotifyBrokerOfCredit>
{
   using enum glz::fix::fix42::NotifyBrokerOfCredit;
   static constexpr auto value = glz::enumerate(DetailsShouldNotBeCommunicated, DetailsShouldBeCommunicated);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::OpenClose>
{
   using enum glz::fix::fix42::OpenClose;
   static constexpr auto value = glz::enumerate(Close, Open);
   static constexpr std::array<std::string_view, 2> fix_values{"C", "O"};
};
template <>
struct glz::meta<glz::fix::fix42::OpenCloseSettleFlag>
{
   using enum glz::fix::fix42::OpenCloseSettleFlag;
   static constexpr auto value = glz::enumerate(DailyOpen, SessionOpen, DeliverySettlementEntry);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::OrdRejReason>
{
   using enum glz::fix::fix42::OrdRejReason;
   static constexpr auto value = glz::enumerate(BrokerCredit, UnknownSymbol, ExchangeClosed, OrderExceedsLimit, TooLateToEnter, UnknownOrder, DuplicateOrder, DuplicateOfAVerballyCommunicatedOrder, StaleOrder);
   static constexpr std::array<std::string_view, 9> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix42::OrdStatus>
{
   using enum glz::fix::fix42::OrdStatus;
   static constexpr auto value = glz::enumerate(New, PartiallyFilled, Filled, DoneForDay, Canceled, Replaced, PendingCancel, Stopped, Rejected, Suspended, PendingNew, Calculated, Expired, AcceptedForBidding, PendingReplace);
   static constexpr std::array<std::string_view, 15> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E"};
};
template <>
struct glz::meta<glz::fix::fix42::OrdType>
{
   using enum glz::fix::fix42::OrdType;
   static constexpr auto value = glz::enumerate(Market, Limit, Stop, StopLimit, MarketOnClose, WithOrWithout, LimitOrBetter, LimitWithOrWithout, OnBasis, OnClose, LimitOnClose, ForexMarket, PreviouslyQuoted, PreviouslyIndicated, ForexLimit, ForexSwap, ForexPreviouslyQuoted, Funari, Pegged);
   static constexpr std::array<std::string_view, 19> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "P"};
};
template <>
struct glz::meta<glz::fix::fix42::PossDupFlag>
{
   using enum glz::fix::fix42::PossDupFlag;
   static constexpr auto value = glz::enumerate(OriginalTransmission, PossibleDuplicate);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::PossResend>
{
   using enum glz::fix::fix42::PossResend;
   static constexpr auto value = glz::enumerate(OriginalTransmission, PossibleResend);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::PriceType>
{
   using enum glz::fix::fix42::PriceType;
   static constexpr auto value = glz::enumerate(Percentage, PerUnit, FixedAmount);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::ProcessCode>
{
   using enum glz::fix::fix42::ProcessCode;
   static constexpr auto value = glz::enumerate(Regular, SoftDollar, StepIn, StepOut, SoftDollarStepIn, SoftDollarStepOut, PlanSponsor);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix42::ProgRptReqs>
{
   using enum glz::fix::fix42::ProgRptReqs;
   static constexpr auto value = glz::enumerate(BuySideRequests, SellSideSends, RealTimeExecutionReports);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::PutOrCall>
{
   using enum glz::fix::fix42::PutOrCall;
   static constexpr auto value = glz::enumerate(Put, Call);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteAckStatus>
{
   using enum glz::fix::fix42::QuoteAckStatus;
   static constexpr auto value = glz::enumerate(Accepted, CancelForSymbol, CanceledForSecurityType, CanceledForUnderlying, CanceledAll, Rejected);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteCancelType>
{
   using enum glz::fix::fix42::QuoteCancelType;
   static constexpr auto value = glz::enumerate(CancelForOneOrMoreSecurities, CancelForSecurityType, CancelForUnderlyingSecurity, CancelAllQuotes);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteCondition>
{
   using enum glz::fix::fix42::QuoteCondition;
   static constexpr auto value = glz::enumerate(Open, Closed, ExchangeBest, ConsolidatedBest, Locked, Crossed, Depth, FastTrading, NonFirm);
   static constexpr std::array<std::string_view, 9> fix_values{"A", "B", "C", "D", "E", "F", "G", "H", "I"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteEntryRejectReason>
{
   using enum glz::fix::fix42::QuoteEntryRejectReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, Exchange, QuoteExceedsLimit, TooLateToEnter, UnknownQuote, DuplicateQuote, InvalidBidAskSpread, InvalidPrice, NotAuthorizedToQuoteSecurity);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteRejectReason>
{
   using enum glz::fix::fix42::QuoteRejectReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, Exchange, QuoteRequestExceedsLimit, TooLateToEnter, UnknownQuote, DuplicateQuote, InvalidBid, InvalidPrice, NotAuthorizedToQuoteSecurity);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteRequestType>
{
   using enum glz::fix::fix42::QuoteRequestType;
   static constexpr auto value = glz::enumerate(Manual, Automatic);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::QuoteResponseLevel>
{
   using enum glz::fix::fix42::QuoteResponseLevel;
   static constexpr auto value = glz::enumerate(NoAcknowledgement, AcknowledgeOnlyNegativeOrErroneousQuotes, AcknowledgeEachQuoteMessage);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::ReportToExch>
{
   using enum glz::fix::fix42::ReportToExch;
   static constexpr auto value = glz::enumerate(SenderReports, ReceiverReports);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::ResetSeqNumFlag>
{
   using enum glz::fix::fix42::ResetSeqNumFlag;
   static constexpr auto value = glz::enumerate(No, Yes);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::RoutingType>
{
   using enum glz::fix::fix42::RoutingType;
   static constexpr auto value = glz::enumerate(TargetFirm, TargetList, BlockFirm, BlockList);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix42::Rule80A>
{
   using enum glz::fix::fix42::Rule80A;
   static constexpr auto value = glz::enumerate(AgencySingleOrder, ShortExemptTransactionAType, ProprietaryNonAlgo, ProgramOrderMember, ShortExemptTransactionForPrincipal, ShortExemptTransactionWType, ShortExemptTransactionIType, IndividualInvestor, ProprietaryAlgo, AgencyAlgo, ShortExemptTransactionMemberAffliated, ProgramOrderOtherMember, AgentForOtherMember, ProprietaryTransactionAffiliated, Principal, TransactionNonMember, SpecialistTrades, TransactionUnaffiliatedMember, AgencyIndexArb, AllOtherOrdersAsAgentForOtherMember, ShortExemptTransactionMemberNotAffliated, AgencyNonAlgo, ShortExemptTransactionNonMember);
   static constexpr std::array<std::string_view, 23> fix_values{"A", "B", "C", "D", "E", "F", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "W", "X", "Y", "Z"};
};
template <>
struct glz::meta<glz::fix::fix42::SecurityRequestType>
{
   using enum glz::fix::fix42::SecurityRequestType;
   static constexpr auto value = glz::enumerate(RequestSecurityIdentityAndSpecifications, RequestSecurityIdentityForSpecifications, RequestListSecurityTypes, RequestListSecurities);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::SecurityResponseType>
{
   using enum glz::fix::fix42::SecurityResponseType;
   static constexpr auto value = glz::enumerate(AcceptAsIs, AcceptWithRevisions, ListOfSecurityTypesReturnedPerRequest, ListOfSecuritiesReturnedPerRequest, RejectSecurityProposal, CannotMatchSelectionCriteria);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix42::SecurityTradingStatus>
{
   using enum glz::fix::fix42::SecurityTradingStatus;
   static constexpr auto value = glz::enumerate(OpeningDelay, MarketOnCloseImbalanceSell, NoMarketImbalance, NoMarketOnCloseImbalance, ITSPreOpening, NewPriceIndication, TradeDisseminationTime, ReadyToTrade, NotAvailableForTrading, NotTradedOnThisMarket, TradingHalt, UnknownOrInvalid, Resume, NoOpen, PriceIndication, TradingRangeIndication, MarketImbalanceBuy, MarketImbalanceSell, MarketOnCloseImbalanceBuy);
   static constexpr std::array<std::string_view, 19> fix_values{"1", "10", "12", "13", "14", "15", "16", "17", "18", "19", "2", "20", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::SecurityType>
{
   using enum glz::fix::fix42::SecurityType;
   static constexpr auto value = glz::enumerate(Wildcard, BankersAcceptance, ConvertibleBond, CertificateOfDeposit, CollateralizedMortgageObligation, CorporateBond, CommercialPaper, CorporatePrivatePlacement, CommonStock, FederalHousingAuthority, FederalHomeLoan, FederalNationalMortgageAssociation, ForeignExchangeContract, Future, GovernmentNationalMortgageAssociation, TreasuriesAgencyDebenture, IOETTEMortgage, MutualFund, MortgageInterestOnly, MortgagePrincipalOnly, MortgagePrivatePlacement, MiscellaneousPassThrough, MunicipalBond, NoSecurityType, Option, PreferredStock, RepurchaseAgreement, ReverseRepurchaseAgreement, StudentLoanMarketingAssociation, TimeDeposit, USTreasuryBillOld, Warrant, CatsTigersAndLions);
   static constexpr std::array<std::string_view, 33> fix_values{"?", "BA", "CB", "CD", "CMO", "CORP", "CP", "CPP", "CS", "FHA", "FHL", "FN", "FOR", "FUT", "GN", "GOVT", "IET", "MF", "MIO", "MPO", "MPP", "MPT", "MUNI", "NONE", "OPT", "PS", "RP", "RVRP", "SL", "TD", "USTB", "WAR", "ZOO"};
};
template <>
struct glz::meta<glz::fix::fix42::SessionRejectReason>
{
   using enum glz::fix::fix42::SessionRejectReason;
   static constexpr auto value = glz::enumerate(InvalidTagNumber, RequiredTagMissing, SendingTimeAccuracyProblem, InvalidMsgType, TagNotDefinedForThisMessageType, UndefinedTag, TagSpecifiedWithoutAValue, ValueIsIncorrect, IncorrectDataFormatForValue, DecryptionProblem, SignatureProblem, CompIDProblem);
   static constexpr std::array<std::string_view, 12> fix_values{"0", "1", "10", "11", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlCurrFxRateCalc>
{
   using enum glz::fix::fix42::SettlCurrFxRateCalc;
   static constexpr auto value = glz::enumerate(Multiply, Divide);
   static constexpr std::array<std::string_view, 2> fix_values{"M", "D"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlDeliveryType>
{
   using enum glz::fix::fix42::SettlDeliveryType;
   static constexpr auto value = glz::enumerate(Versus, Free);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlInstMode>
{
   using enum glz::fix::fix42::SettlInstMode;
   static constexpr auto value = glz::enumerate(Default, StandingInstructionsProvided, SpecificAllocationAccountOverriding, SpecificAllocationAccountStanding);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlInstSource>
{
   using enum glz::fix::fix42::SettlInstSource;
   static constexpr auto value = glz::enumerate(BrokerCredit, Institution);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlInstTransType>
{
   using enum glz::fix::fix42::SettlInstTransType;
   static constexpr auto value = glz::enumerate(Cancel, New, Replace);
   static constexpr std::array<std::string_view, 3> fix_values{"C", "N", "R"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlLocation>
{
   using enum glz::fix::fix42::SettlLocation;
   static constexpr auto value = glz::enumerate(CEDEL, DepositoryTrustCompany, EuroClear, FederalBookEntry, LocalMarketSettleLocation, Physical, ParticipantTrustCompany);
   static constexpr std::array<std::string_view, 7> fix_values{"CED", "DTC", "EUR", "FED", "ISO Country Code", "PNY", "PTC"};
};
template <>
struct glz::meta<glz::fix::fix42::SettlmntTyp>
{
   using enum glz::fix::fix42::SettlmntTyp;
   static constexpr auto value = glz::enumerate(Regular, Cash, NextDay, TPlus2, TPlus3, TPlus4, Future, WhenAndIfIssued, SellersOption, TPlus5);
   static constexpr std::array<std::string_view, 10> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::Side>
{
   using enum glz::fix::fix42::Side;
   static constexpr auto value = glz::enumerate(Buy, Sell, BuyMinus, SellPlus, SellShort, SellShortExempt, Undisclosed, Cross, CrossShort);
   static constexpr std::array<std::string_view, 9> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix42::SideValueInd>
{
   using enum glz::fix::fix42::SideValueInd;
   static constexpr auto value = glz::enumerate(SideValue1, SideValue2);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::SolicitedFlag>
{
   using enum glz::fix::fix42::SolicitedFlag;
   static constexpr auto value = glz::enumerate(WasNotSolicited, WasSolicited);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::StandInstDbType>
{
   using enum glz::fix::fix42::StandInstDbType;
   static constexpr auto value = glz::enumerate(Other, DTCSID, ThomsonALERT, AGlobalCustodian);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::SubscriptionRequestType>
{
   using enum glz::fix::fix42::SubscriptionRequestType;
   static constexpr auto value = glz::enumerate(Snapshot, SnapshotAndUpdates, DisablePreviousSnapshot);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix42::TickDirection>
{
   using enum glz::fix::fix42::TickDirection;
   static constexpr auto value = glz::enumerate(PlusTick, ZeroPlusTick, MinusTick, ZeroMinusTick);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::TimeInForce>
{
   using enum glz::fix::fix42::TimeInForce;
   static constexpr auto value = glz::enumerate(Day, GoodTillCancel, AtTheOpening, ImmediateOrCancel, FillOrKill, GoodTillCrossing, GoodTillDate);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix42::TradSesMethod>
{
   using enum glz::fix::fix42::TradSesMethod;
   static constexpr auto value = glz::enumerate(Electronic, OpenOutcry, TwoParty);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::TradSesMode>
{
   using enum glz::fix::fix42::TradSesMode;
   static constexpr auto value = glz::enumerate(Testing, Simulated, Production);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix42::TradSesStatus>
{
   using enum glz::fix::fix42::TradSesStatus;
   static constexpr auto value = glz::enumerate(Halted, Open, Closed, PreOpen, PreClose);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix42::TradeCondition>
{
   using enum glz::fix::fix42::TradeCondition;
   static constexpr auto value = glz::enumerate(Cash, AveragePriceTrade, CashTrade, NextDay, Opening, IntradayTradeDetail, Rule127Trade, Rule155Trade, SoldLast, NextDayTrade, Opened, Seller, Sold, StoppedStock);
   static constexpr std::array<std::string_view, 14> fix_values{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N"};
};
template <>
struct glz::meta<glz::fix::fix42::TradeType>
{
   using enum glz::fix::fix42::TradeType;
   static constexpr auto value = glz::enumerate(Agency, VWAPGuarantee, GuaranteedClose, RiskTrade);
   static constexpr std::array<std::string_view, 4> fix_values{"A", "G", "J", "R"};
};
template <>
struct glz::meta<glz::fix::fix42::UnsolicitedIndicator>
{
   using enum glz::fix::fix42::UnsolicitedIndicator;
   static constexpr auto value = glz::enumerate(MessageIsBeingSentAsAResultOfAPriorRequest, MessageIsBeingSentUnsolicited);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "Y"};
};
template <>
struct glz::meta<glz::fix::fix42::Urgency>
{
   using enum glz::fix::fix42::Urgency;
   static constexpr auto value = glz::enumerate(Normal, Flash, Background);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};

template <>
struct glz::meta<glz::fix::fix42::StandardHeader>
{
   using T = glz::fix::fix42::StandardHeader;
   static constexpr auto value = glz::object("8", &T::begin_string, "9", &T::body_length, "35", &T::msg_type, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "370", &T::on_behalf_of_sending_time);
};
template <>
struct glz::meta<glz::fix::fix42::StandardTrailer>
{
   using T = glz::fix::fix42::StandardTrailer;
   static constexpr auto value = glz::object("93", &T::signature_length, "89", &T::signature, "10", &T::check_sum);
};
template <>
struct glz::meta<glz::fix::fix42::Heartbeat>
{
   using T = glz::fix::fix42::Heartbeat;
   static constexpr std::string_view fix_msg_type = "0";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fix42::TestRequest>
{
   using T = glz::fix::fix42::TestRequest;
   static constexpr std::string_view fix_msg_type = "1";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fix42::ResendRequest>
{
   using T = glz::fix::fix42::ResendRequest;
   static constexpr std::string_view fix_msg_type = "2";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("7", &T::begin_seq_no, "16", &T::end_seq_no);
};
template <>
struct glz::meta<glz::fix::fix42::Reject>
{
   using T = glz::fix::fix42::Reject;
   static constexpr std::string_view fix_msg_type = "3";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "371", &T::ref_tag_id, "372", &T::ref_msg_type, "373", &T::session_reject_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::SequenceReset>
{
   using T = glz::fix::fix42::SequenceReset;
   static constexpr std::string_view fix_msg_type = "4";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("123", &T::gap_fill_flag, "36", &T::new_seq_no);
};
template <>
struct glz::meta<glz::fix::fix42::Logout>
{
   using T = glz::fix::fix42::Logout;
   static constexpr std::string_view fix_msg_type = "5";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::IOIQualGrp>
{
   using T = glz::fix::fix42::IOIQualGrp;
   static constexpr auto value = glz::object("104", &T::ioi_qualifier);
};
template <>
struct glz::meta<glz::fix::fix42::RoutingGrp>
{
   using T = glz::fix::fix42::RoutingGrp;
   static constexpr auto value = glz::object("216", &T::routing_type, "217", &T::routing_id);
};
template <>
struct glz::meta<glz::fix::fix42::IOI>
{
   using T = glz::fix::fix42::IOI;
   static constexpr std::string_view fix_msg_type = "6";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("23", &T::ioiid, "28", &T::ioi_trans_type, "26", &T::ioi_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "27", &T::ioi_shares, "44", &T::price, "15", &T::currency, "62", &T::valid_until_time, "25", &T::ioi_qlty_ind, "130", &T::ioi_natural_flag, "199", &T::no_ioi_qualifiers, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "60", &T::transact_time, "149", &T::url_link, "215", &T::no_routing_ids, "218", &T::spread_to_benchmark, "219", &T::benchmark);
};
template <>
struct glz::meta<glz::fix::fix42::Advertisement>
{
   using T = glz::fix::fix42::Advertisement;
   static constexpr std::string_view fix_msg_type = "7";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("2", &T::adv_id, "5", &T::adv_trans_type, "3", &T::adv_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "4", &T::adv_side, "53", &T::shares, "44", &T::price, "15", &T::currency, "75", &T::trade_date, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "149", &T::url_link, "30", &T::last_mkt, "336", &T::trading_session_id);
};
template <>
struct glz::meta<glz::fix::fix42::ContraGrp>
{
   using T = glz::fix::fix42::ContraGrp;
   static constexpr auto value = glz::object("375", &T::contra_broker, "337", &T::contra_trader, "437", &T::contra_trade_qty, "438", &T::contra_trade_time);
};
template <>
struct glz::meta<glz::fix::fix42::ExecutionReport>
{
   using T = glz::fix::fix42::ExecutionReport;
   static constexpr std::string_view fix_msg_type = "8";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("37", &T::order_id, "198", &T::secondary_order_id, "11", &T::cl_ord_id, "41", &T::orig_cl_ord_id, "109", &T::client_id, "76", &T::exec_broker, "382", &T::no_contra_brokers, "66", &T::list_id, "17", &T::exec_id, "20", &T::exec_trans_type, "19", &T::exec_ref_id, "150", &T::exec_type, "39", &T::ord_status, "103", &T::ord_rej_reason, "378", &T::exec_restatement_reason, "1", &T::account, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "40", &T::ord_type, "44", &T::price, "99", &T::stop_px, "211", &T::peg_difference, "388", &T::discretion_inst, "389", &T::discretion_offset, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "18", &T::exec_inst, "47", &T::rule80_a, "32", &T::last_shares, "31", &T::last_px, "194", &T::last_spot_rate, "195", &T::last_forward_points, "30", &T::last_mkt, "336", &T::trading_session_id, "29", &T::last_capacity, "151", &T::leaves_qty, "14", &T::cum_qty, "6", &T::avg_px, "424", &T::day_order_qty, "425", &T::day_cum_qty, "426", &T::day_avg_px, "427", &T::gt_booking_inst, "75", &T::trade_date, "60", &T::transact_time, "113", &T::report_to_exch, "12", &T::commission, "13", &T::comm_type, "381", &T::gross_trade_amt, "119", &T::settl_curr_amt, "120", &T::settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "21", &T::handl_inst, "110", &T::min_qty, "111", &T::max_floor, "77", &T::open_close, "210", &T::max_show, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::fut_sett_date2, "192", &T::order_qty2, "439", &T::clearing_firm, "440", &T::clearing_account, "442", &T::multi_leg_reporting_type);
};
template <>
struct glz::meta<glz::fix::fix42::OrderCancelReject>
{
   using T = glz::fix::fix42::OrderCancelReject;
   static constexpr std::string_view fix_msg_type = "9";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("37", &T::order_id, "198", &T::secondary_order_id, "11", &T::cl_ord_id, "41", &T::orig_cl_ord_id, "39", &T::ord_status, "109", &T::client_id, "76", &T::exec_broker, "66", &T::list_id, "1", &T::account, "60", &T::transact_time, "434", &T::cxl_rej_response_to, "102", &T::cxl_rej_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::MsgTypeGrp>
{
   using T = glz::fix::fix42::MsgTypeGrp;
   static constexpr auto value = glz::object("372", &T::ref_msg_type, "385", &T::msg_direction);
};
template <>
struct glz::meta<glz::fix::fix42::Logon>
{
   using T = glz::fix::fix42::Logon;
   static constexpr std::string_view fix_msg_type = "A";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("98", &T::encrypt_method, "108", &T::heart_bt_int, "95", &T::raw_data_length, "96", &T::raw_data, "141", &T::reset_seq_num_flag, "383", &T::max_message_size, "384", &T::no_msg_types);
};
template <>
struct glz::meta<glz::fix::fix42::InstrmtGrp>
{
   using T = glz::fix::fix42::InstrmtGrp;
   static constexpr auto value = glz::object("46", &T::relatd_sym, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc);
};
template <>
struct glz::meta<glz::fix::fix42::LinesOfTextGrp>
{
   using T = glz::fix::fix42::LinesOfTextGrp;
   static constexpr auto value = glz::object("58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::News>
{
   using T = glz::fix::fix42::News;
   static constexpr std::string_view fix_msg_type = "B";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("42", &T::orig_time, "61", &T::urgency, "148", &T::headline, "358", &T::encoded_headline_len, "359", &T::encoded_headline, "215", &T::no_routing_ids, "146", &T::no_related_sym, "33", &T::lines_of_text, "149", &T::url_link, "95", &T::raw_data_length, "96", &T::raw_data);
};
template <>
struct glz::meta<glz::fix::fix42::Email>
{
   using T = glz::fix::fix42::Email;
   static constexpr std::string_view fix_msg_type = "C";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("164", &T::email_thread_id, "94", &T::email_type, "42", &T::orig_time, "147", &T::subject, "356", &T::encoded_subject_len, "357", &T::encoded_subject, "215", &T::no_routing_ids, "146", &T::no_related_sym, "37", &T::order_id, "11", &T::cl_ord_id, "33", &T::lines_of_text, "95", &T::raw_data_length, "96", &T::raw_data);
};
template <>
struct glz::meta<glz::fix::fix42::PreAllocGrp>
{
   using T = glz::fix::fix42::PreAllocGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "80", &T::alloc_shares);
};
template <>
struct glz::meta<glz::fix::fix42::TrdgSesGrp>
{
   using T = glz::fix::fix42::TrdgSesGrp;
   static constexpr auto value = glz::object("336", &T::trading_session_id);
};
template <>
struct glz::meta<glz::fix::fix42::NewOrderSingle>
{
   using T = glz::fix::fix42::NewOrderSingle;
   static constexpr std::string_view fix_msg_type = "D";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "109", &T::client_id, "76", &T::exec_broker, "1", &T::account, "78", &T::no_allocs, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "140", &T::prev_close_px, "54", &T::side, "114", &T::locate_reqd, "60", &T::transact_time, "38", &T::order_qty, "152", &T::cash_order_qty, "40", &T::ord_type, "44", &T::price, "99", &T::stop_px, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "47", &T::rule80_a, "121", &T::forex_req, "120", &T::settl_currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::fut_sett_date2, "192", &T::order_qty2, "77", &T::open_close, "203", &T::covered_or_uncovered, "204", &T::customer_or_firm, "210", &T::max_show, "211", &T::peg_difference, "388", &T::discretion_inst, "389", &T::discretion_offset, "439", &T::clearing_firm, "440", &T::clearing_account);
};
template <>
struct glz::meta<glz::fix::fix42::ListOrdGrp>
{
   using T = glz::fix::fix42::ListOrdGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "67", &T::list_seq_no, "160", &T::settl_inst_mode, "109", &T::client_id, "76", &T::exec_broker, "1", &T::account, "78", &T::no_allocs, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "140", &T::prev_close_px, "54", &T::side, "401", &T::side_value_ind, "114", &T::locate_reqd, "60", &T::transact_time, "38", &T::order_qty, "152", &T::cash_order_qty, "40", &T::ord_type, "44", &T::price, "99", &T::stop_px, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "47", &T::rule80_a, "121", &T::forex_req, "120", &T::settl_currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::fut_sett_date2, "192", &T::order_qty2, "77", &T::open_close, "203", &T::covered_or_uncovered, "204", &T::customer_or_firm, "210", &T::max_show, "211", &T::peg_difference, "388", &T::discretion_inst, "389", &T::discretion_offset, "439", &T::clearing_firm, "440", &T::clearing_account);
};
template <>
struct glz::meta<glz::fix::fix42::NewOrderList>
{
   using T = glz::fix::fix42::NewOrderList;
   static constexpr std::string_view fix_msg_type = "E";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "390", &T::bid_id, "391", &T::client_bid_id, "414", &T::prog_rpt_reqs, "394", &T::bid_type, "415", &T::prog_period_interval, "433", &T::list_exec_inst_type, "69", &T::list_exec_inst, "352", &T::encoded_list_exec_inst_len, "353", &T::encoded_list_exec_inst, "68", &T::tot_no_orders, "73", &T::no_orders);
};
template <>
struct glz::meta<glz::fix::fix42::OrderCancelRequest>
{
   using T = glz::fix::fix42::OrderCancelRequest;
   static constexpr std::string_view fix_msg_type = "F";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("41", &T::orig_cl_ord_id, "37", &T::order_id, "11", &T::cl_ord_id, "66", &T::list_id, "1", &T::account, "109", &T::client_id, "76", &T::exec_broker, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "60", &T::transact_time, "38", &T::order_qty, "152", &T::cash_order_qty, "376", &T::compliance_id, "377", &T::solicited_flag, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::OrderCancelReplaceRequest>
{
   using T = glz::fix::fix42::OrderCancelReplaceRequest;
   static constexpr std::string_view fix_msg_type = "G";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("37", &T::order_id, "109", &T::client_id, "76", &T::exec_broker, "41", &T::orig_cl_ord_id, "11", &T::cl_ord_id, "66", &T::list_id, "1", &T::account, "78", &T::no_allocs, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "60", &T::transact_time, "38", &T::order_qty, "152", &T::cash_order_qty, "40", &T::ord_type, "44", &T::price, "99", &T::stop_px, "211", &T::peg_difference, "388", &T::discretion_inst, "389", &T::discretion_offset, "376", &T::compliance_id, "377", &T::solicited_flag, "15", &T::currency, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "47", &T::rule80_a, "121", &T::forex_req, "120", &T::settl_currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::fut_sett_date2, "192", &T::order_qty2, "77", &T::open_close, "203", &T::covered_or_uncovered, "204", &T::customer_or_firm, "210", &T::max_show, "114", &T::locate_reqd, "439", &T::clearing_firm, "440", &T::clearing_account);
};
template <>
struct glz::meta<glz::fix::fix42::OrderStatusRequest>
{
   using T = glz::fix::fix42::OrderStatusRequest;
   static constexpr std::string_view fix_msg_type = "H";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("37", &T::order_id, "11", &T::cl_ord_id, "109", &T::client_id, "1", &T::account, "76", &T::exec_broker, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side);
};
template <>
struct glz::meta<glz::fix::fix42::OrdAllocGrp>
{
   using T = glz::fix::fix42::OrdAllocGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "66", &T::list_id, "105", &T::wave_no);
};
template <>
struct glz::meta<glz::fix::fix42::ExecAllocGrp>
{
   using T = glz::fix::fix42::ExecAllocGrp;
   static constexpr auto value = glz::object("32", &T::last_shares, "17", &T::exec_id, "31", &T::last_px, "29", &T::last_capacity);
};
template <>
struct glz::meta<glz::fix::fix42::MiscFeesGrp>
{
   using T = glz::fix::fix42::MiscFeesGrp;
   static constexpr auto value = glz::object("137", &T::misc_fee_amt, "138", &T::misc_fee_curr, "139", &T::misc_fee_type);
};
template <>
struct glz::meta<glz::fix::fix42::AllocGrp>
{
   using T = glz::fix::fix42::AllocGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "366", &T::alloc_price, "80", &T::alloc_shares, "81", &T::process_code, "92", &T::broker_of_credit, "208", &T::notify_broker_of_credit, "209", &T::alloc_handl_inst, "161", &T::alloc_text, "360", &T::encoded_alloc_text_len, "361", &T::encoded_alloc_text, "76", &T::exec_broker, "109", &T::client_id, "12", &T::commission, "13", &T::comm_type, "153", &T::alloc_avg_px, "154", &T::alloc_net_money, "119", &T::settl_curr_amt, "120", &T::settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "159", &T::accrued_interest_amt, "160", &T::settl_inst_mode, "136", &T::no_misc_fees);
};
template <>
struct glz::meta<glz::fix::fix42::Allocation>
{
   using T = glz::fix::fix42::Allocation;
   static constexpr std::string_view fix_msg_type = "J";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("70", &T::alloc_id, "71", &T::alloc_trans_type, "72", &T::ref_alloc_id, "196", &T::alloc_link_id, "197", &T::alloc_link_type, "73", &T::no_orders, "124", &T::no_execs, "54", &T::side, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "53", &T::shares, "30", &T::last_mkt, "336", &T::trading_session_id, "6", &T::avg_px, "15", &T::currency, "74", &T::avg_prx_precision, "75", &T::trade_date, "60", &T::transact_time, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "381", &T::gross_trade_amt, "118", &T::net_money, "77", &T::open_close, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "157", &T::num_days_interest, "158", &T::accrued_interest_rate, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix42::ListCancelRequest>
{
   using T = glz::fix::fix42::ListCancelRequest;
   static constexpr std::string_view fix_msg_type = "K";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::ListExecute>
{
   using T = glz::fix::fix42::ListExecute;
   static constexpr std::string_view fix_msg_type = "L";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "391", &T::client_bid_id, "390", &T::bid_id, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::ListStatusRequest>
{
   using T = glz::fix::fix42::ListStatusRequest;
   static constexpr std::string_view fix_msg_type = "M";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::OrdListStatGrp>
{
   using T = glz::fix::fix42::OrdListStatGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "14", &T::cum_qty, "39", &T::ord_status, "151", &T::leaves_qty, "84", &T::cxl_qty, "6", &T::avg_px, "103", &T::ord_rej_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::ListStatus>
{
   using T = glz::fix::fix42::ListStatus;
   static constexpr std::string_view fix_msg_type = "N";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "429", &T::list_status_type, "82", &T::no_rpts, "431", &T::list_order_status, "83", &T::rpt_seq, "444", &T::list_status_text, "445", &T::encoded_list_status_text_len, "446", &T::encoded_list_status_text, "60", &T::transact_time, "68", &T::tot_no_orders, "73", &T::no_orders);
};
template <>
struct glz::meta<glz::fix::fix42::AllocationAck>
{
   using T = glz::fix::fix42::AllocationAck;
   static constexpr std::string_view fix_msg_type = "P";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("109", &T::client_id, "76", &T::exec_broker, "70", &T::alloc_id, "75", &T::trade_date, "60", &T::transact_time, "87", &T::alloc_status, "88", &T::alloc_rej_code, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::DontKnowTrade>
{
   using T = glz::fix::fix42::DontKnowTrade;
   static constexpr std::string_view fix_msg_type = "Q";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("37", &T::order_id, "17", &T::exec_id, "127", &T::dk_reason, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "32", &T::last_shares, "31", &T::last_px, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::QuotReqGrp>
{
   using T = glz::fix::fix42::QuotReqGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "140", &T::prev_close_px, "303", &T::quote_request_type, "336", &T::trading_session_id, "54", &T::side, "38", &T::order_qty, "64", &T::fut_sett_date, "40", &T::ord_type, "193", &T::fut_sett_date2, "192", &T::order_qty2, "126", &T::expire_time, "60", &T::transact_time, "15", &T::currency);
};
template <>
struct glz::meta<glz::fix::fix42::QuoteRequest>
{
   using T = glz::fix::fix42::QuoteRequest;
   static constexpr std::string_view fix_msg_type = "R";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix42::Quote>
{
   using T = glz::fix::fix42::Quote;
   static constexpr std::string_view fix_msg_type = "S";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "301", &T::quote_response_level, "336", &T::trading_session_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "132", &T::bid_px, "133", &T::offer_px, "134", &T::bid_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "60", &T::transact_time, "64", &T::fut_sett_date, "40", &T::ord_type, "193", &T::fut_sett_date2, "192", &T::order_qty2, "15", &T::currency);
};
template <>
struct glz::meta<glz::fix::fix42::SettlementInstructions>
{
   using T = glz::fix::fix42::SettlementInstructions;
   static constexpr std::string_view fix_msg_type = "T";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("162", &T::settl_inst_id, "163", &T::settl_inst_trans_type, "214", &T::settl_inst_ref_id, "160", &T::settl_inst_mode, "165", &T::settl_inst_source, "79", &T::alloc_account, "166", &T::settl_location, "75", &T::trade_date, "70", &T::alloc_id, "30", &T::last_mkt, "336", &T::trading_session_id, "54", &T::side, "167", &T::security_type, "168", &T::effective_time, "60", &T::transact_time, "109", &T::client_id, "76", &T::exec_broker, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "172", &T::settl_delivery_type, "173", &T::settl_depository_code, "174", &T::settl_brkr_code, "175", &T::settl_inst_code, "176", &T::security_settl_agent_name, "177", &T::security_settl_agent_code, "178", &T::security_settl_agent_acct_num, "179", &T::security_settl_agent_acct_name, "180", &T::security_settl_agent_contact_name, "181", &T::security_settl_agent_contact_phone, "182", &T::cash_settl_agent_name, "183", &T::cash_settl_agent_code, "184", &T::cash_settl_agent_acct_num, "185", &T::cash_settl_agent_acct_name, "186", &T::cash_settl_agent_contact_name, "187", &T::cash_settl_agent_contact_phone);
};
template <>
struct glz::meta<glz::fix::fix42::MDReqGrp>
{
   using T = glz::fix::fix42::MDReqGrp;
   static constexpr auto value = glz::object("269", &T::md_entry_type);
};
template <>
struct glz::meta<glz::fix::fix42::InstrmtMDReqGrp>
{
   using T = glz::fix::fix42::InstrmtMDReqGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "336", &T::trading_session_id);
};
template <>
struct glz::meta<glz::fix::fix42::MarketDataRequest>
{
   using T = glz::fix::fix42::MarketDataRequest;
   static constexpr std::string_view fix_msg_type = "V";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("262", &T::md_req_id, "263", &T::subscription_request_type, "264", &T::market_depth, "265", &T::md_update_type, "266", &T::aggregated_book, "267", &T::no_md_entry_types, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix42::MDFullGrp>
{
   using T = glz::fix::fix42::MDFullGrp;
   static constexpr auto value = glz::object("269", &T::md_entry_type, "270", &T::md_entry_px, "15", &T::currency, "271", &T::md_entry_size, "272", &T::md_entry_date, "273", &T::md_entry_time, "274", &T::tick_direction, "275", &T::md_mkt, "336", &T::trading_session_id, "276", &T::quote_condition, "277", &T::trade_condition, "282", &T::md_entry_originator, "283", &T::location_id, "284", &T::desk_id, "286", &T::open_close_settle_flag, "59", &T::time_in_force, "432", &T::expire_date, "126", &T::expire_time, "110", &T::min_qty, "18", &T::exec_inst, "287", &T::seller_days, "37", &T::order_id, "299", &T::quote_entry_id, "288", &T::md_entry_buyer, "289", &T::md_entry_seller, "346", &T::number_of_orders, "290", &T::md_entry_position_no, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::MarketDataSnapshotFullRefresh>
{
   using T = glz::fix::fix42::MarketDataSnapshotFullRefresh;
   static constexpr std::string_view fix_msg_type = "W";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("262", &T::md_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "291", &T::financial_status, "292", &T::corporate_action, "387", &T::total_volume_traded, "268", &T::no_md_entries);
};
template <>
struct glz::meta<glz::fix::fix42::MDIncGrp>
{
   using T = glz::fix::fix42::MDIncGrp;
   static constexpr auto value = glz::object("279", &T::md_update_action, "285", &T::delete_reason, "269", &T::md_entry_type, "278", &T::md_entry_id, "280", &T::md_entry_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "291", &T::financial_status, "292", &T::corporate_action, "270", &T::md_entry_px, "15", &T::currency, "271", &T::md_entry_size, "272", &T::md_entry_date, "273", &T::md_entry_time, "274", &T::tick_direction, "275", &T::md_mkt, "336", &T::trading_session_id, "276", &T::quote_condition, "277", &T::trade_condition, "282", &T::md_entry_originator, "283", &T::location_id, "284", &T::desk_id, "286", &T::open_close_settle_flag, "59", &T::time_in_force, "432", &T::expire_date, "126", &T::expire_time, "110", &T::min_qty, "18", &T::exec_inst, "287", &T::seller_days, "37", &T::order_id, "299", &T::quote_entry_id, "288", &T::md_entry_buyer, "289", &T::md_entry_seller, "346", &T::number_of_orders, "290", &T::md_entry_position_no, "387", &T::total_volume_traded, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::MarketDataIncrementalRefresh>
{
   using T = glz::fix::fix42::MarketDataIncrementalRefresh;
   static constexpr std::string_view fix_msg_type = "X";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("262", &T::md_req_id, "268", &T::no_md_entries);
};
template <>
struct glz::meta<glz::fix::fix42::MarketDataRequestReject>
{
   using T = glz::fix::fix42::MarketDataRequestReject;
   static constexpr std::string_view fix_msg_type = "Y";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("262", &T::md_req_id, "281", &T::md_req_rej_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::QuotCxlEntriesGrp>
{
   using T = glz::fix::fix42::QuotCxlEntriesGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "311", &T::underlying_symbol);
};
template <>
struct glz::meta<glz::fix::fix42::QuoteCancel>
{
   using T = glz::fix::fix42::QuoteCancel;
   static constexpr std::string_view fix_msg_type = "Z";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "298", &T::quote_cancel_type, "301", &T::quote_response_level, "336", &T::trading_session_id, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix42::QuoteStatusRequest>
{
   using T = glz::fix::fix42::QuoteStatusRequest;
   static constexpr std::string_view fix_msg_type = "a";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("117", &T::quote_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "54", &T::side, "336", &T::trading_session_id);
};
template <>
struct glz::meta<glz::fix::fix42::QuotEntryAckGrp>
{
   using T = glz::fix::fix42::QuotEntryAckGrp;
   static constexpr auto value = glz::object("299", &T::quote_entry_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "368", &T::quote_entry_reject_reason);
};
template <>
struct glz::meta<glz::fix::fix42::QuotSetAckGrp>
{
   using T = glz::fix::fix42::QuotSetAckGrp;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_id_source, "310", &T::underlying_security_type, "313", &T::underlying_maturity_month_year, "314", &T::underlying_maturity_day, "315", &T::underlying_put_or_call, "316", &T::underlying_strike_price, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "304", &T::tot_quote_entries, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix42::QuoteAcknowledgement>
{
   using T = glz::fix::fix42::QuoteAcknowledgement;
   static constexpr std::string_view fix_msg_type = "b";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "297", &T::quote_ack_status, "300", &T::quote_reject_reason, "301", &T::quote_response_level, "336", &T::trading_session_id, "58", &T::text, "296", &T::no_quote_sets);
};
template <>
struct glz::meta<glz::fix::fix42::UndInstrmtGrp>
{
   using T = glz::fix::fix42::UndInstrmtGrp;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_id_source, "310", &T::underlying_security_type, "313", &T::underlying_maturity_month_year, "314", &T::underlying_maturity_day, "315", &T::underlying_put_or_call, "316", &T::underlying_strike_price, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "319", &T::ratio_qty, "54", &T::side, "318", &T::underlying_currency);
};
template <>
struct glz::meta<glz::fix::fix42::SecurityDefinitionRequest>
{
   using T = glz::fix::fix42::SecurityDefinitionRequest;
   static constexpr std::string_view fix_msg_type = "c";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("320", &T::security_req_id, "321", &T::security_request_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix42::SecurityDefinition>
{
   using T = glz::fix::fix42::SecurityDefinition;
   static constexpr std::string_view fix_msg_type = "d";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("320", &T::security_req_id, "322", &T::security_response_id, "323", &T::security_response_type, "393", &T::total_num_securities, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "15", &T::currency, "336", &T::trading_session_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix42::SecurityStatusRequest>
{
   using T = glz::fix::fix42::SecurityStatusRequest;
   static constexpr std::string_view fix_msg_type = "e";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("324", &T::security_status_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "15", &T::currency, "263", &T::subscription_request_type, "336", &T::trading_session_id);
};
template <>
struct glz::meta<glz::fix::fix42::SecurityStatus>
{
   using T = glz::fix::fix42::SecurityStatus;
   static constexpr std::string_view fix_msg_type = "f";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("324", &T::security_status_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "15", &T::currency, "336", &T::trading_session_id, "325", &T::unsolicited_indicator, "326", &T::security_trading_status, "291", &T::financial_status, "292", &T::corporate_action, "327", &T::halt_reason, "328", &T::in_view_of_common, "329", &T::due_to_related, "330", &T::buy_volume, "331", &T::sell_volume, "332", &T::high_px, "333", &T::low_px, "31", &T::last_px, "60", &T::transact_time, "334", &T::adjustment);
};
template <>
struct glz::meta<glz::fix::fix42::TradingSessionStatusRequest>
{
   using T = glz::fix::fix42::TradingSessionStatusRequest;
   static constexpr std::string_view fix_msg_type = "g";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("335", &T::trad_ses_req_id, "336", &T::trading_session_id, "338", &T::trad_ses_method, "339", &T::trad_ses_mode, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix42::TradingSessionStatus>
{
   using T = glz::fix::fix42::TradingSessionStatus;
   static constexpr std::string_view fix_msg_type = "h";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("335", &T::trad_ses_req_id, "336", &T::trading_session_id, "338", &T::trad_ses_method, "339", &T::trad_ses_mode, "325", &T::unsolicited_indicator, "340", &T::trad_ses_status, "341", &T::trad_ses_start_time, "342", &T::trad_ses_open_time, "343", &T::trad_ses_pre_close_time, "344", &T::trad_ses_close_time, "345", &T::trad_ses_end_time, "387", &T::total_volume_traded, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::QuotEntryGrp>
{
   using T = glz::fix::fix42::QuotEntryGrp;
   static constexpr auto value = glz::object("299", &T::quote_entry_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "132", &T::bid_px, "133", &T::offer_px, "134", &T::bid_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "60", &T::transact_time, "336", &T::trading_session_id, "64", &T::fut_sett_date, "40", &T::ord_type, "193", &T::fut_sett_date2, "192", &T::order_qty2, "15", &T::currency);
};
template <>
struct glz::meta<glz::fix::fix42::QuotSetGrp>
{
   using T = glz::fix::fix42::QuotSetGrp;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_id_source, "310", &T::underlying_security_type, "313", &T::underlying_maturity_month_year, "314", &T::underlying_maturity_day, "315", &T::underlying_put_or_call, "316", &T::underlying_strike_price, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "367", &T::quote_set_valid_until_time, "304", &T::tot_quote_entries, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix42::MassQuote>
{
   using T = glz::fix::fix42::MassQuote;
   static constexpr std::string_view fix_msg_type = "i";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "301", &T::quote_response_level, "293", &T::def_bid_size, "294", &T::def_offer_size, "296", &T::no_quote_sets);
};
template <>
struct glz::meta<glz::fix::fix42::BusinessMessageReject>
{
   using T = glz::fix::fix42::BusinessMessageReject;
   static constexpr std::string_view fix_msg_type = "j";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "372", &T::ref_msg_type, "379", &T::business_reject_ref_id, "380", &T::business_reject_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::BidDescReqGrp>
{
   using T = glz::fix::fix42::BidDescReqGrp;
   static constexpr auto value = glz::object("399", &T::bid_descriptor_type, "400", &T::bid_descriptor, "401", &T::side_value_ind, "404", &T::liquidity_value, "441", &T::liquidity_num_securities, "402", &T::liquidity_pct_low, "403", &T::liquidity_pct_high, "405", &T::efp_tracking_error, "406", &T::fair_value, "407", &T::outside_index_pct, "408", &T::value_of_futures);
};
template <>
struct glz::meta<glz::fix::fix42::BidCompReqGrp>
{
   using T = glz::fix::fix42::BidCompReqGrp;
   static constexpr auto value = glz::object("66", &T::list_id, "54", &T::side, "336", &T::trading_session_id, "430", &T::net_gross_ind, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "1", &T::account);
};
template <>
struct glz::meta<glz::fix::fix42::BidRequest>
{
   using T = glz::fix::fix42::BidRequest;
   static constexpr std::string_view fix_msg_type = "k";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("390", &T::bid_id, "391", &T::client_bid_id, "374", &T::bid_request_trans_type, "392", &T::list_name, "393", &T::total_num_securities, "394", &T::bid_type, "395", &T::num_tickets, "15", &T::currency, "396", &T::side_value1, "397", &T::side_value2, "398", &T::no_bid_descriptors, "420", &T::no_bid_components, "409", &T::liquidity_ind_type, "410", &T::wt_average_liquidity, "411", &T::exchange_for_physical, "412", &T::out_main_cntry_u_index, "413", &T::cross_percent, "414", &T::prog_rpt_reqs, "415", &T::prog_period_interval, "416", &T::inc_tax_ind, "121", &T::forex_req, "417", &T::num_bidders, "75", &T::trade_date, "418", &T::trade_type, "419", &T::basis_px_type, "443", &T::strike_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::BidCompRspGrp>
{
   using T = glz::fix::fix42::BidCompRspGrp;
   static constexpr auto value = glz::object("12", &T::commission, "13", &T::comm_type, "66", &T::list_id, "421", &T::country, "54", &T::side, "44", &T::price, "423", &T::price_type, "406", &T::fair_value, "430", &T::net_gross_ind, "63", &T::settlmnt_typ, "64", &T::fut_sett_date, "336", &T::trading_session_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::BidResponse>
{
   using T = glz::fix::fix42::BidResponse;
   static constexpr std::string_view fix_msg_type = "l";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("390", &T::bid_id, "391", &T::client_bid_id, "420", &T::no_bid_components);
};
template <>
struct glz::meta<glz::fix::fix42::InstrmtStrkPxGrp>
{
   using T = glz::fix::fix42::InstrmtStrkPxGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::id_source, "167", &T::security_type, "200", &T::maturity_month_year, "205", &T::maturity_day, "201", &T::put_or_call, "202", &T::strike_price, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "140", &T::prev_close_px, "11", &T::cl_ord_id, "54", &T::side, "44", &T::price, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix42::ListStrikePrice>
{
   using T = glz::fix::fix42::ListStrikePrice;
   static constexpr std::string_view fix_msg_type = "m";
   static constexpr std::string_view fix_begin_string = "FIX.4.2";
   static constexpr auto value = glz::object("66", &T::list_id, "422", &T::tot_no_strikes, "428", &T::no_strikes);
};
