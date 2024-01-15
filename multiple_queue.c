#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;

} queue;

typedef struct queue *queue_pointer;

void enqueue(queue_pointer *front, queue_pointer *rear, int x)
{
    queue_pointer p = malloc(sizeof(queue));
    p->data = x;
    p->next = NULL;
    if (*front)
    {
        (*rear)->next = p;
    }
    else
    {
        *front = p;
    }
    *rear = p;
}
void dequeue(queue_pointer *front, queue_pointer *rear)
{
    queue_pointer tmp = *front;
    if (*front == *rear)
    {
        *front = *rear = NULL;
        printf("The Queue is empty!");
        return;
    }
    *front = tmp->next;
    free(tmp);
}

void printlist(queue_pointer *front, queue_pointer *rear)
{
    queue_pointer tmp = *front;
    while (tmp != *rear)
    {
        printf(" %d - ", tmp->data);
        tmp = tmp->next;
    }
    printf(" %d - ", tmp->data);
}
int main()
{
    queue_pointer front[10], rear[10];
    for (int i = 0; i < 10; i++)
    {
        front[i] = NULL;
    }
    enqueue(&front[0], &rear[0], 1);
    enqueue(&front[0], &rear[0], 2);
    enqueue(&front[0], &rear[0], 3);
    enqueue(&front[0], &rear[0], 4);
    enqueue(&front[0], &rear[0], 5);

    enqueue(&front[1], &rear[1], 11);
    enqueue(&front[1], &rear[1], 22);
    enqueue(&front[1], &rear[1], 33);
    enqueue(&front[1], &rear[1], 44);
    enqueue(&front[1], &rear[1], 55);
    printlist(&front[0], &rear[0]);
    printf("\n");
    printlist(&front[1], &rear[1]);
}