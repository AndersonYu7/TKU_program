#include <stdlib.h>
#include <stdio.h>

#define MAX_DEGREE 101
#define False 0
#define True 1

#define COMPARE(a,b) ((a)>(b) ? 1:(a)<(b) ? -1:0)

typedef struct 
{
    int degree;
    float coef[MAX_DEGREE];
}polynomal;

polynomal zero()
{
    polynomal d;
    d.degree = 0;
    for(int i=0;i<MAX_DEGREE;i++) d.coef[i] = 0;

    return d;
}

int IsZero(polynomal poly)
{
    if(poly.degree == 0) return True;
    else return False;
}

int LeadExp(polynomal poly)
{
    return poly.degree;
}

int Coef(polynomal poly, int degree)
{
    return poly.coef[degree];
}

polynomal Attach(polynomal poly, int coef, int expon)
{

    if(!poly.coef[expon]) poly.coef[expon] = coef;
    return poly;
}

polynomal Remove(polynomal poly, int expon)
{
    int i = expon - 1;
    while(!IsZero(poly)){
        if(poly.coef[i]){
            poly.degree = i;
            break;
        }
        i--;
    }
    poly.coef[expon] = 0;
    return poly;
}

void print_poly(polynomal poly)
{
    for(int i=LeadExp(poly);i>=0;i--){
        if(poly.coef[i]!=0){
            if(i!=LeadExp(poly)){
                if(i==0) printf(" + %.f", poly.coef[i]);
                else printf(" + %.fx^%d ",poly.coef[i], i);
            }
            else printf("%.fx^%d",poly.coef[i], i);
        }
    }
}

int main(void)
{
    polynomal a, b, d;
    d = zero();
    a = zero();
    b = zero();

    a.degree = 3;
    b.degree = 2;

    a.coef[3] = 6;
    a.coef[1] = 3;
    a.coef[0] = 1;

    b.coef[2] = 5;
    b.coef[1] = 4;
    
    float sum = 0;
    while(!IsZero(a) && !IsZero(b)){ //ok
        switch (COMPARE(LeadExp(a), LeadExp(b))){
            case -1:
                d = Attach(d, Coef(b, LeadExp(b)), LeadExp(b));
                b = Remove(b, LeadExp(b));
                break;

            case 0:
                sum = Coef(a, LeadExp(a)) + Coef(b, LeadExp(b)); 

                if(sum){
                    d = Attach(d, sum, LeadExp(a));
                    a = Remove(a, LeadExp(a));
                    b = Remove(b, LeadExp(b));
                }
                break;

            case 1:
                d = Attach(d, Coef(a, LeadExp(a)), LeadExp(a));
                a = Remove(a, LeadExp(a));
                break;
        }
    }
    while(a.coef[LeadExp(a)]){
        d = Attach(d, Coef(a, LeadExp(a)), LeadExp(a));
        a = Remove(a, LeadExp(a));
    }

    while(b.coef[LeadExp(b)]){
        d = Attach(d, Coef(b, LeadExp(b)), LeadExp(b));
        b = Remove(b, LeadExp(b));
    }
    for(int i=MAX_DEGREE-1;i>=0;i--){
        if(d.coef[i]!=0){
            d.degree = i;
            break;
        }
    }

    print_poly(d);

    return 0;
}