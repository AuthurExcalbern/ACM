#include<stdio.h>
#include<math.h>
int main()
{
    int nn,m,i,j,x,y,max,min,xx,yy,n[1000][1000];
    while( scanf("%d %d",&m,&nn) != EOF)
    {
        for( i = 0; i < m; i++)
            for( j = 0; j < nn; j++)
                scanf("%d",&n[i][j]);
        max = n[0][0];
        min = n[0][0];
        x = xx = y = yy = 0;
        for( i = 0; i < m; i++)
            for( j = 0; j < nn; j++)
            {
                if( n[i][j] > max)
                {
                    max = n[i][j];
                    y = i;
                    x = j;
                }
                if( n[i][j] < min)
                {
                    min = n[i][j];
                    yy = i;
                    xx = j;
                }
            }
        if( max > -min )
            printf("%d %d %d\n",y+1,x+1,max);
        else
            printf("%d %d %d\n",yy+1,xx+1,min);
    }
    return 0;
}