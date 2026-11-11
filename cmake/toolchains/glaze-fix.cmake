# Toolchain for the glaze-fix presets (cmake/presets/glaze-fix.json) and the vcpkg triplets in triplets/.
#
# One file for every compiler. The preset (or the triplet, for vcpkg's own port builds) picks the
# compiler and the variants through cache variables:
#   GLAZE_FIX_COMPILER   gcc16 | clang23 | p2996
#   GLAZE_FIX_SANITIZER  none | asan | tsan   (asan = AddressSanitizer + UndefinedBehaviorSanitizer;
#                        tsan = ThreadSanitizer; GCC 16 supports it on Linux only, as it has no
#                        TSan runtime on macOS)
#   GLAZE_FIX_HARDENING  none | fast | extensive | debug
#                        libc++ (_LIBCPP_HARDENING_MODE) on the clang compilers; on GCC anything but
#                        none turns on _GLIBCXX_ASSERTIONS. Set it explicitly: the clang-p2996 libc++
#                        defaults to extensive and Homebrew's to none, which skews any comparison.
#
# Compilers are bare names found on PATH (mise and Homebrew provide them); no machine path is written
# here. To use a compiler outside PATH, set the environment variables GLAZE_FIX_CXX and GLAZE_FIX_CC
# (for example in a gitignored CMakeUserPresets.json). They reach both this project and vcpkg's port
# builds, because the triplets pass them through (VCPKG_ENV_PASSTHROUGH). cmake/glaze-fix-check.cmake
# then refuses a compiler that is not the one GLAZE_FIX_COMPILER names.

include_guard(GLOBAL)

set(GLAZE_FIX_COMPILER "gcc16" CACHE STRING "Compiler: gcc16, clang23 or p2996")
set(GLAZE_FIX_SANITIZER "none" CACHE STRING "Sanitizer: none, asan or tsan")
set(GLAZE_FIX_HARDENING "none" CACHE STRING "Standard library hardening: none, fast, extensive or debug")
set_property(CACHE GLAZE_FIX_COMPILER PROPERTY STRINGS gcc16 clang23 p2996)
set_property(CACHE GLAZE_FIX_SANITIZER PROPERTY STRINGS none asan tsan)
set_property(CACHE GLAZE_FIX_HARDENING PROPERTY STRINGS none fast extensive debug)

# try_compile projects re-read this file; pass the choices through to them.
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES GLAZE_FIX_COMPILER GLAZE_FIX_SANITIZER GLAZE_FIX_HARDENING GLAZE_FIX_PORT_BUILD GLAZE_FIX_EXTRA_CXX_FLAGS)

set(_glaze_fix_flags "")        # C and C++
set(_glaze_fix_cxx_only "")     # C++ only
set(_glaze_fix_link "")
set(_glaze_fix_reflection "")
if(GLAZE_FIX_COMPILER STREQUAL "gcc16")
  set(_glaze_fix_cxx g++-16)
  set(_glaze_fix_c gcc-16)
  set(_glaze_fix_reflection -freflection)
  set(_glaze_fix_libcxx OFF)
elseif(GLAZE_FIX_COMPILER STREQUAL "clang23")
  set(_glaze_fix_cxx clang++)
  set(_glaze_fix_c clang)
  set(_glaze_fix_libcxx ON)
elseif(GLAZE_FIX_COMPILER STREQUAL "p2996")
  set(_glaze_fix_cxx clang++-p2996)
  set(_glaze_fix_c clang-p2996)
  set(_glaze_fix_reflection -freflection -fexpansion-statements -fannotation-attributes)
  set(_glaze_fix_libcxx ON)
else()
  message(FATAL_ERROR "GLAZE_FIX_COMPILER must be gcc16, clang23 or p2996, not '${GLAZE_FIX_COMPILER}'")
endif()

