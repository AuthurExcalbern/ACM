#include<stdio.h>
#include<string.h>

int num[110];

void insort(int len)
{
    int key,z,i,j;
    for(j = 1; j < len; j++)
        {
            key = num[j];
            z = j - 1;
            while(z >= 0 && num[z] > key)
            {
                num[z + 1] = num[z];
                z = z - 1;
            }
            num[z + 1] = key;
        }
}

int main()
{
    int n,k[110],j=0,s,i;
    while(scanf("%d",&n) , n != 0)
    {
        memset(k,0,sizeof(k));
        for( i = 0; i < n; i++)
        {
            scanf("%d",&num[i]);
            if( num[i] < 0)
            {
                k[j] = -num[i];
                j++;
                num[i] = -num[i];
            }
        }
        insort(n);//printf("%d\n\n",num[1]);
        
        for( i = n-1; i > 0; i--)
        {
            for( s = 0; s < j; s++)
            {
                if( num[i] != k[s])
                    continue;
                else
                    break;
            }
            if( s == j)
                printf("%d ",num[i]);
            else
                printf("%d ",-num[i]);
        }
        printf("%d\n",num[i]);
    }
    return 0;
}