#include <stdlib.h>
#include <stdio.h>

#define MAX_TERMS 101

typedef struct
{
    int row, col, value;
}term;

void transpose(term a[], term b[])
{
    int currentb, num_terms = a[0].value;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = num_terms;

    if(num_terms > 0){
        currentb = 1;
        for(int i=0;i<a[0].col;i++){
            for(int j=1;j<=num_terms;j++){
                if(a[j].col == i){
                    b[currentb].col = a[j].row;
                    b[currentb].row = a[j].col;
                    b[currentb++].value = a[j].value;
                }
            }
        }
    }
}

void fastTranspose(term a[], term b[])
{
    int row_terms[MAX_TERMS], starting_pos[MAX_TERMS];
    int num_cols = a[0].col, num_terms = a[0].value;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = num_terms;

    if(num_terms > 0){
        for(int i=0;i<num_cols;i++)
            row_terms[i] = 0;

        for(int i=1;i<=num_terms;i++)
            row_terms[a[i].col]++;

        starting_pos[0] = 1;
        for(int i=1;i<num_cols;i++)
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

        for(int i=1;i<=num_terms;i++){
            int j=starting_pos[a[i].col]++;
            b[j].col = a[i].row;
            b[j].row = a[i].col;
            b[j].value= a[i].value;
        }
    }
}

int main()
{


    return 0;
}