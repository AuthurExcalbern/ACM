/* Probelm 732 My Calendar III

 * 每次都给定一个范围：start <= x < end
 * 然后设定一个函数，返回重复预订的次数

Example 1:

MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3

Explanation: 
The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
The remaining events cause the maximum K-booking to be only a 3-booking.
Note that the last event locally causes a 2-booking, but the answer is still 3 because
eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
Note:

The number of calls to MyCalendarThree.book per test case will be at most 400.
In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].

 */

using PII = pair<int, int>;
#define F first
#define S second
class MyCalendarThree {
public:
    map<PII, int> m;
    MyCalendarThree() {

    }

    int book(int start, int end) {
        m[{end, -1}]++;
        m[{start, 1}]++;
        int s = 0, maxn = 0;
        for (const auto &it : m) {
            s += it.S * it.F.S;
            if (maxn <= s) {
                maxn = s;
            }
        }
        return maxn;
    }
};
