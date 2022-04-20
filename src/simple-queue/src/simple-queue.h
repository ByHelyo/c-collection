#ifndef C_COLLECTION_SIMPLE_QUEUE_H
#define C_COLLECTION_SIMPLE_QUEUE_H

#include <stdlib.h>

struct Node;

struct SimpleQueue
{
    struct Node *head;
    struct Node *tail;

    size_t size;
};

struct SimpleQueue simpleQueue_build();

void simpleQueue_enqueue(struct SimpleQueue *simple_queue, void *elt);

#endif // C_COLLECTION_SIMPLE_QUEUE_H
