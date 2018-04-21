#include<stdio.h>
#include<string.h>

int main()
{
    int f[60],i,n;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for( i = 4; i < 57; i++)
        f[i] = f[i-1] + f[i-3];
    while(scanf("%d",&n) , n != 0)
        printf("%d\n",f[n]);
    return 0;
}
        