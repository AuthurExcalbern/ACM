//这条递归公式一样可行：f[i] = 2^n-2 + f[n-2]
#include<stdio.h>
int main()
{
    int n,i,a[1100]={0,0};
    a[2]=2;
    a[3]=2;
    for(i=4;i<=1000;i++)
    {
        a[i]=(a[i-1]+2*a[i-2])%10000;
    }
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}