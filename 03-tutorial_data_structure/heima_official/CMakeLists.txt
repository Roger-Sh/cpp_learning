CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(data_structure_heima)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

INCLUDE_DIRECTORIES(include)

# test01_dynamic_array
ADD_EXECUTABLE(test01_dynamic_array 
    src/test01_dynamic_array.cpp 
    src/DynamicArray.cpp)

# test02_linklist
ADD_EXECUTABLE(test02_linklist 
    src/test02_linklist.cpp 
    src/LinkList.cpp)

# test03_linklist_enterprise
ADD_EXECUTABLE(test03_linklist_enterprise
    src/test03_linklist_enterprise.cpp 
    src/LinkList_Enterprise.cpp)

# test04_linklist_circle
ADD_EXECUTABLE(test04_linklist_circle
    src/test04_linklist_circle.cpp 
    src/LinkList_Circle.cpp)

# test05_linklist_double
ADD_EXECUTABLE(test05_linklist_double
    src/test05_linklist_double.cpp 
    src/LinkList_Double.cpp)

# test06_stackseq
ADD_EXECUTABLE(test06_stackseq
    src/test06_stackseq.cpp 
    src/StackSeq.cpp)

# test07_stacklink
ADD_EXECUTABLE(test07_stacklink
    src/test07_stacklink.cpp 
    src/StackLink.cpp)

# test08_queueseq
ADD_EXECUTABLE(test08_queueseq
    src/test08_queueseq.cpp 
    src/QueueSeq.cpp)

# test09_queuelink
ADD_EXECUTABLE(test09_queuelink
    src/test09_queuelink.cpp 
    src/QueueLink.cpp)

# test10_binaryTree
ADD_EXECUTABLE(test10_binarytree
    src/test10_binarytree
    src/BinaryTree)