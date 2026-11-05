# C++26 static reflection and glaze-fix

This note explains what C++26 reflection is, what parts of it a FIX tag=value
codec can use, how far compilers have come, how glaze reflects structs today,
and a concrete design for a reflection-driven glaze-fix with a C++23 fallback.

Where the state of the world is uncertain (compiler status in particular) the
text says so. Nothing here is a measurement; it is a design discussion.

## 1. The relevant C++26 papers

### P2996 — Reflection for C++26

P2996 is the core proposal and was adopted into the C++26 working draft. Its
building blocks:

- `^^T` (the reflection operator) yields a `std::meta::info`, an opaque
  constexpr handle that can denote a type, a non-static data member, an
  enumerator, a namespace, a value, and so on.
- `std::meta::nonstatic_data_members_of(^^T, ctx)` returns a
  `std::vector<std::meta::info>` listing the fields of `T` in declaration
  order. The second argument is an `access_context`; `access_context::unchecked()`
  sees private members, `access_context::current()` only what the calling
  code could name.
- `std::meta::identifier_of(m)` gives the spelled name as a `string_view`
  (`"cl_ord_id"`), `type_of(m)` the member's type, `offset_of(m)`,
  `alignment_of(m)`, `is_public(m)` and similar predicates.
- Splicing, `[: r :]`, turns a reflection back into source. `obj.[:m:]` reads
  a member, `typename [:t:]` names a type, `[:v:]` yields a constant value.
- Everything runs in `consteval`/constant-evaluated contexts only. A
  `std::vector<info>` produced by a metafunction cannot escape to runtime, but
  it can be converted with `std::define_static_array` or copied element by
  element into a `std::array` in a `constexpr` variable's initialiser.

### P3394 — Annotations for reflection

P3394 adds `[[= expr]]` annotations: an attribute-like syntax whose operand is
an arbitrary constant expression attached to a declaration. Reflection reads
them back with `std::meta::annotations_of(m)` and
`annotations_of_with_type<A>(m)` (names as in the adopted paper; earlier drafts
used slightly different spellings). This is the piece that makes a FIX mapping
declarative:

```cpp
struct NewOrderSingle {
   [[=fix::tag(11)]] std::string cl_ord_id;
   [[=fix::tag(55)]] std::string symbol;
   [[=fix::tag(54)]] char side;
   [[=fix::tag(38)]] fix::decimal order_qty;
   [[=fix::tag(44)]] std::optional<fix::decimal> price;
   [[=fix::tag(60)]] fix::utc_timestamp transact_time;
};
```

`fix::tag` is just a literal struct:

```cpp
namespace glz::fix {
   struct tag { uint32_t value; };
   struct msg_type { char code[3]; };     // [[=fix::msg_type("D")]] on the struct
   struct group { uint32_t count_tag; };  // for repeating groups
}
```

### P1306 — Expansion statements (`template for`)

P1306 adds `template for (constexpr auto m : members) { ... }` which stamps out
the body once per element of a constant range, with `m` a constant in each
copy. It removes the `for_each<N>([&]<size_t I>(){})` lambda idiom that glaze
uses today and lets the body contain `if constexpr`, `return`, and splices
directly. P1306 was adopted for C++26 after P2996; its compiler support lags
P2996 itself in some implementations, so the design below never depends on it
for correctness, only for brevity.

### `define_aggregate`

`std::meta::define_aggregate(^^S, {data_member_spec(^^int, {.name="x"}), ...})`
completes a previously declared incomplete struct with synthesized members.
For glaze-fix it is interesting for generating *parallel* structs, for example
a "presence bitmap" or a struct-of-`std::string_view` shadow for lazy parsing.
It is the most exotic of the facilities, the least implemented, and the design
below treats it as optional.

## 2. Compiler status (as understood at the time of writing)

State these with care; verify against the vendor's own documentation before
relying on any of them.

