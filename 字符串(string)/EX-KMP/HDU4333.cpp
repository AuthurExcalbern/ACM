/*
题意:给定一个数字<=10^100000,一次将该数的第一位放到放到最后一位,求所有组成的不同的数比原数小的个数,
相等的个数,大的个数
分析:由于输入的数太大了,只能当作字符串处理,将输入的原串粘贴在后面，
这样就可以对原串进行EKMP,最终只要统计从第i个位置开始的extend[i],
如果>=len则从第i个位置开始的组成的数与原数相等,否则只要比较s[i]与s[i+next[i]]即可
*/
  
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int maxn=1e6+100;  
char s1[maxn], s2[maxn];
int node;
int nxt[maxn], ex[maxn]; //ex数组即为extend数组
void get_node(int len)//记录开始出现重复字符串的位置，因为在出现重复的字符串后，后面的数字会都是重复的，所以不用计算
{
    int i = 0, j = -1;
    nxt[0] = -1;
    while(i < len)
    {
        if(j == -1 || s1[i] == s1[j])
        {
            i++; j++;
            nxt[i] = j;
        }
        else
         j = nxt[j];
    }
    node = len - nxt[len];
}

/****************************拓展KMP模板***********************************/

//预处理计算next数组
void GETNEXT(char *str)
{
    int i = 0, j, po, len = strlen(str);
    nxt[0] = len;//初始化next[0]
    while(str[i] == str[i + 1] && i + 1 < len) i++;//计算next[1]
    nxt[1] = i;
    po = 1;//初始化po的位置
    for(i = 2; i < len; i++)
    {
        if(nxt[i - po] + i < nxt[po] + po) nxt[i]=nxt[i-po];//第一种情况，可以直接得到next[i]的值
        else//第二种情况，要继续匹配才能得到next[i]的值
        {
            j = nxt[po] + po - i;
            if(j < 0) j = 0;//如果i>po+next[po],则要从头开始匹配
            while(i + j < len && str[j] == str[j + i]) j++;//计算next[i]
            nxt[i] = j;
            po = i;//更新po的位置
        }
    }
}
//计算extend数组
void EXKMP(char *s1,char *s2)
{
    int i = 0, j, po, len=strlen(s1), l2=strlen(s2);
    GETNEXT(s2);//计算子串的next数组
    while(s1[i] == s2[i] && i < l2 && i < len) i++;//计算ex[0]
    ex[0] = i;
    po = 0;//初始化po的位置
    for(i = 1; i < len; i++)
    {
        if(nxt[i - po] + i < ex[po] + po) ex[i] = nxt[i - po];//第一种情况，直接可以得到ex[i]的值
        else//第二种情况，要继续匹配才能得到ex[i]的值
        {
            j = ex[po] + po - i;
            if(j < 0) j = 0;//如果i>ex[po]+po则要从头开始匹配
            while(i + j < len && j < l2 && s1[j+i] == s2[j]) j++;//计算ex[i]
            ex[i] = j;
            po = i;//更新po的位置
        }
    }
}
/****************************拓展KMP模板***********************************/

int main(void)
{
    int T, kase = 0;
    cin >> T;
    while(T--)
    {
        cin >> s1;
        int len = strlen(s1);
        strcpy(s2, s1);
        strcat(s2, s1);
        EXKMP(s2, s1);
        get_node(len);
        if(len % node != 0) node = len;
        int num1 = 0, num2 = 0, num3 = 0;
        for(int i = 0; i < node; i++)
            if(ex[i] >= len) num2++;
            else if(s1[ex[i]] > s2[i + ex[i]]) num1++;
            else if(s1[ex[i]] < s2[i + ex[i]]) num3++;
        }
        printf("Case %d: %d %d %d\n",++kase,num1,num2,num3);
    }
    return 0;
}
