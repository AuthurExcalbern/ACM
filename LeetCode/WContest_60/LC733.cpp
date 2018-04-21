/* LeetCode Weekly Contest 60 第一题
 * problem 733 Flood Fill

给定一个二维平面，二维数组内容都是0到65535的数组
再给一个起始点，给一个染色数字，让起始点与所有与起始点同数字且与起始点在四个方向连成一片的点都变成染色数字

Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

1, 1, 1   2, 2, 2
1, 1，0 ->2, 2, 0
1, 0, 1   2, 0, 1

The length of image and image[0] will be in the range [1, 50].

The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.

The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

解法：
可以用队列和标记法来实现广度优先搜索来解决

 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();//n为行数，m为列数
        vector<vector<int> > res = image;//复制出一个相同的地图
        queue<pair<int, int> > que;//创建一个队列，成员是pair<int, int>
        vector<vector<bool> > vis(n, vector<bool>(m));//创建一个bool类型的二维数组，这二维数组有n行，vector<bool>(m)表示构造一个无名且含m个0的vector<bool>对象
        que.push(make_pair(sr, sc));//在队列中压入起始点
        vis[sr][sc] = true;//把起始点的内容转换并标记
        res[sr][sc] = newColor;
        int dx[] = {0, 1, 0, -1};//前进的四个方向
        int dy[] = {-1, 0, 1, 0};
        //对于队列中的每个点依照先进先出的原则，对每个出队的点寻找它四个方向的点，如果有与出队点颜色颜色相同且未被标记的点，就改变其颜色且标记，并入队，直到队列非空为止
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && image[x][y] == image[nx][ny]) {
                    res[nx][ny] = newColor;
                    vis[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                }
            }
        }
        return res;
    }
};
