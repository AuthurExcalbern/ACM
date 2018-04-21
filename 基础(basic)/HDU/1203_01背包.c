#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a>b) ? a:b)

int main()
{
    int count_i,count_j,n,m,a[10010];
    float b[10010],f[10010];
    while(scanf("%d %d",&n,&m) != EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        if(n == 0 && m == 0)
            break;
        for(count_i = 1;count_i <= m;count_i++)
            scanf("%d %f",&a[count_i],&b[count_i]);
        for(count_i = 1;count_i <= m;count_i++)
            for(count_j = n;count_j >= a[count_i];count_j--)
                f[count_j] = max(f[count_j] , 1 - (1 - f[count_j - a[count_i] ]) * (1 - b[count_i]) );
        printf("%.1f%%\n",f[n]*100);
    }
    return 0;
}