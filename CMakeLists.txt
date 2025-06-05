cmake_minimum_required(VERSION 3.22)
project(library_management)

file(GLOB_RECURSE SOURCES src/*.cpp)
include_directories(
  include
  lib/logging/include
)

add_subdirectory(lib/logging)

add_executable(library_management ${SOURCES})
target_link_libraries(library_management logging uuid)
