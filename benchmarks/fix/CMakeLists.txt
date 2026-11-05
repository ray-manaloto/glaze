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
