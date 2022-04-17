#include "linkedlist.h"
#include <err.h>

struct LinkedList linkedList_build()
{
    struct LinkedList linked_list = { .head = NULL, .size = 0 };

    return linked_list;
}

void linkedList_push(struct LinkedList* linked_list, void* elt)
{
    struct List* list = calloc(1, sizeof(struct List));

    if (list == NULL)
        err(1, "Failed allocation");

    list->next = linked_list->head;
    list->data = elt;

    linked_list->head = list;
    linked_list->size += 1;
}

void* linkedList_pop(struct LinkedList* linked_list, size_t index)
{
    struct List* prev_list = NULL;
    struct List* current_list = linked_list->head;

    while (current_list != NULL && index > 0) {
        prev_list = current_list;
        current_list = current_list->next;

        index -= 1;
    }

    if (current_list == NULL) {
        return NULL;
    }

    void* ret = current_list->data;

    linked_list->size -= 1;

    // If the popped element is at index 0
    // linked_list->head points to the next element
    if (prev_list == NULL) {
        linked_list->head = linked_list->head->next;
    }

    // Otherwise, prev_list points to the next element
    else {
        prev_list->next = current_list->next;
    }

    free(current_list);

    return ret;
}