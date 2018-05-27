// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 0;
        int high = n;
        int mid;
        bool flag;
        
        while(low < high)
        {
            mid = (high - low) / 2 + low;
            flag = isBadVersion(mid);
            
            if(flag)
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};
