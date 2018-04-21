/*
 * HDU 1052
 * 
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1052
 * 
 * It's solve by greedy algorithm.
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void *b)             //used to qsort,make arrey sort form big to small.
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int i,n;                                    //n is each test case number.
    int tian,king;                              //i,tian,king all is used to count.
    int ha,hb,la,lb;
    int a[1005],b[1005];
    
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        getchar();
        memset( a, 0, sizeof(a) );              //Initialize
        memset( b, 0, sizeof(b) );
        ha = hb = 0;
        la = lb = n-1;
        tian = king = 0;
        
        for(i = 0; i < n; i++)                  //get data
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &b[i]);
        
        qsort(a, n, sizeof(int), cmp);          //sort arrey form big to small
        qsort(b, n, sizeof(int), cmp);
        
        
        
        while(ha != la)
        {
            if(a[ha] > b[hb])                   //compare the fastest one
            {
                tian++;
                ha++;
                hb++;
            }
            else if(a[la] > b[lb])              //compare the slowest one
            {
                tian++;
                la--;
                lb--;
            }
            else if(a[la] < b[hb])              //compare the fastest with slowest
            {
                king++;
                la--;
                hb++;
            }
            else
                break;
        }
        
        if(a[ha] > b[hb])
            tian++;
        else if(a[ha] < b[hb])
            king++;
        
        printf("%d\n", (tian-king)*200);
    }
    system("pause");
    return 0;
}