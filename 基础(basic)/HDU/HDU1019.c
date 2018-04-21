/*
 * HDU 1019
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1019
 * 
 * The least common multiple (LCM) of a set of positive integers is the smallest positive integer
 * which is divisible by all the numbers in the set.
 * For example, the LCM of 5, 7 and 15 is 105.
 */

#include<stdio.h>

int main(){
    
    int count_i,count_z;
    int case_num,each_case_num;
    int num[12767];
    int M,N,count,R;                                            //used to Euclidean algorithm
    
    scanf("%d", &case_num);
    
    for( count_i = 0; count_i < case_num; count_i++)
    {
        scanf("%d", &each_case_num);
        
        for( count_z = 0; count_z < each_case_num; count_z++)
        {
            scanf("%d", &num[count_z]);
        }
        
        count=num[0];                                           //Initialize
        
        for( count_z = 1; count_z < each_case_num; count_z++)   //Euclidean algorithm
        {
            M = count;
            N = num[count_z];
            
            while( N > 0)
            {
                R = M % N;
                M = N;
                N = R;
            }
            //count = count * n[z] / M;                         It will overflow.
            count = (count / M ) * num[count_z];
        }
        printf("%d\n",count);
    }
    return 0;
}