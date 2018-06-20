/* LeetCode Weekly Contest 59 第二题
 * Probelm 729 My Calendar I

 * 每次都给定一个范围：start <= x < end
 * 然后设定一个函数
 * 如果给定的范围都不曾给过，就进行记录，并返回ture；如果已经给过，就返回false

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.

 * 关于pair的资料：
 * http://blog.csdn.net/edward_wong/article/details/39480527
 * https://www.quora.com/How-can-I-use-pair-int-int-v-in-C++-language
 * 
 * 关于map的资料：
 * https://www.cnblogs.com/hailexuexi/archive/2012/04/10/2440209.html
 */

//他人解法
using PII = pair<int, int>;
#define F first
#define S second
class MyCalendar {
public:
    map<PII, int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        m[{end, -1}]++;//注意这里的巧妙设计
        m[{start, 1}]++;
        int s = 0;
        for (const auto &it : m) {
            s += it.S * it.F.S;
            if (s >= 2) {//如果在一段区域内出现了第二个start，s就会>=2
                m[{end, -1}]--;
                m[{start, 1}]--;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
