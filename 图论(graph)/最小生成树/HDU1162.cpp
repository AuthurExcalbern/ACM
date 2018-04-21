/* HDU 1162
 * 
 *  给个点的坐标，求问最少要连多长的直线可以使N个点联通
 * 
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
//要把模板里部分数据改为double
/****************************Kruskal模板*******************************/
using namespace std;
const int maxn = 100 + 10;
const int maxm = 100 * 100 + 10;

struct Edge//边
{
    int u, v;
    double dist;
    Edge(int u, int v, double d): u(u), v(v), dist(d) {}
    bool operator<(const Edge&rhs)const
    {
        return dist < rhs.dist;
    }
};

struct Kruskal
{
    int n, m;          //点数,边数
    vector<Edge> edges;//边列表
    int fa[maxn];      //并查集
    int findset(int x){ return fa[x] == -1 ? x : fa[x] = findset(fa[x]); }

    void init(int n)
    {
        this->n = n;
        m = 0;
        memset(fa, -1, sizeof(fa));
        edges.clear();
    }

    void AddEdge(int u, int v, double dist)
    {
        edges.push_back(Edge(u, v, dist));
        m=edges.size();
    }

    double kruskal()
    {
        double sum = 0; //最小生成树权值
        int cnt = 0; //最小生成树边数目
        sort(edges.begin(), edges.end());

        for(int i = 0; i < m; i++)
        {
            int u = edges[i].u, v = edges[i].v;
            if(findset(u) != findset(v))
            {
                sum += edges[i].dist;
                fa[findset(u)] = findset(v);
                if(++cnt >= n - 1) break;
            }
        }
        //注意n==0时应该输出0，当最小生成树不存在时，输出-1
        return cnt>=n-1?sum:-1;
    }
}KK;
/****************************Kruskal模板*******************************/

struct Node
{
    double x, y;
}n[maxn];

double getDist(int i, int j)
{
    return sqrt((n[i].x-n[j].x) * (n[i].x-n[j].x) + (n[i].y-n[j].y) *(n[i].y-n[j].y));
}

int main(void)
{
    int N;
    while(scanf("%d", &N) == 1)
    {
        KK.init(N);
        for(int i = 0; i < N; i++)
            scanf("%lf %lf", &n[i].x, &n[i].y);
        for(int i = 0; i < N; i++)
            for(int j = i+1; j < N; j++)
                KK.AddEdge(i, j, getDist(i, j));
        printf("%.2lf\n", KK.kruskal());
    }
    return 0;
}