#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};

void traversal(struct node *ptr){
    struct node * p = ptr->next;
    int i = 1;
    while(p!=NULL){
        printf("Element %d : %d\n",i,p->data);
        p = p->next;
        i++;
    }
}

void insertInBetween(struct node *first, struct node *second, int d){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = second;
    first->next = ptr;
};

int main()
{
    struct node * head;    
    struct node * second;    
    struct node * third;    
    struct node * fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));


    //head->data = 34;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 765;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    printf("Before Insertion\n");
    traversal(head);

    insertInBetween(second, third, 476);

    printf("After Insertion\n");
    traversal(head);

    return 0;
}