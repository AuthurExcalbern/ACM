#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long int f[200];
    int a[200],b[200];
    int count_i,count_j;
    int N;
    memset(f,0,sizeof(f));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&N);
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    for(count_i = 4;count_i <= 200;count_i++)
        f[count_i] = f[count_i - 1] + f[count_i - 2];
    for(count_i = 0;count_i < N;count_i++)
    {
        scanf("%d %d",&a[count_i],&b[count_i]);
        count_j = b[count_i] - a[count_i] + 1;
        if(count_j <= 1)
            printf("0\n");
        else
            printf("%lld\n",f[count_j]);
    }
    return 0;
}