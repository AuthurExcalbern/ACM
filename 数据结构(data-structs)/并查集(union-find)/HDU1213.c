/*
 * HDU 1213
 *
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1213
 *
 * 并查集的基础运用
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MA 1005
int pa[MA];

int findRoot(int x)
{
    return pa[x] == -1 ? x : (pa[x] = findRoot(pa[x]) );
}

int bind(int u, int v)
{
    int pa_u = findRoot(u);
    int pa_v = findRoot(v);
    if(pa_u != pa_v)
    {
        pa[pa_u] = pa_v;
        return 1;
    }
    else
        return 0;
}

int main(void)
{
    int T, N, M;//T为测试数，N为朋友数（表号为1到N），M为关系数
    int ans;
    int i;
    int temp_i, temp_j;

    scanf("%d", &T);
    while(T--)
    {
        memset(pa, -1, sizeof(pa) );
        scanf("%d %d", &N, &M);
        ans = N;
        for(i = 0; i < M; i++)
        {
            scanf("%d %d", &temp_i, &temp_j);
            if(bind(temp_i, temp_j) )
                ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
