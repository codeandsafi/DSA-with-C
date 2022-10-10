#include <stdio.h>

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
}

int indInsert(int a[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {12, 23, 33, 47, 49, 50};
    int size = 6;
    int element = 45, index = 3;
    printarray(arr, size);
    printf("After Insertion\n");
    int val = indInsert(arr, size, element, 100, index);
    if (val == 1)
    {
        size += 1;
        printarray(arr, size);
    }
    else
    {
        printf("Insertion not possible");
    }
    return 0;
}