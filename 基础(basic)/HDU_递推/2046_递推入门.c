/* n=1 1
 * n=2 2
 * n=3 3
 * n=4 5
 * f[n]=f[n-1]+f[n-2]
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long int sum[55];
    int n,count_i;
    memset(sum,0,sizeof(sum));
    sum[1] = 1;
    sum[2] = 2;
    for(count_i = 3;count_i <= 52;count_i++)
        sum[count_i] = sum[count_i - 1] + sum[count_i - 2];
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",sum[n]);
    return 0;
}