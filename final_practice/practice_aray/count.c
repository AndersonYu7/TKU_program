#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int how_many(char c, const char *arr);
int main()
{
    char c = 's', str[80] = "Mississippi sassafras";

    printf("The number of occurrences of %c in \" %s \" is %d\n", c, str, how_many(c, str));

    system("pause");
    return 0;
}

int how_many(char c, const char *arr)
{
    int count = 0;

    if(arr[0] == '\0') return count;

    else{
        if(arr[0] == c) return 1 + how_many(c, &arr[1]);
        else return how_many(c, &arr[1]);
    }
}