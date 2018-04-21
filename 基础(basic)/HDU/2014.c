#include<stdio.h>

int main()
{
    int num,j,i,z;
    double max,sum,min,n[110],sco;
    while(scanf("%d",&num) != EOF)
    {
        max = 0.0;
        min = 1000;
        for( i = 0; i < num; i++)
            scanf("%lf",&n[i]);
        for( i = 0; i < num; i++)
        {
            if(n[i] > max)
            {
                max = n[i];
                j = i;
            }
            if(n[i] < min)
            {
                min = n[i];
                z = i;
            }
        }
        sum = 0.0;
        for( i = 0; i < num; i++)
        {
            if(i == j || i == z)
                continue;
            sum = sum + n[i];
        }
        sco = sum / (num - 2.0);
        printf("%.2lf\n",sco);
    }
    return 0;
}