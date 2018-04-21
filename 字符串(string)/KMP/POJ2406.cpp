/* POJ-2406
 * 
 * 题意：
 * 给出一个字符串 问它最多由多少相同的字串组成
 * 如  abababab由4个ab组成
 * 
 * 分析：
 * kmp中的next数组求最小循环节的应用
 * 
 * next数组的值，就是失配后下次开始匹配时往前移动的字符串的移动距离
 * 
 * 假设有一串长度为n的字符串，且next[n] = x
 * 那么说明字符串的 1～x位 与 (n-x)~n位 是相同的
 * 即next[n]代表着原字符串前缀与后缀相等的最长长度
 * 那么就可以求得循环节的长度=n - next[n]
 * 
 * 如果n不能整除循环节长度，则输出1
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000005;

int next[maxn];

void get_next(char *s)
{
    int l = strlen(s);
    int j = 0, k = -1;
    next[0] = -1;
    while(j < l)
    {
        if(k == -1 || s[j] == s[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

char s[maxn];

int main(void)
{
    while(scanf("%s", s) > 0)
    {
        if(strcmp(s, ".") == 0)
            break;
        get_next(s);
        int ans = 1;
        int l = strlen(s);
        if(l % (l - next[l]) == 0)
            ans = l / (l - next[l]);
        printf("%d\n", ans);
    }
    return 0;
}