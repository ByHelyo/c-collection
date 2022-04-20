#include "linkedlist.h"
#include "../../node.h"
#include <err.h>

struct LinkedList linkedList_build()
{
    struct LinkedList linked_list = {.head = NULL, .size = 0};

    return linked_list;
}

size_t linkedList_size(struct LinkedList *linked_list)
{
    return linked_list->size;
}

void linkedList_push(struct LinkedList *linked_list, void *elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");

    node->next = linked_list->head;
    node->data = elt;

    linked_list->head = node;
    linked_list->size += 1;
}

void linkedList_append(struct LinkedList *linked_list, void *elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (linked_list->size == 0)
    {
        linkedList_push(linked_list, elt);

        return;
    }

    struct Node *current_node = linked_list->head;

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");

    node->data = elt;
    node->next = NULL;

    current_node->next = node;
    linked_list->size += 1;
}

void linkedList_insert(struct LinkedList *linked_list, size_t index, void *elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index == 0)
    {
        linkedList_push(linked_list, elt);

        return;
    }

    if (index > linked_list->size)
        errx(1, "given index is higher than the size of the linked list");

    struct Node *prev_node = NULL;
    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        prev_node = current_node;
        current_node = current_node->next;
        index -= 1;
    }

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");

    node->data = elt;
    node->next = current_node;

    prev_node->next = node;
    linked_list->size += 1;
}

void *linkedList_pop(struct LinkedList *linked_list, size_t index)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index >= linked_list->size)
        return NULL;

    struct Node *prev_node = NULL;
    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        prev_node = current_node;
        current_node = current_node->next;

        index -= 1;
    }

    void *ret = current_node->data;

    linked_list->size -= 1;

    // If the popped element is at index 0
    // linked_list->head points to the next element
    if (prev_node == NULL)
    {
        linked_list->head = linked_list->head->next;
    }

    // Otherwise, prev_list points to the next element
    else
    {
        prev_node->next = current_node->next;
    }

    free(current_node);

    return ret;
}

void *linkedList_get(struct LinkedList *linked_list, size_t index)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index >= linked_list->size)
        return NULL;

    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        current_node = current_node->next;
        index -= 1;
    }

    return current_node->data;
}

void linkedList_clear(struct LinkedList *linked_list, void (*free_function)(void *))
{
    while (linked_list->size > 0)
    {
        void *popped_elt = linkedList_pop(linked_list, 0);

        if (free_function != NULL)
        {
            free_function(popped_elt);
        }
    }
}
