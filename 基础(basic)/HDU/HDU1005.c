/*
 * HDU 1005
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1005
 * 
 * A number sequence is defined as follows:
 * f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
 * Given A, B, and n, you are to calculate the value of f(n).
 */

#include<stdio.h>

int main()
{
    int A,B,n;
    int count_i;
    int array[48];
    while( scanf("%d %d %d", &A, &B, &n), A || B || n)
    {
        array[1] = 1;
        array[2] = 1;
        
        for(count_i = 3; count_i < 48; count_i++)                       //It's regular!
            array[count_i] = ( A * array[count_i - 1]
                                    + B * array[count_i - 2] ) % 7;
        
        printf("%d\n", array[ n % 48] );
    }
    return 0;
}

/*Memory Limit Exceeded
 * 
#include <stdio.h>

int f(long int n,int A,int B)
{
    int result;
    if(n == 1 || n == 2)
        return 1;
    else
    {
        result = ( A * f( n-1, A, B) + B * f( n-2, A, B) ) % 7;
        return result;
    }
}

int main(void)
{
    int A,B;
    long int n;
    while( scanf( "%d %d %ld", &A, &B, &n), ( A != 0 || B != 0 || n != 0) )
    {
        printf("%d\n", f(n,A,B) );
    }
    return 0;
}
*/