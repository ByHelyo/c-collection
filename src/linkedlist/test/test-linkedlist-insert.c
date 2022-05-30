#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_insert, insert_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    int elt1 = 1;

    linkedList_insert(linked_list, 3, &elt1);
}

Test(linkedList_insert, insert_at_0_size_0)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;

    linkedList_insert(&linked_list, 0, &elt1);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->data, &elt1);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->data), elt1);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_at_0_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    linkedList_insert(&linked_list, 0, &inserted_elt);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_at_1_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    linkedList_insert(&linked_list, 1, &inserted_elt);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_at_2_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    linkedList_insert(&linked_list, 2, &inserted_elt);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_at_3_size_3)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    linkedList_insert(&linked_list, 3, &inserted_elt);

    // Check inserted element

    // Check address
    cr_assert_eq(linked_list.head->next->next->next->data, &inserted_elt);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->next->next->data), inserted_elt);

    // Check linked_list->size
    cr_assert_eq(linked_list.size, 4);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_insert, insert_at_4_size_3, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    int inserted_elt = 4;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt3);

    linkedList_insert(&linked_list, 4, &inserted_elt);
}
