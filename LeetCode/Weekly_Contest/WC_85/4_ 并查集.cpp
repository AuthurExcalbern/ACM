class Solution {
public:
    
    vector<int> parent;
    
    void unite(int a, int b){
        int aa = find(a);
        int bb = find(b);
        
        parent[aa] = parent[bb];
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    bool good(const string &a, const string &b)
    {
        int count = 0;
        
        for (int i = 0; i < a.size(); ++i) {
            count +=  (a[i] != b[i]);
        }
        
        return count == 2;
    }
    
    int numSimilarGroups(vector<string>& A) {
        parent.resize(A.size());
        for (int i = 0; i < A.size(); ++i) {
            parent[i] = i;
        }
        
        
        for (int i = 0; i < A.size();++i) {
            for (int j = i+1; j < A.size(); ++j) {
                if (find(i) == find(j)) {
                    continue;
                }
                
                if (good(A[i], A[j])) {
                    unite(i, j);
                }
            }
        }
        
        set<int> s;
        
        for (int i = 0; i < A.size(); ++i) {
            s.insert(find(i));
        }
        
        return s.size();
    }
};
