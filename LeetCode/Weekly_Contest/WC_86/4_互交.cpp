/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int same(string& s, string& t) {
        int len = s.size(), ret = 0;
        for (int i = 0; i < len; ++i) {
            ret += s[i] == t[i];
        }
        return ret;
    }
    int calc(vector<string>& words, string& s) {
        vector<int> cnt(7);
        for (auto& it : words) {
            cnt[same(it, s)]++;
        }
        return *max_element(cnt.begin(), cnt.end());
    }

    void findSecretWord(vector<string>& words, Master& master) {
        for (int k = 0; k < 10; ++k) {
            int best = 1LL << 30, best_i = -1;
            for (int i = 0; i < words.size(); ++i) {
                int maxv = calc(words, words[i]);
                if (best > maxv) {
                    best = maxv;
                    best_i = i;
                }
            }
            int feedback = master.guess(words[best_i]);
            vector<string> nxt_words;
            for (auto& s : words) {
                if (same(s, words[best_i]) == feedback) {
                    nxt_words.push_back(s);
                }
            }
            words = move(nxt_words);
        }
        
    }
};
