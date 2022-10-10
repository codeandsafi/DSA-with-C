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
    while (p != NULL)
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }
}

void deletionForValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->next = first;

    first->data = 16;
    first->next = second;

    second->data = 71;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 6;
    fourth->next = fifth;

    fifth->data = 65;
    fifth->next = NULL;

    printf("Before Deletion:\n");
    traversal(head);

    printf("After Deletion:\n");
    deletionForValue(head, 1);
        traversal(head);

    return 0;
}