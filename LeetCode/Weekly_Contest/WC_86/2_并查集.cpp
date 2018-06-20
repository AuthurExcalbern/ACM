//有N个房间，每个房间保存有其他房间的钥匙
//求所有是否能成为一个联通块
/***********************************并查集模板***********************************/
//并查集基本模板
//fa需要初始化：memset(fa, -1, sizeof(fa))
//fa[i]表示i节点的父节点
const int MAXN = 1020;
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

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //const int MAXN = rooms.size();
        memset(fa, -1, sizeof(fa));
        
        for(int i = 0; i < rooms.size(); i++)
        {
            for(int j = 0; j < rooms[i].size(); j++)
            {
                bind(i, rooms[i][j]);
            }
        }
        
        int ff = findset(0);//cout<<ff<<endl;
        for(int i = 0; i < rooms.size(); i++)
        {//cout<<findset(i)<<endl;
            if(findset(i) != ff)
                return false;
        }
        return true;
    }
};

