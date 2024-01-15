#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next;
} node;
node *head = NULL;

node *create(char data)
{
    node *result = malloc(sizeof(node));
    result->data = data;
    result->next = NULL;
    return result;
}
void push(char data)
{
    node *new = create(data);
    new->next = head;
    head = new;
}

void pop()
{
    if (head == NULL)
        return;
    node *tmp = head;
    printf("%c", tmp->data);
    head = tmp->next;
    free(tmp);
}

void reverse(char *C)
{
    int length = 0;
    for (int i = 0; C[i] != '\0'; ++i)
    {
        length++;
    }

    for (int i = 0; i < length; i++)
    {
        push(C[i]);
    }
    for (int i = 0; i < length; i++)
    {
        pop();
    }
}

void print()
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("- %d ", tmp->data);
        tmp = tmp->next;
    }
}
int main()
{
    char a[50];
    printf("Your string: ");
    scanf("%s", &a);
    reverse(a);

    return 0;
}
