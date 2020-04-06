cmake_minimum_required(VERSION 2.8.3)
project(test_mst40)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(test_mst40 src/main.cpp)