//char strcat(char *s1, const *s2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10] = "test";
    char b[10] = " HI";

    strcat(a,b);
    puts(a);
    puts(b);


    system("pause");
}