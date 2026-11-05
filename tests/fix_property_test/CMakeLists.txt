project(fix_property_test)

## FIX tag=value format: property tests (round trip, corruption, truncation) and one test per
## rule of docs/fix/conformance.md.

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_common)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_code_coverage(${PROJECT_NAME} AUTO ALL)
