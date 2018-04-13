/* 题意:
 * 给你多个命令,每个命令如Register 2004 200 对应于编号为2004的事件,每隔200秒发生一次(首次发生是在200秒).然后在给你一个K,要你输出前K个发生事件的编号.如果几个事件同时发生,输出事件编号小的.
 * 
 * 分析:
 * 本题只需要维护一个优先队列即可,每次从队列中取出时间最小且编号最小的事件,输出其编号,然后将其发生时间加上一个周期再从新放入优先队列即可.
 */
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node
{
    int id,time, period;
    
    Node(int id, int time, int period):id(id),time(time),period(period){}
    
    bool operator<(const struct Node &rhs)const
    {
        return time>rhs.time || (time==rhs.time && id>rhs.id);
    }
};

int main(void)
{
    string com;//Register
    priority_queue<Node> Q;
    
    while(cin >> com)
    {
        if(com == "#") break;
        
        int id, time;
        cin >> id >> time;
        
        Q.push(Node(id,time,time));
    }
    
    int k;
    cin >> k;
    while(k--)
    {
        Node tmp = Q.top(); Q.pop();
        cout << tmp.id << endl;
        
        tmp.time += tmp.period;
        Q.push(tmp);
    }
    
    return 0;
}