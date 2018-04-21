#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    while(scanf("%s",&a)!=EOF)
    {
        int len=strlen(a);
        char max=a[0];
        for(int i=0;i<len;i++)
        {
            if(max<a[i])
                max=a[i];
        }
        for(int j=0;j<len;j++)
        {
            if(max==a[j])
                printf("%c(max)",a[j]);
            else printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}