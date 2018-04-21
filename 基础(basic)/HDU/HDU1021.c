/*
 * HDU 1021
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1021
 * 
 * There are another kind of Fibonacci numbers: F(0) = 7, F(1) = 11, F(n) = F(n-1) + F(n-2) (n>=2).
 * Print the word "yes" if 3 divide evenly into F(n).
 * Print the word "no" if not.
 */

#include<stdio.h>  

int main(void)
{
    int n;
    
    while( scanf("%d", &n) != EOF)//It's regular.
    {
        if( n % 4 == 2)
            printf("yes\n");
        else
            printf("no\n");    
    }
    return 0;
}
