#include<stdio.h>
#include<string.h>

int main()
{
    char c1[35],c2[35];
    int t,len1,len2,key,i;
    scanf("%d",&t);getchar();
    while(t--)
    {
        
        gets(c1);//printf("\n\n");
        len1 = strlen(c1);
        //getchar();
        gets(c2);
        len2 = strlen(c2);
        key = len1 / 2;
        for( i = 0; i < key; i++)
            printf("%c",c1[i]);
        for( i = 0; i < len2; i++)
            printf("%c",c2[i]);
        for( i = key ; i < len1; i++)
            printf("%c",c1[i]);
        printf("\n");
    }
    return 0;
}