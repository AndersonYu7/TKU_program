//LIFO (Last In First Out，後入先出)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 101
#define true 1
#define false 0

typedef struct{
    int key;
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

int isFull(element stack[], int maxStackSize)
{
    maxStackSize = MAX_STACK_SIZE;
    if(top!=-1 && top==maxStackSize) return true;
    return false;
}

void stackFull()
{
    fprintf(stderr, "stack is full, and it can not push any element");
    exit(EXIT_FAILURE);
}

element pop()
{
    if(top == -1){
        fprintf(stderr, "stack is empty, and it can not pop any element");
        exit(EXIT_FAILURE);
    }  

    return stack[top--];
}

void push(element item)
{
    if(top >= MAX_STACK_SIZE-1)
        stackFull();

    stack[++top] = item; 
}

int main()
{
    element item;

    char fuc[5];
    while(scanf("%s", &fuc)){
        int pop_ = false;
        int push_ = false;

        if(!strcmp(fuc, "pop")) pop_ = true;
        else if(pop_==false && !strcmp(fuc, "push")) push_ = true;
        else if(!strcmp(fuc, "q")) exit(EXIT_FAILURE);

        if(pop_ && !push_) pop();
        else if(push_ && !pop_){
            scanf("%d", &item.key);
            push(item);
        }

        for(int i = top;i>=0;i--) printf("%d\n", stack[i].key);
    }


    return 0;
}