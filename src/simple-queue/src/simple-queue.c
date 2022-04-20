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
