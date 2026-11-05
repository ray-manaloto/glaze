project(fix_dictionary_test)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_common)

# fix44::NewOrderSingle has 156 fields, so its glz::meta tuple has 312 elements. Clang's default
# -fbracket-depth of 256 rejects the fold expressions over it; GCC has no such limit.
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
   target_compile_options(${PROJECT_NAME} PRIVATE -fbracket-depth=1024)
endif()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_code_coverage(${PROJECT_NAME} AUTO ALL)
