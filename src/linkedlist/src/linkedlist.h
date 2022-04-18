#ifndef C_COLLECTION_LINKEDLIST_H
#define C_COLLECTION_LINKEDLIST_H

#include <stdlib.h>

struct Node;

struct LinkedList
{
    struct Node *head;
    size_t size;
};

struct LinkedList linkedList_build();

size_t linkedList_size(struct LinkedList *linked_list);

void linkedList_push(struct LinkedList *linked_list, void *elt);

void linkedList_append(struct LinkedList *linked_list, void *elt);

int linkedList_insert(struct LinkedList *linked_list, size_t index, void *elt);

void *linkedList_pop(struct LinkedList *linked_list, size_t index);

void linkedList_clear(struct LinkedList *linked_list, void (*free)(void *));

#endif // C_COLLECTION_LINKEDLIST_H
