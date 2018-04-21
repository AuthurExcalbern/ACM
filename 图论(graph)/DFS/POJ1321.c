/*
 *POJ 1321
 *
 *URL:http://poj.org/problem?id=1321
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char map[10][10];     //记录棋盘位置
int book[10];        //记录一列是否已经放过棋子
int n, k;
int ans, record;    //ans 是放棋子的方案数 ，record是已放入棋盘的棋子数目

void DFS(int cnt)
{
    int j;//用于计数

    if(k == record)
    {
        ans++;
        return ;
    }

    if(cnt >= n)    //边界
        return ;

    for(j = 0; j < n; j++)
        if(book[j] == 0 && map[cnt][j] == '#')  //判断条件
        {
            book[j] = 1;           //标记
            record++;
            DFS(cnt + 1);
            book[j] = 0;           //改回来方便下一行的判断
            record--;
        }

    DFS(cnt + 1);                //到下一行(关键所在！！！）
}

int main(void)
{
    int i,j;//用于计数

    while(scanf("%d %d", &n, &k) && n != -1 && k != -1) //限制条件
    {
        ans = 0;
        record = 0;

        for(i = 0; i < n; i++)
            scanf("%s", *(map + i));

        memset(book, 0, sizeof(book));

        DFS(0);
        printf("%d\n",ans);
    }
    return 0;
}
