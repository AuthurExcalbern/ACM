//https://blog.csdn.net/sunnyyoona/article/details/43234889
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<cstddef>
using std::string;

//使两个字符串等长
string::size_type MakeSameLen(string& num1, string& num2)
{
    string::size_type len1 = num1.size();
    string::size_type len2 = num2.size();
    
    if(len1 < len2)
    {
        //改进
        for(string::size_type i = 0; i < len2 - len1; i++)
            num1 = "0" + num1;
        
        return len2;
    }
    else
    {
        for(string::size_type i = 0; i < len1 - len2; i++)
            num2 = "0" + num2;
        
        return len1;
    }
}

//return num1 - num2;
string MinusString(string num1, string num2)
{
    string::size_type len1 = num1.size();
    string::size_type len2 = num2.size();
    
    if(num1 == num2)
        return "0";
    
    bool positive = true;
    if(len1 < len2 || (len1 == len2 && num1 < num2))
    {
        positive = false;
        
        std::swap(num1, num2);
        
        std::swap(len1, len2);
    }
    
    string ret;
    int i = len1 - 1;
    int j = len2 - 1;
    int a, b, sum, carry = 0;
    
    while(i >= 0 || j >= 0)
    {
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        sum = a - b + carry;
        carry = 0;
        
        if(sum < 0)
        {
            sum += 10;
            carry = -1;
        }
        
        ret.insert(ret.begin(), sum + '0');
        
        i--;
        j--;
    }
    
    string::iterator iter = ret.begin();
    while(iter != ret.end() && *iter == '0')
        iter++;
    ret.erase(ret.begin(), iter);
    
    return positive ? ret : "-" + ret;
}

//return num1 + num2;
string AddString(string num1, string num2)
{
    string::size_type len1 = num1.size();
    string::size_type len2 = num2.size();
    
    if(len1 <= 0)
        return num2;
    if(len2 <= 0)
        return num1;
    
    string ret;
    int i = len1 - 1;
    int j = len2 - 1;
    int a, b, sum, carry = 0;
    
    while(i >= 0 || j >= 0 || carry > 0)
    {
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        
        sum = a + b + carry;
        
        carry = sum / 10;
        ret.insert(ret.begin(), sum % 10 + '0');
        
        i--;
        j--;
    }
    
    return ret;
}

//num = num * 10^len;
string ShiftString(string num, string::size_type len)
{
    if(num == "0")
        return num;
    
    for(string::size_type i = 0; i < len; i++)
        num += "0";
    
    return num;
}

//return num1 * num2
string KaratsubaMultiply(string num1, string num2)
{
    string::size_type len = MakeSameLen(num1, num2);
    
    //to_string 需要用 C++11 标准
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