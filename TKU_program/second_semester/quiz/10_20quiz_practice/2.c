#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x[4] = {1, 2, 3, 4};
    int y[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    int *xptr = x;
    int *yptr = y;

    printf("(a)=%p\n", &x);
    printf("(b)=%p\n", &x[2]);
    printf("(c)=%p\n", &xptr);
    printf("(d)=%p\n", *xptr++);
    printf("(e)=%p\n", *xptr);
    printf("(f)=%p\n", y);
    printf("(g)=%p\n", y[2]);
    printf("(h)=%d\n", **(y+3));
    printf("(i)=%p\n", yptr);
    printf("(j)=%d\n", *(yptr));
    printf("(k)=%d\n", *(*y)+2);
    printf("(l)=%p\n", *y);
    printf("(m)=%p\n",&y[0][0]);
    
    return 0;
}