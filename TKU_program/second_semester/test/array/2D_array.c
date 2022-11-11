#include <stdlib.h>
#include <stdio.h>

#define MALLOC(p, s) \
    if(!((p)=malloc(s))){ \
        fprintf(stderr, "insufficient memory"); \
        exit(EXIT_FAILURE); \
    }
/*
    stderr -> 用於紀錄執行時的錯誤或除錯資訊 使用fprintf
    其他例子: stdin, stdout

    EXIT_FAILURE 可以作為exit()函式使用 表示沒有成功執行一個程序
    EXIT_SUCCESS 作為exit()函式使用 表示成功執行一個程序

*/
int main()
{
    int row, col, **x;

    printf("Enter the size of 2D-array: ");
    scanf("%d %d", &row, &col);

    if(row<1 || col<1){
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }
    MALLOC(x, row*sizeof(*x));
    for(int i =0;i<col;i++) MALLOC(x[i], col*sizeof(**x));

    printf("The content of X is: %p\n", x);
    printf("The memory address of the first row of X is: %p\n", &x[0]);
    printf("The content of X[0] is: %p\n", x[0]);
    printf("The memory address of the first element in X is: %p\n", &x[0][0]);
    printf("The content of X[1] is: %p\n", x[1]);
    printf("The memory address of first element in second row of X is %p\n", &x[1][0]);
    printf("The content of X[2] is: %p\n", x[2]);
    printf("The memory address of first element in third row of X is %p\n", &x[2][0]);
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            x[i][j] = i*row+j;
            printf("x[%d][%d]=%d\t", i, j, x[i][j]);
        }
        puts("");
    }

    return 0;
}