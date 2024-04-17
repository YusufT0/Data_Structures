#include <stdio.h>

void Heapify(int arr[], int size, int i)
{
    int tmp;
    int left = 2 * i;
    int right = (2 * i) + 1;
    if (arr[left] > arr[right] && left <= size)
    {
        if (left > i)
        {
            tmp = arr[i];
            arr[i] = arr[left];
            arr[left] = tmp;
            Heapify(arr, size, left);
        }
    }
    else
    {
        if (arr[right] > arr[i] && right <= size)
        {
            tmp = arr[i];
            arr[i] = arr[right];
            arr[right] = tmp;
            Heapify(arr, size, right);
        }
    }
}

void MaxHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
        Heapify(arr, n, i);
}

void Sort(int arr[], int size)
{
    int i, t, left, right;
    for (i = size; i >= 2; i--)
    {
        t = arr[1];
        arr[1] = arr[i];
        arr[i] = t;
        size--;
        Heapify(arr, size, 1);
    }
}
void printer(int arr[])
{
    for (int i = 1; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {0, 23, 54, 35, 78, 42, 12, 18};
    MaxHeap(arr, 7);
    printer(arr);
    printf("\n");
    Sort(arr, 7);
    printer(arr);
}