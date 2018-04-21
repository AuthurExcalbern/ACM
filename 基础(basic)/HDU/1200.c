#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,count_i,count_j,len;
    char s[1000],key;
    memset(s,'0',sizeof(s));
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%s",s);
        len = strlen(s);
        for(count_i = 2*n - 1;count_i <= (len - n + 2);count_i = count_i + 2*n)//转换顺序
            for(count_j = 0;count_j < n/2;count_j++)
            {
                //printf("\n\n%d\n\n",count_j);
                key = s[count_i - count_j];
                s[count_i - count_j] = s[count_i - (n-1) + count_j];
                s[count_i - (n-1) + count_j] = key;
            }
        for(count_j = 0;count_j < n;count_j++)
            for(count_i = 0;count_i <= (len - n);count_i = count_i + n)
                printf("%c",s[count_i + count_j]);
        printf("\n");
    }
    return 0;
}