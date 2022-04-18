add_library(stack STATIC
        src/stack.c
        src/stack.h
        ../node.h)

add_executable(stack-test
        test/test-stack-build.c
        test/test-stack-pop.c
        test/test-stack-push.c)

target_compile_options(stack-test PUBLIC -Werror)
target_compile_options(stack-test PUBLIC -Wall)
target_compile_options(stack-test PUBLIC -Wextra)
target_compile_options(stack-test PUBLIC -pedantic)
#target_compile_options(stack-test PUBLIC -fsanitize=address)
target_compile_options(stack-test PUBLIC -g)

#target_link_options(stack-test PUBLIC -fsanitize=address)

target_link_libraries(stack-test stack criterion)