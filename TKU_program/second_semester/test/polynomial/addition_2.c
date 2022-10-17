#include<stdio.h>
#include <stdlib.h>
#define COMPARE(a,b) ((a)>(b) ? 1:(a)<(b) ? -1:0)
#define MAX_TERMS 101

typedef struct{
    int expon;
    float coef;
}polynomial;

polynomial terms[MAX_TERMS];
int avail=0;

void attach(float coeff,int exp);
void PRINT(polynomial a[],int start,int max);

int main()
{
    int starta=0;
    int finisha=1;
    int startb=2;
    int finishb=5;
    int startd;
    int finishd;
    float coefficient;
    avail = finishb+1;
    startd = avail;

    terms[0].expon=1000;
    terms[0].coef=2.0;
    terms[1].expon=0;
    terms[1].coef=1.0;
    terms[2].expon=4;
    terms[2].coef=1.0;
    terms[3].expon=3;
    terms[3].coef=10.0;
    terms[4].expon=2;
    terms[4].coef=3.0;
    terms[5].expon=0;
    terms[5].coef=1.0;

    while(starta <= finisha && startb <= finishb)
        switch(COMPARE(terms[starta].expon,
                       terms[startb].expon))
        {
            case -1: //a expon < b expon
                    attach(terms[startb].coef,terms[startb].expon);
                    startb++;
                    break;
            case  0: //equal expon
                    coefficient = terms[starta].coef +
                                  terms[startb].coef;
                    if(coefficient)
                        attach(coefficient,terms[starta].expon);
                    starta++;
                    startb++;
                    break;
            case  1: //a expoon > b expon
                    attach(terms[starta].coef,terms[starta].expon);
                    starta++;
        }
        //add in remaining terms of A(x)
        for(; starta <= finisha; starta++)
            attach(terms[starta].coef,terms[starta].expon);
        //add in remaining terms of B(x)
        for(; startb <= finishb; startb++)
            attach(terms[startb].coef,terms[startb].expon);

        finishd = avail - 1;

        PRINT(terms, startd, finishd);
    puts("");
}
void attach(float coeff,int exp)
{
    if(avail >= MAX_TERMS){
        fprintf(stderr,"Too many terms in the poly\n");
        exit(1);
    }
    terms[avail].coef = coeff;
    terms[avail++].expon = exp;

}
void PRINT(polynomial a[],int start,int max)
{
    if(max >= MAX_TERMS) exit(1);
    for(int i=start;i<=max;i++){
          if(a[i].coef) printf("%.fX^%d ",a[i].coef,a[i].expon);
    }
    puts("");
}