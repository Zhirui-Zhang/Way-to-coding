法1：回溯法，逐个判断是否为回文串，若是则加入tmp字符串，继续下一层递归
时间O(N!)应该也为全排列  空间O(N)最大递归深度为s串的长度 
执行用时：104 ms, 在所有 C++ 提交中击败了79.78% 的用户
内存消耗：73.9 MB, 在所有 C++ 提交中击败了62.52% 的用户
class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<string> tmp;
    void dfs(string& s, int start) {
        if (start == s.size()) {    // 递归结束条件
            res.push_back(tmp);
            return;
        }
        for (int end = start; end < s.size(); end++) {      // 右边界从start开始，到字符串末尾结束
            if (checkS(s, start, end)) {                    // 依次判断是否为回文串
                tmp.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1);
                tmp.pop_back();
            }
        }
    }
    bool checkS(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else return false;            
        }
        return true;
    }
};