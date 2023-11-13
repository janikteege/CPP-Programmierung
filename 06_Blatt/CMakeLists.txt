cmake_minimum_required(VERSION 3.5.0)
project(a05 VERSION 0.0.0)
set (CMAKE_CXX_STANDARD 17)

add_executable(a05 exptree.cpp main.cpp)


target_compile_options(a05 PRIVATE -Wall -Wextra -pedantic)