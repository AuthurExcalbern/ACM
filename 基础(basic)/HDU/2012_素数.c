#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int judge(int n)
{
    int count_i,count_j,key;
    for(count_i = 2;count_i <= sqrt( n );count_i++)
    {
        if(n % count_i == 0)
            break;
    }
    if(count_i > sqrt( n ) )
        return 1;
    else
        return 0;
}

int main()
{
    int key,count_i,count_j,x,y,n[10000];
    while(scanf("%d %d",&x,&y) != EOF)
    {
        if(x == 0 && y == 0)
            break;
        if(x > y)
        {
            key = x;
            x = y;
            y = key;
        }
        for(count_j = 0,count_i = x;count_i <= y;count_i++,count_j++)
            n[count_j] = count_i * count_i + count_i + 41;
        for(count_j = 0,count_i = x;count_i <= y;count_i++,count_j++)
        {
            if( judge(n[count_j]) == 1)
                continue;
            else
                break;
        }
        if(count_i > y)
            printf("OK\n");
        else
            printf("Sorry\n");
    }
    return 0;
}