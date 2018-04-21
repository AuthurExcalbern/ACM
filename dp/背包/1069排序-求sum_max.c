#include<stdio.h>

int max(int x,int y)
{
	return x>y ? x:y;
}

struct DATA
{
    int a,b,h;//方块的长宽高
}dp1[100];//方块

int dp[100][100]={0};

int main()
{
    int n,a,b,h,t=1;//n为方块种类
    while(~scanf("%d",&n)&&n)
    {
        int i,j,j1,k=1,flag,ans=0;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&h);//读入n种不同方块的长宽高
            dp1[k].a=a;
            dp1[k].b=b;
            dp1[k++].h=h;
            dp1[k].a=h;
            dp1[k].b=b;
            dp1[k++].h=a;
            dp1[k].a=h;
            dp1[k].b=a;
            dp1[k++].h=b;//同一种方块的不同放法
        }
        for(j=1;j<k;j++)//收录每种放法的高
        {
            dp[1][j]=dp1[j].h;
        }
        for(i=2;i<k;i++)//对于每一种放法有用和不用两种状态，可以看为背包问题
        {
            flag=0;
            for(j=1;j<k;j++)
            {
                ans=0;
                for(j1=1;j1<k;j1++)
                {
                    if((dp1[j1].a>dp1[j].a && dp1[j1].b>dp1[j].b) || (dp1[j1].a>dp1[j].b && dp1[j1].b>dp1[j].a))
                    {
                        flag=1;
                        ans=max(dp[i-1][j1]+dp1[j].h,ans);
                    }
                }
                dp[i][j]=ans;
            }
            if(flag==0) break;
        }
        int max_=0;
        for(i=1;i<k;i++)//求出最高
        {
            for(j=1;j<k;j++)
            {
                max_=max(max_,dp[i][j]);
            }
        }
        printf("Case %d: maximum height = %d\n",t++,max_);
    }
    return 0;
}
