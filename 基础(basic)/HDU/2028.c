#include<stdio.h>

unsigned long gcd(unsigned long u,unsigned long v)
{
    int remainder;
    remainder = u % v;
    while(remainder)
    {
        u = v;
        v = remainder;
        remainder = u % v;
    }
    return v;
}

unsigned long lcm(unsigned long u,unsigned long v)
{
    return u * v / gcd(u , v);
}


int main()
{
    int n;
    unsigned long u;
    unsigned long res;
    while(scanf("%d",&n) != EOF)
    {
        res = 1;
        while( n-- )
        {
            scanf("%lu",&u);
            res = lcm(res,u);
        }
        printf("%lu\n",res);
    }
    return 0;
}