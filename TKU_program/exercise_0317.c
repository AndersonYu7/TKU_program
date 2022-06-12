#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[2][2] = {{1,2},
                   {2,3}};

    int b[2][3] = {{1,2,3},
                   {3,2,1}};
    
    int c[2][3] = {0};
    

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%2d ",c[i][j]);
            if(j==2) puts("");
        }
    }

    system("pause");
    return 0;
}