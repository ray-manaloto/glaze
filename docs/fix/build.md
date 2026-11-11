# Building glaze-fix: presets, toolchain and vcpkg

## Run

```sh
cmake --workflow --preset gcc16-release    # configure, build, test
cmake --list-presets                       # all presets
```

There are 11 presets, one per compiler and configuration. Each has configure, build, test and workflow presets of the same name.

| Compiler | debug | release | asan | tsan |
|---|---|---|---|---|
| GCC 16.2 (`g++-16`, `-freflection`) | `gcc16-debug` | `gcc16-release` | `gcc16-asan` | none: GCC 16 has no TSan runtime on macOS |
| Homebrew LLVM clang 23 (`clang++`, libc++) | `clang23-debug` | `clang23-release` | `clang23-asan` | `clang23-tsan` |
| clang-p2996 (`clang++-p2996`, libc++, reflection) | `p2996-debug` | `p2996-release` | `p2996-asan` | `p2996-tsan` |

- **release:** `Release`, with standard library hardening off. It matches the benchmarks.
- **debug:** `Debug`, with libc++ hardening set to `debug`. On GCC this is `_GLIBCXX_ASSERTIONS`.
- **asan:** `debug` plus AddressSanitizer and UBSan (`-fno-sanitize-recover`, so UB fails the test), with vcpkg's libraries built the same way (`-asan` triplets). Leak checking (`detect_leaks=1`) is on for clang23 and p2996; it is off on GCC 16, where an ASan binary with leak checking hangs at exit on this Mac.
- **tsan:** `debug` plus ThreadSanitizer, with vcpkg's libraries built with TSan too (`-tsan` triplets). TSan cannot share a build with ASan, hence a separate preset.
- Checked on this Mac with a deliberate bug per sanitizer: ASan (heap-buffer-overflow) and UBSan (signed overflow) report on all three compilers; TSan reports a data race on clang23 and p2996, and does not link on GCC 16. MemorySanitizer is Linux-only.

The presets set `glaze_ENABLE_SANITIZERS=OFF` and `glaze_ENABLE_FUZZING=OFF`: upstream's test CMake otherwise adds ASan and UBSan to every clang test build, release included, which would make release timings meaningless and clash with TSan. Sanitizers come only from the preset.

Every build directory is `build/<preset>`. Upstream glaze's own presets (`clang-debug`, `gcc-release`, ...) are unchanged in `CMakePresets.json`. The glaze-fix presets live in `cmake/presets/glaze-fix.json`, which that file includes.

## Pieces

