#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000000
typedef struct
{
    char s[110];
    int  v;         //牛奶总体积
    double price;   //喝一天牛奶得花的钱数
}Milk;

int cmp(const void *p1,const void *p2)
{
    Milk a=*(Milk *)p1;
    Milk b=*(Milk *)p2;
    if(a.price!=b.price) return a.price-b.price;
    if(a.v!=b.v) return b.v-a.v;
}
int main()
{
    Milk m[110];
    int T,t;
    int i;
    int p;          //买牛奶的价格
    int  d;         //牛奶喝的天数
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&t);
            for(i=0;i<t;i++)
            {
                scanf("%s%d%d",m[i].s,&p,&m[i].v);
                d=m[i].v/200;
                if(d>5) d=5;
                if(d==0)
                {m[i].price=MAX;continue;}
                m[i].price=(double)p/(double)d;
            }
            qsort(m,t,sizeof(m[0]),cmp);
            printf("%s\n",m[0].s);
            memset(m,0,sizeof(m));
        }
    }
    return 0;
}
/*
 编译器函数库自带的快速排序函数。
使用qsort()排序并用 bsearch()搜索是一个比较常用的组合，使用方便快捷。
qsort 的函数原型是
void qsort(void*base,size_t num,size_t width,int(__cdecl*compare)(const void*,const void*));
各参数：1 待排序数组首地址 2 数组中待排序元素数量 3 各元素的占用空间大小 4 指向函数的指针
*/






/*
#include<stdio.h>
int main()
{
    int testNum;
    int kindOfMilk;
    char name[100][100];
    int count_i,count_j;
    double key[100],min,max;
    int price[100],V[100];
    int milk[100];
    int chose;
    scanf("%d",&testNum);
    while(testNum--)
    {
        scanf("%d",&kindOfMilk);
        for(count_i = 0;count_i < kindOfMilk;count_i++)
        {
            scanf("%s",name[count_i]);
            scanf("%d",&price[count_i]);
            scanf("%d",&V[count_i]);
        }
        for(count_i = 0;count_i < kindOfMilk;count_i++)
        {
            if(V[count_i] > 1200)
                V[count_i] = 1200;
            else if((count_j = V[count_i] % 200) != 0)
                V[count_i] = V[count_i] - count_j;
        }
        for(count_i = 0;count_i < kindOfMilk;count_i++)
            key[count_i] = V[count_i] / price[count_i]*1.0;
        min = key[0];
        for(count_i = 1,count_j = 0;count_i < kindOfMilk;count_i++)
        {
            if(min > key[count_i])
                min = key[count_i];
            //else if(min = key[count_i])
            //{
                //milk[count_j] = count_i;
                //count_j++;
            //}
        }
        for(count_i = 0,count_j = 0;count_i < kindOfMilk;count_i++)
        {
            if(min = key[count_i])
            {
                milk[count_j] = count_i;
                count_j++;
            }
        }
        //milk[count_j] = count_i;
        max = V[milk[0]];
        //count_j = milk[0];
        for(count_i = 1;count_i < count_j;count_i++)
        {
            if(max < V[milk[count_i]]);
            {
                max = V[milk[count_i]];
                //count_j = milk[count_i];
                chose = milk[count_i];
            }
        }
        printf("%s",name[chose]);
    }
    return 0;
}
*/