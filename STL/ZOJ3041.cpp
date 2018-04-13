/* ZOJ-3041
 * 
 * 题意：
 * 现在有m个工厂和n个打算建城市的地点(给出所有点的x和y坐标，且(0,0)位于2维坐标轴的中心),
 * 如果有一个工厂在一个打算建城市地点的左上角(就算在边界也算),
 * 那么该地点就不能建城市(因为会被污染).现在要你输出所有可以建城市的点坐标.
 * 
 * 分析：
 * 我们通过将所有工厂和城市点按x从小到大,(如果x相等,则y从大到小,如果x和y都相等,就把工厂排在城市前面)的顺序排序.
 * 现在我们确定了x坐标一定是从小到大排序的,所以如果我们当前考虑第i个点(该点是城市)是否可行时?我们只要从0到i-1这些点中找出是否有一个工厂的y坐标大于等于它的y坐标就行(因为这前面任意工厂的x坐标肯定<=该地点的x坐标).
 * 所以程序中我们用y来记录我们当前所遇到过的所有工厂中y坐标的最大值.如果这个最大值依然小于当前城市点的y坐标,那么就不可能有妨碍该城市的工厂存在了
 * 
 */
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Node
{
    int x, y;
    bool f;//true时表示工厂
    
    //赋值操作
    Node(int x, int y, bool f):x(x),y(y),f(f){}
    
    //排序,先按x从小到大排序，x相等时用y从大到小排序
    bool operator<(const Node & rhs)const
    {
        return x<rhs.x || (x == rhs.x && y < rhs.y);
    }
};

//排序,先按x从小到大排序，x相等时用y从大到小排序,x和y相等时工厂在前
bool cmp(const Node & lhs, const Node & rhs)
{
    return lhs.x<rhs.x || (lhs.x==rhs.x && lhs.y>rhs.y) || (lhs.x==rhs.x && lhs.y==rhs.y && lhs.f);
}

int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2)
    {
        //保存所有点，并排序
        vector<Node> vcl;
        for(int i = 0; i < n; i++)//读入城市
        {
            int x, y;
            scanf("%d %d", &x ,&y);
            vcl.push_back(Node(x, y, false));
        }
        for(int i = 0; i < m; i++)//读入工厂
        {
            int x, y;
            scanf("%d %d", &x ,&y);
            vcl.push_back(Node(x, y, true));
        }
        sort(vcl.begin(), vcl.end(), cmp);
        
        //保存可建城市的点
        vector<Node> vc2;
        int max_y = -(1e9)+1;
        for(int i = 0; i < vcl.size(); i++)
        {
            if(vcl[i].f == true)
                max_y = max(max_y, vcl[i].y);
            else
                if(vcl[i].y > max_y)
                    vc2.push_back(vcl[i]);
        }
        sort(vc2.begin(), vc2.end());
        
        printf("%lu\n", vc2.size());
        for(int i = 0; i < vc2.size(); i++)
            printf("%d %d\n", vc2[i].x, vc2[i].y);
    }
    return 0;
}