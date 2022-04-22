#include "simple-queue.h"
#include "../../node.h"
#include <err.h>

struct SimpleQueue simpleQueue_build()
{
    struct SimpleQueue simple_queue = {.head = NULL, .tail = NULL, .size = 0};

    return simple_queue;
}

void simpleQueue_enqueue(struct SimpleQueue *simple_queue, void *elt)
{
    if (simple_queue == NULL)
        errx(1, "stack is NULL");

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");
    node->data = elt;
    node->next = NULL;

    if (simple_queue->size == 0)
    {
        simple_queue->head = node;
        simple_queue->tail = node;

        simple_queue->size += 1;

        return;
    }

    // Old tail node points to the new node
    simple_queue->tail->next = node;
    simple_queue->tail = node;

    simple_queue->size += 1;
}

void *simpleQueue_dequeue(struct SimpleQueue *simple_queue)
{
    if (simple_queue == NULL)
        errx(1, "stack is NULL");

    if (simple_queue->size == 0)
        errx(1, "stack is empty");

    struct Node *head_node = simple_queue->head;
    void *ret = head_node->data;

    simple_queue->head = simple_queue->head->next;
    simple_queue->size -= 1;

    free(head_node);
    return ret;
}

void *simpleQueue_peek(struct SimpleQueue *simple_queue)
{
    if (simple_queue == NULL)
        errx(1, "stack is NULL");

    if (simple_queue->size == 0)
        errx(1, "stack is empty");

    return simple_queue->head->data;
}

void simpleQueue_clear(struct SimpleQueue *simple_queue, void (*free_function)(void *))
{
    while (simple_queue->size > 0)
    {
        void *dequeued_elt = simpleQueue_dequeue(simple_queue);

        if (free_function != NULL)
        {
            free_function(dequeued_elt);
        }
    }
}