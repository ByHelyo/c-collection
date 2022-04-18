cmake_minimum_required(VERSION 3.22)

project(c-collection)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src/linkedlist)
add_executable(c-collection src/main.c)