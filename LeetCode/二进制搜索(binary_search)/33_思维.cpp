//一个已经排序好的数组向右边移动未知位
//要求用O(logn)的解法
//可以把非target所在的一边设置为MAX或MIN

/* 一个很酷的解法：
int search(vector<int>& nums, int target) 
{
        auto skip_left  = [&]( int x) { return x >= nums[0] ? numeric_limits<int>::min() : x; };
        auto skip_right = [&] (int x) { return x < nums[0] ? numeric_limits<int>::max() : x; };
        auto adjust = [&] (int x) { return target < nums[0] ? skip_left(x) : skip_right(x); };
  
        auto it = lower_bound( nums.begin(), nums.end(), target, [&] (int x, int y) { return adjust(x) < adjust(y); } );
            
        return it != nums.end() && *it == target ? it-nums.begin() : -1;
}
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return -1;
        
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        bool flag = target < nums[0];
        
        while(low <= high)
        {
            mid = (high - low) / 2 + low;
            
            int temp = (nums[mid] < nums[0]) == flag ? nums[mid] : \
                ((target < nums[0]) ?  numeric_limits<int>::min() : numeric_limits<int>::max());
            
            if(temp < target)
                low = mid + 1;
            else if(temp > target)
                high = mid - 1;
            else
                return mid;
        }
        
        return -1;
    }
};
