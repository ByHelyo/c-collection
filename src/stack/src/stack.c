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
        errx(1, "stack is empty");

    struct Node *first_node = stack->head;
    void *ret = first_node->data;

    stack->size -= 1;
    stack->head = stack->head->next;

    free(first_node);

    return ret;
}

void *stack_peek(struct Stack *stack)
{
    if (stack == NULL)
        errx(1, "stack is NULL");

    if (stack->size == 0)
        errx(1, "stack is empty");

    return stack->head->data;
}

void stack_clear(struct Stack *stack, void (*free_function)(void *))
{
    while (stack->size > 0)
    {
        void *popped_elt = stack_pop(stack);

        if (free_function != NULL)
        {
            free_function(popped_elt);
        }
    }
}
