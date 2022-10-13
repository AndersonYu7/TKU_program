#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int M1[4][16];
    int M2[16][4];
    int M3[4][4] = {0};

    int judge;
    scanf("%d",&judge);

    if(judge==1){
        int k = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<16;j++){
                M1[i][j] = 2*k+1;
                k++;
            }
        }
        k = 0;
        for(int i=0;i<16;i++){
            for(int j=0;j<4;j++){
                M2[i][j] = 2*k+2;
                k++;
            }
        }
    }
    else{
        srand(time(NULL));
        int Max = 50;
        int min = 1;
        for(int i=0;i<4;i++){
            for(int j=0;j<16;j++){
                M1[i][j] = rand()%(Max-min+1)+min;
            }
        }

        for(int i=0;i<16;i++){
            for(int j=0;j<4;j++){
                M2[i][j] = rand()%(Max-min+1)+min;
            }
        }        
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<16;k++){
                M3[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }    

    printf("M1:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<16;j++){
            printf("%3d ",M1[i][j]);
            if(j==15) puts("");
        }
    }
    puts("");

    printf("M2:\n");
    for(int i=0;i<16;i++){
        for(int j=0;j<4;j++){
            printf("%3d ",M2[i][j]);
            if(j==3) puts("");
        }
    }
    puts("");

    printf("M3:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%6d ",M3[i][j]);
            if(j==3) puts("");
        }
    }

    system("pause");
    return 0;
}