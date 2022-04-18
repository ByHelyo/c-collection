cmake_minimum_required(VERSION 3.22)

project(c-collection)

set(CMAKE_C_STANDARD 99)

add_library(linkedlist STATIC
        src/linkedlist/src/linkedlist.c
        src/list/src/list.h
)

add_executable(linkedlist-test
        src/linkedlist/test/test-linkedlist-insert.c
        src/linkedlist/test/test-linkedlist-append.c
        src/linkedlist/test/test-linkedlist-build.c
        src/linkedlist/test/test-linkedlist-pop.c
        src/linkedlist/test/test-linkedlist-push.c)

target_link_libraries(linkedlist-test linkedlist criterion)
target_compile_options(linkedlist-test PUBLIC -Werror)
target_compile_options(linkedlist-test PUBLIC -Wall)
target_compile_options(linkedlist-test PUBLIC -Wextra)
target_compile_options(linkedlist-test PUBLIC -pedantic)
target_compile_options(linkedlist-test PUBLIC -fsanitize=address)
target_compile_options(linkedlist-test PUBLIC -g)
target_link_options(linkedlist-test PUBLIC -fsanitize=address)

add_executable(c-collection src/main.c)