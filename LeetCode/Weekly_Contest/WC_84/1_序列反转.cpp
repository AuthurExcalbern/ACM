class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(vector<int>& rev : A)
        {
            reverse(rev.begin(), rev.end());
            for(int& i : rev)
                i ^= 1;
        }
        return A;
    }
};
