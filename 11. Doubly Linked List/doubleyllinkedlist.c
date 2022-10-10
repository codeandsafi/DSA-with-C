#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traversalBothDir(struct node *ptr)
{
    struct node *p = ptr;
    struct node *q;
    while (q != NULL)
    {
        if (p->next != NULL)
        {
            printf("Element : %d\n", p->data);
            p = p->next;
            q = p;
        }
        else
        {
            printf("Element : %d\n", q->data);
            q = q->prev;
        }
    }
}

void insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    struct node *q = p->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    ptr->next = p->next;
    ptr->prev = p;
    q->prev = ptr;
    p->next = ptr;
}

void deletionForVal(struct node *head, int val)
{
    struct node *p;
    struct node *q;
    struct node *r;
    p = head;
    q = head->next;
    r = q->next;
    while (q->data != val && r->next != NULL)
    {
        p = p->next;
        q = q->next;
        r = r->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        r->prev = p;
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

    head->data = 133;
    head->next = first;
    head->prev = NULL;
    first->data = 34;
    first->next = second;
    first->prev = head;
    second->data = 12;
    second->next = third;
    second->prev = first;
    third->data = 1223;
    third->next = fourth;
    third->prev = second;
    fourth->data = 1323;
    fourth->next = fifth;
    fourth->prev = third;
    fifth->data = 187;
    fifth->next = NULL;
    fifth->prev = fourth;

    printf("Before Insertion\n");
    traversalBothDir(head);

    // printf("After Insertion\n");
    // insertAtIndex(head, 12345, 2);
    // traversalBothDir(head);

    printf("After Deletion\n");
    deletionForVal(head, 12);
    traversalBothDir(head);

    return 0;
}