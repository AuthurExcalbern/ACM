/*
 * HDU 1014
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1014
 * 
 * seed(x+1) = [seed(x) + STEP] % MOD
 */

#include<stdio.h>

int main()
{
    long long int num_a, num_b;
    int status;
    int count_i;
    
    while(scanf("%I64d%I64d", &num_a, &num_b) != EOF)
    {
        for( count_i = 1; count_i <= num_a && count_i <= num_b; count_i++)
        {
            if( num_a % count_i == 0 && num_b % count_i == 0)
                status = count_i;
        }
        
        if(status == 1)
            printf("%10lld%10lld    Good Choice\n\n", num_a, num_b);
        else
            printf("%10lld%10lld    Bad Choice\n\n", num_a, num_b);
    }
}