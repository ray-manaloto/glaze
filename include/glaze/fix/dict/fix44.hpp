// Glaze Library
// For the license information refer to glaze.hpp
//
// GENERATED FILE - do not edit. Produced by util/fix_codegen/fix_codegen.py from the
// FIX Orchestra repository file for FIX.4.4 (version FIX.4.4_EP311).
// Source data: https://github.com/FIXTradingCommunity/orchestrations
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

namespace glz::fix::fix44
{
   inline constexpr std::string_view begin_string = "FIX.4.4";

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
      inline constexpr uint32_t HandlInst = 21;
      inline constexpr uint32_t SecurityIDSource = 22;
      inline constexpr uint32_t IOIID = 23;
      inline constexpr uint32_t IOIQltyInd = 25;
      inline constexpr uint32_t IOIRefID = 26;
      inline constexpr uint32_t IOIQty = 27;
      inline constexpr uint32_t IOITransType = 28;
      inline constexpr uint32_t LastCapacity = 29;
      inline constexpr uint32_t LastMkt = 30;
      inline constexpr uint32_t LastPx = 31;
      inline constexpr uint32_t LastQty = 32;
      inline constexpr uint32_t NoLinesOfText = 33;
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
      inline constexpr uint32_t SecurityID = 48;
      inline constexpr uint32_t SenderCompID = 49;
      inline constexpr uint32_t SenderSubID = 50;
      inline constexpr uint32_t SendingTime = 52;
      inline constexpr uint32_t Quantity = 53;
      inline constexpr uint32_t Side = 54;
      inline constexpr uint32_t Symbol = 55;
      inline constexpr uint32_t TargetCompID = 56;
      inline constexpr uint32_t TargetSubID = 57;
      inline constexpr uint32_t Text = 58;
      inline constexpr uint32_t TimeInForce = 59;
      inline constexpr uint32_t TransactTime = 60;
      inline constexpr uint32_t Urgency = 61;
      inline constexpr uint32_t ValidUntilTime = 62;
      inline constexpr uint32_t SettlType = 63;
      inline constexpr uint32_t SettlDate = 64;
      inline constexpr uint32_t SymbolSfx = 65;
      inline constexpr uint32_t ListID = 66;
      inline constexpr uint32_t ListSeqNo = 67;
      inline constexpr uint32_t TotNoOrders = 68;
      inline constexpr uint32_t ListExecInst = 69;
      inline constexpr uint32_t AllocID = 70;
      inline constexpr uint32_t AllocTransType = 71;
      inline constexpr uint32_t RefAllocID = 72;
      inline constexpr uint32_t NoOrders = 73;
      inline constexpr uint32_t AvgPxPrecision = 74;
      inline constexpr uint32_t TradeDate = 75;
      inline constexpr uint32_t PositionEffect = 77;
      inline constexpr uint32_t NoAllocs = 78;
      inline constexpr uint32_t AllocAccount = 79;
      inline constexpr uint32_t AllocQty = 80;
      inline constexpr uint32_t ProcessCode = 81;
      inline constexpr uint32_t NoRpts = 82;
      inline constexpr uint32_t RptSeq = 83;
      inline constexpr uint32_t CxlQty = 84;
      inline constexpr uint32_t NoDlvyInst = 85;
      inline constexpr uint32_t AllocStatus = 87;
      inline constexpr uint32_t AllocRejCode = 88;
      inline constexpr uint32_t Signature = 89;
      inline constexpr uint32_t SecureDataLen = 90;
      inline constexpr uint32_t SecureData = 91;
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
      inline constexpr uint32_t Issuer = 106;
      inline constexpr uint32_t SecurityDesc = 107;
      inline constexpr uint32_t HeartBtInt = 108;
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
      inline constexpr uint32_t SecurityType = 167;
      inline constexpr uint32_t EffectiveTime = 168;
      inline constexpr uint32_t StandInstDbType = 169;
      inline constexpr uint32_t StandInstDbName = 170;
      inline constexpr uint32_t StandInstDbID = 171;
      inline constexpr uint32_t SettlDeliveryType = 172;
      inline constexpr uint32_t BidSpotRate = 188;
      inline constexpr uint32_t BidForwardPoints = 189;
      inline constexpr uint32_t OfferSpotRate = 190;
      inline constexpr uint32_t OfferForwardPoints = 191;
      inline constexpr uint32_t OrderQty2 = 192;
      inline constexpr uint32_t SettlDate2 = 193;
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
      inline constexpr uint32_t OptAttribute = 206;
      inline constexpr uint32_t SecurityExchange = 207;
      inline constexpr uint32_t NotifyBrokerOfCredit = 208;
      inline constexpr uint32_t AllocHandlInst = 209;
      inline constexpr uint32_t MaxShow = 210;
      inline constexpr uint32_t PegOffsetValue = 211;
      inline constexpr uint32_t XmlDataLen = 212;
      inline constexpr uint32_t XmlData = 213;
      inline constexpr uint32_t SettlInstRefID = 214;
      inline constexpr uint32_t NoRoutingIDs = 215;
      inline constexpr uint32_t RoutingType = 216;
      inline constexpr uint32_t RoutingID = 217;
      inline constexpr uint32_t Spread = 218;
      inline constexpr uint32_t BenchmarkCurveCurrency = 220;
      inline constexpr uint32_t BenchmarkCurveName = 221;
      inline constexpr uint32_t BenchmarkCurvePoint = 222;
      inline constexpr uint32_t CouponRate = 223;
      inline constexpr uint32_t CouponPaymentDate = 224;
      inline constexpr uint32_t IssueDate = 225;
      inline constexpr uint32_t RepurchaseTerm = 226;
      inline constexpr uint32_t RepurchaseRate = 227;
      inline constexpr uint32_t Factor = 228;
      inline constexpr uint32_t TradeOriginationDate = 229;
      inline constexpr uint32_t ExDate = 230;
      inline constexpr uint32_t ContractMultiplier = 231;
      inline constexpr uint32_t NoStipulations = 232;
      inline constexpr uint32_t StipulationType = 233;
      inline constexpr uint32_t StipulationValue = 234;
      inline constexpr uint32_t YieldType = 235;
      inline constexpr uint32_t Yield = 236;
      inline constexpr uint32_t TotalTakedown = 237;
      inline constexpr uint32_t Concession = 238;
      inline constexpr uint32_t RepoCollateralSecurityType = 239;
      inline constexpr uint32_t RedemptionDate = 240;
      inline constexpr uint32_t UnderlyingCouponPaymentDate = 241;
      inline constexpr uint32_t UnderlyingIssueDate = 242;
      inline constexpr uint32_t UnderlyingRepoCollateralSecurityType = 243;
      inline constexpr uint32_t UnderlyingRepurchaseTerm = 244;
      inline constexpr uint32_t UnderlyingRepurchaseRate = 245;
      inline constexpr uint32_t UnderlyingFactor = 246;
      inline constexpr uint32_t UnderlyingRedemptionDate = 247;
      inline constexpr uint32_t LegCouponPaymentDate = 248;
      inline constexpr uint32_t LegIssueDate = 249;
      inline constexpr uint32_t LegRepoCollateralSecurityType = 250;
      inline constexpr uint32_t LegRepurchaseTerm = 251;
      inline constexpr uint32_t LegRepurchaseRate = 252;
      inline constexpr uint32_t LegFactor = 253;
      inline constexpr uint32_t LegRedemptionDate = 254;
      inline constexpr uint32_t CreditRating = 255;
      inline constexpr uint32_t UnderlyingCreditRating = 256;
      inline constexpr uint32_t LegCreditRating = 257;
      inline constexpr uint32_t TradedFlatSwitch = 258;
      inline constexpr uint32_t BasisFeatureDate = 259;
      inline constexpr uint32_t BasisFeaturePrice = 260;
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
      inline constexpr uint32_t OpenCloseSettlFlag = 286;
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
      inline constexpr uint32_t QuoteStatus = 297;
      inline constexpr uint32_t QuoteCancelType = 298;
      inline constexpr uint32_t QuoteEntryID = 299;
      inline constexpr uint32_t QuoteRejectReason = 300;
      inline constexpr uint32_t QuoteResponseLevel = 301;
      inline constexpr uint32_t QuoteSetID = 302;
      inline constexpr uint32_t QuoteRequestType = 303;
      inline constexpr uint32_t TotNoQuoteEntries = 304;
      inline constexpr uint32_t UnderlyingSecurityIDSource = 305;
      inline constexpr uint32_t UnderlyingIssuer = 306;
      inline constexpr uint32_t UnderlyingSecurityDesc = 307;
      inline constexpr uint32_t UnderlyingSecurityExchange = 308;
      inline constexpr uint32_t UnderlyingSecurityID = 309;
      inline constexpr uint32_t UnderlyingSecurityType = 310;
      inline constexpr uint32_t UnderlyingSymbol = 311;
      inline constexpr uint32_t UnderlyingSymbolSfx = 312;
      inline constexpr uint32_t UnderlyingMaturityMonthYear = 313;
      inline constexpr uint32_t UnderlyingPutOrCall = 315;
      inline constexpr uint32_t UnderlyingStrikePrice = 316;
      inline constexpr uint32_t UnderlyingOptAttribute = 317;
      inline constexpr uint32_t UnderlyingCurrency = 318;
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
      inline constexpr uint32_t DiscretionOffsetValue = 389;
      inline constexpr uint32_t BidID = 390;
      inline constexpr uint32_t ClientBidID = 391;
      inline constexpr uint32_t ListName = 392;
      inline constexpr uint32_t TotNoRelatedSym = 393;
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
      inline constexpr uint32_t BidTradeType = 418;
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
      inline constexpr uint32_t LiquidityNumSecurities = 441;
      inline constexpr uint32_t MultiLegReportingType = 442;
      inline constexpr uint32_t StrikeTime = 443;
      inline constexpr uint32_t ListStatusText = 444;
      inline constexpr uint32_t EncodedListStatusTextLen = 445;
      inline constexpr uint32_t EncodedListStatusText = 446;
      inline constexpr uint32_t PartyIDSource = 447;
      inline constexpr uint32_t PartyID = 448;
      inline constexpr uint32_t NetChgPrevDay = 451;
      inline constexpr uint32_t PartyRole = 452;
      inline constexpr uint32_t NoPartyIDs = 453;
      inline constexpr uint32_t NoSecurityAltID = 454;
      inline constexpr uint32_t SecurityAltID = 455;
      inline constexpr uint32_t SecurityAltIDSource = 456;
      inline constexpr uint32_t NoUnderlyingSecurityAltID = 457;
      inline constexpr uint32_t UnderlyingSecurityAltID = 458;
      inline constexpr uint32_t UnderlyingSecurityAltIDSource = 459;
      inline constexpr uint32_t Product = 460;
      inline constexpr uint32_t CFICode = 461;
      inline constexpr uint32_t UnderlyingProduct = 462;
      inline constexpr uint32_t UnderlyingCFICode = 463;
      inline constexpr uint32_t TestMessageIndicator = 464;
      inline constexpr uint32_t BookingRefID = 466;
      inline constexpr uint32_t IndividualAllocID = 467;
      inline constexpr uint32_t RoundingDirection = 468;
      inline constexpr uint32_t RoundingModulus = 469;
      inline constexpr uint32_t CountryOfIssue = 470;
      inline constexpr uint32_t StateOrProvinceOfIssue = 471;
      inline constexpr uint32_t LocaleOfIssue = 472;
      inline constexpr uint32_t NoRegistDtls = 473;
      inline constexpr uint32_t MailingDtls = 474;
      inline constexpr uint32_t InvestorCountryOfResidence = 475;
      inline constexpr uint32_t PaymentRef = 476;
      inline constexpr uint32_t DistribPaymentMethod = 477;
      inline constexpr uint32_t CashDistribCurr = 478;
      inline constexpr uint32_t CommCurrency = 479;
      inline constexpr uint32_t CancellationRights = 480;
      inline constexpr uint32_t MoneyLaunderingStatus = 481;
      inline constexpr uint32_t MailingInst = 482;
      inline constexpr uint32_t TransBkdTime = 483;
      inline constexpr uint32_t ExecPriceType = 484;
      inline constexpr uint32_t ExecPriceAdjustment = 485;
      inline constexpr uint32_t DateOfBirth = 486;
      inline constexpr uint32_t TradeReportTransType = 487;
      inline constexpr uint32_t CardHolderName = 488;
      inline constexpr uint32_t CardNumber = 489;
      inline constexpr uint32_t CardExpDate = 490;
      inline constexpr uint32_t CardIssNum = 491;
      inline constexpr uint32_t PaymentMethod = 492;
      inline constexpr uint32_t RegistAcctType = 493;
      inline constexpr uint32_t Designation = 494;
      inline constexpr uint32_t TaxAdvantageType = 495;
      inline constexpr uint32_t RegistRejReasonText = 496;
      inline constexpr uint32_t FundRenewWaiv = 497;
      inline constexpr uint32_t CashDistribAgentName = 498;
      inline constexpr uint32_t CashDistribAgentCode = 499;
      inline constexpr uint32_t CashDistribAgentAcctNumber = 500;
      inline constexpr uint32_t CashDistribPayRef = 501;
      inline constexpr uint32_t CashDistribAgentAcctName = 502;
      inline constexpr uint32_t CardStartDate = 503;
      inline constexpr uint32_t PaymentDate = 504;
      inline constexpr uint32_t PaymentRemitterID = 505;
      inline constexpr uint32_t RegistStatus = 506;
      inline constexpr uint32_t RegistRejReasonCode = 507;
      inline constexpr uint32_t RegistRefID = 508;
      inline constexpr uint32_t RegistDtls = 509;
      inline constexpr uint32_t NoDistribInsts = 510;
      inline constexpr uint32_t RegistEmail = 511;
      inline constexpr uint32_t DistribPercentage = 512;
      inline constexpr uint32_t RegistID = 513;
      inline constexpr uint32_t RegistTransType = 514;
      inline constexpr uint32_t ExecValuationPoint = 515;
      inline constexpr uint32_t OrderPercent = 516;
      inline constexpr uint32_t OwnershipType = 517;
      inline constexpr uint32_t NoContAmts = 518;
      inline constexpr uint32_t ContAmtType = 519;
      inline constexpr uint32_t ContAmtValue = 520;
      inline constexpr uint32_t ContAmtCurr = 521;
      inline constexpr uint32_t OwnerType = 522;
      inline constexpr uint32_t PartySubID = 523;
      inline constexpr uint32_t NestedPartyID = 524;
      inline constexpr uint32_t NestedPartyIDSource = 525;
      inline constexpr uint32_t SecondaryClOrdID = 526;
      inline constexpr uint32_t SecondaryExecID = 527;
      inline constexpr uint32_t OrderCapacity = 528;
      inline constexpr uint32_t OrderRestrictions = 529;
      inline constexpr uint32_t MassCancelRequestType = 530;
      inline constexpr uint32_t MassCancelResponse = 531;
      inline constexpr uint32_t MassCancelRejectReason = 532;
      inline constexpr uint32_t TotalAffectedOrders = 533;
      inline constexpr uint32_t NoAffectedOrders = 534;
      inline constexpr uint32_t AffectedOrderID = 535;
      inline constexpr uint32_t AffectedSecondaryOrderID = 536;
      inline constexpr uint32_t QuoteType = 537;
      inline constexpr uint32_t NestedPartyRole = 538;
      inline constexpr uint32_t NoNestedPartyIDs = 539;
      inline constexpr uint32_t TotalAccruedInterestAmt = 540;
      inline constexpr uint32_t MaturityDate = 541;
      inline constexpr uint32_t UnderlyingMaturityDate = 542;
      inline constexpr uint32_t InstrRegistry = 543;
      inline constexpr uint32_t CashMargin = 544;
      inline constexpr uint32_t NestedPartySubID = 545;
      inline constexpr uint32_t Scope = 546;
      inline constexpr uint32_t MDImplicitDelete = 547;
      inline constexpr uint32_t CrossID = 548;
      inline constexpr uint32_t CrossType = 549;
      inline constexpr uint32_t CrossPrioritization = 550;
      inline constexpr uint32_t OrigCrossID = 551;
      inline constexpr uint32_t NoSides = 552;
      inline constexpr uint32_t Username = 553;
      inline constexpr uint32_t Password = 554;
      inline constexpr uint32_t NoLegs = 555;
      inline constexpr uint32_t LegCurrency = 556;
      inline constexpr uint32_t TotNoSecurityTypes = 557;
      inline constexpr uint32_t NoSecurityTypes = 558;
      inline constexpr uint32_t SecurityListRequestType = 559;
      inline constexpr uint32_t SecurityRequestResult = 560;
      inline constexpr uint32_t RoundLot = 561;
      inline constexpr uint32_t MinTradeVol = 562;
      inline constexpr uint32_t MultiLegRptTypeReq = 563;
      inline constexpr uint32_t LegPositionEffect = 564;
      inline constexpr uint32_t LegCoveredOrUncovered = 565;
      inline constexpr uint32_t LegPrice = 566;
      inline constexpr uint32_t TradSesStatusRejReason = 567;
      inline constexpr uint32_t TradeRequestID = 568;
      inline constexpr uint32_t TradeRequestType = 569;
      inline constexpr uint32_t PreviouslyReported = 570;
      inline constexpr uint32_t TradeReportID = 571;
      inline constexpr uint32_t TradeReportRefID = 572;
      inline constexpr uint32_t MatchStatus = 573;
      inline constexpr uint32_t MatchType = 574;
      inline constexpr uint32_t OddLot = 575;
      inline constexpr uint32_t NoClearingInstructions = 576;
      inline constexpr uint32_t ClearingInstruction = 577;
      inline constexpr uint32_t TradeInputSource = 578;
      inline constexpr uint32_t TradeInputDevice = 579;
      inline constexpr uint32_t NoDates = 580;
      inline constexpr uint32_t AccountType = 581;
      inline constexpr uint32_t CustOrderCapacity = 582;
      inline constexpr uint32_t ClOrdLinkID = 583;
      inline constexpr uint32_t MassStatusReqID = 584;
      inline constexpr uint32_t MassStatusReqType = 585;
      inline constexpr uint32_t OrigOrdModTime = 586;
      inline constexpr uint32_t LegSettlType = 587;
      inline constexpr uint32_t LegSettlDate = 588;
      inline constexpr uint32_t DayBookingInst = 589;
      inline constexpr uint32_t BookingUnit = 590;
      inline constexpr uint32_t PreallocMethod = 591;
      inline constexpr uint32_t UnderlyingCountryOfIssue = 592;
      inline constexpr uint32_t UnderlyingStateOrProvinceOfIssue = 593;
      inline constexpr uint32_t UnderlyingLocaleOfIssue = 594;
      inline constexpr uint32_t UnderlyingInstrRegistry = 595;
      inline constexpr uint32_t LegCountryOfIssue = 596;
      inline constexpr uint32_t LegStateOrProvinceOfIssue = 597;
      inline constexpr uint32_t LegLocaleOfIssue = 598;
      inline constexpr uint32_t LegInstrRegistry = 599;
      inline constexpr uint32_t LegSymbol = 600;
      inline constexpr uint32_t LegSymbolSfx = 601;
      inline constexpr uint32_t LegSecurityID = 602;
      inline constexpr uint32_t LegSecurityIDSource = 603;
      inline constexpr uint32_t NoLegSecurityAltID = 604;
      inline constexpr uint32_t LegSecurityAltID = 605;
      inline constexpr uint32_t LegSecurityAltIDSource = 606;
      inline constexpr uint32_t LegProduct = 607;
      inline constexpr uint32_t LegCFICode = 608;
      inline constexpr uint32_t LegSecurityType = 609;
      inline constexpr uint32_t LegMaturityMonthYear = 610;
      inline constexpr uint32_t LegMaturityDate = 611;
      inline constexpr uint32_t LegStrikePrice = 612;
      inline constexpr uint32_t LegOptAttribute = 613;
      inline constexpr uint32_t LegContractMultiplier = 614;
      inline constexpr uint32_t LegCouponRate = 615;
      inline constexpr uint32_t LegSecurityExchange = 616;
      inline constexpr uint32_t LegIssuer = 617;
      inline constexpr uint32_t EncodedLegIssuerLen = 618;
      inline constexpr uint32_t EncodedLegIssuer = 619;
      inline constexpr uint32_t LegSecurityDesc = 620;
      inline constexpr uint32_t EncodedLegSecurityDescLen = 621;
      inline constexpr uint32_t EncodedLegSecurityDesc = 622;
      inline constexpr uint32_t LegRatioQty = 623;
      inline constexpr uint32_t LegSide = 624;
      inline constexpr uint32_t TradingSessionSubID = 625;
      inline constexpr uint32_t AllocType = 626;
      inline constexpr uint32_t NoHops = 627;
      inline constexpr uint32_t HopCompID = 628;
      inline constexpr uint32_t HopSendingTime = 629;
      inline constexpr uint32_t HopRefID = 630;
      inline constexpr uint32_t MidPx = 631;
      inline constexpr uint32_t BidYield = 632;
      inline constexpr uint32_t MidYield = 633;
      inline constexpr uint32_t OfferYield = 634;
      inline constexpr uint32_t ClearingFeeIndicator = 635;
      inline constexpr uint32_t WorkingIndicator = 636;
      inline constexpr uint32_t LegLastPx = 637;
      inline constexpr uint32_t PriorityIndicator = 638;
      inline constexpr uint32_t PriceImprovement = 639;
      inline constexpr uint32_t Price2 = 640;
      inline constexpr uint32_t LastForwardPoints2 = 641;
      inline constexpr uint32_t BidForwardPoints2 = 642;
      inline constexpr uint32_t OfferForwardPoints2 = 643;
      inline constexpr uint32_t RFQReqID = 644;
      inline constexpr uint32_t MktBidPx = 645;
      inline constexpr uint32_t MktOfferPx = 646;
      inline constexpr uint32_t MinBidSize = 647;
      inline constexpr uint32_t MinOfferSize = 648;
      inline constexpr uint32_t QuoteStatusReqID = 649;
      inline constexpr uint32_t LegalConfirm = 650;
      inline constexpr uint32_t UnderlyingLastPx = 651;
      inline constexpr uint32_t UnderlyingLastQty = 652;
      inline constexpr uint32_t LegRefID = 654;
      inline constexpr uint32_t ContraLegRefID = 655;
      inline constexpr uint32_t SettlCurrBidFxRate = 656;
      inline constexpr uint32_t SettlCurrOfferFxRate = 657;
      inline constexpr uint32_t QuoteRequestRejectReason = 658;
      inline constexpr uint32_t SideComplianceID = 659;
      inline constexpr uint32_t AcctIDSource = 660;
      inline constexpr uint32_t AllocAcctIDSource = 661;
      inline constexpr uint32_t BenchmarkPrice = 662;
      inline constexpr uint32_t BenchmarkPriceType = 663;
      inline constexpr uint32_t ConfirmID = 664;
      inline constexpr uint32_t ConfirmStatus = 665;
      inline constexpr uint32_t ConfirmTransType = 666;
      inline constexpr uint32_t ContractSettlMonth = 667;
      inline constexpr uint32_t DeliveryForm = 668;
      inline constexpr uint32_t LastParPx = 669;
      inline constexpr uint32_t NoLegAllocs = 670;
      inline constexpr uint32_t LegAllocAccount = 671;
      inline constexpr uint32_t LegIndividualAllocID = 672;
      inline constexpr uint32_t LegAllocQty = 673;
      inline constexpr uint32_t LegAllocAcctIDSource = 674;
      inline constexpr uint32_t LegSettlCurrency = 675;
      inline constexpr uint32_t LegBenchmarkCurveCurrency = 676;
      inline constexpr uint32_t LegBenchmarkCurveName = 677;
      inline constexpr uint32_t LegBenchmarkCurvePoint = 678;
      inline constexpr uint32_t LegBenchmarkPrice = 679;
      inline constexpr uint32_t LegBenchmarkPriceType = 680;
      inline constexpr uint32_t LegBidPx = 681;
      inline constexpr uint32_t LegIOIQty = 682;
      inline constexpr uint32_t NoLegStipulations = 683;
      inline constexpr uint32_t LegOfferPx = 684;
      inline constexpr uint32_t LegPriceType = 686;
      inline constexpr uint32_t LegQty = 687;
      inline constexpr uint32_t LegStipulationType = 688;
      inline constexpr uint32_t LegStipulationValue = 689;
      inline constexpr uint32_t LegSwapType = 690;
      inline constexpr uint32_t Pool = 691;
      inline constexpr uint32_t QuotePriceType = 692;
      inline constexpr uint32_t QuoteRespID = 693;
      inline constexpr uint32_t QuoteRespType = 694;
      inline constexpr uint32_t QuoteQualifier = 695;
      inline constexpr uint32_t YieldRedemptionDate = 696;
      inline constexpr uint32_t YieldRedemptionPrice = 697;
      inline constexpr uint32_t YieldRedemptionPriceType = 698;
      inline constexpr uint32_t BenchmarkSecurityID = 699;
      inline constexpr uint32_t ReversalIndicator = 700;
      inline constexpr uint32_t YieldCalcDate = 701;
      inline constexpr uint32_t NoPositions = 702;
      inline constexpr uint32_t PosType = 703;
      inline constexpr uint32_t LongQty = 704;
      inline constexpr uint32_t ShortQty = 705;
      inline constexpr uint32_t PosQtyStatus = 706;
      inline constexpr uint32_t PosAmtType = 707;
      inline constexpr uint32_t PosAmt = 708;
      inline constexpr uint32_t PosTransType = 709;
      inline constexpr uint32_t PosReqID = 710;
      inline constexpr uint32_t NoUnderlyings = 711;
      inline constexpr uint32_t PosMaintAction = 712;
      inline constexpr uint32_t OrigPosReqRefID = 713;
      inline constexpr uint32_t PosMaintRptRefID = 714;
      inline constexpr uint32_t ClearingBusinessDate = 715;
      inline constexpr uint32_t SettlSessID = 716;
      inline constexpr uint32_t SettlSessSubID = 717;
      inline constexpr uint32_t AdjustmentType = 718;
      inline constexpr uint32_t ContraryInstructionIndicator = 719;
      inline constexpr uint32_t PriorSpreadIndicator = 720;
      inline constexpr uint32_t PosMaintRptID = 721;
      inline constexpr uint32_t PosMaintStatus = 722;
      inline constexpr uint32_t PosMaintResult = 723;
      inline constexpr uint32_t PosReqType = 724;
      inline constexpr uint32_t ResponseTransportType = 725;
      inline constexpr uint32_t ResponseDestination = 726;
      inline constexpr uint32_t TotalNumPosReports = 727;
      inline constexpr uint32_t PosReqResult = 728;
      inline constexpr uint32_t PosReqStatus = 729;
      inline constexpr uint32_t SettlPrice = 730;
      inline constexpr uint32_t SettlPriceType = 731;
      inline constexpr uint32_t UnderlyingSettlPrice = 732;
      inline constexpr uint32_t UnderlyingSettlPriceType = 733;
      inline constexpr uint32_t PriorSettlPrice = 734;
      inline constexpr uint32_t NoQuoteQualifiers = 735;
      inline constexpr uint32_t AllocSettlCurrency = 736;
      inline constexpr uint32_t AllocSettlCurrAmt = 737;
      inline constexpr uint32_t InterestAtMaturity = 738;
      inline constexpr uint32_t LegDatedDate = 739;
      inline constexpr uint32_t LegPool = 740;
      inline constexpr uint32_t AllocInterestAtMaturity = 741;
      inline constexpr uint32_t AllocAccruedInterestAmt = 742;
      inline constexpr uint32_t DeliveryDate = 743;
      inline constexpr uint32_t AssignmentMethod = 744;
      inline constexpr uint32_t AssignmentUnit = 745;
      inline constexpr uint32_t OpenInterest = 746;
      inline constexpr uint32_t ExerciseMethod = 747;
      inline constexpr uint32_t TotNumTradeReports = 748;
      inline constexpr uint32_t TradeRequestResult = 749;
      inline constexpr uint32_t TradeRequestStatus = 750;
      inline constexpr uint32_t TradeReportRejectReason = 751;
      inline constexpr uint32_t SideMultiLegReportingType = 752;
      inline constexpr uint32_t NoPosAmt = 753;
      inline constexpr uint32_t AutoAcceptIndicator = 754;
      inline constexpr uint32_t AllocReportID = 755;
      inline constexpr uint32_t NoNested2PartyIDs = 756;
      inline constexpr uint32_t Nested2PartyID = 757;
      inline constexpr uint32_t Nested2PartyIDSource = 758;
      inline constexpr uint32_t Nested2PartyRole = 759;
      inline constexpr uint32_t Nested2PartySubID = 760;
      inline constexpr uint32_t BenchmarkSecurityIDSource = 761;
      inline constexpr uint32_t SecuritySubType = 762;
      inline constexpr uint32_t UnderlyingSecuritySubType = 763;
      inline constexpr uint32_t LegSecuritySubType = 764;
      inline constexpr uint32_t AllowableOneSidednessPct = 765;
      inline constexpr uint32_t AllowableOneSidednessValue = 766;
      inline constexpr uint32_t AllowableOneSidednessCurr = 767;
      inline constexpr uint32_t NoTrdRegTimestamps = 768;
      inline constexpr uint32_t TrdRegTimestamp = 769;
      inline constexpr uint32_t TrdRegTimestampType = 770;
      inline constexpr uint32_t TrdRegTimestampOrigin = 771;
      inline constexpr uint32_t ConfirmRefID = 772;
      inline constexpr uint32_t ConfirmType = 773;
      inline constexpr uint32_t ConfirmRejReason = 774;
      inline constexpr uint32_t BookingType = 775;
      inline constexpr uint32_t IndividualAllocRejCode = 776;
      inline constexpr uint32_t SettlInstMsgID = 777;
      inline constexpr uint32_t NoSettlInst = 778;
      inline constexpr uint32_t LastUpdateTime = 779;
      inline constexpr uint32_t AllocSettlInstType = 780;
      inline constexpr uint32_t NoSettlPartyIDs = 781;
      inline constexpr uint32_t SettlPartyID = 782;
      inline constexpr uint32_t SettlPartyIDSource = 783;
      inline constexpr uint32_t SettlPartyRole = 784;
      inline constexpr uint32_t SettlPartySubID = 785;
      inline constexpr uint32_t SettlPartySubIDType = 786;
      inline constexpr uint32_t DlvyInstType = 787;
      inline constexpr uint32_t TerminationType = 788;
      inline constexpr uint32_t NextExpectedMsgSeqNum = 789;
      inline constexpr uint32_t OrdStatusReqID = 790;
      inline constexpr uint32_t SettlInstReqID = 791;
      inline constexpr uint32_t SettlInstReqRejCode = 792;
      inline constexpr uint32_t SecondaryAllocID = 793;
      inline constexpr uint32_t AllocReportType = 794;
      inline constexpr uint32_t AllocReportRefID = 795;
      inline constexpr uint32_t AllocCancReplaceReason = 796;
      inline constexpr uint32_t CopyMsgIndicator = 797;
      inline constexpr uint32_t AllocAccountType = 798;
      inline constexpr uint32_t OrderAvgPx = 799;
      inline constexpr uint32_t OrderBookingQty = 800;
      inline constexpr uint32_t NoSettlPartySubIDs = 801;
      inline constexpr uint32_t NoPartySubIDs = 802;
      inline constexpr uint32_t PartySubIDType = 803;
      inline constexpr uint32_t NoNestedPartySubIDs = 804;
      inline constexpr uint32_t NestedPartySubIDType = 805;
      inline constexpr uint32_t NoNested2PartySubIDs = 806;
      inline constexpr uint32_t Nested2PartySubIDType = 807;
      inline constexpr uint32_t AllocIntermedReqType = 808;
      inline constexpr uint32_t UnderlyingPx = 810;
      inline constexpr uint32_t PriceDelta = 811;
      inline constexpr uint32_t ApplQueueMax = 812;
      inline constexpr uint32_t ApplQueueDepth = 813;
      inline constexpr uint32_t ApplQueueResolution = 814;
      inline constexpr uint32_t ApplQueueAction = 815;
      inline constexpr uint32_t NoAltMDSource = 816;
      inline constexpr uint32_t AltMDSourceID = 817;
      inline constexpr uint32_t SecondaryTradeReportID = 818;
      inline constexpr uint32_t AvgPxIndicator = 819;
      inline constexpr uint32_t TradeLinkID = 820;
      inline constexpr uint32_t OrderInputDevice = 821;
      inline constexpr uint32_t UnderlyingTradingSessionID = 822;
      inline constexpr uint32_t UnderlyingTradingSessionSubID = 823;
      inline constexpr uint32_t TradeLegRefID = 824;
      inline constexpr uint32_t ExchangeRule = 825;
      inline constexpr uint32_t TradeAllocIndicator = 826;
      inline constexpr uint32_t ExpirationCycle = 827;
      inline constexpr uint32_t TrdType = 828;
      inline constexpr uint32_t TrdSubType = 829;
      inline constexpr uint32_t TransferReason = 830;
      inline constexpr uint32_t TotNumAssignmentReports = 832;
      inline constexpr uint32_t AsgnRptID = 833;
      inline constexpr uint32_t ThresholdAmount = 834;
      inline constexpr uint32_t PegMoveType = 835;
      inline constexpr uint32_t PegOffsetType = 836;
      inline constexpr uint32_t PegLimitType = 837;
      inline constexpr uint32_t PegRoundDirection = 838;
      inline constexpr uint32_t PeggedPrice = 839;
      inline constexpr uint32_t PegScope = 840;
      inline constexpr uint32_t DiscretionMoveType = 841;
      inline constexpr uint32_t DiscretionOffsetType = 842;
      inline constexpr uint32_t DiscretionLimitType = 843;
      inline constexpr uint32_t DiscretionRoundDirection = 844;
      inline constexpr uint32_t DiscretionPrice = 845;
      inline constexpr uint32_t DiscretionScope = 846;
      inline constexpr uint32_t TargetStrategy = 847;
      inline constexpr uint32_t TargetStrategyParameters = 848;
      inline constexpr uint32_t ParticipationRate = 849;
      inline constexpr uint32_t TargetStrategyPerformance = 850;
      inline constexpr uint32_t LastLiquidityInd = 851;
      inline constexpr uint32_t PublishTrdIndicator = 852;
      inline constexpr uint32_t ShortSaleReason = 853;
      inline constexpr uint32_t QtyType = 854;
      inline constexpr uint32_t SecondaryTrdType = 855;
      inline constexpr uint32_t TradeReportType = 856;
      inline constexpr uint32_t AllocNoOrdersType = 857;
      inline constexpr uint32_t SharedCommission = 858;
      inline constexpr uint32_t ConfirmReqID = 859;
      inline constexpr uint32_t AvgParPx = 860;
      inline constexpr uint32_t ReportedPx = 861;
      inline constexpr uint32_t NoCapacities = 862;
      inline constexpr uint32_t OrderCapacityQty = 863;
      inline constexpr uint32_t NoEvents = 864;
      inline constexpr uint32_t EventType = 865;
      inline constexpr uint32_t EventDate = 866;
      inline constexpr uint32_t EventPx = 867;
      inline constexpr uint32_t EventText = 868;
      inline constexpr uint32_t PctAtRisk = 869;
      inline constexpr uint32_t NoInstrAttrib = 870;
      inline constexpr uint32_t InstrAttribType = 871;
      inline constexpr uint32_t InstrAttribValue = 872;
      inline constexpr uint32_t DatedDate = 873;
      inline constexpr uint32_t InterestAccrualDate = 874;
      inline constexpr uint32_t CPProgram = 875;
      inline constexpr uint32_t CPRegType = 876;
      inline constexpr uint32_t UnderlyingCPProgram = 877;
      inline constexpr uint32_t UnderlyingCPRegType = 878;
      inline constexpr uint32_t UnderlyingQty = 879;
      inline constexpr uint32_t TrdMatchID = 880;
      inline constexpr uint32_t SecondaryTradeReportRefID = 881;
      inline constexpr uint32_t UnderlyingDirtyPrice = 882;
      inline constexpr uint32_t UnderlyingEndPrice = 883;
      inline constexpr uint32_t UnderlyingStartValue = 884;
      inline constexpr uint32_t UnderlyingCurrentValue = 885;
      inline constexpr uint32_t UnderlyingEndValue = 886;
      inline constexpr uint32_t NoUnderlyingStips = 887;
      inline constexpr uint32_t UnderlyingStipType = 888;
      inline constexpr uint32_t UnderlyingStipValue = 889;
      inline constexpr uint32_t MaturityNetMoney = 890;
      inline constexpr uint32_t MiscFeeBasis = 891;
      inline constexpr uint32_t TotNoAllocs = 892;
      inline constexpr uint32_t LastFragment = 893;
      inline constexpr uint32_t CollReqID = 894;
      inline constexpr uint32_t CollAsgnReason = 895;
      inline constexpr uint32_t CollInquiryQualifier = 896;
      inline constexpr uint32_t NoTrades = 897;
      inline constexpr uint32_t MarginRatio = 898;
      inline constexpr uint32_t MarginExcess = 899;
      inline constexpr uint32_t TotalNetValue = 900;
      inline constexpr uint32_t CashOutstanding = 901;
      inline constexpr uint32_t CollAsgnID = 902;
      inline constexpr uint32_t CollAsgnTransType = 903;
      inline constexpr uint32_t CollRespID = 904;
      inline constexpr uint32_t CollAsgnRespType = 905;
      inline constexpr uint32_t CollAsgnRejectReason = 906;
      inline constexpr uint32_t CollAsgnRefID = 907;
      inline constexpr uint32_t CollRptID = 908;
      inline constexpr uint32_t CollInquiryID = 909;
      inline constexpr uint32_t CollStatus = 910;
      inline constexpr uint32_t TotNumReports = 911;
      inline constexpr uint32_t LastRptRequested = 912;
      inline constexpr uint32_t AgreementDesc = 913;
      inline constexpr uint32_t AgreementID = 914;
      inline constexpr uint32_t AgreementDate = 915;
      inline constexpr uint32_t StartDate = 916;
      inline constexpr uint32_t EndDate = 917;
      inline constexpr uint32_t AgreementCurrency = 918;
      inline constexpr uint32_t DeliveryType = 919;
      inline constexpr uint32_t EndAccruedInterestAmt = 920;
      inline constexpr uint32_t StartCash = 921;
      inline constexpr uint32_t EndCash = 922;
      inline constexpr uint32_t UserRequestID = 923;
      inline constexpr uint32_t UserRequestType = 924;
      inline constexpr uint32_t NewPassword = 925;
      inline constexpr uint32_t UserStatus = 926;
      inline constexpr uint32_t UserStatusText = 927;
      inline constexpr uint32_t StatusValue = 928;
      inline constexpr uint32_t StatusText = 929;
      inline constexpr uint32_t RefCompID = 930;
      inline constexpr uint32_t RefSubID = 931;
      inline constexpr uint32_t NetworkResponseID = 932;
      inline constexpr uint32_t NetworkRequestID = 933;
      inline constexpr uint32_t LastNetworkResponseID = 934;
      inline constexpr uint32_t NetworkRequestType = 935;
      inline constexpr uint32_t NoCompIDs = 936;
      inline constexpr uint32_t NetworkStatusResponseType = 937;
      inline constexpr uint32_t NoCollInquiryQualifier = 938;
      inline constexpr uint32_t TrdRptStatus = 939;
      inline constexpr uint32_t AffirmStatus = 940;
      inline constexpr uint32_t UnderlyingStrikeCurrency = 941;
      inline constexpr uint32_t LegStrikeCurrency = 942;
      inline constexpr uint32_t TimeBracket = 943;
      inline constexpr uint32_t CollAction = 944;
      inline constexpr uint32_t CollInquiryStatus = 945;
      inline constexpr uint32_t CollInquiryResult = 946;
      inline constexpr uint32_t StrikeCurrency = 947;
      inline constexpr uint32_t NoNested3PartyIDs = 948;
      inline constexpr uint32_t Nested3PartyID = 949;
      inline constexpr uint32_t Nested3PartyIDSource = 950;
      inline constexpr uint32_t Nested3PartyRole = 951;
      inline constexpr uint32_t NoNested3PartySubIDs = 952;
      inline constexpr uint32_t Nested3PartySubID = 953;
      inline constexpr uint32_t Nested3PartySubIDType = 954;
      inline constexpr uint32_t LegContractSettlMonth = 955;
      inline constexpr uint32_t LegInterestAccrualDate = 956;
   }

   // AccountTypeCodeSet (int)
   enum class AccountType : int32_t {
      CarriedCustomerSide = 1,
      CarriedNonCustomerSide = 2,
      HouseTrader = 3,
      FloorTrader = 4,
      CarriedNonCustomerSideCrossMargined = 6,
      HouseTraderCrossMargined = 7,
      JointBackOfficeAccount = 8,
   };
   // AcctIDSourceCodeSet (int)
   enum class AcctIDSource : int32_t {
      BIC = 1,
      SIDCode = 2,
      TFM = 3,
      OMGEO = 4,
      DTCCCode = 5,
      Other = 99,
   };
   // AdjustmentCodeSet (int)
   enum class Adjustment : int32_t {
      Cancel = 1,
      Error = 2,
      Correction = 3,
   };
   // AdjustmentTypeCodeSet (int)
   enum class AdjustmentType : int32_t {
      ProcessRequestAsMarginDisposition = 0,
      DeltaPlus = 1,
      DeltaMinus = 2,
      Final = 3,
   };
   // AdvSideCodeSet (char)
   enum class AdvSide : char {
      Buy = 'B',
      Sell = 'S',
      Cross = 'X',
      Trade = 'T',
   };
   // AdvTransTypeCodeSet (String)
   enum class AdvTransType : uint16_t {
      New = 0,
      Cancel = 1,
      Replace = 2,
   };
   // AffirmStatusCodeSet (int)
   enum class AffirmStatus : int32_t {
      Received = 1,
      ConfirmRejected = 2,
      Affirmed = 3,
   };
   // AggregatedBookCodeSet (Boolean)
   enum class AggregatedBook : uint16_t {
      BookEntriesToBeAggregated = 0,
      BookEntriesShouldNotBeAggregated = 1,
   };
   // AllocAccountTypeCodeSet (int)
   enum class AllocAccountType : int32_t {
      CarriedCustomerSide = 1,
      CarriedNonCustomerSide = 2,
      HouseTrader = 3,
      FloorTrader = 4,
      CarriedNonCustomerSideCrossMargined = 6,
      HouseTraderCrossMargined = 7,
      JointBackOfficeAccount = 8,
   };
   // AllocCancReplaceReasonCodeSet (int)
   enum class AllocCancReplaceReason : int32_t {
      OriginalDetailsIncomplete = 1,
      ChangeInUnderlyingOrderDetails = 2,
      Other = 99,
   };
   // AllocHandlInstCodeSet (int)
   enum class AllocHandlInst : int32_t {
      Match = 1,
      Forward = 2,
      ForwardAndMatch = 3,
   };
   // AllocIntermedReqTypeCodeSet (int)
   enum class AllocIntermedReqType : int32_t {
      PendingAccept = 1,
      PendingRelease = 2,
      PendingReversal = 3,
      Accept = 4,
      BlockLevelReject = 5,
      AccountLevelReject = 6,
   };
   // AllocLinkTypeCodeSet (int)
   enum class AllocLinkType : int32_t {
      FXNetting = 0,
      FXSwap = 1,
   };
   // AllocNoOrdersTypeCodeSet (int)
   enum class AllocNoOrdersType : int32_t {
      NotSpecified = 0,
      ExplicitListProvided = 1,
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
      IncorrectAllocatedQuantity = 8,
      CalculationDifference = 9,
      UnknownOrStaleExecID = 10,
      MismatchedData = 11,
      UnknownClOrdID = 12,
      WarehouseRequestRejected = 13,
   };
   // AllocReportTypeCodeSet (int)
   enum class AllocReportType : int32_t {
      SellsideCalculatedUsingPreliminary = 3,
      SellsideCalculatedWithoutPreliminary = 4,
      WarehouseRecap = 5,
      RequestToIntermediary = 8,
   };
   // AllocSettlInstTypeCodeSet (int)
   enum class AllocSettlInstType : int32_t {
      UseDefaultInstructions = 0,
      DeriveFromParametersProvided = 1,
      FullDetailsProvided = 2,
      SSIDBIDsProvided = 3,
      PhoneForInstructions = 4,
   };
   // AllocStatusCodeSet (int)
   enum class AllocStatus : int32_t {
      Accepted = 0,
      BlockLevelReject = 1,
      AccountLevelReject = 2,
      Received = 3,
      Incomplete = 4,
      RejectedByIntermediary = 5,
   };
   // AllocTransTypeCodeSet (char)
   enum class AllocTransType : char {
      New = '0',
      Replace = '1',
      Cancel = '2',
   };
   // AllocTypeCodeSet (int)
   enum class AllocType : int32_t {
      Calculated = 1,
      Preliminary = 2,
      ReadyToBook = 5,
      WarehouseInstruction = 7,
      RequestToIntermediary = 8,
   };
   // ApplQueueActionCodeSet (int)
   enum class ApplQueueAction : int32_t {
      NoActionTaken = 0,
      QueueFlushed = 1,
      OverlayLast = 2,
      EndSession = 3,
   };
   // ApplQueueResolutionCodeSet (int)
   enum class ApplQueueResolution : int32_t {
      NoActionTaken = 0,
      QueueFlushed = 1,
      OverlayLast = 2,
      EndSession = 3,
   };
   // AssignmentMethodCodeSet (char)
   enum class AssignmentMethod : char {
      Random = 'R',
      ProRata = 'P',
   };
   // AvgPxIndicatorCodeSet (int)
   enum class AvgPxIndicator : int32_t {
      NoAveragePricing = 0,
      Trade = 1,
      LastTrade = 2,
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
   // BenchmarkCurveNameCodeSet (String)
   enum class BenchmarkCurveName : uint16_t {
      EONIA = 0,
      EUREPO = 1,
      Euribor = 2,
      FutureSWAP = 3,
      LIBID = 4,
      LIBOR = 5,
      MuniAAA = 6,
      OTHER = 7,
      Pfandbriefe = 8,
      SONIA = 9,
      SWAP = 10,
      Treasury = 11,
   };
   // BidDescriptorTypeCodeSet (int)
   enum class BidDescriptorType : int32_t {
      Sector = 1,
      Country = 2,
      Index = 3,
   };
   // BidRequestTransTypeCodeSet (char)
   enum class BidRequestTransType : char {
      New = 'N',
      Cancel = 'C',
   };
   // BidTradeTypeCodeSet (char)
   enum class BidTradeType : char {
      RiskTrade = 'R',
      VWAPGuarantee = 'G',
      Agency = 'A',
      GuaranteedClose = 'J',
   };
   // BidTypeCodeSet (int)
   enum class BidType : int32_t {
      NonDisclosed = 1,
      Disclosed = 2,
      NoBiddingProcess = 3,
   };
   // BookingTypeCodeSet (int)
   enum class BookingType : int32_t {
      RegularBooking = 0,
      CFD = 1,
      TotalReturnSwap = 2,
   };
   // BookingUnitCodeSet (char)
   enum class BookingUnit : char {
      EachPartialExecutionIsABookableUnit = '0',
      AggregatePartialExecutionsOnThisOrder = '1',
      AggregateExecutionsForThisSymbol = '2',
   };
   // BusinessRejectReasonCodeSet (int)
   enum class BusinessRejectReason : int32_t {
      Other = 0,
      UnknownID = 1,
      UnknownSecurity = 2,
      UnsupportedMessageType = 3,
      ApplicationNotAvailable = 4,
      ConditionallyRequiredFieldMissing = 5,
      NotAuthorized = 6,
      DeliverToFirmNotAvailableAtThisTime = 7,
   };
   // CPProgramCodeSet (int)
   enum class CPProgram : int32_t {
      Program3a3 = 1,
      Program42 = 2,
      Other = 99,
   };
   // CancellationRightsCodeSet (char)
   enum class CancellationRights : char {
      Yes = 'Y',
      NoExecutionOnly = 'N',
      NoWaiverAgreement = 'M',
      NoInstitutional = 'O',
   };
   // CashMarginCodeSet (char)
   enum class CashMargin : char {
      Cash = '1',
      MarginOpen = '2',
      MarginClose = '3',
   };
   // ClearingFeeIndicatorCodeSet (String)
   enum class ClearingFeeIndicator : uint16_t {
      CBOEMember = 0,
      NonMemberAndCustomer = 1,
      EquityMemberAndClearingMember = 2,
      FullAndAssociateMember = 3,
      Firms106HAnd106J = 4,
      GIM = 5,
      Lessee106FEmployees = 6,
      AllOtherOwnershipTypes = 7,
      FirstYearDelegate = 8,
      SecondYearDelegate = 9,
      ThirdYearDelegate = 10,
      FourthYearDelegate = 11,
      FifthYearDelegate = 12,
      SixthYearDelegate = 13,
   };
   // ClearingInstructionCodeSet (int)
   enum class ClearingInstruction : int32_t {
      ProcessNormally = 0,
      ExcludeFromAllNetting = 1,
      BilateralNettingOnly = 2,
      ExClearing = 3,
      SpecialTrade = 4,
      MultilateralNetting = 5,
      ClearAgainstCentralCounterparty = 6,
      ExcludeFromCentralCounterparty = 7,
      ManualMode = 8,
      AutomaticPostingMode = 9,
      AutomaticGiveUpMode = 10,
      QualifiedServiceRepresentativeQSR = 11,
      CustomerTrade = 12,
      SelfClearing = 13,
   };
   // CollActionCodeSet (int)
   enum class CollAction : int32_t {
      Retain = 0,
      Add = 1,
      Remove = 2,
   };
   // CollAsgnReasonCodeSet (int)
   enum class CollAsgnReason : int32_t {
      Initial = 0,
      Scheduled = 1,
      TimeWarning = 2,
      MarginDeficiency = 3,
      MarginExcess = 4,
      ForwardCollateralDemand = 5,
      EventOfDefault = 6,
      AdverseTaxEvent = 7,
   };
   // CollAsgnRejectReasonCodeSet (int)
   enum class CollAsgnRejectReason : int32_t {
      UnknownDeal = 0,
      UnknownOrInvalidInstrument = 1,
      UnauthorizedTransaction = 2,
      InsufficientCollateral = 3,
      InvalidTypeOfCollateral = 4,
      ExcessiveSubstitution = 5,
      Other = 99,
   };
   // CollAsgnRespTypeCodeSet (int)
   enum class CollAsgnRespType : int32_t {
      Received = 0,
      Accepted = 1,
      Declined = 2,
      Rejected = 3,
   };
   // CollAsgnTransTypeCodeSet (int)
   enum class CollAsgnTransType : int32_t {
      New = 0,
      Replace = 1,
      Cancel = 2,
      Release = 3,
      Reverse = 4,
   };
   // CollInquiryQualifierCodeSet (int)
   enum class CollInquiryQualifier : int32_t {
      TradeDate = 0,
      GCInstrument = 1,
      CollateralInstrument = 2,
      SubstitutionEligible = 3,
      NotAssigned = 4,
      PartiallyAssigned = 5,
      FullyAssigned = 6,
      OutstandingTrades = 7,
   };
   // CollInquiryResultCodeSet (int)
   enum class CollInquiryResult : int32_t {
      Successful = 0,
      InvalidOrUnknownInstrument = 1,
      InvalidOrUnknownCollateralType = 2,
      InvalidParties = 3,
      InvalidTransportTypeRequested = 4,
      InvalidDestinationRequested = 5,
      NoCollateralFoundForTheTradeSpecified = 6,
      NoCollateralFoundForTheOrderSpecified = 7,
      CollateralInquiryTypeNotSupported = 8,
      UnauthorizedForCollateralInquiry = 9,
      Other = 99,
   };
   // CollInquiryStatusCodeSet (int)
   enum class CollInquiryStatus : int32_t {
      Accepted = 0,
      AcceptedWithWarnings = 1,
      Completed = 2,
      CompletedWithWarnings = 3,
      Rejected = 4,
   };
   // CollStatusCodeSet (int)
   enum class CollStatus : int32_t {
      Unassigned = 0,
      PartiallyAssigned = 1,
      AssignmentProposed = 2,
      Assigned = 3,
      Challenged = 4,
   };
   // CommTypeCodeSet (char)
   enum class CommType : char {
      PerUnit = '1',
      Percent = '2',
      Absolute = '3',
      PercentageWaivedCashDiscount = '4',
      PercentageWaivedEnhancedUnits = '5',
      PointsPerBondOrContract = '6',
   };
   // ConfirmRejReasonCodeSet (int)
   enum class ConfirmRejReason : int32_t {
      MismatchedAccount = 1,
      MissingSettlementInstructions = 2,
      Other = 99,
   };
   // ConfirmStatusCodeSet (int)
   enum class ConfirmStatus : int32_t {
      Received = 1,
      MismatchedAccount = 2,
      MissingSettlementInstructions = 3,
      Confirmed = 4,
      RequestRejected = 5,
   };
   // ConfirmTransTypeCodeSet (int)
   enum class ConfirmTransType : int32_t {
      New = 0,
      Replace = 1,
      Cancel = 2,
   };
   // ConfirmTypeCodeSet (int)
   enum class ConfirmType : int32_t {
      Status = 1,
      Confirmation = 2,
      ConfirmationRequestRejected = 3,
   };
   // ContAmtTypeCodeSet (int)
   enum class ContAmtType : int32_t {
      CommissionAmount = 1,
      CommissionPercent = 2,
      InitialChargeAmount = 3,
      InitialChargePercent = 4,
      DiscountAmount = 5,
      DiscountPercent = 6,
      DilutionLevyAmount = 7,
      DilutionLevyPercent = 8,
      ExitChargeAmount = 9,
      ExitChargePercent = 10,
      FundBasedRenewalCommissionPercent = 11,
      ProjectedFundValue = 12,
      FundBasedRenewalCommissionOnOrder = 13,
      FundBasedRenewalCommissionOnFund = 14,
      NetSettlementAmount = 15,
   };
   // CorporateActionCodeSet (MultipleValueString)
   enum class CorporateAction : uint16_t {
      ExDividend = 0,
      ExDistribution = 1,
      ExRights = 2,
      New = 3,
      ExInterest = 4,
   };
   // CoveredOrUncoveredCodeSet (int)
   enum class CoveredOrUncovered : int32_t {
      Covered = 0,
      Uncovered = 1,
   };
   // CrossPrioritizationCodeSet (int)
   enum class CrossPrioritization : int32_t {
      None = 0,
      BuySideIsPrioritized = 1,
      SellSideIsPrioritized = 2,
   };
   // CrossTypeCodeSet (int)
   enum class CrossType : int32_t {
      CrossAON = 1,
      CrossIOC = 2,
      CrossOneSide = 3,
      CrossSamePrice = 4,
   };
   // CustOrderCapacityCodeSet (int)
   enum class CustOrderCapacity : int32_t {
      MemberTradingForTheirOwnAccount = 1,
      ClearingFirmTradingForItsProprietaryAccount = 2,
      MemberTradingForAnotherMember = 3,
      AllOther = 4,
   };
   // CxlRejReasonCodeSet (int)
   enum class CxlRejReason : int32_t {
      TooLateToCancel = 0,
      UnknownOrder = 1,
      BrokerCredit = 2,
      OrderAlreadyInPendingStatus = 3,
      UnableToProcessOrderMassCancelRequest = 4,
      OrigOrdModTime = 5,
      DuplicateClOrdID = 6,
      Other = 99,
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
      CalculationDifference = 'F',
      Other = 'Z',
   };
   // DayBookingInstCodeSet (char)
   enum class DayBookingInst : char {
      Auto = '0',
      SpeakWithOrderInitiatorBeforeBooking = '1',
      Accumulate = '2',
   };
   // DeleteReasonCodeSet (char)
   enum class DeleteReason : char {
      Cancellation = '0',
      Error = '1',
   };
   // DeliveryFormCodeSet (int)
   enum class DeliveryForm : int32_t {
      BookEntry = 1,
      Bearer = 2,
   };
   // DeliveryTypeCodeSet (int)
   enum class DeliveryType : int32_t {
      VersusPayment = 0,
      Free = 1,
      TriParty = 2,
      HoldInCustody = 3,
   };
   // DiscretionInstCodeSet (char)
   enum class DiscretionInst : char {
      RelatedToDisplayedPrice = '0',
      RelatedToMarketPrice = '1',
      RelatedToPrimaryPrice = '2',
      RelatedToLocalPrimaryPrice = '3',
      RelatedToMidpointPrice = '4',
      RelatedToLastTradePrice = '5',
      RelatedToVWAP = '6',
   };
   // DiscretionLimitTypeCodeSet (int)
   enum class DiscretionLimitType : int32_t {
      OrBetter = 0,
      Strict = 1,
      OrWorse = 2,
   };
   // DiscretionMoveTypeCodeSet (int)
   enum class DiscretionMoveType : int32_t {
      Floating = 0,
      Fixed = 1,
   };
   // DiscretionOffsetTypeCodeSet (int)
   enum class DiscretionOffsetType : int32_t {
      Price = 0,
      BasisPoints = 1,
      Ticks = 2,
      PriceTier = 3,
   };
   // DiscretionRoundDirectionCodeSet (int)
   enum class DiscretionRoundDirection : int32_t {
      MoreAggressive = 1,
      MorePassive = 2,
   };
   // DiscretionScopeCodeSet (int)
   enum class DiscretionScope : int32_t {
      Local = 1,
      National = 2,
      Global = 3,
      NationalExcludingLocal = 4,
   };
   // DistribPaymentMethodCodeSet (int)
   enum class DistribPaymentMethod : int32_t {
      CREST = 1,
      NSCC = 2,
      Euroclear = 3,
      Clearstream = 4,
      Cheque = 5,
      TelegraphicTransfer = 6,
      FedWire = 7,
      DirectCredit = 8,
      ACHCredit = 9,
      BPAY = 10,
      HighValueClearingSystemHVACS = 11,
      ReinvestInFund = 12,
   };
   // DlvyInstTypeCodeSet (char)
   enum class DlvyInstType : char {
      Securities = 'S',
      Cash = 'C',
   };
   // DueToRelatedCodeSet (Boolean)
   enum class DueToRelated : uint16_t {
      RelatedToSecurityHalt = 0,
      NotRelatedToSecurityHalt = 1,
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
   // EventTypeCodeSet (int)
   enum class EventType : int32_t {
      Put = 1,
      Call = 2,
      Tender = 3,
      SinkingFundCall = 4,
      Other = 99,
   };
   // ExchangeForPhysicalCodeSet (Boolean)
   enum class ExchangeForPhysical : uint16_t {
      True = 0,
      False = 1,
   };
   // ExecInstCodeSet (MultipleValueString)
   enum class ExecInst : uint16_t {
      NotHeld = 0,
      Work = 1,
      GoAlong = 2,
      OverTheDay = 3,
      Held = 4,
      ParticipateDoNotInitiate = 5,
      StrictScale = 6,
      TryToScale = 7,
      StayOnBidSide = 8,
      StayOnOfferSide = 9,
      NoCross = 10,
      OKToCross = 11,
      CallFirst = 12,
      PercentOfVolume = 13,
      DoNotIncrease = 14,
      DoNotReduce = 15,
      AllOrNone = 16,
      ReinstateOnSystemFailure = 17,
      InstitutionsOnly = 18,
      ReinstateOnTradingHalt = 19,
      CancelOnTradingHalt = 20,
      LastPeg = 21,
      MidPricePeg = 22,
      NonNegotiable = 23,
      OpeningPeg = 24,
      MarketPeg = 25,
      CancelOnSystemFailure = 26,
      PrimaryPeg = 27,
      Suspend = 28,
      FixedPegToLocalBestBidOrOfferAtTimeOfOrder = 29,
      CustomerDisplayInstruction = 30,
      Netting = 31,
      PegToVWAP = 32,
      TradeAlong = 33,
      TryToStop = 34,
      CancelIfNotBest = 35,
      TrailingStopPeg = 36,
      StrictLimit = 37,
      IgnorePriceValidityChecks = 38,
      PegToLimitPrice = 39,
      WorkToTargetStrategy = 40,
   };
   // ExecPriceTypeCodeSet (char)
   enum class ExecPriceType : char {
      BidPrice = 'B',
      CreationPrice = 'C',
      CreationPricePlusAdjustmentPercent = 'D',
      CreationPricePlusAdjustmentAmount = 'E',
      OfferPrice = 'O',
      OfferPriceMinusAdjustmentPercent = 'P',
      OfferPriceMinusAdjustmentAmount = 'Q',
      SinglePrice = 'S',
   };
   // ExecRestatementReasonCodeSet (int)
   enum class ExecRestatementReason : int32_t {
      GTCorporateAction = 0,
      GTRenewal = 1,
      VerbalChange = 2,
      RepricingOfOrder = 3,
      BrokerOption = 4,
      PartialDeclineOfOrderQty = 5,
      CancelOnTradingHalt = 6,
      CancelOnSystemFailure = 7,
      Market = 8,
      Canceled = 9,
      WarehouseRecap = 10,
      Other = 99,
   };
   // ExecTypeCodeSet (char)
   enum class ExecType : char {
      New = '0',
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
      Trade = 'F',
      TradeCorrect = 'G',
      TradeCancel = 'H',
      OrderStatus = 'I',
   };
   // ExerciseMethodCodeSet (char)
   enum class ExerciseMethod : char {
      Automatic = 'A',
      Manual = 'M',
   };
   // ExpirationCycleCodeSet (int)
   enum class ExpirationCycle : int32_t {
      ExpireOnTradingSessionClose = 0,
      ExpireOnTradingSessionOpen = 1,
   };
   // FinancialStatusCodeSet (MultipleValueString)
   enum class FinancialStatus : uint16_t {
      Bankrupt = 0,
      PendingDelisting = 1,
   };
   // ForexReqCodeSet (Boolean)
   enum class ForexReq : uint16_t {
      ExecuteForexAfterSecurityTrade = 0,
      DoNotExecuteForexAfterSecurityTrade = 1,
   };
   // FundRenewWaivCodeSet (char)
   enum class FundRenewWaiv : char {
      Yes = 'Y',
      No = 'N',
   };
   // GTBookingInstCodeSet (int)
   enum class GTBookingInst : int32_t {
      BookOutAllTradesOnDayOfExecution = 0,
      AccumulateUntilFilledOrExpired = 1,
      AccumulateUntilVerballlyNotifiedOtherwise = 2,
   };
   // GapFillFlagCodeSet (Boolean)
   enum class GapFillFlag : uint16_t {
      GapFillMessage = 0,
      SequenceReset = 1,
   };
   // HaltReasonCodeSet (char)
   enum class HaltReason : char {
      OrderImbalance = 'I',
      EquipmentChangeover = 'X',
      NewsPending = 'P',
      NewsDissemination = 'D',
      OrderInflux = 'E',
      AdditionalInformation = 'M',
   };
   // HandlInstCodeSet (char)
   enum class HandlInst : char {
      AutomatedExecutionNoIntervention = '1',
      AutomatedExecutionInterventionOK = '2',
      ManualOrder = '3',
   };
   // IOINaturalFlagCodeSet (Boolean)
   enum class IOINaturalFlag : uint16_t {
      Natural = 0,
      NotNatural = 1,
   };
   // IOIQltyIndCodeSet (char)
   enum class IOIQltyInd : char {
      Low = 'L',
      Medium = 'M',
      High = 'H',
   };
   // IOIQtyCodeSet (String)
   enum class IOIQty : uint16_t {
      Small = 0,
      Medium = 1,
      Large = 2,
   };
   // IOIQualifierCodeSet (char)
   enum class IOIQualifier : char {
      AllOrNone = 'A',
      MarketOnClose = 'B',
      AtTheClose = 'C',
      VWAP = 'D',
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
   // IOITransTypeCodeSet (char)
   enum class IOITransType : char {
      New = 'N',
      Cancel = 'C',
      Replace = 'R',
   };
   // InViewOfCommonCodeSet (Boolean)
   enum class InViewOfCommon : uint16_t {
      HaltWasDueToCommonStockBeingHalted = 0,
      HaltWasNotRelatedToAHaltOfTheCommonStock = 1,
   };
   // IncTaxIndCodeSet (int)
   enum class IncTaxInd : int32_t {
      Net = 1,
      Gross = 2,
   };
   // InstrAttribTypeCodeSet (int)
   enum class InstrAttribType : int32_t {
      Flat = 1,
      ZeroCoupon = 2,
      InterestBearing = 3,
      NoPeriodicPayments = 4,
      VariableRate = 5,
      LessFeeForPut = 6,
      SteppedCoupon = 7,
      CouponPeriod = 8,
      When = 9,
      OriginalIssueDiscount = 10,
      Callable = 11,
      EscrowedToMaturity = 12,
      EscrowedToRedemptionDate = 13,
      PreRefunded = 14,
      InDefault = 15,
      Unrated = 16,
      Taxable = 17,
      Indexed = 18,
      SubjectToAlternativeMinimumTax = 19,
      OriginalIssueDiscountPrice = 20,
      CallableBelowMaturityValue = 21,
      CallableWithoutNotice = 22,
      Text = 99,
   };
   // LastCapacityCodeSet (char)
   enum class LastCapacity : char {
      Agent = '1',
      CrossAsAgent = '2',
      CrossAsPrincipal = '3',
      Principal = '4',
   };
   // LastFragmentCodeSet (Boolean)
   enum class LastFragment : uint16_t {
      LastMessage = 0,
      NotLastMessage = 1,
   };
   // LastLiquidityIndCodeSet (int)
   enum class LastLiquidityInd : int32_t {
      AddedLiquidity = 1,
      RemovedLiquidity = 2,
      LiquidityRoutedOut = 3,
   };
   // LegSwapTypeCodeSet (int)
   enum class LegSwapType : int32_t {
      ParForPar = 1,
      ModifiedDuration = 2,
      Risk = 4,
      Proceeds = 5,
   };
   // LegalConfirmCodeSet (Boolean)
   enum class LegalConfirm : uint16_t {
      LegalConfirm = 0,
      DoesNotConsituteALegalConfirm = 1,
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
      SellDriven = '3',
      BuyDrivenCashTopUp = '4',
      BuyDrivenCashWithdraw = '5',
   };
   // ListOrderStatusCodeSet (int)
   enum class ListOrderStatus : int32_t {
      InBiddingProcess = 1,
      ReceivedForExecution = 2,
      Executing = 3,
      Cancelling = 4,
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
      Yes = 0,
      No = 1,
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
      Imbalance = 'A',
      TradeVolume = 'B',
      OpenInterest = 'C',
   };
   // MDImplicitDeleteCodeSet (Boolean)
   enum class MDImplicitDelete : uint16_t {
      Yes = 0,
      No = 1,
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
      UnsupportedTradingSessionID = '9',
      UnsupportedScope = 'A',
      UnsupportedOpenCloseSettleFlag = 'B',
      UnsupportedMDImplicitDelete = 'C',
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
   // MassCancelRejectReasonCodeSet (int)
   enum class MassCancelRejectReason : int32_t {
      MassCancelNotSupported = 0,
      InvalidOrUnknownSecurity = 1,
      InvalidOrUnkownUnderlyingSecurity = 2,
      InvalidOrUnknownProduct = 3,
      InvalidOrUnknownCFICode = 4,
      InvalidOrUnknownSecurityType = 5,
      InvalidOrUnknownTradingSession = 6,
      Other = 99,
   };
   // MassCancelRequestTypeCodeSet (char)
   enum class MassCancelRequestType : char {
      CancelOrdersForASecurity = '1',
      CancelOrdersForAnUnderlyingSecurity = '2',
      CancelOrdersForAProduct = '3',
      CancelOrdersForACFICode = '4',
      CancelOrdersForASecurityType = '5',
      CancelOrdersForATradingSession = '6',
      CancelAllOrders = '7',
   };
   // MassCancelResponseCodeSet (char)
   enum class MassCancelResponse : char {
      CancelRequestRejected = '0',
      CancelOrdersForASecurity = '1',
      CancelOrdersForAnUnderlyingSecurity = '2',
      CancelOrdersForAProduct = '3',
      CancelOrdersForACFICode = '4',
      CancelOrdersForASecurityType = '5',
      CancelOrdersForATradingSession = '6',
      CancelAllOrders = '7',
   };
   // MassStatusReqTypeCodeSet (int)
   enum class MassStatusReqType : int32_t {
      StatusForOrdersForASecurity = 1,
      StatusForOrdersForAnUnderlyingSecurity = 2,
      StatusForOrdersForAProduct = 3,
      StatusForOrdersForACFICode = 4,
      StatusForOrdersForASecurityType = 5,
      StatusForOrdersForATradingSession = 6,
      StatusForAllOrders = 7,
      StatusForOrdersForAPartyID = 8,
   };
   // MatchStatusCodeSet (char)
   enum class MatchStatus : char {
      Compared = '0',
      Uncompared = '1',
      AdvisoryOrAlert = '2',
   };
   // MatchTypeCodeSet (String)
   enum class MatchType : uint16_t {
      ExactMatchPlus4BadgesExecTime = 0,
      ExactMatchPlus4Badges = 1,
      ExactMatchPlus2BadgesExecTime = 2,
      ExactMatchPlus2Badges = 3,
      ExactMatchPlusExecTime = 4,
      StampedAdvisoriesOrSpecialistAccepts = 5,
      A1ExactMatchSummarizedQuantity = 6,
      A2ExactMatchSummarizedQuantity = 7,
      A3ExactMatchSummarizedQuantity = 8,
      A4ExactMatchSummarizedQuantity = 9,
      A5ExactMatchSummarizedQuantity = 10,
      ExactMatchMinusBadgesTimes = 11,
      SummarizedMatchMinusBadgesTimes = 12,
      OCSLockedIn = 13,
      ACTAcceptedTrade = 14,
      ACTDefaultTrade = 15,
      ACTDefaultAfterM2 = 16,
      ACTM6Match = 17,
   };
   // MessageEncodingCodeSet (String)
   enum class MessageEncoding : uint16_t {
      ISO2022JP = 0,
      EUCJP = 1,
      ShiftJIS = 2,
      UTF8 = 3,
   };
   // MiscFeeBasisCodeSet (int)
   enum class MiscFeeBasis : int32_t {
      Absolute = 0,
      PerUnit = 1,
      Percentage = 2,
   };
   // MiscFeeTypeCodeSet (String)
   enum class MiscFeeType : uint16_t {
      Regulatory = 0,
      Tax = 1,
      LocalCommission = 2,
      ExchangeFees = 3,
      Stamp = 4,
      Levy = 5,
      Other = 6,
      Markup = 7,
      ConsumptionTax = 8,
      PerTransaction = 9,
      Conversion = 10,
      Agent = 11,
   };
   // MoneyLaunderingStatusCodeSet (char)
   enum class MoneyLaunderingStatus : char {
      Passed = 'Y',
      NotChecked = 'N',
      ExemptBelowLimit = '1',
      ExemptMoneyType = '2',
      ExemptAuthorised = '3',
   };
   // MsgDirectionCodeSet (char)
   enum class MsgDirection : char {
      Send = 'S',
      Receive = 'R',
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
      AllocationInstruction = 18,
      ListCancelRequest = 19,
      ListExecute = 20,
      ListStatusRequest = 21,
      ListStatus = 22,
      AllocationInstructionAck = 23,
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
      MassQuoteAcknowledgement = 34,
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
      XMLNonFIX = 46,
      RegistrationInstructions = 47,
      RegistrationInstructionsResponse = 48,
      OrderMassCancelRequest = 49,
      OrderMassCancelReport = 50,
      NewOrderCross = 51,
      CrossOrderCancelReplaceRequest = 52,
      CrossOrderCancelRequest = 53,
      SecurityTypeRequest = 54,
      SecurityTypes = 55,
      SecurityListRequest = 56,
      SecurityList = 57,
      DerivativeSecurityListRequest = 58,
      DerivativeSecurityList = 59,
      NewOrderMultileg = 60,
      MultilegOrderCancelReplace = 61,
      TradeCaptureReportRequest = 62,
      TradeCaptureReport = 63,
      OrderMassStatusRequest = 64,
      QuoteRequestReject = 65,
      RFQRequest = 66,
      QuoteStatusReport = 67,
      QuoteResponse = 68,
      Confirmation = 69,
      PositionMaintenanceRequest = 70,
      PositionMaintenanceReport = 71,
      RequestForPositions = 72,
      RequestForPositionsAck = 73,
      PositionReport = 74,
      TradeCaptureReportRequestAck = 75,
      TradeCaptureReportAck = 76,
      AllocationReport = 77,
      AllocationReportAck = 78,
      ConfirmationAck = 79,
      SettlementInstructionRequest = 80,
      AssignmentReport = 81,
      CollateralRequest = 82,
      CollateralAssignment = 83,
      CollateralResponse = 84,
      CollateralReport = 85,
      CollateralInquiry = 86,
      NetworkCounterpartySystemStatusRequest = 87,
      NetworkCounterpartySystemStatusResponse = 88,
      UserRequest = 89,
      UserResponse = 90,
      CollateralInquiryAck = 91,
      ConfirmationRequest = 92,
   };
   // MultiLegReportingTypeCodeSet (char)
   enum class MultiLegReportingType : char {
      SingleSecurity = '1',
      IndividualLegOfAMultiLegSecurity = '2',
      MultiLegSecurity = '3',
   };
   // MultiLegRptTypeReqCodeSet (int)
   enum class MultiLegRptTypeReq : int32_t {
      ReportByMulitlegSecurityOnly = 0,
      ReportByMultilegSecurityAndInstrumentLegs = 1,
      ReportByInstrumentLegsOnly = 2,
   };
   // NetGrossIndCodeSet (int)
   enum class NetGrossInd : int32_t {
      Net = 1,
      Gross = 2,
   };
   // NetworkRequestTypeCodeSet (int)
   enum class NetworkRequestType : int32_t {
      Snapshot = 1,
      Subscribe = 2,
      StopSubscribing = 4,
      LevelOfDetail = 8,
   };
   // NetworkStatusResponseTypeCodeSet (int)
   enum class NetworkStatusResponseType : int32_t {
      Full = 1,
      IncrementalUpdate = 2,
   };
   // NoSidesCodeSet (NumInGroup)
   enum class NoSides : int32_t {
      OneSide = 1,
      BothSides = 2,
   };
   // NotifyBrokerOfCreditCodeSet (Boolean)
   enum class NotifyBrokerOfCredit : uint16_t {
      DetailsShouldBeCommunicated = 0,
      DetailsShouldNotBeCommunicated = 1,
   };
   // OddLotCodeSet (Boolean)
   enum class OddLot : uint16_t {
      TreatAsOddLot = 0,
      TreatAsRoundLot = 1,
   };
   // OpenCloseSettlFlagCodeSet (MultipleValueString)
   enum class OpenCloseSettlFlag : uint16_t {
      DailyOpen = 0,
      SessionOpen = 1,
      DeliverySettlementEntry = 2,
      ExpectedEntry = 3,
      EntryFromPreviousBusinessDay = 4,
      TheoreticalPriceValue = 5,
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
      TradeAlongRequired = 9,
      InvalidInvestorID = 10,
      UnsupportedOrderCharacteristic = 11,
      SurveillanceOption = 12,
      IncorrectQuantity = 13,
      IncorrectAllocatedQuantity = 14,
      UnknownAccount = 15,
      Other = 99,
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
      WithOrWithout = '6',
      LimitOrBetter = '7',
      LimitWithOrWithout = '8',
      OnBasis = '9',
      PreviouslyQuoted = 'D',
      PreviouslyIndicated = 'E',
      ForexSwap = 'G',
      Funari = 'I',
      MarketIfTouched = 'J',
      MarketWithLeftOverAsLimit = 'K',
      PreviousFundValuationPoint = 'L',
      NextFundValuationPoint = 'M',
      Pegged = 'P',
   };
   // OrderCapacityCodeSet (char)
   enum class OrderCapacity : char {
      Agency = 'A',
      Proprietary = 'G',
      Individual = 'I',
      Principal = 'P',
      RisklessPrincipal = 'R',
      AgentForOtherMember = 'W',
   };
   // OrderRestrictionsCodeSet (MultipleValueString)
   enum class OrderRestrictions : uint16_t {
      ProgramTrade = 0,
      IndexArbitrage = 1,
      NonIndexArbitrage = 2,
      CompetingMarketMaker = 3,
      ActingAsMarketMakerOrSpecialistInSecurity = 4,
      ActingAsMarketMakerOrSpecialistInUnderlying = 5,
      ForeignEntity = 6,
      ExternalMarketParticipant = 7,
      ExternalInterConnectedMarketLinkage = 8,
      RisklessArbitrage = 9,
   };
   // OwnerTypeCodeSet (int)
   enum class OwnerType : int32_t {
      IndividualInvestor = 1,
      PublicCompany = 2,
      PrivateCompany = 3,
      IndividualTrustee = 4,
      CompanyTrustee = 5,
      PensionPlan = 6,
      CustodianUnderGiftsToMinorsAct = 7,
      Trusts = 8,
      Fiduciaries = 9,
      NetworkingSubAccount = 10,
      NonProfitOrganization = 11,
      CorporateBody = 12,
      Nominee = 13,
   };
   // OwnershipTypeCodeSet (char)
   enum class OwnershipType : char {
      JointInvestors = 'J',
      TenantsInCommon = 'T',
      JointTrustees = '2',
   };
   // PartyIDSourceCodeSet (char)
   enum class PartyIDSource : char {
      BIC = 'B',
      GeneralIdentifier = 'C',
      Proprietary = 'D',
      ISOCountryCode = 'E',
      SettlementEntityLocation = 'F',
      MIC = 'G',
      CSDParticipant = 'H',
      KoreanInvestorID = '1',
      TaiwaneseForeignInvestorID = '2',
      TaiwaneseTradingAcct = '3',
      MalaysianCentralDepository = '4',
      ChineseInvestorID = '5',
      UKNationalInsuranceOrPensionNumber = '6',
      USSocialSecurityNumber = '7',
      USEmployerOrTaxIDNumber = '8',
      AustralianBusinessNumber = '9',
      AustralianTaxFileNumber = 'A',
      ISITCAcronym = 'I',
   };
   // PartyRoleCodeSet (int)
   enum class PartyRole : int32_t {
      ExecutingFirm = 1,
      BrokerOfCredit = 2,
      ClientID = 3,
      ClearingFirm = 4,
      InvestorID = 5,
      IntroducingFirm = 6,
      EnteringFirm = 7,
      Locate = 8,
      FundManagerClientID = 9,
      SettlementLocation = 10,
      OrderOriginationTrader = 11,
      ExecutingTrader = 12,
      OrderOriginationFirm = 13,
      GiveupClearingFirm = 14,
      CorrespondantClearingFirm = 15,
      ExecutingSystem = 16,
      ContraFirm = 17,
      ContraClearingFirm = 18,
      SponsoringFirm = 19,
      UnderlyingContraFirm = 20,
      ClearingOrganization = 21,
      Exchange = 22,
      CustomerAccount = 24,
      CorrespondentClearingOrganization = 25,
      CorrespondentBroker = 26,
      Buyer = 27,
      Custodian = 28,
      Intermediary = 29,
      Agent = 30,
      SubCustodian = 31,
      Beneficiary = 32,
      InterestedParty = 33,
      RegulatoryBody = 34,
      LiquidityProvider = 35,
      EnteringTrader = 36,
      ContraTrader = 37,
      PositionAccount = 38,
   };
   // PartySubIDTypeCodeSet (int)
   enum class PartySubIDType : int32_t {
      Firm = 1,
      Person = 2,
      System = 3,
      Application = 4,
      FullLegalNameOfFirm = 5,
      PostalAddress = 6,
      PhoneNumber = 7,
      EmailAddress = 8,
      ContactName = 9,
      SecuritiesAccountNumber = 10,
      RegistrationNumber = 11,
      RegisteredAddressForConfirmation = 12,
      RegulatoryStatus = 13,
      RegistrationName = 14,
      CashAccountNumber = 15,
      BIC = 16,
      CSDParticipantMemberCode = 17,
      RegisteredAddress = 18,
      FundAccountName = 19,
      TelexNumber = 20,
      FaxNumber = 21,
      SecuritiesAccountName = 22,
      CashAccountName = 23,
      Department = 24,
      LocationDesk = 25,
      PositionAccountType = 26,
   };
   // PaymentMethodCodeSet (int)
   enum class PaymentMethod : int32_t {
      CREST = 1,
      NSCC = 2,
      Euroclear = 3,
      Clearstream = 4,
      Cheque = 5,
      TelegraphicTransfer = 6,
      FedWire = 7,
      DebitCard = 8,
      DirectDebit = 9,
      DirectCredit = 10,
      CreditCard = 11,
      ACHDebit = 12,
      ACHCredit = 13,
      BPAY = 14,
      HighValueClearingSystem = 15,
   };
   // PegLimitTypeCodeSet (int)
   enum class PegLimitType : int32_t {
      OrBetter = 0,
      Strict = 1,
      OrWorse = 2,
   };
   // PegMoveTypeCodeSet (int)
   enum class PegMoveType : int32_t {
      Floating = 0,
      Fixed = 1,
   };
   // PegOffsetTypeCodeSet (int)
   enum class PegOffsetType : int32_t {
      Price = 0,
      BasisPoints = 1,
      Ticks = 2,
      PriceTier = 3,
   };
   // PegRoundDirectionCodeSet (int)
   enum class PegRoundDirection : int32_t {
      MoreAggressive = 1,
      MorePassive = 2,
   };
   // PegScopeCodeSet (int)
   enum class PegScope : int32_t {
      Local = 1,
      National = 2,
      Global = 3,
      NationalExcludingLocal = 4,
   };
   // PosAmtTypeCodeSet (String)
   enum class PosAmtType : uint16_t {
      FinalMarkToMarketAmount = 0,
      IncrementalMarkToMarketAmount = 1,
      TradeVariationAmount = 2,
      StartOfDayMarkToMarketAmount = 3,
      PremiumAmount = 4,
      CashResidualAmount = 5,
      CashAmount = 6,
      ValueAdjustedAmount = 7,
   };
   // PosMaintActionCodeSet (int)
   enum class PosMaintAction : int32_t {
      New = 1,
      Replace = 2,
      Cancel = 3,
   };
   // PosMaintResultCodeSet (int)
   enum class PosMaintResult : int32_t {
      SuccessfulCompletion = 0,
      Rejected = 1,
      Other = 99,
   };
   // PosMaintStatusCodeSet (int)
   enum class PosMaintStatus : int32_t {
      Accepted = 0,
      AcceptedWithWarnings = 1,
      Rejected = 2,
      Completed = 3,
      CompletedWithWarnings = 4,
   };
   // PosQtyStatusCodeSet (int)
   enum class PosQtyStatus : int32_t {
      Submitted = 0,
      Accepted = 1,
      Rejected = 2,
   };
   // PosReqResultCodeSet (int)
   enum class PosReqResult : int32_t {
      ValidRequest = 0,
      InvalidOrUnsupportedRequest = 1,
      NoPositionsFoundThatMatchCriteria = 2,
      NotAuthorizedToRequestPositions = 3,
      RequestForPositionNotSupported = 4,
      Other = 99,
   };
   // PosReqStatusCodeSet (int)
   enum class PosReqStatus : int32_t {
      Completed = 0,
      CompletedWithWarnings = 1,
      Rejected = 2,
   };
   // PosReqTypeCodeSet (int)
   enum class PosReqType : int32_t {
      Positions = 0,
      Trades = 1,
      Exercises = 2,
      Assignments = 3,
   };
   // PosTransTypeCodeSet (int)
   enum class PosTransType : int32_t {
      Exercise = 1,
      DoNotExercise = 2,
      PositionAdjustment = 3,
      PositionChangeSubmission = 4,
      Pledge = 5,
   };
   // PosTypeCodeSet (String)
   enum class PosType : uint16_t {
      TransactionQuantity = 0,
      IntraSpreadQty = 1,
      InterSpreadQty = 2,
      EndOfDayQty = 3,
      StartOfDayQty = 4,
      OptionExerciseQty = 5,
      OptionAssignment = 6,
      TransactionFromExercise = 7,
      TransactionFromAssignment = 8,
      PitTradeQty = 9,
      TransferTradeQty = 10,
      ElectronicTradeQty = 11,
      AllocationTradeQty = 12,
      AdjustmentQty = 13,
      AsOfTradeQty = 14,
      DeliveryQty = 15,
      TotalTransactionQty = 16,
      CrossMarginQty = 17,
      IntegralSplit = 18,
   };
   // PositionEffectCodeSet (char)
   enum class PositionEffect : char {
      Open = 'O',
      Close = 'C',
      Rolled = 'R',
      FIFO = 'F',
   };
   // PossDupFlagCodeSet (Boolean)
   enum class PossDupFlag : uint16_t {
      PossibleDuplicate = 0,
      OriginalTransmission = 1,
   };
   // PossResendCodeSet (Boolean)
   enum class PossResend : uint16_t {
      PossibleResend = 0,
      OriginalTransmission = 1,
   };
   // PreallocMethodCodeSet (char)
   enum class PreallocMethod : char {
      ProRata = '0',
      DoNotProRata = '1',
   };
   // PreviouslyReportedCodeSet (Boolean)
   enum class PreviouslyReported : uint16_t {
      PerviouslyReportedToCounterparty = 0,
      NotReportedToCounterparty = 1,
   };
   // PriceTypeCodeSet (int)
   enum class PriceType : int32_t {
      Percentage = 1,
      PerUnit = 2,
      FixedAmount = 3,
      Discount = 4,
      Premium = 5,
      Spread = 6,
      TEDPrice = 7,
      TEDYield = 8,
      Yield = 9,
      FixedCabinetTradePrice = 10,
      VariableCabinetTradePrice = 11,
   };
   // PriorityIndicatorCodeSet (int)
   enum class PriorityIndicator : int32_t {
      PriorityUnchanged = 0,
      LostPriorityAsResultOfOrderChange = 1,
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
   // ProductCodeSet (int)
   enum class Product : int32_t {
      AGENCY = 1,
      COMMODITY = 2,
      CORPORATE = 3,
      CURRENCY = 4,
      EQUITY = 5,
      GOVERNMENT = 6,
      INDEX = 7,
      LOAN = 8,
      MONEYMARKET = 9,
      MORTGAGE = 10,
      MUNICIPAL = 11,
      OTHER = 12,
      FINANCING = 13,
   };
   // ProgRptReqsCodeSet (int)
   enum class ProgRptReqs : int32_t {
      BuySideRequests = 1,
      SellSideSends = 2,
      RealTimeExecutionReports = 3,
   };
   // PublishTrdIndicatorCodeSet (Boolean)
   enum class PublishTrdIndicator : uint16_t {
      ReportTrade = 0,
      DoNotReportTrade = 1,
   };
   // PutOrCallCodeSet (int)
   enum class PutOrCall : int32_t {
      Put = 0,
      Call = 1,
   };
   // QtyTypeCodeSet (int)
   enum class QtyType : int32_t {
      Units = 0,
      Contracts = 1,
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
   // QuotePriceTypeCodeSet (int)
   enum class QuotePriceType : int32_t {
      Percent = 1,
      PerShare = 2,
      FixedAmount = 3,
      Discount = 4,
      Premium = 5,
      Spread = 6,
      TEDPrice = 7,
      TEDYield = 8,
      YieldSpread = 9,
      Yield = 10,
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
      Other = 99,
   };
   // QuoteRequestRejectReasonCodeSet (int)
   enum class QuoteRequestRejectReason : int32_t {
      UnknownSymbol = 1,
      Exchange = 2,
      QuoteRequestExceedsLimit = 3,
      TooLateToEnter = 4,
      InvalidPrice = 5,
      NotAuthorizedToRequestQuote = 6,
      NoMatchForInquiry = 7,
      NoMarketForInstrument = 8,
      NoInventory = 9,
      Pass = 10,
      Other = 99,
   };
   // QuoteRequestTypeCodeSet (int)
   enum class QuoteRequestType : int32_t {
      Manual = 1,
      Automatic = 2,
   };
   // QuoteRespTypeCodeSet (int)
   enum class QuoteRespType : int32_t {
      Hit = 1,
      Counter = 2,
      Expired = 3,
      Cover = 4,
      DoneAway = 5,
      Pass = 6,
   };
   // QuoteResponseLevelCodeSet (int)
   enum class QuoteResponseLevel : int32_t {
      NoAcknowledgement = 0,
      AcknowledgeOnlyNegativeOrErroneousQuotes = 1,
      AcknowledgeEachQuoteMessage = 2,
   };
   // QuoteStatusCodeSet (int)
   enum class QuoteStatus : int32_t {
      Accepted = 0,
      CancelForSymbol = 1,
      CanceledForSecurityType = 2,
      CanceledForUnderlying = 3,
      CanceledAll = 4,
      Rejected = 5,
      RemovedFromMarket = 6,
      Expired = 7,
      Query = 8,
      QuoteNotFound = 9,
      Pending = 10,
      Pass = 11,
      LockedMarketWarning = 12,
      CrossMarketWarning = 13,
      CanceledDueToLockMarket = 14,
      CanceledDueToCrossMarket = 15,
   };
   // QuoteTypeCodeSet (int)
   enum class QuoteType : int32_t {
      Indicative = 0,
      Tradeable = 1,
      RestrictedTradeable = 2,
      Counter = 3,
   };
   // RegistRejReasonCodeCodeSet (int)
   enum class RegistRejReasonCode : int32_t {
      InvalidAccountType = 1,
      InvalidTaxExemptType = 2,
      InvalidOwnershipType = 3,
      NoRegDetails = 4,
      InvalidRegSeqNo = 5,
      InvalidRegDetails = 6,
      InvalidMailingDetails = 7,
      InvalidMailingInstructions = 8,
      InvalidInvestorID = 9,
      InvalidInvestorIDSource = 10,
      InvalidDateOfBirth = 11,
      InvalidCountry = 12,
      InvalidDistribInstns = 13,
      InvalidPercentage = 14,
      InvalidPaymentMethod = 15,
      InvalidAccountName = 16,
      InvalidAgentCode = 17,
      InvalidAccountNum = 18,
      Other = 99,
   };
   // RegistStatusCodeSet (char)
   enum class RegistStatus : char {
      Accepted = 'A',
      Rejected = 'R',
      Held = 'H',
      Reminder = 'N',
   };
   // RegistTransTypeCodeSet (char)
   enum class RegistTransType : char {
      New = '0',
      Replace = '1',
      Cancel = '2',
   };
   // ReportToExchCodeSet (Boolean)
   enum class ReportToExch : uint16_t {
      ReceiverReports = 0,
      SenderReports = 1,
   };
   // ResetSeqNumFlagCodeSet (Boolean)
   enum class ResetSeqNumFlag : uint16_t {
      Yes = 0,
      No = 1,
   };
   // ResponseTransportTypeCodeSet (int)
   enum class ResponseTransportType : int32_t {
      Inband = 0,
      OutOfBand = 1,
   };
   // RoundingDirectionCodeSet (char)
   enum class RoundingDirection : char {
      RoundToNearest = '0',
      RoundDown = '1',
      RoundUp = '2',
   };
   // RoutingTypeCodeSet (int)
   enum class RoutingType : int32_t {
      TargetFirm = 1,
      TargetList = 2,
      BlockFirm = 3,
      BlockList = 4,
   };
   // ScopeCodeSet (MultipleValueString)
   enum class Scope : uint16_t {
      LocalMarket = 0,
      National = 1,
      Global = 2,
   };
   // SecurityIDSourceCodeSet (String)
   enum class SecurityIDSource : uint16_t {
      CUSIP = 0,
      SEDOL = 1,
      QUIK = 2,
      ISINNumber = 3,
      RICCode = 4,
      ISOCurrencyCode = 5,
      ISOCountryCode = 6,
      ExchangeSymbol = 7,
      ConsolidatedTapeAssociation = 8,
      BloombergSymbol = 9,
      Wertpapier = 10,
      Dutch = 11,
      Valoren = 12,
      Sicovam = 13,
      Belgian = 14,
      Common = 15,
      ClearingHouse = 16,
      ISDAFpMLSpecification = 17,
      OptionPriceReportingAuthority = 18,
   };
   // SecurityListRequestTypeCodeSet (int)
   enum class SecurityListRequestType : int32_t {
      Symbol = 0,
      SecurityTypeAnd = 1,
      Product = 2,
      TradingSessionID = 3,
      AllSecurities = 4,
   };
   // SecurityRequestResultCodeSet (int)
   enum class SecurityRequestResult : int32_t {
      ValidRequest = 0,
      InvalidOrUnsupportedRequest = 1,
      NoInstrumentsFound = 2,
      NotAuthorizedToRetrieveInstrumentData = 3,
      InstrumentDataTemporarilyUnavailable = 4,
      RequestForInstrumentDataNotSupported = 5,
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
      RejectSecurityProposal = 5,
      CannotMatchSelectionCriteria = 6,
   };
   // SecurityTradingStatusCodeSet (int)
   enum class SecurityTradingStatus : int32_t {
      OpeningDelay = 1,
      TradingHalt = 2,
      Resume = 3,
      NoOpen = 4,
      PriceIndication = 5,
      TradingRangeIndication = 6,
      MarketImbalanceBuy = 7,
      MarketImbalanceSell = 8,
      MarketOnCloseImbalanceBuy = 9,
      MarketOnCloseImbalanceSell = 10,
      NoMarketImbalance = 12,
      NoMarketOnCloseImbalance = 13,
      ITSPreOpening = 14,
      NewPriceIndication = 15,
      TradeDisseminationTime = 16,
      ReadyToTrade = 17,
      NotAvailableForTrading = 18,
      NotTradedOnThisMarket = 19,
      UnknownOrInvalid = 20,
      PreOpen = 21,
      OpeningRotation = 22,
      FastMarket = 23,
   };
   // SecurityTypeCodeSet (String)
   enum class SecurityType : uint16_t {
      EuroSupranationalCoupons = 0,
      FederalAgencyCoupon = 1,
      FederalAgencyDiscountNote = 2,
      PrivateExportFunding = 3,
      USDSupranationalCoupons = 4,
      CorporateBond = 5,
      CorporatePrivatePlacement = 6,
      ConvertibleBond = 7,
      DualCurrency = 8,
      EuroCorporateBond = 9,
      IndexedLinked = 10,
      StructuredNotes = 11,
      YankeeCorporateBond = 12,
      ForeignExchangeContract = 13,
      CommonStock = 14,
      PreferredStock = 15,
      BradyBond = 16,
      EuroSovereigns = 17,
      USTreasuryBond = 18,
      InterestStripFromAnyBondOrNote = 19,
      TreasuryInflationProtectedSecurities = 20,
      PrincipalStripOfACallableBondOrNote = 21,
      PrincipalStripFromANonCallableBondOrNote = 22,
      USTreasuryNoteOld = 23,
      USTreasuryBillOld = 24,
      USTreasuryNote = 25,
      USTreasuryBill = 26,
      Repurchase = 27,
      Forward = 28,
      BuySellback = 29,
      SecuritiesLoan = 30,
      SecuritiesPledge = 31,
      TermLoan = 32,
      RevolverLoan = 33,
      Revolver = 34,
      BridgeLoan = 35,
      LetterOfCredit = 36,
      SwingLineFacility = 37,
      DebtorInPossession = 38,
      Defaulted = 39,
      Withdrawn = 40,
      Replaced = 41,
      Matured = 42,
      Amended = 43,
      Retired = 44,
      BankersAcceptance = 45,
      BankNotes = 46,
      BillOfExchanges = 47,
      CertificateOfDeposit = 48,
      CallLoans = 49,
      CommercialPaper = 50,
      DepositNotes = 51,
      EuroCertificateOfDeposit = 52,
      EuroCommercialPaper = 53,
      LiquidityNote = 54,
      MediumTermNotes = 55,
      Overnight = 56,
      PromissoryNote = 57,
      PlazosFijos = 58,
      ShortTermLoanNote = 59,
      TimeDeposit = 60,
      ExtendedCommNote = 61,
      YankeeCertificateOfDeposit = 62,
      AssetBackedSecurities = 63,
      Corp = 64,
      CollateralizedMortgageObligation = 65,
      IOETTEMortgage = 66,
      MortgageBackedSecurities = 67,
      MortgageInterestOnly = 68,
      MortgagePrincipalOnly = 69,
      MortgagePrivatePlacement = 70,
      MiscellaneousPassThrough = 71,
      Pfandbriefe = 72,
      ToBeAnnounced = 73,
      OtherAnticipationNotes = 74,
      CertificateOfObligation = 75,
      CertificateOfParticipation = 76,
      GeneralObligationBonds = 77,
      MandatoryTender = 78,
      RevenueAnticipationNote = 79,
      RevenueBonds = 80,
      SpecialAssessment = 81,
      SpecialObligation = 82,
      SpecialTax = 83,
      TaxAnticipationNote = 84,
      TaxAllocation = 85,
      TaxExemptCommercialPaper = 86,
      TaxRevenueAnticipationNote = 87,
      VariableRateDemandNote = 88,
      Warrant = 89,
      MutualFund = 90,
      MultilegInstrument = 91,
      NoSecurityType = 92,
      Future = 93,
      Option = 94,
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
      Non = 17,
      Other = 99,
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
      TriParty = 2,
      HoldInCustody = 3,
   };
   // SettlInstModeCodeSet (char)
   enum class SettlInstMode : char {
      StandingInstructionsProvided = '1',
      SpecificOrderForASingleAccount = '4',
      RequestReject = '5',
   };
   // SettlInstReqRejCodeCodeSet (int)
   enum class SettlInstReqRejCode : int32_t {
      UnableToProcessRequest = 0,
      UnknownAccount = 1,
      NoMatchingSettlementInstructionsFound = 2,
      Other = 99,
   };
   // SettlInstSourceCodeSet (char)
   enum class SettlInstSource : char {
      BrokerCredit = '1',
      Institution = '2',
      Investor = '3',
   };
   // SettlInstTransTypeCodeSet (char)
   enum class SettlInstTransType : char {
      New = 'N',
      Cancel = 'C',
      Replace = 'R',
      Restate = 'T',
   };
   // SettlPriceTypeCodeSet (int)
   enum class SettlPriceType : int32_t {
      Final = 1,
      Theoretical = 2,
   };
   // SettlSessIDCodeSet (String)
   enum class SettlSessID : uint16_t {
      Intraday = 0,
      RegularTradingHours = 1,
      ElectronicTradingHours = 2,
   };
   // SettlTypeCodeSet (char)
   enum class SettlType : char {
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
   // ShortSaleReasonCodeSet (int)
   enum class ShortSaleReason : int32_t {
      DealerSoldShort = 0,
      DealerSoldShortExempt = 1,
      SellingCustomerSoldShort = 2,
      SellingCustomerSoldShortExempt = 3,
      QualifiedServiceRepresentative = 4,
      QSROrAGUContraSideSoldShortExempt = 5,
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
      CrossShortExempt = 'A',
      AsDefined = 'B',
      Opposite = 'C',
      Subscribe = 'D',
      Redeem = 'E',
      Lend = 'F',
      Borrow = 'G',
   };
   // SideMultiLegReportingTypeCodeSet (int)
   enum class SideMultiLegReportingType : int32_t {
      SingleSecurity = 1,
      IndividualLegOfAMultilegSecurity = 2,
      MultilegSecurity = 3,
   };
   // SideValueIndCodeSet (int)
   enum class SideValueInd : int32_t {
      SideValue1 = 1,
      SideValue2 = 2,
   };
   // SolicitedFlagCodeSet (Boolean)
   enum class SolicitedFlag : uint16_t {
      WasSolicited = 0,
      WasNotSolicited = 1,
   };
   // StandInstDbTypeCodeSet (int)
   enum class StandInstDbType : int32_t {
      Other = 0,
      DTCSID = 1,
      ThomsonALERT = 2,
      AGlobalCustodian = 3,
      AccountNet = 4,
   };
   // StatusValueCodeSet (int)
   enum class StatusValue : int32_t {
      Connected = 1,
      NotConnectedUnexpected = 2,
      NotConnectedExpected = 3,
      InProcess = 4,
   };
   // StipulationTypeCodeSet (String)
   enum class StipulationType : uint16_t {
      AlternativeMinimumTax = 0,
      AutoReinvestment = 1,
      BankQualified = 2,
      BargainConditions = 3,
      CouponRange = 4,
      ISOCurrencyCode = 5,
      CustomStart = 6,
      Geographics = 7,
      ValuationDiscount = 8,
      Insured = 9,
      IssueDate = 10,
      Issuer = 11,
      IssueSizeRange = 12,
      LookbackDays = 13,
      ExplicitLotIdentifier = 14,
      LotVariance = 15,
      MaturityYearAndMonth = 16,
      MaturityRange = 17,
      MaximumSubstitutions = 18,
      MinimumQuantity = 19,
      MinimumIncrement = 20,
      MinimumDenomination = 21,
      PaymentFrequency = 22,
      NumberOfPieces = 23,
      PoolsMaximum = 24,
      PoolsPerMillion = 25,
      PoolsPerLot = 26,
      PoolsPerTrade = 27,
      PriceRange = 28,
      PricingFrequency = 29,
      ProductionYear = 30,
      CallProtection = 31,
      Purpose = 32,
      BenchmarkPriceSource = 33,
      RatingSourceAndRange = 34,
      TypeOfRedemption = 35,
      Restricted = 36,
      MarketSector = 37,
      SecurityTypeIncludedOrExcluded = 38,
      Structure = 39,
      SubstitutionsFrequency = 40,
      SubstitutionsLeft = 41,
      FreeformText = 42,
      TradeVariance = 43,
      WeightedAverageCoupon = 44,
      WeightedAverageLifeCoupon = 45,
      WeightedAverageLoanAge = 46,
      WeightedAverageMaturity = 47,
      WholePool = 48,
      YieldRange = 49,
   };
   // SubscriptionRequestTypeCodeSet (char)
   enum class SubscriptionRequestType : char {
      Snapshot = '0',
      SnapshotAndUpdates = '1',
      DisablePreviousSnapshot = '2',
   };
   // TargetStrategyCodeSet (int)
   enum class TargetStrategy : int32_t {
      VWAP = 1,
      Participate = 2,
      MininizeMarketImpact = 3,
   };
   // TaxAdvantageTypeCodeSet (int)
   enum class TaxAdvantageType : int32_t {
      None = 0,
      MaxiISA = 1,
      TESSA = 2,
      MiniCashISA = 3,
      MiniStocksAndSharesISA = 4,
      MiniInsuranceISA = 5,
      CurrentYearPayment = 6,
      PriorYearPayment = 7,
      AssetTransfer = 8,
      EmployeePriorYear = 9,
      EmployeeCurrentYear = 10,
      EmployerPriorYear = 11,
      EmployerCurrentYear = 12,
      NonFundPrototypeIRA = 13,
      NonFundQualifiedPlan = 14,
      DefinedContributionPlan = 15,
      IRA = 16,
      IRARollover = 17,
      KEOGH = 18,
      ProfitSharingPlan = 19,
      US401K = 20,
      SelfDirectedIRA = 21,
      US403b = 22,
      US457 = 23,
      RothIRAPrototype = 24,
      RothIRANonPrototype = 25,
      RothConversionIRAPrototype = 26,
      RothConversionIRANonPrototype = 27,
      EducationIRAPrototype = 28,
      EducationIRANonPrototype = 29,
   };
   // TerminationTypeCodeSet (int)
   enum class TerminationType : int32_t {
      Overnight = 1,
      Term = 2,
      Flexible = 3,
      Open = 4,
   };
   // TestMessageIndicatorCodeSet (Boolean)
   enum class TestMessageIndicator : uint16_t {
      True = 0,
      False = 1,
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
      AtTheClose = '7',
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
      Unknown = 0,
      Halted = 1,
      Open = 2,
      Closed = 3,
      PreOpen = 4,
      PreClose = 5,
      RequestRejected = 6,
   };
   // TradSesStatusRejReasonCodeSet (int)
   enum class TradSesStatusRejReason : int32_t {
      UnknownOrInvalidTradingSessionID = 1,
      Other = 99,
   };
   // TradeAllocIndicatorCodeSet (int)
   enum class TradeAllocIndicator : int32_t {
      AllocationNotRequired = 0,
      AllocationRequired = 1,
      UseAllocationProvidedWithTheTrade = 2,
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
      ImbalanceMoreBuyers = 14,
      ImbalanceMoreSellers = 15,
      OpeningPrice = 16,
   };
   // TradeReportRejectReasonCodeSet (int)
   enum class TradeReportRejectReason : int32_t {
      Successful = 0,
      InvalidPartyOnformation = 1,
      UnknownInstrument = 2,
      UnauthorizedToReportTrades = 3,
      InvalidTradeType = 4,
      Other = 99,
   };
   // TradeReportTransTypeCodeSet (int)
   enum class TradeReportTransType : int32_t {
      New = 0,
      Cancel = 1,
      Replace = 2,
      Release = 3,
      Reverse = 4,
   };
   // TradeReportTypeCodeSet (int)
   enum class TradeReportType : int32_t {
      Submit = 0,
      Alleged = 1,
      Accept = 2,
      Decline = 3,
      Addendum = 4,
      No = 5,
      TradeReportCancel = 6,
      LockedIn = 7,
   };
   // TradeRequestResultCodeSet (int)
   enum class TradeRequestResult : int32_t {
      Successful = 0,
      InvalidOrUnknownInstrument = 1,
      InvalidTypeOfTradeRequested = 2,
      InvalidParties = 3,
      InvalidTransportTypeRequested = 4,
      InvalidDestinationRequested = 5,
      TradeRequestTypeNotSupported = 8,
      NotAuthorized = 9,
      Other = 99,
   };
   // TradeRequestStatusCodeSet (int)
   enum class TradeRequestStatus : int32_t {
      Accepted = 0,
      Completed = 1,
      Rejected = 2,
   };
   // TradeRequestTypeCodeSet (int)
   enum class TradeRequestType : int32_t {
      AllTrades = 0,
      MatchedTradesMatchingCriteria = 1,
      UnmatchedTradesThatMatchCriteria = 2,
      UnreportedTradesThatMatchCriteria = 3,
      AdvisoriesThatMatchCriteria = 4,
   };
   // TradedFlatSwitchCodeSet (Boolean)
   enum class TradedFlatSwitch : uint16_t {
      TradedFlat = 0,
      NotTradedFlat = 1,
   };
   // TrdRegTimestampTypeCodeSet (int)
   enum class TrdRegTimestampType : int32_t {
      ExecutionTime = 1,
      TimeIn = 2,
      TimeOut = 3,
      BrokerReceipt = 4,
      BrokerExecution = 5,
   };
   // TrdRptStatusCodeSet (int)
   enum class TrdRptStatus : int32_t {
      Accepted = 0,
      Rejected = 1,
   };
   // TrdTypeCodeSet (int)
   enum class TrdType : int32_t {
      RegularTrade = 0,
      BlockTrade = 1,
      EFP = 2,
      Transfer = 3,
      LateTrade = 4,
      TTrade = 5,
      WeightedAveragePriceTrade = 6,
      BunchedTrade = 7,
      LateBunchedTrade = 8,
      PriorReferencePriceTrade = 9,
      AfterHoursTrade = 10,
   };
   // UnsolicitedIndicatorCodeSet (Boolean)
   enum class UnsolicitedIndicator : uint16_t {
      MessageIsBeingSentUnsolicited = 0,
      MessageIsBeingSentAsAResultOfAPriorRequest = 1,
   };
   // UrgencyCodeSet (char)
   enum class Urgency : char {
      Normal = '0',
      Flash = '1',
      Background = '2',
   };
   // UserRequestTypeCodeSet (int)
   enum class UserRequestType : int32_t {
      LogOnUser = 1,
      LogOffUser = 2,
      ChangePasswordForUser = 3,
      RequestIndividualUserStatus = 4,
   };
   // UserStatusCodeSet (int)
   enum class UserStatus : int32_t {
      LoggedIn = 1,
      NotLoggedIn = 2,
      UserNotRecognised = 3,
      PasswordIncorrect = 4,
      PasswordChanged = 5,
      Other = 6,
   };
   // WorkingIndicatorCodeSet (Boolean)
   enum class WorkingIndicator : uint16_t {
      Working = 0,
      NotWorking = 1,
   };
   // YieldTypeCodeSet (String)
   enum class YieldType : uint16_t {
      AfterTaxYield = 0,
      AnnualYield = 1,
      YieldAtIssue = 2,
      YieldToAverageMaturity = 3,
      BookYield = 4,
      YieldToNextCall = 5,
      YieldChangeSinceClose = 6,
      ClosingYield = 7,
      CompoundYield = 8,
      CurrentYield = 9,
      TrueGrossYield = 10,
      GvntEquivalentYield = 11,
      YieldWithInflationAssumption = 12,
      InverseFloaterBondYield = 13,
      MostRecentClosingYield = 14,
      ClosingYieldMostRecentMonth = 15,
      ClosingYieldMostRecentQuarter = 16,
      ClosingYieldMostRecentYear = 17,
      YieldToLongestAverageLife = 18,
      MarkToMarketYield = 19,
      YieldToMaturity = 20,
      YieldToNextRefund = 21,
      OpenAverageYield = 22,
      YieldToNextPut = 23,
      PreviousCloseYield = 24,
      ProceedsYield = 25,
      SemiAnnualYield = 26,
      YieldToShortestAverageLife = 27,
      SimpleYield = 28,
      TaxEquivalentYield = 29,
      YieldToTenderDate = 30,
      TrueYield = 31,
      YieldValueOf132 = 32,
      YieldToWorst = 33,
   };

   // ---- repeating groups ----
   struct SecAltIDGrp
   {
      std::optional<std::string> security_alt_id{};
      std::optional<SecurityIDSource> security_alt_id_source{};
      bool operator==(const SecAltIDGrp&) const = default;
   };
   struct EvntGrp
   {
      std::optional<EventType> event_type{};
      std::optional<std::string> event_date{};
      std::optional<double> event_px{};
      std::optional<std::string> event_text{};
      bool operator==(const EvntGrp&) const = default;
   };
   struct AttrbGrp
   {
      std::optional<InstrAttribType> instr_attrib_type{};
      std::optional<std::string> instr_attrib_value{};
      bool operator==(const AttrbGrp&) const = default;
   };
   struct LegSecAltIDGrp
   {
      std::optional<std::string> leg_security_alt_id{};
      std::optional<SecurityIDSource> leg_security_alt_id_source{};
      bool operator==(const LegSecAltIDGrp&) const = default;
   };
   struct SettlPtysSubGrp
   {
      std::optional<std::string> settl_party_sub_id{};
      std::optional<PartySubIDType> settl_party_sub_id_type{};
      bool operator==(const SettlPtysSubGrp&) const = default;
   };
   struct SettlPartiesGrp
   {
      std::optional<std::string> settl_party_id{};
      std::optional<PartyIDSource> settl_party_id_source{};
      std::optional<PartyRole> settl_party_role{};
      std::vector<SettlPtysSubGrp> no_settl_party_sub_ids{};
      bool operator==(const SettlPartiesGrp&) const = default;
   };
   struct DlvyInstGrp
   {
      std::optional<SettlInstSource> settl_inst_source{};
      std::optional<DlvyInstType> dlvy_inst_type{};
      std::vector<SettlPartiesGrp> no_settl_party_ids{};
      bool operator==(const DlvyInstGrp&) const = default;
   };
   struct UndSecAltIDGrp
   {
      std::optional<std::string> underlying_security_alt_id{};
      std::optional<SecurityIDSource> underlying_security_alt_id_source{};
      bool operator==(const UndSecAltIDGrp&) const = default;
   };
   struct UnderlyingStipulationsGrp
   {
      std::optional<StipulationType> underlying_stip_type{};
      std::optional<std::string> underlying_stip_value{};
      bool operator==(const UnderlyingStipulationsGrp&) const = default;
   };
   struct HopGrp
   {
      std::optional<std::string> hop_comp_id{};
      std::optional<std::string> hop_sending_time{};
      std::optional<int64_t> hop_ref_id{};
      bool operator==(const HopGrp&) const = default;
   };
   struct UndInstrmtGrp
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      bool operator==(const UndInstrmtGrp&) const = default;
   };
   struct StipulationsGrp
   {
      std::optional<StipulationType> stipulation_type{};
      std::optional<std::string> stipulation_value{};
      bool operator==(const StipulationsGrp&) const = default;
   };
   struct LegStipulationsGrp
   {
      std::optional<std::string> leg_stipulation_type{};
      std::optional<std::string> leg_stipulation_value{};
      bool operator==(const LegStipulationsGrp&) const = default;
   };
   struct InstrmtLegIOIGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<std::string> leg_ioi_qty{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      bool operator==(const InstrmtLegIOIGrp&) const = default;
   };
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
   struct InstrmtLegGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      bool operator==(const InstrmtLegGrp&) const = default;
   };
   struct PtysSubGrp
   {
      std::optional<std::string> party_sub_id{};
      std::optional<PartySubIDType> party_sub_id_type{};
      bool operator==(const PtysSubGrp&) const = default;
   };
   struct PartiesGrp
   {
      std::optional<std::string> party_id{};
      std::optional<PartyIDSource> party_id_source{};
      std::optional<PartyRole> party_role{};
      std::vector<PtysSubGrp> no_party_sub_ids{};
      bool operator==(const PartiesGrp&) const = default;
   };
   struct ContraGrp
   {
      std::optional<std::string> contra_broker{};
      std::optional<std::string> contra_trader{};
      std::optional<double> contra_trade_qty{};
      std::optional<std::string> contra_trade_time{};
      std::optional<std::string> contra_leg_ref_id{};
      bool operator==(const ContraGrp&) const = default;
   };
   struct ContAmtGrp
   {
      std::optional<ContAmtType> cont_amt_type{};
      std::optional<double> cont_amt_value{};
      std::optional<std::string> cont_amt_curr{};
      bool operator==(const ContAmtGrp&) const = default;
   };
   struct NstdPtysSubGrp
   {
      std::optional<std::string> nested_party_sub_id{};
      std::optional<PartySubIDType> nested_party_sub_id_type{};
      bool operator==(const NstdPtysSubGrp&) const = default;
   };
   struct NestedPartiesGrp
   {
      std::optional<std::string> nested_party_id{};
      std::optional<PartyIDSource> nested_party_id_source{};
      std::optional<PartyRole> nested_party_role{};
      std::vector<NstdPtysSubGrp> no_nested_party_sub_ids{};
      bool operator==(const NestedPartiesGrp&) const = default;
   };
   struct InstrmtLegExecGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::optional<PositionEffect> leg_position_effect{};
      std::optional<int64_t> leg_covered_or_uncovered{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<std::string> leg_ref_id{};
      std::optional<double> leg_price{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      std::optional<double> leg_last_px{};
      bool operator==(const InstrmtLegExecGrp&) const = default;
   };
   struct MiscFeesGrp
   {
      std::optional<double> misc_fee_amt{};
      std::optional<std::string> misc_fee_curr{};
      std::optional<MiscFeeType> misc_fee_type{};
      std::optional<MiscFeeBasis> misc_fee_basis{};
      bool operator==(const MiscFeesGrp&) const = default;
   };
   struct MsgTypeGrp
   {
      std::optional<MsgType> ref_msg_type{};
      std::optional<MsgDirection> msg_direction{};
      bool operator==(const MsgTypeGrp&) const = default;
   };
   struct InstrmtGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
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
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<std::string> alloc_settl_currency{};
      std::optional<std::string> individual_alloc_id{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<double> alloc_qty{};
      bool operator==(const PreAllocGrp&) const = default;
   };
   struct TrdgSesGrp
   {
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      bool operator==(const TrdgSesGrp&) const = default;
   };
   struct ListOrdGrp
   {
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      int64_t list_seq_no{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<SettlInstMode> settl_inst_mode{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<std::string> alloc_id{};
      std::optional<PreallocMethod> prealloc_method{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      Side side{};
      std::optional<SideValueInd> side_value_ind{};
      std::optional<LocateReqd> locate_reqd{};
      std::optional<std::string> transact_time{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<OrdType> ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> price2{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<std::string> designation{};
      bool operator==(const ListOrdGrp&) const = default;
   };
   struct NstdPtys2SubGrp
   {
      std::optional<std::string> nested2_party_sub_id{};
      std::optional<PartySubIDType> nested2_party_sub_id_type{};
      bool operator==(const NstdPtys2SubGrp&) const = default;
   };
   struct NestedParties2Grp
   {
      std::optional<std::string> nested2_party_id{};
      std::optional<PartyIDSource> nested2_party_id_source{};
      std::optional<PartyRole> nested2_party_role{};
      std::vector<NstdPtys2SubGrp> no_nested2_party_sub_ids{};
      bool operator==(const NestedParties2Grp&) const = default;
   };
   struct OrdAllocGrp
   {
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> list_id{};
      std::vector<NestedParties2Grp> no_nested2_party_ids{};
      std::optional<double> order_qty{};
      std::optional<double> order_avg_px{};
      std::optional<double> order_booking_qty{};
      bool operator==(const OrdAllocGrp&) const = default;
   };
   struct ExecAllocGrp
   {
      std::optional<double> last_qty{};
      std::optional<std::string> exec_id{};
      std::optional<std::string> secondary_exec_id{};
      std::optional<double> last_px{};
      std::optional<double> last_par_px{};
      std::optional<LastCapacity> last_capacity{};
      bool operator==(const ExecAllocGrp&) const = default;
   };
   struct ClrInstGrp
   {
      std::optional<ClearingInstruction> clearing_instruction{};
      bool operator==(const ClrInstGrp&) const = default;
   };
   struct AllocGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<MatchStatus> match_status{};
      std::optional<double> alloc_price{};
      std::optional<double> alloc_qty{};
      std::optional<std::string> individual_alloc_id{};
      std::optional<ProcessCode> process_code{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<NotifyBrokerOfCredit> notify_broker_of_credit{};
      std::optional<AllocHandlInst> alloc_handl_inst{};
      std::optional<std::string> alloc_text{};
      std::optional<int64_t> encoded_alloc_text_len{};
      std::optional<std::string> encoded_alloc_text{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<double> alloc_avg_px{};
      std::optional<double> alloc_net_money{};
      std::optional<double> settl_curr_amt{};
      std::optional<double> alloc_settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<std::string> alloc_settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<double> alloc_accrued_interest_amt{};
      std::optional<double> alloc_interest_at_maturity{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::vector<ClrInstGrp> no_clearing_instructions{};
      std::optional<AllocSettlInstType> alloc_settl_inst_type{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      bool operator==(const AllocGrp&) const = default;
   };
   struct OrdListStatGrp
   {
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      double cum_qty{};
      OrdStatus ord_status{};
      std::optional<WorkingIndicator> working_indicator{};
      double leaves_qty{};
      double cxl_qty{};
      double avg_px{};
      std::optional<OrdRejReason> ord_rej_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrdListStatGrp&) const = default;
   };
   struct AllocAckGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<double> alloc_price{};
      std::optional<std::string> individual_alloc_id{};
      std::optional<AllocRejCode> individual_alloc_rej_code{};
      std::optional<std::string> alloc_text{};
      std::optional<int64_t> encoded_alloc_text_len{};
      std::optional<std::string> encoded_alloc_text{};
      bool operator==(const AllocAckGrp&) const = default;
   };
   struct QuotReqLegsGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<std::string> leg_benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> leg_benchmark_curve_name{};
      std::optional<std::string> leg_benchmark_curve_point{};
      std::optional<double> leg_benchmark_price{};
      std::optional<int64_t> leg_benchmark_price_type{};
      bool operator==(const QuotReqLegsGrp&) const = default;
   };
   struct QuotQualGrp
   {
      std::optional<char> quote_qualifier{};
      bool operator==(const QuotQualGrp&) const = default;
   };
   struct QuotReqGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      std::optional<QuoteRequestType> quote_request_type{};
      std::optional<QuoteType> quote_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> trade_origination_date{};
      std::optional<Side> side{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<QuotReqLegsGrp> no_legs{};
      std::vector<QuotQualGrp> no_quote_qualifiers{};
      std::optional<QuotePriceType> quote_price_type{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> valid_until_time{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> transact_time{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> price2{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::vector<PartiesGrp> no_party_ids{};
      bool operator==(const QuotReqGrp&) const = default;
   };
   struct LegQuotGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<int64_t> leg_price_type{};
      std::optional<double> leg_bid_px{};
      std::optional<double> leg_offer_px{};
      std::optional<std::string> leg_benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> leg_benchmark_curve_name{};
      std::optional<std::string> leg_benchmark_curve_point{};
      std::optional<double> leg_benchmark_price{};
      std::optional<int64_t> leg_benchmark_price_type{};
      bool operator==(const LegQuotGrp&) const = default;
   };
   struct SettlInstGrp
   {
      std::optional<std::string> settl_inst_id{};
      std::optional<SettlInstTransType> settl_inst_trans_type{};
      std::optional<std::string> settl_inst_ref_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<Side> side{};
      std::optional<Product> product{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> cfi_code{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> last_update_time{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      std::optional<PaymentMethod> payment_method{};
      std::optional<std::string> payment_ref{};
      std::optional<std::string> card_holder_name{};
      std::optional<std::string> card_number{};
      std::optional<std::string> card_start_date{};
      std::optional<std::string> card_exp_date{};
      std::optional<std::string> card_iss_num{};
      std::optional<std::string> payment_date{};
      std::optional<std::string> payment_remitter_id{};
      bool operator==(const SettlInstGrp&) const = default;
   };
   struct MDReqGrp
   {
      MDEntryType md_entry_type{};
      bool operator==(const MDReqGrp&) const = default;
   };
   struct InstrmtMDReqGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      bool operator==(const InstrmtMDReqGrp&) const = default;
   };
   struct MDFullGrp
   {
      MDEntryType md_entry_type{};
      std::optional<double> md_entry_px{};
      std::optional<std::string> currency{};
      std::optional<double> md_entry_size{};
      std::optional<std::string> md_entry_date{};
      std::optional<std::string> md_entry_time{};
      std::optional<TickDirection> tick_direction{};
      std::optional<std::string> md_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> quote_condition{};
      std::optional<std::string> trade_condition{};
      std::optional<std::string> md_entry_originator{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      std::optional<std::string> open_close_settl_flag{};
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
      std::optional<std::string> scope{};
      std::optional<double> price_delta{};
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
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> financial_status{};
      std::optional<std::string> corporate_action{};
      std::optional<double> md_entry_px{};
      std::optional<std::string> currency{};
      std::optional<double> md_entry_size{};
      std::optional<std::string> md_entry_date{};
      std::optional<std::string> md_entry_time{};
      std::optional<TickDirection> tick_direction{};
      std::optional<std::string> md_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> quote_condition{};
      std::optional<std::string> trade_condition{};
      std::optional<std::string> md_entry_originator{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      std::optional<std::string> open_close_settl_flag{};
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
      std::optional<std::string> scope{};
      std::optional<double> price_delta{};
      std::optional<double> net_chg_prev_day{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const MDIncGrp&) const = default;
   };
   struct MDRjctGrp
   {
      std::optional<std::string> alt_md_source_id{};
      bool operator==(const MDRjctGrp&) const = default;
   };
   struct QuotCxlEntriesGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      bool operator==(const QuotCxlEntriesGrp&) const = default;
   };
   struct QuotEntryAckGrp
   {
      std::optional<std::string> quote_entry_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> bid_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<double> mid_px{};
      std::optional<double> bid_yield{};
      std::optional<double> mid_yield{};
      std::optional<double> offer_yield{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> settl_date{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> bid_forward_points2{};
      std::optional<double> offer_forward_points2{};
      std::optional<std::string> currency{};
      std::optional<QuoteRejectReason> quote_entry_reject_reason{};
      bool operator==(const QuotEntryAckGrp&) const = default;
   };
   struct QuotSetAckGrp
   {
      std::optional<std::string> quote_set_id{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<int64_t> tot_no_quote_entries{};
      std::optional<LastFragment> last_fragment{};
      std::vector<QuotEntryAckGrp> no_quote_entries{};
      bool operator==(const QuotSetAckGrp&) const = default;
   };
   struct QuotEntryGrp
   {
      std::string quote_entry_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> bid_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<double> mid_px{};
      std::optional<double> bid_yield{};
      std::optional<double> mid_yield{};
      std::optional<double> offer_yield{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> settl_date{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> bid_forward_points2{};
      std::optional<double> offer_forward_points2{};
      std::optional<std::string> currency{};
      bool operator==(const QuotEntryGrp&) const = default;
   };
   struct QuotSetGrp
   {
      std::string quote_set_id{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<std::string> quote_set_valid_until_time{};
      int64_t tot_no_quote_entries{};
      std::optional<LastFragment> last_fragment{};
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
      std::optional<std::string> trading_session_sub_id{};
      std::optional<NetGrossInd> net_gross_ind{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      bool operator==(const BidCompReqGrp&) const = default;
   };
   struct BidCompRspGrp
   {
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<std::string> list_id{};
      std::optional<std::string> country{};
      std::optional<Side> side{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> fair_value{};
      std::optional<NetGrossInd> net_gross_ind{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const BidCompRspGrp&) const = default;
   };
   struct InstrmtStrkPxGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      bool operator==(const InstrmtStrkPxGrp&) const = default;
   };
   struct UndInstrmtStrkPxGrp
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<double> prev_close_px{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<Side> side{};
      double price{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const UndInstrmtStrkPxGrp&) const = default;
   };
   struct RgstDtlsGrp
   {
      std::optional<std::string> regist_dtls{};
      std::optional<std::string> regist_email{};
      std::optional<std::string> mailing_dtls{};
      std::optional<std::string> mailing_inst{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<OwnerType> owner_type{};
      std::optional<std::string> date_of_birth{};
      std::optional<std::string> investor_country_of_residence{};
      bool operator==(const RgstDtlsGrp&) const = default;
   };
   struct RgstDistInstGrp
   {
      std::optional<DistribPaymentMethod> distrib_payment_method{};
      std::optional<double> distrib_percentage{};
      std::optional<std::string> cash_distrib_curr{};
      std::optional<std::string> cash_distrib_agent_name{};
      std::optional<std::string> cash_distrib_agent_code{};
      std::optional<std::string> cash_distrib_agent_acct_number{};
      std::optional<std::string> cash_distrib_pay_ref{};
      std::optional<std::string> cash_distrib_agent_acct_name{};
      bool operator==(const RgstDistInstGrp&) const = default;
   };
   struct AffectedOrdGrp
   {
      std::optional<std::string> orig_cl_ord_id{};
      std::optional<std::string> affected_order_id{};
      std::optional<std::string> affected_secondary_order_id{};
      bool operator==(const AffectedOrdGrp&) const = default;
   };
   struct SideCrossOrdModGrp
   {
      Side side{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> orig_ord_mod_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> side_compliance_id{};
      bool operator==(const SideCrossOrdModGrp&) const = default;
   };
   struct SideCrossOrdCxlGrp
   {
      Side side{};
      std::string orig_cl_ord_id{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> orig_ord_mod_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<std::string> compliance_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const SideCrossOrdCxlGrp&) const = default;
   };
   struct SecTypesGrp
   {
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      bool operator==(const SecTypesGrp&) const = default;
   };
   struct InstrmtLegSecListGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<LegSwapType> leg_swap_type{};
      std::optional<SettlType> leg_settl_type{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::optional<std::string> leg_benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> leg_benchmark_curve_name{};
      std::optional<std::string> leg_benchmark_curve_point{};
      std::optional<double> leg_benchmark_price{};
      std::optional<int64_t> leg_benchmark_price_type{};
      bool operator==(const InstrmtLegSecListGrp&) const = default;
   };
   struct SecListGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::vector<InstrmtLegSecListGrp> no_legs{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<double> round_lot{};
      std::optional<double> min_trade_vol{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<ExpirationCycle> expiration_cycle{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const SecListGrp&) const = default;
   };
   struct RelSymDerivSecGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::optional<ExpirationCycle> expiration_cycle{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const RelSymDerivSecGrp&) const = default;
   };
   struct NstdPtys3SubGrp
   {
      std::optional<std::string> nested3_party_sub_id{};
      std::optional<PartySubIDType> nested3_party_sub_id_type{};
      bool operator==(const NstdPtys3SubGrp&) const = default;
   };
   struct NestedParties3Grp
   {
      std::optional<std::string> nested3_party_id{};
      std::optional<PartyIDSource> nested3_party_id_source{};
      std::optional<PartyRole> nested3_party_role{};
      std::vector<NstdPtys3SubGrp> no_nested3_party_sub_ids{};
      bool operator==(const NestedParties3Grp&) const = default;
   };
   struct PreAllocMlegGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<std::string> alloc_settl_currency{};
      std::optional<std::string> individual_alloc_id{};
      std::vector<NestedParties3Grp> no_nested3_party_ids{};
      std::optional<double> alloc_qty{};
      bool operator==(const PreAllocMlegGrp&) const = default;
   };
   struct LegPreAllocGrp
   {
      std::optional<std::string> leg_alloc_account{};
      std::optional<std::string> leg_individual_alloc_id{};
      std::vector<NestedParties2Grp> no_nested2_party_ids{};
      std::optional<double> leg_alloc_qty{};
      std::optional<AcctIDSource> leg_alloc_acct_id_source{};
      std::optional<std::string> leg_settl_currency{};
      bool operator==(const LegPreAllocGrp&) const = default;
   };
   struct LegOrdGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::vector<LegPreAllocGrp> no_leg_allocs{};
      std::optional<PositionEffect> leg_position_effect{};
      std::optional<int64_t> leg_covered_or_uncovered{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<std::string> leg_ref_id{};
      std::optional<double> leg_price{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      bool operator==(const LegOrdGrp&) const = default;
   };
   struct TrdCapDtGrp
   {
      std::optional<std::string> trade_date{};
      std::optional<std::string> transact_time{};
      bool operator==(const TrdCapDtGrp&) const = default;
   };
   struct PositionAmountDataGrp
   {
      std::optional<PosAmtType> pos_amt_type{};
      std::optional<double> pos_amt{};
      bool operator==(const PositionAmountDataGrp&) const = default;
   };
   struct TrdInstrmtLegGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::optional<PositionEffect> leg_position_effect{};
      std::optional<int64_t> leg_covered_or_uncovered{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      std::optional<std::string> leg_ref_id{};
      std::optional<double> leg_price{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      std::optional<double> leg_last_px{};
      bool operator==(const TrdInstrmtLegGrp&) const = default;
   };
   struct TrdRegTimestampsGrp
   {
      std::optional<std::string> trd_reg_timestamp{};
      std::optional<TrdRegTimestampType> trd_reg_timestamp_type{};
      std::optional<std::string> trd_reg_timestamp_origin{};
      bool operator==(const TrdRegTimestampsGrp&) const = default;
   };
   struct TrdAllocGrp
   {
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<std::string> alloc_settl_currency{};
      std::optional<std::string> individual_alloc_id{};
      std::vector<NestedParties2Grp> no_nested2_party_ids{};
      std::optional<double> alloc_qty{};
      bool operator==(const TrdAllocGrp&) const = default;
   };
   struct TrdCapRptSideGrp
   {
      Side side{};
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> list_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<ProcessCode> process_code{};
      std::optional<OddLot> odd_lot{};
      std::vector<ClrInstGrp> no_clearing_instructions{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<std::string> trade_input_source{};
      std::optional<std::string> trade_input_device{};
      std::optional<std::string> order_input_device{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> exec_inst{};
      std::optional<std::string> trans_bkd_time{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> time_bracket{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<double> gross_trade_amt{};
      std::optional<int64_t> num_days_interest{};
      std::optional<std::string> ex_date{};
      std::optional<double> accrued_interest_rate{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> interest_at_maturity{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> concession{};
      std::optional<double> total_takedown{};
      std::optional<double> net_money{};
      std::optional<double> settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<PositionEffect> position_effect{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<SideMultiLegReportingType> side_multi_leg_reporting_type{};
      std::vector<ContAmtGrp> no_cont_amts{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::optional<std::string> exchange_rule{};
      std::optional<TradeAllocIndicator> trade_alloc_indicator{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<TrdAllocGrp> no_allocs{};
      bool operator==(const TrdCapRptSideGrp&) const = default;
   };
   struct QuotReqRjctGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      std::optional<QuoteRequestType> quote_request_type{};
      std::optional<QuoteType> quote_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> trade_origination_date{};
      std::optional<Side> side{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<QuotReqLegsGrp> no_legs{};
      std::vector<QuotQualGrp> no_quote_qualifiers{};
      std::optional<QuotePriceType> quote_price_type{};
      std::optional<OrdType> ord_type{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> transact_time{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> price2{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::vector<PartiesGrp> no_party_ids{};
      bool operator==(const QuotReqRjctGrp&) const = default;
   };
   struct RFQReqGrp
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<double> prev_close_px{};
      std::optional<QuoteRequestType> quote_request_type{};
      std::optional<QuoteType> quote_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      bool operator==(const RFQReqGrp&) const = default;
   };
   struct LegQuotStatGrp
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      std::optional<double> leg_qty{};
      std::optional<LegSwapType> leg_swap_type{};
      std::optional<SettlType> leg_settl_type{};
      std::optional<std::string> leg_settl_date{};
      std::vector<LegStipulationsGrp> no_leg_stipulations{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      bool operator==(const LegQuotStatGrp&) const = default;
   };
   struct CpctyConfGrp
   {
      OrderCapacity order_capacity{};
      std::optional<std::string> order_restrictions{};
      double order_capacity_qty{};
      bool operator==(const CpctyConfGrp&) const = default;
   };
   struct PositionQtyGrp
   {
      std::optional<PosType> pos_type{};
      std::optional<double> long_qty{};
      std::optional<double> short_qty{};
      std::optional<PosQtyStatus> pos_qty_status{};
      std::vector<NestedPartiesGrp> no_nested_party_ids{};
      bool operator==(const PositionQtyGrp&) const = default;
   };
   struct PosUndInstrmtGrp
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      double underlying_settl_price{};
      int64_t underlying_settl_price_type{};
      bool operator==(const PosUndInstrmtGrp&) const = default;
   };
   struct ExecCollGrp
   {
      std::optional<std::string> exec_id{};
      bool operator==(const ExecCollGrp&) const = default;
   };
   struct TrdCollGrp
   {
      std::optional<std::string> trade_report_id{};
      std::optional<std::string> secondary_trade_report_id{};
      bool operator==(const TrdCollGrp&) const = default;
   };
   struct UndInstrmtCollGrp
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<CollAction> coll_action{};
      bool operator==(const UndInstrmtCollGrp&) const = default;
   };
   struct CollInqQualGrp
   {
      std::optional<CollInquiryQualifier> coll_inquiry_qualifier{};
      bool operator==(const CollInqQualGrp&) const = default;
   };
   struct CompIDReqGrp
   {
      std::optional<std::string> ref_comp_id{};
      std::optional<std::string> ref_sub_id{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      bool operator==(const CompIDReqGrp&) const = default;
   };
   struct CompIDStatGrp
   {
      std::optional<std::string> ref_comp_id{};
      std::optional<std::string> ref_sub_id{};
      std::optional<std::string> location_id{};
      std::optional<std::string> desk_id{};
      std::optional<StatusValue> status_value{};
      std::optional<std::string> status_text{};
      bool operator==(const CompIDStatGrp&) const = default;
   };

   // ---- components (flattened) ----
   struct CommissionData
   {
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      bool operator==(const CommissionData&) const = default;
   };
   struct DiscretionInstructions
   {
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      bool operator==(const DiscretionInstructions&) const = default;
   };
   struct FinancingDetails
   {
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      bool operator==(const FinancingDetails&) const = default;
   };
   struct Instrument
   {
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      bool operator==(const Instrument&) const = default;
   };
   struct InstrumentExtension
   {
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      bool operator==(const InstrumentExtension&) const = default;
   };
   struct InstrumentLeg
   {
      std::optional<std::string> leg_symbol{};
      std::optional<std::string> leg_symbol_sfx{};
      std::optional<std::string> leg_security_id{};
      std::optional<SecurityIDSource> leg_security_id_source{};
      std::vector<LegSecAltIDGrp> no_leg_security_alt_id{};
      std::optional<int64_t> leg_product{};
      std::optional<std::string> leg_cfi_code{};
      std::optional<std::string> leg_security_type{};
      std::optional<std::string> leg_security_sub_type{};
      std::optional<std::string> leg_maturity_month_year{};
      std::optional<std::string> leg_maturity_date{};
      std::optional<std::string> leg_coupon_payment_date{};
      std::optional<std::string> leg_issue_date{};
      std::optional<std::string> leg_repo_collateral_security_type{};
      std::optional<int64_t> leg_repurchase_term{};
      std::optional<double> leg_repurchase_rate{};
      std::optional<double> leg_factor{};
      std::optional<std::string> leg_credit_rating{};
      std::optional<std::string> leg_instr_registry{};
      std::optional<std::string> leg_country_of_issue{};
      std::optional<std::string> leg_state_or_province_of_issue{};
      std::optional<std::string> leg_locale_of_issue{};
      std::optional<std::string> leg_redemption_date{};
      std::optional<double> leg_strike_price{};
      std::optional<std::string> leg_strike_currency{};
      std::optional<char> leg_opt_attribute{};
      std::optional<double> leg_contract_multiplier{};
      std::optional<double> leg_coupon_rate{};
      std::optional<std::string> leg_security_exchange{};
      std::optional<std::string> leg_issuer{};
      std::optional<int64_t> encoded_leg_issuer_len{};
      std::optional<std::string> encoded_leg_issuer{};
      std::optional<std::string> leg_security_desc{};
      std::optional<int64_t> encoded_leg_security_desc_len{};
      std::optional<std::string> encoded_leg_security_desc{};
      std::optional<double> leg_ratio_qty{};
      std::optional<char> leg_side{};
      std::optional<std::string> leg_currency{};
      std::optional<std::string> leg_pool{};
      std::optional<std::string> leg_dated_date{};
      std::optional<std::string> leg_contract_settl_month{};
      std::optional<std::string> leg_interest_accrual_date{};
      bool operator==(const InstrumentLeg&) const = default;
   };
   struct LegBenchmarkCurveData
   {
      std::optional<std::string> leg_benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> leg_benchmark_curve_name{};
      std::optional<std::string> leg_benchmark_curve_point{};
      std::optional<double> leg_benchmark_price{};
      std::optional<int64_t> leg_benchmark_price_type{};
      bool operator==(const LegBenchmarkCurveData&) const = default;
   };
   struct OrderQtyData
   {
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      bool operator==(const OrderQtyData&) const = default;
   };
   struct PegInstructions
   {
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      bool operator==(const PegInstructions&) const = default;
   };
   struct SettlInstructionsData
   {
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      bool operator==(const SettlInstructionsData&) const = default;
   };
   struct SpreadOrBenchmarkCurveData
   {
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      bool operator==(const SpreadOrBenchmarkCurveData&) const = default;
   };
   struct UnderlyingInstrument
   {
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      bool operator==(const UnderlyingInstrument&) const = default;
   };
   struct YieldData
   {
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      bool operator==(const YieldData&) const = default;
   };
   struct StandardHeader
   {
      std::string begin_string{};
      int64_t body_length{};
      MsgType msg_type{};
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
      std::optional<PossDupFlag> poss_dup_flag{};
      std::optional<PossResend> poss_resend{};
      std::string sending_time{};
      std::optional<std::string> orig_sending_time{};
      std::optional<int64_t> xml_data_len{};
      std::optional<std::string> xml_data{};
      std::optional<MessageEncoding> message_encoding{};
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
      std::optional<MsgType> ref_msg_type{};
      std::optional<SessionRejectReason> session_reject_reason{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Reject&) const = default;
   };
   struct SequenceReset
   {
      std::optional<GapFillFlag> gap_fill_flag{};
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
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      Side side{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      IOIQty ioi_qty{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::vector<InstrmtLegIOIGrp> no_legs{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<std::string> valid_until_time{};
      std::optional<IOIQltyInd> ioi_qlty_ind{};
      std::optional<IOINaturalFlag> ioi_natural_flag{};
      std::vector<IOIQualGrp> no_ioi_qualifiers{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> url_link{};
      std::vector<RoutingGrp> no_routing_ids{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      bool operator==(const IOI&) const = default;
   };
   struct Advertisement
   {
      std::string adv_id{};
      AdvTransType adv_trans_type{};
      std::optional<std::string> adv_ref_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      AdvSide adv_side{};
      double quantity{};
      std::optional<QtyType> qty_type{};
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
      std::optional<std::string> trading_session_sub_id{};
      bool operator==(const Advertisement&) const = default;
   };
   struct ExecutionReport
   {
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> secondary_exec_id{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> orig_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> quote_resp_id{};
      std::optional<std::string> ord_status_req_id{};
      std::optional<std::string> mass_status_req_id{};
      std::optional<int64_t> tot_num_reports{};
      std::optional<bool> last_rpt_requested{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::vector<ContraGrp> no_contra_brokers{};
      std::optional<std::string> list_id{};
      std::optional<std::string> cross_id{};
      std::optional<std::string> orig_cross_id{};
      std::optional<CrossType> cross_type{};
      std::string exec_id{};
      std::optional<std::string> exec_ref_id{};
      ExecType exec_type{};
      OrdStatus ord_status{};
      std::optional<WorkingIndicator> working_indicator{};
      std::optional<OrdRejReason> ord_rej_reason{};
      std::optional<ExecRestatementReason> exec_restatement_reason{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      Side side{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<OrdType> ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<double> pegged_price{};
      std::optional<double> discretion_price{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<double> target_strategy_performance{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> exec_inst{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<double> last_qty{};
      std::optional<double> underlying_last_qty{};
      std::optional<double> last_px{};
      std::optional<double> underlying_last_px{};
      std::optional<double> last_par_px{};
      std::optional<double> last_spot_rate{};
      std::optional<double> last_forward_points{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> time_bracket{};
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
      std::optional<ReportToExch> report_to_exch{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<double> gross_trade_amt{};
      std::optional<int64_t> num_days_interest{};
      std::optional<std::string> ex_date{};
      std::optional<double> accrued_interest_rate{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> interest_at_maturity{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<TradedFlatSwitch> traded_flat_switch{};
      std::optional<std::string> basis_feature_date{};
      std::optional<double> basis_feature_price{};
      std::optional<double> concession{};
      std::optional<double> total_takedown{};
      std::optional<double> net_money{};
      std::optional<double> settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<HandlInst> handl_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<PositionEffect> position_effect{};
      std::optional<double> max_show{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> last_forward_points2{};
      std::optional<MultiLegReportingType> multi_leg_reporting_type{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      std::optional<std::string> trans_bkd_time{};
      std::optional<std::string> exec_valuation_point{};
      std::optional<ExecPriceType> exec_price_type{};
      std::optional<double> exec_price_adjustment{};
      std::optional<PriorityIndicator> priority_indicator{};
      std::optional<double> price_improvement{};
      std::optional<LastLiquidityInd> last_liquidity_ind{};
      std::vector<ContAmtGrp> no_cont_amts{};
      std::vector<InstrmtLegExecGrp> no_legs{};
      std::optional<bool> copy_msg_indicator{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      bool operator==(const ExecutionReport&) const = default;
   };
   struct OrderCancelReject
   {
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::string cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::string orig_cl_ord_id{};
      OrdStatus ord_status{};
      std::optional<WorkingIndicator> working_indicator{};
      std::optional<std::string> orig_ord_mod_time{};
      std::optional<std::string> list_id{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
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
      std::optional<ResetSeqNumFlag> reset_seq_num_flag{};
      std::optional<int64_t> next_expected_msg_seq_num{};
      std::optional<int64_t> max_message_size{};
      std::vector<MsgTypeGrp> no_msg_types{};
      std::optional<TestMessageIndicator> test_message_indicator{};
      std::optional<std::string> username{};
      std::optional<std::string> password{};
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
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<LinesOfTextGrp> no_lines_of_text{};
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
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> order_id{};
      std::optional<std::string> cl_ord_id{};
      std::vector<LinesOfTextGrp> no_lines_of_text{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      bool operator==(const Email&) const = default;
   };
   struct NewOrderSingle
   {
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      Side side{};
      std::optional<LocateReqd> locate_reqd{};
      std::string transact_time{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> price2{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
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
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<ListExecInstType> list_exec_inst_type{};
      std::optional<std::string> list_exec_inst{};
      std::optional<int64_t> encoded_list_exec_inst_len{};
      std::optional<std::string> encoded_list_exec_inst{};
      std::optional<double> allowable_one_sidedness_pct{};
      std::optional<double> allowable_one_sidedness_value{};
      std::optional<std::string> allowable_one_sidedness_curr{};
      int64_t tot_no_orders{};
      std::optional<LastFragment> last_fragment{};
      std::vector<ListOrdGrp> no_orders{};
      bool operator==(const NewOrderList&) const = default;
   };
   struct OrderCancelRequest
   {
      std::string orig_cl_ord_id{};
      std::optional<std::string> order_id{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> list_id{};
      std::optional<std::string> orig_ord_mod_time{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      Side side{};
      std::string transact_time{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<std::string> compliance_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrderCancelRequest&) const = default;
   };
   struct OrderCancelReplaceRequest
   {
      std::optional<std::string> order_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::string orig_cl_ord_id{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> list_id{};
      std::optional<std::string> orig_ord_mod_time{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<PreAllocGrp> no_allocs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      Side side{};
      std::string transact_time{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> currency{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<double> price2{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<double> max_show{};
      std::optional<LocateReqd> locate_reqd{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      bool operator==(const OrderCancelReplaceRequest&) const = default;
   };
   struct OrderStatusRequest
   {
      std::optional<std::string> order_id{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> ord_status_req_id{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      Side side{};
      bool operator==(const OrderStatusRequest&) const = default;
   };
   struct AllocationInstruction
   {
      std::string alloc_id{};
      AllocTransType alloc_trans_type{};
      AllocType alloc_type{};
      std::optional<std::string> secondary_alloc_id{};
      std::optional<std::string> ref_alloc_id{};
      std::optional<AllocCancReplaceReason> alloc_canc_replace_reason{};
      std::optional<AllocIntermedReqType> alloc_intermed_req_type{};
      std::optional<std::string> alloc_link_id{};
      std::optional<AllocLinkType> alloc_link_type{};
      std::optional<std::string> booking_ref_id{};
      AllocNoOrdersType alloc_no_orders_type{};
      std::vector<OrdAllocGrp> no_orders{};
      std::vector<ExecAllocGrp> no_execs{};
      std::optional<PreviouslyReported> previously_reported{};
      std::optional<bool> reversal_indicator{};
      std::optional<MatchType> match_type{};
      Side side{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      double quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<PriceType> price_type{};
      double avg_px{};
      std::optional<double> avg_par_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<std::string> currency{};
      std::optional<int64_t> avg_px_precision{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string trade_date{};
      std::optional<std::string> transact_time{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<BookingType> booking_type{};
      std::optional<double> gross_trade_amt{};
      std::optional<double> concession{};
      std::optional<double> total_takedown{};
      std::optional<double> net_money{};
      std::optional<PositionEffect> position_effect{};
      std::optional<bool> auto_accept_indicator{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<int64_t> num_days_interest{};
      std::optional<double> accrued_interest_rate{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> total_accrued_interest_amt{};
      std::optional<double> interest_at_maturity{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<LegalConfirm> legal_confirm{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<int64_t> tot_no_allocs{};
      std::optional<LastFragment> last_fragment{};
      std::vector<AllocGrp> no_allocs{};
      bool operator==(const AllocationInstruction&) const = default;
   };
   struct ListCancelRequest
   {
      std::string list_id{};
      std::string transact_time{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
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
      std::optional<LastFragment> last_fragment{};
      std::vector<OrdListStatGrp> no_orders{};
      bool operator==(const ListStatus&) const = default;
   };
   struct AllocationInstructionAck
   {
      std::string alloc_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> secondary_alloc_id{};
      std::optional<std::string> trade_date{};
      std::string transact_time{};
      AllocStatus alloc_status{};
      std::optional<AllocRejCode> alloc_rej_code{};
      std::optional<AllocType> alloc_type{};
      std::optional<AllocIntermedReqType> alloc_intermed_req_type{};
      std::optional<MatchStatus> match_status{};
      std::optional<Product> product{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<AllocAckGrp> no_allocs{};
      bool operator==(const AllocationInstructionAck&) const = default;
   };
   struct DontKnowTrade
   {
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      std::string exec_id{};
      DKReason dk_reason{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      Side side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<double> last_qty{};
      std::optional<double> last_px{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const DontKnowTrade&) const = default;
   };
   struct QuoteRequest
   {
      std::string quote_req_id{};
      std::optional<std::string> rfq_req_id{};
      std::optional<std::string> cl_ord_id{};
      std::optional<OrderCapacity> order_capacity{};
      std::vector<QuotReqGrp> no_related_sym{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const QuoteRequest&) const = default;
   };
   struct Quote
   {
      std::optional<std::string> quote_req_id{};
      std::string quote_id{};
      std::optional<std::string> quote_resp_id{};
      std::optional<QuoteType> quote_type{};
      std::vector<QuotQualGrp> no_quote_qualifiers{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<Side> side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<LegQuotGrp> no_legs{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> mkt_bid_px{};
      std::optional<double> mkt_offer_px{};
      std::optional<double> min_bid_size{};
      std::optional<double> bid_size{};
      std::optional<double> min_offer_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<double> mid_px{};
      std::optional<double> bid_yield{};
      std::optional<double> mid_yield{};
      std::optional<double> offer_yield{};
      std::optional<std::string> transact_time{};
      std::optional<OrdType> ord_type{};
      std::optional<double> bid_forward_points2{};
      std::optional<double> offer_forward_points2{};
      std::optional<double> settl_curr_bid_fx_rate{};
      std::optional<double> settl_curr_offer_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<CommType> comm_type{};
      std::optional<double> commission{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<std::string> ex_destination{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<PriceType> price_type{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const Quote&) const = default;
   };
   struct SettlementInstructions
   {
      std::string settl_inst_msg_id{};
      std::optional<std::string> settl_inst_req_id{};
      SettlInstMode settl_inst_mode{};
      std::optional<SettlInstReqRejCode> settl_inst_req_rej_code{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> cl_ord_id{};
      std::string transact_time{};
      std::vector<SettlInstGrp> no_settl_inst{};
      bool operator==(const SettlementInstructions&) const = default;
   };
   struct MarketDataRequest
   {
      std::string md_req_id{};
      SubscriptionRequestType subscription_request_type{};
      int64_t market_depth{};
      std::optional<MDUpdateType> md_update_type{};
      std::optional<AggregatedBook> aggregated_book{};
      std::optional<std::string> open_close_settl_flag{};
      std::optional<std::string> scope{};
      std::optional<MDImplicitDelete> md_implicit_delete{};
      std::vector<MDReqGrp> no_md_entry_types{};
      std::vector<InstrmtMDReqGrp> no_related_sym{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ApplQueueAction> appl_queue_action{};
      std::optional<int64_t> appl_queue_max{};
      bool operator==(const MarketDataRequest&) const = default;
   };
   struct MarketDataSnapshotFullRefresh
   {
      std::optional<std::string> md_req_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> financial_status{};
      std::optional<std::string> corporate_action{};
      std::optional<double> net_chg_prev_day{};
      std::vector<MDFullGrp> no_md_entries{};
      std::optional<int64_t> appl_queue_depth{};
      std::optional<ApplQueueResolution> appl_queue_resolution{};
      bool operator==(const MarketDataSnapshotFullRefresh&) const = default;
   };
   struct MarketDataIncrementalRefresh
   {
      std::optional<std::string> md_req_id{};
      std::vector<MDIncGrp> no_md_entries{};
      std::optional<int64_t> appl_queue_depth{};
      std::optional<ApplQueueResolution> appl_queue_resolution{};
      bool operator==(const MarketDataIncrementalRefresh&) const = default;
   };
   struct MarketDataRequestReject
   {
      std::string md_req_id{};
      std::optional<MDReqRejReason> md_req_rej_reason{};
      std::vector<MDRjctGrp> no_alt_md_source{};
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
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::vector<QuotCxlEntriesGrp> no_quote_entries{};
      bool operator==(const QuoteCancel&) const = default;
   };
   struct QuoteStatusRequest
   {
      std::optional<std::string> quote_status_req_id{};
      std::optional<std::string> quote_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const QuoteStatusRequest&) const = default;
   };
   struct MassQuoteAcknowledgement
   {
      std::optional<std::string> quote_req_id{};
      std::optional<std::string> quote_id{};
      QuoteStatus quote_status{};
      std::optional<QuoteRejectReason> quote_reject_reason{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::optional<QuoteType> quote_type{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<QuotSetAckGrp> no_quote_sets{};
      bool operator==(const MassQuoteAcknowledgement&) const = default;
   };
   struct SecurityDefinitionRequest
   {
      std::string security_req_id{};
      SecurityRequestType security_request_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<ExpirationCycle> expiration_cycle{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const SecurityDefinitionRequest&) const = default;
   };
   struct SecurityDefinition
   {
      std::string security_req_id{};
      std::string security_response_id{};
      SecurityResponseType security_response_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<std::string> currency{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<ExpirationCycle> expiration_cycle{};
      std::optional<double> round_lot{};
      std::optional<double> min_trade_vol{};
      bool operator==(const SecurityDefinition&) const = default;
   };
   struct SecurityStatusRequest
   {
      std::string security_status_req_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> currency{};
      SubscriptionRequestType subscription_request_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      bool operator==(const SecurityStatusRequest&) const = default;
   };
   struct SecurityStatus
   {
      std::optional<std::string> security_status_req_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> currency{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<UnsolicitedIndicator> unsolicited_indicator{};
      std::optional<SecurityTradingStatus> security_trading_status{};
      std::optional<std::string> financial_status{};
      std::optional<std::string> corporate_action{};
      std::optional<HaltReason> halt_reason{};
      std::optional<InViewOfCommon> in_view_of_common{};
      std::optional<DueToRelated> due_to_related{};
      std::optional<double> buy_volume{};
      std::optional<double> sell_volume{};
      std::optional<double> high_px{};
      std::optional<double> low_px{};
      std::optional<double> last_px{};
      std::optional<std::string> transact_time{};
      std::optional<Adjustment> adjustment{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const SecurityStatus&) const = default;
   };
   struct TradingSessionStatusRequest
   {
      std::string trad_ses_req_id{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<TradSesMethod> trad_ses_method{};
      std::optional<TradSesMode> trad_ses_mode{};
      SubscriptionRequestType subscription_request_type{};
      bool operator==(const TradingSessionStatusRequest&) const = default;
   };
   struct TradingSessionStatus
   {
      std::optional<std::string> trad_ses_req_id{};
      std::string trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<TradSesMethod> trad_ses_method{};
      std::optional<TradSesMode> trad_ses_mode{};
      std::optional<UnsolicitedIndicator> unsolicited_indicator{};
      TradSesStatus trad_ses_status{};
      std::optional<TradSesStatusRejReason> trad_ses_status_rej_reason{};
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
      std::optional<QuoteType> quote_type{};
      std::optional<QuoteResponseLevel> quote_response_level{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<double> def_bid_size{};
      std::optional<double> def_offer_size{};
      std::vector<QuotSetGrp> no_quote_sets{};
      bool operator==(const MassQuote&) const = default;
   };
   struct BusinessMessageReject
   {
      std::optional<int64_t> ref_seq_num{};
      MsgType ref_msg_type{};
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
      int64_t tot_no_related_sym{};
      BidType bid_type{};
      std::optional<int64_t> num_tickets{};
      std::optional<std::string> currency{};
      std::optional<double> side_value1{};
      std::optional<double> side_value2{};
      std::vector<BidDescReqGrp> no_bid_descriptors{};
      std::vector<BidCompReqGrp> no_bid_components{};
      std::optional<LiquidityIndType> liquidity_ind_type{};
      std::optional<double> wt_average_liquidity{};
      std::optional<ExchangeForPhysical> exchange_for_physical{};
      std::optional<double> out_main_cntry_u_index{};
      std::optional<double> cross_percent{};
      std::optional<ProgRptReqs> prog_rpt_reqs{};
      std::optional<int64_t> prog_period_interval{};
      std::optional<IncTaxInd> inc_tax_ind{};
      std::optional<ForexReq> forex_req{};
      std::optional<int64_t> num_bidders{};
      std::optional<std::string> trade_date{};
      BidTradeType bid_trade_type{};
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
      std::optional<LastFragment> last_fragment{};
      std::vector<InstrmtStrkPxGrp> no_strikes{};
      std::vector<UndInstrmtStrkPxGrp> no_underlyings{};
      bool operator==(const ListStrikePrice&) const = default;
   };
   struct XMLnonFIX
   {
      bool operator==(const XMLnonFIX&) const = default;
   };
   struct RegistrationInstructions
   {
      std::string regist_id{};
      RegistTransType regist_trans_type{};
      std::string regist_ref_id{};
      std::optional<std::string> cl_ord_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<std::string> regist_acct_type{};
      std::optional<TaxAdvantageType> tax_advantage_type{};
      std::optional<OwnershipType> ownership_type{};
      std::vector<RgstDtlsGrp> no_regist_dtls{};
      std::vector<RgstDistInstGrp> no_distrib_insts{};
      bool operator==(const RegistrationInstructions&) const = default;
   };
   struct RegistrationInstructionsResponse
   {
      std::string regist_id{};
      RegistTransType regist_trans_type{};
      std::string regist_ref_id{};
      std::optional<std::string> cl_ord_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      RegistStatus regist_status{};
      std::optional<RegistRejReasonCode> regist_rej_reason_code{};
      std::optional<std::string> regist_rej_reason_text{};
      bool operator==(const RegistrationInstructionsResponse&) const = default;
   };
   struct OrderMassCancelRequest
   {
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      MassCancelRequestType mass_cancel_request_type{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<Side> side{};
      std::string transact_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrderMassCancelRequest&) const = default;
   };
   struct OrderMassCancelReport
   {
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::string order_id{};
      std::optional<std::string> secondary_order_id{};
      MassCancelRequestType mass_cancel_request_type{};
      MassCancelResponse mass_cancel_response{};
      std::optional<MassCancelRejectReason> mass_cancel_reject_reason{};
      std::optional<int64_t> total_affected_orders{};
      std::vector<AffectedOrdGrp> no_affected_orders{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<Side> side{};
      std::optional<std::string> transact_time{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const OrderMassCancelReport&) const = default;
   };
   struct NewOrderCross
   {
      std::string cross_id{};
      CrossType cross_type{};
      CrossPrioritization cross_prioritization{};
      std::vector<SideCrossOrdModGrp> no_sides{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::optional<double> prev_close_px{};
      std::optional<LocateReqd> locate_reqd{};
      std::string transact_time{};
      std::vector<StipulationsGrp> no_stipulations{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      bool operator==(const NewOrderCross&) const = default;
   };
   struct CrossOrderCancelReplaceRequest
   {
      std::optional<std::string> order_id{};
      std::string cross_id{};
      std::string orig_cross_id{};
      CrossType cross_type{};
      CrossPrioritization cross_prioritization{};
      std::vector<SideCrossOrdModGrp> no_sides{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      std::optional<double> prev_close_px{};
      std::optional<LocateReqd> locate_reqd{};
      std::string transact_time{};
      std::vector<StipulationsGrp> no_stipulations{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      bool operator==(const CrossOrderCancelReplaceRequest&) const = default;
   };
   struct CrossOrderCancelRequest
   {
      std::optional<std::string> order_id{};
      std::string cross_id{};
      std::string orig_cross_id{};
      CrossType cross_type{};
      CrossPrioritization cross_prioritization{};
      std::vector<SideCrossOrdCxlGrp> no_sides{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::string transact_time{};
      bool operator==(const CrossOrderCancelRequest&) const = default;
   };
   struct SecurityTypeRequest
   {
      std::string security_req_id{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<Product> product{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      bool operator==(const SecurityTypeRequest&) const = default;
   };
   struct SecurityTypes
   {
      std::string security_req_id{};
      std::string security_response_id{};
      SecurityResponseType security_response_type{};
      std::optional<int64_t> tot_no_security_types{};
      std::optional<LastFragment> last_fragment{};
      std::vector<SecTypesGrp> no_security_types{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const SecurityTypes&) const = default;
   };
   struct SecurityListRequest
   {
      std::string security_req_id{};
      SecurityListRequestType security_list_request_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const SecurityListRequest&) const = default;
   };
   struct SecurityList
   {
      std::string security_req_id{};
      std::string security_response_id{};
      SecurityRequestResult security_request_result{};
      std::optional<int64_t> tot_no_related_sym{};
      std::optional<LastFragment> last_fragment{};
      std::vector<SecListGrp> no_related_sym{};
      bool operator==(const SecurityList&) const = default;
   };
   struct DerivativeSecurityListRequest
   {
      std::string security_req_id{};
      SecurityListRequestType security_list_request_type{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> currency{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const DerivativeSecurityListRequest&) const = default;
   };
   struct DerivativeSecurityList
   {
      std::string security_req_id{};
      std::string security_response_id{};
      SecurityRequestResult security_request_result{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<int64_t> tot_no_related_sym{};
      std::optional<LastFragment> last_fragment{};
      std::vector<RelSymDerivSecGrp> no_related_sym{};
      bool operator==(const DerivativeSecurityList&) const = default;
   };
   struct NewOrderMultileg
   {
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<PreAllocMlegGrp> no_allocs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      Side side{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      std::vector<LegOrdGrp> no_legs{};
      std::optional<LocateReqd> locate_reqd{};
      std::string transact_time{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      std::optional<MultiLegRptTypeReq> multi_leg_rpt_type_req{};
      bool operator==(const NewOrderMultileg&) const = default;
   };
   struct MultilegOrderCancelReplace
   {
      std::optional<std::string> order_id{};
      std::string orig_cl_ord_id{};
      std::string cl_ord_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::optional<std::string> cl_ord_link_id{};
      std::optional<std::string> orig_ord_mod_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trade_date{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<DayBookingInst> day_booking_inst{};
      std::optional<BookingUnit> booking_unit{};
      std::optional<PreallocMethod> prealloc_method{};
      std::optional<std::string> alloc_id{};
      std::vector<PreAllocMlegGrp> no_allocs{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<CashMargin> cash_margin{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<HandlInst> handl_inst{};
      std::optional<std::string> exec_inst{};
      std::optional<double> min_qty{};
      std::optional<double> max_floor{};
      std::optional<std::string> ex_destination{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::optional<ProcessCode> process_code{};
      Side side{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> prev_close_px{};
      std::vector<LegOrdGrp> no_legs{};
      std::optional<LocateReqd> locate_reqd{};
      std::string transact_time{};
      std::optional<QtyType> qty_type{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      OrdType ord_type{};
      std::optional<PriceType> price_type{};
      std::optional<double> price{};
      std::optional<double> stop_px{};
      std::optional<std::string> currency{};
      std::optional<std::string> compliance_id{};
      std::optional<SolicitedFlag> solicited_flag{};
      std::optional<std::string> ioiid{};
      std::optional<std::string> quote_id{};
      std::optional<TimeInForce> time_in_force{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_date{};
      std::optional<std::string> expire_time{};
      std::optional<GTBookingInst> gt_booking_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<ForexReq> forex_req{};
      std::optional<std::string> settl_currency{};
      std::optional<BookingType> booking_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<PositionEffect> position_effect{};
      std::optional<CoveredOrUncovered> covered_or_uncovered{};
      std::optional<double> max_show{};
      std::optional<double> peg_offset_value{};
      std::optional<PegMoveType> peg_move_type{};
      std::optional<PegOffsetType> peg_offset_type{};
      std::optional<PegLimitType> peg_limit_type{};
      std::optional<PegRoundDirection> peg_round_direction{};
      std::optional<PegScope> peg_scope{};
      std::optional<DiscretionInst> discretion_inst{};
      std::optional<double> discretion_offset_value{};
      std::optional<DiscretionMoveType> discretion_move_type{};
      std::optional<DiscretionOffsetType> discretion_offset_type{};
      std::optional<DiscretionLimitType> discretion_limit_type{};
      std::optional<DiscretionRoundDirection> discretion_round_direction{};
      std::optional<DiscretionScope> discretion_scope{};
      std::optional<TargetStrategy> target_strategy{};
      std::optional<std::string> target_strategy_parameters{};
      std::optional<double> participation_rate{};
      std::optional<CancellationRights> cancellation_rights{};
      std::optional<MoneyLaunderingStatus> money_laundering_status{};
      std::optional<std::string> regist_id{};
      std::optional<std::string> designation{};
      std::optional<MultiLegRptTypeReq> multi_leg_rpt_type_req{};
      bool operator==(const MultilegOrderCancelReplace&) const = default;
   };
   struct TradeCaptureReportRequest
   {
      std::string trade_request_id{};
      TradeRequestType trade_request_type{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<std::string> trade_report_id{};
      std::optional<std::string> secondary_trade_report_id{};
      std::optional<std::string> exec_id{};
      std::optional<ExecType> exec_type{};
      std::optional<std::string> order_id{};
      std::optional<std::string> cl_ord_id{};
      std::optional<MatchStatus> match_status{};
      std::optional<TrdType> trd_type{};
      std::optional<int64_t> trd_sub_type{};
      std::optional<std::string> transfer_reason{};
      std::optional<int64_t> secondary_trd_type{};
      std::optional<std::string> trade_link_id{};
      std::optional<std::string> trd_match_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<TrdCapDtGrp> no_dates{};
      std::optional<std::string> clearing_business_date{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> time_bracket{};
      std::optional<Side> side{};
      std::optional<MultiLegReportingType> multi_leg_reporting_type{};
      std::optional<std::string> trade_input_source{};
      std::optional<std::string> trade_input_device{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const TradeCaptureReportRequest&) const = default;
   };
   struct TradeCaptureReport
   {
      std::string trade_report_id{};
      std::optional<TradeReportTransType> trade_report_trans_type{};
      std::optional<TradeReportType> trade_report_type{};
      std::optional<std::string> trade_request_id{};
      std::optional<TrdType> trd_type{};
      std::optional<int64_t> trd_sub_type{};
      std::optional<int64_t> secondary_trd_type{};
      std::optional<std::string> transfer_reason{};
      std::optional<ExecType> exec_type{};
      std::optional<int64_t> tot_num_trade_reports{};
      std::optional<bool> last_rpt_requested{};
      std::optional<UnsolicitedIndicator> unsolicited_indicator{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<std::string> trade_report_ref_id{};
      std::optional<std::string> secondary_trade_report_ref_id{};
      std::optional<std::string> secondary_trade_report_id{};
      std::optional<std::string> trade_link_id{};
      std::optional<std::string> trd_match_id{};
      std::optional<std::string> exec_id{};
      std::optional<OrdStatus> ord_status{};
      std::optional<std::string> secondary_exec_id{};
      std::optional<ExecRestatementReason> exec_restatement_reason{};
      PreviouslyReported previously_reported{};
      std::optional<PriceType> price_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<QtyType> qty_type{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<std::string> underlying_trading_session_id{};
      std::optional<std::string> underlying_trading_session_sub_id{};
      double last_qty{};
      double last_px{};
      std::optional<double> last_par_px{};
      std::optional<double> last_spot_rate{};
      std::optional<double> last_forward_points{};
      std::optional<std::string> last_mkt{};
      std::string trade_date{};
      std::optional<std::string> clearing_business_date{};
      std::optional<double> avg_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<AvgPxIndicator> avg_px_indicator{};
      std::vector<PositionAmountDataGrp> no_pos_amt{};
      std::optional<MultiLegReportingType> multi_leg_reporting_type{};
      std::optional<std::string> trade_leg_ref_id{};
      std::vector<TrdInstrmtLegGrp> no_legs{};
      std::string transact_time{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<MatchStatus> match_status{};
      std::optional<MatchType> match_type{};
      std::vector<TrdCapRptSideGrp> no_sides{};
      std::optional<bool> copy_msg_indicator{};
      std::optional<PublishTrdIndicator> publish_trd_indicator{};
      std::optional<ShortSaleReason> short_sale_reason{};
      bool operator==(const TradeCaptureReport&) const = default;
   };
   struct OrderMassStatusRequest
   {
      std::string mass_status_req_id{};
      MassStatusReqType mass_status_req_type{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> underlying_symbol{};
      std::optional<std::string> underlying_symbol_sfx{};
      std::optional<std::string> underlying_security_id{};
      std::optional<SecurityIDSource> underlying_security_id_source{};
      std::vector<UndSecAltIDGrp> no_underlying_security_alt_id{};
      std::optional<int64_t> underlying_product{};
      std::optional<std::string> underlying_cfi_code{};
      std::optional<std::string> underlying_security_type{};
      std::optional<std::string> underlying_security_sub_type{};
      std::optional<std::string> underlying_maturity_month_year{};
      std::optional<std::string> underlying_maturity_date{};
      std::optional<int64_t> underlying_put_or_call{};
      std::optional<std::string> underlying_coupon_payment_date{};
      std::optional<std::string> underlying_issue_date{};
      std::optional<std::string> underlying_repo_collateral_security_type{};
      std::optional<int64_t> underlying_repurchase_term{};
      std::optional<double> underlying_repurchase_rate{};
      std::optional<double> underlying_factor{};
      std::optional<std::string> underlying_credit_rating{};
      std::optional<std::string> underlying_instr_registry{};
      std::optional<std::string> underlying_country_of_issue{};
      std::optional<std::string> underlying_state_or_province_of_issue{};
      std::optional<std::string> underlying_locale_of_issue{};
      std::optional<std::string> underlying_redemption_date{};
      std::optional<double> underlying_strike_price{};
      std::optional<std::string> underlying_strike_currency{};
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
      std::optional<std::string> underlying_cp_program{};
      std::optional<std::string> underlying_cp_reg_type{};
      std::optional<std::string> underlying_currency{};
      std::optional<double> underlying_qty{};
      std::optional<double> underlying_px{};
      std::optional<double> underlying_dirty_price{};
      std::optional<double> underlying_end_price{};
      std::optional<double> underlying_start_value{};
      std::optional<double> underlying_current_value{};
      std::optional<double> underlying_end_value{};
      std::vector<UnderlyingStipulationsGrp> no_underlying_stips{};
      std::optional<Side> side{};
      bool operator==(const OrderMassStatusRequest&) const = default;
   };
   struct QuoteRequestReject
   {
      std::string quote_req_id{};
      std::optional<std::string> rfq_req_id{};
      QuoteRequestRejectReason quote_request_reject_reason{};
      std::vector<QuotReqRjctGrp> no_related_sym{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const QuoteRequestReject&) const = default;
   };
   struct RFQRequest
   {
      std::string rfq_req_id{};
      std::vector<RFQReqGrp> no_related_sym{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      bool operator==(const RFQRequest&) const = default;
   };
   struct QuoteStatusReport
   {
      std::optional<std::string> quote_status_req_id{};
      std::optional<std::string> quote_req_id{};
      std::string quote_id{};
      std::optional<std::string> quote_resp_id{};
      std::optional<QuoteType> quote_type{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<Side> side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<LegQuotStatGrp> no_legs{};
      std::vector<QuotQualGrp> no_quote_qualifiers{};
      std::optional<std::string> expire_time{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> mkt_bid_px{};
      std::optional<double> mkt_offer_px{};
      std::optional<double> min_bid_size{};
      std::optional<double> bid_size{};
      std::optional<double> min_offer_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<double> mid_px{};
      std::optional<double> bid_yield{};
      std::optional<double> mid_yield{};
      std::optional<double> offer_yield{};
      std::optional<std::string> transact_time{};
      std::optional<OrdType> ord_type{};
      std::optional<double> bid_forward_points2{};
      std::optional<double> offer_forward_points2{};
      std::optional<double> settl_curr_bid_fx_rate{};
      std::optional<double> settl_curr_offer_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<CommType> comm_type{};
      std::optional<double> commission{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<std::string> ex_destination{};
      std::optional<QuoteStatus> quote_status{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const QuoteStatusReport&) const = default;
   };
   struct QuoteResponse
   {
      std::string quote_resp_id{};
      std::optional<std::string> quote_id{};
      QuoteRespType quote_resp_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> ioiid{};
      std::optional<QuoteType> quote_type{};
      std::vector<QuotQualGrp> no_quote_qualifiers{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<Side> side{};
      std::optional<double> order_qty{};
      std::optional<double> cash_order_qty{};
      std::optional<double> order_percent{};
      std::optional<RoundingDirection> rounding_direction{};
      std::optional<double> rounding_modulus{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<std::string> settl_date2{};
      std::optional<double> order_qty2{};
      std::optional<std::string> currency{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::vector<LegQuotGrp> no_legs{};
      std::optional<double> bid_px{};
      std::optional<double> offer_px{};
      std::optional<double> mkt_bid_px{};
      std::optional<double> mkt_offer_px{};
      std::optional<double> min_bid_size{};
      std::optional<double> bid_size{};
      std::optional<double> min_offer_size{};
      std::optional<double> offer_size{};
      std::optional<std::string> valid_until_time{};
      std::optional<double> bid_spot_rate{};
      std::optional<double> offer_spot_rate{};
      std::optional<double> bid_forward_points{};
      std::optional<double> offer_forward_points{};
      std::optional<double> mid_px{};
      std::optional<double> bid_yield{};
      std::optional<double> mid_yield{};
      std::optional<double> offer_yield{};
      std::optional<std::string> transact_time{};
      std::optional<OrdType> ord_type{};
      std::optional<double> bid_forward_points2{};
      std::optional<double> offer_forward_points2{};
      std::optional<double> settl_curr_bid_fx_rate{};
      std::optional<double> settl_curr_offer_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<std::string> ex_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      bool operator==(const QuoteResponse&) const = default;
   };
   struct Confirmation
   {
      std::string confirm_id{};
      std::optional<std::string> confirm_ref_id{};
      std::optional<std::string> confirm_req_id{};
      ConfirmTransType confirm_trans_type{};
      ConfirmType confirm_type{};
      std::optional<bool> copy_msg_indicator{};
      std::optional<LegalConfirm> legal_confirm{};
      ConfirmStatus confirm_status{};
      std::vector<PartiesGrp> no_party_ids{};
      std::vector<OrdAllocGrp> no_orders{};
      std::optional<std::string> alloc_id{};
      std::optional<std::string> secondary_alloc_id{};
      std::optional<std::string> individual_alloc_id{};
      std::string transact_time{};
      std::string trade_date{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      double alloc_qty{};
      std::optional<QtyType> qty_type{};
      Side side{};
      std::optional<std::string> currency{};
      std::optional<std::string> last_mkt{};
      std::vector<CpctyConfGrp> no_capacities{};
      std::string alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<AllocAccountType> alloc_account_type{};
      double avg_px{};
      std::optional<int64_t> avg_px_precision{};
      std::optional<PriceType> price_type{};
      std::optional<double> avg_par_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<double> reported_px{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<ProcessCode> process_code{};
      double gross_trade_amt{};
      std::optional<int64_t> num_days_interest{};
      std::optional<std::string> ex_date{};
      std::optional<double> accrued_interest_rate{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> interest_at_maturity{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> concession{};
      std::optional<double> total_takedown{};
      double net_money{};
      std::optional<double> maturity_net_money{};
      std::optional<double> settl_curr_amt{};
      std::optional<std::string> settl_currency{};
      std::optional<double> settl_curr_fx_rate{};
      std::optional<SettlCurrFxRateCalc> settl_curr_fx_rate_calc{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      std::optional<double> commission{};
      std::optional<CommType> comm_type{};
      std::optional<std::string> comm_currency{};
      std::optional<FundRenewWaiv> fund_renew_waiv{};
      std::optional<double> shared_commission{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      bool operator==(const Confirmation&) const = default;
   };
   struct PositionMaintenanceRequest
   {
      std::string pos_req_id{};
      PosTransType pos_trans_type{};
      PosMaintAction pos_maint_action{};
      std::optional<std::string> orig_pos_req_ref_id{};
      std::optional<std::string> pos_maint_rpt_ref_id{};
      std::string clearing_business_date{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string account{};
      std::optional<AcctIDSource> acct_id_source{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::string transact_time{};
      std::vector<PositionQtyGrp> no_positions{};
      std::optional<AdjustmentType> adjustment_type{};
      std::optional<bool> contrary_instruction_indicator{};
      std::optional<bool> prior_spread_indicator{};
      std::optional<double> threshold_amount{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const PositionMaintenanceRequest&) const = default;
   };
   struct PositionMaintenanceReport
   {
      std::string pos_maint_rpt_id{};
      PosTransType pos_trans_type{};
      std::optional<std::string> pos_req_id{};
      PosMaintAction pos_maint_action{};
      std::string orig_pos_req_ref_id{};
      PosMaintStatus pos_maint_status{};
      std::optional<PosMaintResult> pos_maint_result{};
      std::string clearing_business_date{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string account{};
      std::optional<AcctIDSource> acct_id_source{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::string transact_time{};
      std::vector<PositionQtyGrp> no_positions{};
      std::vector<PositionAmountDataGrp> no_pos_amt{};
      std::optional<AdjustmentType> adjustment_type{};
      std::optional<double> threshold_amount{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const PositionMaintenanceReport&) const = default;
   };
   struct RequestForPositions
   {
      std::string pos_req_id{};
      PosReqType pos_req_type{};
      std::optional<MatchStatus> match_status{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string account{};
      std::optional<AcctIDSource> acct_id_source{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::string clearing_business_date{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::vector<TrdgSesGrp> no_trading_sessions{};
      std::string transact_time{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const RequestForPositions&) const = default;
   };
   struct RequestForPositionsAck
   {
      std::string pos_maint_rpt_id{};
      std::optional<std::string> pos_req_id{};
      std::optional<int64_t> total_num_pos_reports{};
      std::optional<UnsolicitedIndicator> unsolicited_indicator{};
      PosReqResult pos_req_result{};
      PosReqStatus pos_req_status{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string account{};
      std::optional<AcctIDSource> acct_id_source{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const RequestForPositionsAck&) const = default;
   };
   struct PositionReport
   {
      std::string pos_maint_rpt_id{};
      std::optional<std::string> pos_req_id{};
      std::optional<PosReqType> pos_req_type{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<int64_t> total_num_pos_reports{};
      std::optional<UnsolicitedIndicator> unsolicited_indicator{};
      PosReqResult pos_req_result{};
      std::string clearing_business_date{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string account{};
      std::optional<AcctIDSource> acct_id_source{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      double settl_price{};
      SettlPriceType settl_price_type{};
      double prior_settl_price{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<PosUndInstrmtGrp> no_underlyings{};
      std::vector<PositionQtyGrp> no_positions{};
      std::vector<PositionAmountDataGrp> no_pos_amt{};
      std::optional<RegistStatus> regist_status{};
      std::optional<std::string> delivery_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const PositionReport&) const = default;
   };
   struct TradeCaptureReportRequestAck
   {
      std::string trade_request_id{};
      TradeRequestType trade_request_type{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<int64_t> tot_num_trade_reports{};
      TradeRequestResult trade_request_result{};
      TradeRequestStatus trade_request_status{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::optional<MultiLegReportingType> multi_leg_reporting_type{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const TradeCaptureReportRequestAck&) const = default;
   };
   struct TradeCaptureReportAck
   {
      std::string trade_report_id{};
      std::optional<TradeReportTransType> trade_report_trans_type{};
      std::optional<TradeReportType> trade_report_type{};
      std::optional<TrdType> trd_type{};
      std::optional<int64_t> trd_sub_type{};
      std::optional<int64_t> secondary_trd_type{};
      std::optional<std::string> transfer_reason{};
      ExecType exec_type{};
      std::optional<std::string> trade_report_ref_id{};
      std::optional<std::string> secondary_trade_report_ref_id{};
      std::optional<TrdRptStatus> trd_rpt_status{};
      std::optional<TradeReportRejectReason> trade_report_reject_reason{};
      std::optional<std::string> secondary_trade_report_id{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<std::string> trade_link_id{};
      std::optional<std::string> trd_match_id{};
      std::optional<std::string> exec_id{};
      std::optional<std::string> secondary_exec_id{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> transact_time{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<TrdInstrmtLegGrp> no_legs{};
      std::optional<ClearingFeeIndicator> clearing_fee_indicator{};
      std::optional<OrderCapacity> order_capacity{};
      std::optional<std::string> order_restrictions{};
      std::optional<CustOrderCapacity> cust_order_capacity{};
      std::optional<std::string> account{};
      std::optional<AcctIDSource> acct_id_source{};
      std::optional<AccountType> account_type{};
      std::optional<PositionEffect> position_effect{};
      std::optional<PreallocMethod> prealloc_method{};
      std::vector<TrdAllocGrp> no_allocs{};
      bool operator==(const TradeCaptureReportAck&) const = default;
   };
   struct AllocationReport
   {
      std::string alloc_report_id{};
      std::optional<std::string> alloc_id{};
      AllocTransType alloc_trans_type{};
      std::optional<std::string> alloc_report_ref_id{};
      std::optional<AllocCancReplaceReason> alloc_canc_replace_reason{};
      std::optional<std::string> secondary_alloc_id{};
      AllocReportType alloc_report_type{};
      AllocStatus alloc_status{};
      std::optional<AllocRejCode> alloc_rej_code{};
      std::optional<std::string> ref_alloc_id{};
      std::optional<AllocIntermedReqType> alloc_intermed_req_type{};
      std::optional<std::string> alloc_link_id{};
      std::optional<AllocLinkType> alloc_link_type{};
      std::optional<std::string> booking_ref_id{};
      AllocNoOrdersType alloc_no_orders_type{};
      std::vector<OrdAllocGrp> no_orders{};
      std::vector<ExecAllocGrp> no_execs{};
      std::optional<PreviouslyReported> previously_reported{};
      std::optional<bool> reversal_indicator{};
      std::optional<MatchType> match_type{};
      Side side{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<DeliveryForm> delivery_form{};
      std::optional<double> pct_at_risk{};
      std::vector<AttrbGrp> no_instr_attrib{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<InstrmtLegGrp> no_legs{};
      double quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> last_mkt{};
      std::optional<std::string> trade_origination_date{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<PriceType> price_type{};
      double avg_px{};
      std::optional<double> avg_par_px{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::optional<std::string> currency{};
      std::optional<int64_t> avg_px_precision{};
      std::vector<PartiesGrp> no_party_ids{};
      std::string trade_date{};
      std::optional<std::string> transact_time{};
      std::optional<SettlType> settl_type{};
      std::optional<std::string> settl_date{};
      std::optional<BookingType> booking_type{};
      std::optional<double> gross_trade_amt{};
      std::optional<double> concession{};
      std::optional<double> total_takedown{};
      std::optional<double> net_money{};
      std::optional<PositionEffect> position_effect{};
      std::optional<bool> auto_accept_indicator{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::optional<int64_t> num_days_interest{};
      std::optional<double> accrued_interest_rate{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> total_accrued_interest_amt{};
      std::optional<double> interest_at_maturity{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<LegalConfirm> legal_confirm{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<YieldType> yield_type{};
      std::optional<double> yield{};
      std::optional<std::string> yield_calc_date{};
      std::optional<std::string> yield_redemption_date{};
      std::optional<double> yield_redemption_price{};
      std::optional<int64_t> yield_redemption_price_type{};
      std::optional<int64_t> tot_no_allocs{};
      std::optional<LastFragment> last_fragment{};
      std::vector<AllocGrp> no_allocs{};
      bool operator==(const AllocationReport&) const = default;
   };
   struct AllocationReportAck
   {
      std::string alloc_report_id{};
      std::string alloc_id{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> secondary_alloc_id{};
      std::optional<std::string> trade_date{};
      std::string transact_time{};
      AllocStatus alloc_status{};
      std::optional<AllocRejCode> alloc_rej_code{};
      std::optional<AllocReportType> alloc_report_type{};
      std::optional<AllocIntermedReqType> alloc_intermed_req_type{};
      std::optional<MatchStatus> match_status{};
      std::optional<Product> product{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      std::vector<AllocAckGrp> no_allocs{};
      bool operator==(const AllocationReportAck&) const = default;
   };
   struct ConfirmationAck
   {
      std::string confirm_id{};
      std::string trade_date{};
      std::string transact_time{};
      AffirmStatus affirm_status{};
      std::optional<ConfirmRejReason> confirm_rej_reason{};
      std::optional<MatchStatus> match_status{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const ConfirmationAck&) const = default;
   };
   struct SettlementInstructionRequest
   {
      std::string settl_inst_req_id{};
      std::string transact_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<Side> side{};
      std::optional<Product> product{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> cfi_code{};
      std::optional<std::string> effective_time{};
      std::optional<std::string> expire_time{};
      std::optional<std::string> last_update_time{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      bool operator==(const SettlementInstructionRequest&) const = default;
   };
   struct AssignmentReport
   {
      std::string asgn_rpt_id{};
      std::optional<int64_t> tot_num_assignment_reports{};
      std::optional<bool> last_rpt_requested{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      AccountType account_type{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::vector<PositionQtyGrp> no_positions{};
      std::vector<PositionAmountDataGrp> no_pos_amt{};
      std::optional<double> threshold_amount{};
      double settl_price{};
      SettlPriceType settl_price_type{};
      double underlying_settl_price{};
      std::optional<std::string> expire_date{};
      AssignmentMethod assignment_method{};
      std::optional<double> assignment_unit{};
      double open_interest{};
      ExerciseMethod exercise_method{};
      SettlSessID settl_sess_id{};
      std::string settl_sess_sub_id{};
      std::string clearing_business_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const AssignmentReport&) const = default;
   };
   struct CollateralRequest
   {
      std::string coll_req_id{};
      CollAsgnReason coll_asgn_reason{};
      std::string transact_time{};
      std::optional<std::string> expire_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtCollGrp> no_underlyings{};
      std::optional<double> margin_excess{};
      std::optional<double> total_net_value{};
      std::optional<double> cash_outstanding{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<Side> side{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::optional<std::string> clearing_business_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralRequest&) const = default;
   };
   struct CollateralAssignment
   {
      std::string coll_asgn_id{};
      std::optional<std::string> coll_req_id{};
      CollAsgnReason coll_asgn_reason{};
      CollAsgnTransType coll_asgn_trans_type{};
      std::optional<std::string> coll_asgn_ref_id{};
      std::string transact_time{};
      std::optional<std::string> expire_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtCollGrp> no_underlyings{};
      std::optional<double> margin_excess{};
      std::optional<double> total_net_value{};
      std::optional<double> cash_outstanding{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<Side> side{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::optional<std::string> clearing_business_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralAssignment&) const = default;
   };
   struct CollateralResponse
   {
      std::string coll_resp_id{};
      std::string coll_asgn_id{};
      std::optional<std::string> coll_req_id{};
      CollAsgnReason coll_asgn_reason{};
      std::optional<CollAsgnTransType> coll_asgn_trans_type{};
      CollAsgnRespType coll_asgn_resp_type{};
      std::optional<CollAsgnRejectReason> coll_asgn_reject_reason{};
      std::string transact_time{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtCollGrp> no_underlyings{};
      std::optional<double> margin_excess{};
      std::optional<double> total_net_value{};
      std::optional<double> cash_outstanding{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<Side> side{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralResponse&) const = default;
   };
   struct CollateralReport
   {
      std::string coll_rpt_id{};
      std::optional<std::string> coll_inquiry_id{};
      CollStatus coll_status{};
      std::optional<int64_t> tot_num_reports{};
      std::optional<bool> last_rpt_requested{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> margin_excess{};
      std::optional<double> total_net_value{};
      std::optional<double> cash_outstanding{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<Side> side{};
      std::vector<MiscFeesGrp> no_misc_fees{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::optional<std::string> clearing_business_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralReport&) const = default;
   };
   struct CollateralInquiry
   {
      std::string coll_inquiry_id{};
      std::vector<CollInqQualGrp> no_coll_inquiry_qualifier{};
      std::optional<SubscriptionRequestType> subscription_request_type{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<double> margin_excess{};
      std::optional<double> total_net_value{};
      std::optional<double> cash_outstanding{};
      std::vector<TrdRegTimestampsGrp> no_trd_reg_timestamps{};
      std::optional<Side> side{};
      std::optional<double> price{};
      std::optional<PriceType> price_type{};
      std::optional<double> accrued_interest_amt{};
      std::optional<double> end_accrued_interest_amt{};
      std::optional<double> start_cash{};
      std::optional<double> end_cash{};
      std::optional<double> spread{};
      std::optional<std::string> benchmark_curve_currency{};
      std::optional<BenchmarkCurveName> benchmark_curve_name{};
      std::optional<std::string> benchmark_curve_point{};
      std::optional<double> benchmark_price{};
      std::optional<int64_t> benchmark_price_type{};
      std::optional<std::string> benchmark_security_id{};
      std::optional<SecurityIDSource> benchmark_security_id_source{};
      std::vector<StipulationsGrp> no_stipulations{};
      std::optional<SettlDeliveryType> settl_delivery_type{};
      std::optional<StandInstDbType> stand_inst_db_type{};
      std::optional<std::string> stand_inst_db_name{};
      std::optional<std::string> stand_inst_db_id{};
      std::vector<DlvyInstGrp> no_dlvy_inst{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::optional<std::string> clearing_business_date{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralInquiry&) const = default;
   };
   struct NetworkCounterpartySystemStatusRequest
   {
      NetworkRequestType network_request_type{};
      std::string network_request_id{};
      std::vector<CompIDReqGrp> no_comp_ids{};
      bool operator==(const NetworkCounterpartySystemStatusRequest&) const = default;
   };
   struct NetworkCounterpartySystemStatusResponse
   {
      NetworkStatusResponseType network_status_response_type{};
      std::optional<std::string> network_request_id{};
      std::string network_response_id{};
      std::optional<std::string> last_network_response_id{};
      std::vector<CompIDStatGrp> no_comp_ids{};
      bool operator==(const NetworkCounterpartySystemStatusResponse&) const = default;
   };
   struct UserRequest
   {
      std::string user_request_id{};
      UserRequestType user_request_type{};
      std::string username{};
      std::optional<std::string> password{};
      std::optional<std::string> new_password{};
      std::optional<int64_t> raw_data_length{};
      std::optional<std::string> raw_data{};
      bool operator==(const UserRequest&) const = default;
   };
   struct UserResponse
   {
      std::string user_request_id{};
      std::string username{};
      std::optional<UserStatus> user_status{};
      std::optional<std::string> user_status_text{};
      bool operator==(const UserResponse&) const = default;
   };
   struct CollateralInquiryAck
   {
      std::string coll_inquiry_id{};
      CollInquiryStatus coll_inquiry_status{};
      std::optional<CollInquiryResult> coll_inquiry_result{};
      std::vector<CollInqQualGrp> no_coll_inquiry_qualifier{};
      std::optional<int64_t> tot_num_reports{};
      std::vector<PartiesGrp> no_party_ids{};
      std::optional<std::string> account{};
      std::optional<AccountType> account_type{};
      std::optional<std::string> cl_ord_id{};
      std::optional<std::string> order_id{};
      std::optional<std::string> secondary_order_id{};
      std::optional<std::string> secondary_cl_ord_id{};
      std::vector<ExecCollGrp> no_execs{};
      std::vector<TrdCollGrp> no_trades{};
      std::optional<std::string> symbol{};
      std::optional<std::string> symbol_sfx{};
      std::optional<std::string> security_id{};
      std::optional<SecurityIDSource> security_id_source{};
      std::vector<SecAltIDGrp> no_security_alt_id{};
      std::optional<Product> product{};
      std::optional<std::string> cfi_code{};
      std::optional<SecurityType> security_type{};
      std::optional<std::string> security_sub_type{};
      std::optional<std::string> maturity_month_year{};
      std::optional<std::string> maturity_date{};
      std::optional<PutOrCall> put_or_call{};
      std::optional<std::string> coupon_payment_date{};
      std::optional<std::string> issue_date{};
      std::optional<std::string> repo_collateral_security_type{};
      std::optional<int64_t> repurchase_term{};
      std::optional<double> repurchase_rate{};
      std::optional<double> factor{};
      std::optional<std::string> credit_rating{};
      std::optional<std::string> instr_registry{};
      std::optional<std::string> country_of_issue{};
      std::optional<std::string> state_or_province_of_issue{};
      std::optional<std::string> locale_of_issue{};
      std::optional<std::string> redemption_date{};
      std::optional<double> strike_price{};
      std::optional<std::string> strike_currency{};
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
      std::optional<std::string> pool{};
      std::optional<std::string> contract_settl_month{};
      std::optional<CPProgram> cp_program{};
      std::optional<std::string> cp_reg_type{};
      std::vector<EvntGrp> no_events{};
      std::optional<std::string> dated_date{};
      std::optional<std::string> interest_accrual_date{};
      std::optional<std::string> agreement_desc{};
      std::optional<std::string> agreement_id{};
      std::optional<std::string> agreement_date{};
      std::optional<std::string> agreement_currency{};
      std::optional<TerminationType> termination_type{};
      std::optional<std::string> start_date{};
      std::optional<std::string> end_date{};
      std::optional<DeliveryType> delivery_type{};
      std::optional<double> margin_ratio{};
      std::optional<std::string> settl_date{};
      std::optional<double> quantity{};
      std::optional<QtyType> qty_type{};
      std::optional<std::string> currency{};
      std::vector<InstrmtLegGrp> no_legs{};
      std::vector<UndInstrmtGrp> no_underlyings{};
      std::optional<std::string> trading_session_id{};
      std::optional<std::string> trading_session_sub_id{};
      std::optional<SettlSessID> settl_sess_id{};
      std::optional<std::string> settl_sess_sub_id{};
      std::optional<std::string> clearing_business_date{};
      std::optional<ResponseTransportType> response_transport_type{};
      std::optional<std::string> response_destination{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const CollateralInquiryAck&) const = default;
   };
   struct ConfirmationRequest
   {
      std::string confirm_req_id{};
      ConfirmType confirm_type{};
      std::vector<OrdAllocGrp> no_orders{};
      std::optional<std::string> alloc_id{};
      std::optional<std::string> secondary_alloc_id{};
      std::optional<std::string> individual_alloc_id{};
      std::string transact_time{};
      std::optional<std::string> alloc_account{};
      std::optional<AcctIDSource> alloc_acct_id_source{};
      std::optional<AllocAccountType> alloc_account_type{};
      std::optional<std::string> text{};
      std::optional<int64_t> encoded_text_len{};
      std::optional<std::string> encoded_text{};
      bool operator==(const ConfirmationRequest&) const = default;
   };
}

template <>
struct glz::meta<glz::fix::fix44::AccountType>
{
   using enum glz::fix::fix44::AccountType;
   static constexpr auto value = glz::enumerate(CarriedCustomerSide, CarriedNonCustomerSide, HouseTrader, FloorTrader, CarriedNonCustomerSideCrossMargined, HouseTraderCrossMargined, JointBackOfficeAccount);
   static constexpr std::array<std::string_view, 7> fix_values{"1", "2", "3", "4", "6", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::AcctIDSource>
{
   using enum glz::fix::fix44::AcctIDSource;
   static constexpr auto value = glz::enumerate(BIC, SIDCode, TFM, OMGEO, DTCCCode, Other);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::Adjustment>
{
   using enum glz::fix::fix44::Adjustment;
   static constexpr auto value = glz::enumerate(Cancel, Error, Correction);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::AdjustmentType>
{
   using enum glz::fix::fix44::AdjustmentType;
   static constexpr auto value = glz::enumerate(ProcessRequestAsMarginDisposition, DeltaPlus, DeltaMinus, Final);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::AdvSide>
{
   using enum glz::fix::fix44::AdvSide;
   static constexpr auto value = glz::enumerate(Buy, Sell, Cross, Trade);
   static constexpr std::array<std::string_view, 4> fix_values{"B", "S", "X", "T"};
};
template <>
struct glz::meta<glz::fix::fix44::AdvTransType>
{
   using enum glz::fix::fix44::AdvTransType;
   static constexpr auto value = glz::enumerate(New, Cancel, Replace);
   static constexpr std::array<std::string_view, 3> fix_values{"N", "C", "R"};
};
template <>
struct glz::meta<glz::fix::fix44::AffirmStatus>
{
   using enum glz::fix::fix44::AffirmStatus;
   static constexpr auto value = glz::enumerate(Received, ConfirmRejected, Affirmed);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::AggregatedBook>
{
   using enum glz::fix::fix44::AggregatedBook;
   static constexpr auto value = glz::enumerate(BookEntriesToBeAggregated, BookEntriesShouldNotBeAggregated);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocAccountType>
{
   using enum glz::fix::fix44::AllocAccountType;
   static constexpr auto value = glz::enumerate(CarriedCustomerSide, CarriedNonCustomerSide, HouseTrader, FloorTrader, CarriedNonCustomerSideCrossMargined, HouseTraderCrossMargined, JointBackOfficeAccount);
   static constexpr std::array<std::string_view, 7> fix_values{"1", "2", "3", "4", "6", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocCancReplaceReason>
{
   using enum glz::fix::fix44::AllocCancReplaceReason;
   static constexpr auto value = glz::enumerate(OriginalDetailsIncomplete, ChangeInUnderlyingOrderDetails, Other);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocHandlInst>
{
   using enum glz::fix::fix44::AllocHandlInst;
   static constexpr auto value = glz::enumerate(Match, Forward, ForwardAndMatch);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocIntermedReqType>
{
   using enum glz::fix::fix44::AllocIntermedReqType;
   static constexpr auto value = glz::enumerate(PendingAccept, PendingRelease, PendingReversal, Accept, BlockLevelReject, AccountLevelReject);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocLinkType>
{
   using enum glz::fix::fix44::AllocLinkType;
   static constexpr auto value = glz::enumerate(FXNetting, FXSwap);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocNoOrdersType>
{
   using enum glz::fix::fix44::AllocNoOrdersType;
   static constexpr auto value = glz::enumerate(NotSpecified, ExplicitListProvided);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocRejCode>
{
   using enum glz::fix::fix44::AllocRejCode;
   static constexpr auto value = glz::enumerate(UnknownAccount, IncorrectQuantity, IncorrectAveragePrice, UnknownExecutingBrokerMnemonic, CommissionDifference, UnknownOrderID, UnknownListID, OtherSeeText, IncorrectAllocatedQuantity, CalculationDifference, UnknownOrStaleExecID, MismatchedData, UnknownClOrdID, WarehouseRequestRejected);
   static constexpr std::array<std::string_view, 14> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocReportType>
{
   using enum glz::fix::fix44::AllocReportType;
   static constexpr auto value = glz::enumerate(SellsideCalculatedUsingPreliminary, SellsideCalculatedWithoutPreliminary, WarehouseRecap, RequestToIntermediary);
   static constexpr std::array<std::string_view, 4> fix_values{"3", "4", "5", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocSettlInstType>
{
   using enum glz::fix::fix44::AllocSettlInstType;
   static constexpr auto value = glz::enumerate(UseDefaultInstructions, DeriveFromParametersProvided, FullDetailsProvided, SSIDBIDsProvided, PhoneForInstructions);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocStatus>
{
   using enum glz::fix::fix44::AllocStatus;
   static constexpr auto value = glz::enumerate(Accepted, BlockLevelReject, AccountLevelReject, Received, Incomplete, RejectedByIntermediary);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocTransType>
{
   using enum glz::fix::fix44::AllocTransType;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::AllocType>
{
   using enum glz::fix::fix44::AllocType;
   static constexpr auto value = glz::enumerate(Calculated, Preliminary, ReadyToBook, WarehouseInstruction, RequestToIntermediary);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "5", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::ApplQueueAction>
{
   using enum glz::fix::fix44::ApplQueueAction;
   static constexpr auto value = glz::enumerate(NoActionTaken, QueueFlushed, OverlayLast, EndSession);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::ApplQueueResolution>
{
   using enum glz::fix::fix44::ApplQueueResolution;
   static constexpr auto value = glz::enumerate(NoActionTaken, QueueFlushed, OverlayLast, EndSession);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::AssignmentMethod>
{
   using enum glz::fix::fix44::AssignmentMethod;
   static constexpr auto value = glz::enumerate(Random, ProRata);
   static constexpr std::array<std::string_view, 2> fix_values{"R", "P"};
};
template <>
struct glz::meta<glz::fix::fix44::AvgPxIndicator>
{
   using enum glz::fix::fix44::AvgPxIndicator;
   static constexpr auto value = glz::enumerate(NoAveragePricing, Trade, LastTrade);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::BasisPxType>
{
   using enum glz::fix::fix44::BasisPxType;
   static constexpr auto value = glz::enumerate(ClosingPriceAtMorningSession, ClosingPrice, CurrentPrice, SQ, VWAPThroughADay, VWAPThroughAMorningSession, VWAPThroughAnAfternoonSession, VWAPThroughADayExcept, VWAPThroughAMorningSessionExcept, VWAPThroughAnAfternoonSessionExcept, Strike, Open, Others);
   static constexpr std::array<std::string_view, 13> fix_values{"2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "Z"};
};
template <>
struct glz::meta<glz::fix::fix44::BenchmarkCurveName>
{
   using enum glz::fix::fix44::BenchmarkCurveName;
   static constexpr auto value = glz::enumerate(EONIA, EUREPO, Euribor, FutureSWAP, LIBID, LIBOR, MuniAAA, OTHER, Pfandbriefe, SONIA, SWAP, Treasury);
   static constexpr std::array<std::string_view, 12> fix_values{"EONIA", "EUREPO", "Euribor", "FutureSWAP", "LIBID", "LIBOR", "MuniAAA", "OTHER", "Pfandbriefe", "SONIA", "SWAP", "Treasury"};
};
template <>
struct glz::meta<glz::fix::fix44::BidDescriptorType>
{
   using enum glz::fix::fix44::BidDescriptorType;
   static constexpr auto value = glz::enumerate(Sector, Country, Index);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::BidRequestTransType>
{
   using enum glz::fix::fix44::BidRequestTransType;
   static constexpr auto value = glz::enumerate(New, Cancel);
   static constexpr std::array<std::string_view, 2> fix_values{"N", "C"};
};
template <>
struct glz::meta<glz::fix::fix44::BidTradeType>
{
   using enum glz::fix::fix44::BidTradeType;
   static constexpr auto value = glz::enumerate(RiskTrade, VWAPGuarantee, Agency, GuaranteedClose);
   static constexpr std::array<std::string_view, 4> fix_values{"R", "G", "A", "J"};
};
template <>
struct glz::meta<glz::fix::fix44::BidType>
{
   using enum glz::fix::fix44::BidType;
   static constexpr auto value = glz::enumerate(NonDisclosed, Disclosed, NoBiddingProcess);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::BookingType>
{
   using enum glz::fix::fix44::BookingType;
   static constexpr auto value = glz::enumerate(RegularBooking, CFD, TotalReturnSwap);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::BookingUnit>
{
   using enum glz::fix::fix44::BookingUnit;
   static constexpr auto value = glz::enumerate(EachPartialExecutionIsABookableUnit, AggregatePartialExecutionsOnThisOrder, AggregateExecutionsForThisSymbol);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::BusinessRejectReason>
{
   using enum glz::fix::fix44::BusinessRejectReason;
   static constexpr auto value = glz::enumerate(Other, UnknownID, UnknownSecurity, UnsupportedMessageType, ApplicationNotAvailable, ConditionallyRequiredFieldMissing, NotAuthorized, DeliverToFirmNotAvailableAtThisTime);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::CPProgram>
{
   using enum glz::fix::fix44::CPProgram;
   static constexpr auto value = glz::enumerate(Program3a3, Program42, Other);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::CancellationRights>
{
   using enum glz::fix::fix44::CancellationRights;
   static constexpr auto value = glz::enumerate(Yes, NoExecutionOnly, NoWaiverAgreement, NoInstitutional);
   static constexpr std::array<std::string_view, 4> fix_values{"Y", "N", "M", "O"};
};
template <>
struct glz::meta<glz::fix::fix44::CashMargin>
{
   using enum glz::fix::fix44::CashMargin;
   static constexpr auto value = glz::enumerate(Cash, MarginOpen, MarginClose);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::ClearingFeeIndicator>
{
   using enum glz::fix::fix44::ClearingFeeIndicator;
   static constexpr auto value = glz::enumerate(CBOEMember, NonMemberAndCustomer, EquityMemberAndClearingMember, FullAndAssociateMember, Firms106HAnd106J, GIM, Lessee106FEmployees, AllOtherOwnershipTypes, FirstYearDelegate, SecondYearDelegate, ThirdYearDelegate, FourthYearDelegate, FifthYearDelegate, SixthYearDelegate);
   static constexpr std::array<std::string_view, 14> fix_values{"B", "C", "E", "F", "H", "I", "L", "M", "1", "2", "3", "4", "5", "9"};
};
template <>
struct glz::meta<glz::fix::fix44::ClearingInstruction>
{
   using enum glz::fix::fix44::ClearingInstruction;
   static constexpr auto value = glz::enumerate(ProcessNormally, ExcludeFromAllNetting, BilateralNettingOnly, ExClearing, SpecialTrade, MultilateralNetting, ClearAgainstCentralCounterparty, ExcludeFromCentralCounterparty, ManualMode, AutomaticPostingMode, AutomaticGiveUpMode, QualifiedServiceRepresentativeQSR, CustomerTrade, SelfClearing);
   static constexpr std::array<std::string_view, 14> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
};
template <>
struct glz::meta<glz::fix::fix44::CollAction>
{
   using enum glz::fix::fix44::CollAction;
   static constexpr auto value = glz::enumerate(Retain, Add, Remove);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::CollAsgnReason>
{
   using enum glz::fix::fix44::CollAsgnReason;
   static constexpr auto value = glz::enumerate(Initial, Scheduled, TimeWarning, MarginDeficiency, MarginExcess, ForwardCollateralDemand, EventOfDefault, AdverseTaxEvent);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::CollAsgnRejectReason>
{
   using enum glz::fix::fix44::CollAsgnRejectReason;
   static constexpr auto value = glz::enumerate(UnknownDeal, UnknownOrInvalidInstrument, UnauthorizedTransaction, InsufficientCollateral, InvalidTypeOfCollateral, ExcessiveSubstitution, Other);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::CollAsgnRespType>
{
   using enum glz::fix::fix44::CollAsgnRespType;
   static constexpr auto value = glz::enumerate(Received, Accepted, Declined, Rejected);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::CollAsgnTransType>
{
   using enum glz::fix::fix44::CollAsgnTransType;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel, Release, Reverse);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::CollInquiryQualifier>
{
   using enum glz::fix::fix44::CollInquiryQualifier;
   static constexpr auto value = glz::enumerate(TradeDate, GCInstrument, CollateralInstrument, SubstitutionEligible, NotAssigned, PartiallyAssigned, FullyAssigned, OutstandingTrades);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::CollInquiryResult>
{
   using enum glz::fix::fix44::CollInquiryResult;
   static constexpr auto value = glz::enumerate(Successful, InvalidOrUnknownInstrument, InvalidOrUnknownCollateralType, InvalidParties, InvalidTransportTypeRequested, InvalidDestinationRequested, NoCollateralFoundForTheTradeSpecified, NoCollateralFoundForTheOrderSpecified, CollateralInquiryTypeNotSupported, UnauthorizedForCollateralInquiry, Other);
   static constexpr std::array<std::string_view, 11> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::CollInquiryStatus>
{
   using enum glz::fix::fix44::CollInquiryStatus;
   static constexpr auto value = glz::enumerate(Accepted, AcceptedWithWarnings, Completed, CompletedWithWarnings, Rejected);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::CollStatus>
{
   using enum glz::fix::fix44::CollStatus;
   static constexpr auto value = glz::enumerate(Unassigned, PartiallyAssigned, AssignmentProposed, Assigned, Challenged);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::CommType>
{
   using enum glz::fix::fix44::CommType;
   static constexpr auto value = glz::enumerate(PerUnit, Percent, Absolute, PercentageWaivedCashDiscount, PercentageWaivedEnhancedUnits, PointsPerBondOrContract);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmRejReason>
{
   using enum glz::fix::fix44::ConfirmRejReason;
   static constexpr auto value = glz::enumerate(MismatchedAccount, MissingSettlementInstructions, Other);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmStatus>
{
   using enum glz::fix::fix44::ConfirmStatus;
   static constexpr auto value = glz::enumerate(Received, MismatchedAccount, MissingSettlementInstructions, Confirmed, RequestRejected);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmTransType>
{
   using enum glz::fix::fix44::ConfirmTransType;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmType>
{
   using enum glz::fix::fix44::ConfirmType;
   static constexpr auto value = glz::enumerate(Status, Confirmation, ConfirmationRequestRejected);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::ContAmtType>
{
   using enum glz::fix::fix44::ContAmtType;
   static constexpr auto value = glz::enumerate(CommissionAmount, CommissionPercent, InitialChargeAmount, InitialChargePercent, DiscountAmount, DiscountPercent, DilutionLevyAmount, DilutionLevyPercent, ExitChargeAmount, ExitChargePercent, FundBasedRenewalCommissionPercent, ProjectedFundValue, FundBasedRenewalCommissionOnOrder, FundBasedRenewalCommissionOnFund, NetSettlementAmount);
   static constexpr std::array<std::string_view, 15> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
};
template <>
struct glz::meta<glz::fix::fix44::CorporateAction>
{
   using enum glz::fix::fix44::CorporateAction;
   static constexpr auto value = glz::enumerate(ExDividend, ExDistribution, ExRights, New, ExInterest);
   static constexpr std::array<std::string_view, 5> fix_values{"A", "B", "C", "D", "E"};
};
template <>
struct glz::meta<glz::fix::fix44::CoveredOrUncovered>
{
   using enum glz::fix::fix44::CoveredOrUncovered;
   static constexpr auto value = glz::enumerate(Covered, Uncovered);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::CrossPrioritization>
{
   using enum glz::fix::fix44::CrossPrioritization;
   static constexpr auto value = glz::enumerate(None, BuySideIsPrioritized, SellSideIsPrioritized);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::CrossType>
{
   using enum glz::fix::fix44::CrossType;
   static constexpr auto value = glz::enumerate(CrossAON, CrossIOC, CrossOneSide, CrossSamePrice);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::CustOrderCapacity>
{
   using enum glz::fix::fix44::CustOrderCapacity;
   static constexpr auto value = glz::enumerate(MemberTradingForTheirOwnAccount, ClearingFirmTradingForItsProprietaryAccount, MemberTradingForAnotherMember, AllOther);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::CxlRejReason>
{
   using enum glz::fix::fix44::CxlRejReason;
   static constexpr auto value = glz::enumerate(TooLateToCancel, UnknownOrder, BrokerCredit, OrderAlreadyInPendingStatus, UnableToProcessOrderMassCancelRequest, OrigOrdModTime, DuplicateClOrdID, Other);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::CxlRejResponseTo>
{
   using enum glz::fix::fix44::CxlRejResponseTo;
   static constexpr auto value = glz::enumerate(OrderCancelRequest, OrderCancel);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::DKReason>
{
   using enum glz::fix::fix44::DKReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, WrongSide, QuantityExceedsOrder, NoMatchingOrder, PriceExceedsLimit, CalculationDifference, Other);
   static constexpr std::array<std::string_view, 7> fix_values{"A", "B", "C", "D", "E", "F", "Z"};
};
template <>
struct glz::meta<glz::fix::fix44::DayBookingInst>
{
   using enum glz::fix::fix44::DayBookingInst;
   static constexpr auto value = glz::enumerate(Auto, SpeakWithOrderInitiatorBeforeBooking, Accumulate);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::DeleteReason>
{
   using enum glz::fix::fix44::DeleteReason;
   static constexpr auto value = glz::enumerate(Cancellation, Error);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::DeliveryForm>
{
   using enum glz::fix::fix44::DeliveryForm;
   static constexpr auto value = glz::enumerate(BookEntry, Bearer);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::DeliveryType>
{
   using enum glz::fix::fix44::DeliveryType;
   static constexpr auto value = glz::enumerate(VersusPayment, Free, TriParty, HoldInCustody);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionInst>
{
   using enum glz::fix::fix44::DiscretionInst;
   static constexpr auto value = glz::enumerate(RelatedToDisplayedPrice, RelatedToMarketPrice, RelatedToPrimaryPrice, RelatedToLocalPrimaryPrice, RelatedToMidpointPrice, RelatedToLastTradePrice, RelatedToVWAP);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionLimitType>
{
   using enum glz::fix::fix44::DiscretionLimitType;
   static constexpr auto value = glz::enumerate(OrBetter, Strict, OrWorse);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionMoveType>
{
   using enum glz::fix::fix44::DiscretionMoveType;
   static constexpr auto value = glz::enumerate(Floating, Fixed);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionOffsetType>
{
   using enum glz::fix::fix44::DiscretionOffsetType;
   static constexpr auto value = glz::enumerate(Price, BasisPoints, Ticks, PriceTier);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionRoundDirection>
{
   using enum glz::fix::fix44::DiscretionRoundDirection;
   static constexpr auto value = glz::enumerate(MoreAggressive, MorePassive);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionScope>
{
   using enum glz::fix::fix44::DiscretionScope;
   static constexpr auto value = glz::enumerate(Local, National, Global, NationalExcludingLocal);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::DistribPaymentMethod>
{
   using enum glz::fix::fix44::DistribPaymentMethod;
   static constexpr auto value = glz::enumerate(CREST, NSCC, Euroclear, Clearstream, Cheque, TelegraphicTransfer, FedWire, DirectCredit, ACHCredit, BPAY, HighValueClearingSystemHVACS, ReinvestInFund);
   static constexpr std::array<std::string_view, 12> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
};
template <>
struct glz::meta<glz::fix::fix44::DlvyInstType>
{
   using enum glz::fix::fix44::DlvyInstType;
   static constexpr auto value = glz::enumerate(Securities, Cash);
   static constexpr std::array<std::string_view, 2> fix_values{"S", "C"};
};
template <>
struct glz::meta<glz::fix::fix44::DueToRelated>
{
   using enum glz::fix::fix44::DueToRelated;
   static constexpr auto value = glz::enumerate(RelatedToSecurityHalt, NotRelatedToSecurityHalt);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::EmailType>
{
   using enum glz::fix::fix44::EmailType;
   static constexpr auto value = glz::enumerate(New, Reply, AdminReply);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::EncryptMethod>
{
   using enum glz::fix::fix44::EncryptMethod;
   static constexpr auto value = glz::enumerate(None, PKCS, DES, PKCSDES, PGPDES, PGPDESMD5, PEM);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::EventType>
{
   using enum glz::fix::fix44::EventType;
   static constexpr auto value = glz::enumerate(Put, Call, Tender, SinkingFundCall, Other);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::ExchangeForPhysical>
{
   using enum glz::fix::fix44::ExchangeForPhysical;
   static constexpr auto value = glz::enumerate(True, False);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::ExecInst>
{
   using enum glz::fix::fix44::ExecInst;
   static constexpr auto value = glz::enumerate(NotHeld, Work, GoAlong, OverTheDay, Held, ParticipateDoNotInitiate, StrictScale, TryToScale, StayOnBidSide, StayOnOfferSide, NoCross, OKToCross, CallFirst, PercentOfVolume, DoNotIncrease, DoNotReduce, AllOrNone, ReinstateOnSystemFailure, InstitutionsOnly, ReinstateOnTradingHalt, CancelOnTradingHalt, LastPeg, MidPricePeg, NonNegotiable, OpeningPeg, MarketPeg, CancelOnSystemFailure, PrimaryPeg, Suspend, FixedPegToLocalBestBidOrOfferAtTimeOfOrder, CustomerDisplayInstruction, Netting, PegToVWAP, TradeAlong, TryToStop, CancelIfNotBest, TrailingStopPeg, StrictLimit, IgnorePriceValidityChecks, PegToLimitPrice, WorkToTargetStrategy);
   static constexpr std::array<std::string_view, 41> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e"};
};
template <>
struct glz::meta<glz::fix::fix44::ExecPriceType>
{
   using enum glz::fix::fix44::ExecPriceType;
   static constexpr auto value = glz::enumerate(BidPrice, CreationPrice, CreationPricePlusAdjustmentPercent, CreationPricePlusAdjustmentAmount, OfferPrice, OfferPriceMinusAdjustmentPercent, OfferPriceMinusAdjustmentAmount, SinglePrice);
   static constexpr std::array<std::string_view, 8> fix_values{"B", "C", "D", "E", "O", "P", "Q", "S"};
};
template <>
struct glz::meta<glz::fix::fix44::ExecRestatementReason>
{
   using enum glz::fix::fix44::ExecRestatementReason;
   static constexpr auto value = glz::enumerate(GTCorporateAction, GTRenewal, VerbalChange, RepricingOfOrder, BrokerOption, PartialDeclineOfOrderQty, CancelOnTradingHalt, CancelOnSystemFailure, Market, Canceled, WarehouseRecap, Other);
   static constexpr std::array<std::string_view, 12> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::ExecType>
{
   using enum glz::fix::fix44::ExecType;
   static constexpr auto value = glz::enumerate(New, DoneForDay, Canceled, Replaced, PendingCancel, Stopped, Rejected, Suspended, PendingNew, Calculated, Expired, Restated, PendingReplace, Trade, TradeCorrect, TradeCancel, OrderStatus);
   static constexpr std::array<std::string_view, 17> fix_values{"0", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I"};
};
template <>
struct glz::meta<glz::fix::fix44::ExerciseMethod>
{
   using enum glz::fix::fix44::ExerciseMethod;
   static constexpr auto value = glz::enumerate(Automatic, Manual);
   static constexpr std::array<std::string_view, 2> fix_values{"A", "M"};
};
template <>
struct glz::meta<glz::fix::fix44::ExpirationCycle>
{
   using enum glz::fix::fix44::ExpirationCycle;
   static constexpr auto value = glz::enumerate(ExpireOnTradingSessionClose, ExpireOnTradingSessionOpen);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::FinancialStatus>
{
   using enum glz::fix::fix44::FinancialStatus;
   static constexpr auto value = glz::enumerate(Bankrupt, PendingDelisting);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::ForexReq>
{
   using enum glz::fix::fix44::ForexReq;
   static constexpr auto value = glz::enumerate(ExecuteForexAfterSecurityTrade, DoNotExecuteForexAfterSecurityTrade);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::FundRenewWaiv>
{
   using enum glz::fix::fix44::FundRenewWaiv;
   static constexpr auto value = glz::enumerate(Yes, No);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::GTBookingInst>
{
   using enum glz::fix::fix44::GTBookingInst;
   static constexpr auto value = glz::enumerate(BookOutAllTradesOnDayOfExecution, AccumulateUntilFilledOrExpired, AccumulateUntilVerballlyNotifiedOtherwise);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::GapFillFlag>
{
   using enum glz::fix::fix44::GapFillFlag;
   static constexpr auto value = glz::enumerate(GapFillMessage, SequenceReset);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::HaltReason>
{
   using enum glz::fix::fix44::HaltReason;
   static constexpr auto value = glz::enumerate(OrderImbalance, EquipmentChangeover, NewsPending, NewsDissemination, OrderInflux, AdditionalInformation);
   static constexpr std::array<std::string_view, 6> fix_values{"I", "X", "P", "D", "E", "M"};
};
template <>
struct glz::meta<glz::fix::fix44::HandlInst>
{
   using enum glz::fix::fix44::HandlInst;
   static constexpr auto value = glz::enumerate(AutomatedExecutionNoIntervention, AutomatedExecutionInterventionOK, ManualOrder);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::IOINaturalFlag>
{
   using enum glz::fix::fix44::IOINaturalFlag;
   static constexpr auto value = glz::enumerate(Natural, NotNatural);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::IOIQltyInd>
{
   using enum glz::fix::fix44::IOIQltyInd;
   static constexpr auto value = glz::enumerate(Low, Medium, High);
   static constexpr std::array<std::string_view, 3> fix_values{"L", "M", "H"};
};
template <>
struct glz::meta<glz::fix::fix44::IOIQty>
{
   using enum glz::fix::fix44::IOIQty;
   static constexpr auto value = glz::enumerate(Small, Medium, Large);
   static constexpr std::array<std::string_view, 3> fix_values{"S", "M", "L"};
};
template <>
struct glz::meta<glz::fix::fix44::IOIQualifier>
{
   using enum glz::fix::fix44::IOIQualifier;
   static constexpr auto value = glz::enumerate(AllOrNone, MarketOnClose, AtTheClose, VWAP, InTouchWith, Limit, MoreBehind, AtTheOpen, TakingAPosition, AtTheMarket, ReadyToTrade, PortfolioShown, ThroughTheDay, Versus, Indication, CrossingOpportunity, AtTheMidpoint, PreOpen);
   static constexpr std::array<std::string_view, 18> fix_values{"A", "B", "C", "D", "I", "L", "M", "O", "P", "Q", "R", "S", "T", "V", "W", "X", "Y", "Z"};
};
template <>
struct glz::meta<glz::fix::fix44::IOITransType>
{
   using enum glz::fix::fix44::IOITransType;
   static constexpr auto value = glz::enumerate(New, Cancel, Replace);
   static constexpr std::array<std::string_view, 3> fix_values{"N", "C", "R"};
};
template <>
struct glz::meta<glz::fix::fix44::InViewOfCommon>
{
   using enum glz::fix::fix44::InViewOfCommon;
   static constexpr auto value = glz::enumerate(HaltWasDueToCommonStockBeingHalted, HaltWasNotRelatedToAHaltOfTheCommonStock);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::IncTaxInd>
{
   using enum glz::fix::fix44::IncTaxInd;
   static constexpr auto value = glz::enumerate(Net, Gross);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::InstrAttribType>
{
   using enum glz::fix::fix44::InstrAttribType;
   static constexpr auto value = glz::enumerate(Flat, ZeroCoupon, InterestBearing, NoPeriodicPayments, VariableRate, LessFeeForPut, SteppedCoupon, CouponPeriod, When, OriginalIssueDiscount, Callable, EscrowedToMaturity, EscrowedToRedemptionDate, PreRefunded, InDefault, Unrated, Taxable, Indexed, SubjectToAlternativeMinimumTax, OriginalIssueDiscountPrice, CallableBelowMaturityValue, CallableWithoutNotice, Text);
   static constexpr std::array<std::string_view, 23> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::LastCapacity>
{
   using enum glz::fix::fix44::LastCapacity;
   static constexpr auto value = glz::enumerate(Agent, CrossAsAgent, CrossAsPrincipal, Principal);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::LastFragment>
{
   using enum glz::fix::fix44::LastFragment;
   static constexpr auto value = glz::enumerate(LastMessage, NotLastMessage);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::LastLiquidityInd>
{
   using enum glz::fix::fix44::LastLiquidityInd;
   static constexpr auto value = glz::enumerate(AddedLiquidity, RemovedLiquidity, LiquidityRoutedOut);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::LegSwapType>
{
   using enum glz::fix::fix44::LegSwapType;
   static constexpr auto value = glz::enumerate(ParForPar, ModifiedDuration, Risk, Proceeds);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::LegalConfirm>
{
   using enum glz::fix::fix44::LegalConfirm;
   static constexpr auto value = glz::enumerate(LegalConfirm, DoesNotConsituteALegalConfirm);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::LiquidityIndType>
{
   using enum glz::fix::fix44::LiquidityIndType;
   static constexpr auto value = glz::enumerate(FiveDayMovingAverage, TwentyDayMovingAverage, NormalMarketSize, Other);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::ListExecInstType>
{
   using enum glz::fix::fix44::ListExecInstType;
   static constexpr auto value = glz::enumerate(Immediate, WaitForInstruction, SellDriven, BuyDrivenCashTopUp, BuyDrivenCashWithdraw);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::ListOrderStatus>
{
   using enum glz::fix::fix44::ListOrderStatus;
   static constexpr auto value = glz::enumerate(InBiddingProcess, ReceivedForExecution, Executing, Cancelling, Alert, AllDone, Reject);
   static constexpr std::array<std::string_view, 7> fix_values{"1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::ListStatusType>
{
   using enum glz::fix::fix44::ListStatusType;
   static constexpr auto value = glz::enumerate(Ack, Response, Timed, ExecStarted, AllDone, Alert);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::LocateReqd>
{
   using enum glz::fix::fix44::LocateReqd;
   static constexpr auto value = glz::enumerate(Yes, No);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::MDEntryType>
{
   using enum glz::fix::fix44::MDEntryType;
   static constexpr auto value = glz::enumerate(Bid, Offer, Trade, IndexValue, OpeningPrice, ClosingPrice, SettlementPrice, TradingSessionHighPrice, TradingSessionLowPrice, TradingSessionVWAPPrice, Imbalance, TradeVolume, OpenInterest);
   static constexpr std::array<std::string_view, 13> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};
};
template <>
struct glz::meta<glz::fix::fix44::MDImplicitDelete>
{
   using enum glz::fix::fix44::MDImplicitDelete;
   static constexpr auto value = glz::enumerate(Yes, No);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::MDReqRejReason>
{
   using enum glz::fix::fix44::MDReqRejReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, DuplicateMDReqID, InsufficientBandwidth, InsufficientPermissions, UnsupportedSubscriptionRequestType, UnsupportedMarketDepth, UnsupportedMDUpdateType, UnsupportedAggregatedBook, UnsupportedMDEntryType, UnsupportedTradingSessionID, UnsupportedScope, UnsupportedOpenCloseSettleFlag, UnsupportedMDImplicitDelete);
   static constexpr std::array<std::string_view, 13> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};
};
template <>
struct glz::meta<glz::fix::fix44::MDUpdateAction>
{
   using enum glz::fix::fix44::MDUpdateAction;
   static constexpr auto value = glz::enumerate(New, Change, Delete);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::MDUpdateType>
{
   using enum glz::fix::fix44::MDUpdateType;
   static constexpr auto value = glz::enumerate(FullRefresh, IncrementalRefresh);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::MassCancelRejectReason>
{
   using enum glz::fix::fix44::MassCancelRejectReason;
   static constexpr auto value = glz::enumerate(MassCancelNotSupported, InvalidOrUnknownSecurity, InvalidOrUnkownUnderlyingSecurity, InvalidOrUnknownProduct, InvalidOrUnknownCFICode, InvalidOrUnknownSecurityType, InvalidOrUnknownTradingSession, Other);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::MassCancelRequestType>
{
   using enum glz::fix::fix44::MassCancelRequestType;
   static constexpr auto value = glz::enumerate(CancelOrdersForASecurity, CancelOrdersForAnUnderlyingSecurity, CancelOrdersForAProduct, CancelOrdersForACFICode, CancelOrdersForASecurityType, CancelOrdersForATradingSession, CancelAllOrders);
   static constexpr std::array<std::string_view, 7> fix_values{"1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::MassCancelResponse>
{
   using enum glz::fix::fix44::MassCancelResponse;
   static constexpr auto value = glz::enumerate(CancelRequestRejected, CancelOrdersForASecurity, CancelOrdersForAnUnderlyingSecurity, CancelOrdersForAProduct, CancelOrdersForACFICode, CancelOrdersForASecurityType, CancelOrdersForATradingSession, CancelAllOrders);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::MassStatusReqType>
{
   using enum glz::fix::fix44::MassStatusReqType;
   static constexpr auto value = glz::enumerate(StatusForOrdersForASecurity, StatusForOrdersForAnUnderlyingSecurity, StatusForOrdersForAProduct, StatusForOrdersForACFICode, StatusForOrdersForASecurityType, StatusForOrdersForATradingSession, StatusForAllOrders, StatusForOrdersForAPartyID);
   static constexpr std::array<std::string_view, 8> fix_values{"1", "2", "3", "4", "5", "6", "7", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::MatchStatus>
{
   using enum glz::fix::fix44::MatchStatus;
   static constexpr auto value = glz::enumerate(Compared, Uncompared, AdvisoryOrAlert);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::MatchType>
{
   using enum glz::fix::fix44::MatchType;
   static constexpr auto value = glz::enumerate(ExactMatchPlus4BadgesExecTime, ExactMatchPlus4Badges, ExactMatchPlus2BadgesExecTime, ExactMatchPlus2Badges, ExactMatchPlusExecTime, StampedAdvisoriesOrSpecialistAccepts, A1ExactMatchSummarizedQuantity, A2ExactMatchSummarizedQuantity, A3ExactMatchSummarizedQuantity, A4ExactMatchSummarizedQuantity, A5ExactMatchSummarizedQuantity, ExactMatchMinusBadgesTimes, SummarizedMatchMinusBadgesTimes, OCSLockedIn, ACTAcceptedTrade, ACTDefaultTrade, ACTDefaultAfterM2, ACTM6Match);
   static constexpr std::array<std::string_view, 18> fix_values{"A1", "A2", "A3", "A4", "A5", "AQ", "S1", "S2", "S3", "S4", "S5", "M1", "M2", "MT", "M3", "M4", "M5", "M6"};
};
template <>
struct glz::meta<glz::fix::fix44::MessageEncoding>
{
   using enum glz::fix::fix44::MessageEncoding;
   static constexpr auto value = glz::enumerate(ISO2022JP, EUCJP, ShiftJIS, UTF8);
   static constexpr std::array<std::string_view, 4> fix_values{"ISO-2022-JP", "EUC-JP", "Shift_JIS", "UTF-8"};
};
template <>
struct glz::meta<glz::fix::fix44::MiscFeeBasis>
{
   using enum glz::fix::fix44::MiscFeeBasis;
   static constexpr auto value = glz::enumerate(Absolute, PerUnit, Percentage);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::MiscFeeType>
{
   using enum glz::fix::fix44::MiscFeeType;
   static constexpr auto value = glz::enumerate(Regulatory, Tax, LocalCommission, ExchangeFees, Stamp, Levy, Other, Markup, ConsumptionTax, PerTransaction, Conversion, Agent);
   static constexpr std::array<std::string_view, 12> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
};
template <>
struct glz::meta<glz::fix::fix44::MoneyLaunderingStatus>
{
   using enum glz::fix::fix44::MoneyLaunderingStatus;
   static constexpr auto value = glz::enumerate(Passed, NotChecked, ExemptBelowLimit, ExemptMoneyType, ExemptAuthorised);
   static constexpr std::array<std::string_view, 5> fix_values{"Y", "N", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::MsgDirection>
{
   using enum glz::fix::fix44::MsgDirection;
   static constexpr auto value = glz::enumerate(Send, Receive);
   static constexpr std::array<std::string_view, 2> fix_values{"S", "R"};
};
template <>
struct glz::meta<glz::fix::fix44::MsgType>
{
   using enum glz::fix::fix44::MsgType;
   static constexpr auto value = glz::enumerate(Heartbeat, TestRequest, ResendRequest, Reject, SequenceReset, Logout, IOI, Advertisement, ExecutionReport, OrderCancelReject, Logon, News, Email, NewOrderSingle, NewOrderList, OrderCancelRequest, OrderCancelReplaceRequest, OrderStatusRequest, AllocationInstruction, ListCancelRequest, ListExecute, ListStatusRequest, ListStatus, AllocationInstructionAck, DontKnowTrade, QuoteRequest, Quote, SettlementInstructions, MarketDataRequest, MarketDataSnapshotFullRefresh, MarketDataIncrementalRefresh, MarketDataRequestReject, QuoteCancel, QuoteStatusRequest, MassQuoteAcknowledgement, SecurityDefinitionRequest, SecurityDefinition, SecurityStatusRequest, SecurityStatus, TradingSessionStatusRequest, TradingSessionStatus, MassQuote, BusinessMessageReject, BidRequest, BidResponse, ListStrikePrice, XMLNonFIX, RegistrationInstructions, RegistrationInstructionsResponse, OrderMassCancelRequest, OrderMassCancelReport, NewOrderCross, CrossOrderCancelReplaceRequest, CrossOrderCancelRequest, SecurityTypeRequest, SecurityTypes, SecurityListRequest, SecurityList, DerivativeSecurityListRequest, DerivativeSecurityList, NewOrderMultileg, MultilegOrderCancelReplace, TradeCaptureReportRequest, TradeCaptureReport, OrderMassStatusRequest, QuoteRequestReject, RFQRequest, QuoteStatusReport, QuoteResponse, Confirmation, PositionMaintenanceRequest, PositionMaintenanceReport, RequestForPositions, RequestForPositionsAck, PositionReport, TradeCaptureReportRequestAck, TradeCaptureReportAck, AllocationReport, AllocationReportAck, ConfirmationAck, SettlementInstructionRequest, AssignmentReport, CollateralRequest, CollateralAssignment, CollateralResponse, CollateralReport, CollateralInquiry, NetworkCounterpartySystemStatusRequest, NetworkCounterpartySystemStatusResponse, UserRequest, UserResponse, CollateralInquiryAck, ConfirmationRequest);
   static constexpr std::array<std::string_view, 93> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN", "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX", "AY", "AZ", "BA", "BB", "BC", "BD", "BE", "BF", "BG", "BH"};
};
template <>
struct glz::meta<glz::fix::fix44::MultiLegReportingType>
{
   using enum glz::fix::fix44::MultiLegReportingType;
   static constexpr auto value = glz::enumerate(SingleSecurity, IndividualLegOfAMultiLegSecurity, MultiLegSecurity);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::MultiLegRptTypeReq>
{
   using enum glz::fix::fix44::MultiLegRptTypeReq;
   static constexpr auto value = glz::enumerate(ReportByMulitlegSecurityOnly, ReportByMultilegSecurityAndInstrumentLegs, ReportByInstrumentLegsOnly);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::NetGrossInd>
{
   using enum glz::fix::fix44::NetGrossInd;
   static constexpr auto value = glz::enumerate(Net, Gross);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::NetworkRequestType>
{
   using enum glz::fix::fix44::NetworkRequestType;
   static constexpr auto value = glz::enumerate(Snapshot, Subscribe, StopSubscribing, LevelOfDetail);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "4", "8"};
};
template <>
struct glz::meta<glz::fix::fix44::NetworkStatusResponseType>
{
   using enum glz::fix::fix44::NetworkStatusResponseType;
   static constexpr auto value = glz::enumerate(Full, IncrementalUpdate);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::NoSides>
{
   using enum glz::fix::fix44::NoSides;
   static constexpr auto value = glz::enumerate(OneSide, BothSides);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::NotifyBrokerOfCredit>
{
   using enum glz::fix::fix44::NotifyBrokerOfCredit;
   static constexpr auto value = glz::enumerate(DetailsShouldBeCommunicated, DetailsShouldNotBeCommunicated);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::OddLot>
{
   using enum glz::fix::fix44::OddLot;
   static constexpr auto value = glz::enumerate(TreatAsOddLot, TreatAsRoundLot);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::OpenCloseSettlFlag>
{
   using enum glz::fix::fix44::OpenCloseSettlFlag;
   static constexpr auto value = glz::enumerate(DailyOpen, SessionOpen, DeliverySettlementEntry, ExpectedEntry, EntryFromPreviousBusinessDay, TheoreticalPriceValue);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::OrdRejReason>
{
   using enum glz::fix::fix44::OrdRejReason;
   static constexpr auto value = glz::enumerate(BrokerCredit, UnknownSymbol, ExchangeClosed, OrderExceedsLimit, TooLateToEnter, UnknownOrder, DuplicateOrder, DuplicateOfAVerballyCommunicatedOrder, StaleOrder, TradeAlongRequired, InvalidInvestorID, UnsupportedOrderCharacteristic, SurveillanceOption, IncorrectQuantity, IncorrectAllocatedQuantity, UnknownAccount, Other);
   static constexpr std::array<std::string_view, 17> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::OrdStatus>
{
   using enum glz::fix::fix44::OrdStatus;
   static constexpr auto value = glz::enumerate(New, PartiallyFilled, Filled, DoneForDay, Canceled, Replaced, PendingCancel, Stopped, Rejected, Suspended, PendingNew, Calculated, Expired, AcceptedForBidding, PendingReplace);
   static constexpr std::array<std::string_view, 15> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E"};
};
template <>
struct glz::meta<glz::fix::fix44::OrdType>
{
   using enum glz::fix::fix44::OrdType;
   static constexpr auto value = glz::enumerate(Market, Limit, Stop, StopLimit, WithOrWithout, LimitOrBetter, LimitWithOrWithout, OnBasis, PreviouslyQuoted, PreviouslyIndicated, ForexSwap, Funari, MarketIfTouched, MarketWithLeftOverAsLimit, PreviousFundValuationPoint, NextFundValuationPoint, Pegged);
   static constexpr std::array<std::string_view, 17> fix_values{"1", "2", "3", "4", "6", "7", "8", "9", "D", "E", "G", "I", "J", "K", "L", "M", "P"};
};
template <>
struct glz::meta<glz::fix::fix44::OrderCapacity>
{
   using enum glz::fix::fix44::OrderCapacity;
   static constexpr auto value = glz::enumerate(Agency, Proprietary, Individual, Principal, RisklessPrincipal, AgentForOtherMember);
   static constexpr std::array<std::string_view, 6> fix_values{"A", "G", "I", "P", "R", "W"};
};
template <>
struct glz::meta<glz::fix::fix44::OrderRestrictions>
{
   using enum glz::fix::fix44::OrderRestrictions;
   static constexpr auto value = glz::enumerate(ProgramTrade, IndexArbitrage, NonIndexArbitrage, CompetingMarketMaker, ActingAsMarketMakerOrSpecialistInSecurity, ActingAsMarketMakerOrSpecialistInUnderlying, ForeignEntity, ExternalMarketParticipant, ExternalInterConnectedMarketLinkage, RisklessArbitrage);
   static constexpr std::array<std::string_view, 10> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "A"};
};
template <>
struct glz::meta<glz::fix::fix44::OwnerType>
{
   using enum glz::fix::fix44::OwnerType;
   static constexpr auto value = glz::enumerate(IndividualInvestor, PublicCompany, PrivateCompany, IndividualTrustee, CompanyTrustee, PensionPlan, CustodianUnderGiftsToMinorsAct, Trusts, Fiduciaries, NetworkingSubAccount, NonProfitOrganization, CorporateBody, Nominee);
   static constexpr std::array<std::string_view, 13> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
};
template <>
struct glz::meta<glz::fix::fix44::OwnershipType>
{
   using enum glz::fix::fix44::OwnershipType;
   static constexpr auto value = glz::enumerate(JointInvestors, TenantsInCommon, JointTrustees);
   static constexpr std::array<std::string_view, 3> fix_values{"J", "T", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::PartyIDSource>
{
   using enum glz::fix::fix44::PartyIDSource;
   static constexpr auto value = glz::enumerate(BIC, GeneralIdentifier, Proprietary, ISOCountryCode, SettlementEntityLocation, MIC, CSDParticipant, KoreanInvestorID, TaiwaneseForeignInvestorID, TaiwaneseTradingAcct, MalaysianCentralDepository, ChineseInvestorID, UKNationalInsuranceOrPensionNumber, USSocialSecurityNumber, USEmployerOrTaxIDNumber, AustralianBusinessNumber, AustralianTaxFileNumber, ISITCAcronym);
   static constexpr std::array<std::string_view, 18> fix_values{"B", "C", "D", "E", "F", "G", "H", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "I"};
};
template <>
struct glz::meta<glz::fix::fix44::PartyRole>
{
   using enum glz::fix::fix44::PartyRole;
   static constexpr auto value = glz::enumerate(ExecutingFirm, BrokerOfCredit, ClientID, ClearingFirm, InvestorID, IntroducingFirm, EnteringFirm, Locate, FundManagerClientID, SettlementLocation, OrderOriginationTrader, ExecutingTrader, OrderOriginationFirm, GiveupClearingFirm, CorrespondantClearingFirm, ExecutingSystem, ContraFirm, ContraClearingFirm, SponsoringFirm, UnderlyingContraFirm, ClearingOrganization, Exchange, CustomerAccount, CorrespondentClearingOrganization, CorrespondentBroker, Buyer, Custodian, Intermediary, Agent, SubCustodian, Beneficiary, InterestedParty, RegulatoryBody, LiquidityProvider, EnteringTrader, ContraTrader, PositionAccount);
   static constexpr std::array<std::string_view, 37> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38"};
};
template <>
struct glz::meta<glz::fix::fix44::PartySubIDType>
{
   using enum glz::fix::fix44::PartySubIDType;
   static constexpr auto value = glz::enumerate(Firm, Person, System, Application, FullLegalNameOfFirm, PostalAddress, PhoneNumber, EmailAddress, ContactName, SecuritiesAccountNumber, RegistrationNumber, RegisteredAddressForConfirmation, RegulatoryStatus, RegistrationName, CashAccountNumber, BIC, CSDParticipantMemberCode, RegisteredAddress, FundAccountName, TelexNumber, FaxNumber, SecuritiesAccountName, CashAccountName, Department, LocationDesk, PositionAccountType);
   static constexpr std::array<std::string_view, 26> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
};
template <>
struct glz::meta<glz::fix::fix44::PaymentMethod>
{
   using enum glz::fix::fix44::PaymentMethod;
   static constexpr auto value = glz::enumerate(CREST, NSCC, Euroclear, Clearstream, Cheque, TelegraphicTransfer, FedWire, DebitCard, DirectDebit, DirectCredit, CreditCard, ACHDebit, ACHCredit, BPAY, HighValueClearingSystem);
   static constexpr std::array<std::string_view, 15> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
};
template <>
struct glz::meta<glz::fix::fix44::PegLimitType>
{
   using enum glz::fix::fix44::PegLimitType;
   static constexpr auto value = glz::enumerate(OrBetter, Strict, OrWorse);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::PegMoveType>
{
   using enum glz::fix::fix44::PegMoveType;
   static constexpr auto value = glz::enumerate(Floating, Fixed);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::PegOffsetType>
{
   using enum glz::fix::fix44::PegOffsetType;
   static constexpr auto value = glz::enumerate(Price, BasisPoints, Ticks, PriceTier);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::PegRoundDirection>
{
   using enum glz::fix::fix44::PegRoundDirection;
   static constexpr auto value = glz::enumerate(MoreAggressive, MorePassive);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::PegScope>
{
   using enum glz::fix::fix44::PegScope;
   static constexpr auto value = glz::enumerate(Local, National, Global, NationalExcludingLocal);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::PosAmtType>
{
   using enum glz::fix::fix44::PosAmtType;
   static constexpr auto value = glz::enumerate(FinalMarkToMarketAmount, IncrementalMarkToMarketAmount, TradeVariationAmount, StartOfDayMarkToMarketAmount, PremiumAmount, CashResidualAmount, CashAmount, ValueAdjustedAmount);
   static constexpr std::array<std::string_view, 8> fix_values{"FMTM", "IMTM", "TVAR", "SMTM", "PREM", "CRES", "CASH", "VADJ"};
};
template <>
struct glz::meta<glz::fix::fix44::PosMaintAction>
{
   using enum glz::fix::fix44::PosMaintAction;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::PosMaintResult>
{
   using enum glz::fix::fix44::PosMaintResult;
   static constexpr auto value = glz::enumerate(SuccessfulCompletion, Rejected, Other);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::PosMaintStatus>
{
   using enum glz::fix::fix44::PosMaintStatus;
   static constexpr auto value = glz::enumerate(Accepted, AcceptedWithWarnings, Rejected, Completed, CompletedWithWarnings);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::PosQtyStatus>
{
   using enum glz::fix::fix44::PosQtyStatus;
   static constexpr auto value = glz::enumerate(Submitted, Accepted, Rejected);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::PosReqResult>
{
   using enum glz::fix::fix44::PosReqResult;
   static constexpr auto value = glz::enumerate(ValidRequest, InvalidOrUnsupportedRequest, NoPositionsFoundThatMatchCriteria, NotAuthorizedToRequestPositions, RequestForPositionNotSupported, Other);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::PosReqStatus>
{
   using enum glz::fix::fix44::PosReqStatus;
   static constexpr auto value = glz::enumerate(Completed, CompletedWithWarnings, Rejected);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::PosReqType>
{
   using enum glz::fix::fix44::PosReqType;
   static constexpr auto value = glz::enumerate(Positions, Trades, Exercises, Assignments);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::PosTransType>
{
   using enum glz::fix::fix44::PosTransType;
   static constexpr auto value = glz::enumerate(Exercise, DoNotExercise, PositionAdjustment, PositionChangeSubmission, Pledge);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::PosType>
{
   using enum glz::fix::fix44::PosType;
   static constexpr auto value = glz::enumerate(TransactionQuantity, IntraSpreadQty, InterSpreadQty, EndOfDayQty, StartOfDayQty, OptionExerciseQty, OptionAssignment, TransactionFromExercise, TransactionFromAssignment, PitTradeQty, TransferTradeQty, ElectronicTradeQty, AllocationTradeQty, AdjustmentQty, AsOfTradeQty, DeliveryQty, TotalTransactionQty, CrossMarginQty, IntegralSplit);
   static constexpr std::array<std::string_view, 19> fix_values{"TQ", "IAS", "IES", "FIN", "SOD", "EX", "AS", "TX", "TA", "PIT", "TRF", "ETR", "ALC", "PA", "ASF", "DLV", "TOT", "XM", "SPL"};
};
template <>
struct glz::meta<glz::fix::fix44::PositionEffect>
{
   using enum glz::fix::fix44::PositionEffect;
   static constexpr auto value = glz::enumerate(Open, Close, Rolled, FIFO);
   static constexpr std::array<std::string_view, 4> fix_values{"O", "C", "R", "F"};
};
template <>
struct glz::meta<glz::fix::fix44::PossDupFlag>
{
   using enum glz::fix::fix44::PossDupFlag;
   static constexpr auto value = glz::enumerate(PossibleDuplicate, OriginalTransmission);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::PossResend>
{
   using enum glz::fix::fix44::PossResend;
   static constexpr auto value = glz::enumerate(PossibleResend, OriginalTransmission);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::PreallocMethod>
{
   using enum glz::fix::fix44::PreallocMethod;
   static constexpr auto value = glz::enumerate(ProRata, DoNotProRata);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::PreviouslyReported>
{
   using enum glz::fix::fix44::PreviouslyReported;
   static constexpr auto value = glz::enumerate(PerviouslyReportedToCounterparty, NotReportedToCounterparty);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::PriceType>
{
   using enum glz::fix::fix44::PriceType;
   static constexpr auto value = glz::enumerate(Percentage, PerUnit, FixedAmount, Discount, Premium, Spread, TEDPrice, TEDYield, Yield, FixedCabinetTradePrice, VariableCabinetTradePrice);
   static constexpr std::array<std::string_view, 11> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
};
template <>
struct glz::meta<glz::fix::fix44::PriorityIndicator>
{
   using enum glz::fix::fix44::PriorityIndicator;
   static constexpr auto value = glz::enumerate(PriorityUnchanged, LostPriorityAsResultOfOrderChange);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::ProcessCode>
{
   using enum glz::fix::fix44::ProcessCode;
   static constexpr auto value = glz::enumerate(Regular, SoftDollar, StepIn, StepOut, SoftDollarStepIn, SoftDollarStepOut, PlanSponsor);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::Product>
{
   using enum glz::fix::fix44::Product;
   static constexpr auto value = glz::enumerate(AGENCY, COMMODITY, CORPORATE, CURRENCY, EQUITY, GOVERNMENT, INDEX, LOAN, MONEYMARKET, MORTGAGE, MUNICIPAL, OTHER, FINANCING);
   static constexpr std::array<std::string_view, 13> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
};
template <>
struct glz::meta<glz::fix::fix44::ProgRptReqs>
{
   using enum glz::fix::fix44::ProgRptReqs;
   static constexpr auto value = glz::enumerate(BuySideRequests, SellSideSends, RealTimeExecutionReports);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::PublishTrdIndicator>
{
   using enum glz::fix::fix44::PublishTrdIndicator;
   static constexpr auto value = glz::enumerate(ReportTrade, DoNotReportTrade);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::PutOrCall>
{
   using enum glz::fix::fix44::PutOrCall;
   static constexpr auto value = glz::enumerate(Put, Call);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::QtyType>
{
   using enum glz::fix::fix44::QtyType;
   static constexpr auto value = glz::enumerate(Units, Contracts);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteCancelType>
{
   using enum glz::fix::fix44::QuoteCancelType;
   static constexpr auto value = glz::enumerate(CancelForOneOrMoreSecurities, CancelForSecurityType, CancelForUnderlyingSecurity, CancelAllQuotes);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteCondition>
{
   using enum glz::fix::fix44::QuoteCondition;
   static constexpr auto value = glz::enumerate(Open, Closed, ExchangeBest, ConsolidatedBest, Locked, Crossed, Depth, FastTrading, NonFirm);
   static constexpr std::array<std::string_view, 9> fix_values{"A", "B", "C", "D", "E", "F", "G", "H", "I"};
};
template <>
struct glz::meta<glz::fix::fix44::QuotePriceType>
{
   using enum glz::fix::fix44::QuotePriceType;
   static constexpr auto value = glz::enumerate(Percent, PerShare, FixedAmount, Discount, Premium, Spread, TEDPrice, TEDYield, YieldSpread, Yield);
   static constexpr std::array<std::string_view, 10> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRejectReason>
{
   using enum glz::fix::fix44::QuoteRejectReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, Exchange, QuoteRequestExceedsLimit, TooLateToEnter, UnknownQuote, DuplicateQuote, InvalidBid, InvalidPrice, NotAuthorizedToQuoteSecurity, Other);
   static constexpr std::array<std::string_view, 10> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRequestRejectReason>
{
   using enum glz::fix::fix44::QuoteRequestRejectReason;
   static constexpr auto value = glz::enumerate(UnknownSymbol, Exchange, QuoteRequestExceedsLimit, TooLateToEnter, InvalidPrice, NotAuthorizedToRequestQuote, NoMatchForInquiry, NoMarketForInstrument, NoInventory, Pass, Other);
   static constexpr std::array<std::string_view, 11> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRequestType>
{
   using enum glz::fix::fix44::QuoteRequestType;
   static constexpr auto value = glz::enumerate(Manual, Automatic);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRespType>
{
   using enum glz::fix::fix44::QuoteRespType;
   static constexpr auto value = glz::enumerate(Hit, Counter, Expired, Cover, DoneAway, Pass);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteResponseLevel>
{
   using enum glz::fix::fix44::QuoteResponseLevel;
   static constexpr auto value = glz::enumerate(NoAcknowledgement, AcknowledgeOnlyNegativeOrErroneousQuotes, AcknowledgeEachQuoteMessage);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteStatus>
{
   using enum glz::fix::fix44::QuoteStatus;
   static constexpr auto value = glz::enumerate(Accepted, CancelForSymbol, CanceledForSecurityType, CanceledForUnderlying, CanceledAll, Rejected, RemovedFromMarket, Expired, Query, QuoteNotFound, Pending, Pass, LockedMarketWarning, CrossMarketWarning, CanceledDueToLockMarket, CanceledDueToCrossMarket);
   static constexpr std::array<std::string_view, 16> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
};
template <>
struct glz::meta<glz::fix::fix44::QuoteType>
{
   using enum glz::fix::fix44::QuoteType;
   static constexpr auto value = glz::enumerate(Indicative, Tradeable, RestrictedTradeable, Counter);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::RegistRejReasonCode>
{
   using enum glz::fix::fix44::RegistRejReasonCode;
   static constexpr auto value = glz::enumerate(InvalidAccountType, InvalidTaxExemptType, InvalidOwnershipType, NoRegDetails, InvalidRegSeqNo, InvalidRegDetails, InvalidMailingDetails, InvalidMailingInstructions, InvalidInvestorID, InvalidInvestorIDSource, InvalidDateOfBirth, InvalidCountry, InvalidDistribInstns, InvalidPercentage, InvalidPaymentMethod, InvalidAccountName, InvalidAgentCode, InvalidAccountNum, Other);
   static constexpr std::array<std::string_view, 19> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::RegistStatus>
{
   using enum glz::fix::fix44::RegistStatus;
   static constexpr auto value = glz::enumerate(Accepted, Rejected, Held, Reminder);
   static constexpr std::array<std::string_view, 4> fix_values{"A", "R", "H", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::RegistTransType>
{
   using enum glz::fix::fix44::RegistTransType;
   static constexpr auto value = glz::enumerate(New, Replace, Cancel);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::ReportToExch>
{
   using enum glz::fix::fix44::ReportToExch;
   static constexpr auto value = glz::enumerate(ReceiverReports, SenderReports);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::ResetSeqNumFlag>
{
   using enum glz::fix::fix44::ResetSeqNumFlag;
   static constexpr auto value = glz::enumerate(Yes, No);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::ResponseTransportType>
{
   using enum glz::fix::fix44::ResponseTransportType;
   static constexpr auto value = glz::enumerate(Inband, OutOfBand);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::RoundingDirection>
{
   using enum glz::fix::fix44::RoundingDirection;
   static constexpr auto value = glz::enumerate(RoundToNearest, RoundDown, RoundUp);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::RoutingType>
{
   using enum glz::fix::fix44::RoutingType;
   static constexpr auto value = glz::enumerate(TargetFirm, TargetList, BlockFirm, BlockList);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::Scope>
{
   using enum glz::fix::fix44::Scope;
   static constexpr auto value = glz::enumerate(LocalMarket, National, Global);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityIDSource>
{
   using enum glz::fix::fix44::SecurityIDSource;
   static constexpr auto value = glz::enumerate(CUSIP, SEDOL, QUIK, ISINNumber, RICCode, ISOCurrencyCode, ISOCountryCode, ExchangeSymbol, ConsolidatedTapeAssociation, BloombergSymbol, Wertpapier, Dutch, Valoren, Sicovam, Belgian, Common, ClearingHouse, ISDAFpMLSpecification, OptionPriceReportingAuthority);
   static constexpr std::array<std::string_view, 19> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityListRequestType>
{
   using enum glz::fix::fix44::SecurityListRequestType;
   static constexpr auto value = glz::enumerate(Symbol, SecurityTypeAnd, Product, TradingSessionID, AllSecurities);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityRequestResult>
{
   using enum glz::fix::fix44::SecurityRequestResult;
   static constexpr auto value = glz::enumerate(ValidRequest, InvalidOrUnsupportedRequest, NoInstrumentsFound, NotAuthorizedToRetrieveInstrumentData, InstrumentDataTemporarilyUnavailable, RequestForInstrumentDataNotSupported);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityRequestType>
{
   using enum glz::fix::fix44::SecurityRequestType;
   static constexpr auto value = glz::enumerate(RequestSecurityIdentityAndSpecifications, RequestSecurityIdentityForSpecifications, RequestListSecurityTypes, RequestListSecurities);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityResponseType>
{
   using enum glz::fix::fix44::SecurityResponseType;
   static constexpr auto value = glz::enumerate(AcceptAsIs, AcceptWithRevisions, RejectSecurityProposal, CannotMatchSelectionCriteria);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityTradingStatus>
{
   using enum glz::fix::fix44::SecurityTradingStatus;
   static constexpr auto value = glz::enumerate(OpeningDelay, TradingHalt, Resume, NoOpen, PriceIndication, TradingRangeIndication, MarketImbalanceBuy, MarketImbalanceSell, MarketOnCloseImbalanceBuy, MarketOnCloseImbalanceSell, NoMarketImbalance, NoMarketOnCloseImbalance, ITSPreOpening, NewPriceIndication, TradeDisseminationTime, ReadyToTrade, NotAvailableForTrading, NotTradedOnThisMarket, UnknownOrInvalid, PreOpen, OpeningRotation, FastMarket);
   static constexpr std::array<std::string_view, 22> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"};
};
template <>
struct glz::meta<glz::fix::fix44::SecurityType>
{
   using enum glz::fix::fix44::SecurityType;
   static constexpr auto value = glz::enumerate(EuroSupranationalCoupons, FederalAgencyCoupon, FederalAgencyDiscountNote, PrivateExportFunding, USDSupranationalCoupons, CorporateBond, CorporatePrivatePlacement, ConvertibleBond, DualCurrency, EuroCorporateBond, IndexedLinked, StructuredNotes, YankeeCorporateBond, ForeignExchangeContract, CommonStock, PreferredStock, BradyBond, EuroSovereigns, USTreasuryBond, InterestStripFromAnyBondOrNote, TreasuryInflationProtectedSecurities, PrincipalStripOfACallableBondOrNote, PrincipalStripFromANonCallableBondOrNote, USTreasuryNoteOld, USTreasuryBillOld, USTreasuryNote, USTreasuryBill, Repurchase, Forward, BuySellback, SecuritiesLoan, SecuritiesPledge, TermLoan, RevolverLoan, Revolver, BridgeLoan, LetterOfCredit, SwingLineFacility, DebtorInPossession, Defaulted, Withdrawn, Replaced, Matured, Amended, Retired, BankersAcceptance, BankNotes, BillOfExchanges, CertificateOfDeposit, CallLoans, CommercialPaper, DepositNotes, EuroCertificateOfDeposit, EuroCommercialPaper, LiquidityNote, MediumTermNotes, Overnight, PromissoryNote, PlazosFijos, ShortTermLoanNote, TimeDeposit, ExtendedCommNote, YankeeCertificateOfDeposit, AssetBackedSecurities, Corp, CollateralizedMortgageObligation, IOETTEMortgage, MortgageBackedSecurities, MortgageInterestOnly, MortgagePrincipalOnly, MortgagePrivatePlacement, MiscellaneousPassThrough, Pfandbriefe, ToBeAnnounced, OtherAnticipationNotes, CertificateOfObligation, CertificateOfParticipation, GeneralObligationBonds, MandatoryTender, RevenueAnticipationNote, RevenueBonds, SpecialAssessment, SpecialObligation, SpecialTax, TaxAnticipationNote, TaxAllocation, TaxExemptCommercialPaper, TaxRevenueAnticipationNote, VariableRateDemandNote, Warrant, MutualFund, MultilegInstrument, NoSecurityType, Future, Option);
   static constexpr std::array<std::string_view, 95> fix_values{"EUSUPRA", "FAC", "FADN", "PEF", "SUPRA", "CORP", "CPP", "CB", "DUAL", "EUCORP", "XLINKD", "STRUCT", "YANK", "FOR", "CS", "PS", "BRADY", "EUSOV", "TBOND", "TINT", "TIPS", "TCAL", "TPRN", "UST", "USTB", "TNOTE", "TBILL", "REPO", "FORWARD", "BUYSELL", "SECLOAN", "SECPLEDGE", "TERM", "RVLV", "RVLVTRM", "BRIDGE", "LOFC", "SWING", "DINP", "DEFLTED", "WITHDRN", "REPLACD", "MATURED", "AMENDED", "RETIRED", "BA", "BN", "BOX", "CD", "CL", "CP", "DN", "EUCD", "EUCP", "LQN", "MTN", "ONITE", "PN", "PZFJ", "STN", "TD", "XCN", "YCD", "ABS", "CMBS", "CMO", "IET", "MBS", "MIO", "MPO", "MPP", "MPT", "PFAND", "TBA", "AN", "COFO", "COFP", "GO", "MT", "RAN", "REV", "SPCLA", "SPCLO", "SPCLT", "TAN", "TAXA", "TECP", "TRAN", "VRDN", "WAR", "MF", "MLEG", "NONE", "FUT", "OPT"};
};
template <>
struct glz::meta<glz::fix::fix44::SessionRejectReason>
{
   using enum glz::fix::fix44::SessionRejectReason;
   static constexpr auto value = glz::enumerate(InvalidTagNumber, RequiredTagMissing, TagNotDefinedForThisMessageType, UndefinedTag, TagSpecifiedWithoutAValue, ValueIsIncorrect, IncorrectDataFormatForValue, DecryptionProblem, SignatureProblem, CompIDProblem, SendingTimeAccuracyProblem, InvalidMsgType, XMLValidationError, TagAppearsMoreThanOnce, TagSpecifiedOutOfRequiredOrder, RepeatingGroupFieldsOutOfOrder, IncorrectNumInGroupCountForRepeatingGroup, Non, Other);
   static constexpr std::array<std::string_view, 19> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlCurrFxRateCalc>
{
   using enum glz::fix::fix44::SettlCurrFxRateCalc;
   static constexpr auto value = glz::enumerate(Multiply, Divide);
   static constexpr std::array<std::string_view, 2> fix_values{"M", "D"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlDeliveryType>
{
   using enum glz::fix::fix44::SettlDeliveryType;
   static constexpr auto value = glz::enumerate(Versus, Free, TriParty, HoldInCustody);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstMode>
{
   using enum glz::fix::fix44::SettlInstMode;
   static constexpr auto value = glz::enumerate(StandingInstructionsProvided, SpecificOrderForASingleAccount, RequestReject);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstReqRejCode>
{
   using enum glz::fix::fix44::SettlInstReqRejCode;
   static constexpr auto value = glz::enumerate(UnableToProcessRequest, UnknownAccount, NoMatchingSettlementInstructionsFound, Other);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstSource>
{
   using enum glz::fix::fix44::SettlInstSource;
   static constexpr auto value = glz::enumerate(BrokerCredit, Institution, Investor);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstTransType>
{
   using enum glz::fix::fix44::SettlInstTransType;
   static constexpr auto value = glz::enumerate(New, Cancel, Replace, Restate);
   static constexpr std::array<std::string_view, 4> fix_values{"N", "C", "R", "T"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlPriceType>
{
   using enum glz::fix::fix44::SettlPriceType;
   static constexpr auto value = glz::enumerate(Final, Theoretical);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlSessID>
{
   using enum glz::fix::fix44::SettlSessID;
   static constexpr auto value = glz::enumerate(Intraday, RegularTradingHours, ElectronicTradingHours);
   static constexpr std::array<std::string_view, 3> fix_values{"ITD", "RTH", "ETH"};
};
template <>
struct glz::meta<glz::fix::fix44::SettlType>
{
   using enum glz::fix::fix44::SettlType;
   static constexpr auto value = glz::enumerate(Regular, Cash, NextDay, TPlus2, TPlus3, TPlus4, Future, WhenAndIfIssued, SellersOption, TPlus5);
   static constexpr std::array<std::string_view, 10> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
template <>
struct glz::meta<glz::fix::fix44::ShortSaleReason>
{
   using enum glz::fix::fix44::ShortSaleReason;
   static constexpr auto value = glz::enumerate(DealerSoldShort, DealerSoldShortExempt, SellingCustomerSoldShort, SellingCustomerSoldShortExempt, QualifiedServiceRepresentative, QSROrAGUContraSideSoldShortExempt);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::Side>
{
   using enum glz::fix::fix44::Side;
   static constexpr auto value = glz::enumerate(Buy, Sell, BuyMinus, SellPlus, SellShort, SellShortExempt, Undisclosed, Cross, CrossShort, CrossShortExempt, AsDefined, Opposite, Subscribe, Redeem, Lend, Borrow);
   static constexpr std::array<std::string_view, 16> fix_values{"1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G"};
};
template <>
struct glz::meta<glz::fix::fix44::SideMultiLegReportingType>
{
   using enum glz::fix::fix44::SideMultiLegReportingType;
   static constexpr auto value = glz::enumerate(SingleSecurity, IndividualLegOfAMultilegSecurity, MultilegSecurity);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::SideValueInd>
{
   using enum glz::fix::fix44::SideValueInd;
   static constexpr auto value = glz::enumerate(SideValue1, SideValue2);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::SolicitedFlag>
{
   using enum glz::fix::fix44::SolicitedFlag;
   static constexpr auto value = glz::enumerate(WasSolicited, WasNotSolicited);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::StandInstDbType>
{
   using enum glz::fix::fix44::StandInstDbType;
   static constexpr auto value = glz::enumerate(Other, DTCSID, ThomsonALERT, AGlobalCustodian, AccountNet);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::StatusValue>
{
   using enum glz::fix::fix44::StatusValue;
   static constexpr auto value = glz::enumerate(Connected, NotConnectedUnexpected, NotConnectedExpected, InProcess);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::StipulationType>
{
   using enum glz::fix::fix44::StipulationType;
   static constexpr auto value = glz::enumerate(AlternativeMinimumTax, AutoReinvestment, BankQualified, BargainConditions, CouponRange, ISOCurrencyCode, CustomStart, Geographics, ValuationDiscount, Insured, IssueDate, Issuer, IssueSizeRange, LookbackDays, ExplicitLotIdentifier, LotVariance, MaturityYearAndMonth, MaturityRange, MaximumSubstitutions, MinimumQuantity, MinimumIncrement, MinimumDenomination, PaymentFrequency, NumberOfPieces, PoolsMaximum, PoolsPerMillion, PoolsPerLot, PoolsPerTrade, PriceRange, PricingFrequency, ProductionYear, CallProtection, Purpose, BenchmarkPriceSource, RatingSourceAndRange, TypeOfRedemption, Restricted, MarketSector, SecurityTypeIncludedOrExcluded, Structure, SubstitutionsFrequency, SubstitutionsLeft, FreeformText, TradeVariance, WeightedAverageCoupon, WeightedAverageLifeCoupon, WeightedAverageLoanAge, WeightedAverageMaturity, WholePool, YieldRange);
   static constexpr std::array<std::string_view, 50> fix_values{"AMT", "AUTOREINV", "BANKQUAL", "BGNCON", "COUPON", "CURRENCY", "CUSTOMDATE", "GEOG", "HAIRCUT", "INSURED", "ISSUE", "ISSUER", "ISSUESIZE", "LOOKBACK", "LOT", "LOTVAR", "MAT", "MATURITY", "MAXSUBS", "MINQTY", "MININCR", "MINDNOM", "PAYFREQ", "PIECES", "PMAX", "PPM", "PPL", "PPT", "PRICE", "PRICEFREQ", "PROD", "PROTECT", "PURPOSE", "PXSOURCE", "RATING", "REDEMPTION", "RESTRICTED", "SECTOR", "SECTYPE", "STRUCT", "SUBSFREQ", "SUBSLEFT", "TEXT", "TRDVAR", "WAC", "WAL", "WALA", "WAM", "WHOLE", "YIELD"};
};
template <>
struct glz::meta<glz::fix::fix44::SubscriptionRequestType>
{
   using enum glz::fix::fix44::SubscriptionRequestType;
   static constexpr auto value = glz::enumerate(Snapshot, SnapshotAndUpdates, DisablePreviousSnapshot);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::TargetStrategy>
{
   using enum glz::fix::fix44::TargetStrategy;
   static constexpr auto value = glz::enumerate(VWAP, Participate, MininizeMarketImpact);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::TaxAdvantageType>
{
   using enum glz::fix::fix44::TaxAdvantageType;
   static constexpr auto value = glz::enumerate(None, MaxiISA, TESSA, MiniCashISA, MiniStocksAndSharesISA, MiniInsuranceISA, CurrentYearPayment, PriorYearPayment, AssetTransfer, EmployeePriorYear, EmployeeCurrentYear, EmployerPriorYear, EmployerCurrentYear, NonFundPrototypeIRA, NonFundQualifiedPlan, DefinedContributionPlan, IRA, IRARollover, KEOGH, ProfitSharingPlan, US401K, SelfDirectedIRA, US403b, US457, RothIRAPrototype, RothIRANonPrototype, RothConversionIRAPrototype, RothConversionIRANonPrototype, EducationIRAPrototype, EducationIRANonPrototype);
   static constexpr std::array<std::string_view, 30> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29"};
};
template <>
struct glz::meta<glz::fix::fix44::TerminationType>
{
   using enum glz::fix::fix44::TerminationType;
   static constexpr auto value = glz::enumerate(Overnight, Term, Flexible, Open);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::TestMessageIndicator>
{
   using enum glz::fix::fix44::TestMessageIndicator;
   static constexpr auto value = glz::enumerate(True, False);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::TickDirection>
{
   using enum glz::fix::fix44::TickDirection;
   static constexpr auto value = glz::enumerate(PlusTick, ZeroPlusTick, MinusTick, ZeroMinusTick);
   static constexpr std::array<std::string_view, 4> fix_values{"0", "1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::TimeInForce>
{
   using enum glz::fix::fix44::TimeInForce;
   static constexpr auto value = glz::enumerate(Day, GoodTillCancel, AtTheOpening, ImmediateOrCancel, FillOrKill, GoodTillCrossing, GoodTillDate, AtTheClose);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::TradSesMethod>
{
   using enum glz::fix::fix44::TradSesMethod;
   static constexpr auto value = glz::enumerate(Electronic, OpenOutcry, TwoParty);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::TradSesMode>
{
   using enum glz::fix::fix44::TradSesMode;
   static constexpr auto value = glz::enumerate(Testing, Simulated, Production);
   static constexpr std::array<std::string_view, 3> fix_values{"1", "2", "3"};
};
template <>
struct glz::meta<glz::fix::fix44::TradSesStatus>
{
   using enum glz::fix::fix44::TradSesStatus;
   static constexpr auto value = glz::enumerate(Unknown, Halted, Open, Closed, PreOpen, PreClose, RequestRejected);
   static constexpr std::array<std::string_view, 7> fix_values{"0", "1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::TradSesStatusRejReason>
{
   using enum glz::fix::fix44::TradSesStatusRejReason;
   static constexpr auto value = glz::enumerate(UnknownOrInvalidTradingSessionID, Other);
   static constexpr std::array<std::string_view, 2> fix_values{"1", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeAllocIndicator>
{
   using enum glz::fix::fix44::TradeAllocIndicator;
   static constexpr auto value = glz::enumerate(AllocationNotRequired, AllocationRequired, UseAllocationProvidedWithTheTrade);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeCondition>
{
   using enum glz::fix::fix44::TradeCondition;
   static constexpr auto value = glz::enumerate(Cash, AveragePriceTrade, CashTrade, NextDay, Opening, IntradayTradeDetail, Rule127Trade, Rule155Trade, SoldLast, NextDayTrade, Opened, Seller, Sold, StoppedStock, ImbalanceMoreBuyers, ImbalanceMoreSellers, OpeningPrice);
   static constexpr std::array<std::string_view, 17> fix_values{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "P", "Q", "R"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeReportRejectReason>
{
   using enum glz::fix::fix44::TradeReportRejectReason;
   static constexpr auto value = glz::enumerate(Successful, InvalidPartyOnformation, UnknownInstrument, UnauthorizedToReportTrades, InvalidTradeType, Other);
   static constexpr std::array<std::string_view, 6> fix_values{"0", "1", "2", "3", "4", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeReportTransType>
{
   using enum glz::fix::fix44::TradeReportTransType;
   static constexpr auto value = glz::enumerate(New, Cancel, Replace, Release, Reverse);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeReportType>
{
   using enum glz::fix::fix44::TradeReportType;
   static constexpr auto value = glz::enumerate(Submit, Alleged, Accept, Decline, Addendum, No, TradeReportCancel, LockedIn);
   static constexpr std::array<std::string_view, 8> fix_values{"0", "1", "2", "3", "4", "5", "6", "7"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeRequestResult>
{
   using enum glz::fix::fix44::TradeRequestResult;
   static constexpr auto value = glz::enumerate(Successful, InvalidOrUnknownInstrument, InvalidTypeOfTradeRequested, InvalidParties, InvalidTransportTypeRequested, InvalidDestinationRequested, TradeRequestTypeNotSupported, NotAuthorized, Other);
   static constexpr std::array<std::string_view, 9> fix_values{"0", "1", "2", "3", "4", "5", "8", "9", "99"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeRequestStatus>
{
   using enum glz::fix::fix44::TradeRequestStatus;
   static constexpr auto value = glz::enumerate(Accepted, Completed, Rejected);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::TradeRequestType>
{
   using enum glz::fix::fix44::TradeRequestType;
   static constexpr auto value = glz::enumerate(AllTrades, MatchedTradesMatchingCriteria, UnmatchedTradesThatMatchCriteria, UnreportedTradesThatMatchCriteria, AdvisoriesThatMatchCriteria);
   static constexpr std::array<std::string_view, 5> fix_values{"0", "1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::TradedFlatSwitch>
{
   using enum glz::fix::fix44::TradedFlatSwitch;
   static constexpr auto value = glz::enumerate(TradedFlat, NotTradedFlat);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::TrdRegTimestampType>
{
   using enum glz::fix::fix44::TrdRegTimestampType;
   static constexpr auto value = glz::enumerate(ExecutionTime, TimeIn, TimeOut, BrokerReceipt, BrokerExecution);
   static constexpr std::array<std::string_view, 5> fix_values{"1", "2", "3", "4", "5"};
};
template <>
struct glz::meta<glz::fix::fix44::TrdRptStatus>
{
   using enum glz::fix::fix44::TrdRptStatus;
   static constexpr auto value = glz::enumerate(Accepted, Rejected);
   static constexpr std::array<std::string_view, 2> fix_values{"0", "1"};
};
template <>
struct glz::meta<glz::fix::fix44::TrdType>
{
   using enum glz::fix::fix44::TrdType;
   static constexpr auto value = glz::enumerate(RegularTrade, BlockTrade, EFP, Transfer, LateTrade, TTrade, WeightedAveragePriceTrade, BunchedTrade, LateBunchedTrade, PriorReferencePriceTrade, AfterHoursTrade);
   static constexpr std::array<std::string_view, 11> fix_values{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
};
template <>
struct glz::meta<glz::fix::fix44::UnsolicitedIndicator>
{
   using enum glz::fix::fix44::UnsolicitedIndicator;
   static constexpr auto value = glz::enumerate(MessageIsBeingSentUnsolicited, MessageIsBeingSentAsAResultOfAPriorRequest);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::Urgency>
{
   using enum glz::fix::fix44::Urgency;
   static constexpr auto value = glz::enumerate(Normal, Flash, Background);
   static constexpr std::array<std::string_view, 3> fix_values{"0", "1", "2"};
};
template <>
struct glz::meta<glz::fix::fix44::UserRequestType>
{
   using enum glz::fix::fix44::UserRequestType;
   static constexpr auto value = glz::enumerate(LogOnUser, LogOffUser, ChangePasswordForUser, RequestIndividualUserStatus);
   static constexpr std::array<std::string_view, 4> fix_values{"1", "2", "3", "4"};
};
template <>
struct glz::meta<glz::fix::fix44::UserStatus>
{
   using enum glz::fix::fix44::UserStatus;
   static constexpr auto value = glz::enumerate(LoggedIn, NotLoggedIn, UserNotRecognised, PasswordIncorrect, PasswordChanged, Other);
   static constexpr std::array<std::string_view, 6> fix_values{"1", "2", "3", "4", "5", "6"};
};
template <>
struct glz::meta<glz::fix::fix44::WorkingIndicator>
{
   using enum glz::fix::fix44::WorkingIndicator;
   static constexpr auto value = glz::enumerate(Working, NotWorking);
   static constexpr std::array<std::string_view, 2> fix_values{"Y", "N"};
};
template <>
struct glz::meta<glz::fix::fix44::YieldType>
{
   using enum glz::fix::fix44::YieldType;
   static constexpr auto value = glz::enumerate(AfterTaxYield, AnnualYield, YieldAtIssue, YieldToAverageMaturity, BookYield, YieldToNextCall, YieldChangeSinceClose, ClosingYield, CompoundYield, CurrentYield, TrueGrossYield, GvntEquivalentYield, YieldWithInflationAssumption, InverseFloaterBondYield, MostRecentClosingYield, ClosingYieldMostRecentMonth, ClosingYieldMostRecentQuarter, ClosingYieldMostRecentYear, YieldToLongestAverageLife, MarkToMarketYield, YieldToMaturity, YieldToNextRefund, OpenAverageYield, YieldToNextPut, PreviousCloseYield, ProceedsYield, SemiAnnualYield, YieldToShortestAverageLife, SimpleYield, TaxEquivalentYield, YieldToTenderDate, TrueYield, YieldValueOf132, YieldToWorst);
   static constexpr std::array<std::string_view, 34> fix_values{"AFTERTAX", "ANNUAL", "ATISSUE", "AVGMATURITY", "BOOK", "CALL", "CHANGE", "CLOSE", "COMPOUND", "CURRENT", "GROSS", "GOVTEQUIV", "INFLATION", "INVERSEFLOATER", "LASTCLOSE", "LASTMONTH", "LASTQUARTER", "LASTYEAR", "LONGAVGLIFE", "MARK", "MATURITY", "NEXTREFUND", "OPENAVG", "PUT", "PREVCLOSE", "PROCEEDS", "SEMIANNUAL", "SHORTAVGLIFE", "SIMPLE", "TAXEQUIV", "TENDER", "TRUE", "VALUE1/32", "WORST"};
};

template <>
struct glz::meta<glz::fix::fix44::CommissionData>
{
   using T = glz::fix::fix44::CommissionData;
   static constexpr auto value = glz::object("12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv);
};
template <>
struct glz::meta<glz::fix::fix44::DiscretionInstructions>
{
   using T = glz::fix::fix44::DiscretionInstructions;
   static constexpr auto value = glz::object("388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope);
};
template <>
struct glz::meta<glz::fix::fix44::FinancingDetails>
{
   using T = glz::fix::fix44::FinancingDetails;
   static constexpr auto value = glz::object("913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio);
};
template <>
struct glz::meta<glz::fix::fix44::SecAltIDGrp>
{
   using T = glz::fix::fix44::SecAltIDGrp;
   static constexpr auto value = glz::object("455", &T::security_alt_id, "456", &T::security_alt_id_source);
};
template <>
struct glz::meta<glz::fix::fix44::EvntGrp>
{
   using T = glz::fix::fix44::EvntGrp;
   static constexpr auto value = glz::object("865", &T::event_type, "866", &T::event_date, "867", &T::event_px, "868", &T::event_text);
};
template <>
struct glz::meta<glz::fix::fix44::Instrument>
{
   using T = glz::fix::fix44::Instrument;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date);
};
template <>
struct glz::meta<glz::fix::fix44::AttrbGrp>
{
   using T = glz::fix::fix44::AttrbGrp;
   static constexpr auto value = glz::object("871", &T::instr_attrib_type, "872", &T::instr_attrib_value);
};
template <>
struct glz::meta<glz::fix::fix44::InstrumentExtension>
{
   using T = glz::fix::fix44::InstrumentExtension;
   static constexpr auto value = glz::object("668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib);
};
template <>
struct glz::meta<glz::fix::fix44::LegSecAltIDGrp>
{
   using T = glz::fix::fix44::LegSecAltIDGrp;
   static constexpr auto value = glz::object("605", &T::leg_security_alt_id, "606", &T::leg_security_alt_id_source);
};
template <>
struct glz::meta<glz::fix::fix44::InstrumentLeg>
{
   using T = glz::fix::fix44::InstrumentLeg;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date);
};
template <>
struct glz::meta<glz::fix::fix44::LegBenchmarkCurveData>
{
   using T = glz::fix::fix44::LegBenchmarkCurveData;
   static constexpr auto value = glz::object("676", &T::leg_benchmark_curve_currency, "677", &T::leg_benchmark_curve_name, "678", &T::leg_benchmark_curve_point, "679", &T::leg_benchmark_price, "680", &T::leg_benchmark_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::OrderQtyData>
{
   using T = glz::fix::fix44::OrderQtyData;
   static constexpr auto value = glz::object("38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus);
};
template <>
struct glz::meta<glz::fix::fix44::PegInstructions>
{
   using T = glz::fix::fix44::PegInstructions;
   static constexpr auto value = glz::object("211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope);
};
template <>
struct glz::meta<glz::fix::fix44::SettlPtysSubGrp>
{
   using T = glz::fix::fix44::SettlPtysSubGrp;
   static constexpr auto value = glz::object("785", &T::settl_party_sub_id, "786", &T::settl_party_sub_id_type);
};
template <>
struct glz::meta<glz::fix::fix44::SettlPartiesGrp>
{
   using T = glz::fix::fix44::SettlPartiesGrp;
   static constexpr auto value = glz::object("782", &T::settl_party_id, "783", &T::settl_party_id_source, "784", &T::settl_party_role, "801", &T::no_settl_party_sub_ids);
};
template <>
struct glz::meta<glz::fix::fix44::DlvyInstGrp>
{
   using T = glz::fix::fix44::DlvyInstGrp;
   static constexpr auto value = glz::object("165", &T::settl_inst_source, "787", &T::dlvy_inst_type, "781", &T::no_settl_party_ids);
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstructionsData>
{
   using T = glz::fix::fix44::SettlInstructionsData;
   static constexpr auto value = glz::object("172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst);
};
template <>
struct glz::meta<glz::fix::fix44::SpreadOrBenchmarkCurveData>
{
   using T = glz::fix::fix44::SpreadOrBenchmarkCurveData;
   static constexpr auto value = glz::object("218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source);
};
template <>
struct glz::meta<glz::fix::fix44::UndSecAltIDGrp>
{
   using T = glz::fix::fix44::UndSecAltIDGrp;
   static constexpr auto value = glz::object("458", &T::underlying_security_alt_id, "459", &T::underlying_security_alt_id_source);
};
template <>
struct glz::meta<glz::fix::fix44::UnderlyingStipulationsGrp>
{
   using T = glz::fix::fix44::UnderlyingStipulationsGrp;
   static constexpr auto value = glz::object("888", &T::underlying_stip_type, "889", &T::underlying_stip_value);
};
template <>
struct glz::meta<glz::fix::fix44::UnderlyingInstrument>
{
   using T = glz::fix::fix44::UnderlyingInstrument;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips);
};
template <>
struct glz::meta<glz::fix::fix44::YieldData>
{
   using T = glz::fix::fix44::YieldData;
   static constexpr auto value = glz::object("235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::HopGrp>
{
   using T = glz::fix::fix44::HopGrp;
   static constexpr auto value = glz::object("628", &T::hop_comp_id, "629", &T::hop_sending_time, "630", &T::hop_ref_id);
};
template <>
struct glz::meta<glz::fix::fix44::StandardHeader>
{
   using T = glz::fix::fix44::StandardHeader;
   static constexpr auto value = glz::object("8", &T::begin_string, "9", &T::body_length, "35", &T::msg_type, "49", &T::sender_comp_id, "56", &T::target_comp_id, "115", &T::on_behalf_of_comp_id, "128", &T::deliver_to_comp_id, "90", &T::secure_data_len, "91", &T::secure_data, "34", &T::msg_seq_num, "50", &T::sender_sub_id, "142", &T::sender_location_id, "57", &T::target_sub_id, "143", &T::target_location_id, "116", &T::on_behalf_of_sub_id, "144", &T::on_behalf_of_location_id, "129", &T::deliver_to_sub_id, "145", &T::deliver_to_location_id, "43", &T::poss_dup_flag, "97", &T::poss_resend, "52", &T::sending_time, "122", &T::orig_sending_time, "212", &T::xml_data_len, "213", &T::xml_data, "347", &T::message_encoding, "369", &T::last_msg_seq_num_processed, "627", &T::no_hops);
};
template <>
struct glz::meta<glz::fix::fix44::StandardTrailer>
{
   using T = glz::fix::fix44::StandardTrailer;
   static constexpr auto value = glz::object("93", &T::signature_length, "89", &T::signature, "10", &T::check_sum);
};
template <>
struct glz::meta<glz::fix::fix44::Heartbeat>
{
   using T = glz::fix::fix44::Heartbeat;
   static constexpr std::string_view fix_msg_type = "0";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fix44::TestRequest>
{
   using T = glz::fix::fix44::TestRequest;
   static constexpr std::string_view fix_msg_type = "1";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("112", &T::test_req_id);
};
template <>
struct glz::meta<glz::fix::fix44::ResendRequest>
{
   using T = glz::fix::fix44::ResendRequest;
   static constexpr std::string_view fix_msg_type = "2";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("7", &T::begin_seq_no, "16", &T::end_seq_no);
};
template <>
struct glz::meta<glz::fix::fix44::Reject>
{
   using T = glz::fix::fix44::Reject;
   static constexpr std::string_view fix_msg_type = "3";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "371", &T::ref_tag_id, "372", &T::ref_msg_type, "373", &T::session_reject_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::SequenceReset>
{
   using T = glz::fix::fix44::SequenceReset;
   static constexpr std::string_view fix_msg_type = "4";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("123", &T::gap_fill_flag, "36", &T::new_seq_no);
};
template <>
struct glz::meta<glz::fix::fix44::Logout>
{
   using T = glz::fix::fix44::Logout;
   static constexpr std::string_view fix_msg_type = "5";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::UndInstrmtGrp>
{
   using T = glz::fix::fix44::UndInstrmtGrp;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips);
};
template <>
struct glz::meta<glz::fix::fix44::StipulationsGrp>
{
   using T = glz::fix::fix44::StipulationsGrp;
   static constexpr auto value = glz::object("233", &T::stipulation_type, "234", &T::stipulation_value);
};
template <>
struct glz::meta<glz::fix::fix44::LegStipulationsGrp>
{
   using T = glz::fix::fix44::LegStipulationsGrp;
   static constexpr auto value = glz::object("688", &T::leg_stipulation_type, "689", &T::leg_stipulation_value);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtLegIOIGrp>
{
   using T = glz::fix::fix44::InstrmtLegIOIGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "682", &T::leg_ioi_qty, "683", &T::no_leg_stipulations);
};
template <>
struct glz::meta<glz::fix::fix44::IOIQualGrp>
{
   using T = glz::fix::fix44::IOIQualGrp;
   static constexpr auto value = glz::object("104", &T::ioi_qualifier);
};
template <>
struct glz::meta<glz::fix::fix44::RoutingGrp>
{
   using T = glz::fix::fix44::RoutingGrp;
   static constexpr auto value = glz::object("216", &T::routing_type, "217", &T::routing_id);
};
template <>
struct glz::meta<glz::fix::fix44::IOI>
{
   using T = glz::fix::fix44::IOI;
   static constexpr std::string_view fix_msg_type = "6";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("23", &T::ioiid, "28", &T::ioi_trans_type, "26", &T::ioi_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "27", &T::ioi_qty, "15", &T::currency, "232", &T::no_stipulations, "555", &T::no_legs, "423", &T::price_type, "44", &T::price, "62", &T::valid_until_time, "25", &T::ioi_qlty_ind, "130", &T::ioi_natural_flag, "199", &T::no_ioi_qualifiers, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "60", &T::transact_time, "149", &T::url_link, "215", &T::no_routing_ids, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtLegGrp>
{
   using T = glz::fix::fix44::InstrmtLegGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date);
};
template <>
struct glz::meta<glz::fix::fix44::Advertisement>
{
   using T = glz::fix::fix44::Advertisement;
   static constexpr std::string_view fix_msg_type = "7";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("2", &T::adv_id, "5", &T::adv_trans_type, "3", &T::adv_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "555", &T::no_legs, "711", &T::no_underlyings, "4", &T::adv_side, "53", &T::quantity, "854", &T::qty_type, "44", &T::price, "15", &T::currency, "75", &T::trade_date, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "149", &T::url_link, "30", &T::last_mkt, "336", &T::trading_session_id, "625", &T::trading_session_sub_id);
};
template <>
struct glz::meta<glz::fix::fix44::PtysSubGrp>
{
   using T = glz::fix::fix44::PtysSubGrp;
   static constexpr auto value = glz::object("523", &T::party_sub_id, "803", &T::party_sub_id_type);
};
template <>
struct glz::meta<glz::fix::fix44::PartiesGrp>
{
   using T = glz::fix::fix44::PartiesGrp;
   static constexpr auto value = glz::object("448", &T::party_id, "447", &T::party_id_source, "452", &T::party_role, "802", &T::no_party_sub_ids);
};
template <>
struct glz::meta<glz::fix::fix44::ContraGrp>
{
   using T = glz::fix::fix44::ContraGrp;
   static constexpr auto value = glz::object("375", &T::contra_broker, "337", &T::contra_trader, "437", &T::contra_trade_qty, "438", &T::contra_trade_time, "655", &T::contra_leg_ref_id);
};
template <>
struct glz::meta<glz::fix::fix44::ContAmtGrp>
{
   using T = glz::fix::fix44::ContAmtGrp;
   static constexpr auto value = glz::object("519", &T::cont_amt_type, "520", &T::cont_amt_value, "521", &T::cont_amt_curr);
};
template <>
struct glz::meta<glz::fix::fix44::NstdPtysSubGrp>
{
   using T = glz::fix::fix44::NstdPtysSubGrp;
   static constexpr auto value = glz::object("545", &T::nested_party_sub_id, "805", &T::nested_party_sub_id_type);
};
template <>
struct glz::meta<glz::fix::fix44::NestedPartiesGrp>
{
   using T = glz::fix::fix44::NestedPartiesGrp;
   static constexpr auto value = glz::object("524", &T::nested_party_id, "525", &T::nested_party_id_source, "538", &T::nested_party_role, "804", &T::no_nested_party_sub_ids);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtLegExecGrp>
{
   using T = glz::fix::fix44::InstrmtLegExecGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "683", &T::no_leg_stipulations, "564", &T::leg_position_effect, "565", &T::leg_covered_or_uncovered, "539", &T::no_nested_party_ids, "654", &T::leg_ref_id, "566", &T::leg_price, "587", &T::leg_settl_type, "588", &T::leg_settl_date, "637", &T::leg_last_px);
};
template <>
struct glz::meta<glz::fix::fix44::MiscFeesGrp>
{
   using T = glz::fix::fix44::MiscFeesGrp;
   static constexpr auto value = glz::object("137", &T::misc_fee_amt, "138", &T::misc_fee_curr, "139", &T::misc_fee_type, "891", &T::misc_fee_basis);
};
template <>
struct glz::meta<glz::fix::fix44::ExecutionReport>
{
   using T = glz::fix::fix44::ExecutionReport;
   static constexpr std::string_view fix_msg_type = "8";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "527", &T::secondary_exec_id, "11", &T::cl_ord_id, "41", &T::orig_cl_ord_id, "583", &T::cl_ord_link_id, "693", &T::quote_resp_id, "790", &T::ord_status_req_id, "584", &T::mass_status_req_id, "911", &T::tot_num_reports, "912", &T::last_rpt_requested, "453", &T::no_party_ids, "229", &T::trade_origination_date, "382", &T::no_contra_brokers, "66", &T::list_id, "548", &T::cross_id, "551", &T::orig_cross_id, "549", &T::cross_type, "17", &T::exec_id, "19", &T::exec_ref_id, "150", &T::exec_type, "39", &T::ord_status, "636", &T::working_indicator, "103", &T::ord_rej_reason, "378", &T::exec_restatement_reason, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "232", &T::no_stipulations, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "839", &T::pegged_price, "845", &T::discretion_price, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "850", &T::target_strategy_performance, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "18", &T::exec_inst, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "32", &T::last_qty, "652", &T::underlying_last_qty, "31", &T::last_px, "651", &T::underlying_last_px, "669", &T::last_par_px, "194", &T::last_spot_rate, "195", &T::last_forward_points, "30", &T::last_mkt, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "943", &T::time_bracket, "29", &T::last_capacity, "151", &T::leaves_qty, "14", &T::cum_qty, "6", &T::avg_px, "424", &T::day_order_qty, "425", &T::day_cum_qty, "426", &T::day_avg_px, "427", &T::gt_booking_inst, "75", &T::trade_date, "60", &T::transact_time, "113", &T::report_to_exch, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "381", &T::gross_trade_amt, "157", &T::num_days_interest, "230", &T::ex_date, "158", &T::accrued_interest_rate, "159", &T::accrued_interest_amt, "738", &T::interest_at_maturity, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "258", &T::traded_flat_switch, "259", &T::basis_feature_date, "260", &T::basis_feature_price, "238", &T::concession, "237", &T::total_takedown, "118", &T::net_money, "119", &T::settl_curr_amt, "120", &T::settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "21", &T::handl_inst, "110", &T::min_qty, "111", &T::max_floor, "77", &T::position_effect, "210", &T::max_show, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::settl_date2, "192", &T::order_qty2, "641", &T::last_forward_points2, "442", &T::multi_leg_reporting_type, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation, "483", &T::trans_bkd_time, "515", &T::exec_valuation_point, "484", &T::exec_price_type, "485", &T::exec_price_adjustment, "638", &T::priority_indicator, "639", &T::price_improvement, "851", &T::last_liquidity_ind, "518", &T::no_cont_amts, "555", &T::no_legs, "797", &T::copy_msg_indicator, "136", &T::no_misc_fees);
};
template <>
struct glz::meta<glz::fix::fix44::OrderCancelReject>
{
   using T = glz::fix::fix44::OrderCancelReject;
   static constexpr std::string_view fix_msg_type = "9";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "11", &T::cl_ord_id, "583", &T::cl_ord_link_id, "41", &T::orig_cl_ord_id, "39", &T::ord_status, "636", &T::working_indicator, "586", &T::orig_ord_mod_time, "66", &T::list_id, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "229", &T::trade_origination_date, "75", &T::trade_date, "60", &T::transact_time, "434", &T::cxl_rej_response_to, "102", &T::cxl_rej_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::MsgTypeGrp>
{
   using T = glz::fix::fix44::MsgTypeGrp;
   static constexpr auto value = glz::object("372", &T::ref_msg_type, "385", &T::msg_direction);
};
template <>
struct glz::meta<glz::fix::fix44::Logon>
{
   using T = glz::fix::fix44::Logon;
   static constexpr std::string_view fix_msg_type = "A";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("98", &T::encrypt_method, "108", &T::heart_bt_int, "95", &T::raw_data_length, "96", &T::raw_data, "141", &T::reset_seq_num_flag, "789", &T::next_expected_msg_seq_num, "383", &T::max_message_size, "384", &T::no_msg_types, "464", &T::test_message_indicator, "553", &T::username, "554", &T::password);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtGrp>
{
   using T = glz::fix::fix44::InstrmtGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date);
};
template <>
struct glz::meta<glz::fix::fix44::LinesOfTextGrp>
{
   using T = glz::fix::fix44::LinesOfTextGrp;
   static constexpr auto value = glz::object("58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::News>
{
   using T = glz::fix::fix44::News;
   static constexpr std::string_view fix_msg_type = "B";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("42", &T::orig_time, "61", &T::urgency, "148", &T::headline, "358", &T::encoded_headline_len, "359", &T::encoded_headline, "215", &T::no_routing_ids, "146", &T::no_related_sym, "555", &T::no_legs, "711", &T::no_underlyings, "33", &T::no_lines_of_text, "149", &T::url_link, "95", &T::raw_data_length, "96", &T::raw_data);
};
template <>
struct glz::meta<glz::fix::fix44::Email>
{
   using T = glz::fix::fix44::Email;
   static constexpr std::string_view fix_msg_type = "C";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("164", &T::email_thread_id, "94", &T::email_type, "42", &T::orig_time, "147", &T::subject, "356", &T::encoded_subject_len, "357", &T::encoded_subject, "215", &T::no_routing_ids, "146", &T::no_related_sym, "711", &T::no_underlyings, "555", &T::no_legs, "37", &T::order_id, "11", &T::cl_ord_id, "33", &T::no_lines_of_text, "95", &T::raw_data_length, "96", &T::raw_data);
};
template <>
struct glz::meta<glz::fix::fix44::PreAllocGrp>
{
   using T = glz::fix::fix44::PreAllocGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "661", &T::alloc_acct_id_source, "736", &T::alloc_settl_currency, "467", &T::individual_alloc_id, "539", &T::no_nested_party_ids, "80", &T::alloc_qty);
};
template <>
struct glz::meta<glz::fix::fix44::TrdgSesGrp>
{
   using T = glz::fix::fix44::TrdgSesGrp;
   static constexpr auto value = glz::object("336", &T::trading_session_id, "625", &T::trading_session_sub_id);
};
template <>
struct glz::meta<glz::fix::fix44::NewOrderSingle>
{
   using T = glz::fix::fix44::NewOrderSingle;
   static constexpr std::string_view fix_msg_type = "D";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "140", &T::prev_close_px, "54", &T::side, "114", &T::locate_reqd, "60", &T::transact_time, "232", &T::no_stipulations, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::settl_date2, "192", &T::order_qty2, "640", &T::price2, "77", &T::position_effect, "203", &T::covered_or_uncovered, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation);
};
template <>
struct glz::meta<glz::fix::fix44::ListOrdGrp>
{
   using T = glz::fix::fix44::ListOrdGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "67", &T::list_seq_no, "583", &T::cl_ord_link_id, "160", &T::settl_inst_mode, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "70", &T::alloc_id, "591", &T::prealloc_method, "78", &T::no_allocs, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "140", &T::prev_close_px, "54", &T::side, "401", &T::side_value_ind, "114", &T::locate_reqd, "60", &T::transact_time, "232", &T::no_stipulations, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::settl_date2, "192", &T::order_qty2, "640", &T::price2, "77", &T::position_effect, "203", &T::covered_or_uncovered, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "494", &T::designation);
};
template <>
struct glz::meta<glz::fix::fix44::NewOrderList>
{
   using T = glz::fix::fix44::NewOrderList;
   static constexpr std::string_view fix_msg_type = "E";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "390", &T::bid_id, "391", &T::client_bid_id, "414", &T::prog_rpt_reqs, "394", &T::bid_type, "415", &T::prog_period_interval, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "433", &T::list_exec_inst_type, "69", &T::list_exec_inst, "352", &T::encoded_list_exec_inst_len, "353", &T::encoded_list_exec_inst, "765", &T::allowable_one_sidedness_pct, "766", &T::allowable_one_sidedness_value, "767", &T::allowable_one_sidedness_curr, "68", &T::tot_no_orders, "893", &T::last_fragment, "73", &T::no_orders);
};
template <>
struct glz::meta<glz::fix::fix44::OrderCancelRequest>
{
   using T = glz::fix::fix44::OrderCancelRequest;
   static constexpr std::string_view fix_msg_type = "F";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("41", &T::orig_cl_ord_id, "37", &T::order_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "66", &T::list_id, "586", &T::orig_ord_mod_time, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "453", &T::no_party_ids, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "60", &T::transact_time, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "376", &T::compliance_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::OrderCancelReplaceRequest>
{
   using T = glz::fix::fix44::OrderCancelReplaceRequest;
   static constexpr std::string_view fix_msg_type = "G";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "41", &T::orig_cl_ord_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "66", &T::list_id, "586", &T::orig_ord_mod_time, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "60", &T::transact_time, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "376", &T::compliance_id, "377", &T::solicited_flag, "15", &T::currency, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "193", &T::settl_date2, "192", &T::order_qty2, "640", &T::price2, "77", &T::position_effect, "203", &T::covered_or_uncovered, "210", &T::max_show, "114", &T::locate_reqd, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation);
};
template <>
struct glz::meta<glz::fix::fix44::OrderStatusRequest>
{
   using T = glz::fix::fix44::OrderStatusRequest;
   static constexpr std::string_view fix_msg_type = "H";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "453", &T::no_party_ids, "790", &T::ord_status_req_id, "1", &T::account, "660", &T::acct_id_source, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side);
};
template <>
struct glz::meta<glz::fix::fix44::NstdPtys2SubGrp>
{
   using T = glz::fix::fix44::NstdPtys2SubGrp;
   static constexpr auto value = glz::object("760", &T::nested2_party_sub_id, "807", &T::nested2_party_sub_id_type);
};
template <>
struct glz::meta<glz::fix::fix44::NestedParties2Grp>
{
   using T = glz::fix::fix44::NestedParties2Grp;
   static constexpr auto value = glz::object("757", &T::nested2_party_id, "758", &T::nested2_party_id_source, "759", &T::nested2_party_role, "806", &T::no_nested2_party_sub_ids);
};
template <>
struct glz::meta<glz::fix::fix44::OrdAllocGrp>
{
   using T = glz::fix::fix44::OrdAllocGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "66", &T::list_id, "756", &T::no_nested2_party_ids, "38", &T::order_qty, "799", &T::order_avg_px, "800", &T::order_booking_qty);
};
template <>
struct glz::meta<glz::fix::fix44::ExecAllocGrp>
{
   using T = glz::fix::fix44::ExecAllocGrp;
   static constexpr auto value = glz::object("32", &T::last_qty, "17", &T::exec_id, "527", &T::secondary_exec_id, "31", &T::last_px, "669", &T::last_par_px, "29", &T::last_capacity);
};
template <>
struct glz::meta<glz::fix::fix44::ClrInstGrp>
{
   using T = glz::fix::fix44::ClrInstGrp;
   static constexpr auto value = glz::object("577", &T::clearing_instruction);
};
template <>
struct glz::meta<glz::fix::fix44::AllocGrp>
{
   using T = glz::fix::fix44::AllocGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "661", &T::alloc_acct_id_source, "573", &T::match_status, "366", &T::alloc_price, "80", &T::alloc_qty, "467", &T::individual_alloc_id, "81", &T::process_code, "539", &T::no_nested_party_ids, "208", &T::notify_broker_of_credit, "209", &T::alloc_handl_inst, "161", &T::alloc_text, "360", &T::encoded_alloc_text_len, "361", &T::encoded_alloc_text, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "153", &T::alloc_avg_px, "154", &T::alloc_net_money, "119", &T::settl_curr_amt, "737", &T::alloc_settl_curr_amt, "120", &T::settl_currency, "736", &T::alloc_settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "742", &T::alloc_accrued_interest_amt, "741", &T::alloc_interest_at_maturity, "136", &T::no_misc_fees, "576", &T::no_clearing_instructions, "780", &T::alloc_settl_inst_type, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst);
};
template <>
struct glz::meta<glz::fix::fix44::AllocationInstruction>
{
   using T = glz::fix::fix44::AllocationInstruction;
   static constexpr std::string_view fix_msg_type = "J";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("70", &T::alloc_id, "71", &T::alloc_trans_type, "626", &T::alloc_type, "793", &T::secondary_alloc_id, "72", &T::ref_alloc_id, "796", &T::alloc_canc_replace_reason, "808", &T::alloc_intermed_req_type, "196", &T::alloc_link_id, "197", &T::alloc_link_type, "466", &T::booking_ref_id, "857", &T::alloc_no_orders_type, "73", &T::no_orders, "124", &T::no_execs, "570", &T::previously_reported, "700", &T::reversal_indicator, "574", &T::match_type, "54", &T::side, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "53", &T::quantity, "854", &T::qty_type, "30", &T::last_mkt, "229", &T::trade_origination_date, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "423", &T::price_type, "6", &T::avg_px, "860", &T::avg_par_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "15", &T::currency, "74", &T::avg_px_precision, "453", &T::no_party_ids, "75", &T::trade_date, "60", &T::transact_time, "63", &T::settl_type, "64", &T::settl_date, "775", &T::booking_type, "381", &T::gross_trade_amt, "238", &T::concession, "237", &T::total_takedown, "118", &T::net_money, "77", &T::position_effect, "754", &T::auto_accept_indicator, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "157", &T::num_days_interest, "158", &T::accrued_interest_rate, "159", &T::accrued_interest_amt, "540", &T::total_accrued_interest_amt, "738", &T::interest_at_maturity, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "650", &T::legal_confirm, "232", &T::no_stipulations, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "892", &T::tot_no_allocs, "893", &T::last_fragment, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::ListCancelRequest>
{
   using T = glz::fix::fix44::ListCancelRequest;
   static constexpr std::string_view fix_msg_type = "K";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "60", &T::transact_time, "229", &T::trade_origination_date, "75", &T::trade_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ListExecute>
{
   using T = glz::fix::fix44::ListExecute;
   static constexpr std::string_view fix_msg_type = "L";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "391", &T::client_bid_id, "390", &T::bid_id, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ListStatusRequest>
{
   using T = glz::fix::fix44::ListStatusRequest;
   static constexpr std::string_view fix_msg_type = "M";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::OrdListStatGrp>
{
   using T = glz::fix::fix44::OrdListStatGrp;
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "14", &T::cum_qty, "39", &T::ord_status, "636", &T::working_indicator, "151", &T::leaves_qty, "84", &T::cxl_qty, "6", &T::avg_px, "103", &T::ord_rej_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ListStatus>
{
   using T = glz::fix::fix44::ListStatus;
   static constexpr std::string_view fix_msg_type = "N";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "429", &T::list_status_type, "82", &T::no_rpts, "431", &T::list_order_status, "83", &T::rpt_seq, "444", &T::list_status_text, "445", &T::encoded_list_status_text_len, "446", &T::encoded_list_status_text, "60", &T::transact_time, "68", &T::tot_no_orders, "893", &T::last_fragment, "73", &T::no_orders);
};
template <>
struct glz::meta<glz::fix::fix44::AllocAckGrp>
{
   using T = glz::fix::fix44::AllocAckGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "661", &T::alloc_acct_id_source, "366", &T::alloc_price, "467", &T::individual_alloc_id, "776", &T::individual_alloc_rej_code, "161", &T::alloc_text, "360", &T::encoded_alloc_text_len, "361", &T::encoded_alloc_text);
};
template <>
struct glz::meta<glz::fix::fix44::AllocationInstructionAck>
{
   using T = glz::fix::fix44::AllocationInstructionAck;
   static constexpr std::string_view fix_msg_type = "P";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("70", &T::alloc_id, "453", &T::no_party_ids, "793", &T::secondary_alloc_id, "75", &T::trade_date, "60", &T::transact_time, "87", &T::alloc_status, "88", &T::alloc_rej_code, "626", &T::alloc_type, "808", &T::alloc_intermed_req_type, "573", &T::match_status, "460", &T::product, "167", &T::security_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::DontKnowTrade>
{
   using T = glz::fix::fix44::DontKnowTrade;
   static constexpr std::string_view fix_msg_type = "Q";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "198", &T::secondary_order_id, "17", &T::exec_id, "127", &T::dk_reason, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "32", &T::last_qty, "31", &T::last_px, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::QuotReqLegsGrp>
{
   using T = glz::fix::fix44::QuotReqLegsGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "587", &T::leg_settl_type, "588", &T::leg_settl_date, "683", &T::no_leg_stipulations, "539", &T::no_nested_party_ids, "676", &T::leg_benchmark_curve_currency, "677", &T::leg_benchmark_curve_name, "678", &T::leg_benchmark_curve_point, "679", &T::leg_benchmark_price, "680", &T::leg_benchmark_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::QuotQualGrp>
{
   using T = glz::fix::fix44::QuotQualGrp;
   static constexpr auto value = glz::object("695", &T::quote_qualifier);
};
template <>
struct glz::meta<glz::fix::fix44::QuotReqGrp>
{
   using T = glz::fix::fix44::QuotReqGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "140", &T::prev_close_px, "303", &T::quote_request_type, "537", &T::quote_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "229", &T::trade_origination_date, "54", &T::side, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "63", &T::settl_type, "64", &T::settl_date, "193", &T::settl_date2, "192", &T::order_qty2, "15", &T::currency, "232", &T::no_stipulations, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "555", &T::no_legs, "735", &T::no_quote_qualifiers, "692", &T::quote_price_type, "40", &T::ord_type, "62", &T::valid_until_time, "126", &T::expire_time, "60", &T::transact_time, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "423", &T::price_type, "44", &T::price, "640", &T::price2, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "453", &T::no_party_ids);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRequest>
{
   using T = glz::fix::fix44::QuoteRequest;
   static constexpr std::string_view fix_msg_type = "R";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "644", &T::rfq_req_id, "11", &T::cl_ord_id, "528", &T::order_capacity, "146", &T::no_related_sym, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::LegQuotGrp>
{
   using T = glz::fix::fix44::LegQuotGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "587", &T::leg_settl_type, "588", &T::leg_settl_date, "683", &T::no_leg_stipulations, "539", &T::no_nested_party_ids, "686", &T::leg_price_type, "681", &T::leg_bid_px, "684", &T::leg_offer_px, "676", &T::leg_benchmark_curve_currency, "677", &T::leg_benchmark_curve_name, "678", &T::leg_benchmark_curve_point, "679", &T::leg_benchmark_price, "680", &T::leg_benchmark_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::Quote>
{
   using T = glz::fix::fix44::Quote;
   static constexpr std::string_view fix_msg_type = "S";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "693", &T::quote_resp_id, "537", &T::quote_type, "735", &T::no_quote_qualifiers, "301", &T::quote_response_level, "453", &T::no_party_ids, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "63", &T::settl_type, "64", &T::settl_date, "193", &T::settl_date2, "192", &T::order_qty2, "15", &T::currency, "232", &T::no_stipulations, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "555", &T::no_legs, "132", &T::bid_px, "133", &T::offer_px, "645", &T::mkt_bid_px, "646", &T::mkt_offer_px, "647", &T::min_bid_size, "134", &T::bid_size, "648", &T::min_offer_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "631", &T::mid_px, "632", &T::bid_yield, "633", &T::mid_yield, "634", &T::offer_yield, "60", &T::transact_time, "40", &T::ord_type, "642", &T::bid_forward_points2, "643", &T::offer_forward_points2, "656", &T::settl_curr_bid_fx_rate, "657", &T::settl_curr_offer_fx_rate, "156", &T::settl_curr_fx_rate_calc, "13", &T::comm_type, "12", &T::commission, "582", &T::cust_order_capacity, "100", &T::ex_destination, "528", &T::order_capacity, "423", &T::price_type, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::SettlInstGrp>
{
   using T = glz::fix::fix44::SettlInstGrp;
   static constexpr auto value = glz::object("162", &T::settl_inst_id, "163", &T::settl_inst_trans_type, "214", &T::settl_inst_ref_id, "453", &T::no_party_ids, "54", &T::side, "460", &T::product, "167", &T::security_type, "461", &T::cfi_code, "168", &T::effective_time, "126", &T::expire_time, "779", &T::last_update_time, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst, "492", &T::payment_method, "476", &T::payment_ref, "488", &T::card_holder_name, "489", &T::card_number, "503", &T::card_start_date, "490", &T::card_exp_date, "491", &T::card_iss_num, "504", &T::payment_date, "505", &T::payment_remitter_id);
};
template <>
struct glz::meta<glz::fix::fix44::SettlementInstructions>
{
   using T = glz::fix::fix44::SettlementInstructions;
   static constexpr std::string_view fix_msg_type = "T";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("777", &T::settl_inst_msg_id, "791", &T::settl_inst_req_id, "160", &T::settl_inst_mode, "792", &T::settl_inst_req_rej_code, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "11", &T::cl_ord_id, "60", &T::transact_time, "778", &T::no_settl_inst);
};
template <>
struct glz::meta<glz::fix::fix44::MDReqGrp>
{
   using T = glz::fix::fix44::MDReqGrp;
   static constexpr auto value = glz::object("269", &T::md_entry_type);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtMDReqGrp>
{
   using T = glz::fix::fix44::InstrmtMDReqGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs);
};
template <>
struct glz::meta<glz::fix::fix44::MarketDataRequest>
{
   using T = glz::fix::fix44::MarketDataRequest;
   static constexpr std::string_view fix_msg_type = "V";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("262", &T::md_req_id, "263", &T::subscription_request_type, "264", &T::market_depth, "265", &T::md_update_type, "266", &T::aggregated_book, "286", &T::open_close_settl_flag, "546", &T::scope, "547", &T::md_implicit_delete, "267", &T::no_md_entry_types, "146", &T::no_related_sym, "386", &T::no_trading_sessions, "815", &T::appl_queue_action, "812", &T::appl_queue_max);
};
template <>
struct glz::meta<glz::fix::fix44::MDFullGrp>
{
   using T = glz::fix::fix44::MDFullGrp;
   static constexpr auto value = glz::object("269", &T::md_entry_type, "270", &T::md_entry_px, "15", &T::currency, "271", &T::md_entry_size, "272", &T::md_entry_date, "273", &T::md_entry_time, "274", &T::tick_direction, "275", &T::md_mkt, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "276", &T::quote_condition, "277", &T::trade_condition, "282", &T::md_entry_originator, "283", &T::location_id, "284", &T::desk_id, "286", &T::open_close_settl_flag, "59", &T::time_in_force, "432", &T::expire_date, "126", &T::expire_time, "110", &T::min_qty, "18", &T::exec_inst, "287", &T::seller_days, "37", &T::order_id, "299", &T::quote_entry_id, "288", &T::md_entry_buyer, "289", &T::md_entry_seller, "346", &T::number_of_orders, "290", &T::md_entry_position_no, "546", &T::scope, "811", &T::price_delta, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::MarketDataSnapshotFullRefresh>
{
   using T = glz::fix::fix44::MarketDataSnapshotFullRefresh;
   static constexpr std::string_view fix_msg_type = "W";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("262", &T::md_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "291", &T::financial_status, "292", &T::corporate_action, "451", &T::net_chg_prev_day, "268", &T::no_md_entries, "813", &T::appl_queue_depth, "814", &T::appl_queue_resolution);
};
template <>
struct glz::meta<glz::fix::fix44::MDIncGrp>
{
   using T = glz::fix::fix44::MDIncGrp;
   static constexpr auto value = glz::object("279", &T::md_update_action, "285", &T::delete_reason, "269", &T::md_entry_type, "278", &T::md_entry_id, "280", &T::md_entry_ref_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "291", &T::financial_status, "292", &T::corporate_action, "270", &T::md_entry_px, "15", &T::currency, "271", &T::md_entry_size, "272", &T::md_entry_date, "273", &T::md_entry_time, "274", &T::tick_direction, "275", &T::md_mkt, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "276", &T::quote_condition, "277", &T::trade_condition, "282", &T::md_entry_originator, "283", &T::location_id, "284", &T::desk_id, "286", &T::open_close_settl_flag, "59", &T::time_in_force, "432", &T::expire_date, "126", &T::expire_time, "110", &T::min_qty, "18", &T::exec_inst, "287", &T::seller_days, "37", &T::order_id, "299", &T::quote_entry_id, "288", &T::md_entry_buyer, "289", &T::md_entry_seller, "346", &T::number_of_orders, "290", &T::md_entry_position_no, "546", &T::scope, "811", &T::price_delta, "451", &T::net_chg_prev_day, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::MarketDataIncrementalRefresh>
{
   using T = glz::fix::fix44::MarketDataIncrementalRefresh;
   static constexpr std::string_view fix_msg_type = "X";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("262", &T::md_req_id, "268", &T::no_md_entries, "813", &T::appl_queue_depth, "814", &T::appl_queue_resolution);
};
template <>
struct glz::meta<glz::fix::fix44::MDRjctGrp>
{
   using T = glz::fix::fix44::MDRjctGrp;
   static constexpr auto value = glz::object("817", &T::alt_md_source_id);
};
template <>
struct glz::meta<glz::fix::fix44::MarketDataRequestReject>
{
   using T = glz::fix::fix44::MarketDataRequestReject;
   static constexpr std::string_view fix_msg_type = "Y";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("262", &T::md_req_id, "281", &T::md_req_rej_reason, "816", &T::no_alt_md_source, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::QuotCxlEntriesGrp>
{
   using T = glz::fix::fix44::QuotCxlEntriesGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteCancel>
{
   using T = glz::fix::fix44::QuoteCancel;
   static constexpr std::string_view fix_msg_type = "Z";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "298", &T::quote_cancel_type, "301", &T::quote_response_level, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteStatusRequest>
{
   using T = glz::fix::fix44::QuoteStatusRequest;
   static constexpr std::string_view fix_msg_type = "a";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("649", &T::quote_status_req_id, "117", &T::quote_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::QuotEntryAckGrp>
{
   using T = glz::fix::fix44::QuotEntryAckGrp;
   static constexpr auto value = glz::object("299", &T::quote_entry_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "555", &T::no_legs, "132", &T::bid_px, "133", &T::offer_px, "134", &T::bid_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "631", &T::mid_px, "632", &T::bid_yield, "633", &T::mid_yield, "634", &T::offer_yield, "60", &T::transact_time, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "64", &T::settl_date, "40", &T::ord_type, "193", &T::settl_date2, "192", &T::order_qty2, "642", &T::bid_forward_points2, "643", &T::offer_forward_points2, "15", &T::currency, "368", &T::quote_entry_reject_reason);
};
template <>
struct glz::meta<glz::fix::fix44::QuotSetAckGrp>
{
   using T = glz::fix::fix44::QuotSetAckGrp;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "304", &T::tot_no_quote_entries, "893", &T::last_fragment, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix44::MassQuoteAcknowledgement>
{
   using T = glz::fix::fix44::MassQuoteAcknowledgement;
   static constexpr std::string_view fix_msg_type = "b";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "297", &T::quote_status, "300", &T::quote_reject_reason, "301", &T::quote_response_level, "537", &T::quote_type, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "296", &T::no_quote_sets);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityDefinitionRequest>
{
   using T = glz::fix::fix44::SecurityDefinitionRequest;
   static constexpr std::string_view fix_msg_type = "c";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "321", &T::security_request_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "711", &T::no_underlyings, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "555", &T::no_legs, "827", &T::expiration_cycle, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityDefinition>
{
   using T = glz::fix::fix44::SecurityDefinition;
   static constexpr std::string_view fix_msg_type = "d";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "322", &T::security_response_id, "323", &T::security_response_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "711", &T::no_underlyings, "15", &T::currency, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "555", &T::no_legs, "827", &T::expiration_cycle, "561", &T::round_lot, "562", &T::min_trade_vol);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityStatusRequest>
{
   using T = glz::fix::fix44::SecurityStatusRequest;
   static constexpr std::string_view fix_msg_type = "e";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("324", &T::security_status_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "711", &T::no_underlyings, "555", &T::no_legs, "15", &T::currency, "263", &T::subscription_request_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityStatus>
{
   using T = glz::fix::fix44::SecurityStatus;
   static constexpr std::string_view fix_msg_type = "f";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("324", &T::security_status_req_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "711", &T::no_underlyings, "555", &T::no_legs, "15", &T::currency, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "325", &T::unsolicited_indicator, "326", &T::security_trading_status, "291", &T::financial_status, "292", &T::corporate_action, "327", &T::halt_reason, "328", &T::in_view_of_common, "329", &T::due_to_related, "330", &T::buy_volume, "331", &T::sell_volume, "332", &T::high_px, "333", &T::low_px, "31", &T::last_px, "60", &T::transact_time, "334", &T::adjustment, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::TradingSessionStatusRequest>
{
   using T = glz::fix::fix44::TradingSessionStatusRequest;
   static constexpr std::string_view fix_msg_type = "g";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("335", &T::trad_ses_req_id, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "338", &T::trad_ses_method, "339", &T::trad_ses_mode, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::TradingSessionStatus>
{
   using T = glz::fix::fix44::TradingSessionStatus;
   static constexpr std::string_view fix_msg_type = "h";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("335", &T::trad_ses_req_id, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "338", &T::trad_ses_method, "339", &T::trad_ses_mode, "325", &T::unsolicited_indicator, "340", &T::trad_ses_status, "567", &T::trad_ses_status_rej_reason, "341", &T::trad_ses_start_time, "342", &T::trad_ses_open_time, "343", &T::trad_ses_pre_close_time, "344", &T::trad_ses_close_time, "345", &T::trad_ses_end_time, "387", &T::total_volume_traded, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::QuotEntryGrp>
{
   using T = glz::fix::fix44::QuotEntryGrp;
   static constexpr auto value = glz::object("299", &T::quote_entry_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "555", &T::no_legs, "132", &T::bid_px, "133", &T::offer_px, "134", &T::bid_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "631", &T::mid_px, "632", &T::bid_yield, "633", &T::mid_yield, "634", &T::offer_yield, "60", &T::transact_time, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "64", &T::settl_date, "40", &T::ord_type, "193", &T::settl_date2, "192", &T::order_qty2, "642", &T::bid_forward_points2, "643", &T::offer_forward_points2, "15", &T::currency);
};
template <>
struct glz::meta<glz::fix::fix44::QuotSetGrp>
{
   using T = glz::fix::fix44::QuotSetGrp;
   static constexpr auto value = glz::object("302", &T::quote_set_id, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "367", &T::quote_set_valid_until_time, "304", &T::tot_no_quote_entries, "893", &T::last_fragment, "295", &T::no_quote_entries);
};
template <>
struct glz::meta<glz::fix::fix44::MassQuote>
{
   using T = glz::fix::fix44::MassQuote;
   static constexpr std::string_view fix_msg_type = "i";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "117", &T::quote_id, "537", &T::quote_type, "301", &T::quote_response_level, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "293", &T::def_bid_size, "294", &T::def_offer_size, "296", &T::no_quote_sets);
};
template <>
struct glz::meta<glz::fix::fix44::BusinessMessageReject>
{
   using T = glz::fix::fix44::BusinessMessageReject;
   static constexpr std::string_view fix_msg_type = "j";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("45", &T::ref_seq_num, "372", &T::ref_msg_type, "379", &T::business_reject_ref_id, "380", &T::business_reject_reason, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::BidDescReqGrp>
{
   using T = glz::fix::fix44::BidDescReqGrp;
   static constexpr auto value = glz::object("399", &T::bid_descriptor_type, "400", &T::bid_descriptor, "401", &T::side_value_ind, "404", &T::liquidity_value, "441", &T::liquidity_num_securities, "402", &T::liquidity_pct_low, "403", &T::liquidity_pct_high, "405", &T::efp_tracking_error, "406", &T::fair_value, "407", &T::outside_index_pct, "408", &T::value_of_futures);
};
template <>
struct glz::meta<glz::fix::fix44::BidCompReqGrp>
{
   using T = glz::fix::fix44::BidCompReqGrp;
   static constexpr auto value = glz::object("66", &T::list_id, "54", &T::side, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "430", &T::net_gross_ind, "63", &T::settl_type, "64", &T::settl_date, "1", &T::account, "660", &T::acct_id_source);
};
template <>
struct glz::meta<glz::fix::fix44::BidRequest>
{
   using T = glz::fix::fix44::BidRequest;
   static constexpr std::string_view fix_msg_type = "k";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("390", &T::bid_id, "391", &T::client_bid_id, "374", &T::bid_request_trans_type, "392", &T::list_name, "393", &T::tot_no_related_sym, "394", &T::bid_type, "395", &T::num_tickets, "15", &T::currency, "396", &T::side_value1, "397", &T::side_value2, "398", &T::no_bid_descriptors, "420", &T::no_bid_components, "409", &T::liquidity_ind_type, "410", &T::wt_average_liquidity, "411", &T::exchange_for_physical, "412", &T::out_main_cntry_u_index, "413", &T::cross_percent, "414", &T::prog_rpt_reqs, "415", &T::prog_period_interval, "416", &T::inc_tax_ind, "121", &T::forex_req, "417", &T::num_bidders, "75", &T::trade_date, "418", &T::bid_trade_type, "419", &T::basis_px_type, "443", &T::strike_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::BidCompRspGrp>
{
   using T = glz::fix::fix44::BidCompRspGrp;
   static constexpr auto value = glz::object("12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "66", &T::list_id, "421", &T::country, "54", &T::side, "44", &T::price, "423", &T::price_type, "406", &T::fair_value, "430", &T::net_gross_ind, "63", &T::settl_type, "64", &T::settl_date, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::BidResponse>
{
   using T = glz::fix::fix44::BidResponse;
   static constexpr std::string_view fix_msg_type = "l";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("390", &T::bid_id, "391", &T::client_bid_id, "420", &T::no_bid_components);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtStrkPxGrp>
{
   using T = glz::fix::fix44::InstrmtStrkPxGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date);
};
template <>
struct glz::meta<glz::fix::fix44::UndInstrmtStrkPxGrp>
{
   using T = glz::fix::fix44::UndInstrmtStrkPxGrp;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "140", &T::prev_close_px, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "54", &T::side, "44", &T::price, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ListStrikePrice>
{
   using T = glz::fix::fix44::ListStrikePrice;
   static constexpr std::string_view fix_msg_type = "m";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("66", &T::list_id, "422", &T::tot_no_strikes, "893", &T::last_fragment, "428", &T::no_strikes, "711", &T::no_underlyings);
};
template <>
struct glz::meta<glz::fix::fix44::XMLnonFIX>
{
   using T = glz::fix::fix44::XMLnonFIX;
   static constexpr std::string_view fix_msg_type = "n";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object();
};
template <>
struct glz::meta<glz::fix::fix44::RgstDtlsGrp>
{
   using T = glz::fix::fix44::RgstDtlsGrp;
   static constexpr auto value = glz::object("509", &T::regist_dtls, "511", &T::regist_email, "474", &T::mailing_dtls, "482", &T::mailing_inst, "539", &T::no_nested_party_ids, "522", &T::owner_type, "486", &T::date_of_birth, "475", &T::investor_country_of_residence);
};
template <>
struct glz::meta<glz::fix::fix44::RgstDistInstGrp>
{
   using T = glz::fix::fix44::RgstDistInstGrp;
   static constexpr auto value = glz::object("477", &T::distrib_payment_method, "512", &T::distrib_percentage, "478", &T::cash_distrib_curr, "498", &T::cash_distrib_agent_name, "499", &T::cash_distrib_agent_code, "500", &T::cash_distrib_agent_acct_number, "501", &T::cash_distrib_pay_ref, "502", &T::cash_distrib_agent_acct_name);
};
template <>
struct glz::meta<glz::fix::fix44::RegistrationInstructions>
{
   using T = glz::fix::fix44::RegistrationInstructions;
   static constexpr std::string_view fix_msg_type = "o";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("513", &T::regist_id, "514", &T::regist_trans_type, "508", &T::regist_ref_id, "11", &T::cl_ord_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "493", &T::regist_acct_type, "495", &T::tax_advantage_type, "517", &T::ownership_type, "473", &T::no_regist_dtls, "510", &T::no_distrib_insts);
};
template <>
struct glz::meta<glz::fix::fix44::RegistrationInstructionsResponse>
{
   using T = glz::fix::fix44::RegistrationInstructionsResponse;
   static constexpr std::string_view fix_msg_type = "p";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("513", &T::regist_id, "514", &T::regist_trans_type, "508", &T::regist_ref_id, "11", &T::cl_ord_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "506", &T::regist_status, "507", &T::regist_rej_reason_code, "496", &T::regist_rej_reason_text);
};
template <>
struct glz::meta<glz::fix::fix44::OrderMassCancelRequest>
{
   using T = glz::fix::fix44::OrderMassCancelRequest;
   static constexpr std::string_view fix_msg_type = "q";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "530", &T::mass_cancel_request_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "54", &T::side, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::AffectedOrdGrp>
{
   using T = glz::fix::fix44::AffectedOrdGrp;
   static constexpr auto value = glz::object("41", &T::orig_cl_ord_id, "535", &T::affected_order_id, "536", &T::affected_secondary_order_id);
};
template <>
struct glz::meta<glz::fix::fix44::OrderMassCancelReport>
{
   using T = glz::fix::fix44::OrderMassCancelReport;
   static constexpr std::string_view fix_msg_type = "r";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "530", &T::mass_cancel_request_type, "531", &T::mass_cancel_response, "532", &T::mass_cancel_reject_reason, "533", &T::total_affected_orders, "534", &T::no_affected_orders, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "54", &T::side, "60", &T::transact_time, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::SideCrossOrdModGrp>
{
   using T = glz::fix::fix44::SideCrossOrdModGrp;
   static constexpr auto value = glz::object("54", &T::side, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "586", &T::orig_ord_mod_time, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "77", &T::position_effect, "203", &T::covered_or_uncovered, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "377", &T::solicited_flag, "659", &T::side_compliance_id);
};
template <>
struct glz::meta<glz::fix::fix44::NewOrderCross>
{
   using T = glz::fix::fix44::NewOrderCross;
   static constexpr std::string_view fix_msg_type = "s";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("548", &T::cross_id, "549", &T::cross_type, "550", &T::cross_prioritization, "552", &T::no_sides, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "63", &T::settl_type, "64", &T::settl_date, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "140", &T::prev_close_px, "114", &T::locate_reqd, "60", &T::transact_time, "232", &T::no_stipulations, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "15", &T::currency, "376", &T::compliance_id, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation);
};
template <>
struct glz::meta<glz::fix::fix44::CrossOrderCancelReplaceRequest>
{
   using T = glz::fix::fix44::CrossOrderCancelReplaceRequest;
   static constexpr std::string_view fix_msg_type = "t";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "548", &T::cross_id, "551", &T::orig_cross_id, "549", &T::cross_type, "550", &T::cross_prioritization, "552", &T::no_sides, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "63", &T::settl_type, "64", &T::settl_date, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "140", &T::prev_close_px, "114", &T::locate_reqd, "60", &T::transact_time, "232", &T::no_stipulations, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "15", &T::currency, "376", &T::compliance_id, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation);
};
template <>
struct glz::meta<glz::fix::fix44::SideCrossOrdCxlGrp>
{
   using T = glz::fix::fix44::SideCrossOrdCxlGrp;
   static constexpr auto value = glz::object("54", &T::side, "41", &T::orig_cl_ord_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "586", &T::orig_ord_mod_time, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "376", &T::compliance_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CrossOrderCancelRequest>
{
   using T = glz::fix::fix44::CrossOrderCancelRequest;
   static constexpr std::string_view fix_msg_type = "u";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "548", &T::cross_id, "551", &T::orig_cross_id, "549", &T::cross_type, "550", &T::cross_prioritization, "552", &T::no_sides, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "60", &T::transact_time);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityTypeRequest>
{
   using T = glz::fix::fix44::SecurityTypeRequest;
   static constexpr std::string_view fix_msg_type = "v";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "460", &T::product, "167", &T::security_type, "762", &T::security_sub_type);
};
template <>
struct glz::meta<glz::fix::fix44::SecTypesGrp>
{
   using T = glz::fix::fix44::SecTypesGrp;
   static constexpr auto value = glz::object("167", &T::security_type, "762", &T::security_sub_type, "460", &T::product, "461", &T::cfi_code);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityTypes>
{
   using T = glz::fix::fix44::SecurityTypes;
   static constexpr std::string_view fix_msg_type = "w";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "322", &T::security_response_id, "323", &T::security_response_type, "557", &T::tot_no_security_types, "893", &T::last_fragment, "558", &T::no_security_types, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityListRequest>
{
   using T = glz::fix::fix44::SecurityListRequest;
   static constexpr std::string_view fix_msg_type = "x";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "559", &T::security_list_request_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::InstrmtLegSecListGrp>
{
   using T = glz::fix::fix44::InstrmtLegSecListGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "690", &T::leg_swap_type, "587", &T::leg_settl_type, "683", &T::no_leg_stipulations, "676", &T::leg_benchmark_curve_currency, "677", &T::leg_benchmark_curve_name, "678", &T::leg_benchmark_curve_point, "679", &T::leg_benchmark_price, "680", &T::leg_benchmark_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::SecListGrp>
{
   using T = glz::fix::fix44::SecListGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "15", &T::currency, "232", &T::no_stipulations, "555", &T::no_legs, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "561", &T::round_lot, "562", &T::min_trade_vol, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "827", &T::expiration_cycle, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::SecurityList>
{
   using T = glz::fix::fix44::SecurityList;
   static constexpr std::string_view fix_msg_type = "y";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "322", &T::security_response_id, "560", &T::security_request_result, "393", &T::tot_no_related_sym, "893", &T::last_fragment, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix44::DerivativeSecurityListRequest>
{
   using T = glz::fix::fix44::DerivativeSecurityListRequest;
   static constexpr std::string_view fix_msg_type = "z";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "559", &T::security_list_request_type, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "762", &T::security_sub_type, "15", &T::currency, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::RelSymDerivSecGrp>
{
   using T = glz::fix::fix44::RelSymDerivSecGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "827", &T::expiration_cycle, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "555", &T::no_legs, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::DerivativeSecurityList>
{
   using T = glz::fix::fix44::DerivativeSecurityList;
   static constexpr std::string_view fix_msg_type = "AA";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("320", &T::security_req_id, "322", &T::security_response_id, "560", &T::security_request_result, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "393", &T::tot_no_related_sym, "893", &T::last_fragment, "146", &T::no_related_sym);
};
template <>
struct glz::meta<glz::fix::fix44::NstdPtys3SubGrp>
{
   using T = glz::fix::fix44::NstdPtys3SubGrp;
   static constexpr auto value = glz::object("953", &T::nested3_party_sub_id, "954", &T::nested3_party_sub_id_type);
};
template <>
struct glz::meta<glz::fix::fix44::NestedParties3Grp>
{
   using T = glz::fix::fix44::NestedParties3Grp;
   static constexpr auto value = glz::object("949", &T::nested3_party_id, "950", &T::nested3_party_id_source, "951", &T::nested3_party_role, "952", &T::no_nested3_party_sub_ids);
};
template <>
struct glz::meta<glz::fix::fix44::PreAllocMlegGrp>
{
   using T = glz::fix::fix44::PreAllocMlegGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "661", &T::alloc_acct_id_source, "736", &T::alloc_settl_currency, "467", &T::individual_alloc_id, "948", &T::no_nested3_party_ids, "80", &T::alloc_qty);
};
template <>
struct glz::meta<glz::fix::fix44::LegPreAllocGrp>
{
   using T = glz::fix::fix44::LegPreAllocGrp;
   static constexpr auto value = glz::object("671", &T::leg_alloc_account, "672", &T::leg_individual_alloc_id, "756", &T::no_nested2_party_ids, "673", &T::leg_alloc_qty, "674", &T::leg_alloc_acct_id_source, "675", &T::leg_settl_currency);
};
template <>
struct glz::meta<glz::fix::fix44::LegOrdGrp>
{
   using T = glz::fix::fix44::LegOrdGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "683", &T::no_leg_stipulations, "670", &T::no_leg_allocs, "564", &T::leg_position_effect, "565", &T::leg_covered_or_uncovered, "539", &T::no_nested_party_ids, "654", &T::leg_ref_id, "566", &T::leg_price, "587", &T::leg_settl_type, "588", &T::leg_settl_date);
};
template <>
struct glz::meta<glz::fix::fix44::NewOrderMultileg>
{
   using T = glz::fix::fix44::NewOrderMultileg;
   static constexpr std::string_view fix_msg_type = "AB";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "54", &T::side, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "140", &T::prev_close_px, "555", &T::no_legs, "114", &T::locate_reqd, "60", &T::transact_time, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "77", &T::position_effect, "203", &T::covered_or_uncovered, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation, "563", &T::multi_leg_rpt_type_req);
};
template <>
struct glz::meta<glz::fix::fix44::MultilegOrderCancelReplace>
{
   using T = glz::fix::fix44::MultilegOrderCancelReplace;
   static constexpr std::string_view fix_msg_type = "AC";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("37", &T::order_id, "41", &T::orig_cl_ord_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "583", &T::cl_ord_link_id, "586", &T::orig_ord_mod_time, "453", &T::no_party_ids, "229", &T::trade_origination_date, "75", &T::trade_date, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "589", &T::day_booking_inst, "590", &T::booking_unit, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs, "63", &T::settl_type, "64", &T::settl_date, "544", &T::cash_margin, "635", &T::clearing_fee_indicator, "21", &T::handl_inst, "18", &T::exec_inst, "110", &T::min_qty, "111", &T::max_floor, "100", &T::ex_destination, "386", &T::no_trading_sessions, "81", &T::process_code, "54", &T::side, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "140", &T::prev_close_px, "555", &T::no_legs, "114", &T::locate_reqd, "60", &T::transact_time, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "40", &T::ord_type, "423", &T::price_type, "44", &T::price, "99", &T::stop_px, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "23", &T::ioiid, "117", &T::quote_id, "59", &T::time_in_force, "168", &T::effective_time, "432", &T::expire_date, "126", &T::expire_time, "427", &T::gt_booking_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "121", &T::forex_req, "120", &T::settl_currency, "775", &T::booking_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "77", &T::position_effect, "203", &T::covered_or_uncovered, "210", &T::max_show, "211", &T::peg_offset_value, "835", &T::peg_move_type, "836", &T::peg_offset_type, "837", &T::peg_limit_type, "838", &T::peg_round_direction, "840", &T::peg_scope, "388", &T::discretion_inst, "389", &T::discretion_offset_value, "841", &T::discretion_move_type, "842", &T::discretion_offset_type, "843", &T::discretion_limit_type, "844", &T::discretion_round_direction, "846", &T::discretion_scope, "847", &T::target_strategy, "848", &T::target_strategy_parameters, "849", &T::participation_rate, "480", &T::cancellation_rights, "481", &T::money_laundering_status, "513", &T::regist_id, "494", &T::designation, "563", &T::multi_leg_rpt_type_req);
};
template <>
struct glz::meta<glz::fix::fix44::TrdCapDtGrp>
{
   using T = glz::fix::fix44::TrdCapDtGrp;
   static constexpr auto value = glz::object("75", &T::trade_date, "60", &T::transact_time);
};
template <>
struct glz::meta<glz::fix::fix44::TradeCaptureReportRequest>
{
   using T = glz::fix::fix44::TradeCaptureReportRequest;
   static constexpr std::string_view fix_msg_type = "AD";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("568", &T::trade_request_id, "569", &T::trade_request_type, "263", &T::subscription_request_type, "571", &T::trade_report_id, "818", &T::secondary_trade_report_id, "17", &T::exec_id, "150", &T::exec_type, "37", &T::order_id, "11", &T::cl_ord_id, "573", &T::match_status, "828", &T::trd_type, "829", &T::trd_sub_type, "830", &T::transfer_reason, "855", &T::secondary_trd_type, "820", &T::trade_link_id, "880", &T::trd_match_id, "453", &T::no_party_ids, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "580", &T::no_dates, "715", &T::clearing_business_date, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "943", &T::time_bracket, "54", &T::side, "442", &T::multi_leg_reporting_type, "578", &T::trade_input_source, "579", &T::trade_input_device, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::PositionAmountDataGrp>
{
   using T = glz::fix::fix44::PositionAmountDataGrp;
   static constexpr auto value = glz::object("707", &T::pos_amt_type, "708", &T::pos_amt);
};
template <>
struct glz::meta<glz::fix::fix44::TrdInstrmtLegGrp>
{
   using T = glz::fix::fix44::TrdInstrmtLegGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "683", &T::no_leg_stipulations, "564", &T::leg_position_effect, "565", &T::leg_covered_or_uncovered, "539", &T::no_nested_party_ids, "654", &T::leg_ref_id, "566", &T::leg_price, "587", &T::leg_settl_type, "588", &T::leg_settl_date, "637", &T::leg_last_px);
};
template <>
struct glz::meta<glz::fix::fix44::TrdRegTimestampsGrp>
{
   using T = glz::fix::fix44::TrdRegTimestampsGrp;
   static constexpr auto value = glz::object("769", &T::trd_reg_timestamp, "770", &T::trd_reg_timestamp_type, "771", &T::trd_reg_timestamp_origin);
};
template <>
struct glz::meta<glz::fix::fix44::TrdAllocGrp>
{
   using T = glz::fix::fix44::TrdAllocGrp;
   static constexpr auto value = glz::object("79", &T::alloc_account, "661", &T::alloc_acct_id_source, "736", &T::alloc_settl_currency, "467", &T::individual_alloc_id, "756", &T::no_nested2_party_ids, "80", &T::alloc_qty);
};
template <>
struct glz::meta<glz::fix::fix44::TrdCapRptSideGrp>
{
   using T = glz::fix::fix44::TrdCapRptSideGrp;
   static constexpr auto value = glz::object("54", &T::side, "37", &T::order_id, "198", &T::secondary_order_id, "11", &T::cl_ord_id, "526", &T::secondary_cl_ord_id, "66", &T::list_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "81", &T::process_code, "575", &T::odd_lot, "576", &T::no_clearing_instructions, "635", &T::clearing_fee_indicator, "578", &T::trade_input_source, "579", &T::trade_input_device, "821", &T::order_input_device, "15", &T::currency, "376", &T::compliance_id, "377", &T::solicited_flag, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "40", &T::ord_type, "18", &T::exec_inst, "483", &T::trans_bkd_time, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "943", &T::time_bracket, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "381", &T::gross_trade_amt, "157", &T::num_days_interest, "230", &T::ex_date, "158", &T::accrued_interest_rate, "159", &T::accrued_interest_amt, "738", &T::interest_at_maturity, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "238", &T::concession, "237", &T::total_takedown, "118", &T::net_money, "119", &T::settl_curr_amt, "120", &T::settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "77", &T::position_effect, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "752", &T::side_multi_leg_reporting_type, "518", &T::no_cont_amts, "232", &T::no_stipulations, "136", &T::no_misc_fees, "825", &T::exchange_rule, "826", &T::trade_alloc_indicator, "591", &T::prealloc_method, "70", &T::alloc_id, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::TradeCaptureReport>
{
   using T = glz::fix::fix44::TradeCaptureReport;
   static constexpr std::string_view fix_msg_type = "AE";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("571", &T::trade_report_id, "487", &T::trade_report_trans_type, "856", &T::trade_report_type, "568", &T::trade_request_id, "828", &T::trd_type, "829", &T::trd_sub_type, "855", &T::secondary_trd_type, "830", &T::transfer_reason, "150", &T::exec_type, "748", &T::tot_num_trade_reports, "912", &T::last_rpt_requested, "325", &T::unsolicited_indicator, "263", &T::subscription_request_type, "572", &T::trade_report_ref_id, "881", &T::secondary_trade_report_ref_id, "818", &T::secondary_trade_report_id, "820", &T::trade_link_id, "880", &T::trd_match_id, "17", &T::exec_id, "39", &T::ord_status, "527", &T::secondary_exec_id, "378", &T::exec_restatement_reason, "570", &T::previously_reported, "423", &T::price_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "854", &T::qty_type, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "711", &T::no_underlyings, "822", &T::underlying_trading_session_id, "823", &T::underlying_trading_session_sub_id, "32", &T::last_qty, "31", &T::last_px, "669", &T::last_par_px, "194", &T::last_spot_rate, "195", &T::last_forward_points, "30", &T::last_mkt, "75", &T::trade_date, "715", &T::clearing_business_date, "6", &T::avg_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "819", &T::avg_px_indicator, "753", &T::no_pos_amt, "442", &T::multi_leg_reporting_type, "824", &T::trade_leg_ref_id, "555", &T::no_legs, "60", &T::transact_time, "768", &T::no_trd_reg_timestamps, "63", &T::settl_type, "64", &T::settl_date, "573", &T::match_status, "574", &T::match_type, "552", &T::no_sides, "797", &T::copy_msg_indicator, "852", &T::publish_trd_indicator, "853", &T::short_sale_reason);
};
template <>
struct glz::meta<glz::fix::fix44::OrderMassStatusRequest>
{
   using T = glz::fix::fix44::OrderMassStatusRequest;
   static constexpr std::string_view fix_msg_type = "AF";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("584", &T::mass_status_req_id, "585", &T::mass_status_req_type, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "54", &T::side);
};
template <>
struct glz::meta<glz::fix::fix44::QuotReqRjctGrp>
{
   using T = glz::fix::fix44::QuotReqRjctGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "140", &T::prev_close_px, "303", &T::quote_request_type, "537", &T::quote_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "229", &T::trade_origination_date, "54", &T::side, "854", &T::qty_type, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "63", &T::settl_type, "64", &T::settl_date, "193", &T::settl_date2, "192", &T::order_qty2, "15", &T::currency, "232", &T::no_stipulations, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "555", &T::no_legs, "735", &T::no_quote_qualifiers, "692", &T::quote_price_type, "40", &T::ord_type, "126", &T::expire_time, "60", &T::transact_time, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "423", &T::price_type, "44", &T::price, "640", &T::price2, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "453", &T::no_party_ids);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteRequestReject>
{
   using T = glz::fix::fix44::QuoteRequestReject;
   static constexpr std::string_view fix_msg_type = "AG";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("131", &T::quote_req_id, "644", &T::rfq_req_id, "658", &T::quote_request_reject_reason, "146", &T::no_related_sym, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::RFQReqGrp>
{
   using T = glz::fix::fix44::RFQReqGrp;
   static constexpr auto value = glz::object("55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "140", &T::prev_close_px, "303", &T::quote_request_type, "537", &T::quote_type, "336", &T::trading_session_id, "625", &T::trading_session_sub_id);
};
template <>
struct glz::meta<glz::fix::fix44::RFQRequest>
{
   using T = glz::fix::fix44::RFQRequest;
   static constexpr std::string_view fix_msg_type = "AH";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("644", &T::rfq_req_id, "146", &T::no_related_sym, "263", &T::subscription_request_type);
};
template <>
struct glz::meta<glz::fix::fix44::LegQuotStatGrp>
{
   using T = glz::fix::fix44::LegQuotStatGrp;
   static constexpr auto value = glz::object("600", &T::leg_symbol, "601", &T::leg_symbol_sfx, "602", &T::leg_security_id, "603", &T::leg_security_id_source, "604", &T::no_leg_security_alt_id, "607", &T::leg_product, "608", &T::leg_cfi_code, "609", &T::leg_security_type, "764", &T::leg_security_sub_type, "610", &T::leg_maturity_month_year, "611", &T::leg_maturity_date, "248", &T::leg_coupon_payment_date, "249", &T::leg_issue_date, "250", &T::leg_repo_collateral_security_type, "251", &T::leg_repurchase_term, "252", &T::leg_repurchase_rate, "253", &T::leg_factor, "257", &T::leg_credit_rating, "599", &T::leg_instr_registry, "596", &T::leg_country_of_issue, "597", &T::leg_state_or_province_of_issue, "598", &T::leg_locale_of_issue, "254", &T::leg_redemption_date, "612", &T::leg_strike_price, "942", &T::leg_strike_currency, "613", &T::leg_opt_attribute, "614", &T::leg_contract_multiplier, "615", &T::leg_coupon_rate, "616", &T::leg_security_exchange, "617", &T::leg_issuer, "618", &T::encoded_leg_issuer_len, "619", &T::encoded_leg_issuer, "620", &T::leg_security_desc, "621", &T::encoded_leg_security_desc_len, "622", &T::encoded_leg_security_desc, "623", &T::leg_ratio_qty, "624", &T::leg_side, "556", &T::leg_currency, "740", &T::leg_pool, "739", &T::leg_dated_date, "955", &T::leg_contract_settl_month, "956", &T::leg_interest_accrual_date, "687", &T::leg_qty, "690", &T::leg_swap_type, "587", &T::leg_settl_type, "588", &T::leg_settl_date, "683", &T::no_leg_stipulations, "539", &T::no_nested_party_ids);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteStatusReport>
{
   using T = glz::fix::fix44::QuoteStatusReport;
   static constexpr std::string_view fix_msg_type = "AI";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("649", &T::quote_status_req_id, "131", &T::quote_req_id, "117", &T::quote_id, "693", &T::quote_resp_id, "537", &T::quote_type, "453", &T::no_party_ids, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "63", &T::settl_type, "64", &T::settl_date, "193", &T::settl_date2, "192", &T::order_qty2, "15", &T::currency, "232", &T::no_stipulations, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "555", &T::no_legs, "735", &T::no_quote_qualifiers, "126", &T::expire_time, "44", &T::price, "423", &T::price_type, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "132", &T::bid_px, "133", &T::offer_px, "645", &T::mkt_bid_px, "646", &T::mkt_offer_px, "647", &T::min_bid_size, "134", &T::bid_size, "648", &T::min_offer_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "631", &T::mid_px, "632", &T::bid_yield, "633", &T::mid_yield, "634", &T::offer_yield, "60", &T::transact_time, "40", &T::ord_type, "642", &T::bid_forward_points2, "643", &T::offer_forward_points2, "656", &T::settl_curr_bid_fx_rate, "657", &T::settl_curr_offer_fx_rate, "156", &T::settl_curr_fx_rate_calc, "13", &T::comm_type, "12", &T::commission, "582", &T::cust_order_capacity, "100", &T::ex_destination, "297", &T::quote_status, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::QuoteResponse>
{
   using T = glz::fix::fix44::QuoteResponse;
   static constexpr std::string_view fix_msg_type = "AJ";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("693", &T::quote_resp_id, "117", &T::quote_id, "694", &T::quote_resp_type, "11", &T::cl_ord_id, "528", &T::order_capacity, "23", &T::ioiid, "537", &T::quote_type, "735", &T::no_quote_qualifiers, "453", &T::no_party_ids, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "54", &T::side, "38", &T::order_qty, "152", &T::cash_order_qty, "516", &T::order_percent, "468", &T::rounding_direction, "469", &T::rounding_modulus, "63", &T::settl_type, "64", &T::settl_date, "193", &T::settl_date2, "192", &T::order_qty2, "15", &T::currency, "232", &T::no_stipulations, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "555", &T::no_legs, "132", &T::bid_px, "133", &T::offer_px, "645", &T::mkt_bid_px, "646", &T::mkt_offer_px, "647", &T::min_bid_size, "134", &T::bid_size, "648", &T::min_offer_size, "135", &T::offer_size, "62", &T::valid_until_time, "188", &T::bid_spot_rate, "190", &T::offer_spot_rate, "189", &T::bid_forward_points, "191", &T::offer_forward_points, "631", &T::mid_px, "632", &T::bid_yield, "633", &T::mid_yield, "634", &T::offer_yield, "60", &T::transact_time, "40", &T::ord_type, "642", &T::bid_forward_points2, "643", &T::offer_forward_points2, "656", &T::settl_curr_bid_fx_rate, "657", &T::settl_curr_offer_fx_rate, "156", &T::settl_curr_fx_rate_calc, "12", &T::commission, "13", &T::comm_type, "582", &T::cust_order_capacity, "100", &T::ex_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "44", &T::price, "423", &T::price_type, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::CpctyConfGrp>
{
   using T = glz::fix::fix44::CpctyConfGrp;
   static constexpr auto value = glz::object("528", &T::order_capacity, "529", &T::order_restrictions, "863", &T::order_capacity_qty);
};
template <>
struct glz::meta<glz::fix::fix44::Confirmation>
{
   using T = glz::fix::fix44::Confirmation;
   static constexpr std::string_view fix_msg_type = "AK";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("664", &T::confirm_id, "772", &T::confirm_ref_id, "859", &T::confirm_req_id, "666", &T::confirm_trans_type, "773", &T::confirm_type, "797", &T::copy_msg_indicator, "650", &T::legal_confirm, "665", &T::confirm_status, "453", &T::no_party_ids, "73", &T::no_orders, "70", &T::alloc_id, "793", &T::secondary_alloc_id, "467", &T::individual_alloc_id, "60", &T::transact_time, "75", &T::trade_date, "768", &T::no_trd_reg_timestamps, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "80", &T::alloc_qty, "854", &T::qty_type, "54", &T::side, "15", &T::currency, "30", &T::last_mkt, "862", &T::no_capacities, "79", &T::alloc_account, "661", &T::alloc_acct_id_source, "798", &T::alloc_account_type, "6", &T::avg_px, "74", &T::avg_px_precision, "423", &T::price_type, "860", &T::avg_par_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "861", &T::reported_px, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "81", &T::process_code, "381", &T::gross_trade_amt, "157", &T::num_days_interest, "230", &T::ex_date, "158", &T::accrued_interest_rate, "159", &T::accrued_interest_amt, "738", &T::interest_at_maturity, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "238", &T::concession, "237", &T::total_takedown, "118", &T::net_money, "890", &T::maturity_net_money, "119", &T::settl_curr_amt, "120", &T::settl_currency, "155", &T::settl_curr_fx_rate, "156", &T::settl_curr_fx_rate_calc, "63", &T::settl_type, "64", &T::settl_date, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst, "12", &T::commission, "13", &T::comm_type, "479", &T::comm_currency, "497", &T::fund_renew_waiv, "858", &T::shared_commission, "232", &T::no_stipulations, "136", &T::no_misc_fees);
};
template <>
struct glz::meta<glz::fix::fix44::PositionQtyGrp>
{
   using T = glz::fix::fix44::PositionQtyGrp;
   static constexpr auto value = glz::object("703", &T::pos_type, "704", &T::long_qty, "705", &T::short_qty, "706", &T::pos_qty_status, "539", &T::no_nested_party_ids);
};
template <>
struct glz::meta<glz::fix::fix44::PositionMaintenanceRequest>
{
   using T = glz::fix::fix44::PositionMaintenanceRequest;
   static constexpr std::string_view fix_msg_type = "AL";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("710", &T::pos_req_id, "709", &T::pos_trans_type, "712", &T::pos_maint_action, "713", &T::orig_pos_req_ref_id, "714", &T::pos_maint_rpt_ref_id, "715", &T::clearing_business_date, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "386", &T::no_trading_sessions, "60", &T::transact_time, "702", &T::no_positions, "718", &T::adjustment_type, "719", &T::contrary_instruction_indicator, "720", &T::prior_spread_indicator, "834", &T::threshold_amount, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::PositionMaintenanceReport>
{
   using T = glz::fix::fix44::PositionMaintenanceReport;
   static constexpr std::string_view fix_msg_type = "AM";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("721", &T::pos_maint_rpt_id, "709", &T::pos_trans_type, "710", &T::pos_req_id, "712", &T::pos_maint_action, "713", &T::orig_pos_req_ref_id, "722", &T::pos_maint_status, "723", &T::pos_maint_result, "715", &T::clearing_business_date, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "386", &T::no_trading_sessions, "60", &T::transact_time, "702", &T::no_positions, "753", &T::no_pos_amt, "718", &T::adjustment_type, "834", &T::threshold_amount, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::RequestForPositions>
{
   using T = glz::fix::fix44::RequestForPositions;
   static constexpr std::string_view fix_msg_type = "AN";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("710", &T::pos_req_id, "724", &T::pos_req_type, "573", &T::match_status, "263", &T::subscription_request_type, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "715", &T::clearing_business_date, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "386", &T::no_trading_sessions, "60", &T::transact_time, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::RequestForPositionsAck>
{
   using T = glz::fix::fix44::RequestForPositionsAck;
   static constexpr std::string_view fix_msg_type = "AO";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("721", &T::pos_maint_rpt_id, "710", &T::pos_req_id, "727", &T::total_num_pos_reports, "325", &T::unsolicited_indicator, "728", &T::pos_req_result, "729", &T::pos_req_status, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::PosUndInstrmtGrp>
{
   using T = glz::fix::fix44::PosUndInstrmtGrp;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "732", &T::underlying_settl_price, "733", &T::underlying_settl_price_type);
};
template <>
struct glz::meta<glz::fix::fix44::PositionReport>
{
   using T = glz::fix::fix44::PositionReport;
   static constexpr std::string_view fix_msg_type = "AP";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("721", &T::pos_maint_rpt_id, "710", &T::pos_req_id, "724", &T::pos_req_type, "263", &T::subscription_request_type, "727", &T::total_num_pos_reports, "325", &T::unsolicited_indicator, "728", &T::pos_req_result, "715", &T::clearing_business_date, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "453", &T::no_party_ids, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "730", &T::settl_price, "731", &T::settl_price_type, "734", &T::prior_settl_price, "555", &T::no_legs, "711", &T::no_underlyings, "702", &T::no_positions, "753", &T::no_pos_amt, "506", &T::regist_status, "743", &T::delivery_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::TradeCaptureReportRequestAck>
{
   using T = glz::fix::fix44::TradeCaptureReportRequestAck;
   static constexpr std::string_view fix_msg_type = "AQ";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("568", &T::trade_request_id, "569", &T::trade_request_type, "263", &T::subscription_request_type, "748", &T::tot_num_trade_reports, "749", &T::trade_request_result, "750", &T::trade_request_status, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "711", &T::no_underlyings, "555", &T::no_legs, "442", &T::multi_leg_reporting_type, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::TradeCaptureReportAck>
{
   using T = glz::fix::fix44::TradeCaptureReportAck;
   static constexpr std::string_view fix_msg_type = "AR";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("571", &T::trade_report_id, "487", &T::trade_report_trans_type, "856", &T::trade_report_type, "828", &T::trd_type, "829", &T::trd_sub_type, "855", &T::secondary_trd_type, "830", &T::transfer_reason, "150", &T::exec_type, "572", &T::trade_report_ref_id, "881", &T::secondary_trade_report_ref_id, "939", &T::trd_rpt_status, "751", &T::trade_report_reject_reason, "818", &T::secondary_trade_report_id, "263", &T::subscription_request_type, "820", &T::trade_link_id, "880", &T::trd_match_id, "17", &T::exec_id, "527", &T::secondary_exec_id, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "60", &T::transact_time, "768", &T::no_trd_reg_timestamps, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "555", &T::no_legs, "635", &T::clearing_fee_indicator, "528", &T::order_capacity, "529", &T::order_restrictions, "582", &T::cust_order_capacity, "1", &T::account, "660", &T::acct_id_source, "581", &T::account_type, "77", &T::position_effect, "591", &T::prealloc_method, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::AllocationReport>
{
   using T = glz::fix::fix44::AllocationReport;
   static constexpr std::string_view fix_msg_type = "AS";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("755", &T::alloc_report_id, "70", &T::alloc_id, "71", &T::alloc_trans_type, "795", &T::alloc_report_ref_id, "796", &T::alloc_canc_replace_reason, "793", &T::secondary_alloc_id, "794", &T::alloc_report_type, "87", &T::alloc_status, "88", &T::alloc_rej_code, "72", &T::ref_alloc_id, "808", &T::alloc_intermed_req_type, "196", &T::alloc_link_id, "197", &T::alloc_link_type, "466", &T::booking_ref_id, "857", &T::alloc_no_orders_type, "73", &T::no_orders, "124", &T::no_execs, "570", &T::previously_reported, "700", &T::reversal_indicator, "574", &T::match_type, "54", &T::side, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "668", &T::delivery_form, "869", &T::pct_at_risk, "870", &T::no_instr_attrib, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "711", &T::no_underlyings, "555", &T::no_legs, "53", &T::quantity, "854", &T::qty_type, "30", &T::last_mkt, "229", &T::trade_origination_date, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "423", &T::price_type, "6", &T::avg_px, "860", &T::avg_par_px, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "15", &T::currency, "74", &T::avg_px_precision, "453", &T::no_party_ids, "75", &T::trade_date, "60", &T::transact_time, "63", &T::settl_type, "64", &T::settl_date, "775", &T::booking_type, "381", &T::gross_trade_amt, "238", &T::concession, "237", &T::total_takedown, "118", &T::net_money, "77", &T::position_effect, "754", &T::auto_accept_indicator, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "157", &T::num_days_interest, "158", &T::accrued_interest_rate, "159", &T::accrued_interest_amt, "540", &T::total_accrued_interest_amt, "738", &T::interest_at_maturity, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "650", &T::legal_confirm, "232", &T::no_stipulations, "235", &T::yield_type, "236", &T::yield, "701", &T::yield_calc_date, "696", &T::yield_redemption_date, "697", &T::yield_redemption_price, "698", &T::yield_redemption_price_type, "892", &T::tot_no_allocs, "893", &T::last_fragment, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::AllocationReportAck>
{
   using T = glz::fix::fix44::AllocationReportAck;
   static constexpr std::string_view fix_msg_type = "AT";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("755", &T::alloc_report_id, "70", &T::alloc_id, "453", &T::no_party_ids, "793", &T::secondary_alloc_id, "75", &T::trade_date, "60", &T::transact_time, "87", &T::alloc_status, "88", &T::alloc_rej_code, "794", &T::alloc_report_type, "808", &T::alloc_intermed_req_type, "573", &T::match_status, "460", &T::product, "167", &T::security_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text, "78", &T::no_allocs);
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmationAck>
{
   using T = glz::fix::fix44::ConfirmationAck;
   static constexpr std::string_view fix_msg_type = "AU";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("664", &T::confirm_id, "75", &T::trade_date, "60", &T::transact_time, "940", &T::affirm_status, "774", &T::confirm_rej_reason, "573", &T::match_status, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::SettlementInstructionRequest>
{
   using T = glz::fix::fix44::SettlementInstructionRequest;
   static constexpr std::string_view fix_msg_type = "AV";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("791", &T::settl_inst_req_id, "60", &T::transact_time, "453", &T::no_party_ids, "79", &T::alloc_account, "661", &T::alloc_acct_id_source, "54", &T::side, "460", &T::product, "167", &T::security_type, "461", &T::cfi_code, "168", &T::effective_time, "126", &T::expire_time, "779", &T::last_update_time, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id);
};
template <>
struct glz::meta<glz::fix::fix44::AssignmentReport>
{
   using T = glz::fix::fix44::AssignmentReport;
   static constexpr std::string_view fix_msg_type = "AW";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("833", &T::asgn_rpt_id, "832", &T::tot_num_assignment_reports, "912", &T::last_rpt_requested, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "702", &T::no_positions, "753", &T::no_pos_amt, "834", &T::threshold_amount, "730", &T::settl_price, "731", &T::settl_price_type, "732", &T::underlying_settl_price, "432", &T::expire_date, "744", &T::assignment_method, "745", &T::assignment_unit, "746", &T::open_interest, "747", &T::exercise_method, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ExecCollGrp>
{
   using T = glz::fix::fix44::ExecCollGrp;
   static constexpr auto value = glz::object("17", &T::exec_id);
};
template <>
struct glz::meta<glz::fix::fix44::TrdCollGrp>
{
   using T = glz::fix::fix44::TrdCollGrp;
   static constexpr auto value = glz::object("571", &T::trade_report_id, "818", &T::secondary_trade_report_id);
};
template <>
struct glz::meta<glz::fix::fix44::UndInstrmtCollGrp>
{
   using T = glz::fix::fix44::UndInstrmtCollGrp;
   static constexpr auto value = glz::object("311", &T::underlying_symbol, "312", &T::underlying_symbol_sfx, "309", &T::underlying_security_id, "305", &T::underlying_security_id_source, "457", &T::no_underlying_security_alt_id, "462", &T::underlying_product, "463", &T::underlying_cfi_code, "310", &T::underlying_security_type, "763", &T::underlying_security_sub_type, "313", &T::underlying_maturity_month_year, "542", &T::underlying_maturity_date, "315", &T::underlying_put_or_call, "241", &T::underlying_coupon_payment_date, "242", &T::underlying_issue_date, "243", &T::underlying_repo_collateral_security_type, "244", &T::underlying_repurchase_term, "245", &T::underlying_repurchase_rate, "246", &T::underlying_factor, "256", &T::underlying_credit_rating, "595", &T::underlying_instr_registry, "592", &T::underlying_country_of_issue, "593", &T::underlying_state_or_province_of_issue, "594", &T::underlying_locale_of_issue, "247", &T::underlying_redemption_date, "316", &T::underlying_strike_price, "941", &T::underlying_strike_currency, "317", &T::underlying_opt_attribute, "436", &T::underlying_contract_multiplier, "435", &T::underlying_coupon_rate, "308", &T::underlying_security_exchange, "306", &T::underlying_issuer, "362", &T::encoded_underlying_issuer_len, "363", &T::encoded_underlying_issuer, "307", &T::underlying_security_desc, "364", &T::encoded_underlying_security_desc_len, "365", &T::encoded_underlying_security_desc, "877", &T::underlying_cp_program, "878", &T::underlying_cp_reg_type, "318", &T::underlying_currency, "879", &T::underlying_qty, "810", &T::underlying_px, "882", &T::underlying_dirty_price, "883", &T::underlying_end_price, "884", &T::underlying_start_value, "885", &T::underlying_current_value, "886", &T::underlying_end_value, "887", &T::no_underlying_stips, "944", &T::coll_action);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralRequest>
{
   using T = glz::fix::fix44::CollateralRequest;
   static constexpr std::string_view fix_msg_type = "AX";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("894", &T::coll_req_id, "895", &T::coll_asgn_reason, "60", &T::transact_time, "126", &T::expire_time, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "899", &T::margin_excess, "900", &T::total_net_value, "901", &T::cash_outstanding, "768", &T::no_trd_reg_timestamps, "54", &T::side, "136", &T::no_misc_fees, "44", &T::price, "423", &T::price_type, "159", &T::accrued_interest_amt, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "232", &T::no_stipulations, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralAssignment>
{
   using T = glz::fix::fix44::CollateralAssignment;
   static constexpr std::string_view fix_msg_type = "AY";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("902", &T::coll_asgn_id, "894", &T::coll_req_id, "895", &T::coll_asgn_reason, "903", &T::coll_asgn_trans_type, "907", &T::coll_asgn_ref_id, "60", &T::transact_time, "126", &T::expire_time, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "899", &T::margin_excess, "900", &T::total_net_value, "901", &T::cash_outstanding, "768", &T::no_trd_reg_timestamps, "54", &T::side, "136", &T::no_misc_fees, "44", &T::price, "423", &T::price_type, "159", &T::accrued_interest_amt, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "232", &T::no_stipulations, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralResponse>
{
   using T = glz::fix::fix44::CollateralResponse;
   static constexpr std::string_view fix_msg_type = "AZ";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("904", &T::coll_resp_id, "902", &T::coll_asgn_id, "894", &T::coll_req_id, "895", &T::coll_asgn_reason, "903", &T::coll_asgn_trans_type, "905", &T::coll_asgn_resp_type, "906", &T::coll_asgn_reject_reason, "60", &T::transact_time, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "899", &T::margin_excess, "900", &T::total_net_value, "901", &T::cash_outstanding, "768", &T::no_trd_reg_timestamps, "54", &T::side, "136", &T::no_misc_fees, "44", &T::price, "423", &T::price_type, "159", &T::accrued_interest_amt, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "232", &T::no_stipulations, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralReport>
{
   using T = glz::fix::fix44::CollateralReport;
   static constexpr std::string_view fix_msg_type = "BA";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("908", &T::coll_rpt_id, "909", &T::coll_inquiry_id, "910", &T::coll_status, "911", &T::tot_num_reports, "912", &T::last_rpt_requested, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "899", &T::margin_excess, "900", &T::total_net_value, "901", &T::cash_outstanding, "768", &T::no_trd_reg_timestamps, "54", &T::side, "136", &T::no_misc_fees, "44", &T::price, "423", &T::price_type, "159", &T::accrued_interest_amt, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "232", &T::no_stipulations, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CollInqQualGrp>
{
   using T = glz::fix::fix44::CollInqQualGrp;
   static constexpr auto value = glz::object("896", &T::coll_inquiry_qualifier);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralInquiry>
{
   using T = glz::fix::fix44::CollateralInquiry;
   static constexpr std::string_view fix_msg_type = "BB";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("909", &T::coll_inquiry_id, "938", &T::no_coll_inquiry_qualifier, "263", &T::subscription_request_type, "725", &T::response_transport_type, "726", &T::response_destination, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "899", &T::margin_excess, "900", &T::total_net_value, "901", &T::cash_outstanding, "768", &T::no_trd_reg_timestamps, "54", &T::side, "44", &T::price, "423", &T::price_type, "159", &T::accrued_interest_amt, "920", &T::end_accrued_interest_amt, "921", &T::start_cash, "922", &T::end_cash, "218", &T::spread, "220", &T::benchmark_curve_currency, "221", &T::benchmark_curve_name, "222", &T::benchmark_curve_point, "662", &T::benchmark_price, "663", &T::benchmark_price_type, "699", &T::benchmark_security_id, "761", &T::benchmark_security_id_source, "232", &T::no_stipulations, "172", &T::settl_delivery_type, "169", &T::stand_inst_db_type, "170", &T::stand_inst_db_name, "171", &T::stand_inst_db_id, "85", &T::no_dlvy_inst, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::CompIDReqGrp>
{
   using T = glz::fix::fix44::CompIDReqGrp;
   static constexpr auto value = glz::object("930", &T::ref_comp_id, "931", &T::ref_sub_id, "283", &T::location_id, "284", &T::desk_id);
};
template <>
struct glz::meta<glz::fix::fix44::NetworkCounterpartySystemStatusRequest>
{
   using T = glz::fix::fix44::NetworkCounterpartySystemStatusRequest;
   static constexpr std::string_view fix_msg_type = "BC";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("935", &T::network_request_type, "933", &T::network_request_id, "936", &T::no_comp_ids);
};
template <>
struct glz::meta<glz::fix::fix44::CompIDStatGrp>
{
   using T = glz::fix::fix44::CompIDStatGrp;
   static constexpr auto value = glz::object("930", &T::ref_comp_id, "931", &T::ref_sub_id, "283", &T::location_id, "284", &T::desk_id, "928", &T::status_value, "929", &T::status_text);
};
template <>
struct glz::meta<glz::fix::fix44::NetworkCounterpartySystemStatusResponse>
{
   using T = glz::fix::fix44::NetworkCounterpartySystemStatusResponse;
   static constexpr std::string_view fix_msg_type = "BD";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("937", &T::network_status_response_type, "933", &T::network_request_id, "932", &T::network_response_id, "934", &T::last_network_response_id, "936", &T::no_comp_ids);
};
template <>
struct glz::meta<glz::fix::fix44::UserRequest>
{
   using T = glz::fix::fix44::UserRequest;
   static constexpr std::string_view fix_msg_type = "BE";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("923", &T::user_request_id, "924", &T::user_request_type, "553", &T::username, "554", &T::password, "925", &T::new_password, "95", &T::raw_data_length, "96", &T::raw_data);
};
template <>
struct glz::meta<glz::fix::fix44::UserResponse>
{
   using T = glz::fix::fix44::UserResponse;
   static constexpr std::string_view fix_msg_type = "BF";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("923", &T::user_request_id, "553", &T::username, "926", &T::user_status, "927", &T::user_status_text);
};
template <>
struct glz::meta<glz::fix::fix44::CollateralInquiryAck>
{
   using T = glz::fix::fix44::CollateralInquiryAck;
   static constexpr std::string_view fix_msg_type = "BG";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("909", &T::coll_inquiry_id, "945", &T::coll_inquiry_status, "946", &T::coll_inquiry_result, "938", &T::no_coll_inquiry_qualifier, "911", &T::tot_num_reports, "453", &T::no_party_ids, "1", &T::account, "581", &T::account_type, "11", &T::cl_ord_id, "37", &T::order_id, "198", &T::secondary_order_id, "526", &T::secondary_cl_ord_id, "124", &T::no_execs, "897", &T::no_trades, "55", &T::symbol, "65", &T::symbol_sfx, "48", &T::security_id, "22", &T::security_id_source, "454", &T::no_security_alt_id, "460", &T::product, "461", &T::cfi_code, "167", &T::security_type, "762", &T::security_sub_type, "200", &T::maturity_month_year, "541", &T::maturity_date, "201", &T::put_or_call, "224", &T::coupon_payment_date, "225", &T::issue_date, "239", &T::repo_collateral_security_type, "226", &T::repurchase_term, "227", &T::repurchase_rate, "228", &T::factor, "255", &T::credit_rating, "543", &T::instr_registry, "470", &T::country_of_issue, "471", &T::state_or_province_of_issue, "472", &T::locale_of_issue, "240", &T::redemption_date, "202", &T::strike_price, "947", &T::strike_currency, "206", &T::opt_attribute, "231", &T::contract_multiplier, "223", &T::coupon_rate, "207", &T::security_exchange, "106", &T::issuer, "348", &T::encoded_issuer_len, "349", &T::encoded_issuer, "107", &T::security_desc, "350", &T::encoded_security_desc_len, "351", &T::encoded_security_desc, "691", &T::pool, "667", &T::contract_settl_month, "875", &T::cp_program, "876", &T::cp_reg_type, "864", &T::no_events, "873", &T::dated_date, "874", &T::interest_accrual_date, "913", &T::agreement_desc, "914", &T::agreement_id, "915", &T::agreement_date, "918", &T::agreement_currency, "788", &T::termination_type, "916", &T::start_date, "917", &T::end_date, "919", &T::delivery_type, "898", &T::margin_ratio, "64", &T::settl_date, "53", &T::quantity, "854", &T::qty_type, "15", &T::currency, "555", &T::no_legs, "711", &T::no_underlyings, "336", &T::trading_session_id, "625", &T::trading_session_sub_id, "716", &T::settl_sess_id, "717", &T::settl_sess_sub_id, "715", &T::clearing_business_date, "725", &T::response_transport_type, "726", &T::response_destination, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
template <>
struct glz::meta<glz::fix::fix44::ConfirmationRequest>
{
   using T = glz::fix::fix44::ConfirmationRequest;
   static constexpr std::string_view fix_msg_type = "BH";
   static constexpr std::string_view fix_begin_string = "FIX.4.4";
   static constexpr auto value = glz::object("859", &T::confirm_req_id, "773", &T::confirm_type, "73", &T::no_orders, "70", &T::alloc_id, "793", &T::secondary_alloc_id, "467", &T::individual_alloc_id, "60", &T::transact_time, "79", &T::alloc_account, "661", &T::alloc_acct_id_source, "798", &T::alloc_account_type, "58", &T::text, "354", &T::encoded_text_len, "355", &T::encoded_text);
};
