#include<stdio.h>
#include<string.h>
int main()
{
	int len,i;
	char str[100];
	while(gets(str))
	{
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(i==0) str[0]=str[0]-32;
			if(str[i]==' ')
			{
				str[i+1]=str[i+1]-32;
			}
				printf("%c",str[i]);
		}
		printf("\n");
	}
}