#include <stdio.h>
#include <stdlib.h>

void to_double(int arr[], int size, double arr2[]);
void to_double2(double arr[], int *size);
int main()
{
    int arr[10];
    double arr2[10];
    // int i=0;
    // while(scanf("%d",&arr[i]) && arr[i]!=-1) i++;
    // to_double(arr, i, arr2);

    int size;
    to_double2(arr2, &size);
    for(int j=0;j<size;j++) printf("%.2f ",arr2[j]);



    system("pause");
    return 0;
}

void to_double(int arr[], int size, double arr2[])
{
    for(int i=0;i<size;i++) arr2[i] = arr[i];
}

void to_double2(double arr[], int *size)
{   
    int i = 0;
    int array[10];
    while(scanf("%d",&array[i]) && array[i] != -1) i++;

    for(int j=0;j<i;j++) arr[j] = array[j];
    *size = i;
}