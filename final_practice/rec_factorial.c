#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int main()
{
    for(int i=1;i<=10;i++){
        printf("%2d! = %d",i , factorial(i));
        puts("");
    }

    system("pause");
    return 0;
}

int factorial(int n)
{
    if(n==1) return 1;
    else{
        return n*factorial(n-1);
    }
}