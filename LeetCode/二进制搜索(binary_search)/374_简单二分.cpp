// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int low = 1;
        int high = n;
        int mid;
        
        while(low <= high)
        {
            mid = (high - low) / 2 + low;
            
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
};
