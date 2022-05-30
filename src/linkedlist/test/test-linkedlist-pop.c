#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_pop, pop_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    linkedList_pop(linked_list);
}

Test(linkedList_pop, pop_1_elt_size_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int *popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, popped_elt);

    // Check value
    cr_assert_eq(push_elt1, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_pop, pop_2_elt_size_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, popped_elt);

    // Check value
    cr_assert_eq(push_elt2, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, popped_elt);

    // Check value
    cr_assert_eq(push_elt1, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_pop, pop_3_elt_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, popped_elt);

    // Check value
    cr_assert_eq(push_elt3, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, popped_elt);

    // Check value
    cr_assert_eq(push_elt2, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, popped_elt);

    // Check value
    cr_assert_eq(push_elt1, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_pop, pop_4_elt_size_3, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, popped_elt);

    // Check value
    cr_assert_eq(push_elt3, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, popped_elt);

    // Check value
    cr_assert_eq(push_elt2, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    popped_elt = linkedList_pop(&linked_list);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, popped_elt);

    // Check value
    cr_assert_eq(push_elt1, *popped_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);

    linkedList_pop(&linked_list);
}
