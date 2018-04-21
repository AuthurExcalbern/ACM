/*
 * HDU 1004
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1004
 * 
 * Count the balloons of each color and find the max color.
 */

#include<stdio.h>
#include<string.h>

int main(void)
{
    int colorNum;
    int count_i, count_j;
    int num[1000];
    int maxinum,record;
    char color[1000][16];
    
    while(scanf("%d", &colorNum), colorNum != 0)
    {
        maxinum = 0;//Initialize
        record = 0;
        
        for(count_i = 0; count_i < colorNum; count_i++)
        {
            num[count_i] = 0;
            scanf("%s", color[count_i]);
            
            for( count_j = 0; count_j <= count_i-1; count_j++)      //Count how many each color appear.
            {
                if( strcmp( color[count_i], color[count_j]) == 0 )
                    num[count_i]++;
            }
        }
        
        
        for( count_i = 1; count_i < colorNum; count_i++)            //Find the maxinum color
        {
            if( maxinum < num[count_i])
            {
                maxinum = num[count_i];
                record = count_i;
            }
        }
        
        printf("%s\n",color[record]);
    }
    return 0;
}