- **Clang (Bloomberg `clang-p2996` fork).** The reference implementation of
  P2996, maintained by Bloomberg on GitHub, tracks the paper closely and
  implements `^^`, splicing, `nonstatic_data_members_of`, `identifier_of`,
  annotations (P3394) and `define_aggregate`. Enabled with
  `-freflection` (and `-freflection-latest` for the newest spelling). It is
  a fork, not an upstream release; upstream LLVM has been upstreaming pieces
  but, to my knowledge, no released upstream Clang ships complete P2996. The
  glaze `GLZ_REFLECTION26` path was developed against this fork.
- **GCC.** Work on P2996 landed on the GCC trunk aimed at the GCC 16 release
  series, behind `-freflection` (with `-std=c++26`). How complete it is with
  respect to P3394 annotations and P1306 expansion statements is something I
  am not certain about; the core operator, splices and member enumeration are
  the parts most likely to work first. Treat annotations on GCC as "check the
  release notes".
- **EDG.** EDG's front end had an early implementation available on Compiler
  Explorer and is believed to be fairly complete for P2996 proper; it is not
  a production toolchain for most users.
- **MSVC.** No public implementation that I am aware of at the time of
  writing.

Feature-test macros: `__cpp_impl_reflection` (language) and
`__cpp_lib_reflection` (`<meta>` library). glaze already keys `GLZ_REFLECTION26`
off both in `include/glaze/core/feature_test.hpp`, and allows forcing it with
`-DGLZ_REFLECTION26=1` or the `glaze_ENABLE_REFLECTION26` CMake option.

Because P3394 may be present without P1306 (or vice versa), the FIX design
should test for them separately:

```cpp
#if defined(__cpp_impl_reflection)
#  define GLZ_FIX_HAS_P2996 1
#endif
#if defined(__cpp_annotations) || defined(__cpp_impl_annotations) // spelling may differ by vendor
#  define GLZ_FIX_HAS_ANNOTATIONS 1
#endif
#if defined(__cpp_expansion_statements)
#  define GLZ_FIX_HAS_TEMPLATE_FOR 1
#endif
```

## 3. How glaze reflects today

Two paths, selected by `GLZ_REFLECTION26`:

1. **Pre-C++26** (`include/glaze/reflection/to_tuple.hpp`,
   `get_name.hpp`): `count_members<T>` is found by probing aggregate
   initialisation with an `any_t` that converts to anything; `to_tie(obj)`
   uses structured bindings of the matching arity to produce a tuple of
   references; member names are recovered from `__PRETTY_FUNCTION__` /
   `__FUNCSIG__` of a function template instantiated with a pointer to each
   member. This only works for aggregates and needs a large generated table of
   structured-binding arities.
2. **C++26** (same headers under `#if GLZ_REFLECTION26`):
   `count_members<T>` is `nonstatic_data_members_of(^^T, unchecked()).size()`,
   `get_member_ref<I>(obj)` is `obj.[:member:]`, and `get_name<T, I>` is
   `identifier_of(members[I])`. Non-aggregates and inherited members work.

Both paths feed `glz::reflect<T>` in `include/glaze/core/reflect.hpp`, which
exposes `reflect<T>::size`, `reflect<T>::keys` (a `std::array<string_view>`)
and per-index member access. A user-provided `glz::meta<T>` specialisation with
`static constexpr auto value = object("11", &T::cl_ord_id, ...)` overrides the
automatic names, and `glaze_object_t<T>` is the concept for "has a meta".

glaze-fix today (`include/glaze/fix/codec.hpp`) builds on `glz::meta` only:
the mapping keys are decimal tag numbers written as strings, `tag_at<T>(I)`
parses the I-th key with `parse_uint`, `tags<T>` is a `constexpr
std::array<uint32_t, N>`, and `member_index<T>(tag)` is a linear scan over
that array. Writing walks members with `for_each<reflect<T>::size>` and calls
`put_tag` which runs `std::to_chars` on each tag at runtime. Repeating groups
are `std::vector<S>` members whose key is the `NoXXX` count tag; the group's
first member is its delimiter.

