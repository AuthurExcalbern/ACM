#include<stdio.h>

int main()
{
    int count_i;
    int n;
    long long int key[55];
    key[1] = 3;
    key[2] = 6;
    key[3] = 6;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 1)
            printf("3\n");
        else if(n == 2)
            printf("6\n");
        else if(n == 3)
            printf("6\n");
        else
        {
            for(count_i = 4;count_i <= n;count_i++)
                key[count_i] = key[count_i - 1] + key[count_i - 2] * 2;
            printf("%lld\n",key[n]);
        }
    }
    return 0;
}