#include<stdio.h>

int main()
{
    int  d,h,s,ad,ah,as,bd,bh,bs,t,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&ad,&ah,&as,&bd,&bh,&bs);
        s = (as + bs) % 60;
        h = (ah + bh + (as+bs)/60 ) % 60;
        d = ad + bd + (ah + bh + (as+bs)/60 ) / 60;
        printf("%d %d %d\n",d,h,s);
    }
    return 0;
}