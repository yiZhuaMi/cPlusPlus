cmake_minimum_required(VERSION 2.8.3)
project(exam_yfd2)

add_compile_options(-std=c++11)

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(exam_yfd2 src/main.cpp)