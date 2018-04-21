#pragma warning(disable:4996) 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstdlib>
#include <set>
using namespace std;

int dp[1<<16][2];
int dp2[1<<16][20];

struct Node
{
    char s[110];
    int zui;
    int tim;
}a[16];

bool cmp(Node x,Node y)
{
    return strcmp(x.s,y.s)<0;
}

int main()
{
    int t,n,i,j,k,digit,carry,res,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d",a[i].s,&a[i].zui,&a[i].tim);
        }
        sort(a,a+n,cmp);
        memset(dp,0x7f,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        dp[0][0]=dp[0][1]=0;
        digit=1<<n;
        for(i=0;i<digit;i++)
        {
            for(j=0;j<n;j++)
            {
                res=1<<j;
                if(i&res)continue;
                carry=a[j].tim+dp[i][0];
                if(carry<=a[j].zui)carry=0;
                else carry=carry-a[j].zui;
                if(carry+dp[i][1]<dp[i|res][1])
                {
                    for(k=1;k<=dp2[i][0];k++)
                    {
                        dp2[i|res][k]=dp2[i][k];
                    }
                    dp2[i|res][dp2[i][0]+1]=j;
                    dp2[i|res][0]=dp2[i][0]+1;
                    dp[i|res][1]=carry+dp[i][1];
                    dp[i|res][0]=a[j].tim+dp[i][0];
                }
            }
        }
        printf("%d\n",dp[digit-1][1]);
        for(i=1;i<=dp2[digit-1][0];i++)
        {
            res=dp2[digit-1][i];
            puts(a[res].s);
        }
    }
    return 0;
}