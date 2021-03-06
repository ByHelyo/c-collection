#include "../../node.h"
#include "../src/linkedlist.h"
#include <criterion/criterion.h>

Test(linkedList_build, build)
{
    struct LinkedList linked_list = linkedList_build();

    cr_assert_eq(linked_list.size, 0);
    cr_assert_eq(linked_list.head, NULL);
}
