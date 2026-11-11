# vcpkg triplet: Apple silicon macOS, ports built with the glaze-fix toolchain and compiler clang23, with AddressSanitizer and UBSan (asan presets).
# vcpkg chain-loads our toolchain, so ports get the same compiler and standard library as the
# project (each port keeps its own C++ standard; see the toolchain). The libraries are built with the same sanitizers as the asan presets: ASan reports
# false container-overflow errors when a container crosses between instrumented and plain code.
# Make-based ports such as OpenSSL take CC and CXX from the environment over the compiler vcpkg
# detected from our toolchain, so a shell that exports them would build those ports with another
# compiler. Clear them for the port build (the triplet runs inside it).
unset(ENV{CC})
unset(ENV{CXX})
set(VCPKG_TARGET_ARCHITECTURE arm64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE static)
set(VCPKG_CMAKE_SYSTEM_NAME Darwin)
set(VCPKG_OSX_ARCHITECTURES arm64)
set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../cmake/toolchains/glaze-fix.cmake")
set(VCPKG_CMAKE_CONFIGURE_OPTIONS -DGLAZE_FIX_COMPILER=clang23 -DGLAZE_FIX_SANITIZER=asan -DGLAZE_FIX_HARDENING=none -DGLAZE_FIX_PORT_BUILD=ON)
# Compilers chosen outside PATH and the llvm prefix for libc++ (see the toolchain); passed through and part of the port hash.
set(VCPKG_ENV_PASSTHROUGH GLAZE_FIX_CXX GLAZE_FIX_CC GLAZE_FIX_LLVM_PREFIX)
# Rebuild every port when the toolchain file changes.
set(VCPKG_HASH_ADDITIONAL_FILES "${CMAKE_CURRENT_LIST_DIR}/../cmake/toolchains/glaze-fix.cmake")
