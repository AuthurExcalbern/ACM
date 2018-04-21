#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,m,n;
    int dp[10001];
    int a[3]={150,200,350};
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);//输入容量
        memset(dp,0,sizeof(dp));
        for(i=0;i<3;i++)
        {
            for(j=a[i];j<=m;j++)
            {
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
    	}
        printf("%d\n",m-dp[m]);
    }
    return 0;
}