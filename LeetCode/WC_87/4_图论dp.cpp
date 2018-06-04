class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int> > a(n, vector<int>(n, 10000));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                a[i][graph[i][j]] = a[graph[i][j]][i] = 1;
            }
            a[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
                // cout << i << "\t" << j << "\t" << a[i][j] << endl;
            }
        }
        int up = 1 << n;
        vector<vector<int> > dp(up, vector<int>(n, 100000));
        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < up; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < n; k++) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[up - 1][i]);
        }
        return res;
    }
};

