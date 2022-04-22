#include "../../node.h"
#include "../src/simple-queue.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(simpleQueue_peek, err_peek_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct SimpleQueue *simple_queue = NULL;

    simpleQueue_peek(simple_queue);
}

Test(simpleQueue_peek, peek_size_1)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;

    simpleQueue_enqueue(&simple_queue, &elt1);

    int *dequeued_elt = simpleQueue_peek(&simple_queue);

    // Check dequeued element

    // Check address
    cr_assert_eq(dequeued_elt, &elt1);

    // Check value
    cr_assert_eq(*dequeued_elt, elt1);

    // Check simple_queue
    cr_assert_eq(simple_queue.size, 1);

    simpleQueue_clear(&simple_queue, NULL);
}

Test(simpleQueue_peek, peek_size_2)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;
    int elt2 = 2;

    simpleQueue_enqueue(&simple_queue, &elt1);
    simpleQueue_enqueue(&simple_queue, &elt2);

    int *dequeued_elt = simpleQueue_peek(&simple_queue);

    // Check dequeued element

    // Check address
    cr_assert_eq(dequeued_elt, &elt1);

    // Check value
    cr_assert_eq(*dequeued_elt, elt1);

    // Check simple_queue
    cr_assert_eq(simple_queue.size, 2);

    simpleQueue_clear(&simple_queue, NULL);
}
