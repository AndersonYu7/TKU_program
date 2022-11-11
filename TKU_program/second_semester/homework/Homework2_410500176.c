#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int board[SIZE][SIZE] = {0};; //代表整個棋盤
int ktmove1[SIZE] = {-2, -1, 1, 2, 2, 1, -1, -2};   //x座標方向
int ktmove2[SIZE] = {1, 2, 2 ,1, -1, -2, -2, -1};   //y座標方向

typedef struct{
    int x;
    int y;
}step;

int possible(step current)  //判斷是否超出邊界
{
    if(current.x < 0 || current.x >=SIZE || current.y < 0 || current.y >= SIZE)
        return 0;
    else 
        return 1;
}

step find_min(step NEXT[], int npos, int *min)  //找出下一個出口數最少的格子
{
    step next_next;
    int exist[SIZE] = {0};
    for(int i=0;i<npos;i++){
        for(int j=0;j<SIZE;j++){
            next_next.x = NEXT[i].x + ktmove1[j];
            next_next.y = NEXT[i].y + ktmove2[j];
            if(!possible(next_next)) continue;
            if(board[next_next.x][next_next.y] == 0)
                exist[i]++;
        }
    }

    int temp = exist[0];
    *min = 0;
    for(int i=1;i<npos;i++){
        if(exist[i]<temp){
            temp = exist[i];
            *min = i;
        }
    }
    step MIN = {NEXT[*min].x, NEXT[*min].y};
    return MIN;
}

int travel(step current)
{
    printf("(%d,%d)->", current.x, current.y);
    
    board[current.x][current.y] = 1; 
    step next;
    step NEXT[SIZE];
    int min;
    for(int m=2;m<=SIZE*SIZE;m++){
        int npos = 0;
        for(int i=0;i<SIZE;i++){
            next.x = current.x + ktmove1[i];
            next.y = current.y + ktmove2[i];
            if(!possible(next)) continue;   //已超出邊界
            if(!board[next.x][next.y])  //當還沒走過
                NEXT[npos++] = next;
        }
        if(npos == 0) return 0; //find the min steps
        else if(npos == 1){
            min = 0;
            current = NEXT[0];
        }
        else  
            current = find_min(NEXT, npos, &min);

        board[current.x][current.y] = m;

        if(m==64) printf("(%d,%d)", current.x, current.y);
        else printf("(%d,%d)->", current.x, current.y);
        if(m%8==0) puts("");
    }

    return 1;
}

int main()
{
    step start;
    printf("Input the start position(i.e.(x, y) :(0, 0)~(7, 7)): ");
    scanf("%d %d", &start.x, &start.y);
    if(!travel(start)) printf("No Found!\n");

    return 0;
}

