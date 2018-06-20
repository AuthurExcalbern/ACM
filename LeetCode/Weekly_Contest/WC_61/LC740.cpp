/* LeetCode Weekly Contest 61
 * problem 740. Delete and Earn

题意：
给一个数组，如果我们选取一个数num[i]则我们将删除这个数与每一个值为num[i] + 1 或 num[i] - 1 的数并得到num[i]积分
求怎么获得最大积分

Example 1:
Input: nums = [3, 4, 2]
Output: 6

Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9

Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:
The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

分析：
我们可以很容易的用dp求解
对于一个数值i，我们要么不取，那么我们会取值i-1，这样我们会删除数值i，则：dp[i] = dp[i - 1];
如果取数值i，则我们不取i-1：cur = i * cnt[i] + (i - 2 >= 0 ? dp[i - 2] : 0);

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int n = 10001;
        vector<int> cnt(n);
        for (auto& x : nums)//记录在每个值的数的数目
        {
            cnt[x]++;
        }
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i)//遍历每个值，dp求解
        {
            dp[i] = dp[i - 1];//取值i-1情况
            int cur = i * cnt[i] + (i - 2 >= 0 ? dp[i - 2] : 0);//取值i情况
            dp[i] = max(dp[i], cur);
        }
        return dp[n - 1];
    }
};
