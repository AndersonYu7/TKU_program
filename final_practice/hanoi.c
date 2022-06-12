#include <stdio.h>
#include <stdlib.h>

void hanoi(char from, char by, char to, int n);
int main()
{
    hanoi('A','B','C',4);

    system("pause");
    return 0;
}

void hanoi(char from, char by, char to, int n)
{
    if(n==1) printf("Move disk 1 from %c to %c\n", from, to);
    else{
        hanoi(from, to, by, n-1);
        printf("Move disk %d from %c to %c\n",n , from, to);
        hanoi(by, from, to, n-1);
    }
}