#include <stdio.h>
#include <stdlib.h>

#define MAX_TERNS 101

typedef struct 
{
    int col;
    int row;
    int value;
}term;

void transpose(term a[], term b[])
{
    int currentb, num_terms = a[0].value;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

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
    int row_terms[MAX_TERNS], starting_pos[MAX_TERNS];
    int num_cols = a[0].col, num_terms = a[0].value;

    b[0].col = a[0].row;
    b[0].row = num_cols;
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
            int j = starting_pos[a[i].col]++;
            b[j].col = a[i].row;
            b[j].row = a[i].col;
            b[j].value= a[i].value;
        }

    }
}

void print_matrix(term matrix[])
{
    int i;
    printf("Row   Col   Value\n");
    for(i=0;i<=matrix[0].value;i++){
        printf("%-5d %-5d %-5d\n",matrix[i].row,matrix[i].col,matrix[i].value);
    }
}

int main()
{
    term a[MAX_TERNS], b[MAX_TERNS], c[MAX_TERNS];

    FILE *fp;
    fp = fopen("matrix_a.txt", "r");
    for(int i=0;!feof(fp);i++){
        fscanf(fp, "%d\t%d\t%d\n", &a[i].row, &a[i].col, &a[i].value);
    }
    fclose(fp);

    printf("Matrix A:\n");
    print_matrix(a);
    printf("\n\n");

    transpose(a, b);
    printf("Use transpose function\nMatrix b:\n");
    print_matrix(b);
    printf("\n\n");

    fastTranspose(a, c);
    printf("Use fastTranspose function\nMatrix c:\n");
    print_matrix(c);
    printf("\n\n");

    
    return 0;
}