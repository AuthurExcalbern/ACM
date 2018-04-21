#include<stdio.h>

int main()
{
    int a[21]={0,2},b[21]={0,2},m,n;
    for (int i=2;i<21;i++)
    {
        a[i]=3*a[i-1]+2;
        b[i]=a[i-1]+2;
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d\n",b[m]);
    }
    return 0;
}

/*
汉诺塔的算法就3个步骤：第一，把a上的n-1个盘通过c移动到b。第二，把a上的最下面的盘移到c。第三，因为n-1个盘全在b上了，所以把b当做a重复以上步骤就好了。所以算法看起来就简单多了。不过，思考过程还是很痛苦的，难以理解。递归中会保存数据的好处在这里又得到体现，太神奇了。

汉诺塔代码如下：

#include<stdio.h>
 
void move(int n,char a,char b,char c)
{
    if(n==1)
        printf("\t%c->%c\n",a,c);    //当n只有1个的时候直接从a移动到c
    else
    {
        move(n-1,a,c,b);            //第n-1个要从a通过c移动到b
        printf("\t%c->%c\n",a,c);
        move(n-1,b,a,c);            //n-1个移动过来之后b变开始盘，b通过a移动到c，这边很难理解
    }
}
 
main()
{
    int n;
    printf("请输入要移动的块数：");
    scanf("%d",&n);
    move(n,'a','b','c');
}

*/