//给一个N×N的矩阵
//求有多少个3×3的小矩阵横竖和对角和相等
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        if(grid.size() < 3 || grid[0].size() < 3) return 0;
        
        for(int y = 0; y < grid.size()-2; y++)
        {
            for(int x = 0; x < grid[0].size()-2; x++)
            {//cout<<x<<endl;
                if(ismargic(y, x, grid))
                    ans++;
            }
        }
        
        return ans;
    }
private:
    bool ismargic(int y, int x, vector<vector<int>>& grid)
    {
        int sum[10], t = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = y; i < y + 3; i++)
        {
            for(int j = x; j < x + 3; j++)
            {
                if(grid[i][j] > 9 || grid[i][j] < 1)
                    return false;
                else
                    sum[t] = sum[t] + grid[i][j];
            }
            //cout<<sum[t]<<"   "<<t<<endl;
            t++;
        }
        
        for(int i = x; i < x + 3; i++)
        {
            for(int j = y; j < y + 3; j++)
                sum[t] = sum[t] + grid[j][i];
            //cout<<sum[t]<<"   "<<t<<endl;
            t++;
        }
        
        sum[6] = grid[y][x] + grid[y+1][x+1] + grid[y+2][x+2];//cout<<sum[6]<<endl;
        sum[7] = grid[y][x+2] + grid[y+1][x+1] + grid[y+2][x];//cout<<sum[7]<<endl;
        
        if(sum[0] == sum[1] && sum[0] == sum[2] && sum[0] == sum[3] && sum[0] == sum[4] && sum[0] == sum[5] && sum[0] == sum[6] && sum[0] == sum[7])
            return true;
        else
            return false;
    }
};
