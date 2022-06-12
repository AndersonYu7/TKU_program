#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M1[2][8];
    int M2[8][2];
    int M3[2][2] = {0};

//=========計算M1跟M2的數值===========
    int k = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<8;j++){
            M1[i][j] = 2*k+1;
            k++;
        }
    }
    k = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            M2[i][j] = 2*k+2;
            k++;
        }
    }
//====================================
//===========陣列相乘公式=============
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<8;k++){
                M3[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }
//====================================
//========印出M1、M2、M3的值==========
    printf("M1:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<8;j++){
            printf("%2d ",M1[i][j]);
            if(j==7) puts("");
        }
    }
    puts("");

    printf("M2:\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            printf("%2d ",M2[i][j]);
            if(j==1) puts("");
        }
    }
    puts("");

    printf("M3:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%2d ",M3[i][j]);
            if(j==1) puts("");
        }
    }
//====================================
    system("pause");
    return 0;
}
