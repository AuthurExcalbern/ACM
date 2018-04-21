/* POJ 2492
 * URL: http://poj.org/problem?id=2492
 * 路径压缩并查集问题。
 * 每个虫子对应并查集的一个节点，每个节点维护fa[i]：父节点编号，v[i]：i与父节点是否性别相同。
 * 如果v[i]==0，表示相同。如果v[i]==1，表示不相同。
 * 如果两个虫子交互,那么合并他们的连通分量。
 * 如果有处于同一个连通分量且相同性别的两个虫子发生了交流，那么就存在了可疑的虫子。
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MA 2100
int F[MA];//储存父节点信息
int v[MA];//储存子节点
//并查集 根节点查询和连接
int findset(int i)  
{  
    int temp;  
    if(F[i] == -1)
        return i;
    temp = findset(F[i]);
    v[i] = (v[i] + v[F[i]]) % 2;//路径压缩导致的关系变化
    return F[i] = temp;  
}  
void bind(int i,int j)  
{  
    int fa = findset(i);  
    int fb = findset(j);  
    if(fa != fb)  
    {  
        F[fb] = fa;  
        v[fb] = (v[i] + v[j] + 1) % 2;//路径压缩导致的关系变化
    }  
}  

int main(void)  
{  
    int T, kase = 1;  
    int n, m;//n为昆虫的数目，m为昆虫的交流次数  
    int key;
    int a, b;
    int fa; 
    int fb;

    scanf("%d",&T);  
    while(T--)  
    {  
        key = 1;//没有可疑的虫子被发现  
        memset(F, -1, sizeof(F));  
        memset(v, 0, sizeof(v));  
        scanf("%d %d", &n, &m);  
        while(m--)  
        {    
            scanf("%d %d", &a, &b);  
            fa = findset(a);
            fb = findset(b);
            if(fa != fb)  
            {  
                bind(a, b);//这里切记是合并a和b  不是合并fa和fb  
            }  
            else if(fa == fb)  
            {  
                if(v[a] == v[b])  
                    key = 0;  
            }  
        }  
        if(key == 0)  
            printf("Scenario #%d:\nSuspicious bugs found!\n\n",kase++);  
        else if(key == 1)  
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n",kase++);  
    }  
    return 0;  
}
