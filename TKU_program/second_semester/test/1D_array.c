#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
    if(!((p)=malloc(s))){ \
        fprintf(stderr, "insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

int main()
{
    int n, *list;
    printf("Enter the size of array:");
    scanf("%d", &n);
    if(n<1){
        fprintf(stderr, "improper value of n\n");
        exit(EXIT_FAILURE);
    }

    MALLOC(list, n*sizeof(*list));

    for(int i=0;i<n;i++){
        list[i] = i;
        printf("list[%d]=%d\t", i, list[i]);
    }

    return 0;

}