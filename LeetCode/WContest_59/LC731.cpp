/* LeetCode Weekly Contest 59 第四题
 * Probelm 731 My Calendar II

 * 每次都给定一个范围：start <= x < end
 * 然后设定一个函数
 * 如果给定的范围都不曾给超过三次（包括第三次）过，就进行记录，并返回ture；如果已经给过，就返回false

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation: 
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].

 */

//他人解法
using PII = pair<int, int>;
#define F first
#define S second
class MyCalendarTwo {
public:
    map<PII, int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[{end, -1}]++;
        m[{start, 1}]++;
        int s = 0;
        for (const auto &it : m) {
            s += it.S * it.F.S;
            if (s >= 3) {
                m[{end, -1}]--;
                m[{start, 1}]--;
                return false;
            }
        }
        return true;
    }
};

