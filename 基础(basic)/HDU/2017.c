#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,ans=0,len;
    char s[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        ans = 0;
        len = strlen(s);
        for( i = 0; i < len; i++)
            if( s[i] <= '9' && s[i] >= '0')
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}