#ifndef C_COLLECTION_STACK_H
#define C_COLLECTION_STACK_H

#include <stdlib.h>

struct Node;

struct Stack
{
    struct Node *head;

    size_t size;
};

struct Stack stack_build();

size_t stack_size(struct Stack *stack);

void stack_push(struct Stack *stack, void *elt);

void *stack_pop(struct Stack *stack);

#endif // C_COLLECTION_STACK_H
