//一个已经排好序的数组向右移动未知位
//O(logn) 求最小值

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while(low < high)
        {
            if(nums[low] < nums[high])
                return nums[low];
            
            mid = (high - low) / 2 + low;
            
            if(nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid;
        }
        
        return nums[low];
    }
};
