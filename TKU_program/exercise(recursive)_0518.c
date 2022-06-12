#include <stdio.h>
#include <stdlib.h>

int fun_rec(int );
void main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fun_rec(n));

    system("pause");
}

int fun_rec(int n)
{
    return n == 1 ? 1 : n*fun_rec(n-1);

    // if(n == 1) return 1;
    // else return n*fun_rec(n-1);
}