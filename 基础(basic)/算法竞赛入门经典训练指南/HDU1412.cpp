/* HDU 1412

给两个集合的并集，并按从大到小输出
两集合里没有相同的元素

 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[20020];
int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i < n+m; i++)
            scanf("%d", num+i);
        sort(num, num+n+m);
        printf("%d", num[0]);
        for(int i = 1; i < n+m; i++)
        {
            if(num[i] != num[i-1])
                printf(" %d", num[i]);
        }
        printf("\n");
    }
    return 0;
}