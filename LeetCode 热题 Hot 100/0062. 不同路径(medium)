法1：DP法，类型题，并不难，构建DP数组初始为全1，然后逐行逐列遍历修改值为上方和左方值之和，最后输出即可
时间O(MN)  空间O(MN)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了53.51% 的用户
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

法2：数学公式法，找规律题，答案了解即可
时间O(M)  空间O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
