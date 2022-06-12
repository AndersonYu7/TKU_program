#include <stdio.h>
#include <stdlib.h>

int fibonscci(int );
void main()
{
    printf("how long:");
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        if(i==n) printf("%d",fibonscci(i));
        else printf("%d, ",fibonscci(i));
        
    }

    system("pause");
}

int fibonscci(int n)
{
    if(n==1 || n==2) return n-1;
    else return fibonscci(n-1) + fibonscci(n-2);
}