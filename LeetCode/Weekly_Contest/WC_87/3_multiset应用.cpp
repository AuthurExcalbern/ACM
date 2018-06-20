//对于数组 hand
//问是否可以划分为 W 个大小都为 W 的 连续 数组

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        multiset<int> g;
        for(auto i:hand) g.insert(i);
        
        while(g.size())
        {
            int st=*g.begin();
            for(int i=st;i<st+W;i++)
            {
                if(g.count(i)==0) return 0;
                g.erase(g.find(i));
            }
        }
        return 1;
    }
};
