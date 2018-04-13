/* 有n件商品需要卖，每件商品由(p，t)描述。
 * 其中p表示该商品被卖出可获得的利润，t表示该商品被卖出的截止时间。
 * 时间从1开始计时，每件商品被卖出的话需要占用1个时间单位。
 * 如果某件商品的t=3，那么该商品最多只能在时间1，时间2或时间3 这3个时间点上卖。
 * 
 * 现在的问题是：
 * 对于给定的所有商品，我们如何安排每个时间点卖的商品能获得最大利润。输出最大利润即可
 * 
 * 贪心解法+并查集优化查找
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using std::cin;
using std::cout;

const int MAXN = 10005;

struct Node
{
    int p, t;//利润和截止时间
    
    //按利润排序
    bool operator<(const Node & rhs)const
    {
        return p > rhs.p;
    }
}nodes[MAXN];

//findFa(t)返回t时间前的最晚的一个可用时间点(可以为t)
int fa[MAXN];
int findFa(int t)
{
    return fa[t] == -1 ? t : (fa[t] = findFa(fa[t]));
}

int main(void)
{
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) cin >> nodes[i].p >> nodes[i].t;
        std::sort(nodes, nodes+n);
        
        memset(fa, -1, sizeof(fa));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int temp_time = findFa(nodes[i].t);
            if(temp_time > 0)
            {
                ans += nodes[i].p;
                fa[temp_time] = temp_time - 1;
            }
        }
        
        cout << ans << std::endl;
    }
    return 0;
}