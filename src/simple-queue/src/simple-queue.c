#include "simple-queue.h"

struct SimpleQueue simpleQueue_build()
{
    struct SimpleQueue simple_queue = {.head = NULL, .tail = NULL, .size = 0};

    return simple_queue;
}
