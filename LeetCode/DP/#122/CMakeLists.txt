cmake_minimum_required(VERSION 2.8.3)
project(test_122)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(test_122 src/main.cpp)