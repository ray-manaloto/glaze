// glaze-fix vs hffix read/write benchmark on a synthetic FIX 4.4 corpus.
// Each sample times a batch of consecutive messages; ns/message = batch time / batch size.
// Reported: median and p99 of those per-batch ns/message values, and overall messages/s.

#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "glaze/fix/fix.hpp"
#include "hffix.hpp"

// ---------------------------------------------------------------- message structs
struct NewOrderSingle
{
   std::string sender{};
   std::string target{};
   int64_t seq{};
   std::string sending_time{};
   std::string cl_ord_id{};
   std::string symbol{};
   char side{};
   std::string transact_time{};
   double order_qty{};
   char ord_type{};
   double price{};
};
template <>
struct glz::meta<NewOrderSingle>
{
   using T = NewOrderSingle;
   static constexpr auto fix_msg_type = "D";
   static constexpr auto value =
      glz::object("49", &T::sender, "56", &T::target, "34", &T::seq, "52", &T::sending_time, "11", &T::cl_ord_id,
                  "55", &T::symbol, "54", &T::side, "60", &T::transact_time, "38", &T::order_qty, "40", &T::ord_type,
                  "44", &T::price);
};

struct ExecutionReport
{
   std::string sender{};
   std::string target{};
   int64_t seq{};
   std::string sending_time{};
   std::string order_id{};
   std::string cl_ord_id{};
   std::string exec_id{};
   char exec_type{};
   char ord_status{};
   std::string symbol{};
   char side{};
   double order_qty{};
   double price{};
   double last_qty{};
   double last_px{};
   double leaves_qty{};
   double cum_qty{};
   double avg_px{};
   std::string transact_time{};
};
template <>
struct glz::meta<ExecutionReport>
{
   using T = ExecutionReport;
   static constexpr auto fix_msg_type = "8";
   static constexpr auto value = glz::object(
      "49", &T::sender, "56", &T::target, "34", &T::seq, "52", &T::sending_time, "37", &T::order_id, "11",
      &T::cl_ord_id, "17", &T::exec_id, "150", &T::exec_type, "39", &T::ord_status, "55", &T::symbol, "54", &T::side,
      "38", &T::order_qty, "44", &T::price, "32", &T::last_qty, "31", &T::last_px, "151", &T::leaves_qty, "14",
      &T::cum_qty, "6", &T::avg_px, "60", &T::transact_time);
};

struct MDEntry
{
   char update_action{};
   char entry_type{};
   std::string symbol{};
   double px{};
   int64_t size{};
};
template <>
struct glz::meta<MDEntry>
{
   using T = MDEntry;
   static constexpr auto value =
      glz::object("279", &T::update_action, "269", &T::entry_type, "55", &T::symbol, "270", &T::px, "271", &T::size);
};

struct MarketDataIncrementalRefresh
{
   std::string sender{};
   std::string target{};
   int64_t seq{};
   std::string sending_time{};
   std::string md_req_id{};
   std::vector<MDEntry> entries{};
};
template <>
struct glz::meta<MarketDataIncrementalRefresh>
{
   using T = MarketDataIncrementalRefresh;
   static constexpr auto fix_msg_type = "X";
   static constexpr auto value = glz::object("49", &T::sender, "56", &T::target, "34", &T::seq, "52",
                                             &T::sending_time, "262", &T::md_req_id, "268", &T::entries);
};

// ---------------------------------------------------------------- corpus
struct Corpus
{
   std::string bytes;
   std::vector<std::string_view> msgs;
   std::vector<char> types;
};

static Corpus load(const char* path)
{
   Corpus c;
   std::ifstream f(path, std::ios::binary);
   std::stringstream ss;
   ss << f.rdbuf();
   c.bytes = ss.str();
   std::string_view rest = c.bytes;
   while (!rest.empty()) {
      size_t n = glz::fix::frame(rest);
      if (n == 0 || n == glz::fix::frame_error) {
         std::fprintf(stderr, "corpus framing failed\n");
         std::exit(1);
      }
      auto m = rest.substr(0, n);
      if (auto ec = glz::fix::validate(m)) {
         std::fprintf(stderr, "invalid corpus message\n");
         std::exit(1);
      }
      c.msgs.push_back(m);
      c.types.push_back(m[m.find("\x01" "35=") + 4]);
      rest.remove_prefix(n);
   }
   return c;
}

