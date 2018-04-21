#include<stdio.h>
#include<math.h>
#include<string.h>
#define INF (1<<15)//a = a << 2 将a的二进制位左移2位，右补0，左移1位后a = a * 2
struct homework
{
    char name[20];
    int dateline;
    int time;
}work[16];
char stack[20][101];
int snum;
int n;
int dp[INF][3];
int getdp()
{
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=((1<<n)-1);i++)
    {
        dp[i][0]=1<<30;
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1)))
            {
                int a=(dp[i-(1<<(j-1))][1]+work[j].time-work[j].dateline)>=0?(dp[i-(1<<(j-1))][1]+work[j].time-work[j].dateline):0;
                if(dp[i][0]>=dp[i-(1<<(j-1))][0]+a)
                {
                    dp[i][0]=dp[i-(1<<(j-1))][0]+a;
                    dp[i][1]=dp[i-(1<<(j-1))][1]+work[j].time;
                    dp[i][2]=i-(1<<(j-1));
                }
            }
        }
    }
    return 0;
}
int select(int i)
{
    for(int j=0;j<n;j++)
        if(1<<j==i)
            memcpy(stack[++snum],work[j+1].name,sizeof(work[j+1].name));
    return 0;
}
int main()
{
    int t;	
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s%d%d",work[i].name,&work[i].dateline,&work[i].time);
        getdp();
        int j=((1<<n)-1);
        printf("%d\n",dp[j][0]);
        snum=0;
        while(j!=0)
        {
            select(j-dp[j][2]);
            j=dp[j][2];
        }
        for(int z=snum;z>=1;z--)
            printf("%s\n",stack[z]);
    }
    return 0;
}