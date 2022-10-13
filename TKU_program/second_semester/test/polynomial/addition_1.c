#include <stdlib.h>
#include <stdio.h>

#define MAX_DEGREE 101
#define False 0
#define True 1

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

int COMPARE(int degree_1, int degree_2)
{
    if(degree_1 > degree_2) return 1;
    else if(degree_1 < degree_2) return -1;
    else return 0;
}

polynomal Attach(polynomal poly, int coef, int expon)
{
    if(poly.coef[expon] != 0) return poly;
    else{
        poly.coef[expon] = (float)coef;
        return poly;
    }
    
}

polynomal Remove(polynomal poly, int expon)
{
    if(poly.coef[expon]!=(float)0){
        if((float)expon == poly.degree){
            for(int i=expon-1;i>=0;i--){
                if(poly.coef[i]!=(float)0){
                    poly.degree = i;
                    break;
                }
                else{
                    if(i==0) poly.degree = 0;
                }
            }
        }
        poly.coef[expon]=(float)0;
    }
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

    b.coef[2] = 2;
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
