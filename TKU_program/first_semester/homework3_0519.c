#include <stdio.h>
#include <stdlib.h>

int fun(int ,int );
void main()
{
    int m, n;
    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    printf("coefficient value==> %d",fun(m,n));

    system("pause");
}

int fun(int row,int col){
    if(col==row || col==0) return 1;
    else return fun(row-1,col)+fun(row-1,col-1);
}