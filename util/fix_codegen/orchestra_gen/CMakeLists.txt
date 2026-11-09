# Orchestra -> glaze-fix 3-part struct generator (spike).
# Reads FIX Orchestra XML with reflect-cpp's XML serialization (pugixml underneath), built with
# reflect-cpp's C++26 static-reflection backend (REFLECTCPP_USE_CPP26_REFLECTION) on GCC 16.2.
#
#   cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=g++-16
#   cmake --build build
cmake_minimum_required(VERSION 3.30)
project(orchestra_gen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16.2)
  message(FATAL_ERROR "orchestra_gen needs GCC >= 16.2: reflect-cpp's C++26 backend crashes clang-p2996 "
                      "and upstream Clang has no reflection yet.")
endif()

include(FetchContent)
FetchContent_Declare(pugixml
  GIT_REPOSITORY https://github.com/zeux/pugixml.git
  GIT_TAG        c8033ce9d039e7f9d134877c363397b3cfe20816  # v1.16
  GIT_SHALLOW    FALSE)
FetchContent_MakeAvailable(pugixml)

set(REFLECTCPP_XML ON CACHE BOOL "" FORCE)
set(REFLECTCPP_USE_CPP26_REFLECTION ON CACHE BOOL "" FORCE)   # C++26 static reflection backend
set(REFLECTCPP_USE_STD_EXPECTED ON CACHE BOOL "" FORCE)       # rfl::Result is std::expected
set(REFLECTCPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_Declare(reflectcpp
  GIT_REPOSITORY https://github.com/munich-data-engineering/reflect-cpp.git
  GIT_TAG        e0ee3f6f2f8a4d54ce4e2e34bb9d23140c926709  # v0.27.1
  GIT_SHALLOW    FALSE)
FetchContent_MakeAvailable(reflectcpp)

add_executable(orchestra_gen src/main.cpp src/orchestra.cpp src/model.cpp src/emit.cpp)
target_include_directories(orchestra_gen PRIVATE src)
target_link_libraries(orchestra_gen PRIVATE reflectcpp pugixml::pugixml)
# -freflection: GCC's P2996 switch, needed by reflect-cpp's C++26 backend.
target_compile_options(orchestra_gen PRIVATE -freflection -Wall -Wextra -Wno-missing-field-initializers)
target_compile_options(reflectcpp PRIVATE -freflection)
