# glaze-fix consolidated test suite: one executable per source group.
# Each source file records its upstream origin in tests/fix_suite/<group>/SOURCES.md.
project(fix_suite)

file(GLOB_RECURSE FIX_SUITE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*/fix_suite_*.cpp)

foreach(src ${FIX_SUITE_SOURCES})
  get_filename_component(name ${src} NAME_WE)
  get_filename_component(dir ${src} DIRECTORY)
  file(GLOB parts CONFIGURE_DEPENDS ${dir}/*.part.cpp)
  add_executable(${name} ${src} ${parts})
  target_link_libraries(${name} PRIVATE glz_test_common)
  target_compile_options(${name} PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-Werror>)
  target_compile_definitions(${name} PRIVATE GLZ_FIX_VECTORS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/vectors/data"
    FIX_TEST_DATA_DIR="${dir}/data" GLZ_FIX_HAS_STRUCT_MAPPING)
  add_test(NAME ${name} COMMAND ${name})
  set_tests_properties(${name} PROPERTIES LABELS fix_suite)
endforeach()
