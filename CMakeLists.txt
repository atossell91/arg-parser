cmake_minimum_required(VERSION 3.11.2)

project(ArgParser)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC ${CMAKE_SOURCE_DIR}/src)

set(SRC_FILES
    ${SRC}/main.cpp
    ${SRC}/ArgParser.cpp)

set (CONTENT ${CMAKE_BINARY_DIR})
message("Build Path: ${CONTENT}")

add_executable(arg-parser ${SRC_FILES})

add_library(arg-parser-dev SHARED ${SRC_FILES})
