#include<stdio.h>
#include<string.h>

int main()
{
    int n,s[110],k[6]={1,2,5,10,50,100},ans,i,j;
    while(scanf("%d",&n) , n != 0)
    {
        ans = 0;
        for( i = 0; i < n; i++)
            scanf("%d",&s[i]);
        for( i = 0; i < n; i++)
        {
            for( j = 5; j >= 0; j--)
            {
                
                if( s[i] >= k[j])
                {
                    ans = ans + s[i] / k[j];
                    s[i] = s[i] % k[j];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}