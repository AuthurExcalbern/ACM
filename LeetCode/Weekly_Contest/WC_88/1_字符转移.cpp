//给一个小写字符串 S 和 数组 a
//S[1~i] 的字符要向右注意 a[i] 位

class Solution {
public:
    string shiftingLetters(string S, vector<int>& a) {
        int n = a.size();
        
        for (int i = n - 2; i >= 0; --i)
        {
            a[i] += a[i + 1];
            a[i] %= 26;
        }
        
        for (int i = 0; i < n; ++i)
        {
            int k = S[i] - 'a';
            k = (k + a[i]) % 26;
            S[i] = (char)('a' + k);
        }
        return S;
    }
};
