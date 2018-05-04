//https://blog.csdn.net/sunnyyoona/article/details/43234889
#include<iostream>
#include<string>
#include<algorithm>
using std::string;



string KaratsubaMultiply(string num1, string num2)
{
    string::size_type len = MakeSameLen(num1, num2);
    
    if(len == 1)
        return std::to_string((num1[0]-'0') * (num2[0]-'0'));
    
    string::size_type mid = len / 2;
    
    //num1 = x1 * 10^mid + x0
    string x1 = num1.substr(0, mid);
    string x0 = num1.substr(mid, len-mid);
    
    //num2 = y1 * 10^mid + y0
    string y1 = num2.substr(0, mid);
    string y0 = num2.substr(mid, len-mid);
    
    //z0 = x0 * y0
    //z1 = (x1 + x0) * (y1 + y0)
    //z2 = x1 * y1
    string z0 = KaratsubaMultiply(x0, y0);
    string z1 = KaratsubaMultiply(AddString(x1, x0), AddString(y1, y0));
    string z2 = KaratsubaMultiply(x1, y1);
    
    //r1 = z2 * 10^(2*(len-mid))
    //r2 = (z1 - z2 -z0) * 10^(len-mid)
    string r1 = ShiftString(z2, 2 * (len-mid));
    string r2 = ShiftString(MinusString(MinusString(z1, z2), z0), len - mid);
    
    //r1 + r2 + z0
    return AddString(AddString(r1, r2), z0);
}