#include <stdio.h>
#include <stdlib.h>

int check = 0;
int check2 = 0;

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

void traversal(struct queue * ptr){
    int i = ptr->f;
    while(i!=ptr->r){
        printf("The Element at Index %d is: %d\n", i, ptr->arr[i]);
        i = (i+1)%ptr->size;
    }
    printf("The Element at Index %d is: %d\n", i, ptr->arr[i]);
}

void enque(struct queue * ptr, int data){
    if(check == 1){
        printf("Queue Overflow\n");
    }
    else if((ptr->r + 1)%ptr->size == ptr->f){
        check = 1;
        ptr->arr[ptr->r] = data;
        check2 = 1;
    }
    else{
        ptr->arr[ptr->r] = data;
        ptr->r = (ptr->r + 1)%ptr->size;
    }
}

void deque(struct queue * ptr){
    if(ptr->f == ptr->r){
        printf("Queue Empty\n");
    }
    else{
        printf("The Dequeued Element is: %d\n", ptr->arr[ptr->f]);
        ptr->f = (ptr->f + 1)%ptr->size;
        printf("Front is at %d\n",ptr->f);
        check = 0;
        if(check2==1){
            check2 = 0;
            ptr->r = (ptr->r + 1)%ptr->size;
        }
    }
}

int main()
{
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(sizeof(int)*q->size);

    enque(q, 12);
    enque(q, 13);
    enque(q, 122);
    enque(q, 124);
    enque(q, 125);
    enque(q, 121);
    enque(q, 1);
    enque(q, 1234);
    enque(q, 12111);
    enque(q, 87);

    deque(q);
    deque(q);
    deque(q);

    
    enque(q, 29);
    enque(q, 729);
    enque(q, 829);
    enque(q, 19);
    enque(q, 19);

    traversal(q);
    return 0;
}