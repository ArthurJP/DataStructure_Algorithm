cmake_minimum_required(VERSION 3.14)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(max2 max2.cpp)
add_executable(fibonacci fibonacci/main.cpp)
add_executable(vector vector/vector.cpp vector/vector_constructor_by_copying.cpp vector/vector_bracket.cpp)