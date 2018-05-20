#ifndef _KARATSUBA_H_
#define _KARATSUBA_H_

#include"karatsuba.cpp"

using std::string;

//使两个字符串等长
string::size_type MakeSameLen(string& num1, string& num2);

//return num1 - num2;
string MinusString(string num1, string num2);

//return num1 + num2;
string AddString(string num1, string num2);

//num = num * 10^len;
string ShiftString(string num, string::size_type len);

//return num1 * num2
string KaratsubaMultiply(string num1, string num2);

#endif