So the moving parts that reflection can improve are: how the tag table is
declared, how tags are dispatched when reading, and how much of the output
bytes are fixed at compile time.

## 4. Design

### 4.1 Field descriptor and tag table

Everything downstream consumes one `constexpr` table per message type, built
once by whichever front end is available:

```cpp
namespace glz::fix::detail {
   enum class kind : uint8_t { scalar, optional, group, raw_data };

   struct field_desc {
      uint32_t tag;          // FIX tag number
      uint16_t index;        // member index in T
      kind     k;
      uint32_t length_tag;   // for raw_data, the paired length tag (95 for 96), else 0
   };

   template <class T>
   inline constexpr auto fields = build_fields<T>(); // std::array<field_desc, N>
}
```

**Reflection front end** (P2996 + P3394):

```cpp
template <class T>
consteval auto build_fields()
{
   constexpr auto members = std::define_static_array(
      std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::unchecked()));
   std::array<field_desc, members.size()> out{};
   for (size_t i = 0; i < members.size(); ++i) {
      auto m = members[i];
      auto tags = std::meta::annotations_of_with_type<fix::tag>(m);
      if (tags.size() != 1) throw "every FIX member needs exactly one [[=fix::tag(N)]]";
      // extract<T>(info) pulls the constant value back out of the annotation
      const uint32_t t = std::meta::extract<fix::tag>(tags[0]).value;
      out[i] = field_desc{
         .tag = t,
         .index = uint16_t(i),
         .k = classify(std::meta::type_of(m)),
         .length_tag = raw_length_tag_for(t),
      };
   }
   return out;
}
```

`classify` inspects `type_of(m)` with `template_of`/`is_specialization_of`
style queries, or simply by splicing into an existing trait:
`is_optional<typename [:type_of(m):]>`. Throwing in a `consteval` function
turns a missing or duplicated tag into a compile error with a readable message,
which is what the current `std::abort()` in `tag_at` approximates.

**C++23 front end** (`glz::meta` + constexpr arrays), which is essentially what
`codec.hpp` does now, repackaged to produce the same `field_desc` array:

```cpp
template <class T>
consteval auto build_fields()
{
   std::array<field_desc, reflect<T>::size> out{};
   for_each<reflect<T>::size>([&]<size_t I>() {
      uint32_t t{};
      if (!parse_uint(get<I>(reflect<T>::keys), t)) std::abort();
      using M = member_type_t<T, I>;
      out[I] = field_desc{t, uint16_t(I), classify<M>(), raw_length_tag_for(t)};
   });
   return out;
}
```

A user who is on C++23 keeps writing

```cpp
template <> struct glz::meta<NewOrderSingle> {
   using T = NewOrderSingle;
   static constexpr auto value = object("11", &T::cl_ord_id, "55", &T::symbol, ...);
};
```

and the same struct annotated with `[[=fix::tag(..)]]` compiles on both: on a
pre-reflection compiler the annotations are ignored (unknown attributes are
ignored by rule; whether `[[= ...]]` parses cleanly on older compilers needs a
check, otherwise wrap it in a `GLZ_FIX_TAG(n)` macro that expands to nothing
when annotations are unavailable). An optional `glz::meta` can coexist, and the
reflection front end should prefer an explicit `glz::meta` when one exists so
existing code is unchanged.

Member access is unified by `glz::reflect`'s existing `get_member_ref<I>`,
which already splices under `GLZ_REFLECTION26` and uses structured bindings
otherwise. Everything after the table is written once.

### 4.2 Generated field dispatch when reading

Today `member_index<T>(tag)` is a linear scan. With `fields<T>` as a constant,
two better shapes are available, both expressible without `template for` and
nicer with it.

**Switch over tags.** Because every tag is a compile-time constant, a
visitor can be generated as a `switch`, which the optimiser turns into a jump
table or a binary search as it sees fit:

