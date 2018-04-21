/* 有n个点和m条边，每个点带有一个权值p[i]。现在给出Q条命令，要你输出对应的答案。命令格式
 * 
 * query u ：该命令需要输出当前与u点相连的点编号x，x要满足p[x]是所有与u相连的点中最大的 且 p[x]>p[u]。如果有多个满足条件的x存在，那么就输出编号最小的那个x点的编号。
 * 
 * destroy u v：该命令将删除u与v的边。(保证在执行该命令前u与v之间有一条边)
 * 
 * 并查集：离线处理
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using std::cin;
using std::cout;
using std::swap;

const int MAXN = 10005;

int p[MAXN];//power velue

//并查集
int fa[MAXN];
int findFa(int x)
{
    return fa[x] == -1 ? x : fa[x]=findFa(fa[x]);
}
int bind(int u, int v)
{
    int fu = findFa(u);
    int fv = findFa(v);
    if(fu != fv)
    {
        if(p[fu] > p[fv] || (p[fu] == p[fv] && fu < fv)) fa[fv] = fu;
        else fa[fu] = fv;
        return 1;
    }
    return 0;
}

struct Edge//边
{
    int u, v;
    Edge(){}
    Edge(int u, int v):u(u), v(v){}
    
    bool operator<(const Edge & rhs)const//先按第一个点排序再按第二个点排序
    {
        return u < rhs.u || (u == rhs.u && v < rhs.v);
    }
}edges[20005];

bool vis[20005];

struct command//命令
{
    int type, v;
}coms[50005];

int main(void)
{
    int n, m, Q;
    bool first = true;
    while(cin >> n)
    {
        if(!first) cout << std::endl;
        first = false;
        
        //输入边的权值
        for(int i = 0; i < n; i++) scanf("%d",&p[i]);
        
        cin >> m;//边数
        std::map<Edge, int> mp;//边与边的编号的映射
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d",&u,&v);
            if(u > v) swap(u, v);
            edges[i] = Edge(u, v);
            mp[edges[i]] = i;
        }
        
        //vis[i]==true代表第i边已经被删除
        memset(vis, 0, sizeof(vis));
        
        cin >> Q;
        for(int i = 0; i < Q; i++)
        {
            char str[100];
            int u, v;
            
            scanf("%s",str);
            if(str[0] == 'q')
            {
                scanf("%d",&u);
                
                coms[i].type = 0;
                coms[i].v = u;
            }
            else if(str[0] == 'd')
            {
                scanf("%d%d",&u,&v);
                if(u > v) swap(u, v);
                int id = mp[Edge(u, v)];
                
                vis[id] = 1;//删除此边
                coms[i].type = 1;
                coms[i].v = id;
            }
        }
        
        //联通所有未被删除的边
        memset(fa, -1, sizeof(fa));
        for(int i = 0; i < m; i++)
            if(vis[i] == false) bind(edges[i].u, edges[i].v);
        
        //逆序处理所有命令并将query结果保存在数组里
        std::vector<int> vc;
        for(int i = Q-1; i >= 0; i--)
        {
            if(coms[i].type == 0)
            {
                int root = findFa(coms[i].v);
                if(p[root] > p[coms[i].v]) vc.push_back(root);
                else vc.push_back(-1);
            }
            else
            {
                int u = edges[coms[i].v].u, v = edges[coms[i].v].v;
                bind(u, v);
            }
        }
        
        for(int i = vc.size()-1; i >= 0; i--)
            printf("%d\n",vc[i]);
    }
    
    return 0;
}