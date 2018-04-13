/* HDU 1232
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1232
 * 并查集基础运用
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
    int N, M;
    int temp_i, temp_j;
    int i;
    int ans;

    while(scanf("%d %d", &N, &M), N != 0)
    {
        memset(pa, -1, sizeof(pa) );
        ans = N - 1;
        for(i = 0; i < M; i++)
        {
            scanf("%d %d", &temp_i, &temp_j);
            if(bind(temp_i, temp_j) ) ans--;
        }
        printf("%d\n", ans);
    }

    return 0;
}
