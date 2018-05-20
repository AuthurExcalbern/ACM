/*
对于S中的每一个元素，你唯一应该做的就是找到不等于'。'的最近字符：

如果最右边的一个是右边的'L'，用'L'代替;
如果左边最近的一个是'R'，则用'R'代替;
否则跳到S中的下一个。
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        res = dominoes;
        int n = dominoes.size();
        for(int i = 0; i < n; i++){
            if(dominoes[i] == '.'){
                char left = '.';
                char right = '.';
                int j,k;
                for(j = i - 1; j >= 0;j--){
                    if(dominoes[j]!='.'){
                        left = dominoes[j];
                        break;
                    }
                }
                for(k = i + 1; k < n; k++){
                    if(dominoes[k]!='.'){
                        right = dominoes[k];
                        break;
                    }
                }
                if(left=='R'&&right=='L'){
                    if(i-j!=k-i){
                        res[i] = i-j < k-i?left:right;
                    }
                }else if(left ==  'R'){
                    res[i] = left;
                }else if(right == 'L'){
                    res[i] = right;
                }
                
            }
        }
        return res;
    }
};

/* Memory Limit Ex
class Solution {
public:
    string pushDominoes(string dominoes) {
        for(int i = 0; i < dominoes.size(); i++)
        {
            if(dominoes[i] == '.')
                continue;
            else if(dominoes[i] == 'R')
                make_R(i, dominoes);
            else if(dominoes[i] == 'L')
                make_L(i, dominoes);
        }
        
        return dominoes;
    }

private:
    void make_R(int& i, string& str);
    void make_L(int& i, string& str);
};

void Solution::make_R(int& i, string& str)
{//cout <<str<<endl;
    //getchar();
    
    while(str[i+1] == 'R')
        i++;
    
    int x = str.find('L', i);
    
    while(true)
    {
        int y = str.find('R', i+1);
        //cout << y <<endl;
        if(y == string::npos || y > x)
            break;
        else if(y < x)
        {
            string temp(y-i, 'R');
            str = str.substr(0, i+1) + temp + str.substr(y+1, str.size());
            i = y;
            continue;
        }
    }
    
    
    
    if(x == string::npos)
    {
        string temp(str.size()-i-1, 'R');
        str = str.substr(0, i+1) + temp;
        
        i = str.size();
    }
    else
    {
        int mid = (x - i) / 2;
        
        bool miss_mid = (x - i) % 2 == 0 ? true : false;
        
        if(miss_mid)
        {
            string temp1(mid-1, 'R');
            string temp2(mid-1, 'L');
            str = str.substr(0, i+1) + temp1 + "." + temp2 + str.substr(x, str.size());
        }
        else
        {
            string temp1(mid, 'R');
            string temp2(mid, 'L');
            str = str.substr(0, i+1) + temp1 + temp2 + str.substr(x, str.size());
        }
        
        i = x;
    }
    
    
}

void Solution::make_L(int& i, string& str)
{//cout<<str<<endl;
    //getchar();
    for(int j = i-1; j >= 0; j--)
    {
        if(str[j] == '.')
            str[j] = 'L';
        else break;
    }
}
*/