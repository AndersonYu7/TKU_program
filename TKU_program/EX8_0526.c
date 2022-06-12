#include <stdio.h>
#include <stdlib.h>

int find_max(int [], int );
void main()
{
    printf("size:");
    int size;
    scanf("%d",&size);

    printf("array:");
    int arr[size];
    int *ptr;
    for(ptr = arr;ptr!=&arr[size];ptr++) scanf("%d",&*ptr);

    printf("The maxium number is %d\n",find_max(arr,size));
    
    system("pause");
}

int find_max(int arr[], int size)
{
    if(size==1) return arr[0];
    else{
        if(arr[size-1] > find_max(arr,size-1)) return arr[size-1];
        else return find_max(arr,size-1);
    }
}