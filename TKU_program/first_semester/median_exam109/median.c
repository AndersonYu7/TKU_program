#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define row 4
#define column 16
#define Max 50
#define min 1

void matrixmultiple(int [row][column], int [column][row], int [row][row]);
float average(int M1[row][column]);
float standard_deviation_M1(int M1[row][column], float avg);
int main()
{   
    srand(time(NULL));
    int M1[row][column], M2[column][row], M3[row][row];
    int judge;
    printf("please input your selection>>\n");
    printf("press 1 for generating regular content of 2D-array\n");
    printf("press 2 for generating random content of 2D-array\n");
    scanf("%d",&judge);
//======================initalization M1~M3=============================
    int k1 = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(judge == 1) M1[i][j] = 2*k1+1;
            else M1[i][j] = rand()%(Max - min + 1) + min;
            k1++;
        }
    }

    int k2 = 0;
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            if(judge == 1) M2[i][j] = 2*k2+2;
            else M2[i][j] = rand()%(Max - min + 1) + min;
            k2++;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            M3[i][j] = 0;
        }
    }
//====================================================================
    matrixmultiple(M1,M2,M3);
//==============================display===============================
    printf("M1:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("\t%3d",M1[i][j]);
        }
        puts("");
    }
    printf("M2:\n");
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            printf("\t%3d",M2[i][j]);
        }
        puts("");
    }
    printf("M3:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            printf("\t%6d",M3[i][j]);
        }
        puts("");
    }
    printf("\n\n");

    printf("The mean value of M1 array is:%.2f\n\n",average(M1));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%6.2f",(float)M1[i][j]-average(M1));
        }
        puts("");
    }
    puts("");
    printf("The std value of M1 array is: %.2f",standard_deviation_M1(M1,average(M1)));
//=====================================================================
    system("pause");
    return 0;
}

void matrixmultiple(int M1[row][column], int M2[column][row], int M3[row][row])
{
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            for(int k=0;k<column;k++){
                M3[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }
}

float average(int M1[row][column])
{
    int sum = 0;

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            sum += M1[i][j];
        }
    }

    return (float)sum/(row*column);
}

float standard_deviation_M1(int M1[row][column], float avg)
{
    float S;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            S += pow(M1[i][j]-avg,2);
        }   
    }
    S/=row*column;
    
    return sqrt(S);
}