/* 题意:
 * 给你n个数(n<=10w,但是数值<=100w),现在要你回答m个查询,对于每个查询都是k和v,要求你回答原始数据中第k个v值出现的原始下标,如果不存在输出0.
 * 
 * 定义map<int,vector<int> > data.则每个v值对应一个v出现的所有下标构成的向量。对于每个v和k，我们可以直接通过map[v][k-1]直接输出结果
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(void)
{
    int n, m;
    
    while(cin>> n >> m)
    {
        map<int, vector<int> > mp;
        
        for(int i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            if(mp.count(v) == 0)
                mp[v] = vector<int>();
            mp[v].push_back(i);
        }
        
        while(m--)
        {
            int k, v;
            cin >> k >> v;
            if(mp[v].size() < k)
                cout << "0" << endl;
            else
                cout << mp[v][k-1] << endl;
        }
    }
    return 0;
}