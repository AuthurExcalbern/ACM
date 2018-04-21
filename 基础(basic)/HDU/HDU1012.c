/*
 * HDU 1012
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1012
 * 
 * Calculate e
 */

#include <stdio.h>

int f(int n)
{
    int i,t;                                            //i and t all are used to count.
    
    if(n == 0)                                          //Special case: 0! = 1
        return 1;
    
    t = 1;
    for( i = 1; i <= n; i++)                            //Calculate n!
        t = t * i;
    
    return t;
}

int main()
{
    int count_i,count_j;
    int n;
    double ans;
    
    printf("n e\n");
    printf("- -----------\n");
    
    for( count_i = 0; count_i <= 9; count_i++)
    {
        ans = 0.0;
        
        for( count_j = 0; count_j <= count_i; count_j++)//Calculate e
            ans = ans + 1.0/f(count_j);
        
        if( count_i == 0 || count_i == 1)
            printf("%d %.0f\n", count_i, ans);
        else if( count_i == 2)
            printf("%d %.1f\n", count_i, ans);
        else
            printf("%d %.9lf\n", count_i, ans);
    }
    
    return 0;
}