- **`cmake/toolchains/glaze-fix.cmake`** is one toolchain for every compiler. It picks the compiler from `GLAZE_FIX_COMPILER` by its bare name on PATH and sets the flags for C++26, reflection, libc++, hardening and sanitizers. A compiler outside PATH is named by the environment variables `GLAZE_FIX_CXX` and `GLAZE_FIX_CC`, for example in the `environment` of a preset in a gitignored `CMakeUserPresets.json`. The triplets pass both through to vcpkg (`VCPKG_ENV_PASSTHROUGH`), so the ports get the same compiler. Setting `CMAKE_CXX_COMPILER` instead would reach only the project, not the ports. No machine path is committed.
- **clang23 on macOS links Homebrew llvm's own libc++**, not the older one in macOS: the llvm formula's caveat flags (`-D_LIBCPP_DISABLE_AVAILABILITY`, `-L<prefix>/lib/c++ -L<prefix>/lib/unwind -lunwind`), an rpath to `<prefix>/lib/c++` as the formula's test uses, and `CMAKE_CXX_STDLIB_MODULES_JSON` set to `<prefix>/lib/c++/libc++.modules.json` for `import std`. The prefix is the directory above the `bin/` holding the C++ compiler (the `clang++` on PATH, or `GLAZE_FIX_CXX`); with `/opt/homebrew/opt/llvm/bin` on PATH it stays valid across llvm upgrades. The environment variable `GLAZE_FIX_LLVM_PREFIX` overrides it, and the clang23 triplets pass it to the ports like `GLAZE_FIX_CXX`. The prefix is not cached and vcpkg's port configures always start fresh, so the ports follow the same inputs; in the project the resulting flags are cached like every toolchain flag, so configure with `--fresh` after changing the prefix. The configure stops if `<prefix>/lib/c++/libc++.dylib` is missing, which is also what happens first when PATH finds Apple clang. Without these flags, clang23 compiles against libc++ 23 headers and links the system library.
- **`cmake/glaze-fix-check.cmake`** runs after `project()`. It stops the configure if the compiler found is not the one the preset names; for example, Apple clang found for `clang23` is an error. It then adds the reflection flags (`-freflection`, and on p2996 also `-fexpansion-statements -fannotation-attributes`) to the project's C++ compiles only. They are kept out of `CMAKE_CXX_FLAGS` because GCC 16 rejects `-freflection` below C++26, which would break vcpkg's port builds, CMake's compiler checks in nested projects, and glaze's `find_package_test`.
- **vcpkg** runs in manifest mode:
  - `vcpkg.json` pins `builtin-baseline` and groups dependencies into features:
    - `tests` (default): asio, openssl, sqlite3
    - `fix-bench`: hffix, quickfix
    - `lookup`: qlibs mph, frozen, Intel cpp-std-extensions and cib, ConstexprCore perfect_hash
    - `orchestra`: reflect-cpp with XML, pugixml
  - To pick features, set `VCPKG_MANIFEST_FEATURES`.
  - `vcpkg-configuration.json` adds only the overlays. It has no default registry, because one would silently replace the manifest's baseline.
- **`triplets/arm64-osx-<compiler>[-asan|-tsan].cmake`** makes vcpkg build its ports with our toolchain (`VCPKG_CHAINLOAD_TOOLCHAIN_FILE`), so libraries and project share the compiler, standard library and sanitizers. A chain-loaded toolchain replaces vcpkg's own `osx.cmake`, so for port builds ours does what that file does for the processor and cross-compiling: it sets `CMAKE_SYSTEM_PROCESSOR` from the triplet and turns `CMAKE_CROSSCOMPILING` off when host and target match (on Linux it also adds `-fPIC`, as vcpkg's `linux.cmake` does).
- **`ports/`** holds overlay ports for libraries vcpkg lacks or that we patch. `qlibs-mph` carries `portable-bucket.patch`.

`VCPKG_ROOT` comes from the environment; dotfiles sets it through mise. The presets use `$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake`.

## Without vcpkg

To configure without vcpkg, for example before it is installed, override the toolchain:

```sh
cmake --preset gcc16-release -B build/nv-gcc16-release -DCMAKE_TOOLCHAIN_FILE=$PWD/cmake/toolchains/glaze-fix.cmake
```

Glaze's tests find their optional libraries with `find_package` and fall back to their own downloads, so the FIX tests build either way.

## Known test results (2026-11-09, debug presets 2026-11-10)

`cmake --workflow --preset gcc16-release` through vcpkg passes 172 of 173 tests. The FIX suites pass, and so do the SSL and websocket tests, which use vcpkg's openssl and asio. The one failure is `exceptions_test` (7 of 48 checks). It also fails with plain GCC 16 at C++23 without any of these files, so it is an existing glaze issue on GCC 16, not this setup.

The clang23 workflows each run 171 tests:

| Preset | Passed | Failures |
|---|---|---|
| clang23-debug | 171 | none |
| clang23-release | 171 | none |
| clang23-asan | 169 | `json_performance`, `json_perf_benchmark`: UBSan, test-data generator at `tests/json_performance/json_performance.cpp:667` divides by a random count that can be 0, then converts infinity to `int` |
| clang23-tsan | 169 | `asio_repe`: threads write `std::cout` at once; `http_client_test`: worker threads call `expect`, and the `ut` reporter's counters are not thread-safe |

The gcc16 workflows each run 173 tests:

