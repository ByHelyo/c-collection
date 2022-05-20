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
    ++linked_list->size;
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
    ++linked_list->size;
}

void linkedList_insert(struct LinkedList *linked_list, size_t index, void *elt)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index > linked_list->size)
        errx(1, "Given index is higher than the size of the linked list");

    if (index == 0)
    {
        linkedList_push(linked_list, elt);

        return;
    }

    struct Node *prev_node = NULL;
    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        prev_node = current_node;
        current_node = current_node->next;
        --index;
    }

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");

    node->data = elt;
    node->next = current_node;

    prev_node->next = node;
    ++linked_list->size;
}

void *linkedList_remove(struct LinkedList *linked_list, size_t index)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index >= linked_list->size)
        errx(1, "Given index is higher than the size of the linked list");

    if (index == 0)
    {
        struct Node *removed_node = linked_list->head;
        void *removed_element = removed_node->data;

        linked_list->head = linked_list->head->next;

        free(removed_node);

        --linked_list->size;
        return removed_element;
    }

    struct Node *prev_node = NULL;
    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        prev_node = current_node;
        current_node = current_node->next;

        --index;
    }

    void *ret = current_node->data;

    prev_node->next = current_node->next;

    free(current_node);

    --linked_list->size;
    return ret;
}

void *linkedList_get(struct LinkedList *linked_list, size_t index)
{
    if (linked_list == NULL)
        errx(1, "linked_list is NULL");

    if (index >= linked_list->size)
        errx(1, "Given index is higher than the size of the linked list");

    struct Node *current_node = linked_list->head;

    while (index > 0)
    {
        current_node = current_node->next;
        --index;
    }

    return current_node->data;
}

void linkedList_clear(struct LinkedList *linked_list, void (*free_function)(void *))
{
    while (linked_list->size > 0)
    {
        void *popped_elt = linkedList_remove(linked_list, 0);

        if (free_function != NULL)
        {
            free_function(popped_elt);
        }
    }
}
