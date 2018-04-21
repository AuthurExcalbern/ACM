/*
S(n,k)表示将n个不同的物品放到k个相同的盒子里，每个盒子至少有一个物品的种类数。
递推式：S(n,k)=S(n-1,k-1)+k*S(n-1,k)，S(1,1)=1，S(n,n)=1。

这题要求的就是Sum(n)=S(n,1)+S(n,2)+S(n,3)+...+S(n,k-1)+S(n,k)，开一个sum[]数组存Sum(n)，喜欢打表的人最爱的题目。
*/


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 2005
#define MOD 1000

int strling[MAXN][MAXN];
int sum[MAXN];

void Strling_table()
{
    int i,j,tmp;
    memset(strling,0,sizeof(strling));
    memset(sum,0,sizeof(sum));
    strling[1][1]=1;
    sum[1]=1;
    for(i=2;i<MAXN;i++)
    {
        tmp=1;
        for(j=1;j<i;j++)
        {
            strling[i][j]=(strling[i-1][j-1]+j*strling[i-1][j])%MOD;
            tmp+=strling[i][j];
            tmp%=MOD;
        }
        strling[i][i]=1;
        sum[i]=tmp%MOD;
    }
}

int main()
{
    int n,x;
    Strling_table();
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&x);
            printf("%d\n",sum[x]);
        }
    }
    return (0);
}