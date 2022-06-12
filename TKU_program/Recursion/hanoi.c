#include <stdio.h>
#include <stdlib.h>

void tower(char from_peg, char aux_peg, char to_peg, int n);
int main()
{
    tower('A', 'B', 'C', 4);
    puts("");

    system("pause");
    return 0;
}

void tower(char from_peg, char aux_peg, char to_peg, int n)
{
    if(n==1) printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
    else{
        tower(from_peg, to_peg, aux_peg, n-1);
        printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
        tower(aux_peg, from_peg, to_peg, n-1);
    }
}