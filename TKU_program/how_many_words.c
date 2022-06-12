#include <stdio.h>
#include <stdlib.h>

int count(char , const char *);
void main()
{
    char c = 's', str[80] = "Mississippi sassafras";

    printf("The number of occurrences of %c in \" %s \" is %d\n",c,str,count(c,str));

    system("pause");
}

int count(char ch, const char *str)
{
    int ans;

    if(str[0] == '\0') ans = 0;
    else{
        if(ch == str[0]) ans = 1 + count(ch, &str[1]);
        else ans = count(ch, &str[1]);
    }

    return ans;
}