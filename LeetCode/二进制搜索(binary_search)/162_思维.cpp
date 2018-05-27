//O(logn) : 查找一个数组的峰值

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return false;
        int begin=0; 
        int end=nums.size()-1;
        while(begin<end){
            int mid=(begin+end)/2;
            if(nums[mid]<nums[mid+1]) begin=mid+1;
            else end=mid;
        }
        return begin;
    }
};

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        
        int low = 0;
        int high = nums.size();
        int mid;
        
        while(low < high)
        {
            mid = (high - low) / 2 + low;
            
            if(mid == 0 || mid == nums.size()) continue;
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
                low = mid + 1;
            else if(nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1])
                high = mid;
            else //在低谷
                high = mid;
        }
        
        if(low != nums.size() && nums[low] > nums[low-1] && nums[low] > nums[low+1]) return low;
        
        return -1;
    }
};
*/
