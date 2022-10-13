#include <stdio.h>

int main()
{
    int input_num;
    scanf("%d", &input_num);

    for(int i=1;i<=input_num;i++){
        for(int j=input_num-i;j>0;j--) printf(" ");
        for(int k=1;k<=i*2-1;k++) printf("*");
        puts("");
    }
    
    return 0;
}