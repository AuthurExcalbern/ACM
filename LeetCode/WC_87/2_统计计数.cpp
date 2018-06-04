//求数组里 一个先递增再递减的序列 的 最大长度

class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        const int n = A.size();
        vector<int> f(n), g(n);
        
        for (int i = 1; i < n; i++)
        {
            if (A[i] > A[i - 1])
                f[i] = f[i - 1] + 1;
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] > A[i + 1])
                g[i] = g[i + 1] + 1;
        }
        
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (f[i] > 0 && g[i] > 0)
                ans = max(ans, f[i] + g[i] + 1);
        }
        
        return ans;
    }
};
