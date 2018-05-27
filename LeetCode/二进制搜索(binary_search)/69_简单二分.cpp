//二分查找一个整数的整数根
class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) return x;
        
        int high = x;
        int low = 1;
        int mid;
        int temp1, temp2;
        
        while(low <= high)
        {
            mid = (low + high) / 2;
            temp1 = x/mid;
            temp2 = x/(mid+1);
            
            if(mid <= temp1 && (mid+1) > temp2)
                return mid;
            else if(mid > temp1)
                high = mid - 1;
            else if((mid+1) <= temp2)
                low = mid + 1;
        }
    }
};
