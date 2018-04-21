/*  每修复一台电脑，就把它 与 所有距离它不超过D且已经被修复的电脑连通(即合并两者的连通分量)。
 * 每次查询只需要看被查询的两台电脑是否被修复且都在同一个连通分量即可。
 */
#include<iostream>
#include<cstring>
#include<vector>
using std::cin;
using std::cout;

const int MAXN = 1005;

//并查集
int fa[MAXN];
int findFa(int x)
{
    return fa[x] == -1 ? x : findFa(fa[x]);
}
void bind(int u, int v)
{
    int fu = findFa(u);
    int fv = findFa(v);
    if(fu != fv) fa[fu] = fv;
}

struct Node
{
    double x, y;
}p[MAXN];
//得到两点的距离的平方
double get_dist(Node p, Node pp)
{
    return (p.x-pp.x)*(p.x-pp.x) + (p.y-pp.y)*(p.y-pp.y);
}

int main(void)
{
    int n;
    double d;
    bool vis[MAXN];//记录是否已经被修复
    std::vector<int> vc[MAXN];
    
    cin >> n >> d;
    memset(fa, -1, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    
    //注意这里是从1开始
    for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(get_dist(p[i], p[j]) <= d*d)
            {
                vc[i].push_back(j);
                vc[j].push_back(i);
            }
    
    std::string com;
    while(cin >> com)
    {
        if(com[0] == 'O')
        {
            int u;
            cin >> u;
            vis[u] = true;
            for(int i = 0; i < vc[u].size(); i++)
            {
                int v = vc[u][i];
                if(vis[v]) bind(u, v);
            }
        }
        else if(com[0] == 'S')
        {
            int u, v;
            cin >> u >> v;
            if(vis[u] && vis[v] && findFa(u) == findFa(v)) cout << "SUCCESS\n";
            else cout << "FAIL\n";
        }
    }
    return 0;
}