#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_min(char *arr[], int first, int size);
void selection_sort(char *arr[], int size);
int main()
{
    char *arr[3] = {"cab","bca","abc"};

    for(int i=0;i<3;i++) printf("%s\n",arr[i]);
    puts("");

    selection_sort(arr, 3);
    for(int i=0;i<3;i++) printf("%s\n",arr[i]);


    system("pause");
    return 0;
}

int find_min(char *arr[], int first, int size)
{
    int index_min = first;
    
    for(int i=first+1;i<size;i++){
        if(*arr[i] < *arr[index_min]){
            index_min = i;
        }
    }

    return index_min;
}

void selection_sort(char *arr[], int size)
{
    for(int i=0;i<size-1;i++){
        int index_min = find_min(arr, i, size);

        if(index_min != i){
            char *temp = arr[index_min];
            arr[index_min] = arr[i];
            arr[i] = temp;
        }

    }
}