#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int map[SIZE][SIZE] = {0};
int dir_ROW[SIZE] = {1,1,2,2,-1,-1,-2,-2}; //方向
int dir_COL[SIZE] = {2,-2,1,-1,2,-2,1,-1};

struct S{
    int row;
    int col;
};
typedef struct S step;

int possible(step current){ //查看當下位置是否正確
    if(current.row < 0 || current.row >=SIZE || current.col < 0 || current.col >=SIZE || map[current.col][current.row] == 1)
        return 0;
    else
        return 1;
}

int count_Path(step current){ //數當下有幾條出路(0~8)
    step next; //相當於nextnext，current->next->nextnext
    int counter=0;
    for(int i=0;i<SIZE;i++){
        next.row = current.row + dir_ROW[i]; // nextnext = next+dir[i]
        next.col = current.col + dir_COL[i]; 
        if(possible(next)){//如果nextnext位置存在，表示有出路
            counter++; //算有幾個出路
        }
    }
    return counter;
}

step Find_Min_Path(step next[],int *Path_num){ //找到最小的出路，並將此位置回傳給current，
    step go_next; //go_next是存最小出路
    int min_Path = 8;
    for(int i=0;i<SIZE;i++){
        if(Path_num[i] < min_Path && Path_num[i] != -1){ //找最小的出路
            go_next = next[i]; 
            min_Path = Path_num[i];
        }
    }
    return go_next;
}


int tarvel(step current){
    step next;
    step NEXT[SIZE]; //儲存next的有效位置
    int Path_num[SIZE] = {0}; //存NEXT[i]有多少出路
    int dir_index,nextStep = 0; //dir_index:記只有一條出路的方向index nextStep:數可移動方向的個數

    printf("(%d,%d)->",current.row,current.col);
    for(int stepNum=2;stepNum<=64;stepNum++){
        map[current.col][current.row] = 1; //標示已走過
        for(int i=0;i<SIZE;i++){ //往8種方向走
            next.row = current.row + dir_ROW[i];
            next.col = current.col + dir_COL[i];
            if(possible(next)){//如果next位置有效
                nextStep++;
                dir_index = i;
                NEXT[i] = next;
                Path_num[i] = count_Path(next);//數當在next的時候有幾條出路
            }else{
                Path_num[i] = -1;
            }
        }

        if(nextStep == 0 && stepNum < 64){//走到死路
            return 0;
        }else if(nextStep == 1){//只有一條路
            current = NEXT[dir_index];
        }else{
            current = Find_Min_Path(NEXT,Path_num);//找出最小出路的next，並傳給current(迭代)
        }

        if(stepNum == 64) printf("(%d,%d)",current.row,current.col);
        else printf("(%d,%d)->",current.row,current.col);
        
        if(stepNum % 8 == 0) puts("");
        nextStep = 0;
    }
    return 1;
}


int main(){//看在我認真寫註解的份上，問少一點吧，沒問題吧太學! :)
    int row,col;
    printf("Input row col(0~7)[EX:0 0] >");
    scanf("%d %d",&row,&col);
    step start = {row,col};
    if(!tarvel(start)){ //tarvel = 0代表沒找到(給南投人:我這次總沒反人性吧)
        printf("NO FOUND!\n");
    }
    system("pause");
}