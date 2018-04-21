#include <stdio.h>
int main(void)
{
    int a[12]={0,31,28,31,30,31,30,31,31,30,31,30};
    //定义每个月天数的数组，但不能有十二月  的31天且a【0】=0。避免重复//
    int sum;
    int year,month,day,i;
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
    {
        sum=0;
        for(i=0;i<=month-1;i++)
            //用累加法加出总天数 但此时没有最后的一个月天数【最后一个月的天数用day算出】//
        {
            sum+=a[i];
        }
        if((year%400==0)||((year%4==0)&&(year%100!=0)))
            //判断是否为闰年，如果是的话且月份大于2，就总天数加1//
        {
            if(month>2)
                sum++;
        }
        sum+=day;
        //加上最后一月的day
        printf("%d\n",sum);
    }
    return 0;
}