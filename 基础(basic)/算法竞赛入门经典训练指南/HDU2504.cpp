/* HDU 2504

题意：
有三个正整数a,b,c(0<a,b,c<10^6)，其中c不等于b。若a和c的最大公约数为b，现已知a和b，求满足条件的最小的c

输入：
第一行为n
接下来n行每行输入a和b

输出：
输出c

*/
#include<iostream>
#include<cstdio>
using namespace std;

//辗转相除法
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b, c;
        scanf("%d %d", &a, &b);
        c = 2 * b;
        while(gcd(a, c) != b)
            c += b;
        printf("%d\n", c);
    }
    return 0;
}