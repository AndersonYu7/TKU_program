//char *srtcpy(chat *s1, const char *s2)
// 後面那個不會有變化
//直接取代
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[10];
    char b[10];

    strcpy(a,"Test");
    puts(a);    //Test
    strcpy(b,"TTTT");
    puts(b);    //TTTT
    strcpy(a,b);
    puts(a);    //TTTT
    puts(b);    //TTTT

    system("pause");
}