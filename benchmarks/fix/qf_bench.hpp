// QuickFIX C++ read/write paths for fix_bench.cpp (only built with -DFIX_BENCH_QUICKFIX=ON).
#pragma once
#include "DataDictionary.h"
#include "Message.h"
#include "Group.h"

namespace qf
{
   inline std::string get(const FIX::FieldMap& m, int tag) { return m.getField(tag); }
   inline double getd(const FIX::FieldMap& m, int tag)
   {
      const std::string& s = m.getFieldRef(tag).getString();
      double d{};
      std::from_chars(s.data(), s.data() + s.size(), d);
      return d;
   }
   inline int64_t geti(const FIX::FieldMap& m, int tag)
   {
      const std::string& s = m.getFieldRef(tag).getString();
      int64_t v{};
      std::from_chars(s.data(), s.data() + s.size(), v);
      return v;
   }
   inline char getc(const FIX::FieldMap& m, int tag) { return m.getFieldRef(tag).getString()[0]; }

   // Parse (QuickFIX validates BodyLength and CheckSum in setString with validate=true), then
   // extract fields into the same structs as the other libraries.
   inline bool read(const FIX::DataDictionary& dd, FIX::Message& msg, const std::string& s, char type,
                    NewOrderSingle& nos, ExecutionReport& er, MarketDataIncrementalRefresh& md)
   {
      try {
         msg.setString(s, true, &dd);
      }
      catch (...) {
         return false;
      }
      auto hdr = [&](auto& o) {
         const auto& h = msg.getHeader();
         o.sender = get(h, 49);
         o.target = get(h, 56);
         o.seq = geti(h, 34);
         o.sending_time = get(h, 52);
      };
      if (type == 'D') {
         hdr(nos);
         nos.cl_ord_id = get(msg, 11); nos.symbol = get(msg, 55); nos.side = getc(msg, 54);
         nos.transact_time = get(msg, 60); nos.order_qty = getd(msg, 38); nos.ord_type = getc(msg, 40);
         nos.price = getd(msg, 44);
      }
      else if (type == '8') {
         hdr(er);
         er.order_id = get(msg, 37); er.cl_ord_id = get(msg, 11); er.exec_id = get(msg, 17);
         er.exec_type = getc(msg, 150); er.ord_status = getc(msg, 39); er.symbol = get(msg, 55);
         er.side = getc(msg, 54); er.order_qty = getd(msg, 38); er.price = getd(msg, 44);
         er.last_qty = getd(msg, 32); er.last_px = getd(msg, 31); er.leaves_qty = getd(msg, 151);
         er.cum_qty = getd(msg, 14); er.avg_px = getd(msg, 6); er.transact_time = get(msg, 60);
      }
      else {
         hdr(md);
         md.md_req_id = get(msg, 262);
         size_t n = size_t(msg.groupCount(268));
         md.entries.resize(n);
         FIX::Group g(268, 279);
         for (size_t i = 0; i < n; ++i) {
            msg.getGroup(unsigned(i + 1), g);
            auto& e = md.entries[i];
            e.update_action = getc(g, 279); e.entry_type = getc(g, 269); e.symbol = get(g, 55);
            e.px = getd(g, 270); e.size = geti(g, 271);
         }
      }
      return true;
   }

   inline std::string dstr(double d)
   {
      char b[32];
      auto r = std::to_chars(b, b + sizeof(b), d);
      return std::string(b, r.ptr);
   }

   inline size_t write(char type, const NewOrderSingle& nos, const ExecutionReport& er,
                       const MarketDataIncrementalRefresh& md, std::string& out)
   {
      FIX::Message m;
      auto& h = m.getHeader();
      auto hdr = [&](auto& o, const char* t) {
         h.setField(8, "FIX.4.4");
         h.setField(35, t);
         h.setField(49, o.sender);
         h.setField(56, o.target);
         h.setField(34, std::to_string(o.seq));
         h.setField(52, o.sending_time);
      };
      if (type == 'D') {
         hdr(nos, "D");
         m.setField(11, nos.cl_ord_id); m.setField(55, nos.symbol); m.setField(54, std::string(1, nos.side));
         m.setField(60, nos.transact_time); m.setField(38, dstr(nos.order_qty));
         m.setField(40, std::string(1, nos.ord_type)); m.setField(44, dstr(nos.price));
      }
      else if (type == '8') {
         hdr(er, "8");
         m.setField(37, er.order_id); m.setField(11, er.cl_ord_id); m.setField(17, er.exec_id);
         m.setField(150, std::string(1, er.exec_type)); m.setField(39, std::string(1, er.ord_status));
         m.setField(55, er.symbol); m.setField(54, std::string(1, er.side)); m.setField(38, dstr(er.order_qty));
         m.setField(44, dstr(er.price)); m.setField(32, dstr(er.last_qty)); m.setField(31, dstr(er.last_px));
         m.setField(151, dstr(er.leaves_qty)); m.setField(14, dstr(er.cum_qty)); m.setField(6, dstr(er.avg_px));
         m.setField(60, er.transact_time);
      }
      else {
         hdr(md, "X");
         m.setField(262, md.md_req_id);
         for (auto& e : md.entries) {
            FIX::Group g(268, 279);
            g.setField(279, std::string(1, e.update_action)); g.setField(269, std::string(1, e.entry_type));
            g.setField(55, e.symbol); g.setField(270, dstr(e.px)); g.setField(271, std::to_string(e.size));
            m.addGroup(g);
         }
      }
      m.toString(out);
      return out.size();
   }
}
