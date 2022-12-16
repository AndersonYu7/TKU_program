#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    printf("There is not the data that u want to delete!\n");

}

void bubble_sort(node_ptr head)
{
    node_ptr temp_1 = head;
    node_ptr temp_2 = head;

    do{
        while(temp_2!=temp_1){
            if(temp_2->data > temp_1->data){
                int data = temp_2->data;
                temp_2->data = temp_1->data;
                temp_1->data = data;
            }
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
        int data = rand()%(1 + 50 - 1) + 1; //1~20
        insertNode(&head, &rear, data);
    }

    printNode(head);
    printf("\nAfter sorting\n");
    bubble_sort(head);
    printNode(head);

    return 0;
}