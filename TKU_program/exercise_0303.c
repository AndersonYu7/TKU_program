#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SIZE 15

int main()
{
    FILE *inp;
    double input_status;
    double ar_num[SIZE];
    double num,avg,sum = 0,powsum = 0,value = 0;
    int i=0;

    inp = fopen("read.txt","r");

    input_status = fscanf(inp,"%lf",&num);       //read 15 numbers from an input file and put them into array(ar_num[])
    while(input_status!=EOF){
        ar_num[i] = num;
        i++;
        input_status = fscanf(inp,"%lf",&num);
    }
    
    for(int i=0;i<SIZE;i++) sum+=ar_num[i];     //calculate avg
    
    avg=sum/SIZE;

    for(int i=0;i<SIZE;i++) powsum += pow(ar_num[i]-avg,2);   //calculate the standard deviation

    value = sqrt(powsum/SIZE);

    for(int i=0;i<SIZE;i++) printf("a[%d]:%lf\n",i,ar_num[i]); //display array

    for(int i=0;i<SIZE;i++) printf("The difference between a[%d] and the average is %lf\n",i,fabs(ar_num[i]-avg)); //display the difference

    printf("The mean is %lf\n",avg);
    printf("The standard deviation is %lf\n",value);

    fclose(inp);

    system("pause");
    return 0;
}