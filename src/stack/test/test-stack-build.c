#include "../../node.h"
#include "../src/stack.h"
#include <criterion/criterion.h>

Test(stack_build, build)
{
    struct Stack stack = stack_build();

    cr_assert_eq(stack.size, 0);
    cr_assert_eq(stack.head, NULL);
}
