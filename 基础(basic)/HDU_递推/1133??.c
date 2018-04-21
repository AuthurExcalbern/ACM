#include<stdio.h>
#include<string.h>
int main ()
{
    int t=1,max,n,m,c,i,j,a[90001];
    while (scanf ("%d%d",&m,&n)==2&&(n!=0||m!=0))
    {
        memset(a,0,sizeof(a));
        a[0]=1;max=1;
        for (i=1;i<=n+m;i++)
        {
            c=0;
            if (m+1!=i)
            {
                for (j=0;j<max;j++)
                {
                    a[j]=a[j]*i+c;
                    c=a[j]/10;
                    a[j]%=10;
                    if(c&&max<=j+1)
                    max++;
                }
            }

        }
        if(n)
        {
                for (j=0;j<max;j++)
                {
                    a[j]=a[j]*(m-n+1)+c;
                    c=a[j]/10;
                    a[j]%=10;
                    if(c&&max<=j+1)
                    max++;
                }
        }
        printf ("Test #%d:\n",t);
        if (n>m)
        printf ("0");
        else
        {
            if (a[max])
        printf ("%d",a[max]);
       for (j=max-1;j>=0;j--)
       printf ("%d",a[j]);
        }
       printf ("\n");
       t++;
    }
    return 0;
}