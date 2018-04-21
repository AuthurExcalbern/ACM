#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
/****************************AC自动机模板***********************************/
const int maxnode = 11000;
const int sigma_size = 26;
struct AC_Automata
{
    int ch[maxnode][sigma_size];
    int val[maxnode];   // 每个字符串的结尾结点都有一个非0的val
    int f[maxnode];     // fail函数
    int last[maxnode];  // last[i]=j表j节点表示的单词是i节点单词的后缀，且j节点是单词节点
    int sz;

    //初始化0号根节点的相关信息
    void init()
    {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        val[0] = 0;
    }

    //insert负责构造ch与val数组
    //插入字符串,v必须非0表示一个单词节点
    void insert(char *s,int v)
    {
        int n = strlen(s), u = 0;
        for(int i = 0; i < n; i++)
        {
            int id = s[i] - 'a';
            if(ch[u][id] == 0)
            {
                ch[u][id] = sz;
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz++] = 0;
            }
            u=ch[u][id];
        }
        val[u]=v;
    }

    //getFail函数负责构造f和last数组
    void getFail()
    {
        queue<int> q;
        last[0] = f[0] = 0;
        for(int i = 0; i< sigma_size; i++)
        {
            int u = ch[0][i];
            if(u)
            {
                f[u] = last[u] = 0;
                q.push(u);
            }
        }

        while(!q.empty())// 按BFS顺序计算fail
        {
            int r = q.front(); q.pop();
            for(int i = 0; i < sigma_size; i++)
            {
                int u = ch[r][i];
                if(u == 0) continue;
                q.push(u);

                int v = f[r];
                while(v && ch[v][i] == 0) v = f[v];
                f[u] = ch[v][i];
                last[u] =  val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
  
    //递归打印与结点i后缀相同的前缀节点编号
    //进入此函数前需保证val[i]>0
    void print(int i)
    {
        if(i)
        {
            printf("%d\n",i);
            print(last[i]);
        }
    }

    // 在s中找出 出现了哪几个模板单词
    void find(char *s)
    {
        int n = strlen(s), j = 0;
        for(int i = 0; i < n; i++)
        {
            int id = s[i] - 'a';
            while(j && ch[j][id] == 0) j = f[j];
            j = ch[j][id];
            if(val[j]) print(j);
            else if(last[j]) print(last[j]);
        }
    }

};
AC_Automata ac;
/****************************AC自动机模板***********************************/
