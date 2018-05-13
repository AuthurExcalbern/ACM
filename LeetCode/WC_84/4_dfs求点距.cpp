const int MAXN = 10000;
vector<int> edges[MAXN];
class Solution {
    vector<int> nodes, in, out;
    
    void dfs_in (int cur, int par) {
        int node = 1, ret = 0;
        for (int nxt : edges[cur]) {
            if (nxt == par) continue;
            dfs_in(nxt, cur);
            node += nodes[nxt];
            ret += in[nxt] + nodes[nxt];
        }
        in[cur] = ret;
        nodes[cur] = node;
    }
    void dfs_out (int cur, int par) {
        if (par != -1) {
            out[cur] += out[par] + nodes[0] - nodes[par];
            int sibi = nodes[par] - nodes[cur];
            int val = in[par] - in[cur] - nodes[cur];
            out[cur] += val + sibi;
        }
        for (int nxt : edges[cur]) {
            if (nxt == par) continue;
            dfs_out(nxt, cur);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& tmp) {
        nodes = vector<int>(N, 0);
        in = nodes;
        out = nodes;
        for (int i = 0; i < N; i++) {
            edges[i].clear();
        }
        for (auto & item : tmp) {
            edges[item[0]].push_back(item[1]);
            edges[item[1]].push_back(item[0]);
        }
        dfs_in(0, -1);
        dfs_out(0, -1);
        vector<int> ret(N, 0);
        for (int i = 0; i < N; i++) {
            ret[i] = out[i] + in[i];
        }
        return ret;
        
    }
};
