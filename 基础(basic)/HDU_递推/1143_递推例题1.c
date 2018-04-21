
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long ans[35];
    int n,i,j;
    memset(ans,0,sizeof(ans));
    ans[2]=3;
    for(i=4;i<=30;i+=2)
    {
        ans[i]=ans[i-2]*3;
        for(j=i-4;j>=2;j-=2)
            ans[i]+=2*ans[j];
        ans[i]+=2;
    }
    while(~scanf("%d",&n)&&n!=-1)
    {
        if(n==0)
        printf("1");
        else
        printf("%d\n",ans[n]);
    }
    return 0;
}

/*
 * f[i][0] = f[i-2][0] + f[i-1][1] + f[i-2][2]  
 * f[i][1] = f[i-1][2]
 * f[i][2] = f[i][0] + f[i-1][1]
 * 边界条件     f[0][0] = f[1][1] = f[0][2] = 1
 */

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long int f[50][50],sum[50];
    int n,count_i,count_j;
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    f[0][0] = f[1][1] = f[0][2] =1;
    sum[1] = 3;
    f[1][0] = 0;
    f[1][2] = 2;
    for(count_i = 2;count_i <= 35;count_i++)
    {
        f[count_i][0] = f[count_i - 2][0] + f[count_i - 1][1] + f[count_i - 2][2];
        f[count_i][1] = f[count_i - 1][2];
        f[count_i][2] = f[count_i][0] + f[count_i - 1][1];
        sum[count_i] = f[count_i][0] + f[count_i][1] + f[count_i][2];
    }
    while(scanf("%d",&n) != EOF)
    {
        if(n < 0)
            return 0;
        else
            printf("%lld\n",sum[n]);
    }
    return 0;
}
*/