#include<vector>  
#include<cstdio>  
#include<stack>  
#include<queue>  
using namespace std;  
  
struct Data_Struct  
{  
    //vc存放指令pair序列  
    vector<pair<int,int> > vc;  
  
    //构造函数  
    Data_Struct(int n)  
    {  
        for(int i=0;i<n;i++)  
        {  
            int x,y;  
            scanf("%d%d",&x,&y);  
            vc.push_back(make_pair(x,y));  
        }  
    }  
  
    //判断是否可能是一个栈  
    bool is_stack()  
    {  
        stack<int> S;  
        for(int i=0;i<vc.size();i++)  
        {  
            int x=vc[i].first, y=vc[i].second;  
            if(x==1) S.push(y);  
            else if(x==2)  
            {  
                if(S.empty() || S.top()!=y ) return false;  
                S.pop();  
            }  
        }  
        return true;  
    }  
  
    //判断是否可能是一个队列  
    bool is_queue()  
    {  
        queue<int> Q;  
        for(int i=0;i<vc.size();i++)  
        {  
            int x=vc[i].first, y=vc[i].second;  
            if(x==1) Q.push(y);  
            else if(x==2)  
            {  
                if(Q.empty() || Q.front()!=y ) return false;  
                Q.pop();  
            }  
        }  
        return true;  
    }  
  
    //判断是否可能是一个优先队列  
    bool is_priority_queue()  
    {  
        priority_queue<int> Q;  
        for(int i=0;i<vc.size();i++)  
        {  
            int x=vc[i].first,y=vc[i].second;  
            if(x==1) Q.push(y);  
            else  
            {  
                if(Q.empty() || Q.top()!=y )return false;  
                Q.pop();  
            }  
        }  
        return true;  
    }  
  
    //输出整合后的结果  
    void solve()  
    {  
        int S=is_stack(), Q=is_queue(), PQ=is_priority_queue();  
  
        if(S+Q+PQ==0) printf("impossible\n");  
        else if(S+Q+PQ==1)  
        {  
            if(S) printf("stack\n");  
            else if(Q) printf("queue\n");  
            else if(PQ) printf("priority queue\n");  
        }  
        else if(S+Q+PQ>1)  
            printf("not sure\n");  
    }  
};  
  
int main()  
{  
    int n;  
    while(scanf("%d",&n)==1)  
    {  
        Data_Struct ds(n);  
  
        ds.solve();  
    }  
    return 0;  
}
