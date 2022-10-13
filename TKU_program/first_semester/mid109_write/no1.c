#include <stdio.h>
#include <stdlib.h>

int a[] = {3,2,1};
void modifyArray1(int a[],int size);
void modifyArray2(int e);
void modifyArray3(int e);
void modifyArray4(int e);
int modifyArray5(int e);
int modifyArray6(int *e);
void main()
{
    int a[] = {2,4,6};
    int val5,val6;
    modifyArray1(a,3);
    printf("(a)a[1]=%d\n",a[1]);
    modifyArray2(a[1]);
    modifyArray3(a[1]);
    modifyArray2(a[1]);
    modifyArray3(a[1]);
    modifyArray4(a[1]);
    printf("(e)a[1]=%d\n",a[1]);

    val5=modifyArray5(a[2]);
    printf("(f)a[2]=%d\n",a[2]);
    printf("(g)val5=%d\n",val5);
    val6=modifyArray6(&a[2]);
    printf("(h)a[2]=%d\n",a[2]);
    printf("(i)val6=%d\n",val6);

    system("pause");
}

void modifyArray1(int a[],int size)
{
    int i=0;
    for(i=0;i<size;i++){
        a[i]+=2;
    }
}

void modifyArray2(int e)
{
    static int a[3];
    a[1]+=e;
    printf("(b)a[1]=%d\n",a[1]);
}

void modifyArray3(int e)
{
    int a[3] = {1,2,3};
    a[1]+=e;
    printf("(c)a[1]=%d\n",a[1]);
}

void modifyArray4(int e)
{
    a[1]+=e;
    printf("(d)a[1]=%d\n",a[1]);
}

int modifyArray5(int e)
{
    e+=10;
    return e;
}

int modifyArray6(int *e)
{
    *e+=10;
    return a[2];
}
