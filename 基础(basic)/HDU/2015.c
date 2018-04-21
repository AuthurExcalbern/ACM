/*
 * (a+b)/2 = 3  a+b=6 a=2 b=4
 * c=6 d=8
 */
#include<stdio.h>

int main()
{
    int n[120],i,sum,j,z,k,num,m;
    n[0] = 2;
    for( i = 2, j = 1; j <= 110; j++)
        n[j] = n[j - 1] + i;
    while(scanf("%d%d",&num,&m) != EOF)
    {
        j = num / m;
        z = num % m;
        for( k = 0; k < (j-1); k++)
        {
            sum = 0;
            for( i = 0; i < m; i++)
                sum = sum + n[i + k * m];
            printf("%d ",sum/m);
        }
        if( k < j)
        {
            sum = 0;
            for( i = 0; i < m; i++)
                sum = sum + n[i + k * m];
            printf("%d",sum/m);
        }
        if( z > 0)
        {
            sum = 0;
            for( i = 0; i < z; i++)
                sum = sum + n[i + (k+1) * m];
            printf(" %d\n",sum/z);
        }
        else
            printf("\n");
    }
    return 0;
}