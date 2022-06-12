#include <stdio.h>
#include <stdlib.h>

void main()
{
    char string1[20] = "C'est La Vie";
    char string2[20];

    printf("please input a string:\n");
    scanf("%s",string2);
    printf("(a) the first string is :%s\n",string1);
    printf("(b) the second string is :%s\n",string2);

    system("pause");
}