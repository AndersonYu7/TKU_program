#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SETSIZ 65
#define TRUE 1
#define FALSE 0

int is_empty(const char*set);
int is_element(char ele, const char *set);
int is_set(const char *set);
int is_subset(const char *sub, const char *set);
char *set_union(char *result, const char *set1, const char *set2);
void print_with_comma(const char *str);
void print_set(const char *set);
char *get_set(char *set);

int main()
{
    char ele, set_one[SETSIZ], set_two[SETSIZ], set_three[SETSIZ];

    printf("A set is entered in {} ");
    printf("{no duplicate characters}\n");
    printf("For example, {a, b, c} is entered as {abc}\n");

    printf("Enter a set to test validation function> ");
    get_set(set_one);
    putchar('\n');
    print_set(set_one);
    if(is_set(set_one)) printf(" is a vaild set\n");
    else printf(" is invalid\n");

    printf("Enter a single character, a space, and a set> ");
    while(isspace(ele = getchar()));

    get_set(set_one);
    printf("\n%c ",ele);
    if(is_element(ele, set_one)) printf("is an element of ");
    else printf("is not an element of");
    print_set(set_one);

    printf("\nEnter two sets to test set_union> ");
    get_set(set_one);
    get_set(set_two);
    printf("\nThe union of ");
    print_set(set_one);
    printf(" and ");
    print_set(set_two);
    printf(" is ");
    print_set(set_union(set_three, set_one, set_two));
    putchar('\n');

    system("pause");
    return 0;
}

int is_empty(const char *set)
{
    return set[0] == '\0';
}

int is_element(char ele, const char *set)
{
    int ans;

    if(is_empty(set)) ans = FALSE;
    else if(set[0] == ele) ans = TRUE;
    else ans = is_element(ele, &set[1]);

    return ans;
}
 
int is_set(const char *set)
{
    int ans;
    
    if(is_empty(set)) ans = TRUE;
    else if(is_element(set[0], &set[1])) ans = FALSE;
    else ans = is_set(&set[1]);

    return ans;
}

int is_subset(const char *sub, const char *set)
{
    int ans;

    if(is_empty(sub)) ans = TRUE;
    else if(!is_element(sub[0], set)) ans = FALSE;
    else ans = is_subset(&sub[1], set);

    return ans;
}

char *set_union(char *result, const char *set1, const char *set2)
{
    char temp[SETSIZ];

    if(is_empty(set1)) strcpy(result, set2);
    else if(is_element(set1[0], set2)) set_union(result, &set1[1], set2);
    else sprintf(result, "%c%s", set1[0], set_union(temp, &set1[1], set2));

    return result;
}

void print_with_comma(const char *str)
{
    if(strlen(str) == 1) putchar(str[0]);
    else{
        printf("%c, ", str[0]);
        print_with_comma(&str[1]);
    }
}

void print_set(const char *set)
{
    putchar('{');
    if(!is_empty(set)) print_with_comma(set);
    putchar('}');
}

char *get_set(char *set)
{
    char inset[SETSIZ];

    scanf("%s", inset);
    strncpy(set, &inset[1], strlen(inset) - 2);
    set[strlen(inset) - 2] = '\0';

    return set;
}