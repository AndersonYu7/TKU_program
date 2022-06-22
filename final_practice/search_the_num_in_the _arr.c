#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int where(int arr[], int size, int num);
int main()
{
    srand(time(NULL));
    int arr[10];
    for(int i=0;i<10;i++) arr[i] = rand()%(50 - 1) + 1;

    printf("The array is : ");
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
    printf("\nPlease input a number you want to search\n> ");
    int num;
    scanf("%d",&num);

    int where_num = where(arr, 10, num);

    if(where_num != -1) printf("the number is found at index : %d\n", where_num) ;
    else printf("the numbr is not found\n");

    system("pause");
    return 0;
}

int where(int arr[], int size, int num)
{
    int judge = -1;
    for(int i=0;i<size;i++){
        if(arr[i] == num) judge = i;
    }

    return judge;
}