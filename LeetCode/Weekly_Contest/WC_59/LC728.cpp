/* LeetCode Weekly Contest 59 第一题
 * problem 728 Self Dividing Numbers

 * 给定一个范围：left <= n <= right
 * 求在这范围里每一个能被自己每一位数字整除的整数
 * 如：128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0 所以128符合要求
 * 要排除有除数为零时的整数

Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

 * 关于vetor的资料：
 * http://www.cnblogs.com/mr-wid/archive/2013/01/22/2871105.html
 * http://blog.csdn.net/hancunai0017/article/details/7032383
 */

//他人解法
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> a;
        for (int i = left; i <= right; ++i) {
            string s = to_string(i);//把读入的数字转变为字符串
            bool ok = true;
            for (char c : s) {//遍历字符串的字符
                int x = c - '0';
                if (x == 0 || i % x) {
                    ok = false;
                    break;
                }
            }
            if (ok) a.push_back(i);//把合格的数字压入数组
        }
        return a;
    }
};

//我的解法
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int cnt = 0;
        vector<int> ans(10010, 0);
        for(int i = left; i <= right; i++)
        {
            if(i == 10000)
            {
                ans[cnt] = 10000;cnt++;
                break;
            }
            else if(i >= 1000)
            {
                int a = i % 10;
                int b = (i % 100 - a) / 10;
                int c = (i % 1000 - b - a) / 100;
                int d = (i - c - b - a) / 1000;
                if(a!=0&&i%a==0 && b!=0&&i%b==0 && c!=0&&i%c==0 && d!=0&&i%d==0)
                {
                    ans[cnt] = i;
                    cnt++;
                }
            }
            else if(i >= 100)
            {
                int a = i % 10;
                int b = (i % 100 - a) / 10;
                int c = (i % 1000 - b - a) / 100;
                if(a!=0&&i%a==0 && b!=0&&i%b==0 && c!=0&&i%c==0)
                {
                    ans[cnt] = i;
                    cnt++;
                }
            }
            else if(i >= 10)
            {
                int a = i % 10;
                int b = (i % 100 - a) / 10;
                if(a!=0&&i%a==0 && b!=0&&i%b==0)
                {
                    ans[cnt] = i;
                    cnt++;
                }
            }
            else
            {
                ans[cnt] = i;
                cnt++;
            }
        }
        vector<int> answ(cnt,0);
        for(int i = 0; i <= cnt-1; i++) answ[i] = ans[i];
        return answ;
    }
};
