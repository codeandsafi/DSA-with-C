#include <stdio.h>
int binarySearch(int a[], int size, int element){
    int high, low, mid;
    high = size - 1;
    low = 0;
    while(low<=high){
        mid = (high + low)/2;
        if(element==a[mid]){
            return mid;
        }
        if(element<a[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {2, 12, 13, 15, 17, 21, 32, 47, 99};
    int size = sizeof(a)/sizeof(a[0]);
    int result = binarySearch(a, size, 99);
    if(result==-1){
        printf("Element not found\n");
    }
    else{
        printf("The element is found at index %d", result);
    }
    return 0;
}