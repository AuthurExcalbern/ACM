/* LeetCode Weekly Contest 61 第一题
 * problem 739. Daily Temperatures

题意：
给一个数组t，求下一个比t[i]大的数距离i多少位，如果不存在这为0，输出一个距离数组

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

分析：
可以从后向前记录更新一个best数组来解

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);//记录结果的数组
        vector<int> best(101, -1);//记录已经检测的数值的位置
        for (int i = n - 1; i >= 0; --i)//从后往前检测，这样相同数值的数的位置在best数组会不断更新
        {
            ret[i] = 1 << 30;
            for (int j = temperatures[i] + 1; j <= 100; ++j)//检测所有比在数组i位的值大的值
            {
                if (best[j] >= 0)//如果此值存在于已检测的数中
                {
                    ret[i] = min(ret[i], best[j] - i);//则减去i取得相对距离，并取距离最短的
                }
            }
            if (ret[i] == 1 << 30) ret[i] = 0;//如果不存在以检测的数比i的值大，则为0
            best[temperatures[i]] = i;//更新best数组
        }
        return ret;
    }
};
