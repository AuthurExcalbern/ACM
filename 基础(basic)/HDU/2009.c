#include<stdio.h>
#include<math.h>

int main()
{
    int m;
    double sum=0,n;
    while(scanf("%lf %d",&n,&m) != EOF)
    {
        sum = 0;
        while(m--)
        {
            sum = sum + n;
            n = sqrt( n );
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}