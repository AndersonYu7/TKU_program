#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    char a;
    int num;//8
    char b; //8
    double num_;//8
}test;


int main()
{
    printf("%d", sizeof(test));

    return 0;
}