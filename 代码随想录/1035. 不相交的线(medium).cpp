法1：DP，为什么相交的状态转移方程判定我并不清楚，只不过根据表格推出来的，不知道靠不靠谱
时间O(MN)  空间O(MN)
执行用时：20 ms, 在所有 C++ 提交中击败了18.51% 的用户
内存消耗：12.6 MB, 在所有 C++ 提交中击败了51.25% 的用户
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                // 只有当两对应位置的值相等且↖ ← ↑三个方向的dp值相等时才加1
                if (nums1[i - 1] == nums2[j - 1] && dp[i - 1][j] == dp[i - 1][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // 否则取三个方向上的最大值
                else dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        return dp[m][n];
    }
};

简化版：其实就是求最长公共子序列，焯，改一下名称就行了，不用这么麻烦
执行用时：16 ms, 在所有 C++ 提交中击败了55.02% 的用户
内存消耗：12.6 MB, 在所有 C++ 提交中击败了62.51% 的用户
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};