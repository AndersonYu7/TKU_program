#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b, t) ((t)=(a), (a)=(b), (b)=(t))

typedef struct node *node_ptr;
struct node{
    int data;
    node_ptr llink;
    node_ptr rlink;
};

void insertNode(node_ptr *head, node_ptr *rear, int data)
{
    node_ptr temp = (node_ptr)malloc(sizeof(*temp));
    temp->data = data;

    if(*head){
        temp->rlink = (*rear)->rlink;
        temp->llink = *rear;
        (*rear)->rlink->llink = temp;
        (*rear)->rlink = temp;
    } else{
        temp->llink = temp;
        temp->rlink = temp;
        *head = temp;
    }
    *rear = temp;
}

void deleteNode(node_ptr *head, node_ptr *rear, int deleted_data)
{
    node_ptr temp = *head;

    do{
        if(temp->data == deleted_data){
            temp->rlink->llink = temp->llink;
            temp->llink->rlink = temp->rlink;
            
            if(temp==*head) *head = (*head)->rlink;
            if(temp==*rear) *rear = (*rear)->llink;
            free(temp);

            return;
        }
        temp = temp->rlink;
    }while(temp!=*head);

    printf("There is no data that you want to delete!\n");

}

void bubble_sort(node_ptr head, char as_de[])
{
    node_ptr temp_1 = head;
    node_ptr temp_2 = head;

    do{
        while(temp_2!=temp_1){
            int temp;
            if(temp_2->data > temp_1->data && as_de == "ascending") 
                SWAP(temp_1->data, temp_2->data, temp);
            else if(temp_2->data < temp_1->data && as_de == "descending")
                SWAP(temp_1->data, temp_2->data, temp);
            
            temp_2 = temp_2->rlink;
        }
        temp_2 = head;
        temp_1 = temp_1->rlink;
    }while(temp_1!=head);
}

void printNode(node_ptr head)
{
    node_ptr temp = head;
    printf("The data: ");
    do{
        printf("%d ", temp->data);
        temp = temp->rlink;
    }while(temp!=head);
    puts("");
}

int main()
{
    srand(time(NULL));

    node_ptr head = NULL;
    node_ptr rear = head;

    for(int i=0;i<5;i++){
        int data = rand()%(1 + 50 - 1) + 1; 
        insertNode(&head, &rear, data);
    }
    printNode(head);

    int which_function;
    do{
        printf("Insert(1) or Delete(2) or Sort(3)\n");
        scanf("%d", &which_function);
        int insert_num;
        int delete_num;
        switch(which_function){
            case 1:
                printf("input the num u want to insert: ");
                scanf("%d", &insert_num);
                insertNode(&head, &rear, insert_num);
                printNode(head);
                break;
            
            case 2:
                printf("input a number u want to delete: ");
                scanf("%d", &delete_num);
                deleteNode(&head, &rear, delete_num);
                printNode(head);
                break;
            default: break;
        }
        puts("");
    }while(which_function!=3);

    printf("After sorting in ascending\n");
    bubble_sort(head, "ascending");
    printNode(head);

    printf("\nAfter sorting in descending\n");
    bubble_sort(head, "descending");
    printNode(head);

    return 0;
}