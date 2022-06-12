#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *find_caps(char *caps, const char *str);
int main()
{
    char str[100];
    gets(str);

    char caps[strlen(str)];
    printf("%s",find_caps(caps, str));

    system("pause");
    return 0;
}

char *find_caps(char *caps, const char *str)
{
    char restcaps[100];

    if(str[0] == '\0') caps[0] = '\0';
    else{
        if(isupper(str[0])) sprintf(caps, "%c%s", str[0], find_caps(restcaps, &str[1]));
        else find_caps(caps, &str[1]);
    }

    return caps;
}