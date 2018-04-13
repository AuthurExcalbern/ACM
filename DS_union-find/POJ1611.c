/* POJ 1611
 * URL:http://poj.org/problem?id=1611
 * 所有学生被处理前都是独立的连通分量，以自己作为根。
 * 只要读入一个社团，那么社团中所有的学生所属的连通分量都要合并成1个。
 * 不断这么处理，最终和0号学生在同一个连通分量的所有学生都是需要被隔离的。
 * 用 根节点 维护num[i]信息表示当前连通分量的节点数目，
 * 当所有节点合并完之后，只需要计算0号节点所在的连通分量的点数输出即可。
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MA 30005
int fa[MA];//父节点信息
int num[MA];//根节点数目
//查询根节点操作和合并操作
int findset(int x)
{
    return fa[x] == -1 ? x : (fa[x] = findset(fa[x]) );
}
void bind(int u, int v)
{
    int fu = findset(u);
    int fv = findset(v);
    if(fu != fv)
    {
        num[fv] = num[fv] + num[fu];
        fa[fu] = fv;
    }
}

int main(void)
{
    int n, m;//n个学生和m组社团
    int i;//用于计数
    int k, u, v;//k为每组社团的人数，u固定为社团里的第一个人，v代表余下的人

    while(scanf("%d %d", &n, &m), n > 0)
    {
        //memset(fa, -1, sizeof(fa) );
        //memset(num, 1, sizeof(num) );
        for(i = 0; i < n; i++)
        {
            fa[i] = -1;
            num[i] = 1;
        }
        while(m--)
        {
            scanf("%d %d", &k, &u);
            for(i = 1; i < k; i++)
            {
                scanf("%d", &v);
                bind(u, v);
            }
        }
        printf("%d\n", num[findset(0)]);
    }
    return 0;
}
