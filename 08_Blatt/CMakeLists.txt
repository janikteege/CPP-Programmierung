cmake_minimum_required(VERSION 3.5.0)
project(a08 VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(a08 main.cpp)

target_compile_features(a08 PUBLIC cxx_std_14)

target_compile_options(a08 PRIVATE -Wall -Wextra -pedantic -Werror)
