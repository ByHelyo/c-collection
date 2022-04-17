#include "linkedlist.h"

#include <err.h>

struct LinkedList linkedList_build()
{
    struct LinkedList linked_list = { .head = NULL, .size = 0 };

    return linked_list;
}

size_t linkedList_size(struct LinkedList* linked_list)
{
    return linked_list->size;
}

void linkedList_push(struct LinkedList* linked_list, void* elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    struct List* list = calloc(1, sizeof(struct List));
    if (list == NULL)
        err(1, "Failed allocation");

    list->next = linked_list->head;
    list->data = elt;

    linked_list->head = list;
    linked_list->size += 1;
}

void linkedList_append(struct LinkedList* linked_list, void* elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (linked_list->size == 0) {
        linkedList_push(linked_list, elt);

        return;
    }

    struct List* current_list = linked_list->head;

    while (current_list->next != NULL) {
        current_list = current_list->next;
    }

    struct List* new_list = calloc(1, sizeof(struct List));
    if (new_list == NULL)
        err(1, "Failed allocation");

    new_list->data = elt;
    new_list->next = NULL;

    current_list->next = new_list;
    linked_list->size += 1;
}

int linkedList_insert(struct LinkedList* linked_list, size_t index, void* elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index == 0) {
        linkedList_push(linked_list, elt);

        return 1;
    }

    if (index > linked_list->size) {
        return 0;
    }

    struct List* prev_list = NULL;
    struct List* current_list = linked_list->head;

    while (index > 0) {
        prev_list = current_list;
        current_list = current_list->next;
        index -= 1;
    }

    struct List* new_list = calloc(1, sizeof(struct List));
    if (new_list == NULL)
        err(1, "Failed allocation");

    new_list->data = elt;
    new_list->next = current_list;

    prev_list->next = new_list;
    linked_list->size += 1;

    return 1;
}

void* linkedList_pop(struct LinkedList* linked_list, size_t index)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

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

void linkedList_clear(struct LinkedList* linked_list, void (*free_function)(void*))
{
    while (linked_list->size > 0) {
        void* popped_elt = linkedList_pop(linked_list, 0);

        if (free_function != NULL) {
            free_function(popped_elt);
        }
    }
}