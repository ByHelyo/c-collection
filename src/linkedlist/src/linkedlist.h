#ifndef C_COLLECTION_LINKEDLIST_H
#define C_COLLECTION_LINKEDLIST_H

#include "../../list/src/list.h"
#include <stdlib.h>

struct LinkedList {
    struct List* head;
    size_t size;
};

struct LinkedList linkedList_build();

void linkedList_push(struct LinkedList* linked_list, void* elt);

void* linkedList_pop(struct LinkedList* linked_list, size_t index);

void linkedList_clear(struct LinkedList* linked_list, void (*free)(void*));

#endif // C_COLLECTION_LINKEDLIST_H
