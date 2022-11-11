#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
    if(!((p)=MALLOC(s))){\
        fprintf(stderr,"insufficient memory");\
        exit(EXIT_FAILURE);\
    }
int pascal(int i,int j){
    if(i==j||j==0)
        return 1;
    else
        return pascal(i-1,j-1)+pascal(i-2,j-2);
}

int main(void)
{
    int n,**array;
    printf("請輸入任一整數，代表次方數，以顯示Pascal Triangle\n");
    scanf("%d",&n);
    MALLOC(array,n*sizeof (*array));
    for(int i=0;i<n+1;i++){
        MALLOC(array[i],(i+1)*sizeof (**array));
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<i+1;j++){
            array[i][j]=pascal(i,j);
            printf("%3d",array[i][j]);
        }
        puts("");
    }

}