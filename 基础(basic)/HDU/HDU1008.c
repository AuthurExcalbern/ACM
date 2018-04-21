/*
 * HDU 1008
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1008
 * 
 * The highest building in our city has only one elevator.
 * A request list is made up with N positive numbers.
 * The numbers denote at which floors the elevator will stop, in specified order.
 * It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor.
 * The elevator will stay for 5 seconds at each stop.
 * For a given request list, you are to compute the total time spent to fulfill the requests on the list.
 * The elevator is on the 0th floor at the beginning
 * and does not have to return to the ground floor when the requests are fulfilled.
 */

 #include <stdio.h>

int main()
{
    int testCaseNum;
    int floor_now, floor_pre;
    int count_i;
    int count;
    
    while(scanf("%d", &testCaseNum), testCaseNum != 0)
    {
        floor_pre = 0;                                                  //Initialize
        count = 0;
        
        for(count_i = 0; count_i < testCaseNum; count_i++)
        {
            scanf("%d", &floor_now);
            
            if(floor_now > floor_pre)                                   //up
            {
                count = count + (floor_now - floor_pre) * 6 + 5;
            }
            else                                                        //dowm
            {
                count = count + (floor_pre - floor_now) * 4 + 5;
            }
            
            floor_pre = floor_now;
        }
        
        printf("%d\n", count);
    }
    return 0;
}
