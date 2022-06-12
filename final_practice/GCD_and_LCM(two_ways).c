#include <stdlib.h>
#include <stdio.h>

int rec_gcd(int a, int b);
int GCD(int a, int b);
int LCM(int a, int b);
int main()
{
    int n1 = 703, n2 = 407;
    printf("Use general ways to cal gcd : %d\n", GCD(n1, n2));
    printf("Use rec ways to cal gcd : %d\n",rec_gcd(n1, n2));
    printf("The LCM of 703 and 407 is %d\n", LCM(n1, n2));

    system("pause");
    return 0;
}


//Euclidean algorithm for calculate GCD 
int rec_gcd(int a, int b)
{
    if(a % b==0) return b;
    else return rec_gcd(b, a%b);
}

int GCD(int a, int b) 
{
	if(a%b==0) return b;
    else{
        while(a%b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }

        return b;
    }
}

int LCM(int a, int b)
{
    int n = GCD(a, b);
    return n*(a/n)*(b/n);
}