/*
 * HDU 1159
 *
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1159
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) (a>b?a:b)

char str1[2000], str2[2000];
int dp[1000][1000];
int len1, len2;

void LcsLenth()//求最大公共子序列，dp[i][j]表示两数组在i和j间的最大公共子序列
{
    int i, j;

    for(i = 1; i <= len1; i++)
    {
        for(j = 1; j <= len2; j++)
        {
            if(str1[i] == str2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

int main(void)
{
    while(scanf("%s%s",str1 + 1,str2 + 1) != EOF)//这里是从str[1]开始录入
    {
        memset(dp, 0, sizeof(dp));
        len1 = strlen(str1 + 1);
        len2 = strlen(str2 + 1);
        LcsLenth();
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}
