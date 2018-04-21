/*
 * day 1 x = x/2 - 1
 * day 2 x = x/2 - 1
 * 
 * day n x = 1
 */
#include<stdio.h>

int main()
{
    int n,i,x;
    while(scanf("%d",&n) != EOF)
    {
        x = 1;
        for(i = 1; i < n; i++)
            x = (x + 1) * 2;
        printf("%d\n",x);
    }
    return 0;
}