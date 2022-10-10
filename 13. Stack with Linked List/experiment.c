#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * top = NULL;

void traversal(struct node * ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node * ptr){
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
    free(ptr);
}

 void push(struct node * p, int value){
    if(isFull()==1){
        printf("Stack Overflow\n");
    }
    else{
        struct node * ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = value;
        ptr->next = p;
        top = ptr;
    }
}

void * pop(struct node * p){
        if(isEmpty(p)==1){
            printf("Stack Underflow\n");
            return 0;
        }
        else{
            struct node * ptr = p;
            printf("The popped element is: %d\n", p->data);
            top = p->next;
            free(ptr);
        }
    }



int main()
{   
    push(top, 12);
    push(top, 2);
    push(top, 54);

    traversal(top);

    pop(top);
    // top = pop(top);
    // top = pop(top);
    // top = pop(top);

    // top = push(top, 12);
    // top = push(top, 12);
    // top = push(top, 41);
    // top = push(top, 9);

    // traversal(top);

    // top = pop(top);
    // top = pop(top);

    traversal(top);

    return 0;
}