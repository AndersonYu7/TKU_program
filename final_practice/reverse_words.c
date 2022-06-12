#include <stdio.h>
#include <stdlib.h>

void reverse_words(int n);
void rev(char *x);
int main()
{

    // reverse_words(6);

    char a[100];
    rev(a);
    

    system("pause");
    return 0;
}

void reverse_words(int n)
{
    char words[n];
    if(n==1){
        scanf("%s",words);
        printf("%s",words);
    }

    else{
        scanf("%s",words);
        reverse_words(n-1);
        printf(" %s",words);
    }
}

void rev(char *x)
{
    char words[100];
    gets(words);

    static int i=0;
    if(words[i++]){
        rev(words+1);
        printf("%s ",words);
    }
}