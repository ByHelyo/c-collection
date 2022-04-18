#include "../../node.h"
#include "../src/stack.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(stack_push, err_push_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack *stack = NULL;

    int elt1 = 1;

    stack_push(stack, &elt1);
}

Test(stack_push, _push_1)
{
    struct Stack stack = stack_build();

    int elt1 = 1;

    stack_push(&stack, &elt1);

    // Check stack

    // Check size
    cr_assert_eq(stack.size, 1);

    // Check address
    cr_assert_eq(stack.head->data, &elt1);

    // Check value
    cr_assert_eq(*((int *)stack.head->data), elt1);
}

Test(stack_push, _push_2)
{
    struct Stack stack = stack_build();

    int elt1 = 1;
    int elt2 = 2;

    stack_push(&stack, &elt1);
    stack_push(&stack, &elt2);

    // Check stack

    // Check size
    cr_assert_eq(stack.size, 2);

    // Check address
    cr_assert_eq(stack.head->data, &elt2);

    // Check value
    cr_assert_eq(*((int *)stack.head->data), elt2);
}
