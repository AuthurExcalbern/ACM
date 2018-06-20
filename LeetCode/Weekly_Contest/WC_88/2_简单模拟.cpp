//数组 a 中，0 代表空位， 1 代表有人
//求再安排一个人使他和其他人的距离达到最大

class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        int n = a.size();
        int ret = 0;
        
        for (int i = 0, j; i < n; i = j)
        {
            for (; i < n && a[i] == 1; ++i);
            if (i == n) break;
            for (j = i + 1; j < n && a[j] == 0; ++j);
            
            int len = j - i;
            if (i == 0 || j == n) {
                ret = max(ret, len);
            } else {
                ret = max(ret, (len - 1) / 2 + 1);
            }
        }
        return ret;
    }
};
