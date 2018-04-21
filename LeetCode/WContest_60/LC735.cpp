/* LeetCode Weekly Contest 60 第三题
 * problem 735 Asteroid Collision

输入一个数组，正数代表向右移动，负数代表向左一定
两数相撞小的消失（绝对值比较），如果两数相等则都消失，输出最后的数组

Example 1:

Input: 
asteroids = [5, 10, -5]

Output: [5, 10]

Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:

Input: 
asteroids = [8, -8]

Output: []

Explanation: 
The 8 and -8 collide exploding each other.

Example 3:
Input: 
asteroids = [10, 2, -5]

Output: [10]

Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

Example 4:

Input: 
asteroids = [-2, -1, 1, 2]

Output: [-2, -1, 1, 2]

Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..

 * 关于deque的资料：
 * https://www.cnblogs.com/scandy-yuan/archive/2013/01/09/2853603.html

解法：
应用deque灵活解

 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> que;//创建
        vector<int> &a = asteroids;
        int n = a.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {//遍历每个数
            if (a[i] < 0) {//数小于0时
                bool exist = true;
                while (!que.empty()) {//deque非空
                    int val = que.back() + a[i];
                    //判断最后压入的正数是否大于此负数
                    if (val < 0) {//如果整数小就删除这个正数
                        que.pop_back();
                    } else if (val == 0) {//相等时
                        que.pop_back();
                        exist = false;
                        break;
                    } else {//正数大时直接无视此负数
                        exist = false;
                        break;
                    }
                }
                if (exist) {//当负数大于所有整数时压入负数
                    res.push_back(a[i]);
                }
            } else {//数为正数时就压入deque
                que.push_back(a[i]);
            }
        }
        while (!que.empty()) {
            res.push_back(que.front());
            que.pop_front();
        }
        return res;
    }
};
