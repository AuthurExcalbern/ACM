/*
 * ①最少的盘子放了一个，这样每个盘子至少一个，n个盘子先放上n个，剩下的m-n个可以随便放
 * ②最少的盘子没有放，这样剩下的n-1个盘子还是随便放m个
 * int f(int m,int n)
 * { 
 *      if(m<0)
 *          return 0;
 *      if(m==0||n==1)
 *          return 1;
 *      return f(m-n,n)+f(m,n-1);
 * }
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long int f(int m,int n)
{
    long long int f(int,int);
    if(m < 0)
        return 0;
    if(m == 0 || n == 1)
        return 1;
    return f(m - n,n) + f(m,n - 1);
}

int main()
{
    long long int f(int,int);
    long long int sum; 
    int testCase,M,N;
    scanf("%d",&testCase);
    while(testCase--)
    {
        scanf("%d %d",&M,&N);
        sum = f(M,N);
        printf("%lld\n",sum);
    }
    return 0;
}