// ---------------------------------------------------------------- harness
struct Result
{
   double median, p99, msgs_per_s;
};

template <class F>
static Result run(size_t n_msgs, F&& f, int passes = 30, size_t batch = 100)
{
   using clk = std::chrono::steady_clock;
   for (int w = 0; w < 3; ++w) // warm-up
      for (size_t i = 0; i < n_msgs; ++i) f(i);
   std::vector<double> samples;
   samples.reserve(passes * (n_msgs / batch + 1));
   double total_ns = 0;
   size_t total = 0;
   for (int p = 0; p < passes; ++p) {
      for (size_t i = 0; i < n_msgs; i += batch) {
         size_t e = std::min(n_msgs, i + batch);
         auto t0 = clk::now();
         for (size_t j = i; j < e; ++j) f(j);
         auto t1 = clk::now();
         double ns = std::chrono::duration<double, std::nano>(t1 - t0).count();
         samples.push_back(ns / double(e - i));
         total_ns += ns;
         total += e - i;
      }
   }
   std::sort(samples.begin(), samples.end());
   return {samples[samples.size() / 2], samples[size_t(double(samples.size() - 1) * 0.99)],
           double(total) * 1e9 / total_ns};
}

static volatile uint64_t g_sink;

// ---------------------------------------------------------------- hffix helpers
static double to_double(const hffix::field& f)
{
   double d{};
   std::from_chars(f.value().begin(), f.value().end(), d);
   return d;
}
static std::string to_str(const hffix::field& f) { return std::string(f.value().begin(), f.value().end()); }

static void push_px(hffix::message_writer& w, int tag, double v)
{
   w.push_back_decimal<int64_t>(tag, std::llround(v * 100.0), -2);
}

template <bool CheckSum = false>
static bool hffix_read(std::string_view m, char type, NewOrderSingle& nos, ExecutionReport& er,
                       MarketDataIncrementalRefresh& md)
{
   hffix::message_reader r(m.data(), m.size());
   if (!r.is_valid()) return false;
   if constexpr (CheckSum) {
      if (r.calculate_check_sum() != r.check_sum()->value().as_int<unsigned char>()) return false;
   }
   auto it = r.begin();
   auto end = r.end();
   if (type == 'D') {
      for (; it != end; ++it) {
         switch (it->tag()) {
         case 49: nos.sender = to_str(*it); break;
         case 56: nos.target = to_str(*it); break;
         case 34: nos.seq = it->value().as_int<int64_t>(); break;
         case 52: nos.sending_time = to_str(*it); break;
         case 11: nos.cl_ord_id = to_str(*it); break;
         case 55: nos.symbol = to_str(*it); break;
         case 54: nos.side = it->value().as_char(); break;
         case 60: nos.transact_time = to_str(*it); break;
         case 38: nos.order_qty = to_double(*it); break;
         case 40: nos.ord_type = it->value().as_char(); break;
         case 44: nos.price = to_double(*it); break;
         default: break;
         }
      }
   }
   else if (type == '8') {
      for (; it != end; ++it) {
         switch (it->tag()) {
         case 49: er.sender = to_str(*it); break;
         case 56: er.target = to_str(*it); break;
         case 34: er.seq = it->value().as_int<int64_t>(); break;
         case 52: er.sending_time = to_str(*it); break;
         case 37: er.order_id = to_str(*it); break;
         case 11: er.cl_ord_id = to_str(*it); break;
         case 17: er.exec_id = to_str(*it); break;
         case 150: er.exec_type = it->value().as_char(); break;
         case 39: er.ord_status = it->value().as_char(); break;
         case 55: er.symbol = to_str(*it); break;
         case 54: er.side = it->value().as_char(); break;
         case 38: er.order_qty = to_double(*it); break;
         case 44: er.price = to_double(*it); break;
         case 32: er.last_qty = to_double(*it); break;
         case 31: er.last_px = to_double(*it); break;
         case 151: er.leaves_qty = to_double(*it); break;
         case 14: er.cum_qty = to_double(*it); break;
         case 6: er.avg_px = to_double(*it); break;
         case 60: er.transact_time = to_str(*it); break;
         default: break;
         }
      }
   }
   else {
      md.entries.clear();
      MDEntry* cur = nullptr;
      for (; it != end; ++it) {
         switch (it->tag()) {
         case 49: md.sender = to_str(*it); break;
         case 56: md.target = to_str(*it); break;
         case 34: md.seq = it->value().as_int<int64_t>(); break;
         case 52: md.sending_time = to_str(*it); break;
         case 262: md.md_req_id = to_str(*it); break;
         case 268: md.entries.reserve(it->value().as_int<size_t>()); break;
         case 279: cur = &md.entries.emplace_back(); cur->update_action = it->value().as_char(); break;
         case 269: if (cur) cur->entry_type = it->value().as_char(); break;
         case 55: if (cur) cur->symbol = to_str(*it); break;
         case 270: if (cur) cur->px = to_double(*it); break;
         case 271: if (cur) cur->size = it->value().as_int<int64_t>(); break;
         default: break;
         }
      }
   }
   return true;
}

