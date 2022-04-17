#include <criterion/criterion.h>

#include "../src/linkedlist.h"
#include <criterion/redirect.h>

Test(linkedList, push_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList* linked_list = NULL;

    int elt1 = 1;

    linkedList_push(linked_list, &elt1);
}

Test(linkedList_push, push_int)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;

    linkedList_push(&linked_list, &elt1);

    // Check linked_list

    // Check size
    cr_assert_eq(linked_list.size, 1);

    // Check address
    cr_assert_eq(linked_list.head->data, &elt1);

    // Check value
    cr_assert_eq(*((int*)linked_list.head->data), elt1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_push, push_2_int)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;

    linkedList_push(&linked_list, &elt1);
    linkedList_push(&linked_list, &elt2);

    // Check linked_list

    // Check size
    cr_assert_eq(linked_list.size, 2);

    // Check address
    cr_assert_eq(linked_list.head->data, &elt2);

    // Check value
    cr_assert_eq(*((int*)linked_list.head->data), elt2);

    linkedList_clear(&linked_list, NULL);
}