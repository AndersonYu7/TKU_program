#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int number;
    char enter;
    char name[5][30];
    char *str[5];

    printf("Enter number of applicants\n");
    scanf("%d",&number);
    scanf("%c",&enter); //avoid '\n' into name[0]
    printf("Enter names of applicants(less than 30 characters)\n");

    for(int i=0;i<number;i++){
        gets(name[i]);
        str[i]=name[i];
    }

    for(int i=0;i<number;i++){
        for(int j=0;j<number-1;j++){
            if(*str[j] < *str[j+1]){
                char *t=str[j];
                str[j]=str[j+1];
                str[j+1]=t;
            }
        }
    }
    printf("Application Order\tReverse Alphabetical Order\n");
    for(int i=0;i<number;i++){
        printf("%s\t\t\t%s\n",name[i],str[i]);
    }

    system("pause");
}
