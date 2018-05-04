#include<cstdio>
#include<cstring>
#define lson i*2, l, m
#define rson i*2+1, m+1, r
using namespace std;
const int maxn = 50000+5;

//线段树需要维护的信息
int sum[maxn*4];

//i节点收集子节点的统计结果
void PushUp(int i) {sum[i] = sum[i*2] + sum[i*2+1];}

//递归建立线段树
void build(int i, int l, int r)
{
    if(l == r)
    {
        scanf("%d", &sum[i]);
        return;
    }
    int m = (l + r) / 2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    PushUp(i);//搜集子节点的结果
}


//在当前区间[l, r]内查询区间[ql, qr]间的目标值
//且能执行这个函数的前提是：[l,r]与[ql,qr]的交集非空
//其实本函数返回的结果也是 它们交集的目标值
int query(int ql, int qr, int i, int l, int r)
{
    //目的区间包含当前区间
    if(ql <= l && r <= qr) return sum[i];

    int m = (l + r) / 2;
    int res = 0;
    if(ql <= m) res += query(ql, qr, lson);
    if(m < qr) res += query(ql, qr, rson);
    return res;
}

//update这个函数就有点定制的意味了
//本题是单点更新，所以是在区间[l,r]内使得第id数的值+val
//如果是区间更新，可以update的参数需要将id变为ql和qr
void update(int id, int val, int i, int l, int r)
{
    if(l == r)
    {
        sum[i] += val;
        return ;
    }

    int m = (l + r) / 2;
    if(id <= m) update(id, val, lson);
    else update(id, val, rson);
    PushUp(i);//时刻记住维护i节点统计信息正确性
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++)
    {
        printf("Case %d:\n", kase);

        int n;//节点总数
        scanf("%d", &n);
        build(1, 1, n);//建立线段树

        char str[20];
        int u, v;
        while(scanf("%s", str) == 1 && str[0] != 'E')
        {
            scanf("%d%d", &u, &v);
            if(str[0] == 'Q') printf("%d\n", query(u, v, 1, 1, n));
            else if(str[0] == 'A') update(u, v, 1, 1, n);
            else update(u, -v, 1, 1, n);
        }
    }
    return 0;
}
