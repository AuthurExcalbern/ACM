#include<stdio.h>
#include<string.h>
int main()
{
    int i,ans,len;
    char c[35];
    while( gets(c), c[0] != '#')
    {
        len = strlen(c);
        ans = 0;
        for( i = 0; i < len-1; i++)
            if(c[i] == '1')
                ans++;
        if( c[i] == 'e')
        {
            if( ans % 2 == 0)
                c[i] = '0';
            else
                c[i] = '1';
        }
        else
        {
            if( ans % 2 == 0)
                c[i] = '1';
            else
                c[i] = '0';
        }
        puts(c);
    }
    return 0;
}