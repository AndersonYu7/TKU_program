#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
#define min 1
#define max 10

void bubble_sort(int []);
void selection_sort(int []);
void random_arr(int []);
void main()
{
    srand(time(NULL));

    printf("press 1 Bubble Sort\npress 2 Selection Sort\n");
    int which_sort;
    scanf("%d",&which_sort);

    int arr[size];
    random_arr(arr);

    for(int i=0;i<size;i++) printf("%d ",arr[i]);
    printf("\n===================================\n");

    switch (which_sort){
        case 1:
            bubble_sort(arr);
            break;

        case 2:
            selection_sort(arr);
            break;
        
        default:
            break;
    }

    system("pause");
}

void bubble_sort(int arr[])
{   
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        for(int a=0;a<size;a++) printf("%d ",arr[a]);
        puts("");
    }
}

void selection_sort(int arr[])
{
    for(int i=0;i<size-1;i++){
        int min_idx = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        for(int a=0;a<size;a++) printf("%d ",arr[a]);
        puts("");
    }
}

void random_arr(int arr[])
{
    for(int i=0;i<size;i++){
        arr[i] = rand()%(max + min - 1) + min;
        int repeat = 0;

        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]) repeat = 1;
        }
        if(repeat == 1) i--;
    }
}