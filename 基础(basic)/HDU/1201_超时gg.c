/*
 * 关键为润年的计算：
 *      years % 4 == 0 && 
 *      if（years % 100 == 0）years % 400 == 0
 * 
 * 普通而言一年365天;润年有366天。
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int years,mouth,day;
int count = 0;
int num = 0;

void year_s()
{
    void year();
    if(mouth > 2)
        year();
    else
    {
        count++;
        year();
    }
    return;
}

void year()
{
    void year_s();
    void year();
    count = count + 365;
    num++;
    years++;
    /*if(num == 18)
    {
        printf("%d\n",count);
        return;
    }*/
    for(;num != 18;num++,years++)
    {
        if(years % 4 ==0 && years % 100 != 0 || (years%100==0 && years % 400 == 0) )
        {
            if(num != 17 || (num == 17 && mouth <= 2) )
            {
                count++;
                count = count + 365;
                //year();
            }
            else
                count = count + 365;
                //year();
        }
    /*
    else if()
    {
        if(num != 17 || (num == 17 && mouth <= 2) )
        {
            count++;
            year();
        }
        else
            year();
    }*/
    else
        count = count + 365;
        //year();
    }
    printf("%d\n",count);
    return;
}
    
    

int main()
{
    void year_s();
    void year();
    int t;
    char c[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",c);
        years = (c[0]-'0')*1000 + (c[1]-'0')*100 + (c[2]-'0')*10 + (c[3]-'0');
        mouth = (c[5]-'0')*10 + (c[6]-'0');
        day = (c[8]-'0')*10 + (c[9]-'0');
        //printf("\n%d\n\n",day);
        if(years % 4 ==0 && years % 100 != 0 || (years%100==0 && years % 400 == 0) )
            year_s();
       /* else if(years % 400 == 0)
            year_s();
        */else
            year();
    }
    return 0;
}
