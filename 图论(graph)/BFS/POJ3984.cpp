/* POJ-3984 迷宫问题
 * 
 * 简单搜索入门题，可以用bfs，需要记录一下路径
 * 
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;

const int dist_x[4] = {-1,1,0,0};//四个移动的方向
const int dist_y[4] = {0,0,-1,1};
int dist[10][10];//记录走的是第几步
int visit[10][10];//标记已经访问过的点
int gra[10][10];//保存输入的地图

struct node
{
    int x, y;
};

void bfs(int x, int y)//输入起始点(x, y),进行bfs搜索
{
    queue<node> que;//创建一个队列
    
    memset(visit, 0, sizeof(visit));//初始化
    memset(dist, 0, sizeof(dist));
    node start_node;//起始点
    start_node.x = x;
    start_node.y = y;
    
    dist[x][y] = 0;//起始为0步
    que.push(start_node);
    visit[x][y] = 1;
    
    while(!que.empty())//利用队列来进行bfs
    {
        node n = que.front();
        que.pop();
        if(n.x == 5 && n.y == 5)//到达终点结束
            return;
        
        for(int i = 0; i < 4; i++)//搜索四个方向，可行的点则加入队列
        {
            int xx = n.x + dist_x[i];
            int yy = n.y + dist_y[i];
            if(!visit[xx][yy] && gra[xx][yy] == 0 && xx >= 1 && xx <=5 && yy >= 1 && yy <= 5)
            {
                visit[xx][yy] = 1;
                dist[xx][yy] = dist[n.x][n.y] + 1;
                node n2;
                n2.x = xx;
                n2.y = yy;
                que.push(n2);
            }
        }
    }
}

void print_path(node n1, node n2)//从终点反向查找并输出路径
{
    if((n2.x == n1.x) && (n1.y == n2.y))
        return;
    for(int i = 0; i < 4; i++)
    {
        int xx = n2.x + dist_x[i];
        int yy = n2.y + dist_y[i];
        if((dist[n2.x][n2.y] == dist[xx][yy] + 1) && visit[xx][yy])
        {
            node n3;
            n3.x = xx;
            n3.y = yy;
            print_path(n1, n3);
            printf("(%d, %d)\n", n3.x-1, n3.y-1);
        }
    }
    return;
}

int main(void)
{
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            scanf("%d", &gra[i][j]);
    bfs(1,1);
    node n1, n2;
    n1.x = 1;
    n1.y = 1;
    n2.x = 5;
    n2.y = 5;
    print_path(n1, n2);
    printf("(4, 4)");
    return 0;
}

