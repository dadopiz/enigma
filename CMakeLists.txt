cmake_minimum_required(VERSION 3.2.0)

project(enigma)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(examples)
