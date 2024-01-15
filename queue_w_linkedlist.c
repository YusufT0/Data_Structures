#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

node *create_node(int data)
{
    node *result;
    result = malloc(sizeof(node));
    result->data = data;
    result->next = NULL;
}
void enqueue(int data)
{
    node *tmp = create_node(data);
    tmp->data = data;
    tmp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = tmp;
        return;
    }
    rear->next = tmp;
    rear = tmp;
}

void dequeue()
{
    node *tmp = front;
    if (front == NULL)
        return;
    if (front == rear)
    {
        front = rear = NULL;
        return;
    }
    front = tmp->next;
    free(tmp);
}
void printlist()
{
    node *temp = front;

    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    printlist();
}