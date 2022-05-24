法1：DP，不太难，注意初始化时遇到障碍物即break
时间O(MN)  空间O(MN)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.6 MB, 在所有 C++ 提交中击败了31.27% 的用户
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) break;     // 当首行或首列遇到障碍物时立刻退出，否则设为1
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};