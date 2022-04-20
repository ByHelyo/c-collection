#include "../../node.h"
#include "../src/simple-queue.h"
#include <criterion/criterion.h>

Test(stack_build, build)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    cr_assert_eq(simple_queue.size, 0);
    cr_assert_eq(simple_queue.head, NULL);
    cr_assert_eq(simple_queue.tail, NULL);
}
