/* POJ 1182
 * URL:http://poj.org/problem?id=1182
 */
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=50000+5;  
  
int fa[maxn];  
int r[maxn];//与父的关系  
int rev(int val)//返回逆向关系  
{  
    return (3-val)%3;  
}  
int rela_2(int v1,int v2)//由两个连续关系推出1个直接关系  
{  
    if(v1==0) return v2;  
    if(v2==0) return v1;  
    if(v1==1 && v2==1) return 2;  
    if(v1==1 && v2==2) return 0;  
    if(v1==2 && v2==1) return 0;  
    if(v1==2 && v2==2) return 1;  
}  
int rela_3(int v1,int v2,int v3)//3间接关系推1直接关系  
{  
    return rela_2(rela_2(v1,v2),v3);  
}  
int findset(int x)  
{  
    if(fa[x]==-1) return x;  
  
    int root=findset(fa[x]);  
    r[x] = rela_2(r[x],r[fa[x]]);  
    return fa[x]=root;  
}  
int bind(int u,int v,int relation)  
{  
    int fu=findset(u);  
    int fv=findset(v);  
    if(fu!=fv)  
    {  
        r[fu]=rela_3(rev(r[u]), relation, r[v]);  
        fa[fu]=fv;  
        return 0;  
    }  
    else//u与v在同一连通分量  
    {  
        if(rela_2(r[u], rev( r[v] ) ) != relation) return 1;  
        return 0;  
    }  
}  
  
int main()  
{  
    int n,k;  
    int cnt=0;//假话数  
    scanf("%d%d",&n,&k);  
    memset(fa,-1,sizeof(fa));  
    memset(r,0,sizeof(r));  
  
    while(k--)  
    {  
        int relation,x,y;  
        scanf("%d%d%d",&relation,&x,&y);  
        relation--;//这里记得减1  
  
        if(x>n || y>n || (relation==2 && x==y) )  
        {  
            ++cnt;  
            continue;  
        }  
  
        cnt += bind(x,y,relation);  
    }  
  
    printf("%d\n",cnt);  
    return 0;  
} 
