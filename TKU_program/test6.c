#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[200] = "Students will learn how to use strtok from this exercise, please note that, upload your program before deadline.";
   char *token;
   
   /* get the first token */
   token = strtok(str,",");
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
    printf("%s\n", token);
    
    token = strtok(NULL,",");
   }
   
   system("pause");
   return(0);
}