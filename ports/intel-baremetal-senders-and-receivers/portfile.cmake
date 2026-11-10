# Header-only. Upstream's own CMake fetches its dependencies with CPM/FetchContent, so this port
# installs the headers and writes a small CMake package of its own (intel::async).
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO intel/cpp-baremetal-senders-and-receivers
    REF 3e3c8aaa1b0aa8035453050997ae25ab08d936f1
    SHA512 96211e240932ffb74c671de3e55bdf7e3327010848732c4dbb45287f5901d4d6ca72448d6651df796ba2d3da31ebb38643f456486a6400e68acbf8200887e53d
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release)  # headers only
file(INSTALL "${SOURCE_PATH}/include/async" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/${PORT}-config.cmake" [[
include(CMakeFindDependencyMacro)
find_dependency(intel-cpp-std-extensions CONFIG)
find_dependency(boost_mp11 CONFIG)
find_dependency(intel-baremetal-concurrency CONFIG)
if(NOT TARGET intel::async)
  get_filename_component(_prefix "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
  add_library(intel::async INTERFACE IMPORTED)
  set_target_properties(intel::async PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${_prefix}/include" INTERFACE_LINK_LIBRARIES "intel::stdx;Boost::mp11;intel::concurrency")
  unset(_prefix)
endif()
]])
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")
