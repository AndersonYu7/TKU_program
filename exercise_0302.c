#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x[3];
    int t;

    for(int i=0;i<3;i++) scanf("%d",&x[i]);

    if(x[0] > x[1]){
        t = x[0];
        x[0] = x[1];
        x[1] = t;
    }

    if(x[0] > x[2]){
        t = x[0];
        x[0] = x[2];
        x[2] = t;
    }

    if(x[1] > x[2]){
        t = x[1];
        x[1] = x[2];
        x[2] = t;
    }

    for(int i=0;i<2;i++){
        printf("%d, ",x[i]);
    }
    printf("%d",x[2]);


    system("pause");
    return 0;
}

