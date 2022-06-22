#include <stdio.h>
#include <stdlib.h>
#define size 3

void *bubble_sort(char *a[]);
int main()
{   
    char *a[size] = {"abc", "bca", "cab"};
    for(int i=0;i<3;i++) printf("%p\n", a[i]);
    bubble_sort(a);
    for(int i=0;i<3;i++) printf("%s\n", a[i]);
    for(int i=0;i<3;i++) printf("%p\n", a[i]);

    system("pause");
    return 0;
}

void *bubble_sort(char *a[])
{
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(*a[j]<*a[j+1]){
                char *temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}