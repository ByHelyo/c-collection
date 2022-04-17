#include <criterion/criterion.h>

#include "../src/linkedlist.h"

Test(linkedList_pop, pop_int_1_index_0)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int* pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);
}

Test(linkedList_pop, err_pop_int_1_index_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int* pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);

    // Check linked_list

    cr_assert_eq(linked_list.size, 1);
}

Test(linkedList_pop, pop_int_2_index_0)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int* pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);
}

Test(linkedList_pop, pop_int_2_index_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int* pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);
}

Test(linkedList_pop, err_pop_int_2_index_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int* pop_elt = linkedList_pop(&linked_list, 2);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);
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

    int* pop_elt = linkedList_pop(&linked_list, 0);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt3, pop_elt);

    // Check value
    cr_assert_eq(push_elt3, *pop_elt);
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

    int* pop_elt = linkedList_pop(&linked_list, 1);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt2, pop_elt);

    // Check value
    cr_assert_eq(push_elt2, *pop_elt);
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

    int* pop_elt = linkedList_pop(&linked_list, 2);

    // Check popped element

    // Check address
    cr_assert_eq(&push_elt1, pop_elt);

    // Check value
    cr_assert_eq(push_elt1, *pop_elt);
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

    int* pop_elt = linkedList_pop(&linked_list, 3);

    // Check popped element

    // Check address
    cr_assert_eq(NULL, pop_elt);
}