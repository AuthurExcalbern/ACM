/* n=1 3
 * n=2 3*3-1=8 3*3-1
 * n=3 3*3*3-1-4=22 8*3-2
 * n=4 81-1-4-2*2*3=81-5-12=82-17=65 22*3-4
 * f[n]=f[n-1]*3 - (n-1)
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long int sum[50];
    int n,count_i;
    memset(sum,0,sizeof(sum));
    sum[1] = 3;
    sum[2] = 8;
    for(count_i = 3;count_i <= 48;count_i++)
        sum[count_i] =2 * (sum[count_i - 1] + sum[count_i - 2]);
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",sum[n]);
    return 0;
}