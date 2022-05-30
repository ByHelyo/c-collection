#include "../../node.h"
#include "../src/stack.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(stack_peek, peek_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack *stack = NULL;

    stack_peek(stack);
}

Test(stack_peek, peek_empty, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack stack = stack_build();

    stack_peek(&stack);
}

Test(stack_peek, peek_size_1)
{
    struct Stack stack = stack_build();

    int elt1 = 1;

    stack_push(&stack, &elt1);

    int *ret = stack_peek(&stack);

    // Check peeked element

    // Check address
    cr_assert_eq(ret, &elt1);

    // Check value
    cr_assert_eq(*ret, elt1);

    // Check stack
    cr_assert_eq(stack.size, 1);

    stack_clear(&stack, NULL);
}

Test(stack_peek, peek_size_2)
{
    struct Stack stack = stack_build();

    int elt1 = 1;
    int elt2 = 2;

    stack_push(&stack, &elt1);
    stack_push(&stack, &elt2);

    int *ret = stack_peek(&stack);

    // Check peeked element

    // Check address
    cr_assert_eq(ret, &elt2);

    // Check value
    cr_assert_eq(*ret, elt2);

    // Check stack
    cr_assert_eq(stack.size, 2);

    stack_clear(&stack, NULL);
}
