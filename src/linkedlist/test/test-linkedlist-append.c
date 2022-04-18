#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_append, err_append_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    int elt1 = 1;

    linkedList_append(linked_list, &elt1);
}

Test(linkedList_append, append_1)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;

    linkedList_append(&linked_list, &elt1);

    // check appended element

    // Check address
    cr_assert_eq(linked_list.head->data, &elt1);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->data), elt1);

    // Check linked_list-size
    cr_assert_eq(linked_list.size, 1);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_append, append_2)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;

    linkedList_append(&linked_list, &elt1);
    linkedList_append(&linked_list, &elt2);

    // check appended element

    // Check address
    cr_assert_eq(linked_list.head->next->data, &elt2);

    // Check value
    cr_assert_eq(*((int *)linked_list.head->next->data), elt2);

    // Check linked_list-size
    cr_assert_eq(linked_list.size, 2);

    linkedList_clear(&linked_list, NULL);
}
