#include<stdio.h>

int main()
{
    int count = 4,n,i,j,f[20020],cow[5005],c[5005],ans,max,key;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for( i = 4; i <= 20010; i++)
    {
        key = i/2;
        for( j = 2; j <= key; j++)
            if( i % j == 0)
                break;
        if( j > key)
        {
            f[count] = i;
            count++;
        }
    }
    while(scanf("%d",&n) != EOF)
    {
    for( i = 0; i < n; i++)
    {
        scanf("%d",&cow[i]);
        c[i] = cow[i];
        for( j = 2; j < 20000; j++)
        {
            if( c[i] == 1)
            {
                j=1;
                break;
            }
            for(;c[i] % f[j] == 0;c[i] = c[i] / f[j]);
            if( c[i] == 1)
                break;
        }
        c[i] = j;
    }
    max = c[0];
    ans = 0;
    for( i = 1; i < n; i++)
        if(c[i] > max)
        {
            max = c[i];
            ans = i;
        }
    printf("%d\n",cow[ans]);
    }
    return 0;
}