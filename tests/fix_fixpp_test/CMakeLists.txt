project(fix_fixpp_test)

## Tests ported from a third-party FIX library; see LICENSE-* in this directory and
## docs/fix/sessions/fix-tests-hffix-fixpp.md for provenance.

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp fix_fixpp_more.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE FIX_TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data" GLZ_FIX_HAS_STRUCT_MAPPING)

target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_common)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_code_coverage(${PROJECT_NAME} AUTO ALL)
