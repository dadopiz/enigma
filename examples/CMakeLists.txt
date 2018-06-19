set(TARGET_NAME enigma_example)

file(GLOB EXAMPLE_SOURCES *.cpp)

add_executable(${TARGET_NAME} ${EXAMPLE_SOURCES})

target_link_libraries(${TARGET_NAME} enigmaStatic)

include_directories(${CMAKE_SOURCE_DIR}/lib/include)
