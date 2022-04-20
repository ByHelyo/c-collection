#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(linkedList_get, err_get_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList *linked_list = NULL;

    linkedList_get(linked_list, 0);
}

Test(linkedList_get, get_empty, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct LinkedList linked_list = linkedList_build();

    linkedList_get(&linked_list, 10);
}

Test(linkedList_get, get_0)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    linkedList_push(&linked_list, &elt3);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt1);

    int *gotten = linkedList_get(&linked_list, 0);

    // Check gotten element

    // Check address
    cr_assert_eq(gotten, &elt1);

    // Check value
    cr_assert_eq(*gotten, elt1);

    // Check linked_list
    cr_assert_eq(linkedList_size(&linked_list), 3);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_get, get_1)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    linkedList_push(&linked_list, &elt3);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt1);

    int *gotten = linkedList_get(&linked_list, 1);

    // Check gotten element

    // Check address
    cr_assert_eq(gotten, &elt2);

    // Check value
    cr_assert_eq(*gotten, elt2);

    // Check linked_list
    cr_assert_eq(linkedList_size(&linked_list), 3);

    linkedList_clear(&linked_list, NULL);
}

Test(linkedList_get, get_2)
{
    struct LinkedList linked_list = linkedList_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    linkedList_push(&linked_list, &elt3);
    linkedList_push(&linked_list, &elt2);
    linkedList_push(&linked_list, &elt1);

    int *gotten = linkedList_get(&linked_list, 2);

    // Check gotten element

    // Check address
    cr_assert_eq(gotten, &elt3);

    // Check value
    cr_assert_eq(*gotten, elt3);

    // Check linked_list
    cr_assert_eq(linkedList_size(&linked_list), 3);

    linkedList_clear(&linked_list, NULL);
}
