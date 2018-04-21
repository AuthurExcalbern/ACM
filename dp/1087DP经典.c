#include"stdio.h"
int main()
{
    int a[1101],b[1101],n,i,j,sum;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        b[0]=a[0];
        for(i=1;i<n;i++)
        {
            b[i]=a[i];
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j]&&b[i]<b[j]+a[i])
                    b[i]=b[j]+a[i];
                if(sum<b[i])
                    sum=b[i];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

/*
#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    return a>b ? a:b;
}

int count_z = 1002;

int find_max(int *step)
{
    int count_i,count_j,max = 0;
    for(count_i = 0;step[count_i] != 0;count_i++)
    {
        if(max <= step[count_i] && count_i < count_z)
        {
            max = step[count_i];
            count_j = count_i;
        }
    }
    count_z = count_j;
    //step[count_j] = -1;
    return max;
}

int main()
{
    int max(int a,int b);
    int find_max(int *step);
    int N,step[1001];
    int r[1001],sum,count_i,count_j;
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        memset(step,0,sizeof(step));
        memset(r,0,sizeof(r));
        for(count_i = 0;count_i < N;count_i++)
            scanf("%d",&step[count_i]);
        //r[0] = 0;
        for(count_j = 1;count_j <= N;count_j++)
        {
            sum = -1;
            for(count_i = 1;count_i <= count_j;count_i++)
                sum=max(sum,find_max(step) + r[count_j - count_i]);
            r[count_j] = sum;
        }
        printf("%d\n",r[N]);
    }
    return 0;
}*/