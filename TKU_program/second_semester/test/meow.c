#include <stdlib.h>
#include <stdio.h>

#define MALLOC(p,s) \
            if(!((p)=malloc(s))){ \
                fprintf(stderr, "moew"); \
                exit(EXIT_FAILURE); \
            }


int fib(int n)
{
    if(n==0||n==1) return n;
    else return fib(n-1) + fib(n-2);
}

int main()
{
    int **array, n;
    printf("input: ");
    scanf("%d", &n);

    MALLOC(array, n*sizeof(*array));
    for(int i=0;i<n;i++) 
        MALLOC(array[i], (i+1)*sizeof(**array));

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            array[i][j] = fib(j+1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ", array[i][j]);
        }
        puts("");
    }

    return 0;
}