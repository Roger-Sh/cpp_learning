CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(CPP_BASIC_TEST)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


INCLUDE_DIRECTORIES(include)

ADD_EXECUTABLE(union_test src/union_test.cpp )
ADD_EXECUTABLE(struct_copy_test src/struct_copy_test.cpp)
ADD_EXECUTABLE(cpp_input_test src/cpp_input_test.cpp)
ADD_EXECUTABLE(cart_shuffle src/cart_shuffle.cpp)
ADD_EXECUTABLE(class_in_class src/class_in_class.cpp)
