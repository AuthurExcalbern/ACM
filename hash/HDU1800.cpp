#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>

#define mem(a,b) memset(a,b,sizeof(a))
#define M 1000005

typedef long long ll;
using namespace std;
 
unsigned int BKDRHash(char *str)
{
    while(*str=='0')
        *str++;
    unsigned int seed=131;
    unsigned int hash=0;
    while(*str)
        hash=hash*seed + (*str++);
    return hash&0x7FFFFFFF;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        char s[31];
        int i,k,min=0;
        map<int,int>Hash;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            k=BKDRHash(s);
            Hash[k]++;
            if(Hash[k]>min) min=Hash[k];
        }
        printf("%d\n",min);
    }
    return 0;
}
