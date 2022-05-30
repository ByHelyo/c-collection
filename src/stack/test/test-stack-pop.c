#include "../../node.h"
#include "../src/stack.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(stack_pop, pop_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack *stack = NULL;

    stack_pop(stack);
}

Test(stack_pop, pop_empty, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack stack = stack_build();

    stack_pop(&stack);
}

Test(stack_pop, pop_1_elt_size_1)
{
    struct Stack stack = stack_build();

    int push_elt1 = 1;

    stack_push(&stack, &push_elt1);

    int *pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 0);
}

Test(stack_pop, pop_2_elt_size_2)
{
    struct Stack stack = stack_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    stack_push(&stack, &push_elt1);
    stack_push(&stack, &push_elt2);

    int *pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 1);

    pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 0);
}

Test(stack_pop, pop_3_elt_size_3)
{
    struct Stack stack = stack_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    stack_push(&stack, &push_elt1);
    stack_push(&stack, &push_elt2);
    stack_push(&stack, &push_elt3);

    int *pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, pop_elt);

    // Check value
    cr_assert_eq(push_elt3, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 2);

    pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 1);

    pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 0);
}

Test(stack_pop, pop_4_elt_size_3, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct Stack stack = stack_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    stack_push(&stack, &push_elt1);
    stack_push(&stack, &push_elt2);
    stack_push(&stack, &push_elt3);

    int *pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, pop_elt);

    // Check value
    cr_assert_eq(push_elt3, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 2);

    pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 1);

    pop_elt = stack_pop(&stack);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(stack.size, 0);

    stack_pop(&stack);
}
