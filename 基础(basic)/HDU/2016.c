#include<stdio.h>

int main()
{
    int num,n[110],i,key,j,min;
    while(scanf("%d",&num), num != 0)
    {
        for( i = 0; i < num; i++)
            scanf("%d",&n[i]);
        min = n[0];
        j = 0;
        for( i = 1; i < num; i++)
            if( n[i] <= min)
            {
                min = n[i];
                j = i;
            }
        if( j >= 1)
        {
            key = n[0];
            n[0] = n[j];
        }
        for( i = j; i > 1; i--)
            n[i] = n[i-1];
        if( j >= 1)
            n[1] = key;
        for( i = 0; i < num-1; i++)
            printf("%d ",n[i]);
        printf("%d\n",n[i]);
    }
    return 0;
}