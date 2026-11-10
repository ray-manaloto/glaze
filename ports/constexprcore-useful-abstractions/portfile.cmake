# Header-only. Upstream's own CMake fetches its dependencies with CPM/FetchContent, so this port
# installs the headers and writes a small CMake package of its own (ConstexprCore::useful_abstractions).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO ConstexprCore/useful_abstractions
    REF cb4d3283a3a2e788becccb2946182def8922fe9c
    SHA512 00a271cb7daa7a2bf755e9006f8fdc03823764c91e3bda696e7a52d338edd51b8e2b3b573cf8f0f6afc19aef5295fa0dd5bbf67248b242286e7a675b3d8c7ad5
    HEAD_REF master
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/include/ConstexprCore" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
include(CMakeFindDependencyMacro)
if(NOT TARGET ConstexprCore::useful_abstractions)
  get_filename_component(_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  add_library(ConstexprCore::useful_abstractions INTERFACE IMPORTED)
  set_target_properties(ConstexprCore::useful_abstractions PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_prefix}/include")
  unset(_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
