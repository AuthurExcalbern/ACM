#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 500005;
int sum[N], value[27];//sum为前i个字符价值和
int pre[N], pos[N];//pre标记前i个字符为回文串,pos标记后i个字符为回文串

/****************************manacher模板***********************************/
char str[N];//原字符串
char tmp[N<<1];//转换后的字符串
int Len[N<<1];
//转换原始串
int init(char *st)
{
    int i, len = strlen(st);
    tmp[0] = '@';//字符串开头增加一个特殊字符，防止越界
    for(i = 1; i <= 2 * len; i += 2)
    {
        tmp[i] = '#';
        tmp[i + 1] = st[ i / 2];
    }
    tmp[2 * len + 1] = '#';
    tmp[2 * len + 2] = '$';//字符串结尾加一个字符，防止越界
    tmp[2 * len + 3] = '\0';
    return 2 * len + 2;//返回转换字符串的长度
}
//Manacher算法计算过程
void manacher(char *st,int len)
{
     int mx = 0, ans = 0, po = 0;//mx即为当前计算回文串最右边字符的最大值
     for(int i = 1; i <= len; i++)
     {
         if(mx > i) Len[i] = min(mx-i, Len[2 * po - i]);//在Len[j]和mx-i中取个小
         else Len[i] = 1;//如果i>=mx，要从头开始匹配
         while(st[i - Len[i]] == st[i + Len[i]]) Len[i]++;
         if(Len[i] + i > mx)//若新计算的回文串右端点位置大于mx，要更新po和mx的值
         {
             mx = Len[i] + i;
             po = i;
         }
         //ans = max(ans, Len[i]);
         if(i-Len[i] == 0)
             pre[Len[i]-1] = 1;//表示前缀(前p[i]-1个字符)是回文串  
         if(i+Len[i] == len)
             pos[Len[i]-1] = 1;//表示后缀(后p[i]-1个字符)是回文串 
     }
     return ;//ans - 1;//返回Len[i]中的最大值-1即为原串的最长回文子串额长度 
}
/****************************manacher模板***********************************/

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(pre, 0, sizeof(pre));
        memset(pos, 0, sizeof(pos));
        memset(value, 0, sizeof(value));
        for(int i = 0; i < 26; i++) cin >> value[i];
        cin >> str;
        int len = strlen(str);
        int ans = -INF, temp = 0;
        for(int i = 1; i <= len; ++i) sum[i] = sum[i-1] + value[str[i-1]-'a'];
        int l = init(str);
        manacher(tmp, l);
        for(int i = 1; i <= len; i++)
        {
            if(pre[i])
                temp += sum[i];
            if(pos[len-i])
                temp += sum[len]-sum[i];
            if(temp > ans)
                ans = temp;
            temp = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

