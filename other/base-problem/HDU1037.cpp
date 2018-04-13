/* HDU 1037
 * 
 * 输入三个数，输出第一个不大于168的数字，如果都大于168则NO CRASH
 * 
 */
#include<iostream>
using namespace std;
int main(void)
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        if(a > 168 && b > 168 && c > 168)
            cout << "NO CRASH" << endl;
        else if(a <= 168)
            cout << "CRASH " << a << endl;
        else if(b <= 168)
            cout << "CRASH " << b << endl;
        else if(c <= 168)
            cout << "CRASH " << c << endl;
    }
    return 0;
}