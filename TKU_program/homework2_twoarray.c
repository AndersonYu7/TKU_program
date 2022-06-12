#include <stdio.h>
#include <stdlib.h>

int main()
{
//===========================輸入有幾層=================================
    int n;
    printf("Please input a number\n");
    scanf("%d",&n);
//======================================================================
//======================Pascal's Triangle 運算==========================
    int array[n][n];
    for(int i=0;i<n;i++){
        array[i][0] = 1;
        for(int j=1;j<=i;j++){
            if(j!=i) array[i][j] = array[i-1][j]+array[i-1][j-1];
            else array[i][i] = 1;
        }
    }
//======================================================================
//======================印出Pascal's Triangle===========================
    printf("====Pascal's Triangle====\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",array[i][j]);
        }
        puts("");
    }
//======================================================================
    system("pause");
    return 0;
}