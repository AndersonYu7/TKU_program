#include <stdio.h>
#include <stdlib.h>

int fun(int row, int col);
void main()
{
    int num;
    scanf("%d",&num);

    for(int i=0;i<num;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",fun(i,j));
        }
        puts("");
    }

    system("pause");
}

int fun(int row, int col)
{
    if(row == col || col == 0) return 1;
    else return fun(row-1,col)+fun(row-1,col-1);
}