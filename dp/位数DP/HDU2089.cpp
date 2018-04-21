/* HDU-2089
 * 
 * 题意：
 * 对于每个整数对，输出一个不含有不吉利数字的统计个数
 * 
 * 数位dp入门题
 * 判断没有4只要枚举就可以
 * 判断没有连续的62的话需要判断两位
 * 当前一位是6或者不是6这两种不同情况计数是不相同的，所以要用状态来记录不同的方案数
 * dp[pos][sta]表示当前第pos位，前一位是否是6的状态，
 * 这里sta只需要去0和1两种状态就可以了，不是6的情况可视为同种，不会影响计数
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

int a[20];
int dp[20][2];

int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos == -1)
        return 1;
    if(!limit && dp[pos][sta] != -1)
        return dp[pos][sta];
    
    int up = limit ? a[pos] : 9;
    int tmp = 0;
    
    for(int i = 0; i <= up; i++)
    {
        if(pre == 6 && i == 2)
            continue;
        if(i == 4)
            continue;//都是保证枚举合法性
        
        tmp += dfs(pos-1, i, i==6, limit && i==a[pos]);
    }
    
    if(!limit)
        dp[pos][sta]=tmp;
    return tmp;
}

int solve(int x)
{
    int pos = 0;
    while(x)
    {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, -1, 0, true);
}

int main(void)
{
    int le,ri;
    while(~scanf("%d%d", &le, &ri) && le+ri)
    {
        memset(dp, -1, sizeof(dp));
        printf("%d\n",solve(ri) - solve(le-1));
    }
    return 0;
}