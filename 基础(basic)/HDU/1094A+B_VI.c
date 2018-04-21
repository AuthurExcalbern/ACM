#include<stdio.h>
int main()
{
    int a[1000],b,n,m,sum = 0;
    while(scanf("%d",&m) != EOF)
    {
        for(b = 0;b < m;b++)
            scanf("%d",&a[b]);
        for(b = 0;b < m;b++)
            sum = sum + a[b];
        printf("%d\n",sum);
        sum = 0;
    }
    return 0;
}