class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int rec1_x1 = rec1[0];
        int rec1_y1 = rec1[1];
        int rec1_x2 = rec1[2];
        int rec1_y2 = rec1[3];
        
        if(rec2[0] >= rec1_x2 || rec2[1] >= rec1_y2)
            return false;
        else if(rec2[2] <= rec1_x1 || rec2[3] <= rec1_y1)
            return false;
        else
            return true;
    }
};