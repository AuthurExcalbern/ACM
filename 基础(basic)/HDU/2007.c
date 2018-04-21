#include<stdio.h>

int main()
{
    int i,a,b,so,sj,k;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        so=0;
        sj=0;
        if(a>b)
        {
            k=a;
            a=b;
            b=k;
	}
        for(i=a;i<=b;i++)
        {
            if(i%2==0)
                so+=i*i;
            else
                sj+=i*i*i;
        }
        printf("%d %d\n",so,sj);
	}
	return 0;
}