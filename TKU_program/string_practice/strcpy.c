//char *srtcpy(chat *s1, const char *s2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10];
    char b[10];

    strcpy(a,"Test");
    puts(a);
    strcpy(b,"TTTT");
    puts(b);
    strcpy(a,b);
    puts(a);
    puts(b);

    system("pause");
}