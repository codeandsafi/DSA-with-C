#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node * insertAtIndex(struct node *head, int index, int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = d;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 34;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 765;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    printf("Before Insertion\n");
    traversal(head);

    head = insertAtIndex(head, 2, 476);

    printf("After Insertion\n");
    traversal(head);

    return 0;
}