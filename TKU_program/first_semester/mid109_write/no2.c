#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x[]={2,3,5,7};
    int *y;

    printf("the start address of array x is:%p\n",x);   //22FE30
    printf("(a) the value of &x is %p\n",&x);
    printf("(b) the address of x[0] is %p\n",&x[0]);
    printf("(c) the address of x[1] is %p\n",&x[1]);
    printf("(d) the value of x[2] is %d\n",x[2]);
    y=&x[2];
    printf("(e) the value of y is %p\n",y);
    printf("(f) the value of *y is %d\n",*y);

    system("pause");
}