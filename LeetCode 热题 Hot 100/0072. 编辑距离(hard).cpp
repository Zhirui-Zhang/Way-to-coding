法1：DP法，类似于正则化的那道题，比较简单，dp[i][j]表示word1[i-1]转化为word2[j-1]所需的最少次数，分别与 左上  左  上 的数字+1比较，取最小值，特别注意当word1[i-1]==word2[j-1]时左上不变
时间O(MN)  空间O(MN)word1[i]转化为word2[j]
执行用时：20 ms, 在所有 C++ 提交中击败了20.20% 的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了65.58% 的用户
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m + 1; ++i)    dp[i][0] = i;   // 初始化第一行和第一列
        for(int j = 1; j < n + 1; ++j)    dp[0][j] = j;
        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                int left = dp[i][j-1] + 1, up = dp[i-1][j] + 1;
                int diag = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1]: dp[i-1][j-1] + 1;   // 当两字符相等时，不需要修改，原值即可
                dp[i][j] = min({left, up, diag});   // 三个值取最小
            }
        }
        return dp[m][n];
    }
};

学习代码随想录后，自己写的模板更新，与583题唯一的不同之处在于当对应字符不同时，还需要考虑↖方向的值即替换之前的一个字符，所以dp值为三个方向上取最小值+1
时间O(MN)  空间O(MN)
执行用时：24 ms, 在所有 C++ 提交中击败了11.44% 的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了70.44% 的用户
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i)    dp[i][0] = i;
        for (int j = 1; j < n + 1; ++j)    dp[0][j] = j;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            }
        }
        return dp[m][n];
    }
};