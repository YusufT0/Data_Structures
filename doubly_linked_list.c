#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node_t;

void printlist(node_t *head)
{
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printreversed(node_t *head)
{
    node_t *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d -", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

node_t *insert_at_head(node_t *head, node_t *new_node)
{
    node_t *tmp = new_node;
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
    return head;
}
node_t *create_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->data = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

int main()
{
    node_t *head = NULL;
    head = insert_at_head(head, create_node(10));
    head = insert_at_head(head, create_node(12));
    head = insert_at_head(head, create_node(13));
    head = insert_at_head(head, create_node(14));
    head = insert_at_head(head, create_node(15));

    printreversed(head);
    printlist(head);
    return 0;
}