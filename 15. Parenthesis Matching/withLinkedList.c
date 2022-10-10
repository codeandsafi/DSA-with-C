#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node * next;
};

struct node * top = NULL;

int isEmpty(struct node * tp){
    if(tp==NULL){
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

void push(struct node * tp, char value){
    if(isFull()==1){
        printf("Stack Overflow\n");
    }
    else{
        struct node * ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = value;
        ptr->next = tp;
        top = ptr;
    }
}

void pop(struct node * tp){
        if(isEmpty(tp)==1){
            printf("Stack Underflow\n");
        }
        else{
            struct node * ptr = tp;
            top = tp->next;
            free(ptr);
        }
    }

void parenthesisMatching(char * exp){
    int val = 0;
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(top, '(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(top)==1){
                val = 1;
                break;
            }
            else{
                pop(top);
            }
        }
    }
    if(isEmpty(top)==0 || val==1){
        printf("Parenthesis are not matched\n");
    }
    else if(isEmpty(top)==1){
        printf("Parenthesis are matched\n");
    }
}

int main()
{
    char * exp = "()(()))";
    parenthesisMatching(exp);
    return 0;
}