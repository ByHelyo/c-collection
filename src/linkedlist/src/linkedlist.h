#ifndef C_COLLECTION_LINKEDLIST_H
#define C_COLLECTION_LINKEDLIST_H

#include <stdlib.h>

struct Node;

struct LinkedList
{
    struct Node *head;
    size_t size;
};

/**
 * Build a linked list
 *
 * @return linked list built
 */
struct LinkedList linkedList_build();

/**
 * Return the size of the linked list
 *
 * @param linked_list
 * @return size
 */
size_t linkedList_size(struct LinkedList *linked_list);

/**
 * Insert ''elt'' at the head of the linked list
 *
 * @param linked_list
 * @param elt
 */
void linkedList_push(struct LinkedList *linked_list, void *elt);

/**
 * Insert ''elt'' at the end of the linked list
 *
 * @param linked_list
 * @param elt
 */
void linkedList_append(struct LinkedList *linked_list, void *elt);

/**
 * Insert ''elt'' at the specified ''index'' in the linked list
 *
 * @param linked_list
 * @param index
 * @param elt
 */
void linkedList_insert(struct LinkedList *linked_list, size_t index, void *elt);

/**
 * Pop an element from the linked list
 *
 * @param linked_list
 * @return popped element
 */
void *linkedList_pop(struct LinkedList *linked_list);

/**
 * Remove an element at the specified ''index'' in the linked list and return it
 *
 * @param linked_list
 * @param index
 * @return removed element
 */
void *linkedList_remove(struct LinkedList *linked_list, size_t index);

/**
 * get an element at the specified ''index'' in the linked list and return it
 *
 * @param linked_list
 * @param index
 * @return element specified
 */
void *linkedList_get(struct LinkedList *linked_list, size_t index);

/**
 * Clear the linked list
 *
 * A free function can be provided to free each element otherwise ''free_function'' must be set to NULL
 *
 * @param linked_list
 * @param free_function
 */
void linkedList_clear(struct LinkedList *linked_list, void (*free_function)(void *));

#endif // C_COLLECTION_LINKEDLIST_H
