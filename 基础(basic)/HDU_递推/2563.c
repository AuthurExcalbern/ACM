#include<stdio.h>
int main()
{
    int i,n;
    int size[20],a[20];
    for(i=2,size[0]=3,size[1]=7;i<20;i++)
        size[i]=2*size[i-1]+size[i-2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        printf("%d\n",size[a[i]-1]);
    return 0;
}