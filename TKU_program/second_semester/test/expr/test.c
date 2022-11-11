#include <stdio.h>
#include <stdlib.h>

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

typedef enum{lparen, rparen, plus, minus, times, divides, mod, eos, operand} precedence;

char expr[10] = {'a', '*', '(', 'b', '+', 'c', ')', '*', 'd', eos};

precedence get_token(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol){
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '*' : return times;
        case '/' : return divides;
        case '%' : return mod;
        case ' ' : return eos;
        default : return operand;

    }
}


void postfix(void)
{
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;
    for(token = get_token(&symbol, &n); token!=eos; token = get_token(&symbol, &n)){

    }
}



int main()
{
    
    
    
    return 0;
}