法1：DP，仿照题目5最长回文子串和647回文子串个数的形式，只不过前两道题都可以用双指针，而求回文子序列不可以，只能用dp数组
注意细节，比如dp长度不再为n + 1，遍历方式为从下至上，从左至右，可见题解
时间O(N^2)  空间O(N^2)
执行用时：92 ms, 在所有 C++ 提交中击败了71.10% 的用户
内存消耗：71.2 MB, 在所有 C++ 提交中击败了59.15% 的用户
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));      // dp[i][j]的含义为字符串s从s[i]到s[j]包含的最长回文子序列长度
        for (int i = n - 1; i >= 0; --i) {                  // 由于递推公式中涉及dp[i + 1][j - 1]，所以遍历方式不再是正序
            for (int j = i; j < n; ++j) {                   // 由于dp[i][j]定义，[i, j]方向当j < i时无意义，故遍历顺序呈倒三角形式
                if (s[i] == s[j]) {                         // 两种情况，当s[i] == s[j]时，若i == j或i j相邻，长度为1 or 2
                    if (j - i <= 1) dp[i][j] = j - i + 1;   // 若j比i大得多，则长度为dp[i + 1][j - 1] + 2
                    else dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {                                    // 若s[i] != s[j]，可删掉一个元素，取←和↓的较大值
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];         // 注意dp[i][j]的定义，所以dp[0][n - 1]表示整个s字符串的最长回文子序列长度
    }
};