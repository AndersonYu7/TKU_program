#include <stdio.h>

int binary_search(int array[], int left, int right, int x);
int main()
{
    int array[] = {3 ,4 ,5, 6, 7, 8, 9};
    int want_to_search = 4;
    int size = sizeof(array)/sizeof(array[0]); /* 28/4 */

    int result = binary_search(array, 0, size-1, want_to_search);

    if(result == -1) printf("Not found");
    else printf("The result is %d", result);

    return 0;
}

int binary_search(int array[], int left, int right, int x)
{
    
    while(left <= right){
        int mid = (left+right)/2;

        if(array[mid] == x) return mid;
        else if(array[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}