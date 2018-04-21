#include<stdio.h>
#include<string.h>
#define MAX 105
int dp[MAX][MAX];
int path[MAX][MAX];
int len[MAX];
int c[MAX],v[MAX],lest[MAX];
int q[MAX*MAX];
int vis[MAX];
int max(int a,int b){return a>b?a:b;}
void DP(int n,int m)
{if(m==0)return;
    int f=-1,r=-1,cur,pre,i,j;
    int tmp[MAX];
	memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(len[i]==1)
        {
		q[++r]=i;
		vis[i]=1;
        }
    }
    
    while(f!=r)
    {
	cur=q[++f];

	memcpy(tmp,dp[cur],sizeof(tmp));
    	for(i=0;i+lest[cur]<=m;i++)
    	{
		dp[cur][i+lest[cur]]=v[cur]+tmp[i];
    	}
        for(i=0;i<lest[cur];i++)dp[cur][i]=0;
        for(pre=0;pre<n;pre++)
        {
            if(vis[pre]==1||path[pre][cur]==0)continue;
			dp[cur][0]=dp[pre][0]=0;
			memcpy(tmp,dp[pre],sizeof(tmp));
            
            for(i=0;i<=m;i++)
            {
                for(j=0;j<=i;j++)
					dp[pre][i]=max(dp[pre][i],tmp[j]+dp[cur][i-j]);
            }
			len[pre]--;
            if(len[pre]==1)
            {
			vis[pre]=1;
			q[++r]=pre;
            }
        }
    }
}
int main()
{
    int n,m,i,j,k;
    //freopen("x.in","r",stdin);
    //freopen("x.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==-1&&m==-1)break;
        for(i=0;i<n;i++)
        {
			scanf("%d%d",&c[i],&v[i]);
			lest[i]=c[i]/20;
            if(c[i]%20!=0)lest[i]++;
        }
		k=n-1;
		memset(len,0,sizeof(len));
		memset(path,0,sizeof(path));
        while(k--)
        {
			scanf("%d%d",&i,&j);
			i--;
			j--;
			path[i][j]=path[j][i]=1;
			len[i]++;
			len[j]++;
        }
		len[0]++;
		memset(dp,0,sizeof(dp));

		DP(n,m);
        int ans=0;
        for(i=0;i<=m;i++)
			ans=max(ans,dp[0][i]);
		printf("%d\n",ans);
    }
    return 0;
}
