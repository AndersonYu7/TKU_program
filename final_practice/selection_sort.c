#include <stdio.h>
#include <stdlib.h>

int find_min(int list[], int first, int size);
void selection_sort(int list[], int size);
void selection_sort2(int list[], int size);
void re_find_max_and_move(int list[], int size);
void recursive_selection_sort(int list[], int size);
int find_max(int list[], int size);
int selection_sort_max(int list[], int size);
int selection_sort_max2(int list[], int size);
void re_find_min_and_move(int list[], int first, int size);
void recursive_selection_sort_min(int list[], int size);
int main()
{
    int a[5] = {5,4,3,2,1};
    selection_sort(a, 5);
    for(int i=0;i<5;i++) printf("%d ",a[i]);
    putchar('\n');

    int b[5] = {5,4,3,2,1};
    selection_sort2(b, 5);
    for(int i=0;i<5;i++) printf("%d ",b[i]);
    putchar('\n');

    int c[5] = {5,4,3,2,1};
    recursive_selection_sort(c, 5);
    for(int i=0;i<5;i++) printf("%d ",c[i]);
    putchar('\n');

    int d[5] = {5,4,3,2,1};
    selection_sort_max(d, 5);
    for(int i=0;i<5;i++) printf("%d ",d[i]);
    putchar('\n');

    int e[5] = {5,4,3,2,1};
    selection_sort_max2(e, 5);
    for(int i=0;i<5;i++) printf("%d ",e[i]);
    putchar('\n');

    int f[5] = {5,4,3,2,1};
    recursive_selection_sort_min(f, 5);
    for(int i=0;i<5;i++) printf("%d ",f[i]);
    putchar('\n');

    system("pause");
    return 0;
}

int find_min(int list[], int first, int size)
{
    int min_index = first,
        min_value = list[first];

    for(int i=first+1;i<size;i++){
        if(list[i] < min_value){
            min_index = i;
            min_value = list[i];
        }
    }

    return min_index;
}

void selection_sort(int list[], int size) //fin min and move to first one
{
    for(int i=0;i<size-1;i++){
        int min_index = find_min(list, i, size);

        if(i != min_index){
            int temp = list[i];
            list[i] = list[min_index];
            list[min_index] = temp;
        }
    }
}

void selection_sort2(int list[], int size) //find min and move to first one
{
    for(int i=0;i<size-1;i++){
        int min_index = i;

        for(int j=i+1;j<size;j++){
            if(list[j]<list[min_index]) min_index = j;
        }

        int temp = list[i];
        list[i] = list[min_index];
        list[min_index] = temp;
    }
}

void re_find_max_and_move(int list[], int size)  
{
    int max_index = size-1;

    for(int i=0;i<size-1;i++){
        if(list[i]>list[max_index]) max_index = i;
    }

    if(max_index != size -1){
        int temp = list[max_index];
        list[max_index] = list[size-1];
        list[size-1] = temp;
    }

}

void recursive_selection_sort(int list[], int size) //find max and move to last one
{
    if(size>1){
        re_find_max_and_move(list, size);
        recursive_selection_sort(list, size-1);
    }
}

int find_max(int list[], int size)
{
    int max_index = size-1;
    for(int i=0;i<size-1;i++){
        if(list[i]>list[max_index]) max_index = i;
    }

    return max_index;
}

int selection_sort_max(int list[], int size) //find max and move to last one
{
    int max_index = size-1;

    for(int i=size-1;i>=0;i--){
        int max_index = find_max(list, size--);

        if(max_index != i){
            int temp = list[max_index];
            list[max_index] = list[i];
            list[i] = temp;
        }
    }
}

int selection_sort_max2(int list[], int size) //find max and move to last one
{
    for(int i=size-1;i>=0;i--){
        int max_index = i;

        for(int j=i-1;j>=0;j--){
            if(list[max_index]<list[j]) max_index = j;
        }

        int temp = list[max_index];
        list[max_index] = list[i];
        list[i] = temp;

    }
}

void re_find_min_and_move(int list[], int first, int size)
{
    int min_index = first;

    for(int i=first+1;i<size;i++){
        if(list[i] < list[min_index]) min_index = i;
    }

    int temp = list[first];
    list[first] = list[min_index];
    list[min_index] = temp;
}

static int n=0;
void recursive_selection_sort_min(int list[], int size) //find max and move to last one
{
    static int n;
    if(n!=size-1){
        re_find_min_and_move(list, n++, size);
        recursive_selection_sort_min(list, size-1);
    }
}