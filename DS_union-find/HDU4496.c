/*
 * HDU 4496
 *
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=4496
 *
 * 用逆向思维求解
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100005
int pa[10005];
int temp_i[MAX], temp_j[MAX];
int ans[MAX];

int findset(int x)
{
    return pa[x] == -1 ? x : (pa[x] = findset(pa[x]) );
}

int build(int u, int v)
{
    int pa_u = findset(u);
    int pa_v = findset(v);
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
    int N, M;//N为点的数目，M为线的数目
    int i, j;//用于计数

    while(scanf("%d %d", &N, &M) == 2)
    {
        memset(pa, -1, sizeof(pa) );

        for(i = 0; i < M; i++)
            scanf("%d %d", temp_i + i, temp_j + i);
        for(i = M - 1, j = N; i >= 0; i--)
        {
            ans[i] = j;
            if( build(temp_i[i], temp_j[i]) && j > 1)
                j--;
        }
        for(i = 0; i < M; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
