#include<stdio.h>
#include<string.h>
#define CLR(a,b) memset(a,b,sizeof(a))

int N,cnt,res;
char graph[5][5];

struct Node
{
    int y,x;
    int flu;
}mark[20];

//Node ;
void Init();
int check(int i,int j);
int cmp(Node x,Node y)
{
	return x.flu < y.flu;
}


int main()
{
	while(scanf("%d",&N)!=EOF && N)
	{
		CLR(graph,0);
		CLR(mark,0);
		for(int i=0;i<N;i++)
			scanf("%s",graph[i]);
		Init();
		sort(mark,mark+cnt,cmp);
		for(int i=0;i<cnt;i++)	
		{
			if(check(mark[i].y,mark[i].x))
				res++;
		}
		printf("%d\n",res);		
	}	
	
	return 0;
}



void Init()
{
	cnt = 0;
	res = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(graph[i][j] == 'X')
				continue;
			mark[cnt].y = i;
			mark[cnt].x = j;
			for(int k=i-1;k>=0;k--)
			{
				if(graph[k][j] == '.')
					mark[cnt].flu++;
				else if(graph[k][j] == 'X')
					break;
			}
			for(int k=i+1;k<N;k++)
			{
				if(graph[k][j] == '.')
					mark[cnt].flu++;
				else if(graph[k][j] == 'X')
					break;
			}
			for(int k=j-1;k>=0;k--)
			{
				if(graph[i][k] == '.')
					mark[cnt].flu++;
				else if(graph[i][k] == 'X')
					break;
			}
			for(int k=j+1;k<N;k++)
			{
				if(graph[i][k] == '.')
					mark[cnt].flu++;
				else if(graph[i][k] == 'X')
					break;
			}		
			cnt++;
		}
	}
}

int check(int i,int j)
{
	if(graph[i][j] == 'B')
		return 0;
	for(int k=i-1;k>=0;k--)
	{
		if(graph[k][j] == 'B')
			return 0;
		else if(graph[k][j] == 'X')
			break;
	}	
	for(int k=i+1;k<N;k++)
	{
		if(graph[k][j] == 'B')
			return 0;
		else if(graph[k][j] == 'X')
			break;
	}	
	for(int k=j-1;k>=0;k--)
	{
		if(graph[i][k] == 'B')
			return 0;
		else if(graph[i][k] == 'X')
			break;
	}	
	for(int k=j+1;k<N;k++)
	{
		if(graph[i][k] == 'B')
			return 0;
		else if(graph[i][k] == 'X')
			break;
	}
	graph[i][j] = 'B';
	return 1;		
}

/*gg的代码

#include<stdio.h>//贪心：采取能放就放的原则
#include<string.h>
#define max(a,b) a>b?a:b

char Map[10][10];//这是地图
int vis[10][10];//这是用来记录在那一行那一列上已经放了东西的
int N;//地图大小

int isok(int x,int y)//用来检查这一点的上下左右是否为‘X'
{
    int i,j;
    for(i=x+1;i<N;i++)
        if(Map[i][y]=='X') break;
        else if(vis[i][y]) return 0;
    for(i=x-1;i>=0;i--)
        if(Map[i][y]=='X') break;
        else if(vis[i][y]) return 0;
    for(j=y+1;j<N;j++)
        if(Map[x][j]=='X') break;
        else if(vis[x][j]) return 0;
    for(j=y-1;j>=0;j--)
        if(Map[x][j]=='X') break;
        else if(vis[x][j]) return 0;
    return 1;
}

int ans;

void dfs(int x,int y,int count)//对于一个’X'，这函数用来搜索在它的行列上可以用来放东西的点
{
    int j,i;
    ans=max(ans,count);//用来更新ans
    for(j=y+1;j<N;j++)
        if(Map[x][j]!='X' && !vis[x][j] && isok(x,j))
        {
            vis[x][j]=1;//用来标记已经放了
            dfs(x,j,count+1);//广搜dfs
            vis[x][j]=0;//！！！！注意！！！！！还原状态！！！
        }
    for(i=x+1;i<N;i++)
        for(j=0;j<N;j++)
            if(Map[i][j]!='X' && !vis[i][j] &&isok(i,j))
            {
                vis[i][j]=1;
                dfs(i,j,count+1);
                vis[i][j]=0;
            }
}
int main()
{
    int i,j;
    while(scanf("%d",&N) != EOF)
    {
        if( N == 0)
            break;
        //memset(Map,'0',sizeof(Map));
        //getchar();
        printf("%d\n",N);
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                scanf("%c",&Map[i][j]);
        ans=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(Map[i][j]!='X')
                {
                    memset(vis,0,sizeof(vis));
                    vis[i][j]=1;
                    dfs(i,j,1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/