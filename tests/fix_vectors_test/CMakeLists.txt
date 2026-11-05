project(fix_vectors_test)

## Data-driven FIX tag=value vectors ported from other open-source FIX parsers (see data/SOURCES.md)
## and written afresh from the FIX specification. Runs every data/*.fixv file through the
## glz::fix scanner, validator, framer and checksum.

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_common)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    GLZ_FIX_VECTORS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data"
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_code_coverage(${PROJECT_NAME} AUTO ALL)
