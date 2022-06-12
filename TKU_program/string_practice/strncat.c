//char strncat(char *s1, const chat *s2, size_t n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10] = "test";
    char b[10] = " HI Ian";

    strncat(a,b,2);
    puts(a);
    puts(b);

    char c[10] = "test";
    char d[10] = " HI Ian";

    strncat(c,&d[2],3); //I I
    puts(c);
    puts(d);
    
    system("pause");
}