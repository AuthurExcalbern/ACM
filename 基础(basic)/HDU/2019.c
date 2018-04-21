#include<stdio.h>

int main()
{
    int n,m,s[110],i;
    while( scanf("%d %d",&n,&m), n != 0 && m != 0)
    {
        for( i = 0; i < n; i++)
            scanf("%d",&s[i]);
        for( i = 0; i < n; i++)
        {
            if( s[i] < m )
                printf("%d ",s[i]);
            else
            {
                printf("%d",m);
                break;
            }
        }
        for( ; i < n ; i++)
            printf(" %d",s[i]);
        printf("\n");
    }
    return 0;
}