# Header-only. Upstream's own CMake fetches its dependencies with CPM/FetchContent, so this port
# installs the headers and writes a small CMake package of its own (intel::concurrency).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO intel/cpp-baremetal-concurrency
    REF b8a486a3bd1d166128ebbdb8e88f7a43443a5e83
    SHA512 6a8dadb52146550699af105c711b0c1c51817479138a7e1d0a3554a2803729661ab171adebaa3965e2576e3a6bc3483924f276d703254544c64564f980dd8c52
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/include/conc" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
include(CMakeFindDependencyMacro)
if(NOT TARGET intel::concurrency)
  get_filename_component(_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  add_library(intel::concurrency INTERFACE IMPORTED)
  set_target_properties(intel::concurrency PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_prefix}/include")
  unset(_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
