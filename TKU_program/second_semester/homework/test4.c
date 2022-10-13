#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int size;
    int *array;
}Array;


int main()
{
    Array arr;
    scanf("%d", &arr.size);

    arr.array = (int*)malloc(sizeof(int)*arr.size);

    for(int i=0;i<arr.size;i++) arr.array[i] = i+1;

    printf("size: %d\n", arr.size);
    for(int i=0;i<arr.size;i++) printf("%d", arr.array[i]);
    
    
    free(arr.array);
    return 0;
}