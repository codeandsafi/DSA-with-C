#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int s = 0;
        int indexOfMin = i;
        int temp;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[indexOfMin] > arr[j])
            {
                s = 1;
                indexOfMin = j;
            }
        }
        if(s==1){
            temp = arr[i];
            arr[i] = arr[indexOfMin];
            arr[indexOfMin] = temp;
        }
    }
}
int main()
{
    int a[] = {1, 23, 12, 21, 33, 3, 5, 66, 78, 55, 90, 75, 110, 111, 112};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before applying Selection Sort:\n");
    printArray(a, n);
    printf("\nAfter applying Selection Sort:\n");
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}