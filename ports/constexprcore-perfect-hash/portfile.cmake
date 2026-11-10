# Header-only. Upstream's own CMake fetches its dependencies with CPM/FetchContent, so this port
# installs the headers and writes a small CMake package of its own (ConstexprCore::perfect_hash).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO ConstexprCore/perfect_hash
    REF 39355d178ebfa635ec165d6cd4684d05aec5c965
    SHA512 02227f5a2a0168cd3ee2a465024dfb646acb3a71ed7df24e99e8657e8d5542a7771b47bbea52312692c8f0b9b76b3db4c6afdb050af7378a80b7b3a1aafe4a81
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/include/ConstexprCore" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
include(CMakeFindDependencyMacro)
find_dependency(constexprcore-useful-abstractions CONFIG)
if(NOT TARGET ConstexprCore::perfect_hash)
  get_filename_component(_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  add_library(ConstexprCore::perfect_hash INTERFACE IMPORTED)
  set_target_properties(ConstexprCore::perfect_hash PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_prefix}/include" INTERFACE_LINK_LIBRARIES "ConstexprCore::useful_abstractions")
  unset(_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
