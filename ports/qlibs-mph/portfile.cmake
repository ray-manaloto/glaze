# Header-only. Pinned to qlibs/mph main at d6e79cd (2025-07-20) plus portable-bucket.patch, which
# fixes find() reporting a hit for an absent key 0 (the bucket's empty slots now never match).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO qlibs/mph
    REF d6e79cd3970f54844c790ca0fd2cf5be50024834
    SHA512 f073a162266dce99c9aa53fcd860fe879e83fb4c11823ba8a7f4ef910fa5c56493dcd2d1771e1107557014d30531579fdd8875b6b08b9f57c79d8c61ec2f03a9
    HEAD_REF main
    PATCHES portable-bucket.patch
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/mph" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

# mph ships no CMake package; provide mph::mph.
file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
if(NOT TARGET mph::mph)
  add_library(mph::mph INTERFACE IMPORTED)
  get_filename_component(_mph_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  set_target_properties(mph::mph PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_mph_prefix}/include")
  unset(_mph_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/.github/LICENSE")
