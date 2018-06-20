//数据小，可以暴力解

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ret = 0;
        for(int i = -n; i <= n; i++)
            for(int j = -n; j <= n; j++)
                ret = max(ret, check(A, B, i, j));
        
        return ret;
    }
private:
    int check(vector<vector<int> >& A, vector<vector<int> >& B, int dx, int dy)
    {
        int cnt = 0;
        
        for(vector<vector<int> >::size_type i = 0; i < A.size(); i++)
        {
            if(i+dx < 0 || i+dx >= A.size())
                continue;
            
            for(vector<vector<int> >::size_type j = 0; j < A.size(); j++)
            {
                if(j+dy < 0 || j+dy >= A.size() || A[i][j] == 0)
                    continue;
                if(B[i+dx][j+dy] == 1)
                    cnt++;
            }
        }
        
        return cnt;
    }
};
