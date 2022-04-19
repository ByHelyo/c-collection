add_library(linkedlist STATIC
        src/linkedlist.c
        src/linkedlist.h
        ../node.h
        )

add_executable(linkedlist-test
        test/test-linkedlist-append.c
        test/test-linkedlist-build.c
        test/test-linkedlist-get.c
        test/test-linkedlist-insert.c
        test/test-linkedlist-pop.c
        test/test-linkedlist-push.c)

target_compile_options(linkedlist-test PUBLIC -Werror)
target_compile_options(linkedlist-test PUBLIC -Wall)
target_compile_options(linkedlist-test PUBLIC -Wextra)
target_compile_options(linkedlist-test PUBLIC -pedantic)
target_compile_options(linkedlist-test PUBLIC -fsanitize=address)
target_compile_options(linkedlist-test PUBLIC -g)

target_link_options(linkedlist-test PUBLIC -fsanitize=address)

target_link_libraries(linkedlist-test linkedlist criterion)