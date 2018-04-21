// codeforce    893C    Rumor
/*

有n个人，有m对关系，每对关系代表两人是朋友会相互传递消息
要让第i人帮忙传递消息需要ci费用，求怎么花最少的钱让所有人都知道消息

输入：
n m (1 ≤ n ≤ 10^5, 0 ≤ m ≤ 10^5)
n个ci：ci (0 ≤ ci ≤ 10^9)
m个关系：xi and yi are friends (1 ≤ xi, yi ≤ n, xi ≠ yi)

输出花费数

Examples

input
5 2
2 5 3 4 8
1 4
4 5
output

input
10 0
1 2 3 4 5 6 7 8 9 10
output
55
10

input
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
output
15
 */
/* 我用并查集的解，但会超内存

#include<cstdio>
#include<cstring>

const int MAXN = 100000 + 5;

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
    //修改下面，让根保持最小
    if(fu >= fv)//根不同->术语不同联通分量->可合并
    {
        fa[fu]=fv;
        return 1;
    }
    else if(fu < fv) {fa[fv]=fu; return 1;}
    return 0;
}

int main(void)
{
    memset(fa, -1, sizeof(fa));
    int n, m;
    scanf("%d %d", &n, &m);
    int c[n];
    for(int i = 0; i < n; i++) scanf("%d", c+i);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        bind(c[a-1], c[b-1]);
    }
    long long int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(fa[c[i]] == -1) ans += c[i];
        else continue;
    }
    printf("%I64d\n", ans);
    return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 2000000007;

int n, m; 
int c[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
ll res;

int Get(int v)
{
	if (tk[v]) return Inf;
	int res = c[v]; tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		res = min(res, Get(neigh[v][i]));
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		res += Get(i);
	printf("%I64d\n", res);
	return 0;
}
