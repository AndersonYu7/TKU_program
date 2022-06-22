#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SETSIZ 65



int is_empty(const char *set)
{
    return set[0] == '\0';
}

int is_element(char ele, const char *set)
{
    if(is_empty(set)) return 0;
    else{
        if(set[0] == ele) return 1;
        else is_element(ele, &set[1]);
    }
}

int is_set(const char *set)
{
    if(is_empty(set)) return 1;
    else{
        if(is_element(set[0], &set[1])) return 0;
        else return is_set(&set[1]);
    }
}

int is_subset(const char *sub, const char *set)
{
    if(is_empty(sub)) return 1;
    else{
        if(!is_element(sub[0], set)) return 0;
        else return is_subset(&sub[1], set);
    }
}

char *set_union(char *result, const char *set1, const char *set2)
{
    char temp[SETSIZ];
    
    if(is_empty(set1)) strcpy(result, set2); // have '\0'
    else if(is_element(set1[0], set2)) set_union(result, &set1[1], set2);
    else sprintf(result, "%c%s", set1[0], set_union(temp, &set1[1], set2));

    return result;
}

void print_with_comma(const char *str)
{
    if(strlen(str) == 1) putchar(str[0]);
    else{
        printf("%c, ",str[0]);
        print_with_comma(&str[1]);
    }
}

void print_set(const char *set)
{
    putchar('{');
    if(!is_empty(set)) print_with_comma(set) ;
    putchar('}');
}

void *get_set(char *set)
{
    char inset[SETSIZ];
    
    scanf("%s", inset);
    if(is_element('{', inset) || is_element('}', inset)){
        strncpy(set, &inset[1], strlen(inset)-2);
        set[strlen(inset)-2] = '\0';

        return set;
    }
    else return strcpy(set, inset);
}

int main()
{
    char ele, set_one[SETSIZ], set_two[SETSIZ], set_three[SETSIZ];

    // printf("\nEnter two sets to test set_union> ");
    // get_set(set_one);
    // get_set(set_two);
    // printf("\nThe union of ");
    // print_set(set_one);
    // printf(" and ");
    // print_set(set_two);
    // printf(" is ");
    // print_set(set_union(set_three, set_one, set_two));
    // putchar('\n');


    char *set;
    char *set2 = "test ";
    // set2[5] = '\0';
    // puts(set2);
    // set2 = "test ";
    strncpy(set, set2, 4);
    printf("%c\n",set[3]);
    set[4] = 'o';
    printf("%s\n",set);



    system("pause");
    return 0;
}