法1：DP，经典两个字符串比较问题，只需要注意是子数组（连续）还是子序列（不连续）即可
时间O(MN)  空间O(MN)
执行用时：24 ms, 在所有 C++ 提交中击败了46.43% 的用户
内存消耗：12.9 MB, 在所有 C++ 提交中击败了6.45% 的用户
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

PS：由于这个二维dp数组需要借助上左斜三个方向的状态，故不能设置成一维滚动数组来算