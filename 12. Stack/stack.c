#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int t;
    int * arr;
};

int isEmpty(struct stack * p){
    if(p->t == (-1)){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->t == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int value){
    if(isFull(ptr)==1){
        printf("Stack Overflow\n");
    }
    else{
        ptr->t++;
        ptr->arr[ptr->t] = value;
    }
}

void pop(struct stack * ptr){
    if(isEmpty(ptr)==1){
        printf("The Stack is Empty\n");
    }
    else{
        printf("Element Popped: %d\n", ptr->arr[ptr->t]);
        ptr->t--;
    }
}

int peek(struct stack* ptr, int i){
    int arrayInd = ptr->t -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int top(struct stack * ptr){
    return ptr->arr[ptr->t];
}

int bottom(struct stack * ptr){
    return ptr->arr[0];
}

int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 5;
    st->t = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));

    push(st, 6);
    printf("%d\n",st->t);
    push(st, 5);
    printf("%d\n",st->t);
    push(st, 4);
    printf("%d\n",st->t); 
    push(st, 3);
    printf("%d\n",st->t);
    push(st, 2);
    printf("%d\n",st->t);
    push(st, 1);
    printf("%d\n",st->t);
    pop(st);
    printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // pop(st);
    // printf("%d\n",st->t);
    // return 0;

    for (int j = 1; j <= st->t + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(st, j));
    }


    printf("The top most value is: %d\n", top(st));
    printf("The bottom most value is: %d\n", bottom(st));
}