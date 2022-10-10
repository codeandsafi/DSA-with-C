#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node * top){
    if(top==NULL){
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

struct node * push(struct node * top, int value){
    if(isFull()==1){
        printf("Stack Overflow\n");
        return 0;
    }
    else{
        struct node * ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = value;
        ptr->next = top;
        return ptr;
    }
}

struct node * pop(struct node * top){
        if(isEmpty(top)==1){
            printf("Stack Underflow\n");
            return 0;
        }
        else{
            struct node * ptr = top;
            printf("The popped element is: %d\n", top->data);
            top = top->next;
            free(ptr);
            return top;
        }
    }



int main()
{
    struct node * top = NULL;
    
    top = push(top, 12);
    top = push(top, 2);
    top = push(top, 54);

    traversal(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);

    top = push(top, 12);
    top = push(top, 12);
    top = push(top, 41);
    top = push(top, 9);

    traversal(top);

    top = pop(top);
    top = pop(top);

    traversal(top);

    return 0;
}