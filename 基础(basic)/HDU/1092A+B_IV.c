#include<stdio.h>
int main()
{
    int a[1000],b,n,sum = 0;
    while(scanf("%d",&n) !=  EOF)
    {
        if(n == 0)
            break;
        for(b = 0;b < n;b++)
            scanf("%d",&a[b]);
        for(b = 0;b < n;b++)
            sum = sum + a[b];
        printf("%d\n",sum);
        sum = 0;
    }
    return 0;
}