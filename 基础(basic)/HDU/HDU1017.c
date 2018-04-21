/*
 * HDU 1017
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1017
 * 
 * Given two integers n and m, count the number of pairs of integers (a,b) such that 0 < a < b < n and (a^2+b^2 +m)/(ab) is an integer.
 * This problem contains multiple test cases!
 * The first line of a multiple input is an integer N, then a blank line followed by N input blocks.
 * Each input block is in the format indicated in the problem description. There is a blank line between input blocks.
 * The output format consists of N output blocks. There is a blank line between output blocks.
 */

#include<stdio.h>

int judge(int n,int m)
{
    int cnt = 0, i, j;//i and j are used to count.
    for( i = 1; i < n; i++)
        for( j = i + 1; j < n; j++)
            if( ( i * i + j * j + m ) % ( i * j ) == 0 )
                cnt++;
    return cnt;
}

int main(void)
{
    int N,n,m,cnt;
    int count_i, count_j;
    
    scanf("%d",&N);
    getchar();
    //getchar(); have it or not all can AC??!!
    
    for( count_i = 0; count_i < N; count_i++)
    {
        count_j = 1;
        
        while ( scanf("%d%d", &n, &m) == 2 && !( n == 0 && m == 0) )
        {
            cnt = judge(n,m);
            
            printf("Case %d: %d\n", count_j++, cnt);
        }
        
        if( count_i < N - 1)
            printf("\n");
    }
    return 0;
}