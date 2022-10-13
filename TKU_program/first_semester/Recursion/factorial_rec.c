#include <stdio.h>
#include <stdlib.h>

long long int factorial(int );
void main()
{
    for(int i=0;i<=20;i++){
        printf("%2d! = %lld\n",i,factorial(i));
    }

    system("pause");
}

long long int factorial(int n)
{
    if(n<=1) return n;
    else return n*factorial(n-1);
}