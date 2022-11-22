/*
需要改成queue 因為先進先出 
stack 改成 int data 跟 precedence type 跟 link 用意為可以計算9以上的數字
*/

#include <stdio.h>
#include <stdlib.h>

int ISP[8] = {0, 19, 12, 12, 13, 13, 13, 0};    //in the stack
int ICP[8] = {20, 19, 12, 12, 13, 13, 13, 0};   //input 

typedef struct stack *stack_ptr;
struct stack{
    char item;
    stack_ptr link;
};

typedef enum{lparen, rparen, plus, minus, divide, times, mod, eos, operand}precedence;
precedence get_token(stack_ptr top)
{
    char symbol = top->item;
    switch(symbol){
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case ' ' : return eos;
        default : return operand;
    }
}

void printStackNode(stack_ptr top)
{
    printf("Stack Top\n");
    for(;top;top = top->link)
        printf("item: %c\n", top->item);
    printf("Stack Buttom\n\n");
}

void push(stack_ptr *top, char item)
{
    stack_ptr temp = (stack_ptr)malloc(sizeof(struct stack));

    temp->item = item;
    temp->link = *top;
    *top = temp;
    
}

char pop(stack_ptr *top)
{
    stack_ptr temp = *top;
    char item;

    item = temp->item;
    *top = temp->link;
    free(temp);
    return item;

}

stack_ptr input_string(FILE *fp)
{
    stack_ptr stdin_ = NULL, input = NULL;
    char ch;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        push(&stdin_, ch);
    }
    for(;stdin_;stdin_->link){
        char item = pop(&stdin_);
        if(item!=' ') push(&input, item);
    }

    return input;
}

stack_ptr postfix(stack_ptr input)
{
    stack_ptr output = NULL;

    stack_ptr operator = (stack_ptr)malloc(sizeof(struct stack));
    operator->item = ' ';
    operator->link = NULL;
    precedence token;

    for(;input;input->link){
        token = get_token(input);
        if(token == operand){
            char item = pop(&input);
            push(&output, item);
        } else if(token == rparen){
            char item2;
            while(get_token(operator)!=lparen){
                item2 = pop(&operator);
                push(&output, item2);
            }
            item2 = pop(&operator);
            item2 = pop(&input);
            item2 = 0;
            
        } else{ 
            while(ISP[get_token(operator)] >= ICP[token]){
                char item3 = pop(&operator);
                push(&output, item3);
            }
            char item4 = pop(&input);
            push(&operator, item4);
        }
    }
    char item5 = pop(&operator);
    while(item5!=' '){
        push(&output, item5);
        item5 = pop(&operator);
    }

    return output;
}   

stack_ptr reverse(stack_ptr top)
{
    stack_ptr out = NULL;
    for(;top;top->link){        //將輸入的東西 反向給input stack ex 1 + 2 -> 2 + 1
        char item2 = pop(&top); //用意為在pop時需要從前面的輸入開始pop 不反過來會變成從最後一個輸入開始
        push(&out, item2);
    }
    return out;
}

char ans(stack_ptr input)    //問題點: 可能會超過9所以 數字需要改為int 以及 改用queue
{
    char operator;
    int op1, op2, ans = 0;;
    stack_ptr temp = NULL;
    for(;input;input->link){
        if(get_token(input)==operand){
            char item = pop(&input);
            push(&temp, item);
        } else{
            op2 = (int)pop(&temp) - '0';
            op1 = (int)pop(&temp) - '0';
            precedence token = get_token(input);
            pop(&input);
            switch (token){
                case plus:
                    ans = op1 + op2;
                    break;
                case minus:
                    ans = op1 - op2;
                    break;
                case times:
                    ans = op1 * op2;
                    break;
                case divide:
                    ans = op1 / op2;
                    break;
                case mod:
                    ans = op1 % op2;
                    break;
            }
            ans = ans + '0';
            push(&input, (char)ans);
            if(temp){
                for(;temp;temp->link){
                    char item2 = pop(&temp);
                    push(&input, item2);
                }
            }   
            if((input->link->link)==NULL) break;
        }
    }
    return input->item;
}

int main()
{
    stack_ptr top;
    top = NULL;
    char item;

    // char c;
    // while(1){   //need space
    //     scanf("%c", &item);
    //     push(&top, item);
    //     if((c=getchar())=='\n')
    //         break;
    // }

    stack_ptr input = NULL;
    stack_ptr top2 = NULL;
    stack_ptr output = NULL;

    // input = reverse(top);   //讓輸入的stack反過來 因為需要先進先出 懶得用queue
    input = input_string(stdin);
    top2 = postfix(input);
    push(&top2, ' ');
    output = reverse(top2); //同理 所以將output反過來

    char Ans = ans(output);
    printf("The ans = %c", Ans);

    return 0;
}