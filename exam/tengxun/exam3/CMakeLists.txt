cmake_minimum_required(VERSION 2.8.3)
project(exam_tx3)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(exam_tx3 src/main.cpp)