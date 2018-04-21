#include <stdio.h>
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int s=a%10,ans=1;
        while(b>0)
        {
            if(b&1)ans=ans*s%10;
            s=s*s%10;
            b>>=1;
        }
        printf("%d\n",ans);
    }
}