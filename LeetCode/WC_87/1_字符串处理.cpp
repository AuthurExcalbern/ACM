// '#' 代表退格符号，问两个字符串是否相等
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return to(S) == to(T);
    }
private:
    string to(string s)
    {
        vector<char> ans;
        
        for(char c : s)
        {
            if(c == '#')
            {
                if(!ans.empty())
                    ans.pop_back();
            }
            else
                ans.push_back(c);
        }
        
        return string(ans.begin(), ans.end());
    }
};
