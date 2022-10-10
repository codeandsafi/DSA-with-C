#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    struct node *p = ptr->next;
    while (p != ptr)
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }
}

struct node * insertAtFirst(struct node * head, int data){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
    do{
        p = p->next;
    }while(p->next != head);
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct node * head;
    struct node * first;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;
    struct node * sixth;
    struct node * seventh;
    struct node * eigth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));
    eigth = (struct node *)malloc(sizeof(struct node));

    head->data = 133;
    head->next = first;
    first->data = 34;
    first->next = second;
    second->data = 12;
    second->next = third;
    third->data = 1223;
    third->next = fourth;
    fourth->data = 1323;
    fourth->next = fifth;
    fifth->data = 187;
    fifth->next = sixth;
    sixth->data = 32;
    sixth->next = seventh;
    seventh->data = 43;
    seventh->next = eigth;
    eigth->data = 133;
    eigth->next = head;

    printf("Before Insertion\n");
    traversal(head);

    printf("After Insertion\n");
    head = insertAtFirst(head, 12345);
    traversal(head);

    return 0;
}