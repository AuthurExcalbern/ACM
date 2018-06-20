//二分搜索出索引 i
//A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int high = A.size() - 2;
        int low = 1;
        int mid;
        
        while(high >= low)
        {
            mid = (high - low) / 2 + low;
            
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            else if(A[mid] > A[mid-1] && A[mid] < A[mid+1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
};
