#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;      //宣告一整數N
    scanf("%d",&n);     //輸入陣列大小

    int a[n];       //宣告a[]的size為n
    for(int i=0;i<n;i++) scanf("%d",&a[i]);     //輸入陣列數值

    for(int i=0;i<n-1;i++){         //排序:從大到小
        for(int j=0;j<n-1-i;j++){
            if(a[j]<a[j+1]){
                int t=a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }         

    for(int i=0;i<n;i++){   
        printf("%d ",a[i]);     //輸出陣列
    }

    system("pause");
    return 0;
}