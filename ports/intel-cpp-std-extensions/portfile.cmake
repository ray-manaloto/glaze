# Header-only. Upstream's own CMake fetches its dependencies with CPM/FetchContent, so this port
# installs the headers and writes a small CMake package of its own (intel::stdx).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO intel/cpp-std-extensions
    REF d6e517f86d5d4997c3c4fe78a29f41433cfb5c6d
    SHA512 4a907dbf23a72b4c930b4187f3d5653c584e4d72bd1d382bfcfb6046cffd848361866819af511d3c64f596210270c48e4c9cf994d0ea82b334dfad2b905b3324
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/include/stdx" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
include(CMakeFindDependencyMacro)
find_dependency(boost_mp11 CONFIG)
find_dependency(fmt CONFIG)
find_dependency(intel-baremetal-concurrency CONFIG)
if(NOT TARGET intel::stdx)
  get_filename_component(_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  add_library(intel::stdx INTERFACE IMPORTED)
  set_target_properties(intel::stdx PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_prefix}/include" INTERFACE_LINK_LIBRARIES "Boost::mp11;fmt::fmt;intel::concurrency")
  unset(_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
