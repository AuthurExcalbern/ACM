/*
 * POJ 3404
 *
 * URL:http://poj.org/problem?id=3404
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;  

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int opt[200];
    int i,j;
    int n,a[200];

    memset(opt, 0, sizeof(opt) );
    memset(a, 0, sizeof(a) );

    scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }

    sort(a, a+n+1);//每人按过桥时间从小到大排序

    if(n <= 2)//特殊情况
    {
        if(n == 1)
            printf("%d\n", a[1]);
        if(n == 2)
            printf("%d\n", a[2]);
        return 0;
    }
    else
    {
        opt[1] = a[1];
        opt[2] = a[2];
    }

    for(i = 3; i <= n; i++)//自底向上
    {
        opt[i] = min(opt[i-1] + a[1] + a[i], opt[i-2] + a[1] + a[i] + a[2]*2);
    }

    printf("%d\n", opt[n]);
    return 0;
}
