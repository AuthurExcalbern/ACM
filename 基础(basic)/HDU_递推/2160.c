#include<stdio.h>
int main()
{
    int t,n,a[20],i;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            a[1]=1;a[2]=2;
            scanf("%d",&n);
            for(i=3;i<=n;i++)
            {
                a[i]=a[i-1]+a[i-2];
            }
            printf("%d\n",a[n]);
        }
    }
}