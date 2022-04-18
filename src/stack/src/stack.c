#include "stack.h"
#include "../../node.h"
#include <err.h>

struct Stack stack_build()
{
    struct Stack stack = {.head = NULL, .size = 0};

    return stack;
}

size_t stack_size(struct Stack *stack)
{
    return stack->size;
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

void *stack_pop(struct Stack *stack)
{
    if (stack == NULL)
        errx(1, "stack is NULL");

    if (stack->size == 0)
        return NULL;

    struct Node *first_node = stack->head;
    void *ret = first_node->data;

    stack->size -= 1;
    stack->head = stack->head->next;

    free(first_node);

    return ret;
}
