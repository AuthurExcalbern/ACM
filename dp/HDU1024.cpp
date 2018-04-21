/* 给一串数字 sum(i,j)代表从i数字加到j数字
   给定数字m，求m个区间的sum的最大值
*/
#include<cstdio>
#include<algorithm>
#define MAXN 1000010
#define INF 0x7fffffff

int dp[MAXN];
int mmax[MAXN];
int a[MAXN];

int main(void)
{
    int n, m;
    int ans;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            dp[i] = 0;
            mmax[i] = 0;
        }
        dp[0] = 0;
        mmax[0] = 0;
        for(int i = 1; i <= m; i++)
        {
            ans = -INF;
            for(int j = i; j <= n; j++)
            {
                dp[j] = std::max(dp[j-1]+a[j], mmax[j-1]+a[j]);
                mmax[j-1] = ans;
                ans = std::max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