static size_t hffix_write(char* buf, size_t cap, char type, const NewOrderSingle& nos, const ExecutionReport& er,
                          const MarketDataIncrementalRefresh& md)
{
   hffix::message_writer w(buf, buf + cap);
   w.push_back_header("FIX.4.4");
   auto hdr = [&](auto& m, const char* t) {
      w.push_back_string(35, t);
      w.push_back_string(49, m.sender);
      w.push_back_string(56, m.target);
      w.push_back_int(34, m.seq);
      w.push_back_string(52, m.sending_time);
   };
   if (type == 'D') {
      hdr(nos, "D");
      w.push_back_string(11, nos.cl_ord_id);
      w.push_back_string(55, nos.symbol);
      w.push_back_char(54, nos.side);
      w.push_back_string(60, nos.transact_time);
      w.push_back_int(38, int64_t(nos.order_qty));
      w.push_back_char(40, nos.ord_type);
      push_px(w, 44, nos.price);
   }
   else if (type == '8') {
      hdr(er, "8");
      w.push_back_string(37, er.order_id);
      w.push_back_string(11, er.cl_ord_id);
      w.push_back_string(17, er.exec_id);
      w.push_back_char(150, er.exec_type);
      w.push_back_char(39, er.ord_status);
      w.push_back_string(55, er.symbol);
      w.push_back_char(54, er.side);
      w.push_back_int(38, int64_t(er.order_qty));
      push_px(w, 44, er.price);
      w.push_back_int(32, int64_t(er.last_qty));
      push_px(w, 31, er.last_px);
      w.push_back_int(151, int64_t(er.leaves_qty));
      w.push_back_int(14, int64_t(er.cum_qty));
      push_px(w, 6, er.avg_px);
      w.push_back_string(60, er.transact_time);
   }
   else {
      hdr(md, "X");
      w.push_back_string(262, md.md_req_id);
      w.push_back_int(268, md.entries.size());
      for (auto& e : md.entries) {
         w.push_back_char(279, e.update_action);
         w.push_back_char(269, e.entry_type);
         w.push_back_string(55, e.symbol);
         push_px(w, 270, e.px);
         w.push_back_int(271, e.size);
      }
   }
   w.push_back_trailer();
   return size_t(w.message_end() - buf);
}

