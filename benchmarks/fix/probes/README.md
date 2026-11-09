# Layout and tag-lookup probes (spike, not part of the library)

Small programs behind the glaze-fix 3-part design decisions. Each file states what it checks.

| File | Checks |
|---|---|
| `bitfield_reflection.cpp` | C++26 splices read and write enum bit-fields; `stdx::optional` size; `sys_time<ns>` is 8 bytes |
| `enum_char_bitfield.cpp` | a 7-bit field of a `char`-based enum corrupts codes >= 64 where `char` is signed |
| `reflect_cpp_order.cpp` | reflect-cpp XML binding loses interleaved element order; pugixml walk + per-node binding keeps it |
| `struct_size_options.cpp` | `sizeof` of a NewOrderSingle-shaped struct under text-reference and field-subset options |
| `reflect_cpp_orchestra/orchestra_model.cpp` | plain reflect-cpp (`rfl::xml::load`) reading a FIX Orchestra file into hand-written structs; prints what it read as JSON |
| `tag_lookup_mac.cpp`, `tags.hpp` | tag-lookup methods (linear, sorted, direct array, hand hash, mph, cib, frozen) on the three Mac compilers |
| `tag_lookup_mac.sh` | builds and times each method (cycles and instructions per lookup, best of N), libc++ hardening set to none |
| `lookup_asm.sh` | disassembles each method's lookup built out of line and models it with llvm-mca (Apple M2) |
| `lookup_inline_asm.sh` | disassembles the timed loop itself, with the lookup inlined, split by source line |
| `mph-portable-bucket.patch` | qlibs/mph patch: scalar bucket search by default on every compiler (`MPH_USE_EXPERIMENTAL_SIMD=1` opts back in to `std::experimental::simd`), self-contained includes, no 64-entry limit; empty slots can no longer match an absent key (upstream marked them with key 0, so an absent key 0 was found) |

Run: `./run.sh <libs dir>`; the lookup scripts take `<libs dir>` (plus an output dir for the asm scripts). Apply the patch inside the libs dir with `patch -p0 < mph-portable-bucket.patch`; it patches `mph/mph` (the qlibs/mph header) in place. Third-party libraries are fetched separately and are not part of this folder.
