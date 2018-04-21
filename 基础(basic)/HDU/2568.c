#include<stdio.h>

int main()
{
    int ans,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans = 0;
        for(;n!=1;)
        {
            if(n % 2 != 0)
            {
                n--;
                ans++;
            }
            else
               n = n / 2;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}