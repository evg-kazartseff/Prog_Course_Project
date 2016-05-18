cmake_minimum_required(VERSION 2.8.0)
project(translate)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -g -O0)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_subdirectory(src)
add_subdirectory(test)
