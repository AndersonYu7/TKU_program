#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 15

void bubble_sort(int num[],int n);
int median(int num[], int n);

int main()
{
    srand(time(NULL));
//===================宣告所需變數====================
    int num[size];
    int Max = 100, min = 1, sum = 0, isused = 0;
//===================================================
//=============生成15個亂數並存在陣列中==============
    for(int i=0;i<size;i++){
        num[i] = rand()%(Max + min -1) + min;
        sum+=num[i-1];
    }
//==================================================
    bubble_sort(num,size);
//============輸出陣列、平均數、中位數===============
    printf("The array : { ");
    for(int i=0;i<size;i++){
        if(i!=size-1) printf("%d, ",num[i]);
        else printf("%d ",num[i]);
    }
    puts("}");
    printf("The mean value is %.2f\n",(float)sum/size);
    printf("The median of those elements is %d\n",median(num,size));
//=================================================
    system("pause");
    return 0;
}
//================泡沫排序:降序====================
void bubble_sort(int num[],int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(num[j]<num[j+1]){
                int t = num[j];
                num[j] = num[j+1];
                num[j+1] = t;
            }
        }
    }
}
//=================================================
//===================找中位數======================
int median(int num[], int n)
{
    int m;
    if(n%2==0) m = (num[n/2-1]+num[n/2])/2;
    else m = num[n/2];

    return m;
}
//=================================================