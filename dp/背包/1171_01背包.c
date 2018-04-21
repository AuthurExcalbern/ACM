#include<stdio.h>
#include<string.h>
int val[5005];  
int dp[255555]; //开大些 
int max(int a,int b)
{
    return a>b?a:b;
} 
int main()
{
    int n,m,v,l,i,j,sum;
    while(~scanf("%d",&n),n>0)
    {
        l=sum=0;
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {	
            scanf("%d%d",&v,&m);
            while(m--)
            {
                val[l++]=v;
                sum+=v;
            }	
        }
        for(i=0;i<l;i++)
        {
            for(j=sum/2;j>=val[i];j--)
            {
                dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
    return 0;
}

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (a>b ? a:b)

int comp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    int caseNum,testNum,value[1001],num[1001],A[1001],B[1001],mostValue = 0;
    int count_i,count_j,key;
    memset(value,0,sizeof(value));
    memset(num,0,sizeof(num));
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    while(scanf("%d",&caseNum) != EOF)
    {
        if(caseNum < 0)
            break;
        for(count_i = 0;count_i < caseNum;count_i++)
            scanf("%d %d",&value[count_i],&num[count_i]);
        qsort(value,sizeof(value),sizeof(int),comp);
        qsort(num,sizeof(num),sizeof(int),comp);
        for(count_i = 0;count_i < caseNum;count_i++)
            mostValue = mostValue + value[count_i] * num[count_i];
        mostValue = mostValue / 2;
        for(count_i = 1;count_i <= caseNum;count_i++)
            for(count_j = 1;count_j <= count_i;count_j++)
            {
                key = num[count_j -1];
                while(key > 0)
                {
                    if(A[count_j - 1] <= B[count_j - 1] && A[count_j - 1] <= mostValue) 
                    {
                        A[count_j] = max(A[count_j],A[count_j - 1] + value[count_j -1]);
                        B[count_j] = max(B[count_j],B[count_j - 1]);
                        key--;
                    }
                    else
                    {
                        B[count_j] = max(B[count_j],B[count_j - 1] + value[count_j] -1);
                        A[count_j] = max(A[count_j],A[count_j - 1]);
                        key--;
                    }
                }
            }
        if(A[caseNum -1] < B[caseNum -1])
            printf("%d %d",B[caseNum -1],A[caseNum - 1]);
        else
            printf("%d %d",A[caseNum -1],B[caseNum - 1]);
    }
    return 0;
}*/