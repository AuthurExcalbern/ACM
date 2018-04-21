/* POJ 2524 2018-1-17
 * 题目的本意是：有n个点，点间有m条线，求构成的图有多少个联通分支
 * 
 * 解法：基本并查集运用
 */
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 50000+5;
/***********************************并查集模板***********************************/
//并查集基本模板
//fa需要初始化：memset(fa, -1, sizeof(fa))
//fa[i]表示i节点的父节点
int fa[MAXN];

//返回x节点的根，同时使得x节点直接挂在根节点下面
int findset(int x)
{
    return fa[x] == -1 ? x : (fa[x] = findset(fa[x]) );
}

//合并u与v所属的联通分支
int bind(int u, int v)
{
    int fu = findset(u);//获取根
    int fv = findset(v);//获取根
    if(fu != fv)//根不同->术语不同联通分量->可合并
    {
        fa[fu]=fv;
        return 1;
    }
    return 0;
}

/***********************************并查集模板***********************************/
int main(void)
{
    int n, m;
    int k = 1;
    while(cin >> n >> m && n)
    {
        memset(fa, -1, sizeof(fa));
        int cnt = n;//记录当前的连通分支数量
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            cnt -= bind(u, v);//如果两连通分支合并成功则减1
        }
        cout << "Case " << k << ": " << cnt << endl;
        k++;
    }
    return 0;
}