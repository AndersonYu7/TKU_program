#include <stdio.h>
#include <stdlib.h>

#define MAX_terms 101
#define COMPARE(a, b) ((a)>(b)? 1:(a)<(b)? -1:0)

typedef struct 
{
    int row;
    int col;
    int value;
}term;

void print_matrix(term matrix[])
{
    int i;
    printf("Row   Col   Value\n");
    for(i=0;i<=matrix[0].value;i++){
        printf("%-5d %-5d %-5d\n",matrix[i].row,matrix[i].col,matrix[i].value);
    }
}

void fastTranspose(term a[], term b[])
{
    int row_term[MAX_terms], starting_pos[MAX_terms];
    int num_cols = a[0].col, num_terms = a[0].value;
    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if(num_terms > 0){
        for(int i=0;i<num_cols;i++)
            row_term[i] = 0;

        for(int i=1;i<=num_terms;i++)
            row_term[a[i].col]++;

        starting_pos[0] = 1;
        for(int i=1;i<num_cols;i++)
            starting_pos[i] = starting_pos[i-1] + row_term[i-1];

        for(int i=1;i<=num_terms;i++){
            int j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }

}

void storesum(term d[], int *totald, int row, int col, int *sum)
{
    if(*sum){
        if(*totald < MAX_terms){
            d[++*totald].row = row;
            d[*totald].col = col;
            d[*totald].value = *sum;
            *sum = 0;
        } else{
            fprintf(stderr, "Numbers of terms in productexceed %d\n", MAX_terms);
            exit(EXIT_FAILURE);
        }
    }
}

void mmult(term a[], term b[], term d[])
{
    int column, totald = 0;
    int row_begin = 1, row = a[1].row, sum = 0;

    term new_b[MAX_terms];

    if(a[0].col != b[0].row){
        fprintf(stderr, "Incompatible matries\n");
        exit(EXIT_FAILURE);
    }

    fastTranspose(b, new_b);
    printf("\n\nMatrix new_B:\n\n");
    print_matrix(new_b); 

    a[a[0].value+1].row = a[0].row;
    new_b[b[0].value+1].row = b[0].col;
    new_b[b[0].value+1].col= 0;

    for(int i=1;i<=a[0].value;){
        sum = 0;
        column = new_b[0].row;
        for(int j=1;j<=b[0].value+1;){
            if(a[i].row != row){
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                for(;new_b[j].row == column;j++);
                column = new_b[j].row;
            } else if(new_b[j].row != column){
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                column = new_b[j].row;
            } else{
                switch (COMPARE(a[i].col, new_b[j].col)){
                    case -1:
                        i++;
                        break;

                    case 0:
                        sum += a[i++].value * new_b[j++].value;
                        break;

                    case 1:
                        j++;
                        break;
                }
            }
        }
        for(;a[i].row == row;i++);
        row_begin = i;
        row = a[i].row;

    }

    d[0].row = a[0].row;
    d[0].col = b[0].col;
    d[0].value = totald;
}

int main()
{
    term a[MAX_terms], b[MAX_terms], d[MAX_terms];

    FILE *fp;
    fp = fopen("matrix_a.txt", "r");
    for(int i=0;!feof(fp);i++){
        fscanf(fp, "%d\t%d\t%d\n", &a[i].row, &a[i].col, &a[i].value);
    }
    fclose(fp);

    fp = fopen("matrix_b.txt", "r");
    for(int i=0;!feof(fp);i++){
        fscanf(fp, "%d\t%d\t%d\n", &b[i].row, &b[i].col, &b[i].value);
    }
    fclose(fp);

    printf("Matrix A:\n\n"); 
    print_matrix(a); 
    printf("\n\nMatrix B:\n\n");
    print_matrix(b); 

    mmult(a, b, d);

    printf("\n\nMatrix A * B:\n\n");
    print_matrix(d); 

    return 0;
}