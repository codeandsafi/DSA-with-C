#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void bubbleSort(int *arr, int n){
    int temp,j;
    for(j=0;j<n-1;j++){
        
        for(int i=0;i<(n-1-j);i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    printf("Number of paases:%d\n",j);
}
void bubbleSortAdaptive(int *arr, int n){
    int temp, s, j;
    for(j=0;j<n-1;j++){
        s=0;
        for(int i=0;i<(n-1-j);i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                s=1;
            }
        }
        if(s==0){
            printf("Number of passes: %d\n",j);
                return;
            }
    }
    printf("Number of passes: %d\n",j);
}
int main()
{
    int a[]={23,12,21,33,3,5,55,64,78,90};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Before applying Bubble Sort:\n");
    printArray(a, n);
    // printf("\nAfter applying Bubble Sort (non adaptive):\n");
    // bubbleSort(a, n);
    // printArray(a, n);
    printf("\nAfter applying Bubble Sort (adaptive):\n");
    bubbleSortAdaptive(a, n);
    printArray(a, n);
    return 0;
}