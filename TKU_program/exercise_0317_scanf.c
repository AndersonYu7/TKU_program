#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[2][2],b[2][3],c[2][3] = {0};

    printf("ARRAY A:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("ARRAY B:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    printf("ARRAY C:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){       //array a_row
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