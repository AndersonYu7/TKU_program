#include <stdio.h>
#include <stdlib.h>

int fibonacci(int );
int fibonacci_int(int );
int GCD(int ,int );
int GCD_int(int , int );
void main()
{
    printf("Enter two positive integers to calculate GCD\n");
    int num1, num2;
    scanf("%d %d",&num1, &num2);

    printf("Please enter an integer to show the last value of Fibonacci Sequence\n");
    int num3;
    scanf("%d",&num3);

    printf("(rec)Their greatest common divisor is %d\n",GCD(num1, num2));
    printf("(rec)The factorial ans is %d\n",fibonacci(num3));
    printf("(noraml)Their greatest common divisor is %d\n",GCD_int(num1, num2));
    printf("(normal)The factorial ans is %d\n",fibonacci_int(num3));

    system("pause");
}

int fibonacci(int n)
{
    if( n==1 || n==2 ) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci_int(int n)
{
    int n1 = 0, n2 = 1;

    if(n == 1 || n == 2) return n2;
    else{
        for(int i=2;i<=n;i++){
            int next = n1 + n2;
            n1 = n2;
            n2 = next;
        }
        return n2;
    }
}

int GCD(int n,int a)
{
    if(n%a == 0) return a;
    else return GCD(a,n%a);
}

int GCD_int(int n, int a) 
{
    int temp;
    while (n % a != 0) {
        temp = a;
        a = n%a;
        n = temp;
    }
    return a;
}