if(DEFINED ENV{GLAZE_FIX_CXX} AND NOT "$ENV{GLAZE_FIX_CXX}" STREQUAL "")
  set(_glaze_fix_cxx "$ENV{GLAZE_FIX_CXX}")
endif()
if(DEFINED ENV{GLAZE_FIX_CC} AND NOT "$ENV{GLAZE_FIX_CC}" STREQUAL "")
  set(_glaze_fix_c "$ENV{GLAZE_FIX_CC}")
endif()
if(NOT CMAKE_CXX_COMPILER)
  set(CMAKE_CXX_COMPILER "${_glaze_fix_cxx}")
endif()
if(NOT CMAKE_C_COMPILER)
  set(CMAKE_C_COMPILER "${_glaze_fix_c}")
endif()

# C++26 for the project. vcpkg port builds (the triplets pass GLAZE_FIX_PORT_BUILD=ON) keep each port's
# own standard: forcing C++26 on them turns on C++ module builds in some (fmt 12 then fails to build
# its module with libc++ 23). A port that needs C++26, such as reflect-cpp's reflection backend, asks
# for it itself.
if(NOT DEFINED CMAKE_CXX_STANDARD AND NOT GLAZE_FIX_PORT_BUILD)
  set(CMAKE_CXX_STANDARD 26)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# Reflection flags are not set here. GCC 16 refuses -freflection below -std=c++26, so a flag in
# CMAKE_CXX_FLAGS breaks every compile that is not C++26: vcpkg ports, CMake's compiler checks in
# nested projects, and glaze's find_package_test (which forwards CMAKE_CXX_FLAGS). The project adds
# them in cmake/glaze-fix-check.cmake instead, and a port that needs them asks through
# GLAZE_FIX_EXTRA_CXX_FLAGS (the gcc16 triplets do this for reflectcpp).
set(GLAZE_FIX_REFLECTION_FLAGS "${_glaze_fix_reflection}")
# Extra C++ flags a port asks for (reflectcpp[cpp26] passes -freflection).
if(GLAZE_FIX_EXTRA_CXX_FLAGS)
  list(APPEND _glaze_fix_cxx_only ${GLAZE_FIX_EXTRA_CXX_FLAGS})
endif()

# vcpkg port builds. vcpkg passes CMAKE_SYSTEM_NAME to every CMake port configure when the triplet sets
# VCPKG_CMAKE_SYSTEM_NAME (all of ours do), which on its own makes CMake treat
# the build as cross-compiling (try_run refused, CMAKE_SYSTEM_PROCESSOR empty). vcpkg's own linux.cmake
# and osx.cmake undo that, and a chain-loaded toolchain replaces them, so do the same here: set the
# processor from the triplet's architecture and turn cross-compiling off when host and target match.
# On Linux also add -fPIC, as linux.cmake does, so static port libraries can be linked into shared
# libraries and PIE executables (macOS code is position-independent by default).
if(GLAZE_FIX_PORT_BUILD AND DEFINED VCPKG_TARGET_ARCHITECTURE)
  if(NOT DEFINED CMAKE_SYSTEM_PROCESSOR)
    if(VCPKG_TARGET_ARCHITECTURE STREQUAL "x64")
      set(CMAKE_SYSTEM_PROCESSOR x86_64 CACHE STRING "")
    elseif(VCPKG_TARGET_ARCHITECTURE STREQUAL "arm64" AND CMAKE_SYSTEM_NAME STREQUAL "Darwin")
      set(CMAKE_SYSTEM_PROCESSOR arm64 CACHE STRING "")
    elseif(VCPKG_TARGET_ARCHITECTURE STREQUAL "arm64")
      set(CMAKE_SYSTEM_PROCESSOR aarch64 CACHE STRING "")
    endif()
  endif()
  if(CMAKE_SYSTEM_NAME STREQUAL CMAKE_HOST_SYSTEM_NAME AND CMAKE_SYSTEM_PROCESSOR STREQUAL CMAKE_HOST_SYSTEM_PROCESSOR)
    set(CMAKE_CROSSCOMPILING OFF CACHE BOOL "")
  endif()
  if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    list(APPEND _glaze_fix_flags -fPIC)
  endif()
