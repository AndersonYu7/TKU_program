#include<stdio.h>
#include<stdlib.h>

int main()
{
int n;
printf("Please input a number\n");
scanf("%d",&n);

printf("====Pascal's triangle====\n");
for(int row=1; row<=n; row++){
    int a=1;
    for(int i=1; i<=row; i++){
        printf("%d ",a);
        a = a * (row-i)/i;
    }
    printf("\n");
}
    system("pause");
    return 0;
}