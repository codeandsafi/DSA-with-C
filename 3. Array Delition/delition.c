#include <stdio.h>

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
}

int indDelete(int a[], int size, int index)
{
    for (int i = index; i < size; i++)
    {
        a[i] = a[i + 1];
    }
    return 1;
}

int main()
{
    int arr[100] = {12, 23, 33, 47, 49, 50};
    int size = 6;
    int index = 3;
    printarray(arr, size);
    printf("After Deletion\n");
    indDelete(arr, size, index);
    size -= 1;
    printarray(arr, size);
    return 0;
}