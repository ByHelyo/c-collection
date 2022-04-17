cmake_minimum_required(VERSION 3.22)

project(c-collections)

set(CMAKE_C_STANDARD 99)

add_library(linkedlist SHARED
        src/linkedlist/src/linkedlist.c
        src/linkedlist/src/linkedlist.h
        src/list/src/list.h
)

add_executable(linkedlist_test
        src/linkedlist/test/test_linkedlist_build.c
        src/linkedlist/test/test_linkedlist_pop.c
        src/linkedlist/test/test_linkedlist_push.c)
target_link_libraries(linkedlist_test linkedlist criterion)


add_executable(c-collections src/main.c)
target_link_libraries(c-collections linkedlist)