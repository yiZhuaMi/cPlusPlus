cmake_minimum_required(VERSION 2.8.3)
project(hand_write)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(hand_write_test src/main.cpp)
add_executable(pro_com src/producer_comsumer.cpp)