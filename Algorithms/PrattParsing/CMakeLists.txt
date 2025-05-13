cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(pratt_parsing)
add_executable(pratt_parsing main.cpp)

add_library(lexer ./lexer/lexer.cpp ./lexer/lexer.hpp)
add_library(expression ./expression/expression.cpp ./expression/expression.hpp)

target_link_libraries(pratt_parsing lexer expression)
