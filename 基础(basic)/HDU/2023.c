#include<stdio.h>

int s[55][8],n,m;
double sc[55],c[8];

void stu()
{
    int sum,i,j;
    for( i = 0; i < n; i++)
    {
        sum = 0;
        for( j = 0; j < m; j++)
                sum = sum + s[i][j];
        sc[i] = sum * 1.0 / m;
    }
    for( i = 0; i < n-1; i++)
        printf("%.2lf ",sc[i]);
    printf("%.2lf\n",sc[i]);
}

void pro()
{
    int sum,i,j;
    for( j = 0; j < m; j++)
    {
        sum = 0;
        for( i = 0; i < n; i++)
            sum = sum + s[i][j];
        c[j] = sum*1.0 / n;
    }
    for( j = 0; j < m-1; j++)
        printf("%.2lf ",c[j]);
    printf("%.2lf\n",c[j]);
}

int main()
{
    int ans,i,j;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        ans = 0;
        for( i = 0; i < n; i++)
            for( j = 0; j < m; j++)
                scanf("%d",&s[i][j]);
        stu();
        pro();
        for( i = 0; i < n; i++)
        {
            for( j = 0; j < m; j++)
            {
                if( s[i][j] >= c[j])
                    continue;
                else
                    break;
            }
            if( j == m )
                ans++;
        }
        printf("%d\n\n",ans);
    }
    return 0;
}