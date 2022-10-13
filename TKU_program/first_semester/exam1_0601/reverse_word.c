#include <stdio.h>
#include <stdlib.h>

void reverse(int );
void main()
{
    reverse(6);

    system("pause");
}

void reverse(int n)
{
    char str[80];
    if(n==1){
        scanf("%s",str);
        printf("%s",str);
    }

    else{
        scanf("%s",str);
        reverse(n-1);
        printf(" %s",str);
    }
}
