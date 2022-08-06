cmake_minimum_required(VERSION 3.0)
project(eigen-example)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(/usr/include/eigen3)

add_executable (01-eigen-example src/01-eigen-example.cpp)
target_link_libraries (01-eigen-example)