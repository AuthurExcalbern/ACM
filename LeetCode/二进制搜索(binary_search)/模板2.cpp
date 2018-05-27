class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int nums_high = nums.size();//注意这里为size()
        int nums_low = 0;
        int mid;
        
        //等于时跳出
        while(nums_low < nums_high)
        {
            //防止超限
            mid = (nums_high - nums_low) / 2 + nums_low;
            
            if(nums[mid] < target)
                nums_low = mid+1;
            else if(nums[mid] > target)
                nums_high = mid;
            else
                return mid;
        }
        
        //当最后这个元素还在数组内时，需要再判断一次
        if(nums_low != nums.size() && nums[nums_low] == target)
            return nums_low;
        
        return -1;
    }
};
