#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 15
int main()
{
    FILE *inp;
    int i,j;
    double a[SIZE+1]={0},sum=0,diff,st_dev,mean,sum_sqr=0,ok;
    inp=fopen("read.txt","r");

    for(i=1;i<=SIZE;i++)
    {
        fscanf(inp,"%lf",&ok);
        a[i]=ok;
        sum=sum+a[i];
        sum_sqr=sum_sqr+pow(a[i],2);
        printf("%lf\n",a[i]);
    }
    mean=sum/SIZE;
    st_dev=sqrt(sum_sqr/SIZE-pow(mean,2));

    for(j=1;j<=SIZE;j++)
    {
        diff=fabs(mean-a[j]);
        printf("a[%d]=%lf, diff=%lf\n",j,a[j],fabs(mean-a[j]));
    }
    printf("mean=%lf,st_dev=%lf\n",mean,st_dev);
    fclose(inp);

    system("pause");
    return 0;
}