// ---------------------------------------------------------------- main
int main(int argc, char** argv)
{
   const char* path = argc > 1 ? argv[1] : FIX_CORPUS;
   Corpus c = load(path);
   const size_t n = c.msgs.size();
   std::printf("corpus: %s\nmessages: %zu, bytes: %zu (avg %.1f bytes/msg)\n\n", path, n, c.bytes.size(),
               double(c.bytes.size()) / double(n));

   // Pre-decode with glaze (also a correctness check: glaze write must reproduce the corpus bytes).
   std::vector<NewOrderSingle> nos(n);
   std::vector<ExecutionReport> er(n);
   std::vector<MarketDataIncrementalRefresh> md(n);
   size_t mismatches = 0;
   std::string out;
   for (size_t i = 0; i < n; ++i) {
      glz::error_ctx ec{};
      if (c.types[i] == 'D') { ec = glz::read<glz::fix_opts{}>(nos[i], c.msgs[i]); if (!ec) ec = glz::write<glz::fix_opts{}>(nos[i], out); }
      else if (c.types[i] == '8') { ec = glz::read<glz::fix_opts{}>(er[i], c.msgs[i]); if (!ec) ec = glz::write<glz::fix_opts{}>(er[i], out); }
      else { ec = glz::read<glz::fix_opts{}>(md[i], c.msgs[i]); if (!ec) ec = glz::write<glz::fix_opts{}>(md[i], out); }
      if (ec) { std::fprintf(stderr, "glaze failed on message %zu: %s\n", i, ec.custom_error_message.data()); return 1; }
      if (out != c.msgs[i]) ++mismatches;
   }
   // hffix correctness check: decoded struct equals glaze's decode for a sample of fields.
   size_t hffix_mismatch = 0;
   {
      NewOrderSingle a; ExecutionReport b; MarketDataIncrementalRefresh m;
      for (size_t i = 0; i < n; ++i) {
         if (!hffix_read<true>(c.msgs[i], c.types[i], a, b, m)) { ++hffix_mismatch; continue; }
         if (c.types[i] == 'D' && (a.cl_ord_id != nos[i].cl_ord_id || a.price != nos[i].price)) ++hffix_mismatch;
         if (c.types[i] == '8' && (b.exec_id != er[i].exec_id || b.avg_px != er[i].avg_px)) ++hffix_mismatch;
         if (c.types[i] == 'X' && m.entries.size() != md[i].entries.size()) ++hffix_mismatch;
      }
   }
   std::printf("glaze write == corpus bytes: %zu/%zu mismatches\n", mismatches, n);
   std::printf("hffix decode == glaze decode: %zu/%zu mismatches\n\n", hffix_mismatch, n);

   NewOrderSingle a; ExecutionReport b; MarketDataIncrementalRefresh m;
   std::string gbuf;
   gbuf.reserve(4096);
   char hbuf[4096];

   struct Row { const char* name; Result r; };
   std::vector<Row> rows;

   rows.push_back({"glaze-fix read", run(n, [&](size_t i) {
      glz::error_ctx ec{};
      if (c.types[i] == 'D') ec = glz::read<glz::fix_opts{}>(a, c.msgs[i]);
      else if (c.types[i] == '8') ec = glz::read<glz::fix_opts{}>(b, c.msgs[i]);
      else ec = glz::read<glz::fix_opts{}>(m, c.msgs[i]);
      g_sink = g_sink + uint64_t(bool(ec)) + uint64_t(a.seq + b.seq + m.seq);
   })});
   rows.push_back({"hffix read", run(n, [&](size_t i) {
      bool ok = hffix_read(c.msgs[i], c.types[i], a, b, m);
      g_sink = g_sink + uint64_t(ok) + uint64_t(a.seq + b.seq + m.seq);
   })});
   static constexpr glz::fix_opts no_cs{{}, glz::FIX, '\x01', false};
   rows.push_back({"glaze-fix read (no 10= check)", run(n, [&](size_t i) {
      glz::error_ctx ec{};
      if (c.types[i] == 'D') ec = glz::read<no_cs>(a, c.msgs[i]);
      else if (c.types[i] == '8') ec = glz::read<no_cs>(b, c.msgs[i]);
      else ec = glz::read<no_cs>(m, c.msgs[i]);
      g_sink = g_sink + uint64_t(bool(ec)) + uint64_t(a.seq + b.seq + m.seq);
   })});
   rows.push_back({"hffix read + 10= check", run(n, [&](size_t i) {
      bool ok = hffix_read<true>(c.msgs[i], c.types[i], a, b, m);
      g_sink = g_sink + uint64_t(ok) + uint64_t(a.seq + b.seq + m.seq);
   })});
   rows.push_back({"glaze-fix write", run(n, [&](size_t i) {
      glz::error_ctx ec{};
      if (c.types[i] == 'D') ec = glz::write<glz::fix_opts{}>(nos[i], gbuf);
      else if (c.types[i] == '8') ec = glz::write<glz::fix_opts{}>(er[i], gbuf);
      else ec = glz::write<glz::fix_opts{}>(md[i], gbuf);
      g_sink = g_sink + gbuf.size() + uint64_t(bool(ec));
   })});
   rows.push_back({"hffix write", run(n, [&](size_t i) {
      g_sink = g_sink + hffix_write(hbuf, sizeof(hbuf), c.types[i], nos[i], er[i], md[i]);
   })});

   std::printf("| benchmark | median ns/msg | p99 ns/msg | msgs/s |\n|---|---:|---:|---:|\n");
   for (auto& r : rows)
      std::printf("| %s | %.1f | %.1f | %.0f |\n", r.name, r.r.median, r.r.p99, r.r.msgs_per_s);
   return 0;
}
