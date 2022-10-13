#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_applicants 50
#define MAX_str_length 30

void select_sort(char *[], int );
int alpha_first(char *[],int , int );
void main()
{
    printf("Enter number of applicants (0 . . 50)\n> ");

    int the_num_of_applicants;
    scanf("%d",&the_num_of_applicants);

    char one_char;
    do{
        scanf("%c",&one_char);
    }while(one_char != '\n');

    printf("Enter names of aplicants on separate lines of less than\n");
    printf("30 characters in the order in which they applied\n");

    char applicants[MAX_applicants][MAX_str_length+1];
    char *alpha[MAX_applicants];
    for(int i=0;i<the_num_of_applicants;i++){
        gets(applicants[i]);
        alpha[i] = applicants[i];
    }

    for(int i=0;i<the_num_of_applicants;i++)
        select_sort(alpha, the_num_of_applicants);

    printf("\n\n%-30s     %-30s\n\n","Applecation Order","Alphabetical Order");
    for(int i=0;i<the_num_of_applicants;i++){
        printf("%-30s     %-30s\n",applicants[i],alpha[i]);
    }
    
    system("pause");
}

int alpha_first(char *list[],int min, int max)
{
    int first = min;

    for(int i = min + 1;i < max;i++){
        if(strcmp(list[i],list[first])>0)
            first = i;
    }

    return(first);
}

void select_sort(char *list[], int n)
{
    int index_min;
    char *temp;

    for(int fill=0;fill<n-1;fill++){
        index_min = alpha_first(list,fill,n);
        
        if(index_min!=fill){
            temp = list[index_min];
            list[index_min] = list[fill];
            list[fill] = temp;
        }
    }
}