CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(multithread_demo)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(
include
)

# multithread_demo
ADD_EXECUTABLE(multithread_demo src/multithread_demo.cpp)
TARGET_LINK_LIBRARIES(multithread_demo -lpthread)

# multithread_demo
ADD_EXECUTABLE(sum_array_multithread src/sum_array_multithread.cpp)
TARGET_LINK_LIBRARIES(sum_array_multithread -lpthread)

# multithread_demo
ADD_EXECUTABLE(mutex_multithread src/mutex_multithread.cpp)
TARGET_LINK_LIBRARIES(mutex_multithread -lpthread)