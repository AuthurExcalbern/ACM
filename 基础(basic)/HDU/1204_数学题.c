#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int N,M;
    double p,q,rate,k;
    while(cin>>N>>M>>p>>q)
    {
        if(N==0){cout<<"0.00"<<endl;continue;}
        if(M==0){cout<<"1.00"<<endl;continue;}
        if(p==0||q==1){cout<<"0.00"<<endl;continue;}
        if(q==0||p==1){cout<<"1.00"<<endl;continue;}
        if(p==q) rate=1.0*N/(M+N);//   M,N不一定等于0.5
        else
        {
            k = q*(1-p)/(p*(1-q));
            rate = (1.0-pow(k,N))/(1.0-pow(k,M+N));//      【幂运算】
        }
        cout<<fixed<<setprecision(2)<<rate<<endl;//    【设置浮点数输出的有效数字位数】
    }
    return 0;

}






/*
这是一个概率题，首先我们必须清楚我们要求的是什么！

设f(i)表示Speakless有i颗糖果的时候赢的概率，我们要求的就是f(n)
则根据题意我们知道,这时候:
1.Speakless赢这一局的概率是p(1-q),即f(i)变成f(i+1)
2.Speakless输这一局的概率是q(1-p),即f(i)变成f(i-1)
3.Speakless平这一局的概率是1-p(1-q)-q(1-p),即f(i)变成f(i)
因此：
f(i) = p(1-q)*f(i+1) + q(1-p)*f(i-1) + (1-p(1-q)-q(1-p))*f(i)
稍微变形：
p(1-q)*(f(i+1)-f(i)) = q(1-p)*(f(i)-f(i-1))令g(i)=f(i)-f(i-1),
则有p(1-q)*g(i) = q(1-p)g(i-1),即g(i)是等比数列,
设k=q(1-p)/(p(1-q))，则g(i) = k*g(i-1)
g(1) = f(1)-f(0)
g(2) = f(1)-f(0)
...
g(n) = f(n)-f(n-1)
...
g(n+m) = f(n+m)-f(n+m-1)
将上面的各个等式相加的：g(1)+g(2)+...+g(n+m)=f(n+m)-f(0)=1
g(1)+g(2)+...+g(n+m)=g(1)*(1-k^(n+m))/(1-k)
g(1)+g(2)+...+g(n)=g(1)*(1-k^(n))/(1-k)
回到开始定义，我们知道f(0)=0 (表示已经输了)，f(n+m)=1(表示已经赢了)
g(1)=f(1)-f(0)=f(1)
因此g(1)+g(2)+...+g(n+m) = f(1)*(1-k^(n+m))/(1-k)=1............................................（1）
g(1)+g(2)+...+g(n) = f(1)*(1-k^(n))/(1-k)=f(n)...................................................（2）
我们要求的就是f(n)，在（2）式中，只要f(1)是未知的，因此需要更（1）先求出f(1).最终f(n)=(1-k^n)/(1-k^(m+n))需要注意的几个地方：N==0、M==0、p==0、q==0、p==q集中特殊情况！ 
代码很简单，如下：
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int N,M;
    double p,q,rate,k;
    while(cin>>N>>M>>p>>q)
    {
        if(N==0){cout<<"0.00"<<endl;continue;}
        if(M==0){cout<<"1.00"<<endl;continue;}
        if(p==0||q==1){cout<<"0.00"<<endl;continue;}
        if(q==0||p==1){cout<<"1.00"<<endl;continue;}
        if(p==q) rate=1.0*N/(M+N);   M,N不一定等于0.5
        else
        {
            k = q*(1-p)/(p*(1-q));
            rate = (1.0-pow(k,N))/(1.0-pow(k,M+N));      【幂运算】
        }
        cout<<fixed<<setprecision(2)<<rate<<endl;    【设置浮点数输出的有效数字位数】
    }
    return 0;

}*/