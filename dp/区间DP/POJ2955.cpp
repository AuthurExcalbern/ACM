/* POJ-2955
 * 
 * 题意：
 * []、()的匹配问题，问一个[]()串中匹配的字符数，匹配方式为[X],(X)
 * X为一个串，问一个长度为N(N<=100)串中最多的匹配字符个数
 * 
 * 简单区间dp问题，一下为求状态转移方程过程：
 * dp[l][r]代表区间[l, r]的最大匹配数
 * 先由长度为2的区间推出长度为3的区间，一直推到区间[l, r]
 * 
 * 在处理区间[l, r]时：
 * 
 * 如果s[l]与s[r]相匹配，那么dp[l][r] = dp[l+1][r-1] + 2
 * 如果不匹配这dp[l][r]先不变
 * 
 * 然后对于区间[l, r]的每个断点k，再求dp[l][r] = max(dp[l][r],dp[l][k] + dp[k+1][r])
 * 
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 150;

int dp[maxn][maxn];
char s[maxn];

int main(void)
{
    while(scanf("%s", s+1) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        if(s[1] == 'e')
            break;
        int len = strlen(s + 1);
        for(int l = 1; l <= len; l++)
        {
            for(int i = 1; i <= len - l + 1; i++)
            {
                int j = i + l - 1;
                if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
                    dp[i][j] = dp[i+1][j-1] + 2;
                for(int k = i; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
        printf("%d\n", dp[1][len]);
    }
    return 0;
}