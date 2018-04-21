#include<stdio.h>
#include<string.h>

int main()
{
    int i,len,j,l;
    char c[30],s[85];
    while( scanf("%s",c) != EOF)
    {
        getchar();
        l = strlen(c);
        gets(s);
        len = strlen(s);
        for( i = 0; i < len; i++)
        {
            if( islower(s[i]) )
            {
                for( j = 0; j < l; j++)
                    if( s[i] == 'a' + j)
                    {
                        printf("%c",c[j]);
                        break;
                    }
            }
            else
            {
                s[i] = s[i] + 32;
                for( j = 0; j < l; j++)
                    if( s[i] == 'a' + j)
                    {
                        printf("%c",c[j]-32);
                        break;
                    }
            }
            if( j == 26 )
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}