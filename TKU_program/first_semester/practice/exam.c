#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 4
#define y 16
#define z 4

void initalM1(int M1[x][y], int judge);
void initalM2(int M2[y][z], int judge);
void multiple(int M1[x][y], int M2[y][z], int M3[y][z]);
void main()
{
    srand(time(NULL));
    int M1[x][y], M2[y][z], M3[y][z] = {0};
    int judge;
    scanf("%d",&judge);

    initalM1(M1, judge);
    initalM2(M2, judge);
    multiple(M1, M2, M3);

    printf("M1:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("\t%3d",M1[i][j]);
        }
        puts("");
    }
    printf("M2:\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            printf("\t%3d",M2[i][j]);
        }
        puts("");
    }
    printf("M3:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
            printf("\t%6d",M3[i][j]);
        }
        puts("");
    }

    system("pause");
}

void initalM1(int M1[x][y], int judge)
{
    int Max = 50;
    int min = 1;
    int k=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(judge == 1){
                M1[i][j] = 2*k+1;
                k++;
            }
            else M1[i][j] = rand()%(Max - min +1) + min;
        }
    }
}

void initalM2(int M2[y][z], int judge)
{
    int Max = 50;
    int min = 1;
    int k=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            if(judge == 1){
                M2[i][j] = 2*k+2;
                k++;
            }
            else M2[i][j] = rand()%(Max - min +1) + min;
        }
    }
}

void multiple(int M1[x][y], int M2[y][z], int M3[y][z])
{
    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
            for(int k=0;k<y;k++){
                M3[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }
}

