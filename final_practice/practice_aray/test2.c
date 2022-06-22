#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = 5;
    int *b = &a;
    printf("%d\n",*b);

    int *c;
    c = &a;
    printf("%d\n",*c);


    system("pause");
    return 0;
}

