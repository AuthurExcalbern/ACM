/* CF 625A

题意给n块钱买牛奶

塑料盒牛奶价格 a
玻璃盒牛奶价格 b

回收玻璃盒的价格 c
问你最多能买多少盒牛奶

贪心，看 a 便宜还是 d=b-c便宜
如果a便宜，就先尽可能买a，剩下的钱买b
否则，先尽可能买b，最后买a
*/
#include<cstdio>
#include<iostream>
using namespace std;
int main(void)
{
    long long int n, tmp, a, b, c, d;
    cin >> n >> a >> b >> c;
    long long int ans = 0;
    d = b - c;
    
    if(d < a)
    {
        if(n > b)
        {
            ans = (n - b) / d;
            n = b + (n-b)%d;
        }
        if(n >= b)
        {
            ans++;
            n -= d;
        }
        ans += n / a;
    }
    else
    {
        ans = n / a;
        n = n % a;
        if(n > b)
        {
            ans += (n - b) / d;
            n = b + (n-b)%d;
        }
        if(n >= b)
        {
            ans++;
            n -= d;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}