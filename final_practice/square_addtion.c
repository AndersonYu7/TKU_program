#include <stdlib.h>
#include <stdio.h>

int fun(int n);
int main()
{
    printf("%d",fun(4)); // ans = 30 

    system("pause");
    return 0;
}

int fun(int n)
{
    if(n == 0 || n==1) return n;
    else return fun(n-1) + n*n;
}