#include "../../node.h"
#include "../src/simple-queue.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(simpleQueue_enqueue, err_enqueue_NULL, .exit_code = 1, .init = cr_redirect_stderr)
{
    struct SimpleQueue *simple_queue = NULL;

    int elt1 = 1;

    simpleQueue_enqueue(simple_queue, &elt1);
}

Test(simpleQueue_enqueue, enqueue_1)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;

    simpleQueue_enqueue(&simple_queue, &elt1);

    // Check simple_queue

    // Check head
    cr_assert_eq(simple_queue.head->data, &elt1);
    cr_assert_eq(*((int *)simple_queue.head->data), elt1);

    // Check tail
    cr_assert_eq(simple_queue.tail->data, &elt1);
    cr_assert_eq(*((int *)simple_queue.tail->data), elt1);

    cr_assert_eq(simple_queue.size, 1);
}

Test(simpleQueue_enqueue, enqueue_2)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;
    int elt2 = 2;

    simpleQueue_enqueue(&simple_queue, &elt1);
    simpleQueue_enqueue(&simple_queue, &elt2);

    // Check simple_queue

    // Check head
    cr_assert_eq(simple_queue.head->data, &elt1);
    cr_assert_eq(*((int *)simple_queue.head->data), elt1);

    // Check tail
    cr_assert_eq(simple_queue.tail->data, &elt2);
    cr_assert_eq(*((int *)simple_queue.tail->data), elt2);

    cr_assert_eq(simple_queue.size, 2);
}

Test(simpleQueue_enqueue, enqueue_3)
{
    struct SimpleQueue simple_queue = simpleQueue_build();

    int elt1 = 1;
    int elt2 = 2;
    int elt3 = 3;

    simpleQueue_enqueue(&simple_queue, &elt1);
    simpleQueue_enqueue(&simple_queue, &elt2);
    simpleQueue_enqueue(&simple_queue, &elt3);

    // Check simple_queue

    // Check head
    cr_assert_eq(simple_queue.head->data, &elt1);
    cr_assert_eq(*((int *)simple_queue.head->data), elt1);

    // Check tail
    cr_assert_eq(simple_queue.tail->data, &elt3);
    cr_assert_eq(*((int *)simple_queue.tail->data), elt3);

    cr_assert_eq(simple_queue.size, 3);
}
