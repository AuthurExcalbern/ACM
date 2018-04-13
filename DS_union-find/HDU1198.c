/*
 * HDU 1198
 *
 * URL:http://acm.hdu.edu.cn/showproblem.php?pid=1198
 *
 * 注意边界的应用
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MA 55

int N, M;
int mp[MA][MA];

/***********************************并查集模板***********************************/
//并查集基本模板
//fa需要初始化：memset(fa, -1, sizeof(fa))
//fa[i]表示i节点的父节点
int fa[MA * MA];

//返回x节点的根，同时使得x节点直接挂在根节点下面
int findset(int x)
{
    return fa[x] == -1 ? x : (fa[x] = findset(fa[x]) );
}

//合并u与v所属的联通分支
int bind(int u, int v)
{
    int fu = findset(u);//获取根
    int fv = findset(v);//获取根
    if(fu != fv)//根不同->术语不同联通分量->可合并
    {
        fa[fu]=fv;
        return 1;
    }
    return 0;
}

/***********************************并查集模板***********************************/
  
//原始矩形的连通情况
int con[11][4]={
    {1,0,1,0},//A块的上下左右
    {1,0,0,1},//B
    {0,1,1,0},//C
    {0,1,0,1},//D
    {1,1,0,0},//E
    {0,0,1,1},//F
    {1,0,1,1},//G
    {1,1,1,0},//H
    {0,1,1,1},//I
    {1,1,0,1},//J
    {1,1,1,1}//K
};

//往上下左右四个方向移动时，X(行),Y(列)的增量
int dir_x[]={-1,1,0,0};//上下左右
int dir_y[]={0,0,-1,1};

int main(void)
{
    int i, j, ans;
    int x, y, dir;
    int nx, ny, ndir, nid, id;
    char ch;

    while(scanf("%d%d", &N, &M), N >= 0 && M >= 0)
    {
        //读入地图并转化为int储存
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)  
            {  
                scanf(" %c", &ch);  
                mp[i][j] = ch - 'A';  
            }

        memset(fa,-1,sizeof(fa));
        ans = N * M;//原始连通分量数目

        //遍历矩阵,合并连通分量
        for(x = 0; x < N; x++)//行
            for(y = 0; y < M; y++)//列  
            {
                id = x * M + y;//当前格子的编号  
                for(dir = 0; dir < 4; dir++)//判断dir方向的格子是否连通  
                {
                    nx = x + dir_x[dir];  
                    ny = y + dir_y[dir];  
                    ndir = ( (dir % 2) == 0 ? (dir+1) : (dir-1) );//dir的反向  
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M)//判断边界情况  
                    {
                        nid = nx * M + ny;//相邻格子的编号  
                        if(con[mp[x][y]][dir] == 1 && con[mp[nx][ny]][ndir] == 1)//如果连通  
                        {
                            ans = ans - bind(id,nid);//查是否要减一  
                        }
                    }
                }
            }

        //输出结果
        printf("%d\n",ans);
    }
    return 0;
}
