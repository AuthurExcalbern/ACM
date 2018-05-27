//一个二分查找下线
//一个二分查找上线

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return vector<int>{-1, -1};
       
        int left = binary_search_left(nums, target);
        int right = binary_search_right(nums, target);
        
        return vector<int>{left, right};
    }
private:
    int binary_search_left(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size();
        int mid;
        
        while(low < high)
        {
            mid = low + (high - low) / 2;
            
            if(nums[mid] < target)
                low = mid + 1;
            else high = mid;
        }
        
        if(low != nums.size() && nums[low] == target) return low;
        else return -1;
    }
    
    int binary_search_right(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size();
        int mid;
        
        while(low < high)
        {
            mid = low + (high - low) / 2;
            
            if(nums[mid] <= target)
                low = mid + 1;
            else high = mid;
        }
        
        if(low-1 != nums.size() && nums[low-1] == target) return low-1;
        else return -1;
    }
};
