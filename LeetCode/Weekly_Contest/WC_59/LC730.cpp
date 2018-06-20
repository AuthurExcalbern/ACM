/* LeetCode Weekly Contest 59 第三题
 * problem 730 Count Different Palindromic Subsequences

 * 给一个字符串，求出它所有非空子串是回文字符串的个数（相同的字串不重复计算
 * 求出的数目取 mod 10^9 + 7

Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.

The length of S will be in the range [1, 1000].
Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
 */

//他人解法
#define REP(i, n) for (int i = 0; i < int(n); ++i)
using LL = long long;

const LL mod = 1000000007;
char s[1010];
int nxt[1010][26];
int lst[1010][26];

LL dp[1010][1010];

LL f(int l, int r) {
    LL &ret = dp[l][r];
    if (ret >= 0)
      return ret;
    if (l > r) return ret = 1;
    ret = 1;
    REP(i, 26) {
      int a = nxt[l][i];
      int b = lst[r][i];
      if (a < b) ret += f(a + 1, b - 1);
      if (a <= r) ret += 1;
    }
    ret %= mod;
    return ret;
}


int solve(string S) {
    strcpy(s + 1, S.c_str());//c_str()返回一个临时指针
    int n = strlen(s + 1);
    REP(i, 26) nxt[n + 1][i] = n + 1;//初始化第n+1个数组，数字为27（超出26
    for (int i = n; i >= 1; --i) {
      REP(j, 26) nxt[i][j] = nxt[i + 1][j];//将后面的数组都初始化为n+1数组
      nxt[i][s[i] - 'a'] = i;//将字符串转变为数字，nxt[字符串里第i个字母][此字母在字母表中的位置]=i
    }
    REP(i, 26) lst[0][i] = 0;//初始化空出来的第一个数组
    for (int i = 1; i <= n; ++i) {
      REP(j, 26) lst[i][j] = lst[i - 1][j];//将初始化向后赋值
      lst[i][s[i] - 'a'] = i;//同nxt
    }
    memset(dp, -1, sizeof dp);
    LL ans = f(1, n);
    ans = ans == 0 ? mod - 1 : ans - 1;
    return ans;
}



class Solution {
public:
    int countPalindromicSubsequences(string S) {
        return solve(S);
    }
};