```cpp
template <class T, class F>
GLZ_ALWAYS_INLINE bool dispatch(uint32_t tag, T& obj, F&& f)
{
#if GLZ_FIX_HAS_TEMPLATE_FOR
   switch (tag) {
      template for (constexpr auto d : fields<T>) {
         case d.tag: f.template operator()<d>(get_member_ref<d.index>(obj)); return true;
      }
   }
   return false;
#else
   bool hit = false;
   for_each<fields<T>.size()>([&]<size_t I>() {
      constexpr auto d = fields<T>[I];
      if (!hit && tag == d.tag) { f.template operator()<d>(get_member_ref<I>(obj)); hit = true; }
   });
   return hit;
#endif
}
```

**Perfect hash.** FIX tags for one message are a small, sparse set of
integers (11, 38, 40, 44, 54, 55, 60, ...). A constexpr search over multiplier
and table size finds a collision-free `((tag * k) >> shift) & mask` at compile
time; the table stores `uint16_t` member indices with a sentinel for empty
slots, and a single compare on `fields<T>[idx].tag == tag` validates the hit:

```cpp
template <class T>
inline constexpr auto tag_hash = find_perfect_hash(fields<T>); // {k, shift, table}

template <class T>
constexpr int member_index(uint32_t tag) noexcept
{
   constexpr auto& h = tag_hash<T>;
   const auto slot = h.table[(tag * h.k) >> h.shift];
   return (slot != h.empty && fields<T>[slot].tag == tag) ? int(slot) : -1;
}
```

This is independent of reflection; it only needs `fields<T>` to be constexpr,
so it benefits the C++23 path equally. glaze already has a compile-time hash
search for JSON keys that this can mirror.

The "unknown tag" handling that exists today (session envelope tags 8/9/35/10
skipped, `error_on_unknown_tags`, raw-data length tags folded into their data
tag) sits unchanged behind `member_index`.

### 4.3 Precomputed `"35="` prefixes

`put_tag` currently formats the tag number with `std::to_chars` on every
write. The tag is a constant per field, so the whole `"tag="` prefix can be a
`constexpr` byte string chosen at compile time and copied as a fixed-size
block:

```cpp
template <uint32_t Tag>
inline constexpr auto tag_prefix = [] {
   constexpr size_t n = digits(Tag);
   std::array<char, n + 1> a{};
   uint32_t v = Tag;
   for (size_t i = n; i-- > 0; v /= 10) a[i] = char('0' + v % 10);
   a[n] = '=';
   return a;
}();

template <auto D, class V>
void write_field(std::string& out, const V& v)
{
   constexpr auto& p = tag_prefix<D.tag>;
   out.append(p.data(), p.size());
   write_value(out, v);
   out.push_back(soh);
}
```

For messages whose header fields are fixed for a session (`8=FIX.4.4`,
`35=D`), the message-type annotation on the struct lets the writer emit the
`"35=D\x01"` fragment as one constant as well:

```cpp
template <class T>
inline constexpr auto msg_type_field = [] {
   constexpr auto a = std::meta::annotations_of_with_type<fix::msg_type>(^^T);
   static_assert(a.size() == 1);
   return concat("35=", std::meta::extract<fix::msg_type>(a[0]).code, "\x01");
}();
```

On C++23 the same thing comes from a `static constexpr std::string_view
msg_type = "D";` in `glz::meta<T>`.

### 4.4 Partial checksums

The FIX checksum (`10=`) is the byte sum of everything before the `10=` field
modulo 256, and `BodyLength (9)` is the byte count between `9=` and `10=`.
Both are additive, so the contribution of every constant fragment can be
computed when the fragment is:

```cpp
struct fragment {
   std::string_view bytes;
   uint32_t sum;     // sum of bytes, before mod 256
};

template <uint32_t Tag>
inline constexpr fragment tag_prefix_frag{
   {tag_prefix<Tag>.data(), tag_prefix<Tag>.size()},
   byte_sum(tag_prefix<Tag>)};
```

