#include<stdio.h>

int main()
{
    int n,m,t,count,key,i,j;
    scanf("%d",&t);
    while(t--)
    {
        count = 0;
        scanf("%d %d",&n,&m);
        key = m - n;
        for( i = 0; 4*i <= key && i <= n; i++)
            for( j = 0; j + 4*i <= key && (j+i) <= n; j++)
                if( j + 4*i == key )
                    count++;
        printf("%d\n",count);
    }
    return 0;
}