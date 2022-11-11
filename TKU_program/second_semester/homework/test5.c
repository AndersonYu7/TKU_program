#include <stdio.h> 
int travel(int x, int y);
int board[8][8] = {0}; //代表整個棋盤

int main(void) 
{ 
    int startx, starty; //記錄起點
    int i, j; 
    printf("輸入起始點："); 
    scanf("%d %d", &startx, &starty); 

    if(travel(startx, starty)) 
	{ 
           printf("遊歷完成\n"); 
	} 
    else
	{ 
           printf("遊歷失敗\n"); 
	} 

    for(i = 0; i < 8; i++) //列印
	{ 
           for(j = 0; j < 8; j++) 
		{
	           printf("%2d ", board[i][j]); 
		} 
        putchar('\n'); 
	} 
    return 0; 
} 

int travel(int x, int y) 
{ 
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //這兩行對應一個點可以走的八個方向的座標
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //
    int nexti[8] = {0}; //這兩行儲存的是可走的下一步的座標
    int nextj[8] = {0}; //
    int exists[8] = {0}; //記錄每個可走下一步的可走下一步個數
    int i, j, k, m, l; 
    int tmpi, tmpj; 
    int count, min, tmp; 
    i = x; 
    j = y; 
    board[i][j] = 1; //將起點座標置為1

    for(m = 2; m <= 64; m++)//通過迴圈來標記2-64
	{
          for(l = 0; l < 8; l++) 
              exists[l] = 0; //這個陣列是每次迴圈都要重複利用的，所以重置0
          l = 0; //這個l也是重複利用的
          for(k = 0; k < 8; k++) //通過迴圈判斷一個座標的八個方向是否可走
	     { 
                tmpi = i + ktmove1[k]; 
                tmpj = j + ktmove2[k]; 
                if(tmpi < 0 || tmpj < 0 || tmpi > 7 || tmpj > 7) //通過此來篩選是否可走
                     continue;
                if(board[tmpi][tmpj] == 0)//如果可走，就將可走的座標儲存在nexti，nextj中
		  { 
                     nexti[l] = tmpi; 
                     nextj[l] = tmpj; 
                     l++; //把下一步可走位置加一
		  } 
	   } 
         count = l; //將可走位置的數目賦值給count來進行一下判斷
         if(count == 0)//沒有下一步可走，就返回
	    { 
               return 0; 
	     } 
         else if(count == 1)//只有一個位置可走，就選擇這一步，然後繼續迴圈
	   { 
               min = 0; 
	    } 
         else //有多個位置可走時，判斷哪一個可走位置的下一步的可走位置最少，就走這一步，意思是把
	   {  //把最困難的走了，這樣接下來的空間就大了，可以走完所有位置的可能性就變大了
               for(l = 0; l < count; l++) //同時也說明這種非遞迴的方法不一定對於所有初始位置都能
		  {            //走遍全圖，因為畢竟這種演算法使用概率的原理
                      for(k = 0; k < 8; k++) 
			  { 
                              tmpi = nexti[l] + ktmove1[k];
                              tmpj = nextj[l] + ktmove2[k];
                              if(tmpi < 0 || tmpj < 0 || tmpi > 7 || tmpj > 7) 
				  { 
                                      continue; 
				  } 
                              if(board[tmpi][tmpj] == 0)
                                  exists[l]++; //記錄可走位置下一步可走位置的個數
			  } 
		  } 
              tmp = exists[0]; 
              min = 0; 
              for(l = 1; l < count; l++) 
	        { 
                  if(exists[l] < tmp) //取得可走位置下一步可走位置最少的那個座標
	            { 
                        tmp = exists[l]; 
                        min = l; 
		    } 
	        }
	   }
       i = nexti[min]; 
       j = nextj[min]; 
       board[i][j] = m; //將當前步數賦值給那個可走位置下一步可走位置最少的那個座標
        printf("%d %d\n", i, j);
        printf("l:%d\n", l);

       } 

    return 1; 
} 