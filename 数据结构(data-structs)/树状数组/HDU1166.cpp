#include<cstdio>
#include<cstring>
/*********************************树状数组模板********************************/
const int maxn = 50000+5;//最大元素个数

int n = 50000;//元素个数
int c[maxn];//c[i]==A[i]+A[i-1]+...+A[i-lowbit(i)+1]

//返回i的二进制最右边1的值
int lowbit(int i)
{
    return i&(-i);
}

//返回A[1]+...A[i]的和
int sum(int i)
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

//令A[i] += val
void add(int i, int val)
{
    while(i <= n)
    {
        c[i] += val;
        i += lowbit(i);
    }
}
/*********************************树状数组模板********************************/
int main(void)
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--)
    {
        printf("Case %d:\n", kase++);
        int n;
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            int v;
            scanf("%d", &v);
            add(i, v);
        }
        char str[10];
        while(scanf("%s", str) == 1)
        {
            if(str[0] == 'E') break;
            else if(str[0] == 'Q')
            {
                int i, j;
                scanf("%d%d", &i, &j);
                printf("%d\n", sum(j)-sum(i-1));
            }
            else if(str[0] == 'A')
            {
                int x, v;
                scanf("%d%d", &x, &v);
                add(x, v);
            }
            else if(str[0] == 'S')
            {
                int x, v;
                scanf("%d%d", &x, &v);
                add(x, -v);
            }
        }
    }
    return 0;
}
