/*
使用linked list 存 equation (不想寫MAX~)
struct Data 存precedence跟數字
阿用stack不用queue是因為不想設*front跟*rear 
先進先出的特點 用反向stack代替

輸入部分:
用連續單一字元輸入並存入stack 然後再判斷數字是否 >9 跟 EOF
加空格或不加都可以

先將中置式轉為後置式
再計算後置式
AC(2ms, 56KB)
*/
#include <stdio.h>
#include <stdlib.h>

int ISP[8] = {0, 19, 12, 12, 13, 13, 13, 0};    //in the stack
int ICP[8] = {20, 19, 12, 12, 13, 13, 13, 0};   //input 

typedef enum{lparen, rparen, plus, minus, divide, times, mod, eos, operand}precedence;

typedef struct{
    precedence operator;
    int num;
}Data;

typedef struct stack *stack_ptr;
struct stack{
    Data data;
    stack_ptr link;
};

precedence get_token(char ch)
{
    switch(ch){
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
char back_topken(precedence token) //用於printStackNode()
{
    switch(token){
        case lparen : return '(';
        case rparen : return ')';
        case plus : return '+';
        case minus : return '-';
        case divide : return '/';
        case times : return '*';
        case mod : return '%';
        case eos : return ' ';
        default : return '0';
    }
}

void push(stack_ptr *top, Data data)
{
    stack_ptr temp = (stack_ptr)malloc(sizeof(struct stack));
    temp->data = data;
    temp->link = *top;
    *top = temp;
}

Data pop(stack_ptr *top)
{
    stack_ptr temp = *top;
    Data data;

    data = temp->data;
    *top = temp->link;
    free(temp);
    return data;

}

stack_ptr reverse(stack_ptr top)
{
    stack_ptr out = NULL;
    for(;top;top->link){        //將輸入的東西 反向給input stack ex 1 + 2 -> 2 + 1
        Data data = pop(&top);  //因為需要先進先出 但是stack為先進後出 阿我懶得用queue 所以反向就可達到先進先出的功用
        push(&out, data);    
    }
    return out;
}

stack_ptr input_string(FILE *fp)
{
    stack_ptr stdin_ = NULL, input = NULL;
    char ch;
    Data data;
    int num = -1;       //-1代表沒有數字進入
    int prev_num = -1;  //-1代表沒有數字進入
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        if(get_token(ch)==operand){ 
            if(prev_num==-1){   //代表為第一個輸入的數字
                num = ch - '0';
                prev_num = num;
            } else{ //代表此數超過10
                num*=10;             //前一個數進位
                prev_num = ch - '0'; //prev_num等於現在輸入
                num += prev_num;     //兩個相加   
            }
        } else{
            if(num>=0){ //字元輸入為符號時 判斷num是否存值，有的話push 然後再將字元push到stdin_
                data.num = num;
                data.operator = operand;
                push(&stdin_, data);
                num = -1;       //初始化
                prev_num = -1;  //初始化
            }
            data.operator = get_token(ch);
            data.num = -1;
            push(&stdin_, data);
        }
    }
    if(num>=0){ //push最後一個數字
        data.num = num;
        data.operator = operand;
        push(&stdin_, data);
    }
    for(;stdin_;stdin_->link){  //將輸入的空格刪掉
        Data data_pop = pop(&stdin_);
        if(data_pop.operator!=eos) push(&input, data_pop);
    }

    return input;
}

void printStackNode(stack_ptr top)
{
    printf("Stack Top\n");
    for(;top;top = top->link)
        if(top->data.operator==operand)
            printf("item_num: %d\n", top->data.num);
        else
            printf("item_num: %c\n", back_topken(top->data.operator));
    printf("Stack Buttom\n\n");
}

stack_ptr postfix(stack_ptr input)
{
    stack_ptr output = NULL;

    stack_ptr operator = (stack_ptr)malloc(sizeof(struct stack));
    operator->data.operator = eos;  //需要多一個空格去判斷
    operator->data.num = 0;
    operator->link = NULL;
    precedence token;

    for(;input;input->link){
        token = input->data.operator;
        if(token == operand){   //假如是數字 直接Push進output
            Data data = pop(&input);
            push(&output, data);
        } else if(token == rparen){ //遇到')' 將在'('之間的operator push進output
            Data data_operator;
            while(operator->data.operator!=lparen){
                data_operator = pop(&operator);
                push(&output, data_operator);
            }
            data_operator = pop(&operator); //將'('移除
            data_operator = pop(&input);    //將')'移除
            
        } else{ 
            while(ISP[operator->data.operator] >= ICP[token]){
                Data data_operator = pop(&operator);
                push(&output, data_operator);
            }
            Data data_all = pop(&input);
            push(&operator, data_all);
        }
    }
    Data data_operator = pop(&operator);
    while(data_operator.operator!=eos){ //將剩下的operator push進output
        push(&output, data_operator);
        data_operator = pop(&operator);
    }
    output = reverse(output);
    free(operator);
    return output;
}

int cal_ans(stack_ptr equation)
{
    int op1 = 0, op2 = 0, ans = 0;
    stack_ptr temp = NULL; //多一個stack去存數字 假如遇到operator再將temp pop出兩個數字做運算
    for(;equation;equation->link){
        if(equation->data.operator == operand){
            Data data = pop(&equation);
            push(&temp, data);
        } else{
            Data num = pop(&temp);
            num.operator = operand;
            op2 = num.num;  //把兩個數字提出來去做運算
            num = pop(&temp);
            op1 = num.num;
            Data operator_token = pop(&equation);
            switch(operator_token.operator){    //判斷運算符號做運算
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
            num.num = ans;
            push(&equation, num);
            if(temp){   //把剩餘放在temp的數字丟回equation
                for(;temp;temp->link){
                    Data data = pop(&temp);
                    push(&equation, data);
                }
            }
            if((equation->link)==NULL) break;
        }
    }
    free(temp);
    return equation->data.num;

}

int main(int argc, char **argv)
{   
    while(1){   //假如輸入不是EOF 無限執行
        stack_ptr input = NULL;
        printf("The equation: ");
        input = input_string(stdin);
        if(input){  //假如輸入為EOF -> input == NULL
            stack_ptr output = postfix(input);
            printf("ANS: %d\n", cal_ans(output));
        } else break;
    }
    return 0;
}