#include<stdio.h>
#include<string.h>

int main()
{
    int t,len,i;
    char n[55],key;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",n);
        len = strlen(n);
        for( i = 0; i < len; i=i+2)
        {
            key = n[i];
            n[i] = n[i+1];
            n[i+1] = key;
        }
        puts(n);
    }
    return 0;
}