| Preset | Passed | Failures |
|---|---|---|
| gcc16-debug | 172 | `exceptions_test`, as in gcc16-release |
| gcc16-asan | 172 | `exceptions_test`: SEGV inside UBSan's `vptr` check (`__ubsan::checkDynamicType` -> `__dynamic_cast`) while constructing `std::bad_variant_access`; the same test already fails on GCC 16 without sanitizers |

The clang failures above are in test code, not in the glaze headers. Two more fail only sometimes:

- `json_test_non_null` has a timing check (`tests/speculation_guard.hpp:55`) that fails when the machine is heavily loaded; it passed on rerun.
- `websocket_client_test` under clang23-tsan sometimes reports a data race in glaze's `include/glaze/net/websocket_connection.hpp`. In the workflow run, `schedule_close()` calls `shutdown()` on the socket (line 1261) while `do_close()` calls `close()` on it (line 1413). A separate rerun reported `schedule_close()` copying `socket_` (line 1258) while another thread reset it. Both come from the same gap in the source: `schedule_close()` uses `socket_` without taking `socket_op_mutex_`, which `do_close()` holds. The asan presets turn off `-fsanitize=function` for vcpkg ports only (OpenSSL calls functions through mismatched pointer types on purpose); glaze's own code keeps it.

Two GCC 16 workarounds are in the setup:

- **GCC 16's UBSan `null`, `nonnull-attribute` and `returns-nonnull-attribute` checks break constant evaluation.** With any of them, a null check on a pointer into a template parameter object is "not a constant expression", so `std::string_view::find` on a `string_literal` template argument (glaze's jmespath) does not compile. The toolchain turns those three checks off for GCC only.
- **Make-based ports read `CC` and `CXX` from the environment.** vcpkg fills them in from our toolchain only when they are unset, so a shell that exports `CC=clang` built OpenSSL with clang inside a GCC build. The triplets unset both before each port build.

Two things to know when running several presets:

- **`lib_test` shares one library across build directories.** It writes its shared library to `<source>/bin/`, not the build directory, so every preset with the same build type uses the same file (Release writes `libtest_lib.dylib`, the Debug-based presets `libtest_lib_d.dylib`). If presets build one after another, each overwrites it. Running two presets' tests at the same time, or testing one preset after building another, can load a library built by a different compiler; the symptom is `std::bad_function_call`. Rebuild the preset before testing it.
- **The clang-p2996 compiler crashes on 13 FIX test files.** It hits an internal assertion in `SemaTemplateInstantiate.cpp` ("Instantiated local in inner and outer scopes"), even at C++23 without reflection flags. The p2996 presets configure, but the FIX tests do not build until the compiler is fixed. In `p2996-debug` and `p2996-release` the same assertion also hits core glaze tests (`test_lib`, `api_test`, the `beve_test` targets and `glaze_ide`), so both builds stop before any test runs.

## reflect-cpp's C++26 backend

The gcc16 triplets turn on reflect-cpp's C++26 reflection backend (`REFLECTCPP_USE_CPP26_REFLECTION`, plus `-freflection`) for that one port, through vcpkg's per-port triplet settings (`if(PORT STREQUAL "reflectcpp")`). vcpkg's own reflectcpp port is used unchanged, so it follows the baseline. The clang triplets build the C++20 backend: clang-p2996 crashes on the C++26 one, and Homebrew clang 23 has no reflection.

## Moving the vcpkg baseline

1. Ports in `ports/` (mph, stdx, cib, Intel concurrency and senders-and-receivers, perfect_hash, useful_abstractions) are not in vcpkg and are pinned by commit. A port in `ports/` always wins over a vcpkg port of the same name, and the baseline does not move these; bump each `REF` and `SHA512` on purpose. No port in `ports/` shadows a vcpkg port today; keep it that way, or the shadowed library stops following the baseline.
2. Everything else (asio, openssl, sqlite3, frozen, fmt, boost-mp11, reflect-cpp, pugixml, hffix, quickfix) follows `builtin-baseline`.
3. Rebuild every preset: the ABI hash covers the toolchain file, so changed ports rebuild for every triplet.
