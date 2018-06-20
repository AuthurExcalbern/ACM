//dfs把字符串分割为Fibonacci数

class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> res = new ArrayList<>();
        // Map[] memo = new Map[S.length()];
        dfs(S, res, 0, -1, -1);
        return res;
    }
    
    private boolean dfs(String s, List<Integer> res, int idx, int prePre, int pre) {
        if (idx == s.length()) {
            if (res.size() > 2) return true;
            return false;
        }
        
        for (int i = idx; i < s.length(); i++) {
            int cur = Integer.valueOf(s.substring(idx, i + 1));
            if (pre == -1) {
                res.add(cur);
                if (dfs(s, res, i + 1, prePre, cur)) return true;
                res.remove(res.size() - 1);
            }else if (prePre == -1) {
                res.add(cur);
                if (dfs(s, res, i + 1, pre, cur)) return true;
                res.remove(res.size() - 1);
            }else {
                if (cur == prePre + pre) {
                    res.add(cur);
                    if (dfs(s, res, i + 1, pre, cur)) return true;
                    res.remove(res.size() - 1);
                }
            }
            if (cur * 10 / 10 != cur || cur == 0) break;
        }
        return false;
    }
}
