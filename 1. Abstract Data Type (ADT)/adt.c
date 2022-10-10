#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize * sizeof(int));
}

void setVal(struct myArray *a){
    int n;
    // for(int i=0; i , a->used_size; i++){
    //     printf("Enter element %d", i);
    //     scanf("%d", &n);
    //     (a->ptr)[i]=n;
    // }

    for(int i=0; i < a->used_size; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", &(a->ptr)[i]);
    }
}

// void show(struct myArray *a){
//     for(int i=0; i < a->used_size; i++){
//         printf("%d\n", (a->ptr)[i]);
//     }
// }

void get(struct myArray *a, int index){
    printf("The %d number element is %d", index + 1, (a->ptr)[index]);
}

int main()
{
    struct myArray marks;
    int i,n;
    createArray(&marks, 10, 5);
    printf("Now using setVal\n");
    setVal(&marks);
    // printf("Now using show\n");
    // show(&marks);
    printf("Give index of the element to be printed\n");
    scanf("%d",&i);
    n=i-1;
    get(&marks, n);
    return 0;
}