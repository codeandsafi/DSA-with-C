#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertionSort(int *arr, int n)
{
    int temp;
    for (int j = 1; j < n; j++)
    {
        int key, i;
        key = arr[j];
        i = j - 1;
        while (key < arr[i] && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}
int main()
{
    int a[] = {23, 12, 21, 33, 3, 5, 66, 78, 55, 90, 75};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before applying Insertion Sort:\n");
    printArray(a, n);
    printf("\nAfter applying Insertion Sort:\n");
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}
