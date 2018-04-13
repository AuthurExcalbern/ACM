//如果输入的xy会使无向联通图出现环则拒绝，输出拒绝的数目
#include<iostream>
#include<cstring>

const int MAXN = 500005;
int fa[MAXN];
int findset(int x)
{
    return fa[x] == -1 ? x : findset(fa[x]);
}
void bind(int u, int v)
{
    int fu = findset(u);
    int fv = findset(v);
    if(fu != fv) fa[fu] = fv;
}
        
int main(void)
{
    int x, y;
    while(std::cin >> x)
    {
        if(x == -1)//特例
        {
            std::cout << "0\n";
            continue;
        }
        
        int ans = 0;
        memset(fa, -1, sizeof(fa));
        
        while(x != -1)
        {
            std::cin >> y;
            if(findset(x) == findset(y)) ans++;
            else bind(x, y);
            std::cin >> x;
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}