#include <criterion/criterion.h>

#include "../src/linkedlist.h"

Test(linkedlist_build, build)
{
    struct LinkedList linked_list = linkedList_build();

    cr_assert_eq(linked_list.size, 0);
    cr_assert_eq(linked_list.head, NULL);
}
