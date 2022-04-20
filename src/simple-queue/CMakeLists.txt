add_library(simple-queue STATIC
        src/simple-queue.c
        src/simple-queue.h
        ../node.h)

add_executable(simple-queue-test
        test/test-simple-queue-build.c
        test/test-simple-queue-enqueue.c)

target_compile_options(simple-queue-test PUBLIC -Werror)
target_compile_options(simple-queue-test PUBLIC -Wall)
target_compile_options(simple-queue-test PUBLIC -Wextra)
target_compile_options(simple-queue-test PUBLIC -pedantic)
#target_compile_options(simple-queue-test PUBLIC -fsanitize=address)
target_compile_options(simple-queue-test PUBLIC -g)

#target_link_options(simple-queue-test PUBLIC -fsanitize=address)

target_link_libraries(simple-queue-test simple-queue criterion)
