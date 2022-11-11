#include <stdio.h>
#include <stdlib.h>

int n = 5;
int square_1(int *n)
{
    *n = *n * *n;
    return *n;
}

int square_2(int n)
{
    n = n*n;
    return n;
}

void square_3()
{
    n = n*n;
    printf("(e)%d", n);
}

void square_4(int n)
{
    n = n*n;
    printf("(f)%d\n", n);
}

int main(void)
{
    int i=0,j=0,n=3;
    i = square_1(&n);
    printf("(a)%d, (b)%d\n", i, n);
    j = square_2(n);

    printf("(c)%d, (d)%d\n", j, n);

    square_3();
    square_4(n);

    return 0;
}