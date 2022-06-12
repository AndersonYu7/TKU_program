//char *strncpy(char *s1, const char *s2, size_t n)
//取到 s2[n-1]
//取完的值會回傳到s1的後面
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10] = "aaaa";
    char b[10] = "Andersonyu";

    strncpy(a,b,3);
    puts(a);
    puts(b);
    
    char c[10];
    char d[10] = "Andersonyu";

    strncpy(c,&d[5],3);     //son
    puts(c);
    puts(d);

    
    system("pause");
}