#include<stdio.h>
#include<string.h>

int main()
{
    int t,len,i,j;
    char c[1000];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(c);
        len = strlen(c);
        for( i = 0,j = len-1; i <= (len-1)*1.0/2, j >= (len-1)*1.0/2; i++, j--)
            {
                if( c[i] == c[j])
                    continue;
                else
                    break;
            }
        if( i > (len-1)*1.0/2 || j < (len-1)*1.0/2)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}