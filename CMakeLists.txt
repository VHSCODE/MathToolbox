cmake_minimum_required(VERSION 3.5)

project(MathToolbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCE_FILES "src/main.cpp" "src/math_parser.cpp" "src/Calculator.cpp" "src/BinaryTree.cpp")
set(INCLUDE_DIRS "include/")

add_executable(MathToolbox ${SOURCE_FILES})
target_include_directories(MathToolbox PRIVATE ${INCLUDE_DIRS})




