#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueueAtEnd(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element at End: %d\n", val);
    }
}

void enqueueAtFront(struct queue *q, int val){
    if(q->f == -1){
        printf("Enqueue at Front Cannot Be Done\n");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
        printf("Enqued Element at Front: %d\n", val);
    }
}

 
void dequeueAtFront(struct queue *q){
    if(isEmpty(q)){
        printf("Dequeue at Front Cannot be Done. This Queue is empty\n");
    }
    else{
        q->f++;
        printf("Dequeueing Element at Front: %d\n",q->arr[q->f]);
    }
}

void dequeueAtEnd(struct queue *q){
    if(isEmpty(q)){
        printf("Dequeue at End Cannot be Done. This Queue is empty\n");
    }
    else{
        printf("Dequeueing Element at End: %d\n",q->arr[q->r]);
        q->r--;
    }
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueueAtEnd(&q, 12);
    enqueueAtEnd(&q, 15);
    enqueueAtEnd(&q, 1); 
    dequeueAtEnd(&q);
    dequeueAtFront(&q);
    dequeueAtFront(&q);
    // dequeueAtFront(&q);
    enqueueAtFront(&q, 2);
    enqueueAtFront(&q, 278);
    
 
    return 0;
}