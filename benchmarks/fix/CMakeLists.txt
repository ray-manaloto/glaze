# Standalone, opt-in benchmark for glaze-fix. Not part of the main glaze build.
#   cmake -S benchmarks/fix -B build-fix-bench -DCMAKE_BUILD_TYPE=Release && cmake --build build-fix-bench
cmake_minimum_required(VERSION 3.25)
project(glaze_fix_bench LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
# Plain -O3, no -march=native, so the binary and results are portable.
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

if(POLICY CMP0169)
  cmake_policy(SET CMP0169 OLD) # header-only dep: populate only, do not add_subdirectory
endif()
include(FetchContent)
# hffix: header-only, BSD-2-Clause. Pinned commit.
FetchContent_Declare(hffix
  GIT_REPOSITORY https://github.com/jamesdbrock/hffix.git
  GIT_TAG 797ce7db0bd1c240acee88fad297b69bec428778)
FetchContent_GetProperties(hffix)
if(NOT hffix_POPULATED)
  FetchContent_Populate(hffix)
endif()

add_executable(fix_bench fix_bench.cpp)
target_include_directories(fix_bench PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include ${hffix_SOURCE_DIR}/include)
target_compile_definitions(fix_bench PRIVATE FIX_CORPUS="${CMAKE_CURRENT_SOURCE_DIR}/data/corpus.fix")

# Optional: QuickFIX C++ (QuickFIX Software License, BSD-style). Off by default; ~1 min extra build.
option(FIX_BENCH_QUICKFIX "Also benchmark QuickFIX C++" OFF)
if(FIX_BENCH_QUICKFIX)
  FetchContent_Declare(quickfix
    GIT_REPOSITORY https://github.com/quickfix/quickfix.git
    GIT_TAG 386ce46e917ae494ab6e90b1be90fd421cdbe3f9)
  FetchContent_GetProperties(quickfix)
  if(NOT quickfix_POPULATED)
    FetchContent_Populate(quickfix)
  endif()
  set(QUICKFIX_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(QUICKFIX_TESTS OFF CACHE BOOL "" FORCE)
  set(QUICKFIX_SHARED_LIBS OFF CACHE BOOL "" FORCE)
  set(QUICKFIX_LIB_OUTPUT_DIR "${CMAKE_BINARY_DIR}/quickfix-lib" CACHE PATH "" FORCE)
  add_subdirectory(${quickfix_SOURCE_DIR} ${quickfix_BINARY_DIR} EXCLUDE_FROM_ALL)
  target_link_libraries(fix_bench PRIVATE quickfix)
  target_include_directories(fix_bench PRIVATE ${quickfix_SOURCE_DIR}/src/C++ ${quickfix_SOURCE_DIR}/include)
  target_compile_definitions(fix_bench PRIVATE FIX_BENCH_QUICKFIX
    FIX44_XML="${quickfix_SOURCE_DIR}/spec/FIX44.xml")
endif()
