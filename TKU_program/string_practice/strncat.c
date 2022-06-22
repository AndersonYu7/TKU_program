//char strncat(char *s1, const chat *s2, size_t n)
// 後面那個不會有變化

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10] = "test";
    char b[10] = " HI Ian";

    strncat(a,b,2);
    puts(a);    //test H
    puts(b);    // Hi Ian

    char c[10] = "test";
    char d[10] = " HI Ian";

    strncat(c,&d[3],4); //I I
    puts(c);    //test Ian
    puts(d);    // Hi Ian
    
    system("pause");
}