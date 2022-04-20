#include "../../node.h"
#include "../src/simple-queue.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(simpleQueue_dequeue, err_dequeue_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct SimpleQueue *simple_queue = NULL;

    simpleQueue_dequeue(simple_queue);
}

Test(simpleQueue_dequeue, err_dequeue_empty, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    simpleQueue_dequeue(&simple_queue);
}

Test(simpleQueue_dequeue, dequeue_1)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;

    simpleQueue_enqueue(&simple_queue, &elt1);

    int *dequeued = simpleQueue_dequeue(&simple_queue);

    // Check dequeued element

    cr_assert_eq(dequeued, &elt1);
    cr_assert_eq(*dequeued, elt1);
}

Test(simpleQueue_dequeue, dequeue_2)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;
    int elt2 = 2;

    simpleQueue_enqueue(&simple_queue, &elt1);
    simpleQueue_enqueue(&simple_queue, &elt2);

    int *dequeued = simpleQueue_dequeue(&simple_queue);

    // Check dequeued element

    cr_assert_eq(dequeued, &elt1);
    cr_assert_eq(*dequeued, elt1);
}

Test(simpleQueue_dequeue, dequeue_3)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    simpleQueue_enqueue(&simple_queue, &elt1);
    simpleQueue_enqueue(&simple_queue, &elt2);
    simpleQueue_enqueue(&simple_queue, &elt3);

    int *dequeued = simpleQueue_dequeue(&simple_queue);

    // Check dequeued element

    cr_assert_eq(dequeued, &elt1);
    cr_assert_eq(*dequeued, elt1);
}
