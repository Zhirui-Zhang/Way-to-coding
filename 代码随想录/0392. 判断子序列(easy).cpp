法1：DP法，经典比较两个字符串是否相等的问题，dp数组遍即可
时间O(MN)  空间(MN)
执行用时：8 ms, 在所有 C++ 提交中击败了14.72% 的用户
内存消耗：7.8 MB, 在所有 C++ 提交中击败了13.67% 的用户
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n] == m;
    }
};

法2：双指针法，更简单也更直观
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了60.72% 的用户
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.size(), n = s.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (t[i] == s[j]) ++j;
            ++i;
        }
        return j == n;
    }
};