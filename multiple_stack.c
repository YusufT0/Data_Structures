#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 10

#define ISFULL(p) (!(p))
#define ISEMPTY(p) (!(p))

typedef struct stack
{
    int x;
    struct stack *next;
} stack;
typedef struct stack *stack_pointer;
stack_pointer top[MAX_STACK];

void add_stack(stack_pointer *top, int x)
{
    stack_pointer p = malloc(sizeof(stack));
    if (ISFULL(p))
    {
        printf("\n Memory allocation failed");
        exit(1);
    }
    p->x = x;
    p->next = *top;
    *top = p;
}
void remove_stack(stack_pointer *top)
{
    if (*top == NULL)
    {
        printf("STACK IS EMPTY");
        return;
    }
    stack_pointer p = *top;
    *top = p->next;
    free(p);
}

void printList(stack_pointer *top)
{
    stack_pointer p = *top;
    while (p != NULL)
    {
        printf(" %d -", p->x);
        p = p->next;
    }
}

int main()
{
    for (int i = 0; i < MAX_STACK; i++)
    {
        top[i] = NULL;
    }

    add_stack(&top[0], 1);
    add_stack(&top[0], 2);
    add_stack(&top[0], 3);
    add_stack(&top[0], 4);
    add_stack(&top[0], 5);
    remove_stack(&top[0]);
    remove_stack(&top[0]);
    remove_stack(&top[0]);
    add_stack(&top[1], 10);
    add_stack(&top[1], 11);
    add_stack(&top[1], 12);
    add_stack(&top[1], 13);
    add_stack(&top[1], 14);

    printList(&top[0]);
    printf("\n");
    printList(&top[1]);

    return 0;
}
