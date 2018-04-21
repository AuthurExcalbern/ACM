#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char c[3],key;
    while(scanf("%s",c) != EOF)
    {
        if(c[1] < c[0])
        {
            key = c[0];
            c[0] = c[1];
            c[1] = key;
        }
        if(c[2] < c[0])
        {
            key = c[0];
            c[0] = c[2];
            c[2] = c[1];
            c[1] = key;
        }
        else if(c[2] < c[1])
        {
            key = c[1];
            c[1] = c[2];
            c[2] = key;
        }
        printf("%c %c %c\n",c[0],c[1],c[2]);
    }
    return 0 ;
}