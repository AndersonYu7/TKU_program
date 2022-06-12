#include <stdio.h>
#include <stdlib.h>

int find_max(int a[], int n);
int main()
{
    int a[5] = {80, 5, 4, 3, 2};
    printf("%d\n",find_max(a, 5));

    system("pause");
    return 0;
}

int find_max(int a[], int n)
{
    if(n==1) return a[0];
    else{
        if(a[n-1] > find_max(a, n-1)) return a[n-1];
        else return find_max(a, n-1);
    }
}