The writer then accumulates `running_sum += frag.sum` for constant parts and
only sums the bytes of the variable value text it formats itself. At the end
`10=` is `running_sum % 256` without a second pass over the buffer, and the
body length is `out.size() - body_start`. Even further: for a struct whose
field set is always fully present (no optionals, no groups), the sum of *all*
`"tag="` prefixes plus the separators is one constant, `static_checksum_part<T>`,
computed by folding `fields<T>`.

Today `codec.hpp` computes `fix::checksum(msg)` over the completed buffer and
validates it on read with `fix::validate`. The read side is unaffected by this
design; keeping the single-pass validator there is the right call because the
wire bytes are not known at compile time.

### 4.5 Repeating groups

A `std::vector<S>` member annotated `[[=fix::group(268)]]` (or keyed `"268"`
in `glz::meta`) is a group whose count tag is 268 and whose delimiter is
`fields<S>[0].tag`. The reflection front end can `static_assert` at compile
time that `S` carries at least one tagged member and that the delimiter tag
does not collide with the parent's tags, which is a class of mistake that is
only discoverable at runtime today.

### 4.6 What `define_aggregate` could add later

Two possible uses, both optional:

- A generated `presence<T>` bitset struct whose members mirror `T`'s names,
  so a parsed message can report "which tags were on the wire" without
  wrapping every field in `std::optional`.
- A `lazy<T>` shadow where every member is a `std::string_view` into the
  input buffer, with conversion on demand.

Both can be done without `define_aggregate` using `std::bitset<N>` and
`std::array<string_view, N>` indexed by `field_desc::index`; the gain from
`define_aggregate` is nicer spelling (`p.cl_ord_id` rather than `p[0]`), not
new capability. Given its implementation status it should not be on the
critical path.

## 5. Rollout plan

1. Introduce `field_desc` and `fields<T>` in `codec.hpp`, built from
   `glz::meta` as today. Switch `member_index` and the writer to consume
   `fields<T>`. No user-visible change; this is a refactor and is testable on
   every current compiler.
2. Add the constexpr `tag_prefix<Tag>` and fragment sums, and the perfect-hash
   `member_index`. Still C++23.
3. Behind `GLZ_FIX_HAS_ANNOTATIONS`, add the annotation front end for
   `build_fields<T>` and the struct-level `fix::msg_type`. Give explicit
   `glz::meta` precedence so no existing mapping changes meaning.
4. Behind `GLZ_FIX_HAS_TEMPLATE_FOR`, replace the `for_each` lambdas in the
   dispatch and writer with `template for`. Keep the lambda version as the
   fallback body.
5. CI: one job on the Bloomberg clang-p2996 fork with `-freflection
   -freflection-latest -std=c++26`, one on GCC 16 with `-freflection` once a
   release is available, plus the existing C++23 matrix. The reflection jobs
   should compile the same test sources as the C++23 jobs so the two front
   ends are proven to produce identical `fields<T>` tables (a `static_assert`
   comparing the two when both are available is cheap and worth having).

## 6. Risks and open questions

- Exact library spellings (`annotations_of_with_type`, `extract`,
  `define_static_array`) have shifted between paper revisions; keep them
  confined to one small header so a rename is a one-place fix.
- Whether `[[= ...]]` is silently ignored or rejected by pre-C++26 compilers
  determines whether users can annotate structs unconditionally or need a
  macro. This must be checked on GCC, Clang and MSVC before documenting the
  annotation syntax as the recommended one.
- `access_context::unchecked()` lets reflection see private members. The FIX
  front end should probably only map members that carry a `fix::tag`
  annotation and ignore the rest, which also sidesteps the question of what to
  do with untagged private state.
- Build-time cost of large consteval tables is unknown for very wide messages
  (hundreds of tags); the perfect-hash search should have a bounded number of
  attempts and fall back to the `switch` form when it fails.
