cmake_minimum_required(VERSION 3.0.0)
project(translate)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu99  -Wall -g -O0 -lm)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_subdirectory(src)
add_subdirectory(test)
