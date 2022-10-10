#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 13;
    head->next = second;

    second->data = 16;
    second->next = third;

    third->data = 7765;
    third->next = NULL;

    traversal(head);

    return 0;
}