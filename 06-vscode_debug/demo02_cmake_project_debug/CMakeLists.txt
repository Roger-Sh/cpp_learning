cmake_minimum_required(VERSION 2.6)
project(vscode_cmake_debug_demo)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") # set debug mode

# debug模式
set(CMAKE_BUILD_TYPE "RelWithDebInfo")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
set(SRC_LIST src/main.cpp)
add_executable(main ${SRC_LIST})