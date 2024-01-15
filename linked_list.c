#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node_t;

// Function to print the linked list.
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

// Function to create a new node.
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->data = value;
    result->next = NULL;
    return result;
}

// Function to insert to head.
void insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
}

// Function to insert to tail.
void insert_at_tail(node_t *head, node_t *node_to_insert)
{
    node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node_to_insert;
}
// Function to reverse the list.
void reverse(node_t **head)
{
    node_t *current, *prev, *next;
    current = *head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void delete_node_w_position(node_t **head, int position)
{
    node_t *tmp = *head;
    node_t *tmp2;
    if (position == 1)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (position != 2)
    {
        tmp = tmp->next;
        position--;
    }
    tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
}
node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void insert_after_node(node_t *head, int bf_node, int nw_node)
{
    node_t *node_to_insert_after = find_node(head, bf_node);
    node_t *new_node = create_new_node(nw_node);
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}
int main()
{
    int num;
    int last_num;
    node_t *head = NULL;
    node_t *tmp;
    insert_at_head(&head, create_new_node(12));
    insert_at_head(&head, create_new_node(24));
    insert_at_head(&head, create_new_node(36));
    insert_at_head(&head, create_new_node(48));
    insert_at_head(&head, create_new_node(100));
    insert_at_head(&head, create_new_node(101));
    insert_at_tail(head, create_new_node(56));
    reverse(&head);
    printlist(head);
    return 0;
}