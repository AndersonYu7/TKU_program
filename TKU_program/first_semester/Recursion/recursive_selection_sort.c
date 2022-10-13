#include <stdio.h>
#include <stdlib.h>

void place_largest(int [], int );
void select_sort(int [], int );
int main()
{
    int array[10] = {1,2,3,7,3,87,5,2,4,10};
    select_sort(array, 10);

    for(int i=0;i<10;i++) printf("%d ", array[i]);

    system("pause");
    return 0;
}

void place_largest(int array[], int n)
{
    int temp, max_index = n-1;

    for(int j=0;j<n-1;j++){
        if(array[j]>array[max_index]){
            max_index = j;
        }
    }

    if(max_index != n-1){
        temp = array[n-1];
        array[n-1] = array[max_index];
        array[max_index] = temp;

    }
}

void select_sort(int array[], int n)
{
    if(n>1){
        for(int i=0;i<10;i++) printf("%d ", array[i]);
        puts("");
        place_largest(array, n);
        select_sort(array, n-1);
    }
}