//char strcat(char *s1, const *s2)
// 後面那個不會有變化

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10] = "test";
    char b[10] = " HI";

    strcat(a,b);
    puts(a);    //test HI
    puts(b);    // HI


    system("pause");
}