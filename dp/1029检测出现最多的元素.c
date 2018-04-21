/*
 题意：给你n（n是奇数）个整数，求出现（n+1）/2次的数。也就是在此序列中出现次数最多的数（超过一半了~）。

算法思想：如果a是序列中出现次数最多的数，假如在该序列中删除两个不同的数。
那么a还是该序列中出现次数最多的数。
很好理解，假如一个序列有2k+1（k是整数，题目中规定n是奇数）个整数，一开始a出现了k+1，是序列中出现次数最多的数。
如果删除两个不同的数，此时分两种情况考虑：
（1）删除的数据组含有a，则此时a出现的次数是k，序列元素的总个数为2k-1，a 仍然是序列中出现次数最多的数。
（2）若删除的数据中不包含a，则a出现的次数为k+1，序列元素的总个数为2k-1。此时，a仍然是出现次数最多的数。

那么如何将上述思想运用到该题中呢？ 
举个例子： 
1 3 2 3 3 
最初，curIndex=0，指向数组中的第一个元素1，i=1，指向3，即数组中第2个元素，count=1。
i不断向后扫描，如果，扫描到的数据等于curIndex指向的数据，则count++，否则count–。
如果count=0，则说明出现了n对不同数据，则可以忽略他们，考虑其后的数据。
比如说，当i扫描到第一个元素3的时候，count=0，此时出现了一对不同的数据。
则可以忽略他们，考虑其后的元素2 3 3，curIndex重新指向2，i指向curIndex后面的一个数，count=1，继续扫描。
当i扫描到2后面的3时，count=0。此时，又出现一对不同的数据，忽略他们，考虑其后的数据，即3。
最后curIndex指向的数据既是所求的数据，此处为3。
*/

 
# include<stdio.h>
#include<malloc.h>
int main()
{
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
        int count=1,curIndex=0;
        int *num=(int *)malloc(N*sizeof(int));
        for(i=0;i<N;i++)
        {
            scanf("%d",num+i);
        }
        for(i=1;i<N;i++)
        {
            if(num[i]==num[curIndex])
                count++;
            else
                count--;
            if(count<=0)
            {
                count=1;
                curIndex=i+1;
                i=curIndex;
            }
        }
        printf("%d\n",num[curIndex]);
    }
    return 0;
}

