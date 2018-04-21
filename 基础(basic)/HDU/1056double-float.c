#include<stdio.h>
#define ZERO 0.00f
int main()
{
    int cardNum(double overhang);
    double overhang;
    int num;
    while(scanf("%lf",&overhang) != EOF)
    {
        if(overhang == ZERO)
            break;
        num = cardNum(overhang);
        printf("%d card(s)\n",num);
    }
    return 0;
}
int cardNum(double overhang)
{
    int count_i;
    double sum = 0.0;
    for(count_i = 2;sum < overhang;count_i++)
        sum = sum + 1.0/count_i;
    return count_i - 2;
}