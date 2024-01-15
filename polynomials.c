#include <stdio.h>
#include <stdlib.h>

typedef struct poly_node *poly_pointer;
typedef struct poly_node
{
    float coefficent;
    int expon;
    poly_pointer next;
} poly_node;

poly_pointer insert(poly_pointer head, float co, int exp)
{
    poly_pointer tmp;
    poly_pointer newP = malloc(sizeof(poly_node));
    newP->coefficent = co;
    newP->expon = exp;
    newP->next = NULL;

    if (head == NULL || exp > head->expon)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL && tmp->next->expon > exp)
        {
            tmp = tmp->next;
        }
        newP->next = tmp->next;
        tmp->next = newP;
    }
    return head;
}
poly_pointer create(poly_pointer head)
{
    int n;
    float coefficent;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficent for term %d: ", i + 1);
        scanf("%f", &coefficent);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coefficent, expo);
    }
    return head; // Bu satırı eklemeyi unutmayın
}
void printList(poly_pointer head)
{
    if (head == NULL)
        printf("No Polynomial.");
    else
    {
        poly_pointer tmp = head;
        while (tmp != NULL)
        {
            printf("%1.f ^ %d", tmp->coefficent, tmp->expon);
            tmp = tmp->next;
            if (tmp != NULL)
            {
                printf(" + ");
            }
            else
                printf("\n");
        }
    }
}
int main()
{
    poly_pointer head = NULL;
    printf("Enter polynomial\n");
    head = create(head);
    printList(head);
}