#include <stdio.h>
#include <stdlib.h>

void swap(double *smp, double *lgp);
void main()
{
    double x=3.5;
    double y=5.7;
    printf("x's address:%p\n",&x);  //62FE18
    printf("y's address:%p\n",&y);  //62FE10
    swap(&x,&y);
    printf("(f) x:%.lf\n",x);
    printf("(g) y:%.lf\n",y);

    system("pause");
}

void swap(double *smp, double *lgp)
{
    double temp;
    printf("(a) smp:%p\n",smp);
    printf("(b) lqp:%p\n",lgp);
    temp = *smp; 
    smp = lgp;  
    *lgp = temp;    

    printf("(c) smc:%p\n",smp);
    printf("(d) lgp:%p\n",lgp);
    printf("(e) *smp:%.lf\n",*smp);
}