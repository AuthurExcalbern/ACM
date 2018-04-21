//以下为母函数求解 

//参考资料：   http://www.wutianqi.com/?p=596

#include<stdio.h>
int f(int n){
	int s[130],a[130];
	int i,j,k;
	for(i=0;i<=n;i++){
        s[i]=1;
        a[i]=0;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=n;j++)
        	for(k=0;k*i+j<=n;k++)
                a[k*i+j]+=s[j];
                for(k=0;k<=n;k++){
                    s[k]=a[k];
                    a[k]=0;
                }
	}
    return s[n];
}
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",f(n));
    }
    return  0;
}

/*以下为递归求解

 整数划分问题是将一个正整数n拆成一组数连加并等于n的形式，且这组数中的最大加数不大于n。
    如6的整数划分为
    
    6
    5 + 1
    4 + 2, 4 + 1 + 1
    3 + 3, 3 + 2 + 1, 3 + 1 + 1 + 1
    2 + 2 + 2, 2 + 2 + 1 + 1, 2 + 1 + 1 + 1 + 1
    1 + 1 + 1 + 1 + 1 + 1
    
    共11种。下面介绍一种通过递归方法得到一个正整数的划分数。
    
    递归函数的声明为int split(int n, int m);其中n为要划分的正整数，m是划分中的最大加数(当m > n时，最大加数为n)，
    1 当n = 1或m = 1时，split的值为1，可根据上例看出，只有一个划分1 或 1 + 1 + 1 + 1 + 1 + 1
    可用程序表示为if(n == 1 || m == 1) return 1;
    
    2 下面看一看m 和 n的关系。它们有三种关系
    (1) m > n
    在整数划分中实际上最大加数不能大于n，因此在这种情况可以等价为split(n, n);
    可用程序表示为if(m > n) return split(n, n);    
    (2) m = n
    这种情况可用递归表示为split(n, m - 1) + 1，从以上例子中可以看出，就是最大加
    数为6和小于6的划分之和
    用程序表示为if(m == n) return (split(n, m - 1) + 1);
    (3) m < n
    这是最一般的情况，在划分的大多数时都是这种情况。
    从上例可以看出，设m = 4，那split(6, 4)的值是最大加数小于4划分数和整数2的划分数的和。
    因此，split(n, m)可表示为split(n, m - 1) + split(n - m, m)
    
    根据以上描述，可得源程序如下：
 
#include<stdio.h>
int s[130][130]={0};
int split (int n,int m)
{
    if(s[n][m])
        return s[n][m];
    if(n<1||m<1)
        return s[n][m]=0;
    if(n==1||m==0)
        return 1;
    if(n<m)
        return s[n][m]=split(n,n);
    if(n==m)
        return s[n][m]=(split(n,m-1)+1);
    else
        return s[n][m]=(split(n,m-1)+split(n-m,m));
}
int main ()
{
    int n;
    split(120,120);
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",split(n,n));
    return 0;
}
*/ 
