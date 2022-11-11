//FIFO (First In First Out，先入先出)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 101
#define true 1
#define false 0

typedef struct {
    int key;
}element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

void queueFull()
{
    fprintf(stderr, "queue is full, and it can not add any element");
    exit(EXIT_FAILURE);
}


void addq(element item)
{
    if(rear == MAX_QUEUE_SIZE - 1)
        queueFull();

    queue[++rear] = item;
    if(front == -1) front = 0;
}

element deleteq()
{
    if(front == rear){
        fprintf(stderr, "queue is empty,and it can not delete any element");
        exit(EXIT_FAILURE);
    }
    return queue[++front];
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

        if(front!=-1)
            for(int i = rear;i>=front;i--) printf("%d\n", queue[i].key);
        else   
            for(int i = rear;i>front;i--) printf("%d\n", queue[i].key);


    }


    return 0;
}