cmake_minimum_required(VERSION 3.22)

project(c-collection)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src/linkedlist)
add_subdirectory(src/stack)
add_subdirectory(src/simple-queue)

add_executable(c-collection src/main.c)
target_link_libraries(c-collection linkedlist stack)
