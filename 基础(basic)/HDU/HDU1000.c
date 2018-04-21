/*
 * HDU 1000
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1000
 * 
 * Calculate A + B.
 */

#include <stdio.h>

int main()
{
    int addNum_a, addNum_b;
    while(scanf("%d%d", &addNum_a, &addNum_b) != EOF)
    {
        printf("%d\n", addNum_a + addNum_b);
    }
    return 0;
}
