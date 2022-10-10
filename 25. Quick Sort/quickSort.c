#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int a[], int low, int high){
    int pivot = a[low], i = low + 1, j = high, temp;

    do{

        while(a[i] <= pivot){
            i++;
        }

        while(a[j] > pivot){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }while(i<j);

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;    

        return j;
}

void quickSort(int a[], int low, int high){

    if(low<high){
        int index = partition(a, low, high);
        quickSort(a, low, index - 1);
        quickSort(a, index +1, high);
    }
}


int main()
{
    int a[] = {1, 23, 12, 21, 33, 3, 5, 66, 78, 55, 90, 75, 110, 111, 112};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before applying Quick Sort:\n");
    printArray(a, n);
    printf("\nAfter applying Quick Sort:\n");
    quickSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}