#include<stdio.h>

char str[10];  
int n, dot;  
int res[999999], a[999999], b[999999];  
int len, lena, lenb;  
  
void mul()  
{  
    int i, j;  
    memset(res, 0, sizeof(res));  
    for (i=1; i<=lena; i++)  
    {  
        for (j=1; j<=lenb; j++)  
        {  
            res[i+j-1] += a[i] * b[j];  
            if (res[i+j-1]>9)   
            {  
                res[i+j] += res[i+j-1] / 10;  
                res[i+j-1] %= 10;  
            }  
        }  
    }  
    if (res[lena+lenb-1]>9)   
    {  
        res[lena+lenb] += res[lena+lenb-1] / 10;  
        res[lena+lenb-1] %= 10;  
    }  
    lena = lena + lenb;  
    for (i=1; i<=lena; i++) a[i] = res[i];  
}  
  
int main()  
{  
    int i, j, up, down;  
    while (scanf("%s %d", str, &n)!=EOF)  
    {  
        dot = -1;  
        for (i=5, j=1; i>=0; i--)  
        {  
            if (str[i]!='.') a[j] = b[j++] = str[i] - '0';  
            else dot = i;  
        }  
        if (dot==-1) lena = lenb = 6;  
        else lena = lenb = 5;  
        for (i=1; i<n; i++) mul();  
        if (dot==-1)   
        {  
            for (i=lena; i>=1; i--) printf("%d", a[i]);  
            printf("\n");  
        }  
        else  
        {  
            dot = 5 - dot;  
            dot *= n;  
            for (i=1; i<=lena; i++)  
            {  
                if (a[i]!=0)  
                {  
                    down = i;  
                    break;  
                }  
            }  
            for (j=lena; j>=1; j--)  
            {  
                if (a[j]!=0)  
                {  
                    up = j;  
                    break;  
                }  
            }  
            i = up;  
            if (up<dot) i = dot;  
            j = down;  
            if (j>dot) j = dot + 1;  
            for (; i>=j; i--)  
            {  
                if (i==dot) printf(".");  
                printf("%d", a[i]);  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  



/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char num[10010];
int c[10010][10010],sum[100000];

int searchP()
{
    int count_i,count_j;
    for(count_i = 0;count_i < 6;count_i++)
        if(num[count_i] == '.')
            break;
    for(count_j = count_i;count_j < 10000;count_j++)
        num[count_i] = num[count_i + 1];
    return i;
}

void EXP(int P,int n)
{
    int count_i,count_j;
    if(n == 0)
    {
        print("0\n");
        return;
    }
    if(n == 1)
    {
        print("%s\n",num);
        return;
    }
    while(n--)
    {
        for(count_i = 0;count_i <= 10000 ;count_i++)
            for(count_j = 0;count_j <= 10000;count_j++)
            {
                c[count_i][count_j] = (num[count_i] - '0') * (num[count_j] - '0');
                if(c[count_i][count_j] > 9)
                {
                    c[count_i][count_j] = key;
                    c[count_i][count_j] = c[count_i][count_j] % 10;
                    c[count_i][count_j + 1] + = key / 10;
                }
            }
        SUM[0] = C[0][0];
        for(count_i = 0;count_i <= 10000 ;count_i++)
            for(count_j = 0;count_j <= 10000;count_j++)
            {
                sum[count_i + 1] = c[count_i][count_j + 1] + c[count_i + 1][count_j];
                

int main()
{
    //char num[6];
    int n,P;
    memset(sum,0,sizeof(sum));
    while(scanf("%s %d",num,&n) != EOF)
    {
        P = searchP(num);
        EXP(num,P,n);*/