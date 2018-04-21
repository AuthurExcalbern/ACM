/*
 * HDU 1032
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1032
 * 
 * For each pair of input integers i and j you should output i, j, and the maximum cycle length for integers between and including i and j.
 */

#include <stdio.h>

int f(int n)                                        //Calculate the cycle length
{
    int count = 0;
    
    while(n!=1)
    {
        if( n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
        count++;
    }
    return count+1;
}

int main()
{
    int count_i,count_j;
    int maxinum;
    int temp;
    
    while( ~scanf("%d%d", &count_i, &count_j))      //It's native
    {
        printf("%d %d ", count_i, count_j);
        
        if( count_i > count_j)
        {
            temp = count_i;
            count_i = count_j;
            count_j = temp;
        }
        
        max = f(count_i);
        
        for( count_i++; count_i <= count_j; count_i++)
        {
            if( max < f(i) )
                max = f(i);
        }
        
        printf("%d\n",max);
    }
    return 0;
}