endif()

if(_glaze_fix_libcxx)
  list(APPEND _glaze_fix_cxx_only -stdlib=libc++)
  list(APPEND _glaze_fix_link -stdlib=libc++)
endif()

# Homebrew's llvm on macOS: link the libc++ shipped with the llvm package, not the system one, as the
# llvm formula's caveat and test do. Without this, clang23 compiles against the package's libc++ 23
# headers and links the older macOS libc++. The package prefix is the directory above the bin/ that
# holds the C++ compiler (the clang++ on PATH, or GLAZE_FIX_CXX). With /opt/homebrew/opt/llvm/bin on
# PATH that is /opt/homebrew/opt/llvm, which stays valid across llvm upgrades. To use another prefix,
# set the environment variable GLAZE_FIX_LLVM_PREFIX. The prefix is not cached, and vcpkg's port
# builds (the clang23 triplets pass GLAZE_FIX_LLVM_PREFIX and GLAZE_FIX_CXX through) always configure
# fresh, so they follow the same inputs. The project caches the resulting flags like every *_INIT
# flag here, so a changed prefix needs a fresh configure. -D_LIBCPP_DISABLE_AVAILABILITY lets code use libc++
# features newer than the macOS deployment target. CMAKE_CXX_STDLIB_MODULES_JSON is for import std.
if(GLAZE_FIX_COMPILER STREQUAL "clang23" AND CMAKE_HOST_APPLE)
  if(DEFINED ENV{GLAZE_FIX_LLVM_PREFIX} AND NOT "$ENV{GLAZE_FIX_LLVM_PREFIX}" STREQUAL "")
    set(_glaze_fix_llvm "$ENV{GLAZE_FIX_LLVM_PREFIX}")
    set(_glaze_fix_where "prefix from GLAZE_FIX_LLVM_PREFIX")
  else()
    set(_glaze_fix_llvm "")
    set(_glaze_fix_where "compiler not found")
    find_program(_glaze_fix_cxx_path NAMES "${CMAKE_CXX_COMPILER}" NO_CACHE)
    if(_glaze_fix_cxx_path)
      set(_glaze_fix_where "compiler found at ${_glaze_fix_cxx_path}")
      cmake_path(GET _glaze_fix_cxx_path PARENT_PATH _glaze_fix_bin)
      cmake_path(GET _glaze_fix_bin PARENT_PATH _glaze_fix_llvm)
    endif()
  endif()
  if(NOT EXISTS "${_glaze_fix_llvm}/lib/c++/libc++.dylib")
    message(FATAL_ERROR "clang23 on macOS links the libc++ inside Homebrew's llvm, but '${_glaze_fix_llvm}/lib/c++/libc++.dylib' does not exist (compiler '${CMAKE_CXX_COMPILER}', ${_glaze_fix_where}). If that is Apple clang or a wrapper, fix PATH or set GLAZE_FIX_CXX to Homebrew's clang++; if it is another LLVM install, set the environment variable GLAZE_FIX_LLVM_PREFIX to its prefix (brew --prefix llvm).")
  endif()
  list(APPEND _glaze_fix_cxx_only -D_LIBCPP_DISABLE_AVAILABILITY)
  list(APPEND _glaze_fix_link "-L${_glaze_fix_llvm}/lib/c++" "-Wl,-rpath,${_glaze_fix_llvm}/lib/c++")
  # Not under AddressSanitizer: with the package's libunwind linked in, an exception unwinding through
  # ASan-instrumented frames aborts in ASan's own check (unw_init_local's memcpy, asan_thread.cpp:370;
  # glaze's threading_test). Without -lunwind those binaries use the macOS unwinder and pass.
  if(NOT GLAZE_FIX_SANITIZER STREQUAL "asan")
    list(APPEND _glaze_fix_link "-L${_glaze_fix_llvm}/lib/unwind" -lunwind)
  endif()
  set(CMAKE_CXX_STDLIB_MODULES_JSON "${_glaze_fix_llvm}/lib/c++/libc++.modules.json")
