#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
long long int f(int a,long long int n)//小心溢出
{
    long long int sum = 1;
    a %= 10;
    if(n == 1)
        return a;
    else if(n%2==0){
        a *= a;
        n /= 2;
        sum *= (f(a,n)%10);
    }
    else
    {
        sum *= a;
        a *= a;
        n /= 2;
        sum *= (f(a,n)%10);
    }
    return (sum%10);
}
int main(){
    long long int n;
    int t,m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%lld",&n);
        t = n % 10;
        printf("%lld\n",f(t,n));
    }
    return 0;
}