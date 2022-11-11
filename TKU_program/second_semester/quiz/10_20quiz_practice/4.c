#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
    if(!((p)=malloc(s))){ \
        fprintf(stderr, "insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

int fib(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else return n-1 + n-2;
}

int main(void)
{
    int n, **array;
    printf("input the num\n");
    scanf("%d", &n);
    MALLOC(array, n*sizeof(*array));

    for(int i=0;i<n+1;i++)
        MALLOC(array[i], n*sizeof(**array));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<i+1;j++){
            array[i][j] = fib(j+1);
            printf("%d ", array[i][j]);
        }
        puts("");
    }
}