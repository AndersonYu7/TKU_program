#include <stdio.h>
#include <stdlib.h>

int find_min(int arr[], int first, int size);
void selection(int arr[], int size);
int main()
{
    int arr[5] = {4,5,3,2,1};
    selection(arr, 5);

    for(int i=0;i<5;i++) printf("%d ",arr[i]);

    system("pause");
    return 0;
}

int find_min(int arr[], int first, int size)
{
    int min_index = first;
    int min_value = arr[first];

    for(int i=first+1; i<size;i++){
        if(min_value > arr[i]){
            min_index = i;
            min_value = arr[i];
        }
    }

    return min_index;
}

void selection(int arr[], int size)
{
    int index_min;
    for(int i=0;i<size-1;i++){
        index_min = find_min(arr, i, size);

        if(i != index_min){
            int temp = arr[index_min];
            arr[index_min] = arr[i];
            arr[i] = temp;
        }
    }
}