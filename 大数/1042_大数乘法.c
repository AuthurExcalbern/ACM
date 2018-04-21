#include<stdio.h>
#include<string.h>

int main()
{
    int n[10005],num,i,j,len;
    
    while(scanf("%d",&num) != EOF)
    {
        memset(n,0,sizeof(n));
        n[0] = 1;
        n[1] = 1;
        for( i = 2; i <= num; i++)
        {
            len = n[0];
            for( j = 1; j <= len; j++)
                n[j] = n[j] * i;
            for( j = 1; j <= n[0]; j++)
            {
                if( n[j] > 9)
                {
                    n[j + 1] = n[j + 1] + n[j] / 10;
                    n[j] = n[j] % 10;
                }
                if( n[n[0] + 1] )
                    n[0]++;
            }
        }
        for( i = n[0]; i >= 1; i--)
            putchar(n[i] + '0');
        puts("");
    }
    return 0;
}