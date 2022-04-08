法1：模拟法，与做过的寻找最长子串类似，比那个还简单，不需要返回最长的子串，只统计个数即可
时间O(N^2)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了84.57% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了95.34% 的用户
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i){
            res += checkS(s, i, i);
            res += checkS(s, i, i + 1);
        }
        return res;
    }
private:
    int checkS(string& s, int left, int right){
        int cnt = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
};
