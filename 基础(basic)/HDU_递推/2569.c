#include<stdio.h>
int chuli(int a)
{
    if(a==1)
    {
        return 3;
    }
    else if(a==2)
    {
        return 9;
    }
    else 
    {
        return 2*chuli(a-1)+chuli(a-2);
    }
}
int main()
{
    int a,n;
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d",&a);
        
        printf("%d\n",chuli(a));
    }
 }