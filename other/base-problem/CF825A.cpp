/* CF825A Binary Protocol
 * 
 * 题意：
 * 有一种新的01编码来把一串数字编码为01字符串
 * 数值多大就有多少个1,而0的编码为0
 * 
 * 输入：
 * 第一行输入n
 * 第二行输入n个01
 * 
 * 输出：
 * 输出翻译后的数字
 */
#include<iostream>
using namespace std;
int main(void)
{
    int n;
    string s;
    int cnt = 0;
    
    cin >> n;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
            cnt++;
        else
        {
            cout << cnt;
            cnt = 0;
        }
    }
    cout << cnt << endl;//因为最后一位数字没有0来分格，所以要再输出一次
    return 0;
}