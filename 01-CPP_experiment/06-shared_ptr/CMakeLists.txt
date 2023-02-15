CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(test_shared_ptr)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)


INCLUDE_DIRECTORIES(
include
)

# multithread_demo
ADD_EXECUTABLE(test_shared_ptr src/test_shared_ptr.cpp)
# TARGET_LINK_LIBRARIES(test_shared_ptr)
