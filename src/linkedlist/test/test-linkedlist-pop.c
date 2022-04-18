#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_pop, err_pop_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    linkedList_pop(linked_list, 0);
}

Test(linkedList_pop, err_pop_empty)
{
    struct LinkedList linked_list = linkedList_build();

    int *pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    cr_assert_eq(pop_elt, NULL);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_pop, pop_int_1_index_0)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int *pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, err_pop_int_1_index_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int *pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);

    // Check linked_list
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, pop_int_2_index_0)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, pop_int_2_index_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, err_pop_int_2_index_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *pop_elt = linkedList_pop(&linked_list, 2);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, pop_int_3_index_0)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, pop_elt);

    // Check value
    cr_assert_eq(push_elt3, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, pop_int_3_index_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, pop_int_3_index_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *pop_elt = linkedList_pop(&linked_list, 2);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_pop, err_pop_int_3_index_3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *pop_elt = linkedList_pop(&linked_list, 3);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 3);

    linkedList_clear(&linked_list, NULL);
}
