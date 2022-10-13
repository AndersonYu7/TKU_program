#include <stdlib.h>
#include <stdio.h>
#define n 24

void fun(int b[],int c);
void fun(int b[],int c);

int main()
{
    int a[n];

    fun(a,n);

    for(int i=0;i<n;i++){
        // printf("%d\n",a[i]);
        printf("%d %p %p",a[i],a[i],&a[i]);
        puts("");
    }


    
    system("pause");
    return 0;
}

void fun(int b[],int c)
{
    for(int i=0;i<c;i++){
        b[i] = i+1;
    }
}

void fun2(int a,int b)
{
    a+=5;
    b+=10;
}