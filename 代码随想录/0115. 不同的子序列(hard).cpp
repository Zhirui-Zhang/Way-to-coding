法1：DP法，并不是很难，状态转移方程有一点搞错了，注意即可
时间O(MN)  空间O(MN)
执行用时：16 ms, 在所有 C++ 提交中击败了93.85% 的用户
内存消耗：29.2 MB, 在所有 C++ 提交中击败了68.38% 的用户
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();                                            // 由于计算结果会超过int范围，连long long都溢出，只能用unsigned long类型
        vector<vector<unsigned long>> dp(m + 1, vector<unsigned long> (n + 1, 0)); // 把s字符串放在纵列，t放在横行比较符合个人习惯，可见excel题解
        for (int j = 0; j < n + 1; ++j) dp[0][j] = 1;                              // 初始化dp数组，含义为当t为空串时，任意s都有一种匹配方式
        for (int i = 1; i < m + 1; ++i) {
            for (int j = i; j < n + 1; ++j) {                                      // 遍历，注意j可以从i开始遍历，因为s至少需要从下标i开始才可能包含t串，之前的可以忽略不计
                // 两种情况讨论，如果当前字符相等，需要← ↖两个方向的dp相加得到，如果不等，等于左侧已经匹配的方法数
                if (t[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];                         
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};