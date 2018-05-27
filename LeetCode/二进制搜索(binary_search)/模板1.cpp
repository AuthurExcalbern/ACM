class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int nums_high = nums.size() - 1;//注意这里为size()-1
        int nums_low = 0;
        int mid;
        
        while(nums_low <= nums_high)
        {
            //防止超限
            mid = (nums_high - nums_low) / 2 + nums_low;
            
            if(nums[mid] < target)
                nums_low = mid+1;
            else if(nums[mid] > target)
                nums_high = mid-1;
            else
                return mid;
        }
        
        return -1;
    }
};
