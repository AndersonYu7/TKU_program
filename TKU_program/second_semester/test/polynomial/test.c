#include <stdlib.h>
#include <stdio.h>

#define MAX_TERMS 101

typedef struct 
{
    float coef;
    int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

int COMPARE(int a, int b)
{
    if(a>b) return 1;
    else if(a == b) return 0;
    else return -1;
}

void attach(float coefficient, int exponent)
{
    if(avail >= MAX_TERMS){
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }

    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = avail;
    while(starta <= finisha && startb <= finishb){
        switch(COMPARE(terms[starta].expon, terms[startb].expon)){
            case -1:
                attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;

            case 0:
                coefficient = terms[starta].coef + terms[startb].coef;

                if(coefficient)
                    attach(coefficient, terms[starta].expon);
                    starta++;
                    startb++;
                    break;

            case 1:
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
                break;
        }
    }

    for(; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expon);

    for(; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expon);

    *finishd = avail - 1;
}

int main()
{
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

    for(int i=0;i<5;i++) printf("%.f ", terms[i].coef);
    puts("");
    for(int i=0;i<5;i++) printf("%d ", terms[i].expon);
    puts("");

    int start;
    int finish;

    padd(0, 1, 2, 5, &start, &finish);

    for(int i=start;i<finish;i++) printf("%.fx%d ", terms[i].coef, terms[i].expon);

    return 0;
}