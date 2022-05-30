#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_remove, remove_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    linkedList_remove(linked_list, 0);
}

Test(linkedList_remove, remove_empty, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    linkedList_remove(&linked_list, 0);
}

Test(linkedList_remove, remove_at_0_size_1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_at_1_size_1, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;

    linkedList_push(&linked_list, &push_elt1);

    linkedList_remove(&linked_list, 1);
}

Test(linkedList_remove, remove_at_0_size_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_remove, remove_at_1_size_2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_remove, remove_at_2_size_2, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    linkedList_remove(&linked_list, 2);
}

Test(linkedList_remove, remove_at_0_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_remove, remove_at_1_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_remove, remove_at_2_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 2);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_remove, remove_at_3_size_3, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    linkedList_remove(&linked_list, 3);
}

Test(linkedList_remove, remove_size_2_v1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_2_v2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);

    int *remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v1)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v2)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 2);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v3)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v4)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 2);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v5)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}

Test(linkedList_remove, remove_size_3_v6)
{
    struct LinkedList linked_list = linkedList_build();

    int push_elt1 = 1;
    int push_elt2 = 2;
    int push_elt3 = 3;

    linkedList_push(&linked_list, &push_elt1);
    linkedList_push(&linked_list, &push_elt2);
    linkedList_push(&linked_list, &push_elt3);

    int *remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt2, remove_elt);

    // Check value
    cr_assert_eq(push_elt2, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 2);

    remove_elt = linkedList_remove(&linked_list, 1);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt1, remove_elt);

    // Check value
    cr_assert_eq(push_elt1, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    remove_elt = linkedList_remove(&linked_list, 0);

    // Check removed element

    // Check address
    cr_assert_eq(&push_elt3, remove_elt);

    // Check value
    cr_assert_eq(push_elt3, *remove_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 0);
}
