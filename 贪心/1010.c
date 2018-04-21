//http://blog.sina.com.cn/s/blog_a0d75e850100ydgs.html
//不要骂我 哈哈哈哈
// 求大神解释剪枝 。。。。。
#include<stdio.h>
#include<math.h>
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int di,dj;
int si,sj;
int is;
char map[10][10];
int n,m,T,word;
void dfs(int di,int dj,int t)//在这我们传了三个量 一个是狗狗位置 x，y 还有一个就是该死的出题者给的步数
{
	int i;
	if(di<1||dj<1||di>n||dj>m||t>T||is)//这里不知道各位有没有看懂 就是杂七杂八的判断了一些不可能的情况
        return; // 比如有狗狗 眼睛不好走到地图外的情况或者超时的情况
	if(si==di && sj==dj && t==T) //在这里狗狗就要笑了 小样还想关我  狗狗艰难的爬过了九九八十一难并且在规定的时间内找到了出口我们就给它一个胜利的标记
    {
        is=1;
        return ;
    }
	if ((abs(di-si)+abs(dj-sj))%2!=(T-t)%2) return ;//这里是剪枝 用来优化的 去掉一些不可能的情况不用在进行搜索的情况 我也不懂求大神教
	for(i=0;i<4;i++)//这边就控制狗狗的四个方位递归思想回溯
	{
		if(map[di+dx[i]][dj+dy[i]]!='X')//判断狗狗周围的路是不是墙 是墙那狗狗也不是笨狗 当然还是会绕路走的
		{
			map[di+dx[i]][dj+dy[i]]='X';//如果这条路不是墙 嘿嘿 狗狗就昂头挺胸甩着尾巴 大步向前走 妹妹你推车哥哥大步向前走；
			dfs(di+dx[i],dj+dy[i],t+1);		//当然狗狗每走一步我们就要在这个点上向之前一样再进行四个方向的判断
			map[di+dx[i]][dj+dy[i]]='.';
		}
	}
	return;
}
int main()
{
	
	int i,j;
	while(~scanf("%d%d%d",&n,&m,&T)&&n!=0)
	{
		word=0;
		getchar();
		for(i=1;i<=n;i++)//这里是输入不用多说了
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')//我们把 狗狗的初始位置记录下来
				{
					di=i;dj=j;
				}
				if(map[i][j]=='D')//出口的初始位置记录
				{
					si=i;sj=j;
				}
				if(map[i][j]=='X')//墙的数量也记录下来
				{
					word++;
				}
			}
			getchar();
		
		}
		is=0;
		if(n*m-word<T)//地图上 所有的点 减去 墙的数量 小于 给定的步数那么肯定可以过的
						
			is=0;//因为 如果所有的点都在规定步数中走完还走不到那个点 要么那个点周围的墙都是封死的这狗狗会在孤独中死去因为没法进门了！！
		else	// 要么就是没有这个门这个更狠了 这狗狗在这图上走好久好久才发现该死的出题者没有设门！！ 这个两个都是错误的图题目不会出
		{
			map[di][dj]='X';//我们把迈出的第一步变成墙封死这样就防止这条狗走回路 他知道是墙就不会给墙撞死 
			dfs(di,dj,0);//这里我们到上面的函数去
		}
		if(is==1)
			printf("YES\n"); //GOOD
		else
			printf("NO\n");//DARK!!
	}
}

