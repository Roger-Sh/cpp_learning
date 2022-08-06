cmake_minimum_required(VERSION 3.0.0)
project(workerManagerSys VERSION 0.1.0)

include(CTest)
enable_testing()

# include 
include_directories(include)

# src SRC_LIST
aux_source_directory(src SRC_LIST)

# exe
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp ${SRC_LIST})
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


