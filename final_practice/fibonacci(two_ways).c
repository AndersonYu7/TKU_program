#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int rec_fibonacci(int n);
int rec_fibonacci2(int n);
int main()
{
    for(int i=1;i<=10;i++) printf("%2d ",fibonacci(i));
    puts("");
    puts("");

    for(int i=1;i<=10;i++) printf("%2d ",rec_fibonacci(i));
    puts("");
    puts("");

    for(int i=1;i<=10;i++) printf("%2d ",rec_fibonacci2(i));
    puts("");

    system("pause");
    return 0;
}

int fibonacci(int n)
{
    int n1 = 1, n2 = 1;
    if(n==1 || n==2) return 1;
    else{
        for(int i=3;i<=n;i++){
            int next = n1 +  n2;
            n1 = n2;
            n2 = next;
        }
        return n2;
    }
}

int rec_fibonacci(int n)    //1 1 2 3 5 8 13 ~
{
    if(n==1||n==2) return 1;
    else return rec_fibonacci(n-2) + rec_fibonacci(n-1);
}

int rec_fibonacci2(int n)   //0 1 1 2 3 5 8 13 ~
{
    if(n==1 || n==2) return n-1;    
    else return rec_fibonacci2(n-2) + rec_fibonacci2(n-1);
}