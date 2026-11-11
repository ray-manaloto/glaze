# Runs after project() through CMAKE_PROJECT_INCLUDE (set by the glaze-fix presets).
# Refuses a configure whose compiler is not the one GLAZE_FIX_COMPILER names, so a preset can never
# silently build with whatever clang++ or g++ happens to be first on PATH. Then adds the reflection
# flags for this project's C++ (the toolchain keeps them out of CMAKE_CXX_FLAGS on purpose).

include_guard(GLOBAL)

if(NOT DEFINED GLAZE_FIX_COMPILER OR NOT CMAKE_CXX_COMPILER_LOADED)
  return()
endif()

set(_id "${CMAKE_CXX_COMPILER_ID}")
set(_ver "${CMAKE_CXX_COMPILER_VERSION}")
set(_path "${CMAKE_CXX_COMPILER}")  # full path: a p2996 build may install a plain clang++ under a p2996 dir
set(_ok FALSE)
if(GLAZE_FIX_COMPILER STREQUAL "gcc16")
  if(_id STREQUAL "GNU" AND _ver VERSION_GREATER_EQUAL 16 AND _ver VERSION_LESS 17)
    set(_ok TRUE)
  endif()
  set(_want "GCC 16")
elseif(GLAZE_FIX_COMPILER STREQUAL "clang23")
  if(_id STREQUAL "Clang" AND _ver VERSION_GREATER_EQUAL 23 AND _ver VERSION_LESS 24 AND NOT _path MATCHES "p2996")
    set(_ok TRUE)
  endif()
  set(_want "LLVM clang 23 (not Apple clang, not clang-p2996)")
elseif(GLAZE_FIX_COMPILER STREQUAL "p2996")
  if(_id STREQUAL "Clang" AND _path MATCHES "p2996")
    set(_ok TRUE)
  endif()
  set(_want "clang-p2996 (bloomberg/clang-p2996)")
endif()

if(NOT _ok)
  message(FATAL_ERROR
    "GLAZE_FIX_COMPILER=${GLAZE_FIX_COMPILER} wants ${_want}, but CMake found "
    "${_id} ${_ver} at ${CMAKE_CXX_COMPILER}. Fix PATH, or set GLAZE_FIX_CXX and GLAZE_FIX_CC (see docs/fix/build.md).")
endif()

# Reflection flags (set by the toolchain in GLAZE_FIX_REFLECTION_FLAGS) for this project's C++ only.
foreach(_flag IN LISTS GLAZE_FIX_REFLECTION_FLAGS)  # one generator expression per flag
  add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${_flag}>")
endforeach()
message(STATUS "glaze-fix: ${GLAZE_FIX_COMPILER} = ${_id} ${_ver} (${CMAKE_CXX_COMPILER}), "
               "sanitizer ${GLAZE_FIX_SANITIZER}, hardening ${GLAZE_FIX_HARDENING}, reflection [${GLAZE_FIX_REFLECTION_FLAGS}]")
