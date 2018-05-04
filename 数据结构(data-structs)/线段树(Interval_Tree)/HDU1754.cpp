#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
#define lson i*2,l,m
#define rson i*2+1,m+1,r
using namespace std;
const int maxn = 200000+5;

int stu[maxn*4];//用于存储学生的成绩
//注意：这里0不储存信息，以1为根节点，这样才可以使用i*2,i*2+1为左右子节点！

//自底向上维护信息
void PushUp(int i)
{
    stu[i] = max(stu[i*2], stu[i*2+1]);
}

//递归建立线段树
void build(int i, int l, int r)//i代表在树中的位置;l,r别代表从第l个学生到第r个学生
{
    if(l == r)//递归触底
    {
        scanf("%d", &stu[i]);
        return;
    }
    int m = (l + r) / 2;
    build(lson);
    build(rson);
    PushUp(i);//在这里自底向上维护信息
    return;
}

//在l,r这段内查询ql,qr这段内的最高成绩
int Q(int ql, int qr, int i, int l, int r)
{
    if(ql <= l && r <= qr) return stu[i];//目的区间包含当前区间
    int m = (l + r) / 2;
    int max_val = -INF;
    if(ql <= m) max_val = max(max_val, Q(ql, qr, lson));
    if(qr > m) max_val = max(max_val, Q(ql, qr, rson));
    return max_val;
}

//把id学生成绩改为val
void U(int id, int val, int i, int l, int r)
{
    if(l == r) {stu[i] = val; return;}
    int m = (l + r) / 2;
    if(id <= m) U(id, val, lson);
    else U(id, val, rson);
    PushUp(i);//改完后要向上刷新信息
}

int main(void)
{
    int N, M;
    while(scanf("%d %d", &N, &M) == 2)
    {
        //memset(stu, 0, sizeof(stu));当数组较大时会耗很多时间和内存
        build(1, 1, N);
        while(M--)
        {
            char c[10];//用字符串来避免错误！
            int temp1, temp2;
            scanf("%s %d %d", c, &temp1, &temp2);
            if(c[0] == 'Q') printf("%d\n", Q(temp1, temp2, 1, 1, N));
            else U(temp1, temp2, 1, 1, N);
        }
    }
    return 0;
}
