//char *strtok(char *str, const char *delim)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char a[] = "This is a sentence with 7 tokens";

    char *tokenptr = strtok(a, " ");

    while(tokenptr != NULL){
        puts(tokenptr);
        tokenptr = strtok(NULL, " ");
    }
    
    
    system("pause");
}