/*
 * HDU 1002
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1001
 * 
 * In this problem, our task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
 */

#include<stdio.h>

int main()
{
    int count_i, boundary, sum;
    while(scanf("%d", &boundary) != EOF)     //EOF==Ctrl+z
    {
        sum = 0;
        for( count_i = 1; count_i <= boundary; count_i++)
        {
            sum = sum + count_i;
        }
        printf("%d\n\n", sum);               //Notice:It need two "\n"!
    }
    return 0;
}