#include <stdlib.h>
#include <stdio.h>

int main()
{
    char a[3] = {'a','b','c'};
    char *n;
    n = a;
    printf("%s\n",n);

    int b[3] = {'a','b','c'};
    int *n_;
    n_ = b;
    printf("%p\n",n_);  //the first address
    printf("%p\n",b[0]);    //ackii
    printf("%p\n",&b[0]);   //the first address
    printf("%p",n_[1]); //axkii
    printf("%p",n_[1]); //the second address
    
    
    system("pause");
    return 0;
}