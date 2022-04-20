#ifndef C_COLLECTION_STACK_H
#define C_COLLECTION_STACK_H

#include <stdlib.h>

struct Node;

struct Stack
{
    struct Node *head;

    size_t size;
};

/**
 * Build a stack
 *
 * @return stack built
 */
struct Stack stack_build();

/**
 * Return the size of the stack
 *
 * @param stack
 * @return size
 */
size_t stack_size(struct Stack *stack);

/**
 * Push ''element'' at the head of the stack
 *
 * @param stack
 * @param elt
 */
void stack_push(struct Stack *stack, void *elt);

/**
 * Pop an element at the head of the stack and return it
 *
 * @param stack
 * @return popped element
 *         NULL if the stack is empty
 */
void *stack_pop(struct Stack *stack);

/**
 * Get the top element of the stack
 *
 * @param stack
 * @return the top element
 */
void *stack_peek(struct Stack *stack);

/**
 * Clear the stack
 *
 * A free function can be provided to free each element otherwise ''free_function''  must be set to NULL
 *
 * @param stack
 * @param free_function
 */
void stack_clear(struct Stack *stack, void (*free_function)(void *));

#endif // C_COLLECTION_STACK_H
