法1:DP，刚开始陷入误区了，以为单纯的加法就行，实际上应该是每次左右两个子树节点数量的乘积才可以  
例：n=5  dp[5] = dp[4]*dp[0] (头节点为1时，右侧4个，左侧0个) + dp[3]*dp[1] (头节点为2时，右侧3个，左侧1个) + dp[2]*dp[2] + dp[1]*dp[3] + dp[0]*dp[4]
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了72.05% 的用户
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;      // 两种特殊情况，当为空树或只有一个根节点时只有一种情况
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i-j-1];   // 左子树*右子树的和加入dp[i]中
            }
        }
        return dp[n];
    }
};
