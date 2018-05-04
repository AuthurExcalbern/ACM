/*********************************树状数组模板********************************/
const int maxn = 10000+5;//最大元素个数

int n;//元素个数
int c[maxn];//c[i]==A[i]+A[i-1]+...+A[i-lowbit(i)+1]

//返回i的二进制最右边1的值
//例如：6 的二进制是 1100，则返回 100
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
