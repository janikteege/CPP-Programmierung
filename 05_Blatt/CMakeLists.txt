cmake_minimum_required(VERSION 3.5.0)
project(blatt5 VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable(blatt5 example.cpp immstring.cpp)
add_compile_options(-Wall -Wextra -Wpedantic)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
