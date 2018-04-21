#include<stdio.h>
int  main()
{
    int i,n,k;
    long long int f[40];
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&k);
            f[1]=1;
            f[2]=3;
            for(i=3;i<=k;i++)
            {
                f[i]=f[i-1]+2*f[i-2];//重点
            }
            printf("%lld\n",f[k]);
        }
    }
    return 0;
}