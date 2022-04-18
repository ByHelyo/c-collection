#include "../../list/src/list.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_insert, err_insert_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    int elt1 = 1;

    int ret = linkedList_insert(linked_list, 3, &elt1);
    cr_assert_eq(ret, 0);
}

Test(linkedList_insert, insert_0_0)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;

    int ret = linkedList_insert(&linked_list, 0, &elt1);
    cr_assert_eq(ret, 1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->data, &elt1);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->data), elt1);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_3_0)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    int ret = linkedList_insert(&linked_list, 0, &inserted_elt);
    cr_assert_eq(ret, 1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_3_1)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    int ret = linkedList_insert(&linked_list, 1, &inserted_elt);
    cr_assert_eq(ret, 1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_3_2)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    int ret = linkedList_insert(&linked_list, 2, &inserted_elt);
    cr_assert_eq(ret, 1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_3_3)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    int ret = linkedList_insert(&linked_list, 3, &inserted_elt);
    cr_assert_eq(ret, 1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->next->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->next->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, err_insert_3_4)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    int ret = linkedList_insert(&linked_list, 4, &inserted_elt);
    cr_assert_eq(ret, 0);

    // Check inserted element

    cr_assert_eq(ret, 0);

    linkedList_clear(&linked_list, NULL);
}
