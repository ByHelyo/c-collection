#ifndef C_COLLECTION_SIMPLE_QUEUE_H
#define C_COLLECTION_SIMPLE_QUEUE_H

#include <stdlib.h>

struct SimpleQueue
{
    struct Node *head;
    struct Node *tail;

    size_t size;
};

struct SimpleQueue simpleQueue_build();

#endif // C_COLLECTION_SIMPLE_QUEUE_H
