#include<stdio.h>
#include<string.h>

int main()
{
	int n,m;
	char A[100][100];
	int B[12][12],C[13],D[12][12];
	int i,j,num,l=0;
	while(scanf("%d",&m),m)
	{
		l++;
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&D[i][j]);
		int col=m*4+3,row=4*m-1;
		for(i=0;i<col;i++)
		{
			A[0][i]='*';
			A[row-1][i]='*';
		}
		for(i=1;i<row-1;i++)
		{
			A[i][0]='*';
			A[i][col-1]='*';
		}
		for(i=2;i<row-1;i=i+2)
			for(j=1;j<col-1;j++)
				A[i][j]=' ';
		for(i=1;i<row-1;i=i+4)
		{
			for(j=1;j<col-1;j=j+4)
				A[i][j]='H';
			for(j=2;j<col-1;j=j+2)
				A[i][j]=' ';
			for(j=3;j<col-1;j=j+4)
				A[i][j]='O';
		}
		for(i=3;i<row-1;i=i+4)
		{
			for(j=1;j<col-1;j++)
				A[i][j]=' ';
			for(j=3;j<col-1;j=j+4)
				A[i][j]='H';
		}
		num=0;
		memset(B,0,sizeof(B));
		for(i=1;i<col-1;i=i+4)
		{
			num++;
			memset(C,0,sizeof(C));
			for(j=1;j<=m;j++)
			{
				if(D[num][j]==0)
				{
					if(C[j]==0)
					{
						C[j]=1;
						A[i][3+(j-1)*4-1]='-';
						B[num][j]++;
					}
					else
					{
						C[j+1]=1;
						A[i][3+(j-1)*4+1]='-';
						B[num][j]++;
					}
				}
				if(D[num][j]==1)
				{
					A[i][3+(j-1)*4-1]='-';
					A[i][3+(j-1)*4+1]='-';
					C[j]=1;C[j+1]=1;
					B[num][j]=2;
				}
			}
		}
		num=0;
		for(i=3;i<row-1;i=i+4)
		{
			num++;
			for(j=1;j<=m;j++)
			{
				if((D[num][j]==0&&B[num][j]==1)||D[num][j]==-1)
				{
					A[i-1][(j-1)*4+3]='|';
					B[num][j]++;
				}
				else
				{
					A[i+1][(j-1)*4+3]='|';
					B[num+1][j]++;
				}
			}
		}
		printf("Case %d:\n\n",l);
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				printf("%c",A[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    int n,list[12][12];
    int count_i,count_j;
    char l[12][12],x1[3][3],x2[3][3],y[5],z[5][1];
    x1 = {
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        for(count_i = 1;count_i <= n;count_i++)
            for(count_j = 1;count_j <= n;count_j++)
                scanf("%d",&list[count_i][count_j]);
*/        