/*
 * HDU 1009
 * 
 * URL:http://acm.hdu.edu.cn/showproblem.php?pid=1009
 * 
 * 部分背包/分数背包
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trade//save data
{
    int J;
    int F;
    double pro;
};

int cmp(const void* a, const void* b)                           //sort:from big to small
{
    if( ((struct trade*)b)->pro >= ((struct trade*)a)->pro )
        return 1;
    else
        return -1;                                              //amazing!When it's 0,it can't pass!why?
}

int main(void)
{
    int M, N;
    double ans;
    int count_i;
    struct trade * room;
    
    while( scanf("%d %d", &M, &N) , M != -1 || N != -1)
    {
        ans = 0;
        room = (struct trade *) malloc ( N * sizeof(struct trade) );
        
        for( count_i = 0; count_i < N; count_i++)
        {
            scanf("%d %d", &room[count_i].J, &room[count_i].F );
            
            room[count_i].pro = room[count_i].J * 1.0 / room[count_i].F;
        }
        
        qsort( room, N, sizeof(struct trade), cmp);
        
        for( count_i = 0; count_i < N; count_i++)
        {
            if( M >= room[count_i].F )
            {
                M = M - room[count_i].F;
                ans = ans + room[count_i].J;
            }
            else
            {
                ans = ans + M * room[count_i].pro;
                break;
            }
        }
        
        printf("%.3lf\n", ans);
        
        free(room);
    }
    return 0;
}