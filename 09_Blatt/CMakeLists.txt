cmake_minimum_required(VERSION 3.5.0)
project(a09 VERSION 0.0.0)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(a09 main.cpp renderer.cpp)

target_compile_options(a09 PRIVATE -Wall -Wextra -pedantic -Werror)