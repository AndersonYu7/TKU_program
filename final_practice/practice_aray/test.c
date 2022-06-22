#include <stdlib.h>
#include <stdio.h>

int main()
{
    int count = 1;
    char a[4] = {'a','b','c','\0'};  //if it doesn't have '\0', it will produce garbleds
    printf("%d %s\n", count++, a); //abc
    printf("%d %p\n", count++,*a);    //a's ackii
    printf("%d %c\n", count++, *a);
    printf("%d %p\n", count++,a);
    printf("%d %p\n", count++,&a);    //a[0]'s address
    printf("%d %p\n", count++,&a[0]); //a[0]'s address
    a[1] = 'h';
    printf("%d %s\n", count++,a);

    char *b = "abc";
    printf("%d %s\n", count++,b); //abc
    printf("%d %p\n", count++,b); //b[0]'s address pointer -> 1 bit
    printf("%d %p\n", count++, &b);   //b's address
    printf("%d %p\n", count++, &b[0]);    //b[0]'s address    pointer -> 1 bit
    printf("%d %p\n", count++, &b[1]);   //b[1]'s address    pointer -> 1 bit
    printf("%d %p\n", count++, &b[2]);   //b[2]'s address    pointer -> 1 bit
    printf("%d %s\n", count++, &b[0]);    
    printf("%d %s\n", count++, &b[1]);   
    printf("%d %s\n", count++, &b[2]);   
    printf("%d %p\n", count++,*b);
    printf("%d %c\n", count++,*b);
    printf("%d %c\n", count++, b[0]); 
    // b[1] = 'v';  // (X)
    // printf("%s\n",b);
    printf("%d %c\n", count++, *(b+1));
    printf("%d %s\n", count++, b+1);  // == %s &b[1]
    printf("%d %p\n", count++, b+1);  // == %p &b[1]

    char c[] = "abc";
    c[1] = 'v';
    printf("%d %s\n", count++,c);


    char *d[3] = {"abc", "bca", "cab"};
    printf("%d %p\n", count++,*d[0]);   //ackii
    printf("%d %c\n", count++,*d[0]); 
    printf("%d %s", count++,&d[0][1]);

    system("pause");
    return 0;
}