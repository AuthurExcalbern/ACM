/*
思路： 
只要除了数目最多的糖果以外的其他所有糖果的数目之和加1（小心这里要用int64），
大于等于数目最多的糖果数，就能吃完，否则不能。
原理：O X O M O,三种糖果，假设其他糖果总数为n,数目最多的只能插空n+1; 
*/


#include <stdio.h>
#define x 1000000
#define max(a,b) a>b?a:b
int i,n,T,Max;
int a[x];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
         
        __int64 sum=0;
        scanf("%d",&n);
        Max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];        //sum为糖果总数 
            Max=max(Max,a[i]);  //找出糖果数最多的种类 
        }
        sum=sum-Max+1; 
        if(sum>=Max) printf("Yes\n");//如果位子数大于等于最多糖果数，就可以 
        else printf("No\n");
    }
    return 0;
}