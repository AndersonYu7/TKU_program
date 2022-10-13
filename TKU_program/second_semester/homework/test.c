#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#include <time.h>
int main()
{
    printf("How mant number do you want to generate\n");
    int i,n,array[99],a,b=0;
    scanf("%d",&n);
    int *array = (int *)malloc(sizeof(int)*n);
    printf("The generate number are:\n");
    generate_number(array,n);
    printf("After sorting.....\n");
    select(array,n);
    printf("sizeof(array): %d\n", (int)sizeof(array));
    if(b>=0 || b<4)
    {
        title();
        scanf("%d",&a);
            if(a==1)
            {
                inter_bin(array);
                b=0;
                printf("\n");
            }
            if(a==2)
            {
                recur_bin(array);
                b=1;
                printf("\n");
            }
            if (a==4)
            {
                recur_sequential(array);
                b=3;
                printf("\n");
            }
        while(b<4)
        {
            if(a==0 || a>=5)
            {
                printf("exit the program");
                break;
            }
            title();
            scanf("%d",&a);
            if(a==1)
            {
                inter_bin(array);
                b=0;
                printf("\n");
            }
            if(a==2)
            {
                recur_bin(array);
                b=1;
                printf("\n");
            }
            if(a==4)
            {
                recur_sequential(array);
                b=3;
                printf("\n");
            }
        }
    }
}
int generate_number(int array[],int n)
{
    srand(time(NULL));
    int i,j,x;
    for(i=0;i<n;i++)
    {
        x=rand()%300+1;
        array[i]=x;
    }
    printf("{");
    for(i=0;i<n;i++)
    {
        if(array[i]==array[n-1])
        {
            printf("%d",array[i]);
            break;
        }
        printf("%d,",array[i]);
    }
    printf("}\n");
}
int select(int array[],int n)
{
    int i, j, min,box;

    for (int i=0; i<n-1; i++)
    {
        int min = i;
        for (int j=i+1; j<n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        SWAP(array[min],array[i],box);
    }
    printf("{");
    for(i=0;i<n;i++)
    {
        if(array[i]==array[n-1])
        {
            printf("%d",array[i]);
            break;
        }
        printf("%d,",array[i]);
    }
    printf("}\n");
}
void title()
{
    printf("please input the number of your choice or press Q to leave the program:\n");
    printf("1.interactive binary search\n");
    printf("2.recursive binary search\n");
    printf("3.interactive sequential search\n");
    printf("4.recursive sequential search\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////(1)
int inter_bin(int array[])
{
    int a;
    printf("interactive binary search start...\n");
    printf("please input the number you want to search\n");
    scanf("%d",&a);
    int xx=sizeof(array)/sizeof(array[0]);
    int result=ib(array,a,0,xx-1);

    printf("sizeof(array): %d\n", xx);
    if(result==-1)
    {
        printf("not found");
    }
    else
    {
        printf("element is found at index %d",result);
    }

}
int ib(int array[],int x,int low,int high)
{
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(array[mid]==x)
        {
            return mid;
        }
        else if(array[mid] <x)
        {
            low=mid+1 ;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////(1)
/////////////////////////////////////////////////////////////////////////////////////(2)
int recur_bin(int array[])
{
    int a;
    printf("recursive binary search start...\n");
    printf("please input the number you want to search\n");
    scanf("%d",&a);
    int xx=sizeof(array)/sizeof(array[0]);
    int result=rb(array,a,0,xx-1);
    if(result==-1)
    {
        printf("not found");
    }
    else
    {
        printf("element is found at index %d",result);
    }
}
int rb(int array[],int x,int low,int high)
{
        if(high>=low)
        {
            int mid=(low+high)/2;
            if(array[mid]==x)
            {
                return mid;
            }
            else if(array[mid] >x)
            {
                return rb(array,x,low,mid-1);
            }
            else
            {
                return rb(array,x,mid+1,high);
            }
        }
            return -1;
}
/////////////////////////////////////////////////////////////////////////////////////(2)
/////////////////////////////////////////////////////////////////////////////////////(4)
int recur_sequential(int array[])
{
    int a;
    printf("iterative sequential search start...\n");
    printf("please input the number you want to search\n");
    scanf("%d",&a);
    int xx=sizeof(array)/sizeof(array[0]);
    int result=rs(array,xx,a);
    if(result==-1)
    {
        printf("not found");
    }
    else
    {
        printf("element is found at index %d",result);
    }
}
int rs(int array[],int size,int x)
{
    int rec;
    size--;
    if (size >= 0) {
        if (array[size] == x)
            return size;
        else
            rec = rs(array, size, x);
    }
    else
        return -1;

    return rec;
}
/////////////////////////////////////////////////////////////////////////////////////(4)
