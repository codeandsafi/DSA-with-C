#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

void push(char a, struct stack * ptr){
    ptr->top++;
    ptr->arr[ptr->top] = a;
}

void pop(struct stack * ptr){
    ptr->top--;
}

int isMatch(char a, char b){
    if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')){
        return 1;
    }
    else{
        return 0;
    }
}

int parenthesisMatch(char * exp){

    struct stack * ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = strlen(exp);
    ptr->top = -1;
    ptr->arr = (char *)malloc( (sizeof(char)) * ptr->size);
    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i], ptr);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isMatch(ptr->arr[ptr->top], exp[i])){
                pop(ptr);
            }
            else{
                return 0;
            }
        }
    }
    if(ptr->top != -1){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    char * exp = "()[][]{}";
    int val = parenthesisMatch(exp);
    if(val == 1){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}