//FIFO (First In First Out，先入先出)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 6
#define true 1
#define false 0

typedef struct {
    int key;
}element;

element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

void queueFull()
{
    fprintf(stderr, "queue is full, and it can not add any element");
    exit(EXIT_FAILURE);
}


void addq(element item)
{
    rear = (rear+1)%MAX_QUEUE_SIZE;
    if(rear ==  front)
        queueFull();

    queue[rear] = item;
}

element deleteq()
{
    if(front == rear){
        fprintf(stderr, "queue is empty,and it can not delete any element");
        exit(EXIT_FAILURE);
    }
    front = (front+1)%MAX_QUEUE_SIZE;
    return queue[front];
}

int main()
{
    element item;

    char fuc[5];
    while(scanf("%s", &fuc)){
        int addq_ = false;
        int deleteq_ = false;

        if(!strcmp(fuc, "addq")) addq_ = true;
        else if(addq_==false && !strcmp(fuc, "deleteq")) deleteq_ = true;
        else if(!strcmp(fuc, "q")) exit(EXIT_FAILURE);

        if(deleteq_ && !addq_) deleteq();
        else if(addq_ && !deleteq_){
            scanf("%d", &item.key);
            addq(item);
        }
 
            for(int i = rear;i>front;i--) printf("%d\n", queue[i].key);
            printf("front %d\nrear %d\n", front, rear);


    }


    return 0;
}