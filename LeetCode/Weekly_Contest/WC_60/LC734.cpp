/* LeetCode Weekly Contest 60 第二题
 * problem 734 Sentence Similarity

给两个字符串和一个相似单词列表，判断俩字符串是否相似

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

这种相似没有传递性，而且每个单词与它自己总是相似的

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].

 * 关于map的资料：
 * https://www.cnblogs.com/hailexuexi/archive/2012/04/10/2440209.html
 * 关于set的资料:
 * https://www.cnblogs.com/wonderKK/archive/2012/04/10/2441379.html

解法：
灵活运用STL进行解答
 */

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        map<string, set<string> > dict;//用map建立一一对应的关系，set建立一个不重复的字符串有序数组
        for (auto item : pairs) {//遍历相似单词对应表
            dict[item.first].insert(item.second);//建立第一个单词和第二个单词的对应关系
            dict[item.second].insert(item.first);
        }
        if (words1.size() != words2.size()) {//如果两字符串的单词数量不同则必然不相似
            return false;
        }
        //如果有单词不相等且由word1查找到表尾部也未能找到对应的相似单词，则返回false
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i].compare(words2[i]) != 0 && dict[words1[i]].find(words2[i]) == dict[words1[i]].end()) {
                return false;
            }
        }
        return true;
    }
};
