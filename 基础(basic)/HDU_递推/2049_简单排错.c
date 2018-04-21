#include <stdio.h>
int main()
{
    int n,m,c,i;
    scanf("%d",&c);
    while(c--)
    {
        __int64 a[31];
        a[0]=a[1]=0;a[2]=1,a[3]=2;
        for(i=4;i<30;i++)
            a[i]=(i-1)*(a[i-1]+a[i-2]);
        __int64 sum1,sum2;
        sum1=sum2=1;
        scanf("%d%d",&n,&m);
        for(i=n;i>n-m;i--)
            sum1*=i;
        for(i=2;i<=m;i++)
            sum2*=i;
        printf("%I64d\n",sum1/sum2*a[m]);
	}
}