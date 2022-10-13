#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 300
#define min 0

#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

void scanf_skip(char *ch)
{
    while(1){
        scanf("%c", ch);
        if(*ch != '\n' && *ch != ' ') break;
    }
}

void print_array(int *arr, int size)
{
    printf("{");
    for(int i=0;i<size;i++){
        if(i!=size-1) printf("%d, ", arr[i]);
        else printf("%d", arr[i]);
    }
    printf("}\n");
}

void print_result(int result)
{
    if(result == -1) printf("The number you search is not found\n");
    else printf("The number you search is found at position %d\n", result);
}

void random_numbers(int *arr, int size)
{
    for(int i=0;i<size;i++) arr[i] = rand()%(Max - min + 1) + min;
}

void bubble_sort(int *arr, int size)
{
    for(int i=0; i<size;i++){
        for(int j=0; j<size-1;j++){
            if(*(arr+j) > *(arr+j+1)){
                int temp;
                SWAP(arr[j], arr[j+1], temp);
            }
        }
    }
}

int iterative_bin(int *arr, int size, int search)
{
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == search) return mid;
        else if(arr[mid] < search) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int recursive_bin(int *arr, int left, int right, int search)
{
    if(right >= left){
        int mid = (right+left)/2;

        if(arr[mid] == search) return mid;
        else if(arr[mid] < search) return recursive_bin(arr, mid + 1, right, search);
        else return recursive_bin(arr, left, mid - 1, search);
    }

    return -1;
}

int iterative_seq(int *arr, int size, int search)
{
    int found = 0, i;
    for(i=0;i<size;i++){
        if(arr[i] == search){
            found = 1;
            break;
        }
    }

    if(found == 1) return i;
    else return -1;
}

int recursive_seq(int *arr, int size, int search)
{
    size--;
    if(size >= 0){
        if(arr[size]==search) return size;
        else return recursive_seq(arr, size, search);
    }

    return -1;
}

void your_choice(int *arr, int size)
{
    char choice;
    int bool = 1;

    while(bool){
        printf("please input the number of your choice or press Q to leave the program:\n");
        printf("1. iterative binary search\n");
        printf("2. recursive binary search\n");
        printf("3. iterative sequential search\n");
        printf("4. recursive sequential search\n");

        scanf_skip(&choice);

        int search = 0, result = 0;
        switch (choice)
        {
            case '1':
                printf("iterative binary search start....\n");
                printf("please input the number you want to search\n");
                scanf("%d", &search);
                result = iterative_bin(arr, size, search);
                print_result(result);
                break;

            case '2':
                printf("recursive binary search start....\n");
                printf("please input the number you want to search\n");
                scanf("%d", &search);
                result = recursive_bin(arr, 0, size-1, search);
                print_result(result);
                break;

            case '3':
                printf("iterative sequential search start....\n");
                printf("please input the number you want to search\n");
                scanf("%d", &search);
                result = iterative_seq(arr, size, search);
                print_result(result);
                break;

            case '4':
                printf("recursive sequential search start....\n");
                printf("please input the number you want to search\n");
                scanf("%d", &search);
                result = recursive_seq(arr, size, search);
                print_result(result);
                break;

            case 'q':
            case 'Q':
                bool = 0;
                break;

            default:
                break;
        }
    }
}

int main()
{
    srand(time(NULL));

    int how_many_num;

    printf("How many numbers do you want to generate?\n");
    scanf("%d", &how_many_num);

    int *arr = (int *)malloc(sizeof(int)*how_many_num); 
    random_numbers(arr, how_many_num);                      

    printf("The generate numbers are:\n");
    print_array(arr, how_many_num);

    bubble_sort(arr, how_many_num);                         

    printf("After sorting....\n");
    print_array(arr, how_many_num);

    your_choice(arr, how_many_num);                         

    printf("exit the program");

    free(arr);
    return 0;
}