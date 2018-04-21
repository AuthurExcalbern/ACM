#include<stdio.h>
int main()
{
	int n,a,b,c,sum,i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d-%d-%d",&a,&b,&c);
		sum=0;
		if(b==2&&c==29)
		{
			printf("-1\n");
		    continue;
		}
		if(b<=2)
		for(i=a;i<=a+17;i++)
		{
			if(i%4==0 && i%100!=0 || i%400==0)
			sum=sum+366;
			else
			sum=sum+365;
		}
		else
		{
		for(i=a+1;i<=a+18;i++)
		{
			if(i%4==0 && i%100!=0 || i%400==0)
			sum=sum+366;
			else
			sum=sum+365;
		}
		
	   }
	   printf("%d\n",sum);
	}
}