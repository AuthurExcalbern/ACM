#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    long long int fA[1010],fB[1010];
    int count_i,count_j,count_z;
    int n;
    memset(fA,0,sizeof(fA));
    memset(fB,0,sizeof(fB));
    //fA[0] = 0;
    //fB[0] = 0;
    for(count_i = 1;count_i <= 1010;count_i++)
    {
        fB[count_i] = fB[count_i - 1] + fA[count_i - 1] + count_i % 2;
        fA[count_i] = fA[count_i - 1] + fA[count_i - 1];
    }
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            printf("%lld\n",fB[n - 1]);
            continue;
        }
    }
    return 0;
}