endif()

if(GLAZE_FIX_HARDENING STREQUAL "none")
  if(_glaze_fix_libcxx)
    list(APPEND _glaze_fix_cxx_only -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE)
  endif()
elseif(GLAZE_FIX_HARDENING MATCHES "^(fast|extensive|debug)$")
  if(_glaze_fix_libcxx)
    string(TOUPPER "${GLAZE_FIX_HARDENING}" _glaze_fix_mode)
    list(APPEND _glaze_fix_cxx_only -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_${_glaze_fix_mode})
  else()
    list(APPEND _glaze_fix_cxx_only -D_GLIBCXX_ASSERTIONS)
  endif()
else()
  message(FATAL_ERROR "GLAZE_FIX_HARDENING must be none, fast, extensive or debug, not '${GLAZE_FIX_HARDENING}'")
endif()

if(GLAZE_FIX_SANITIZER STREQUAL "asan")
  list(APPEND _glaze_fix_flags -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=undefined)
  list(APPEND _glaze_fix_link -fsanitize=address,undefined)
  # Third-party C ports (OpenSSL: pem_info.c, sparse_array.c) call functions through mismatched
  # pointer types on purpose; clang's -fsanitize=function aborts on that. Our own code keeps it.
  if(GLAZE_FIX_PORT_BUILD AND NOT GLAZE_FIX_COMPILER STREQUAL "gcc16")
    list(APPEND _glaze_fix_flags -fno-sanitize=function)
  endif()
  # GCC 16 bug: with -fsanitize=null, nonnull-attribute or returns-nonnull-attribute, a null check on a
  # pointer into a template parameter object is "not a constant expression", so valid constexpr code
  # (std::string_view::find on a string_literal NTTP, as in glaze's jmespath) fails to compile.
  if(GLAZE_FIX_COMPILER STREQUAL "gcc16")
    list(APPEND _glaze_fix_flags -fno-sanitize=null,nonnull-attribute,returns-nonnull-attribute)
  endif()
elseif(GLAZE_FIX_SANITIZER STREQUAL "tsan")
  # GCC's TSan runtime exists on Linux, not on macOS.
  if(GLAZE_FIX_COMPILER STREQUAL "gcc16" AND CMAKE_HOST_APPLE)
    message(FATAL_ERROR "GCC 16 on macOS has no ThreadSanitizer runtime (___tsan_* undefined at link); use clang23 or p2996")
  endif()
  list(APPEND _glaze_fix_flags -fsanitize=thread -fno-omit-frame-pointer)
  list(APPEND _glaze_fix_link -fsanitize=thread)
elseif(NOT GLAZE_FIX_SANITIZER STREQUAL "none")
  message(FATAL_ERROR "GLAZE_FIX_SANITIZER must be none, asan or tsan, not '${GLAZE_FIX_SANITIZER}'")
endif()

list(JOIN _glaze_fix_flags " " _glaze_fix_common)
list(JOIN _glaze_fix_cxx_only " " _glaze_fix_cxx_extra)
list(JOIN _glaze_fix_link " " _glaze_fix_link_flags)
string(STRIP "${_glaze_fix_common} ${_glaze_fix_cxx_extra}" CMAKE_CXX_FLAGS_INIT)
set(CMAKE_C_FLAGS_INIT "${_glaze_fix_common}")
foreach(_kind EXE SHARED MODULE)
  set(CMAKE_${_kind}_LINKER_FLAGS_INIT "${_glaze_fix_link_flags}")
endforeach()
