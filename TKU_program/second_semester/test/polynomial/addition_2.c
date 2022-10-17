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
    avail = finishb + 1;
    float coefficient;
    *startd = avail;
    while(starta <= finisha && startb <= finishb){
        switch(COMPARE(terms[starta].expon, terms[startb].expon)){
            case -1:    //expon_a < expon_b
                attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;

            case 0:     //expon_a == expon_b
                coefficient = terms[starta].coef + terms[startb].coef;

                if(coefficient)
                    attach(coefficient, terms[starta].expon);
                    starta++;
                    startb++;
                    break;

            case 1:     //expon_a > expon_b
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
                break;
        }
    }

    for(; starta <= finisha; starta++)  //add in remaining terms of A(x)
        attach(terms[starta].coef, terms[starta].expon);

    for(; startb <= finishb; startb++)  //add in remaining terms of B(x)
        attach(terms[startb].coef, terms[startb].expon);

    *finishd = avail - 1;
}

void print_poly(polynomial terms[], int start, int finish)
{
    for(int i=start;i<=finish;i++){
        if(i!=start){
            if(!terms[i].expon)
                printf(" + %.f", terms[i].coef);
            else 
                printf(" + %.fX^%d", terms[i].coef, terms[i].expon);
        } else
            printf("%.fX^%d", terms[i].coef, terms[i].expon);
    }
    puts("");
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

    int startd;
    int finishd;

    padd(0, 1, 2, 5, &startd, &finishd);

    puts("");
    printf("A(X): ");
    print_poly(terms, 0, 1);
    printf("B(X): ");
    print_poly(terms, 2, 5);
    printf("D(X): ");
    print_poly(terms, startd, finishd);
    return 0;
}