#include <stdio.h>
#include <stdlib.h>

int how_many_words(char charcter, const char *str);
int main()
{
    char c = 's', str[80] = "Mississippi sassafras";

    printf("The number of occurrences of %c in \" %s \" is %d\n", c, str, how_many_words(c, str));

    system("pause");
    return 0;
}

int how_many_words(char charcter, const char *str)
{
    if(str[0] == '\0') return 0;
    else{
        if(charcter == str[0]) return 1 + how_many_words(charcter, &str[1]);
        else return how_many_words(charcter, &str[1]);
    }
}