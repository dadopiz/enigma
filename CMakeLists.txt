cmake_minimum_required(VERSION 3.2.0)

project(enigma VERSION 1.0.0 LANGUAGES CXX)

option(ENABLE_COVERAGE "Enable coverage" OFF)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    if (ENABLE_COVERAGE)
        message(STATUS "Enabling coverage")
        set(CMAKE_BUILD_TYPE Debug)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
    endif()
endif()

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(examples)
add_subdirectory(docs)
