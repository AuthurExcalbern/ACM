#include<stdio.h>
int main()
{
    int n,i;
    double sum,a,b,sum1;
    while(scanf("%d",&n)!=EOF)
    {
        sum=sum1=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&a,&b);
            if(b==-1)
                a=0;
            if(b<60&&b>=0)
                b=0;
            if(b>=60&&b<70)
                b=1;
            if(b>=70&&b<80)
                b=2;
            if(b>=80&&b<90)
                b=3;
            if(b>=90&&b<=100)
                b=4;
            sum+=a;
            sum1+=a*b;
        }
        if(sum==0)
            printf("-1\n");
        else
            printf("%.2lf\n",sum1/sum);
    }
    return 0;
}


/*
#include<stdio.h>
#include<string.h>

int main()
{
    int N,sums=0,sump=0,s[1000],p[1000],c[1000],count_i,count_j;
    double y;
    memset(s,0,sizeof(s));
    memset(p,0,sizeof(p));
    memset(c,0,sizeof(c));
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            continue;
        for(count_i = 0;count_i < N;count_i++)
        {
            scanf("%d %d",&s[count_i],&p[count_i]);
            sums = sums + s[count_i];
            p[count_i] = p[count_i] / 10;
            switch(p[count_i])
            {
                case 10:c[count_i] = 4;break;
                case 9:c[count_i] = 4;break;
                case 8:c[count_i] = 3;break;
                case 7:c[count_i] = 2;break;
                case 6:c[count_i] = 1;break;
                default:c[count_i] =0;
            }
            c[count_i] = s[count_i] * c[count_i];
            sump = sump + c[count_i];
        }
        y = (double)sump / (double)sums;
        printf("%2.2lf\n",y);
    }
    return 0;
}
*/