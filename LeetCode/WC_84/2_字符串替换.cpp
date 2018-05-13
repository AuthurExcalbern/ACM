//关键是在于从后面向前面替换

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        vector<datum> datums;
        
        datum temp;
        for(vector<int>::size_type i = 0; i < indexes.size(); i++)
        {
            temp.indexe = indexes[i];
            temp.source = sources[i];
            temp.target = targets[i];
            datums.push_back(temp);
        }
        
        sort(datums.begin(), datums.end());
        
        for(datum i : datums)
        {
            if(S.substr(i.indexe, i.source.size()) == i.source)
                S = S.substr(0, i.indexe) + i.target + S.substr(i.indexe+i.source.size());
        }
        
        return S;
    }
private:
    struct datum
    {
        int indexe;
        string source;
        string target;
        
        bool operator < (const struct datum& oth) const
        {
            return indexe > oth.indexe;
        }
    };
};
