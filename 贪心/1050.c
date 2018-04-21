/*
 * HDU:1050
 * http://acm.hdu.edu.cn/showproblem.php?pid=1050
 * 贪心类题目
 * 
 * 题意：
 * 给予你若干个区间，每次选取用时10分钟，可以一次选取多个区间，但不可选取重叠的区间
 * 求选完所有区间的最低用时是多少分钟？
 *
 */
#include<stdio.h>
#include<string.h>

int N,count,list[210];

struct map//输入的区间的结构体
{
    int a,b;//a为起点，b为终点
    int bool;//用于标记是否已经选取该区间
}m[210];

void insort(int len)//插入排序法：把输入的区间按结束点b的大小来排序
{
    int key1,key2,z,i,j;
    for(j = 1; j < len; j++)
        {
            key1 = m[j].b;
            key2 = m[j].a;//！！注意：交换b的同时要交换起点a
            z = j - 1;
            while(z >= 0 && m[z].b > key1)
            {
                m[z + 1].b = m[z].b;
                m[z + 1].a = m[z].a;
                z = z - 1;
            }
            m[z + 1].b = key1;
            m[z + 1].a = key2;
        }
}

void choose(int beg)//选取中beg所在的区间
{
    int i,j = 0,z,min = 210;
    m[beg].bool = 1;//改变区间状态
    memset(list,0,sizeof(list));
    for( i = beg+1; i < N; i++)//用于遍历出在选择beg区间时，所有可以（在这次选择中）下一个被选择的区间
        if( m[i].a >= m[beg].b && m[i].bool == 0)
        {
            list[j] = i;//list用于记录可能选取的区间位置
            j++;
        }
    if( j != 0)
    {
        for( i = 0; i < j; i++)//！！在所有可能中我们应该选取起点最小的那个
            if( min > m[ list[i] ].a)
            {
                min = m[ list[i] ].a;
                z = list[i];
            }
            choose(z);//递归：用来（在一次选择中）所能选的最多区间
    }
    else
        return;
}

int main()
{
    int i,j,t,ans;
    scanf("%d",&t);
    while(t--)
    {
        count = 0;//！！初始化
        scanf("%d",&N);
        for( i = 0; i < N; i++)
        {
            scanf("%d %d",&m[i].a,&m[i].b);
            if( m[i].a > m[i].b)//！！注意，起点终点的大小是不确定的，如果起点大于终点就要交换大小
            {
                j = m[i].a;
                m[i].a = m[i].b;
                m[i].b = j;
            }
            m[i].bool = 0;//！！注意初始化
        }
        insort(N);//排序
        for( i = 0; i < N; i++)
        {
            if( m[i].bool == 0)
            {
                count++;
                choose(i);
            }
        }
        ans = count * 10;
        printf("%d\n",ans);
    }
    return 0;
}