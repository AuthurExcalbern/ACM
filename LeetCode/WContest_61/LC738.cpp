/* LeetCode Weekly Contest 61
 * problem 738. Monotone Increasing Digits

题意：
给一个数n，求出比n小的能让各个位的数字从小到大的最大的数

Example 1:
Input: N = 10
Output: 9

Example 2:
Input: N = 1234
Output: 1234

Example 3:
Input: N = 332
Output: 299

Note: N is an integer in the range [0, 10^9].

*/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> a;
        for (int t = N; t; t /= 10) a.push_back(t % 10);//从高位到低位压入n的每一位数
        int m = a.size();
        int ret = 0, pre = 0;//ret为返回的结果数字，pre记录目前我们已经取得的数字的最大值
        for (int i = 0; i < m; ++i)//从高位到低位检测n的每一个数
        {
            for (int k = 9; k >= pre; --k)//对于每一位，检测从pre到9那个数字合适
            {
                int cur = ret;//把目前已经取得的数字赋值给cur
                for (int j = i; j < m; ++j)//目前距离最低位还有多少个数字就进行多少次循环
                {
                    cur = cur * 10 + k;//后面的值都先取一样值
                }
                
                if (cur <= N)//如果得出的值小于N
                {
                    ret = ret * 10 + k;//将值加入ret
                    pre = k;//更新pre
                    break;
                }
            }
        }
        return ret;
    }
};
