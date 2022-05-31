法1：DP，经典两个字符串逐位比较，注意初始化第一行和第一列，遍历时判断对应字符是否相同，采用不同的递推公式
时间O(MN)  空间O(MN)
执行用时：24 ms, 在所有 C++ 提交中击败了63.96% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了77.39% 的用户
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < m + 1; ++i) dp[i][0] = i;
        for (int j = 0; j < n + 1; ++j) dp[0][j] = j;   // 初始化第一行和第一列，即与空字符串相比较需要删除的次数为当前字符串本身的长度
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];      // 若对应字符相同，可忽略，等于上一个字符的dp值即可
                else dp[i][j] = min(dp[i -1][j], dp[i][j - 1]) + 1;                 // 若不同，为↑ 或 ← 两个方向取小的值+1
            }
        }
        return dp[m][n];
    }
};

另一种思路，转换为1143求最大子序列长度的那道题，求出子序列长度后，用两字符串长度和减去即可，注意dp[m][n]要乘2
时间O(MN)  空间O(MN)
执行用时：28 ms, 在所有 C++ 提交中击败了38.64% 的用户
内存消耗：12 MB, 在所有 C++ 提交中击败了54.26% 的用户
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;      
                else dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);               
            }
        }
        return m + n - 2 * dp[m][n];
    }
};