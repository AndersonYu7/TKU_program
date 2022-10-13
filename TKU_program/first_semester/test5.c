#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *inp;
    inp = fopen("text.txt","r");

    char string[3][50];
    int i=0;
    while(fgets(string[i],50,inp)!=NULL) i++;

    for(int i=0;i<3;i++){
        char *tokenptr = strtok(string[i], " ,.");
        while(tokenptr != NULL){
            printf("%s\n",tokenptr);
            tokenptr = strtok(NULL, " ,.");
        }
    }
    
    system("pause");
}