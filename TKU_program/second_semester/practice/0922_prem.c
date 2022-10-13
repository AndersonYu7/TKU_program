#include <stdio.h>
#define SWAP(x, y, t) ((t = x), (x = y), (y = t)) 

void perm(char *list, int k, int j);
int main()
{
    char arr[] = "abc";
    perm(arr, 0, 2);

    return 0;
}

void perm(char *list, int k, int j)
{
    char temp;
    if(k == j) printf("%s\n", list);
    else{
        for(int i = k; i<=j; i++){
            SWAP(list[i], list[k], temp);
            perm(list, k+1, j);
            SWAP(list[i], list[k], temp);
        }
    }
}