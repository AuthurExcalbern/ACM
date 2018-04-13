/***********************************并查集模板***********************************/
//并查集基本模板
//fa需要初始化：memset(fa, -1, sizeof(fa))
//fa[i]表示i节点的父节点
int fa[MAXN];

//返回x节点的根，同时使得x节点直接挂在根节点下面
int findset(int x)
{
    return fa[x] == -1 ? x : (fa[x] = findset(fa[x]) );
}

//合并u与v所属的联通分支
int bind(int u, int v)
{
    int fu = findset(u);//获取根
    int fv = findset(v);//获取根
    if(fu != fv)//根不同->术语不同联通分量->可合并
    {
        fa[fu]=fv;
        return 1;
    }
    return 0;
}

/***********************************并查集模板***********************************/
