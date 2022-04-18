#include "stack.h"
#include "../../node.h"
#include <err.h>

struct Stack stack_build()
{
    struct Stack stack = {.head = NULL, .size = 0};

    return stack;
}

void stack_push(struct Stack *stack, void *elt)
{
    if (stack == NULL)
        errx(1, "stack is NULL");

    struct Node *node = calloc(1, sizeof(struct Node));
    if (node == NULL)
        err(1, "Failed allocation");

    node->next = stack->head;
    node->data = elt;

    stack->head = node;
    stack->size += 1;
}
