cmake_minimum_required(VERSION 2.8.3)
project(test_mst46)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(test_mst46 src/main.cpp)