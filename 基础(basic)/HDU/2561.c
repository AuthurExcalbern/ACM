#include<stdio.h>
#include<string.h>

int main()
{
    int t,n[15],min,i,j,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        for( i = 0; i < num; i++)
            scanf("%d",&n[i]);
        min = n[0];
        j = 0;
        for( i = 0; i < num; i++)
            if( n[i] < min)
            {
                min = n[i];
                j = i;
            }//printf("\n\n%d\n\n",j);
        n[j] = 101;
        min = 101;
        for( i = 0; i < num; i++)
            if( n[i] < min)
            {
                min = n[i];
                j = i;
            }
        printf("%d\n",n[j]);
    }
    return 0;
}