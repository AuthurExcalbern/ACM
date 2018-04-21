/* HDU 3342
 * 
 * 题意：
 * 给N点和M条有向边，求问该图是否可拓扑排序
 * 
 * 解法：
 * 读清楚题意后按输出建立好有向图，然后再套入拓扑排序的判断模板即可
 * 有关拓扑排序判断问题可以了解判断模板里的注释
 * 
 */

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 100 + 5;
/*************************拓扑判定模板***************************/
int n, m;
vector<int> G[maxn];//G[i]表示i节点所指向的所有其他点
int in[maxn];//节点入度
bool topo()//判断该图是否可拓扑排序
{
    queue<int> Q;
    int sum = 0;//记录可拆解的点数目
    for(int i = 0; i < n; i++)//压入所有入度为0的点，即为起始点
        if(in[i] == 0)
            Q.push(i);
    while(!Q.empty())//每循环一次，都取走一个起始点，然后与起始点关联的顶点入度都减一
    {
        int u = Q.front();
        Q.pop();
        sum++;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(--in[v] == 0) Q.push(v);
        }
    }
    return sum == n;//如果能取遍所有点，则图是可完全拓扑的
}
/*************************拓扑判定模板***************************/
int main(void)
{
    while(scanf("%d %d", &n, &m) == 2 && n)
    {
        memset(in, 0, sizeof(in));//必要的初始化
        for(int i = 0; i < n; i++)
            G[i].clear();
        
        for(int i = 0; i < m; i++)//建立图
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            in[v]++;
        }
        printf("%s\n", topo() ? "YES" : "NO");
    }
    return 0;
}