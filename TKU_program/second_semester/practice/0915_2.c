#include <stdio.h>

int main()
{
    int a, b, *p1, *p2;
    printf("input a and b: ");
    scanf("%d %d", &a, &b);

    p1 = &a, p2 = &b;

    printf("p1: %d, p2: %d\n\n", *p1, *p2);

    if(*p1 < *p2){
        int t = *p1;
        *p1 = *p2;
        *p2 = t;
    }

    printf("a: %d, b: %d\n", a, b);
    printf("p1: %d, p2: %d", *p1, *p2);
    
    return 0;
}