#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
/****************************Kruskal模板*******************************/
using namespace std;
const int maxn = 100 + 10;
const int maxm = 100 * 100 + 10;

struct Edge//边
{
    int u, v;
    int dist;
    Edge(int u, int v, int d): u(u), v(v), dist(d) {}
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

    void AddEdge(int u, int v, int dist)
    {
        edges.push_back(Edge(u, v, dist));
        m=edges.size();
    }

    int kruskal()
    {
        int sum = 0; //最小生成树权值
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
